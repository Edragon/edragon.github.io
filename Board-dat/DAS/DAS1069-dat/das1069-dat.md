# DAS1069-dat

link - https://www.electrodragon.com/product/esp8266-wifi-arduino-uart-extension-board/

## Current Version 2

![](2023-10-30-16-03-33.png)

![](2023-10-30-16-47-50.png)

## Version 1

![](2023-10-30-16-04-21.png)

![](2023-10-30-16-46-56.png)

### Configuration

| Jumper Name    | Set            | Description                                                 |
| -------------- | -------------- | ----------------------------------------------------------- |
| Flash          | ON or OFF      | Set flash mode, flash LED will turn on                      |
| Arduino Serial | D1/D0 or D3/D4 | Arduino serial switch between softserial or hardware serial |
| Serial Switch  |                | Arduino or standalone output                                |

## ESP Serial Part 

- Serial selectable connect to arduino Serial D0/D1 or D3/D4

## Lora SPI Part

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


