# lora-dat

legacy wiki page
- https://w.electrodragon.com/w/Lora_Tech
- https://www.electrodragon.com/w/Category:Wireless

AIT lora
- https://w.electrodragon.com/w/AIT_LORA_MOD

- [[lorawan-dat]]

- [[samtech-dat]]

## Info 

- LoRa is the physical layer or in simple words is the modulation, the modem or radio, the hardware.
- [[LoRaWAN-dat]] is the network protocol or architecture that works on LoRa.

## Lora 

LoRa ™ is a long-range radio technology "Lo ng- Ra nge" its main features:

- Its spread spectrum modulation allows a significantly greater scope to other technologies.
- High sensitivity (-168dB) combined with high immunity to interference.
- Low Consumption (up to 10 years with a battery, good depends on certain characteristics).
- Low data transfer (up to 255 bytes).

## Board 

- [[arduino-dat]] == [[DVA1007-dat]] - [[DVA1008-dat]] - [[loraduino-dat]] 

- [[DAS1069-dat]]

- [[MPC1056-dat]]

## Module 

### EE1 - common series 
[[NWL1071-dat]] - [[NWL1072-dat]] 

### classic
HPD Series - [[NWL1074-dat]] - [[NWL1075-dat]] - [[NWL1077-dat]]

### high power lora series 
- [[EE2-dat]] - [[NWL1078-dat]] - [[NWL1081-dat]] - [[NWL1079-dat]]
- antenna connection type = 内孔 = internal hole

## Chip 

- LLCC68

- [[ASR6500-dat]] - [[ASR-dat]]

- [[semtech-dat]] - [[SX1278-dat]] - [[SX1262-dat]]

- [[semtech-dat]] 3'rd generation Lora Chip == [[LR1121-dat]]

- [[crystal-dat]]

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

- [[meshtastic-dat]] - [[opensource-dat]]

https://randomnerdtutorials.com/esp32-lora-rfm95-transceiver-arduino-ide/

- [[RFM95-dat]]

- [[crystal-dat]]



- [[lora]]



