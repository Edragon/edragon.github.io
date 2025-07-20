
# NWI1050-DAT


## SCH

![](49-45-17-28-06-2023.png)

Functions 

- IO0 press button (manual program mode) 
- RST press button 
- pull-up EN IO2 and IO15 for boot mode
- 3.3V power supply [[LDO-dat]] 
- Simple 5V/3V3 logic compliant level shifter for serial TXD and RXD


back side optional functions:
- IO4 IO5 pull up resistors via jumpers 
- ADC resistor ladders via jumppers 


## Dimension 

![](52-48-17-28-06-2023.png)


## ref 

- [[ESP-SDK-dat]] - [[ESP8266-dat]] - [[esp8266-modules-dat]]
- https://www.electrodragon.com/w/Category:ESP8266_Hardware#Perpherial_Schematic
- flash guide - https://www.electrodragon.com/flash-firmware-for-nodemcu-on-esp-12f-with-breakout-board/

- [[NWI1050]]


## Version Update Log 

- R2 version support not only ESP-07, ESP-12 but also new ESP-12F, which has extra 6 pis (SPI and I/Os)
- Fixed: Note pin IO4 and IO5 is switched, not same as ESP-12F pinout (we used early version pinout).

