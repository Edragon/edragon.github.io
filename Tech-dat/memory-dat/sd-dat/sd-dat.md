
# sd-dat


## ESP32-WROVER 

SP 4-wire

    #define SD_CS IO13
    #define SD_MISO IO2
    #define SD_MOSI IO15
    #define SD_CLK IO14

- https://github.com/Edragon/Arduino-ESP32/tree/master/Sketchbook/driver-Data


This is how I connected my SD card:

https://github.com/espressif/arduino-esp32/tree/master/libraries/SD



## ESP32 

Dat 0~4

MicroSD Card Connections

The following pins are used to interface with the microSD card when it is on operation.

| MicroSD card | extra      | ESP32   |
| ------------ | ---------- | ------- |
| CLK          |            | GPIO 14 |
| CMD          |            | GPIO 15 |
| DATA0        |            | GPIO 2  |
| DATA1        | flashlight | GPIO 4  |
| DATA2        |            | GPIO 12 |
| DATA3        |            | GPIO 13 |



