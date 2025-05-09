// Define pins for each RC channel
int aileronPin = 14;   // Channel 1 (Throttle)
int elevatorPin = 12;  // Channel 2 (Steering)

const int ENA = 5; // PWM for speed for Motor 1
const int ENB = 4; // PWM for speed for Motor 2

const int IN1 = 0; // Direction for Motor 1
const int IN2 = 2; // Direction pin 1 for Motor 2

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

    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);

    // Initialize motors to off
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);

    Serial.begin(9600);
}

// Helper function to control a single motor
// pwmVal: -255 (full backward) to 255 (full forward)
void setMotorOutput(int dirPin, int speedPin, int pwmVal) {
    if (pwmVal > 0) { // Forward
        digitalWrite(dirPin, HIGH);
        analogWrite(speedPin, pwmVal);
    } else if (pwmVal < 0) { // Backward
        digitalWrite(dirPin, LOW);
        analogWrite(speedPin, -pwmVal); // Speed is positive
    } else { // Stop
        digitalWrite(dirPin, LOW); // Or HIGH, doesn't matter much if speed is 0
        analogWrite(speedPin, 0);
    }
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
    int deadbandRadius = 10; 
    float steeringFactor = 3; // Adjust this value to change steering sensitivity
    float throttleFactor = 3; // Adjust this value to change throttle sensitivity (e.g., 1.2 for 20% stronger throttle)

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

    // Set motor speeds and directions
    setMotorOutput(IN1, ENA, motor1Pwm); // Motor 1
    setMotorOutput(IN2, ENB, motor2Pwm); // Motor 2

    delay(20);  // Shorter delay for better responsiveness
}