
# NWI1126-DAT


## Pin Definitions

    #define OM_LED 10 // on module led
    #define WS_LED 9 // WS2812, select by jumper 

    #define addc 0

    #define W_LED 4 // white
    #define B_LED 5 // blue
    #define G_LED 6 // green
    #define R_LED 7 //red


- IO9 button = program mode pin
- EN button = reset pin 
- programmable LED pin 10 

![](13-39-15-09-06-2023.png)

## Wiring Diagram 

### Wiring for WS2812_5V

![](2023-09-04-17-03-33.png)

- for 12V or 24V led strips, put JP_L red box's jumper on top position
- back side jumper no need to change or check by default 


## Core Module Sch

![](37-36-16-10-07-2023.png)

Peripheral schamtic please refer to [[NWI1124-DAT]]


## quick test 

- find demo code at https://github.com/Edragon/Arduino-ESP32 
- find your board IP address, verify it in browser: http://192.168.8.165
- try the test commands to turn off on board prog LED: http://192.168.8.165/io/10/val/0
- in which, IO is 10 and IO voltage level is 0


## demo video 
- https://twitter.com/electro_phoenix/status/1610204098019880961

## Note

- [[ESP32-USB]] failed on code testing, may work or not, consider it is not working if you buy.

## Update Log 
- New USB footprint to simplified the production process and reduce failure rate
- Tested USB Functions working fine by customers feedback


## ref 

- [[ESP32-­C3-­WROOM-­2-DAT]]

- [[NWI1124-DAT]]
- [[NWI1125-DAT]]
- [[NWI1126]]

- [[ESP32-DAT]]