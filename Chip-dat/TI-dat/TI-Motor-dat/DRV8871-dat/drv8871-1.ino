// NodeMCU (ESP8266) code to drive two DC motors with DRV8871
// Each motor uses a single GPIO:
// Motor 1: IO0 (D3) for IN1, and IN2 driven by IO0 via an inverter.
// Motor 2: IO2 (D4) for IN1, and IN2 driven by IO2 via an inverter.

// Define the NodeMCU pins
// MOTOR 1
// GPIO0 (D3 on many NodeMCU boards) is used here.
// WARNING: GPIO0 is a boot mode pin. If it's LOW during boot, ESP8266 enters flash mode.
// Ensure your circuit doesn't pull GPIO0 LOW at boot unless intended.
const int MOTOR1_CTRL_PIN = 0; // GPIO0 (D3)

// MOTOR 2
// GPIO2 (D4 on many NodeMCU boards) is generally safe to use.
const int MOTOR2_CTRL_PIN = 2; // GPIO2 (D4)


// DRV8871 connections (repeat for each motor):
// - MOTORx_CTRL_PIN to DRV8871 IN1
// - MOTORx_CTRL_PIN -> Inverter -> DRV8871 IN2
// - Motor to DRV8871 OUT1 and OUT2
// - Motor power supply (6.5V to 45V) to DRV8871 VM and GND
// - NodeMCU GND to DRV8871 GND
// - Optionally, ILIM resistor (refer to DRV8871 datasheet)

// ESP8266 analogWrite range is 0-1023 by default.
// PWM_STOP is still needed for the active stopMotor function.
const int PWM_MAX = 1023;
const int PWM_STOP = PWM_MAX / 2; // Approx 511 or 512, for 50% duty cycle

void setup() {
  pinMode(MOTOR1_CTRL_PIN, OUTPUT);
  pinMode(MOTOR2_CTRL_PIN, OUTPUT);

  Serial.begin(9600);
  Serial.println("DRV8871 Dual Motor Single Pin (IO0/IO2 + Inverters) Control - Digital Direction");
  Serial.println("Note: Stop is an active stop (50% PWM). True coast/brake not available.");
  Serial.print("PWM Stop value for active stop: ");
  Serial.println(PWM_STOP);

  // Ensure motors are stopped at startup
  stopMotor1();
  stopMotor2();
}

void loop() {
  // Simple run loop: Both motors Forward, Stop, Reverse, Stop
  Serial.println("Motor 1 & 2 Forward - Full Speed");
  driveMotor1(true); // true for forward
  driveMotor2(true); // true for forward
  delay(2000);

  Serial.println("Motor 1 & 2 Stop");
  stopMotor1();
  stopMotor2();
  delay(1000);

  Serial.println("Motor 1 & 2 Reverse - Full Speed");
  driveMotor1(false); // false for reverse
  driveMotor2(false); // false for reverse
  delay(2000);

  Serial.println("Motor 1 & 2 Stop");
  stopMotor1();
  stopMotor2();
  delay(1000);

  // Example: Motor 1 Forward, Motor 2 Reverse
  Serial.println("Motor 1 Forward, Motor 2 Reverse");
  driveMotor1(true);
  driveMotor2(false);
  delay(2000);

  Serial.println("Motor 1 & 2 Stop");
  stopMotor1();
  stopMotor2();
  delay(1000);
}

// --- Motor 1 Control Functions ---

// Function to drive Motor 1 with digital control for direction
// forward: true for forward (MOTOR1_CTRL_PIN HIGH), false for reverse (MOTOR1_CTRL_PIN LOW)
void driveMotor1(bool forward) {
  if (forward) {
    digitalWrite(MOTOR1_CTRL_PIN, HIGH);
    // Serial.println("Driving Motor 1: Forward (MOTOR1_CTRL_PIN HIGH)");
  } else {
    digitalWrite(MOTOR1_CTRL_PIN, LOW);
    // Serial.println("Driving Motor 1: Reverse (MOTOR1_CTRL_PIN LOW)");
  }
}

// Function to stop Motor 1 (active stop by 50% duty cycle on MOTOR1_CTRL_PIN)
void stopMotor1() {
  analogWrite(MOTOR1_CTRL_PIN, PWM_STOP);
  // Serial.println("Motor 1 Stop (Active - 50% PWM on MOTOR1_CTRL_PIN)");
}

// Function to "brake" Motor 1. Performs an active stop.
void brakeMotor1() {
  stopMotor1();
  // Serial.println("Motor 1 Brake (Performed Active Stop)");
}

// --- Motor 2 Control Functions ---

// Function to drive Motor 2 with digital control for direction
// forward: true for forward (MOTOR2_CTRL_PIN HIGH), false for reverse (MOTOR2_CTRL_PIN LOW)
void driveMotor2(bool forward) {
  if (forward) {
    digitalWrite(MOTOR2_CTRL_PIN, HIGH);
    // Serial.println("Driving Motor 2: Forward (MOTOR2_CTRL_PIN HIGH)");
  } else {
    digitalWrite(MOTOR2_CTRL_PIN, LOW);
    // Serial.println("Driving Motor 2: Reverse (MOTOR2_CTRL_PIN LOW)");
  }
}

// Function to stop Motor 2 (active stop by 50% duty cycle on MOTOR2_CTRL_PIN)
void stopMotor2() {
  analogWrite(MOTOR2_CTRL_PIN, PWM_STOP);
  // Serial.println("Motor 2 Stop (Active - 50% PWM on MOTOR2_CTRL_PIN)");
}

// Function to "brake" Motor 2. Performs an active stop.
void brakeMotor2() {
  stopMotor2();
  // Serial.println("Motor 2 Brake (Performed Active Stop)");
}