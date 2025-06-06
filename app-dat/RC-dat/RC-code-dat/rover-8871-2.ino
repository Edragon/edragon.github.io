// NodeMCU (ESP8266) code to drive two DC motors with DRV8871
// Each motor uses a single GPIO:
// Motor 1: IO0 (D3) for IN1, and IN2 driven by IO0 via an inverter.
// Motor 2: IO2 (D4) for IN1, and IN2 driven by IO2 via an inverter.

#include <Adafruit_NeoPixel.h>

// Define pins for each RC channel
int aileronPin = 14;   // Channel 1 (Throttle) // D5
int elevatorPin = 12;  // Channel 2 (Steering) // D6

// --- START: Added/Modified from drv8871-rc.ino ---
// Define the NodeMCU pins for motors (consistent with drv8871-rc.ino)
// MOTOR 1
// GPIO0 (D3 on many NodeMCU boards) is used here.
// WARNING: GPIO0 is a boot mode pin. If it's LOW during boot, ESP8266 enters flash mode.
// Ensure your circuit doesn't pull GPIO0 LOW at boot unless intended.
const int MOTOR1_CTRL_PIN = 0; // GPIO0 (D3), replaces IN1

// MOTOR 2
// GPIO2 (D4 on many NodeMCU boards) is generally safe to use.
const int MOTOR2_CTRL_PIN = 2; // GPIO2 (D4), replaces IN2

// ESP8266 analogWrite range is 0-1023 by default.
// PWM_STOP is still needed for the active stopMotor function.
const int PWM_MAX = 1023;
const int PWM_STOP = PWM_MAX / 2; // Approx 511 or 512, for 50% duty cycle
// --- END: Added/Modified from drv8871-rc.ino ---

// WS2812 LED Strip Configuration
#define LED_PIN 15 // nodemcu pin D8
#define LED_COUNT 8
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

long aileronControl;  // Mapped value from aileron channel (0-100)
long elevatorControl; // Mapped value from elevator channel (0-100)

// Reads the PWM signal from the aileron channel and maps it to 0-100
long readAileronControlSignal() {
    unsigned long rawPWM = pulseIn(aileronPin, HIGH, 25000);
    // If signal is lost (timeout) or clearly out of valid RC pulse range, return neutral (50)
    // Valid RC pulses are typically 1000-2000us. Values outside ~900-2100us are treated as invalid.
    if (rawPWM == 0 || rawPWM < 900 || rawPWM > 2100) {
        return 50; // Mid-point for 0-100 scale (1500us equivalent), results in stop
    }
    // Otherwise, the signal is likely valid; constrain it to the standard 1000-2000us range and map
    long constrainedPWM = constrain(rawPWM, 1000, 2000);
    return map(constrainedPWM, 1000, 2000, 0, 100);
}

// Reads the PWM signal from the elevator channel and maps it to 0-100
long readElevatorControlSignal() {
    unsigned long rawPWM = pulseIn(elevatorPin, HIGH, 25000);
    // If signal is lost (timeout) or clearly out of valid RC pulse range, return neutral (50)
    // Valid RC pulses are typically 1000-2000us. Values outside ~900-2100us are treated as invalid.
    if (rawPWM == 0 || rawPWM < 900 || rawPWM > 2100) {
        return 50; // Mid-point for 0-100 scale (1500us equivalent), results in stop
    }
    // Otherwise, the signal is likely valid; constrain it to the standard 1000-2000us range and map
    long constrainedPWM = constrain(rawPWM, 1000, 2000);
    return map(constrainedPWM, 1000, 2000, 0, 100);
}

