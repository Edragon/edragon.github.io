

// Define motor control pins
#define RPWM 10
#define LPWM 11
#define R_EN 8
#define L_EN 9

void setup()
{
    // Set control pins as output
    pinMode(RPWM, OUTPUT);
    pinMode(LPWM, OUTPUT);
    pinMode(R_EN, OUTPUT);
    pinMode(L_EN, OUTPUT);

    // Enable both sides of the H-Bridge
    digitalWrite(R_EN, HIGH);
    digitalWrite(L_EN, HIGH);
}

void loop()
{
    // Rotate motor forward
    analogWrite(RPWM, 200); // PWM value (0-255)
    analogWrite(LPWM, 0);
    delay(3000);

    // Stop motor
    analogWrite(RPWM, 0);
    analogWrite(LPWM, 0);
    delay(1000);

    // Rotate motor backward
    analogWrite(RPWM, 0);
    analogWrite(LPWM, 200);
    delay(3000);

    // Stop motor
    analogWrite(RPWM, 0);
    analogWrite(LPWM, 0);
    delay(1000);
}
