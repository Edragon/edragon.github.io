// ...existing code...
// Pins for Motor 1 (Left Motor)
const int ENA = 5; // PWM for speed for Motor 1
const int IN1 = 0; // Direction for Motor 1 (IN2_Motor1 is inverted in hardware)

// Pins for Motor 2 (Right Motor)
const int ENB = 4; // PWM for speed for Motor 2
const int IN2 = 2; // Direction pin 1 for Motor 2

// Define a speed for the motors
const int motorSpeed = 200;

void setup()
{
    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);

    pinMode(ENB, OUTPUT);
    pinMode(IN2, OUTPUT);

    Serial.begin(9600);
    stopMotors(); // Start with motors stopped
}

void goForward() {
    Serial.println("Moving Forward");
    // Motor 1 Forward
    digitalWrite(IN1, HIGH);
    analogWrite(ENA, motorSpeed);
    // Motor 2 Forward
    digitalWrite(IN2, HIGH);
    analogWrite(ENB, motorSpeed);
}

void goBackward() {
    Serial.println("Moving Backward");
    // Motor 1 Backward
    digitalWrite(IN1, LOW);
    analogWrite(ENA, motorSpeed);
    // Motor 2 Backward
    digitalWrite(IN2, LOW);
    analogWrite(ENB, motorSpeed);
}

void turnLeft() {
    Serial.println("Turning Left");
    // Motor 1 (Left) Backward
    digitalWrite(IN1, LOW);
    analogWrite(ENA, motorSpeed);
    // Motor 2 (Right) Forward
    digitalWrite(IN2, HIGH);
    analogWrite(ENB, motorSpeed);
}

void turnRight() {
    Serial.println("Turning Right");
    // Motor 1 (Left) Forward
    digitalWrite(IN1, HIGH);
    analogWrite(ENA, motorSpeed);
    // Motor 2 (Right) Backward
    digitalWrite(IN2, LOW);
    analogWrite(ENB, motorSpeed);
}

void stopMotors() {
    Serial.println("Stopping Motors");
    // Stop Motor 1
    analogWrite(ENA, 0);
    // Stop Motor 2
    analogWrite(ENB, 0);
}

void loop()
{
    goForward();
    delay(2000);

    stopMotors();
    delay(1000);

    goBackward();
    delay(2000);

    stopMotors();
    delay(1000);

    turnLeft();
    delay(1500); // Shorter delay for turns, adjust as needed

    stopMotors();
    delay(1000);

    turnRight();
    delay(1500); // Shorter delay for turns, adjust as needed

    stopMotors();
    delay(1000);
}