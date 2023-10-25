# ESP32 HDK dat

- [[ESP32-WROOM-dat]]

## pins

## Template

| Pin | Prerequisite | Used for   | Note |
| --- | ------------ | ---------- | ---- |
| 36  | input_only   | ~ lead-out |      |
| 39  | input_only   | ~ lead-out |      |
| 34  | input_only   | ~ lead-out |      |
| 35  | input_only   | ~ lead-out |      |
| 32  |              | IN1        |      |
| 33  | XTAL_32K_N   | IN2        |      |
| 25  | DAC          | IN3        |      |
| 26  | DAC          | IN4        |      |
| 27  |              | OUT1       |      |
| 14  |              | OUT2       |      |
| 12  | strapping    | ~ lead-out |      |
| 13  |              | I2C        |      |
| 15  | strapping    | I2C        |      |
| 2   | strapping    | ~ lead-out |      |
| 0   | strapping    | ~ lead-out |      |
| 4   |              | OUT4       |      |
| 16  |              | U2         |      |
| 19  |              | VSPI       |      |
| 17  |              | U2         |      |
| 5   | strapping    | VSPI       |      |
| 18  |              | VSPI       |      |
| 20  |              | OUT3       |      |
| 21  |              | U1         |      |
| 3   | U0R          | U0         |      |
| 1   | U0T          | U0         |      |
| 22  |              | U1         |      |
| 23  |              | VSPI       |      |

### RMT

- RMT_SIG_IN0~7
- Any GPIO Pins
- Eight channels for an IR transmitter and
- RMT_SIG_OUT0~7 receiver of various waveforms

- [[infrared-dat]]

### Serial

- U0 = RXD0 / TXD0
- U1 = SD2 / SD3 (can not use)
- U2 = U2RXD = IO16, U2TXD = IO17

### Functions 

- [[ESP32-SPI-dat]] - [[ESP32-GPIOs-dat]] - [[ESP32-USB-dat]]

EMAC = Ethernet 


DAC 
DAC1 (GPIO25)
DAC2 (GPIO26)

I2C
GPIO 21 (SDA)
GPIO 22 (SCL)


ref 

- https://electropeak.com/learn/full-guide-to-esp32-pinout-reference-what-gpio-pins-should-we-use/
- https://randomnerdtutorials.com/esp32-pinout-reference-gpios/

## Modules

- [[ESP32-WROOM-dat]] - [[ESP32-C3-dat]]

## ref

- [[BTB-dat]]
