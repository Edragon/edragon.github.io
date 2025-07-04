
# lora-hdk-dat

- [[lora-SDK-dat]]

- [[LNA-dat]]

## Dev board SCH 



2025 [[SX1262-dat]] with [[STM32-dat]] - [[STM32-HDK-dat]]

![](2025-06-23-17-59-05.png)

2022 RFM92 with [[atmega328-dat]]

![](2025-06-23-18-15-55.png)

RFM92 with [[RPI-dat]]

![](2025-06-23-18-19-02.png)


## wiring to ESP32

| Lora Module | ESP32   |
| ----------- | ------- |
| ANA         | Antenna |
| GND         | GND     |
| DIO3        | -       |
| DIO4        | -       |
| 3.3V        | 3.3V    |
| DIO0        | IO 2    |
| DIO1        | -       |
| DIO2        | -       |
| GND         | -       |
| DIO5        | -       |
| RESET       | IO 14   |
| NSS         | IO 5    |
| SCK         | IO 18   |
| MOSI        | IO 23   |
| MISO        | IO 19   |
| GND         | -       |

- based on [[ESP32-SPI-dat]]


## ref 

- [[lora-dat]]