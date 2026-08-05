#include <Adafruit_NeoPixel.h>

// Define pins for each RC channel
int aileronPin = 14;   // Channel 1 (Throttle) // D5
int elevatorPin = 12;  // Channel 2 (Steering) // D6

// WS2812 LED Strip Configuration
#define LED_PIN 15 // nodemcu pin D8 
#define LED_COUNT 8 
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// Updated comments for IN1 and IN2 to reflect their role as single control pins
const int IN1 = 4; // Control pin for Motor 1  // D3 (was GPIO2 on NodeMCU D4, now D2/GPIO4)
const int IN2 = 5; // Control pin for Motor 2 // D4 (was GPIO0 on NodeMCU D3, now D1/GPIO5)

const int PWM_MAX = 255;  // ESP8266 PWM range is 0-255 for analogWrite.
                          // Note: Default ESP8266 analogWrite range is 0-1023. 
                          // Call analogWriteRange(255) in setup if 0-255 is desired.
const int PWM_STOP = PWM_MAX / 2;  // Approx. 127, this is brake/neutral for DRV8871 single-pin
const int PWM_MIN_MOVING = 10; // Minimum offset from PWM_STOP to ensure movement


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

    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);

    // Initialize motors to brake state
    analogWrite(IN1, PWM_STOP);
    analogWrite(IN2, PWM_STOP);

    Serial.begin(9600);
    // If you intend PWM_MAX to be 255, you might need to call:
    // analogWriteRange(255); 
    // Otherwise, analogWrite will use a 0-1023 range by default on ESP8266.

    strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
    strip.show();            // Turn OFF all pixels ASAP
    strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
}

// Updated helper function to control a single motor using one control pin
// motorCtrlPin: The pin connected to the motor driver's input (e.g., IN1 for motor 1)
// pwmVal: -255 (full backward) to 255 (full forward), 0 for brake
void setMotorOutput(int motorCtrlPin, int pwmVal) {
    int actualPwm;
    if (pwmVal == 0) {
        actualPwm = PWM_STOP; // Brake
    } else if (pwmVal > 0) { // Forward
        // Map pwmVal from (1 to 255) to (PWM_STOP + PWM_MIN_MOVING to PWM_MAX)
        actualPwm = map(pwmVal, 1, 255, PWM_STOP + PWM_MIN_MOVING, PWM_MAX);
        // Ensure the value is within the defined forward motion range
        actualPwm = constrain(actualPwm, PWM_STOP + PWM_MIN_MOVING, PWM_MAX);
    } else { // Backward (pwmVal < 0)
        // Map abs(pwmVal) from (1 to 255) to (PWM_STOP - PWM_MIN_MOVING to 0)
        actualPwm = map(abs(pwmVal), 1, 255, PWM_STOP - PWM_MIN_MOVING, 0);
        // Ensure the value is within the defined reverse motion range
        actualPwm = constrain(actualPwm, 0, PWM_STOP - PWM_MIN_MOVING);
    }
    analogWrite(motorCtrlPin, actualPwm);
}

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
    Serial.println();

    // Define deadband radius (e.g., +/- 5 around center of 50 for a 0-100 input)
    // This means input values from 45 to 55 (inclusive if center is 50 and radius is 5) will be treated as 0.
    int deadbandRadius = 15; 
    float steeringFactor = 1; // Adjust this value to change steering sensitivity
    float throttleFactor = 1; // Adjust this value to change throttle sensitivity (e.g., 1.2 for 20% stronger throttle)

    // Map control values with deadband
    long rawThrottleValue = mapWithDeadband(aileronControl, 0, 100, 50, deadbandRadius, -255, 255);
    long rawSteeringValue = mapWithDeadband(elevatorControl, 0, 100, 50, deadbandRadius, -255, 255);

    // Apply sensitivity factors
    long throttleValue = rawThrottleValue * throttleFactor;
    long adjustedSteeringValue = rawSteeringValue * steeringFactor;

    // Mix throttle and steering for differential drive
    long motor1Pwm = throttleValue + adjustedSteeringValue;
    long motor2Pwm = throttleValue - adjustedSteeringValue;

    // Constrain PWM values to the valid range [-255, 255]
    motor1Pwm = constrain(motor1Pwm, -255, 255);
    motor2Pwm = constrain(motor2Pwm, -255, 255);

    // Set motor speeds and directions using the updated function
    setMotorOutput(IN1, motor1Pwm); // Motor 1
    setMotorOutput(IN2, motor2Pwm); // Motor 2

    // Add the LED effect
    randomBlinkEffect();

    delay(20);  // Shorter delay for better responsiveness
}