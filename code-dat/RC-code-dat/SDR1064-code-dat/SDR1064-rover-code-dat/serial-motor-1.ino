// Define pins for motor control
const int ENA = 5; // PWM for speed for Motor (single motor)

const int IN1 = 0; // Direction pin A for Motor
const int IN2 = 2 // Direction pin B for Motor

int motorControl = 50; // 0..100, default mid-point

int readControlSignal() {
    // Read control value from Serial if available (expects an integer 0-100 followed by newline)
    if (Serial.available()) {
        String s = Serial.readStringUntil('\n');
        s.trim();
        if (s.length() > 0) {
            int val = s.toInt();
            if (val >= 0 && val <= 100) {
                motorControl = val;
            }
        }
    }
    return motorControl;
}

void setup() {
    // No RC input pin used — control comes from Serial

    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);

    // Initialize motor to off
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 0);

    Serial.begin(9600);
    Serial.println("Motor control ready. Send 0-100 via serial to control speed/direction.");
}

void loop() {
    // Read mapped control signal (from Serial)
    motorControl = readControlSignal();

    // Print the mapped control signal values to the Serial Monitor
    Serial.print("Control: ");
    Serial.print(motorControl);
    Serial.println(); // Newline for better readability

    // Deadband: treat 40..60 as stop (adjust if needed)
    if (motorControl > 60) {
        // Forward: IN1 = HIGH, IN2 = LOW
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);

        // Map motorControl (61-100) to PWM speed (0-255)
        int motorSpeed = map(motorControl, 61, 100, 0, 255);
        motorSpeed = constrain(motorSpeed, 0, 255);
        analogWrite(ENA, motorSpeed);
    } else if (motorControl < 40) {
        // Reverse: IN1 = LOW, IN2 = HIGH
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);

        // Map motorControl (0-39) to PWM speed (0-255)
        int motorSpeed = map(motorControl, 0, 39, 0, 255);
        motorSpeed = constrain(motorSpeed, 0, 255);
        analogWrite(ENA, motorSpeed);
    } else {
        // Stop motor (motorControl is between 40 and 60 inclusive)
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        analogWrite(ENA, 0);
    }

    delay(100);  // Limit output rate
}