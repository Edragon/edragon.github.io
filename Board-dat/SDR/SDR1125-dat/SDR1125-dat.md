

# SDR1125-dat.md


- [[SDR1125-dat]] - [[CRSF-dat]] - [[ELRS-dat]]

orange boxes series 

- [[OPM1153-dat]] - [[MP1584-dat]] == orange middle module 

- [[CONN-USB-A-dat]] USB output 5V 

- orange right-bottom == power input - [[dcdc-down-dat]]

red box

- [[DRV8871-dat]] == 2x motor driver - [[motor-driver-dat]] - [[motor-dat]]
  - motor1 IO15 IO18
  - motor2 IO7 IO8 

yellow boxes
- 5V IO40 GND 
- 5V IO2 IO1 GND 
- 5V GND IO41 IO42 
- support - [[location-dat]] input 

main controller
- [[ESP32-S3-dat]] - [[NWI1243-dat]] 

green box 
- extra lead-out pins 
  - RST, IO4, IO3, 3V3, GND
  - 5V, IO39, IO38, IO37, IO0, IO45, IO47, IO21, GND, VIN

- BAT monitor == IO36 - [[ADC-dat]]

blue box 
- 2x mosfet == IO 5 6  - [[mosfet-dat]]
- 2x relay == IO 9 10  - [[relay-dat]]

- 4x servos == IO11 12 13 14 - [[motor-servo-dat]]

purple box 

- [[ELRS-dat]] - IO 16 17 

![](2026-05-27-14-49-11.png)


## SDK 

- [[ELRS-dat]] 

control [[RC-dat]] setup 


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
  #define CH_THROTTLE 3    // Forward/Backward (CH3)
  #define CH_STEERING 1    // Left/Right (CH1)
  #define CH_SPEED_MODE 6  // Speed Mode (Low/Mid/High) (CH6)

  // Reserved Servo IOs (not in use)
  #define SERVO1_PIN 11
  #define SERVO2_PIN 12
  #define SERVO3_PIN 13
  #define SERVO4_PIN 14

  // Reserved Buzzer control pin (not in use)
  #define BUZZER_PIN 46

  // Reserved Relay IOs (not in use)
  #define RELAY1_PIN 9
  #define RELAY2_PIN 10

  // Reserved MOSFET IOs (not in use)
  #define MOSFET1_PIN 5
  #define MOSFET2_PIN 6

  // Battery Monitor
  #define BATTERY_ADC_PIN 36




## ref 

