/*
 * SDR1132 - ESP32 dual MOSFET H-bridge drive, slow -> full speed ramp
 *
 * Hardware: two H-bridge (4x MOSFET) channels driven by the ESP32
 *   Motor 1 : IN1 = IO4   IN2 = IO5
 *   Motor 2 : IN1 = IO19  IN2 = IO21
 *
 * Drive logic (taken from SDR1129-ELRS-boat-1.ino):
 *   speed > 0 : IN1 = PWM, IN2 = 0    (forward)
 *   speed < 0 : IN1 = 0,   IN2 = PWM  (reverse)
 *   speed = 0 : IN1 = 0,   IN2 = 0    (coast)
 *   brake     : IN1 = IN2 = 255       (short brake)
 *   Includes dead-time on direction change, low-speed deadband
 *   compensation (start offset) and a software kickstart burst.
 *
 * Sequence: both motors ramp together from MIN_SPEED up to FULL_SPEED,
 *           hold at full speed, coast, pause, then repeat.
 *
 * Uses the ESP32 Core 3.x LEDC API:
 *   ledcAttach(pin, freq, res) + ledcWrite(pin, duty)
 */

#include <Arduino.h> // harmless in the IDE, needed by PlatformIO / IntelliSense

// ---- Pin definition ----
const uint8_t M1_IN1 = 4;  // motor 1, bridge input A
const uint8_t M1_IN2 = 5;  // motor 1, bridge input B
const uint8_t M2_IN1 = 19; // motor 2, bridge input A
const uint8_t M2_IN2 = 21; // motor 2, bridge input B

// ---- PWM (ESP32 LEDC) ----
#define PWM_FREQ 1000 // 1 kHz (better for 380 DC motors, less MOSFET switching heat)
#define PWM_RES  8    // 8-bit (0..255)

// ---- Startup power / deadband compensation ----
// Minimum PWM each motor needs to sustain a low-speed crawl without stalling
#define M1_START_OFFSET 10 // minimum effective PWM for motor 1
#define M2_START_OFFSET 5  // minimum effective PWM for motor 2

// ---- Software kickstart ----
#define KICKSTART_PULSE      100 // high pulse (0..255) to overcome static stiction
#define KICKSTART_DURATION_MS 20 // pulse duration in milliseconds
#define MIN_START_THRESHOLD   60 // speeds under this need a kickstart burst

// ---- Dead-time protection ----
// Prevents shoot-through (both MOSFETs on one bridge leg conducting)
// when the direction changes. Match your gate driver's turn-off delay.
#define DEAD_TIME_US 5 // microseconds

// ---- Speed ramp (0..255) ----
const uint8_t MIN_SPEED  = 30;  // duty at which the motor just starts to turn
const uint8_t FULL_SPEED = 255; // full speed
const uint8_t RAMP_STEP  = 5;   // duty added per ramp step

// ---- Timing (ms) ----
const unsigned long RAMP_STEP_MS = 25;   // time per ramp step (~1.1 s slow -> full)
const unsigned long HOLD_TIME    = 3000; // hold at full speed
const unsigned long STOP_TIME    = 2000; // pause between cycles

// ---- Drive state ----
int prevDirM1 = 0; // 1 = forward, -1 = reverse, 0 = stop
int prevDirM2 = 0;
int m1Speed   = 0; // last speed written to motor 1
int m2Speed   = 0;

// ---- Forward declarations ----
void motorWrite(int in1Pin, int in2Pin, int speed, int *prevDir, int *storeSpeed);
void motorBrake(int in1Pin, int in2Pin, int *storeSpeed);
void motorCoast(int in1Pin, int in2Pin, int *storeSpeed);
void motorsCoastAll();
void setBothMotors(int speed);
void rampSlowToFull();

void setup()
{
    Serial.begin(115200);
    delay(200); // let the USB serial settle

    // Attach all four bridge inputs to LEDC PWM
    ledcAttach(M1_IN1, PWM_FREQ, PWM_RES);
    ledcAttach(M1_IN2, PWM_FREQ, PWM_RES);
    ledcAttach(M2_IN1, PWM_FREQ, PWM_RES);
    ledcAttach(M2_IN2, PWM_FREQ, PWM_RES);

    motorsCoastAll(); // always start from a known OFF state

    Serial.println(F("SDR1132 dual motor ramp demo (ELRS boat drive logic)"));
}

void loop()
{
    // 1) Ramp both motors from slow to full speed
    Serial.println(F("ramp: slow -> full"));
    rampSlowToFull();

    // 2) Hold at full speed
    Serial.println(F("full speed hold"));
    delay(HOLD_TIME);

    // 3) Stop, then repeat
    Serial.println(F("STOP (coast)"));
    motorsCoastAll();
    delay(STOP_TIME);
}

// ==================== Motor drive (from SDR1129-ELRS-boat-1.ino) ====================

void motorWrite(int in1Pin, int in2Pin, int speed,
                int *prevDir, int *storeSpeed) {
  int newDir = (speed > 0) ? 1 : (speed < 0) ? -1 : 0;

  // Dead-time: if direction changed (forward<->reverse), insert break
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

// ==================== Demo sequence helpers ====================

// Coast both motors and reset the tracked direction
void motorsCoastAll()
{
    motorCoast(M1_IN1, M1_IN2, &m1Speed);
    motorCoast(M2_IN1, M2_IN2, &m2Speed);
    prevDirM1 = 0;
    prevDirM2 = 0;
}

// Apply the same forward speed to both motors
void setBothMotors(int speed)
{
    motorWrite(M1_IN1, M1_IN2, speed, &prevDirM1, &m1Speed);
    motorWrite(M2_IN1, M2_IN2, speed, &prevDirM2, &m2Speed);
}

// Step the duty from MIN_SPEED up to FULL_SPEED
void rampSlowToFull()
{
    // uint16_t counter so it can pass 255 without wrapping around
    for (uint16_t s = MIN_SPEED; s <= FULL_SPEED; s += RAMP_STEP)
    {
        setBothMotors((int)s);
        Serial.printf("speed %u\n", (unsigned)s);
        delay(RAMP_STEP_MS);
    }

    setBothMotors(FULL_SPEED); // make sure we end exactly at full speed
}

