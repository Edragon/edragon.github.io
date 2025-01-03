# ESP32 HDK dat


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


### Functions 

- [[interface-dat]]

- use [[PDM-dat]] instead of [[I2S-dat]] on [[ESP32-S3-dat]]


- [[ESP32-DAC-dat]] - [[ESP32-I2C-dat]] - [[esp32-serial-dat]] - [[esp32-gpios-dat]] - [[esp32-usb-dat]] - [[ESP32-SPI-dat]] - [[ESP32-I2S-dat]] - [[sd-dat]]



ref 

- https://electropeak.com/learn/full-guide-to-esp32-pinout-reference-what-gpio-pins-should-we-use/
- https://randomnerdtutorials.com/esp32-pinout-reference-gpios/




## NC Pins 

V3 Chips 
-  Pins GPIO6 to GPIO11 on the ESP32-D0WD-V3/ESP32-D0WDR2-V3 chip are connected to the SPI flash integrated on the module and are not led out.

V2 Chips 
- Pins SCK/CLK, SDO/SD0, SDI/SD1, SHD/SD2, SWP/SD3, and SCS/CMD, i.e. GPIO6 to GPIO11 are used to connect to the module integrated SPI flash, not recommended for other functions.


## Module Compare 

![](2024-12-27-18-11-21.png)


## Diagram 

![](2024-12-27-18-11-50.png)

## boot mode 

### Table 3-1. Default Configuration of Strapping Pins

- from esp32 chip datasheet 

| Strapping Pin | note   | Default Configuration Bit | Value |
| ------------- | ------ | ------------------------- | ----- |
| GPIO0         |        | Pull-up                   | 1     |
| GPIO2         |        | Pull-down                 | 0     |
| MTDI          | GPIO12 | Pull-down                 | 0     |
| MTDO          | GPIO15 | Pull-up                   | 1     |
| GPIO5         |        | Pull-up                   | 1     |

### Table 6: Chip Boot Mode Control

- from esp32 wroom module datasheet 
  
| Boot Mode                | GPIO0 | GPIO2     |
| ------------------------ | ----- | --------- |
| SPI Boot Mode            | 1     | Any value |
| Joint Download Boot Mode | 0     | 0         |



## Modules

- [[ESP-SDK-dat]]

- [[ESP32-WROOM-dat]] - [[ESP32-C3-dat]]

- [[ESP32-wrover-dat]]


## documentas 

- [[esp32_technical_reference_manual_en_v5.2.pdf]]

- [[ESP32_Series_datasheet_v4.7.pdf]]

## ref

- [[BTB-dat]]

- [[ESP32-HDK]]

EMAC = Ethernet 