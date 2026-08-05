/*
 * ESP32 Dual MOSFET Boat Controller — ELRS (CRSF) RC Control
 *
 * Controls two DC motors via MOSFET driver (IN1/IN2 per motor).
 * Uses ExpressLRS receiver over CRSF protocol (UART).
 *
 * Controls:
 *   Throttle (CH3) → base speed for both motors
 *   Yaw (CH1)      → steering (differential)
 *
 * Wiring (MOSFET driver → ESP32):
 *   Motor 1: IN1 → GPIO4   IN2 → GPIO5
 *   Motor 2: IN1 → GPIO14  IN2 → GPIO15
 *   ELRS RX  → GPIO17 (UART1 RX)
 *   ELRS TX  → GPIO16 (UART1 TX)
 *
 * Motor control logic:
 *   IN1  IN2  |  Motor
 *   HIGH LOW  |  Forward
 *   LOW  HIGH |  Reverse
 *   HIGH HIGH |  Brake (short)
 *   LOW  LOW  |  Coast (free)
 */

#include <AlfredoCRSF.h>
#include <HardwareSerial.h>

// ==================== CRSF (ELRS) Pins ====================
#define CRSF_RX   17
#define CRSF_TX   16
HardwareSerial crsfSerial(1);
AlfredoCRSF crsf;

// ==================== Pin Definitions ====================
#define M1_IN1   4
#define M1_IN2   5
#define M2_IN1   14
#define M2_IN2   15

// ==================== PWM Parameters ====================
#define PWM_FREQ     1000        // 1 kHz (Better for 380 DC motors & reduces MOSFET switching heat)
#define PWM_RES      8           // 8-bit (0-255)
// New ESP32 Core 3.x+ API: ledcAttach(pin, freq, res) + ledcWrite(pin, duty)
// No channel numbers needed — use pins directly.

// ==================== Startup Power / Deadband Compensation ====================
// Adjust starting thresholds so both motors sustain ultra-low speed crawl without stalling
#define M1_START_OFFSET  10        // Minimum PWM for Motor 1 to sustain low-speed spin
#define M2_START_OFFSET  5        // Minimum PWM for Motor 2 (slightly higher to overcome stiction/friction)

// ==================== Software Kickstart Parameters ====================
#define KICKSTART_PULSE       100  // High pulse value (0-255) to overcome static stiction
#define KICKSTART_DURATION_MS  20  // Pulse duration in milliseconds
#define MIN_START_THRESHOLD    60  // PWM values under this need a kickstart burst

// ==================== Dead-Time Protection ====================
// Prevents shoot-through (both MOSFETs on same bridge leg conducting)
// when switching direction. Adjust based on your MOSFET driver's
// turn-off delay (typical: 1-10 µs for gate drivers, up to 1 µs is safe).
#define DEAD_TIME_US  5           // microseconds

// ==================== CRSF Channel Mapping ====================
// CRSF channel range: 1000 (min) – 1500 (mid) – 2000 (max)
#define CH_THROTTLE   3           // CH3 → speed magnitude (0-255)
#define CH_YAW        1           // CH1 → steering (yaw)
#define CH_DIR        6           // CH6 → 1000=forward, 1500=stop, 2000=backward
#define CH_SPEED      7           // CH7 → Three-position speed switch (1000=low, 1500=medium, 2000=high)

// Track previous direction: 1=forward, -1=reverse, 0=stop
int prevDirM1 = 0;
int prevDirM2 = 0;

// Currently active speeds
int m1Speed = 0;
int m2Speed = 0;

// ==================== Motor Control with Dead-Time ====================

void motorWrite(int in1Pin, int in2Pin, int speed,
                int *prevDir, int *storeSpeed) {
  int newDir = (speed > 0) ? 1 : (speed < 0) ? -1 : 0;

  // Dead-time: if direction changed (forward↔reverse), insert break
  if (*prevDir != 0 && newDir != 0 && *prevDir != newDir) {
    ledcWrite(in1Pin, 0);
    ledcWrite(in2Pin, 0);
    delayMicroseconds(DEAD_TIME_US);
  }

  // --- Software Kickstart (Burst) ---
  // If commencing from a complete stop (*storeSpeed == 0) to a low speed (under MIN_START_THRESHOLD)
  if (*storeSpeed == 0 && speed != 0) {
    int absSpeed = (speed > 0) ? speed : -speed;
    int offset = (in1Pin == M1_IN1) ? M1_START_OFFSET : M2_START_OFFSET;
    int finalTargetSpeed = map(absSpeed, 1, 255, offset, 255);

    if (finalTargetSpeed < MIN_START_THRESHOLD) {
      // Determine correct direction pins to burst
      int burstPin = (speed > 0) ? in1Pin : in2Pin;
      ledcWrite(burstPin, KICKSTART_PULSE);
      delay(KICKSTART_DURATION_MS); // Hold for configured duration (20ms) to break stiction
    }
  }

  *prevDir = newDir;
  *storeSpeed = speed;

  int compensatedSpeed = 0;
  if (speed > 0) {
    int offset = (in1Pin == M1_IN1) ? M1_START_OFFSET : M2_START_OFFSET;
    compensatedSpeed = map(speed, 1, 255, offset, 255);
    ledcWrite(in1Pin, compensatedSpeed);   // IN1 = PWM with startup boost
    ledcWrite(in2Pin, 0);                  // IN2 = LOW
  } else if (speed < 0) {
    int offset = (in1Pin == M1_IN1) ? M1_START_OFFSET : M2_START_OFFSET;
    compensatedSpeed = map(-speed, 1, 255, offset, 255);
    ledcWrite(in1Pin, 0);                  // IN1 = LOW
    ledcWrite(in2Pin, compensatedSpeed);   // IN2 = PWM with startup boost
  } else {
    ledcWrite(in1Pin, 0);                  // IN1 = LOW (coast)
    ledcWrite(in2Pin, 0);                  // IN2 = LOW
  }
}

