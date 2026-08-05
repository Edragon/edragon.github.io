#include <AlfredoCRSF.h>
#include <HardwareSerial.h>
#include <ESP32Servo.h>
#include <Adafruit_NeoPixel.h>

#define PIN_RX 17
#define PIN_TX 16

// Motor Driver DRV8871 Pins
// Motor 1 (Left): IO15, IO18
#define M1_IN1 15
#define M1_IN2 18

// Motor 2 (Right): IO7, IO8
#define M2_IN1 7
#define M2_IN2 8

// Channels
#define CH_THROTTLE 3     // Speed Magnitude (CH3)
#define CH_STEERING 1     // Left/Right (CH1)
#define CH_DIRECTION 6    // Direction Switch (CH6): 1000 FWD / 1500 STOP / 2000 BWD
#define CH_SPEED_MODE 7   // Speed Mode (Low/Mid/High) (CH7)
#define CH_MOSFET1 5      // MOSFET 1 Control (CH5)
#define CH_MOSFET2 8      // MOSFET 2 Control (CH8)
#define CH_SERVO1 2       // Servo 1 Control (CH2) -> SERVO1_PIN
#define CH_SERVO2 10      // Servo 2 Control (CH10) -> SERVO2_PIN

// Servo IOs
#define SERVO1_PIN 11
#define SERVO2_PIN 12
#define SERVO3_PIN 13  // Reserved (not in use)
#define SERVO4_PIN 14  // Reserved (not in use)
Servo servo1;
Servo servo2;

// Reserved Buzzer control pin (not in use)
#define BUZZER_PIN 46

// Reserved Relay IOs (not in use)
#define RELAY1_PIN 9
#define RELAY2_PIN 10

// Reserved MOSFET IOs 
#define MOSFET1_PIN 5
#define MOSFET2_PIN 6

// Battery Monitor
#define BATTERY_ADC_PIN 36

// WS2812 Indicator
#define RGB_PIN 48
#define NUMPIXELS 1
Adafruit_NeoPixel pixels(NUMPIXELS, RGB_PIN, NEO_GRB + NEO_KHZ800);

// Set up a new Serial object
HardwareSerial crsfSerial(1);
AlfredoCRSF crsf;

/**
 * Control a single motor
 * @param speed -255 to 255
 * @param pin1 Primary control pin
 * @param pin2 Secondary control pin
 */
void setMotor(int speed, int pin1, int pin2) {
  if (speed > 0) {
    if (speed > 255) speed = 255;
    analogWrite(pin1, speed);
    analogWrite(pin2, 0);
  } else if (speed < 0) {
    speed = -speed;
    if (speed > 255) speed = 255;
    analogWrite(pin1, 0);
    analogWrite(pin2, speed);
  } else {
    analogWrite(pin1, 0);
    analogWrite(pin2, 0);
  }
}

void setup()
{
  Serial.begin(115200);
  Serial.println("Rover Controller initializing...");
  
  // Motor pins setup
  pinMode(M1_IN1, OUTPUT);
  pinMode(M1_IN2, OUTPUT);
  pinMode(M2_IN1, OUTPUT);
  pinMode(M2_IN2, OUTPUT);

  // Set PWM frequency for motors
  analogWriteFrequency(M1_IN1, 10000);
  analogWriteFrequency(M1_IN2, 10000);
  analogWriteFrequency(M2_IN1, 10000);
  analogWriteFrequency(M2_IN2, 10000);

  // Servo setup (CH2 -> SERVO1_PIN, CH10 -> SERVO2_PIN)
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  servo1.setPeriodHertz(50);
  servo1.attach(SERVO1_PIN, 500, 2400);
  servo2.setPeriodHertz(50);
  servo2.attach(SERVO2_PIN, 500, 2400);
  servo1.write(90);  // Neutral
  servo2.write(90);  // Neutral

  // Reserved Servo IOs setup (commented out/not in use)
  // pinMode(SERVO3_PIN, OUTPUT);
  // pinMode(SERVO4_PIN, OUTPUT);

  // Reserved Buzzer setup (not in use)
  // pinMode(BUZZER_PIN, OUTPUT);

  // Reserved Relay setup (not in use)
  // pinMode(RELAY1_PIN, OUTPUT);
  // pinMode(RELAY2_PIN, OUTPUT);

  // MOSFET setup
  pinMode(MOSFET1_PIN, OUTPUT);
  pinMode(MOSFET2_PIN, OUTPUT);
  digitalWrite(MOSFET1_PIN, LOW);
  digitalWrite(MOSFET2_PIN, LOW);

  // Battery Monitor setup
  pinMode(BATTERY_ADC_PIN, INPUT);

  // WS2812 setup
  pixels.begin();
  pixels.setBrightness(50);
  pixels.setPixelColor(0, pixels.Color(0, 0, 0));
  pixels.show();

  // Stop motors initially
  setMotor(0, M1_IN1, M1_IN2);
  setMotor(0, M2_IN1, M2_IN2);
  
  crsfSerial.begin(CRSF_BAUDRATE, SERIAL_8N1, PIN_RX, PIN_TX);
  if (!crsfSerial) {
    while (1) {
      Serial.println("Invalid crsfSerial configuration");
      delay(1000);
    }
  }

  crsf.begin(crsfSerial);
  Serial.println("CRSF initialized");
}

