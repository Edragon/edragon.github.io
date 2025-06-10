// Define pins for each RC channel
int aileronPin = 14;   // Channel 1 (Throttle) // D5
int elevatorPin = 12;  // Channel 2 (Steering) // D6

const int MOTOR1_CTRL_PIN = 4; // GPIO4 (D2)
const int MOTOR2_CTRL_PIN = 5; // GPIO5 (D1)

long aileronControl;  // Mapped value from aileron channel (0-100)
long elevatorControl; // Mapped value from elevator channel (0-100)

unsigned long rawAileronPWM = 0;
unsigned long rawElevatorPWM = 0;

const int PWM_MAX = 1023;  // ESP8266 PWM range is 0-1023
const int PWM_STOP = PWM_MAX / 2;  // ~511 or 512

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
    pinMode(elevatorPin, INPUT); // Initialize elevator pin
    
    pinMode(MOTOR1_CTRL_PIN, OUTPUT);
    pinMode(MOTOR2_CTRL_PIN, OUTPUT);

    Serial.begin(9600);
    brakeMotor1();
    brakeMotor2();
}

void driveMotor1(bool forward) {
  if (forward) {
    digitalWrite(MOTOR1_CTRL_PIN, HIGH);
  } else {
    digitalWrite(MOTOR1_CTRL_PIN, LOW);
  }
}

void brakeMotor1() {
  analogWrite(MOTOR1_CTRL_PIN, PWM_STOP);
}

void driveMotor2(bool forward) {
  if (forward) {
    digitalWrite(MOTOR2_CTRL_PIN, HIGH);
  } else {
    digitalWrite(MOTOR2_CTRL_PIN, LOW);
  }
}

void brakeMotor2() {
  analogWrite(MOTOR2_CTRL_PIN, PWM_STOP);
}

void loop() {
    // Read mapped control signals from each channel
    aileronControl = readAileronControlSignal();   // Throttle (0-100)
    elevatorControl = readElevatorControlSignal(); // Steering (0-100)

    // Simplified driving approach - no mixing
    String motor1Command = "STOP";
    String motor2Command = "STOP";
    
    // Handle throttle control (forward/reverse)
    if (aileronControl > 60) {
        // Forward
        driveMotor1(true);
        driveMotor2(true);
        motor1Command = "FORWARD";
        motor2Command = "FORWARD";
    } else if (aileronControl < 40) {
        // Reverse
        driveMotor1(false);
        driveMotor2(false);
        motor1Command = "REVERSE";
        motor2Command = "REVERSE";
    } else if (elevatorControl > 60) {
        // Turn right (M1 forward, M2 reverse)
        driveMotor1(true);
        driveMotor2(false);
        motor1Command = "FORWARD";
        motor2Command = "REVERSE";
    } else if (elevatorControl < 40) {
        // Turn left (M1 reverse, M2 forward)
        driveMotor1(false);
        driveMotor2(true);
        motor1Command = "REVERSE";
        motor2Command = "FORWARD";
    } else {
        // Stop
        brakeMotor1();
        brakeMotor2();
    }

    // 1. RC INPUTS
    Serial.print("RC INPUT: ");
    Serial.print("Aileron="); Serial.print(rawAileronPWM); Serial.print("us ("); Serial.print(aileronControl); Serial.print("%), ");
    Serial.print("Elevator="); Serial.print(rawElevatorPWM); Serial.print("us ("); Serial.print(elevatorControl); Serial.println("%)");
    
    // 2. COMMANDS
    Serial.print("MOTORS:   ");
    Serial.print("M1="); Serial.print(motor1Command); Serial.print(", ");
    Serial.print("M2="); Serial.println(motor2Command);

    Serial.println();

    delay(20);  // Delay for RC input reading cycle
}