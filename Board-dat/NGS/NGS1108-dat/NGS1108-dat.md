
# NGS1108-dat

* **Note the default version is the data ONLY version**
* the module information - [[ec20-dat]]


## legecy wiki page 

- https://www.electrodragon.com/w/Modem#WIN_10


## Board Map 

![](2024-03-07-18-36-28.png)

- short JP6 two-pins to enter auto boot mode 


## Quick Start:

- Connect USB Debug cable
- Short connect “Auto boot” and “boot” pin 2-3 seconds to auto boot up the board. (A tweezer can work fine)
- LED started to blink.
- Start to install driver, which needed on WIN10, avaialble in our git.
- Find USB AT commands port, can control it now, auto baudrate can use any you like.


## Logic level selector 

- 5V or 3.3V 
- also can float it, it works fine

## USB Debug

- plugin to have three serial port 


## LED Indicators 

- Status 
- Network_status 
- Net_mode 

## Antenna Connector 

- RF
- GPS
- Ant_Div


## Pin headers 

- Top 
- Bottom 



## boot log 

test with AT+CPIN?

    RDY

    +CFUN: 1

    +CPIN: READY

    +QUSIM: 1

    +QIND: SMS DONE
    AT+CPIN?
    +CPIN: READY

    OK



## Demo 


## Code 

- Please check most docs at our bitbucket folder (link in tracking info email).



## ref 

- [[quectel-AT-dat]] - [[antenna-dat]] - 

- [[NGS1108]] 