# lora-dat

legacy wiki page
https://w.electrodragon.com/w/Lora_Tech



- [[DVA1007-dat]] - [[DVA1008-dat]] - [[loraduino]]

- [[NWL1071-dat]] - [[NWL1072-dat]]

high power lora series [[EE2-dat]] - [[NWL1078-dat]] - [[NWL1081-dat]]

- SX1278
- LLCC68

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

## EE2 Specs

| Product Model                | EE2-433           | EE2-868           | EE2-915           | EE2-170           |
| ---------------------------- | ----------------- | ----------------- | ----------------- | ----------------- |
| Working frequency band       | 410 ~ 441 MHz     | 862 ~ 893 MHz     | 900 ~ 931 MHz     | 160 ~ 173.5 MHz   |
| RF chip                      | SX1278            | SX1276            | SX1276            | 8                 |
| Transmission power           | 30dBm(1W)         | 30dBm(1W)         | 30dBm(1W)         | 30dBm(1W)         |
| Communication distance       | 8000m             | 8000m             | 8000m             | 8000m             |
| Communication                | UART Serial       | UART Serial       | UART Serial       | UART Serial       |
| Closing form                 | DIP PTH           | DIP PTH           | DIP PTH           | DIP PTH           |
| Product size                 | 43 x 24mm         | 43 x 24mm         | 43 x 24mm         | 43 x 24mm         |
| Emission current             | 610 mA            | 680 mA            | 700 mA            | 680 mA            |
| Supply voltage               | 3.3 ~ 5.2 VDC     | 3.3 ~ 5.2 VDC     | 3.3 ~ 5.2 VDC     | 3.3 ~ 5.2 VDC     |
| Operating temperature        | -40℃ ~ +85℃       | -40℃ ~ +85℃       | -40℃ ~ +85℃       | -40℃ ~ +85℃       |
| Baud rate                    | 1200 ~ 115200     | 1200 ~ 115200     | 1200 ~ 115200     | 1200 ~ 115200     |
| Medium speed                 | 0.3k ~ 19.2k bps  | 0.3k ~ 19.2k bps  | 0.3k ~ 19.2k bps  | 0.3k ~ 19.2k bps  |
| Sending and receiving length | 512 bytes         | 512 bytes         | 512 bytes         | 512 bytes         |
| Receive sensitivity          | -147dbm @ O.3kbps | -147dbm @ O.3kbps | -147dbm @ O.3kbps | -147dbm @ O.3kbps |

## ref

https://randomnerdtutorials.com/esp32-lora-rfm95-transceiver-arduino-ide/

- [[crystal-dat]]