# DAS1069-dat

link - https://www.electrodragon.com/product/esp8266-wifi-arduino-uart-extension-board/

## Current Version 2

![](2023-10-30-16-03-33.png)

![](2023-10-30-16-47-50.png)

## Version 1

![](2023-10-30-16-04-21.png)

![](2023-10-30-16-46-56.png)

### Configuration

| Jumper Name    | target  | Set            | Description                                                 |
| -------------- | ------- | -------------- | ----------------------------------------------------------- |
| Flash          | ESP8266 | ON or OFF      | Set flash mode, flash LED will turn on                      |
| Arduino Serial | arduino | D1/D0 or D3/D4 | Arduino serial switch between softserial or hardware serial |

- [[ESP-12F-dat]] - [[Lora-dat]] - [[NWL1071-dat]] - [[RFM95-dat]]

- [[DHT11-dat]] - [[spi-flash-dat]] - [[74HC125-dat]]

## ESP Serial Part 

- [[ESP-12F-dat]]
- Serial selectable connect to arduino Serial D0/D1 or D3/D4

## Lora SPI Part

| arduino | Note        | customize        | Note2.          |
| ------- | ----------- | ---------------- | --------------- |
| 13      |             | lora_CLK         | SPI             |
| 12      |             | lora_DO          | SPI             |
| 11      |             | lora_DI          | SPI             |
| 10      |             | lora_CS          | SPI_CS1         |
| 9       |             | lora_Reset       |                 |
| 8       | via. jumper | lora_DIO5        |                 |
| 7       | via. jumper | lora_DIO2        |                 |
| 6       | via. jumper | lora_DIO1        |                 |
| 5       |             | flash_CS         | SPI_CS2         |
| 4       | alternative | alt. ESP8266_TXD | software Serial |
| 3       | alternative | alt. ESP8266_RXD | software Serial |
| 2       | INT0        | lora_IRQ         |                 |
| 1       | TXD         | ESP8266_RXD      |                 |
| 0       | RXD         | ESP8266_TXD      |                 |


- D13 - CLK
- D12 - DO
- D11 - DI 
- D10 - CS
- DIO0 / IRQ - D2

Reserved DIO (via jumpers)
- DIO1 - D6
- DIO2 - D7
- DIO5 - D8
- DIO3 - x
- DIO4 - x 





## Other 

- D5 - Flash_CS

## DHT11

- Selectable to ESP IO13 or Arduino A0, by backside jumper



## Demo code 

- arduino_uart_esp_at -> arduino send AT commands to ESP8266
- arduino_uart_esp_wifi -> "transparent" communicatino in TCP client mode 
- in https://github.com/Edragon/arduino-esp8266/tree/master/Sketchbook/Hardware


## ref

- [[arduino-dat]]