void setup() {
    pinMode(aileronPin, INPUT);
    pinMode(elevatorPin, INPUT); // Initialize elevator pin

    // --- START: Modified for drv8871-rc.ino motor control ---
    pinMode(MOTOR1_CTRL_PIN, OUTPUT);
    pinMode(MOTOR2_CTRL_PIN, OUTPUT);
    analogWrite(MOTOR2_CTRL_PIN, PWM_STOP);
    // --- END: Modified for drv8871-rc.ino motor control ---

    Serial.begin(9600);
    // --- START: Added/Modified from drv8871-rc.ino setup ---
    Serial.println("RC Rover with DRV8871 Single Pin Control");
    Serial.println("Note: Stop is an active stop (50% PWM).");
    Serial.print("PWM Stop value for active stop: ");
    Serial.println(PWM_STOP);

    // Ensure motors are stopped at startup
    stopMotor1();
    stopMotor2();
    // --- END: Added/Modified from drv8871-rc.ino setup ---

    strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
    strip.show();            // Turn OFF all pixels ASAP
    strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
}

// --- START: Motor control functions from drv8871-rc.ino ---
// --- Motor 1 Control Functions ---
// Function to drive Motor 1 with digital control for direction
// forward: true for forward (MOTOR1_CTRL_PIN HIGH), false for reverse (MOTOR1_CTRL_PIN LOW)
void driveMotor1(bool forward) {
  if (forward) {
    digitalWrite(MOTOR1_CTRL_PIN, HIGH);
  } else {
    digitalWrite(MOTOR1_CTRL_PIN, LOW);
  }
}

// Function to stop Motor 1 (active stop by 50% duty cycle on MOTOR1_CTRL_PIN)
void stopMotor1() {
  analogWrite(MOTOR1_CTRL_PIN, PWM_STOP);
}

// Function to "brake" Motor 1. Performs an active stop.
void brakeMotor1() {
  stopMotor1();
}

// --- Motor 2 Control Functions ---
// Function to drive Motor 2 with digital control for direction
// forward: true for forward (MOTOR2_CTRL_PIN HIGH), false for reverse (MOTOR2_CTRL_PIN LOW)
void driveMotor2(bool forward) {
  if (forward) {
    digitalWrite(MOTOR2_CTRL_PIN, HIGH);
  } else {
    digitalWrite(MOTOR2_CTRL_PIN, LOW);
  }
}

// Function to stop Motor 2
void stopMotor2() {
  // Try a different PWM value if 50% doesn't work
  analogWrite(MOTOR2_CTRL_PIN, PWM_STOP); // or try PWM_MAX
  // Alternatively, try digitalWrite
  // digitalWrite(MOTOR2_CTRL_PIN, LOW); // or try HIGH
}

// Function to "brake" Motor 2. Performs an active stop.
void brakeMotor2() {
  stopMotor2();
}
// --- END: Motor control functions from drv8871-rc.ino ---

// Helper function to map RC control input (0-100) to an output range (e.g., -255 to 255)
// with a deadband around the center (e.g., 50).
long mapWithDeadband(long rcValue, int rcMin, int rcMax, int rcCenter, int deadbandRadius, int outMin, int outMax) {
    long mappedValue = 0;
    int deadbandLower = rcCenter - deadbandRadius;
    int deadbandUpper = rcCenter + deadbandRadius;

    if (rcValue < deadbandLower) {
        // Map the range [rcMin, deadbandLower - 1] to [outMin, -1]
        // Ensure deadbandLower - 1 is not less than rcMin
        if (deadbandLower -1 < rcMin) {
             mappedValue = outMin;
        } else {
            mappedValue = map(rcValue, rcMin, deadbandLower - 1, outMin, -1);
        }
    } else if (rcValue > deadbandUpper) {
        // Map the range [deadbandUpper + 1, rcMax] to [1, outMax]
        // Ensure deadbandUpper + 1 is not greater than rcMax
        if (deadbandUpper + 1 > rcMax) {
            mappedValue = outMax;
        } else {
            mappedValue = map(rcValue, deadbandUpper + 1, rcMax, 1, outMax);
        }
    } else {
        // Inside deadband
        mappedValue = 0;
    }
    return constrain(mappedValue, outMin, outMax);
}