void loop()
{
  static bool wasStopped = true;
  // Must call crsf.update() in loop() to process data
  crsf.update();

  if (crsf.isLinkUp()) {
    // CRSF values typically range from 1000 to 2000
    int throttleInput = crsf.getChannel(CH_THROTTLE); 
    int mosfet1Input = crsf.getChannel(CH_MOSFET1);
    int mosfet2Input = crsf.getChannel(CH_MOSFET2);

    // Control MOSFETs based on CRSF channels (Threshold > 1500)
    digitalWrite(MOSFET1_PIN, mosfet1Input > 1500 ? HIGH : LOW);
    digitalWrite(MOSFET2_PIN, mosfet2Input > 1500 ? HIGH : LOW);
    int steeringInput = crsf.getChannel(CH_STEERING);
    int directionInput = crsf.getChannel(CH_DIRECTION);
    int speedModeInput = crsf.getChannel(CH_SPEED_MODE);
    int servo1Input = crsf.getChannel(CH_SERVO1);
    int servo2Input = crsf.getChannel(CH_SERVO2);

    // Control servos from CH2 (-> SERVO1) and CH10 (-> SERVO2)
    servo1.write(map(servo1Input, 1000, 2000, 0, 180));
    servo2.write(map(servo2Input, 1000, 2000, 0, 180));

    // Determine max PWM based on Speed Mode (CH7)
    int maxLimit = 255;
    if (speedModeInput < 1300) {
      maxLimit = 85;    // Low Speed
    } else if (speedModeInput < 1700) {
      maxLimit = 170;   // Middle Speed
    } else {
      maxLimit = 255;   // High Speed
    }

    // Determine direction from CH6 switch (1000 FWD / 1500 STOP / 2000 BWD)
    int direction = 0;
    if (directionInput < 1300) {
      direction = 1;    // Forward
    } else if (directionInput > 1700) {
      direction = -1;   // Backward
    }
    // else direction = 0; // Stop (center position)

    // Map throttle (CH3) to speed magnitude 0..maxLimit
    int throttleMag = map(throttleInput, 1000, 2000, 0, maxLimit);
    // Apply Deadband to prevent motor hum near center
    if (throttleMag < 20) throttleMag = 0;

    // Apply direction switch (CH6) to throttle
    int throttle = throttleMag * direction;

    int steering = map(steeringInput, 1000, 2000, maxLimit, -maxLimit);
    // Apply Deadband to steering
    if (abs(steering) < 20) steering = 0;

    // Mixed differential steering
    int leftSpeed = throttle + steering;
    int rightSpeed = throttle - steering;

    // Constrain to PWM range
    leftSpeed = constrain(leftSpeed, -255, 255);
    rightSpeed = constrain(rightSpeed, -255, 255);

    // Staggered start to avoid inrush current when starting from stop
    if (leftSpeed != 0 || rightSpeed != 0) {
      if (wasStopped) {
        setMotor(leftSpeed, M1_IN1, M1_IN2);
        delay(150);
        setMotor(rightSpeed, M2_IN1, M2_IN2);
        wasStopped = false;
      } else {
        setMotor(leftSpeed, M1_IN1, M1_IN2);
        setMotor(rightSpeed, M2_IN1, M2_IN2);
      }
    } else {
      setMotor(0, M1_IN1, M1_IN2);
      setMotor(0, M2_IN1, M2_IN2);
      wasStopped = true;
    }

    // Update LED Indicator based on direction
    if (throttle > 20) {
      pixels.setPixelColor(0, pixels.Color(0, 255, 0)); // Forward - Green
    } else if (throttle < -20) {
      pixels.setPixelColor(0, pixels.Color(255, 0, 0)); // Backward - Red
    } else if (abs(steering) > 20) {
      pixels.setPixelColor(0, pixels.Color(0, 0, 255)); // Turning - Blue
    } else {
      pixels.setPixelColor(0, pixels.Color(0, 0, 0));   // Stopped - Off
    }
    pixels.show();

    // Occasional debug print
    static unsigned long lastPrint = 0;
    if (millis() - lastPrint > 200) {
      Serial.print("MODE:"); Serial.print(maxLimit == 85 ? "LOW" : (maxLimit == 170 ? "MID" : "HIGH"));
      Serial.print(" CH1:"); Serial.print(crsf.getChannel(1));
      Serial.print(" CH3:"); Serial.print(crsf.getChannel(3));
      Serial.print(" DIR:"); Serial.print(directionInput);
      Serial.print(" SPDCH:"); Serial.print(speedModeInput);
      Serial.print(" THR:"); Serial.print(throttle);
      Serial.print(" STR:"); Serial.print(steering);
      Serial.print(" M1:"); Serial.print(crsf.getChannel(CH_MOSFET1));
      Serial.print(" M2:"); Serial.print(crsf.getChannel(CH_MOSFET2));
      Serial.print(" S1:"); Serial.print(map(servo1Input, 1000, 2000, 0, 180));
      Serial.print(" S2:"); Serial.print(map(servo2Input, 1000, 2000, 0, 180));
      Serial.print(" L:"); Serial.print(leftSpeed);
      Serial.print(" R:"); Serial.println(rightSpeed);
      lastPrint = millis();
    }
  } else {
    digitalWrite(MOSFET1_PIN, LOW);
    digitalWrite(MOSFET2_PIN, LOW);
    // Failsafe: Stop motors if RC is lost
    setMotor(0, M1_IN1, M1_IN2);
    setMotor(0, M2_IN1, M2_IN2);
    wasStopped = true;
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.show();
  }
}
