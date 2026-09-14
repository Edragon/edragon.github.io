/*
 * MOSFET H-bridge demo - single DC motor, PWM speed + direction
 *
 * Hardware: 4x MOSFET full H-bridge (2 MOSFETs per side)
 *   IN1 = PWM -> bridge input A
 *   IN2 = PWM -> bridge input B
 *
 *   CW  : IN1 = speed, IN2 = LOW
 *   CCW : IN1 = LOW,   IN2 = speed
 *   STOP: IN1 = LOW,   IN2 = LOW   (coast)
 *
 * Sequence: CW 5s -> STOP 3s -> CCW 5s -> STOP 3s -> repeat
 *
 * Fixes vs. first version:
 *   1. Forward declarations added (compiles on strict / non-Arduino toolchains)
 *   2. Soft-start ramp added - full duty from standstill collapses the supply
 *      and is the usual reason a big motor "won't start"
 *   3. Explicit DEAD_TIME when changing direction (prevents shoot-through)
 *   4. Optional active-LOW support for boards with inverted inputs
 *   5. Serial state logging so you can see the sequence is actually running
 */

#include <Arduino.h> // explicit include (harmless in the IDE, needed by PlatformIO/IntelliSense)

// ---- Pin definition (must be PWM capable: 3,5,6,9,10,11 on Uno/Nano) ----
const uint8_t IN1 = 9;  // PWM pin
const uint8_t IN2 = 10; // PWM pin

// Set to 1 if your driver board inputs are active-LOW (inverted logic)
#define BOARD_ACTIVE_LOW 0

// ---- Speed settings (0..255) ----
const uint8_t SPEED     = 200; // target duty cycle
const uint8_t MIN_SPEED = 60;  // duty at which the motor just starts to turn
const uint8_t RAMP_STEP = 5;   // duty added per soft-start step

// ---- Timing (ms) ----
const unsigned long RAMP_STEP_MS = 15;   // delay per soft-start step
const unsigned long RUN_TIME     = 5000; // CW / CCW run time
const unsigned long STOP_TIME    = 3000; // stop time
const unsigned long DEAD_TIME    = 50;   // both inputs OFF when changing direction

// ---- Forward declarations ----
void motorRun(bool cw, uint8_t speed);
void motorRamp(bool cw, uint8_t speed);
void motorCW(uint8_t speed);
void motorCCW(uint8_t speed);
void motorStop();

void setup()
{
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);

    motorStop(); // always start from a known OFF state

    Serial.begin(115200);
    Serial.println(F("MOSFET H-bridge demo start"));
}

void loop()
{
    // 1) Run clockwise for 5 seconds (soft start)
    Serial.println(F("CW"));
    motorCW(SPEED);
    delay(RUN_TIME);

    // 2) Stop for 3 seconds
    Serial.println(F("STOP"));
    motorStop();
    delay(STOP_TIME);
    delay(DEAD_TIME);

    // 3) Run counter-clockwise for 5 seconds (soft start)
    Serial.println(F("CCW"));
    motorCCW(SPEED);
    delay(RUN_TIME);

    // 4) Stop before repeating
    Serial.println(F("STOP"));
    motorStop();
    delay(STOP_TIME);
    delay(DEAD_TIME);
}

// ---- Motor control helpers ----

// Drive the bridge: one input gets PWM, the other is held firmly off
void motorRun(bool cw, uint8_t speed)
{
    uint8_t dutyA = cw ? speed : 0;
    uint8_t dutyB = cw ? 0 : speed;

#if BOARD_ACTIVE_LOW
    dutyA = 255 - dutyA;
    dutyB = 255 - dutyB;
#endif

    analogWrite(IN1, dutyA);
    analogWrite(IN2, dutyB);
}

// Soft start: step the duty up from MIN_SPEED to the target speed
void motorRamp(bool cw, uint8_t speed)
{
    if (speed < MIN_SPEED)
        speed = MIN_SPEED;

    for (uint8_t s = MIN_SPEED; s < speed; s += RAMP_STEP)
    {
        motorRun(cw, s);
        delay(RAMP_STEP_MS);
    }
    motorRun(cw, speed);
}

// Clockwise, with soft start
void motorCW(uint8_t speed)
{
    motorRamp(true, speed);
}

// Counter-clockwise, with soft start
void motorCCW(uint8_t speed)
{
    motorRamp(false, speed);
}

// Coast: both bridge inputs off
void motorStop()
{
    analogWrite(IN1, BOARD_ACTIVE_LOW ? 255 : 0);
    analogWrite(IN2, BOARD_ACTIVE_LOW ? 255 : 0);
}

