// Define pins for each RC channel
int aileronPin = 14;   // Channel 1 (Throttle) // D5
int elevatorPin = 12;  // Channel 2 (Steering) // D6

const int MOTOR1_CTRL_PIN = 4; // GPIO4 (D2)
const int MOTOR2_CTRL_PIN = 5; // GPIO5 (D1)

long aileronControl;  // Mapped value from aileron channel (0-100)
long elevatorControl; // Mapped value from elevator channel (0-100)

unsigned long rawAileronPWM = 0;
unsigned long rawElevatorPWM = 0;

const int PWM_MAX = 255;  // ESP8266 PWM range is 0-255 for analogWrite
const int PWM_STOP = PWM_MAX / 2;  // Approx. 127, this is brake/neutral for DRV8871 single-pin
const int PWM_MIN_MOVING = 10; // Minimum offset from PWM_STOP to ensure movement

// Add these global variables for current speeds and ramp step
int currentMotor1Speed = PWM_STOP;
int currentMotor2Speed = PWM_STOP;
const int RAMP_STEP = 5; // Adjust for desired smoothness. Smaller is smoother.

long readAileronControlSignal() {
    rawAileronPWM = pulseIn(aileronPin, HIGH, 25000);
    if (rawAileronPWM == 0 || rawAileronPWM < 900 || rawAileronPWM > 2100) {
        return 50; // Mid-point for 0-100 scale (1500us equivalent), results in stop
    }
    // Otherwise, the signal is likely valid; constrain it to the standard 1000-2000us range and map
    long constrainedPWM = constrain(rawAileronPWM, 1000, 2000);
    return map(constrainedPWM, 1000, 2000, 0, 100);
}

long readElevatorControlSignal() {
    rawElevatorPWM = pulseIn(elevatorPin, HIGH, 25000);
    if (rawElevatorPWM == 0 || rawElevatorPWM < 900 || rawElevatorPWM > 2100) {
        return 50; // Mid-point for 0-100 scale (1500us equivalent), results in stop
    }
    // Otherwise, the signal is likely valid; constrain it to the standard 1000-2000us range and map
    long constrainedPWM = constrain(rawElevatorPWM, 1000, 2000);
    return map(constrainedPWM, 1000, 2000, 0, 100);
}

void setup() {
    pinMode(aileronPin, INPUT);
    pinMode(elevatorPin, INPUT); 
    
    pinMode(MOTOR1_CTRL_PIN, OUTPUT);
    pinMode(MOTOR2_CTRL_PIN, OUTPUT);

    Serial.begin(9600);
    
    // Initialize motors to braked state using currentSpeed variables
    currentMotor1Speed = PWM_STOP;
    currentMotor2Speed = PWM_STOP;
    analogWrite(MOTOR1_CTRL_PIN, currentMotor1Speed);
    analogWrite(MOTOR2_CTRL_PIN, currentMotor2Speed);
}

void loop() {
    // Read mapped control signals from each channel
    aileronControl = readAileronControlSignal();   // Throttle (0-100)
    elevatorControl = readElevatorControlSignal(); // Steering (0-100)

    String motor1TargetCommand = "BRAKE"; // Command based on stick input
    String motor2TargetCommand = "BRAKE";
    int targetMotor1Speed = PWM_STOP;    // Target speed for this loop iteration
    int targetMotor2Speed = PWM_STOP;    // Target speed for this loop iteration
    
    // Handle throttle control (forward/reverse)
    if (aileronControl > 55) {
        // Forward
        int speed = map(aileronControl, 61, 100, PWM_STOP + PWM_MIN_MOVING, PWM_MAX);
        speed = constrain(speed, PWM_STOP + PWM_MIN_MOVING, PWM_MAX); 
        targetMotor1Speed = speed;
        targetMotor2Speed = speed;
        motor1TargetCommand = "FORWARD";
        motor2TargetCommand = "FORWARD";
    } else if (aileronControl < 45) {
        // Reverse
        int speed = map(aileronControl, 39, 0, PWM_STOP - PWM_MIN_MOVING, 0);
        speed = constrain(speed, 0, PWM_STOP - PWM_MIN_MOVING); 
        targetMotor1Speed = speed;
        targetMotor2Speed = speed;
        motor1TargetCommand = "REVERSE";
        motor2TargetCommand = "REVERSE";
    } else if (elevatorControl > 55) {
        // Turn right (throttle is neutral)
        int turnOffset = map(elevatorControl, 61, 100, PWM_MIN_MOVING, (PWM_MAX - PWM_STOP)); 
        targetMotor1Speed = constrain(PWM_STOP + turnOffset, 0, PWM_MAX);
        targetMotor2Speed = constrain(PWM_STOP - turnOffset, 0, PWM_MAX);
        motor1TargetCommand = "TURN_R_M1";
        motor2TargetCommand = "TURN_R_M2";
    } else if (elevatorControl < 45) {
        // Turn left (throttle is neutral)
        int turnOffset = map(elevatorControl, 39, 0, PWM_MIN_MOVING, (PWM_MAX - PWM_STOP));
        targetMotor1Speed = constrain(PWM_STOP - turnOffset, 0, PWM_MAX);
        targetMotor2Speed = constrain(PWM_STOP + turnOffset, 0, PWM_MAX);
        motor1TargetCommand = "TURN_L_M1";
        motor2TargetCommand = "TURN_L_M2";
    } else {
        // All sticks neutral - Target speeds remain PWM_STOP (Brake)
        // motor1TargetCommand and motor2TargetCommand remain "BRAKE"
    }

    // Ramping logic for Motor 1
    if (currentMotor1Speed < targetMotor1Speed) {
        currentMotor1Speed = min(currentMotor1Speed + RAMP_STEP, targetMotor1Speed);
    } else if (currentMotor1Speed > targetMotor1Speed) {
        currentMotor1Speed = max(currentMotor1Speed - RAMP_STEP, targetMotor1Speed);
    }

    // Ramping logic for Motor 2
    if (currentMotor2Speed < targetMotor2Speed) {
        currentMotor2Speed = min(currentMotor2Speed + RAMP_STEP, targetMotor2Speed);
    } else if (currentMotor2Speed > targetMotor2Speed) {
        currentMotor2Speed = max(currentMotor2Speed - RAMP_STEP, targetMotor2Speed);
    }

    // Apply the ramped speeds
    analogWrite(MOTOR1_CTRL_PIN, currentMotor1Speed);
    analogWrite(MOTOR2_CTRL_PIN, currentMotor2Speed);
    
    Serial.print("RC INPUT: ");
    Serial.print("Aileron="); Serial.print(rawAileronPWM); Serial.print("us ("); Serial.print(aileronControl); Serial.print("%), ");
    Serial.print("Elevator="); Serial.print(rawElevatorPWM); Serial.print("us ("); Serial.print(elevatorControl); Serial.print("%)");
    Serial.print("MOTORS:   ");
    Serial.print("M1_Cmd="); Serial.print(motor1TargetCommand); Serial.print(" (CurPWM:"); Serial.print(currentMotor1Speed); Serial.print(" TgtPWM:"); Serial.print(targetMotor1Speed); Serial.print("), ");
    Serial.print("M2_Cmd="); Serial.print(motor2TargetCommand); Serial.print(" (CurPWM:"); Serial.print(currentMotor2Speed); Serial.print(" TgtPWM:"); Serial.print(targetMotor2Speed); Serial.print(")");

    Serial.println();
    delay(20);  // Delay for RC input reading cycle & ramping interval
}