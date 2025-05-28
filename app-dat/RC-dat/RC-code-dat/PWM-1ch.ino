// Define pins for each RC channel
int aileronPin = 2;   // Channel 1

const int ENA = 5; // PWM for speed for Motor 1
const int ENB = 4; // PWM for speed for Motor 2

const int IN1 = 0; // Direction for Motor 1 (IN2_Motor1 is inverted in hardware)
const int IN2 = 2; // Direction pin 1 for Motor 2

long aileronControl;

long readAileronControlSignal() {
    unsigned long rawPWM = pulseIn(aileronPin, HIGH, 25000);
    if (rawPWM == 0) { // Timeout or no signal
        return 50; // Mid-point for 0-100 scale (1500us equivalent)
    }
    long constrainedPWM = constrain(rawPWM, 1000, 2000);
    return map(constrainedPWM, 1000, 2000, 0, 100);
}

void setup() {
    pinMode(aileronPin, INPUT);

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

void loop() {
    // Read mapped control signals from each channel
    aileronControl = readAileronControlSignal();

    // Print the mapped control signal values to the Serial Monitor
    Serial.print("Aileron: ");
    Serial.print(aileronControl);
    Serial.println(); // Newline for better readability

    if (aileronControl > 70) {
        // Forward
        digitalWrite(IN1, HIGH); // Motor 1 forward
        digitalWrite(IN2, HIGH); // Motor 2 forward 

        // Map aileronControl (61-100) to PWM speed (e.g., 100-255)
        int motorSpeed = map(aileronControl, 61, 100, 100, 255);
        analogWrite(ENA, motorSpeed);
        analogWrite(ENB, motorSpeed);
    } else if (aileronControl < 30) {
        // Backward
        digitalWrite(IN1, LOW);  // Motor 1 backward
        digitalWrite(IN2, LOW);  // Motor 2 backward

        // Map aileronControl (0-39) to PWM speed (e.g., 255-100, reversing the range for backward)
        int motorSpeed = map(aileronControl, 0, 39, 255, 100); 
        analogWrite(ENA, motorSpeed);
        analogWrite(ENB, motorSpeed);
    } else {
        // Stop motors (aileronControl is between 40 and 60 inclusive)
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        analogWrite(ENA, 0);
        analogWrite(ENB, 0);
    }

    delay(100);  // Limit output rate
}