// Function to create a random blinking effect for WS2812 LEDs
void randomBlinkEffect() {
    for (int i = 0; i < LED_COUNT; i++) {
        // Turn on a random LED with a random color
        if (random(0, 2) == 1) { // 50% chance to turn on this LED
            strip.setPixelColor(i, strip.Color(random(0, 256), random(0, 256), random(0, 256)));
        } else {
            strip.setPixelColor(i, strip.Color(0, 0, 0)); // Turn off
        }
    }
    strip.show();   // Send the updated pixel colors to the hardware.
    delay(100);     // Wait a short period
}

void loop() {
    // Read mapped control signals from each channel
    aileronControl = readAileronControlSignal();   // Throttle (0-100)
    elevatorControl = readElevatorControlSignal(); // Steering (0-100)

    // Print the mapped control signal values to the Serial Monitor
    Serial.print("Aileron (Throttle): ");
    Serial.print(aileronControl);
    Serial.print(" Elevator (Steering): ");
    Serial.print(elevatorControl);
    // Serial.println(); // Combined with next print

    // Define deadband radius (e.g., +/- 5 around center of 50 for a 0-100 input)
    // This means input values from 45 to 55 (inclusive if center is 50 and radius is 5) will be treated as 0.
    int deadbandRadius = 15;
    // Factors to adjust how throttle and steering mix.
    // With on/off control, these primarily affect the outcome when throttle and steering have opposing commands.
    float steeringFactor = 1.0; // Start with 1.0, adjust if needed
    float throttleFactor = 1.0; // Start with 1.0, adjust if needed

    // Map control values with deadband. Output is -255 to 255, or 0 if in deadband.
    long rawThrottleValue = mapWithDeadband(aileronControl, 0, 100, 50, deadbandRadius, -255, 255);
    long rawSteeringValue = mapWithDeadband(elevatorControl, 0, 100, 50, deadbandRadius, -255, 255);

    // Apply sensitivity factors
    long throttleValue = rawThrottleValue * throttleFactor;
    long adjustedSteeringValue = rawSteeringValue * steeringFactor;

    // Mix throttle and steering for differential drive
    // The magnitude of these values will only determine the sign for direction control.
    long motor1MixedOutput = throttleValue + adjustedSteeringValue;
    long motor2MixedOutput = throttleValue - adjustedSteeringValue;

    // Print mixed output for debugging
    Serial.print(" M1_Mix: ");
    Serial.print(motor1MixedOutput);
    Serial.print(" M2_Mix: ");
    Serial.print(motor2MixedOutput);
    Serial.println();


    // --- START: Motor control logic using drv8871 functions ---
    // Motor 1 Control
    if (motor1MixedOutput > 0) {      // Any positive value means forward
        driveMotor1(true);
    } else if (motor1MixedOutput < 0) { // Any negative value means reverse
        driveMotor1(false);
    } else {                          // Zero means stop
        stopMotor1();
    }

    // Motor 2 Control
    if (motor2MixedOutput > 0) {      // Any positive value means forward
        driveMotor2(true);
    } else if (motor2MixedOutput < 0) { // Any negative value means reverse
        driveMotor2(false);
    } else {                          // Zero means stop
        stopMotor2();
    }
    // --- END: Motor control logic using drv8871 functions ---

    // Add the LED effect
    randomBlinkEffect(); // This function contains a delay(100)

    delay(20);  // Delay for RC input reading cycle. Total loop delay is this + randomBlinkEffect delay.

    // At the end of your loop
    Serial.print("Motor2 Output: ");
    if (motor2MixedOutput > 0) {
      Serial.println("FORWARD");
    } else if (motor2MixedOutput < 0) {
      Serial.println("REVERSE");
    } else {
      Serial.println("STOP COMMANDED");
    }
}