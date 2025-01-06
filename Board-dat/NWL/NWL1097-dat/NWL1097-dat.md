
# NWL1097-dat


- board type arduino pro mini 3.3V/8M

![](2024-01-16-18-04-43.png)

LEDS
- D5
- Power indicator 

Reset Button 


## repo code 

[Support Arduino-PS2X library.](https://github.com/madsci1016/Arduino-PS2X)

- folk - https://github.com/Edragon/Arduino-PS2X

## code debug 

****************IF YOU HAVE PROBLEMS***********************

open up the PS2X_lib.h file and change (remove the comment markers)

    // $$$$$$$$$$$$ DEBUG ENABLE SECTION $$$$$$$$$$$$$$$$
    // to debug ps2 controller, uncomment these two lines to print out debug to uart

    //#define PS2X_DEBUG
    //#define PS2X_COM_DEBUG

to 

    // $$$$$$$$$$$$ DEBUG ENABLE SECTION $$$$$$$$$$$$$$$$
    // to debug ps2 controller, uncomment these two lines to print out debug to uart

    #define PS2X_DEBUG
    #define PS2X_COM_DEBUG


## ref 

- [[NWL1097]]