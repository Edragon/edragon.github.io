# lora-dat

legacy wiki page
- https://w.electrodragon.com/w/Lora_Tech
- https://www.electrodragon.com/w/Category:Wireless


## Board 
- [[DVA1007-dat]] - [[DVA1008-dat]] - [[loraduino-dat]] - [[MPC1056-dat]]

## Module 

### EE1 - common series 
[[NWL1071-dat]] - [[NWL1072-dat]] 

### classic
HPD Series - [[NWL1074-dat]] - [[NWL1075-dat]] - [[NWL1077-dat]]

### high power lora series 
- [[EE2-dat]] - [[NWL1078-dat]] - [[NWL1081-dat]] - [[NWL1079-dat]]
- antenna connection type = 内孔 = internal hole

## Chip 

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


## ref

https://randomnerdtutorials.com/esp32-lora-rfm95-transceiver-arduino-ide/

- [[crystal-dat]]

- [[lora]]