
# ESP32-chip-error-dat

## ESP32-WROOM version compare 

- [[ESP32-WROOM-DAT]]



## ESP32 CAM board version error 

- [[SCM1030-dat]]

## boot.esp32: PRO CPU has been reset by WDT.

ESP32D0WDQ6 (revision 1) boards

https://github.com/orgs/micropython/discussions/10521


solder a 10UF capacitor between EN and GND pins to prevent the watchdog timer from resetting the board.




## NC Pins 

V3 Chips 
-  Pins GPIO6 to GPIO11 on the ESP32-D0WD-V3/ESP32-D0WDR2-V3 chip are connected to the SPI flash integrated on the module and are not led out.

V2 Chips 
- Pins SCK/CLK, SDO/SD0, SDI/SD1, SHD/SD2, SWP/SD3, and SCS/CMD, i.e. GPIO6 to GPIO11 are used to connect to the module integrated SPI flash, not recommended for other functions.





## ref 

- [[ESP32-dat]]