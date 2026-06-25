
#include <SoftwareSerial.h>

/*
 * ELRS Motor Control Demo for ESP8266
 * 
 * Hardware Setup:
 * - ELRS Receiver: RX -> IO12, TX -> IO13 (SoftwareSerial)
 * - Motor 1 (Left): IN1 -> IO4, IN2 -> IO5
 * - Motor 2 (Right): IN1 -> IO0, IN2 -> IO2
 * - DRV8871 pins are externally pulled-up, so active LOW for driving.
 */

// Motor 1 (Left)
const int M1_IN1 = 4;
const int M1_IN2 = 5;
// Motor 2 (Right)
const int M2_IN1 = 0;
const int M2_IN2 = 2;

// CRSF Protocol Definitions
#define CRSF_ADDR_MODULE 0xEE
#define CRSF_FRAMETYPE_RC_CHANNELS_PACKED 0x16

SoftwareSerial elrsSerial(12, 13); // RX, TX

void setup() {
  Serial.begin(115200);
  elrsSerial.begin(420000); // CRSF standard baud rate is 420k

  pinMode(M1_IN1, OUTPUT);
  pinMode(M1_IN2, OUTPUT);
  pinMode(M2_IN1, OUTPUT);
  pinMode(M2_IN2, OUTPUT);

  // Initialize motors to STOP (HIGH because of external pull-up)
  digitalWrite(M1_IN1, HIGH);
  digitalWrite(M1_IN2, HIGH);
  digitalWrite(M2_IN1, HIGH);
  digitalWrite(M2_IN2, HIGH);

  Serial.println("ELRS DRV8871 Motor Control Initialized.");
}

void stopMotors() {
  digitalWrite(M1_IN1, HIGH);
  digitalWrite(M1_IN2, HIGH);
  digitalWrite(M2_IN1, HIGH);
  digitalWrite(M2_IN2, HIGH);
}

void driveMotor(int in1, int in2, int speed) {
  // speed: -100 to 100
  if (speed > 10) {
    // Forward (using PWM for speed control, since pins are pulled up, we pull LOW)
    analogWrite(in1, 255 - map(speed, 0, 100, 0, 255));
    digitalWrite(in2, HIGH);
  } else if (speed < -10) {
    // Reverse
    digitalWrite(in1, HIGH);
    analogWrite(in2, 255 - map(abs(speed), 0, 100, 0, 255));
  } else {
    // Stop
    digitalWrite(in1, HIGH);
    digitalWrite(in2, HIGH);
  }
}

void loop() {
  if (elrsSerial.available()) {
    uint8_t header = elrsSerial.read();
    if (header == CRSF_ADDR_MODULE) {
      uint8_t len = elrsSerial.read();
      uint8_t type = elrsSerial.read();

      if (type == CRSF_FRAMETYPE_RC_CHANNELS_PACKED) {
        uint8_t buffer[22];
        elrsSerial.readBytes(buffer, 22);
        
        // Simple CRSF channel decoding (11 bits per channel)
        // Channel 1: Roll, Channel 2: Pitch, Channel 3: Throttle, Channel 4: Yaw
        int ch1 = (buffer[0] | buffer[1] << 8) & 0x07FF;
        int ch2 = (buffer[1] >> 3 | buffer[2] << 5) & 0x07FF;
        int ch3 = (buffer[2] >> 6 | buffer[3] << 2 | buffer[4] << 10) & 0x07FF;
        int ch4 = (buffer[4] >> 1 | buffer[5] << 7) & 0x07FF;

        // Map ELRS channels (typically 172-1811, center 992) to -100 to 100
        int throttle = map(ch3, 172, 1811, -100, 100);
        int steering = map(ch1, 172, 1811, -100, 100);

        // Simple Differential Drive logic
        int leftSpeed = throttle + steering;
        int rightSpeed = throttle - steering;

        leftSpeed = constrain(leftSpeed, -100, 100);
        rightSpeed = constrain(rightSpeed, -100, 100);

        driveMotor(M1_IN1, M1_IN2, leftSpeed);
        driveMotor(M2_IN1, M2_IN2, rightSpeed);
      }
    }
  }
}
