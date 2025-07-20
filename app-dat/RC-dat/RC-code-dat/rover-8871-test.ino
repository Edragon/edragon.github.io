// Define pins for each RC channel
int aileronPin = 14;   // Channel 1 (Throttle) // D5
int elevatorPin = 12;  // Channel 2 (Steering) // D6

// Motor control pins
const int MOTOR1_CTRL_PIN = 4; // GPIO4 (D2)
const int MOTOR2_CTRL_PIN = 5; // GPIO5 (D1)

const int PWM_MAX = 1023;  // ESP8266 PWM range is 0-1023
const int PWM_STOP = PWM_MAX / 2;  // ~511 or 512

void setup() {
  pinMode(MOTOR1_CTRL_PIN, OUTPUT);
  pinMode(MOTOR2_CTRL_PIN, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  for (int pwm = 0; pwm <= PWM_MAX; pwm += 50) {

    // Apply the PWM value to both motors
    analogWrite(MOTOR1_CTRL_PIN, pwm);
    analogWrite(MOTOR2_CTRL_PIN, pwm);

    // Wait a moment at this PWM value
    delay(500);
  }
}