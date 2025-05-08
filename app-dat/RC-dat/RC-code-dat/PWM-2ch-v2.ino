// RC signal input pins
#define THROTTLE_PIN 2  // Channel 1 (forward/back)
#define STEERING_PIN 3  // Channel 2 (left/right)

// Motor control pins (L298N)
#define LEFT_ENA 9
#define LEFT_IN1 4
#define LEFT_IN2 5

#define RIGHT_ENB 10
#define RIGHT_IN3 6
#define RIGHT_IN4 7

int throttle, steering;

void setup() {
  pinMode(THROTTLE_PIN, INPUT);
  pinMode(STEERING_PIN, INPUT);

  pinMode(LEFT_IN1, OUTPUT);
  pinMode(LEFT_IN2, OUTPUT);
  pinMode(LEFT_ENA, OUTPUT);

  pinMode(RIGHT_IN3, OUTPUT);
  pinMode(RIGHT_IN4, OUTPUT);
  pinMode(RIGHT_ENB, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // Read PWM input
  throttle = pulseIn(THROTTLE_PIN, HIGH, 25000);
  steering = pulseIn(STEERING_PIN, HIGH, 25000);

  // Center = 1500, range = 1000–2000
  int throttleVal = map(throttle, 1000, 2000, -255, 255);
  int steeringVal = map(steering, 1000, 2000, -100, 100);  // less aggressive

  // Motor mixing (differential drive)
  int leftSpeed = constrain(throttleVal + steeringVal, -255, 255);
  int rightSpeed = constrain(throttleVal - steeringVal, -255, 255);

  setMotor(LEFT_IN1, LEFT_IN2, LEFT_ENA, leftSpeed);
  setMotor(RIGHT_IN3, RIGHT_IN4, RIGHT_ENB, rightSpeed);

  // Debug
  Serial.print("Throttle: "); Serial.print(throttleVal);
  Serial.print("  Steering: "); Serial.print(steeringVal);
  Serial.print("  L: "); Serial.print(leftSpeed);
  Serial.print("  R: "); Serial.println(rightSpeed);

  delay(20);
}

void setMotor(int in1, int in2, int ena, int speed) {
  if (speed > 0) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  } else if (speed < 0) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  } else {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }
  analogWrite(ena, abs(speed));
}
