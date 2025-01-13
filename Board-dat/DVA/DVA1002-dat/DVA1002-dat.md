
# DVA1002-dat

NRF24duino


https://www.electrodragon.com/product/nrf24duino-arduino-mini-plus-nrf24l01-board/

legacy wiki page - https://www.electrodragon.com/w/Nrf24Duino

series - [[edarduino-dat]] - [[RFduino-dat]]

![](2024-01-10-23-03-39.png)


## Quick start 

* Board choose pro-mini '''atmega328 3V3/8M'''

Sketch
* To have a quick start of this board, you can try a pair, or another arduino with nrf24l01.
* The board are pre-flashed RF24 get started sketch, use RF24 arduino library
* Connect the board with FTDI-basic
* Turn on the serial monitor in arduino
 Baudrate: 57600
* One board should be on "T" mode, another one should be on "R" mode.


* Note: LED is not work for default pre-programmed sketch, but can be used for other libraries which support nrf24l01

## Code 

For NRF24 testing 
- https://github.com/Edragon/Arduino-main/tree/master/Sketchbook/RF/06_NRF24

relevant library 
- https://www.arduino.cc/reference/en/libraries/radiohead/
- https://github.com/epsilonrt/RadioHead


## ref 

- Optimize for NRF24L01+ transmission range, [range test can be found here.](https://www.electrodragon.com/distance-test-nrf24duino-loarduino-board/)

- [[low-power-dat]]


- [[dva1002]]

- [[avr-sdk-dat]]