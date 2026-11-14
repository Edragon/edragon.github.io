/*
 * SDR1129 simple dual-motor test
 *
 * Test sequence (loop):
 * 1) CW  5s: speed ramps from slow to fast
 * 2) Stop 2s
 * 3) CCW 5s: speed ramps from slow to fast
 * 4) Stop 2s
 *
 * Pin mapping copied from existing project:
 *   Motor 1: IN1 -> GPIO4   IN2 -> GPIO5
 *   Motor 2: IN1 -> GPIO14  IN2 -> GPIO15
 *
 * Drive logic:
 *   IN1 = PWM, IN2 = 0   -> CW
 *   IN1 = 0,   IN2 = PWM -> CCW
 *   IN1 = 0,   IN2 = 0   -> coast (stop)
 *
 * Protection:
 *   - Dead time: 5 us coast gap on every CW <-> CCW change, so both
 *     MOSFETs on one bridge leg never conduct at the same time.
 *   - Dead zone: ramp starts at SLOW_DUTY, the lowest duty that still
 *     turns the motor, so it never hangs in the stall band.
 */

#define M1_IN1 4
#define M1_IN2 5
#define M2_IN1 19
#define M2_IN2 21

#define PWM_FREQ 5000
#define PWM_RES  8

#define RAMP_TIME_MS 5000
#define STOP_TIME_MS 2000
#define DEAD_TIME_US 5

#define SLOW_DUTY 35
#define FAST_DUTY 255
#define STEPS 100

int prevDir = 0;  // 1=CW, -1=CCW, 0=stop

void writeSingleMotor(int in1Pin, int in2Pin, int speed) {
  if (speed > 0) {
    ledcWrite(in1Pin, speed);
    ledcWrite(in2Pin, 0);
  } else if (speed < 0) {
    ledcWrite(in1Pin, 0);
    ledcWrite(in2Pin, -speed);
  } else {
    ledcWrite(in1Pin, 0);
    ledcWrite(in2Pin, 0);
  }
}

void writeBothMotors(int speed) {
  int newDir = (speed > 0) ? 1 : (speed < 0) ? -1 : 0;

  // Dead-time protection when direction changes CW <-> CCW.
  if (prevDir != 0 && newDir != 0 && prevDir != newDir) {
    writeSingleMotor(M1_IN1, M1_IN2, 0);
    writeSingleMotor(M2_IN1, M2_IN2, 0);
    delayMicroseconds(DEAD_TIME_US);
  }

  prevDir = newDir;
  writeSingleMotor(M1_IN1, M1_IN2, speed);
  writeSingleMotor(M2_IN1, M2_IN2, speed);
}

void motorStop() {
  writeBothMotors(0);
}

// dir = +1 -> CW, dir = -1 -> CCW
// Ramps both motors from SLOW_DUTY (dead-zone floor) up to FAST_DUTY.
void ramp(int dir) {
  for (int i = 0; i < STEPS; i++) {
    int duty = map(i, 0, STEPS - 1, SLOW_DUTY, FAST_DUTY);
    writeBothMotors(dir * duty);
    delay(RAMP_TIME_MS / STEPS);
  }
}

void setup() {
  Serial.begin(115200);

  ledcAttach(M1_IN1, PWM_FREQ, PWM_RES);
  ledcAttach(M1_IN2, PWM_FREQ, PWM_RES);
  ledcAttach(M2_IN1, PWM_FREQ, PWM_RES);
  ledcAttach(M2_IN2, PWM_FREQ, PWM_RES);

  motorStop();
  Serial.println("Start dual-motor CW/CCW ramp test");
}

void loop() {
  Serial.println("CW ramp 5s (both motors)");
  ramp(1);

  Serial.println("Stop 2s (coast)");
  motorStop();
  delay(STOP_TIME_MS);

  Serial.println("CCW ramp 5s (both motors)");
  ramp(-1);

  Serial.println("Stop 2s (coast)");
  motorStop();
  delay(STOP_TIME_MS);
}