void motorBrake(int in1Pin, int in2Pin, int *storeSpeed) {
  ledcWrite(in1Pin, 255);
  ledcWrite(in2Pin, 255);
  *storeSpeed = 0;
}

void motorCoast(int in1Pin, int in2Pin, int *storeSpeed) {
  ledcWrite(in1Pin, 0);
  ledcWrite(in2Pin, 0);
  *storeSpeed = 0;
}

// ==================== CRSF → Motor Mixing ====================
// Map CRSF channel (1000-2000) to PWM speed (-255..255)
int mapCRSFtoSpeed(int chVal) {
  // CRSF: 1000=min, 1500=mid, 2000=max
  // Output: -255..255 (negative=reverse, positive=forward)
  return map(chVal, 1000, 2000, -255, 255);
}

// Differential drive: combine throttle + yaw + direction into two motor speeds
void updateMotorsFromRC() {
  int thr = crsf.getChannel(CH_THROTTLE);  // 1000-2000
  int yaw = crsf.getChannel(CH_YAW);       // 1000-2000
  int dir = crsf.getChannel(CH_DIR);       // 1000=forward, 1500=stop, 2000=backward
  int spdCh = crsf.getChannel(CH_SPEED);   // 1000=low, 1500=medium, 2000=high

  // Failsafe: if no valid CRSF signal yet (channels read 0), stop motors
  if (thr < 900 || yaw < 900 || dir < 900 || spdCh < 900) {
    motorCoast(M1_IN1, M1_IN2, &m1Speed);
    motorCoast(M2_IN1, M2_IN2, &m2Speed);
    prevDirM1 = 0;
    prevDirM2 = 0;
    return;
  }

  // Speed level from CH7
  int maxLimit = 255;
  if (spdCh < 1300) {
    maxLimit = 60;    // Low speed (~1000)
  } else if (spdCh > 1700) {
    maxLimit = 255;    // High speed (~2000)
  } else {
    maxLimit = 150;    // Medium speed (~1500)
  }

  // Speed magnitude with a small deadband at low stick positions (e.g. 1000-1030) to prevent jitter creep
  int speedMag = 0;
  if (thr > 1030) {
    speedMag = map(thr, 1030, 2000, 0, maxLimit);
  }

  // Direction from CH6 (with 100-wide deadband around 1500)
  int direction = 0;
  if      (dir < 1400) direction = 1;   // forward
  else if (dir > 1600) direction = -1;  // backward
  else                 direction = 0;   // stop

  // Apply direction to speed
  int baseSpeed = speedMag * direction;

  // Steering: 1000-2000 → -maxLimit..maxLimit (center = straight)
  int steering = map(yaw, 1000, 2000, -maxLimit, maxLimit);

  // Differential mixing — motor rotation per spec:

  int m1 = constrain(baseSpeed + steering, -maxLimit, maxLimit);
  int m2 = constrain(-baseSpeed + steering, -maxLimit, maxLimit);

  motorWrite(M1_IN1, M1_IN2, m1, &prevDirM1, &m1Speed);
  motorWrite(M2_IN1, M2_IN2, m2, &prevDirM2, &m2Speed);
}

// ==================== Setup ====================
void setup() {
  Serial.begin(115200);
  Serial.println("ELRS Boat Controller starting...");

  // --- PWM (ESP32 Core 3.x+ API) ---
  ledcAttach(M1_IN1, PWM_FREQ, PWM_RES);
  ledcAttach(M1_IN2, PWM_FREQ, PWM_RES);
  ledcAttach(M2_IN1, PWM_FREQ, PWM_RES);
  ledcAttach(M2_IN2, PWM_FREQ, PWM_RES);
  motorCoast(M1_IN1, M1_IN2, &m1Speed);
  motorCoast(M2_IN1, M2_IN2, &m2Speed);

  // --- CRSF (ELRS) Receiver ---
  crsfSerial.begin(CRSF_BAUDRATE, SERIAL_8N1, CRSF_RX, CRSF_TX);
  if (!crsfSerial) {
    Serial.println("FATAL: CRSF serial port failed!");
    while (1) delay(100);
  }
  crsf.begin(crsfSerial);

  Serial.println("ESP32 Dual MOSFET Boat — ELRS RC Control");
  Serial.println("-----------------------------------------");
  Serial.println("Controls: Throttle (CH3) = speed, Yaw (CH1) = steering");
  Serial.println("Waiting for ELRS signal...");
}

// ==================== Loop ====================
void loop() {
  // Must call crsf.update() frequently to process incoming CRSF frames
  crsf.update();

  // Update motors from RC channels
  updateMotorsFromRC();

  // Serial debug every 200ms
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint >= 200) {
    lastPrint = millis();
    int thr = crsf.getChannel(CH_THROTTLE);
    int yaw = crsf.getChannel(CH_YAW);
    int dir = crsf.getChannel(CH_DIR);
    int spdCh = crsf.getChannel(CH_SPEED);
    Serial.print("CH1(Yaw)=");    Serial.print(yaw);
    Serial.print("  CH3(Thr)=");  Serial.print(thr);
    Serial.print("  CH6(Dir)=");  Serial.print(dir);
    Serial.print("  CH7(Spd)=");  Serial.print(spdCh);
    Serial.print("  M1=");        Serial.print(m1Speed);
    Serial.print("  M2=");        Serial.println(m2Speed);
  }
}
