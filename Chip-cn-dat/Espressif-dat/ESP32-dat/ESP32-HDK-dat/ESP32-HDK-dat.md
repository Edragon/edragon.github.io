# ESP32 HDK dat

- [[ESP32-WROOM-dat]]

- [[I2S-dat]] - [[I2C-dat]] - [[DAC-dat]] - [[ADC-dat]] - [[serial-dat]]


## modules 

### pins

#### Template

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

- [[ESP32-SPI-dat]] - [[ESP32-GPIOs-dat]] - [[ESP32-USB-dat]] - [[I2C-dat]]

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



## UART

pin 17 / 18 = SD2 / SD3 = UART1
pin 27 / 28 = IO 26 / 27 = UART2 


## NC Pins 

V3 Chips 
-  Pins GPIO6 to GPIO11 on the ESP32-D0WD-V3/ESP32-D0WDR2-V3 chip are connected to the SPI flash integrated on the module and are not led out.

V2 Chips 
- Pins SCK/CLK, SDO/SD0, SDI/SD1, SHD/SD2, SWP/SD3, and SCS/CMD, i.e. GPIO6 to GPIO11 are used to connect to the module integrated SPI flash, not recommended for other functions.




## Modules

- [[ESP32-WROOM-dat]] - [[ESP32-C3-dat]]

## ref

- [[BTB-dat]]
