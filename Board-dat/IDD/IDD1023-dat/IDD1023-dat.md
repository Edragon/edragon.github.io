
# IDD1023-dat 

## Board Map 



## Wiring

![](2023-11-29-15-48-23.png)


* You will need a USB-TTL adapter bridge board or cable, to interface or program ESP32 via the serial interface

To communicate with ESP32 normally, connect (working mode):
* TXD->RXD, RXD->TXD, +5V=+5V, GND=GND
* remove IO0-GND jumper, IO0 LED should be off

To program ESP32 (flashing mode):
* Connect the same serial interface
* Put **IO0-GND jumper ON**, IO0 LED should be ON
* press reset button to enter into flash mode
* Upload arduino demo code

## Code 

- https://github.com/Edragon/Arduino-ESP32

## Demo Early Test 

correct test: https://twitter.com/electro_phoenix/status/1434776186354241536

test in error: https://twitter.com/electro_phoenix/status/1427971402561327106