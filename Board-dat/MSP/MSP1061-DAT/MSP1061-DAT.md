# MSP1061-DAT


## Features 
Support APPs or UART interface or Python script or ..
- socketCAN - linux 
- CANtact V0.3 
- Cangaroo 
- slCAN
- python 

## hardware 

![](52-11-17-28-04-2023.png)


## Demos 

- https://twitter.com/electro_phoenix/status/1651872392791093249


## Default firmware
- Please notice we flash UART interface fimware before 2023. April
- And Canable firmware after 2023. April
- If you need upgrade to canable firmware, please try DFU update or flash chip with a .bin file
- On board LEDs blink on canable version, but not in UART (slCAN) version



## supported commands 

    O - Open channel
    C - Close channel
    S0 - Set bitrate to 10k
    S1 - Set bitrate to 20k
    S2 - Set bitrate to 50k
    S3 - Set bitrate to 100k
    S4 - Set bitrate to 125k
    S5 - Set bitrate to 250k
    S6 - Set bitrate to 500k
    S7 - Set bitrate to 750k
    S8 - Set bitrate to 1M
    M0 - Set mode to normal mode (default)
    M1 - Set mode to silent mode
    A0 - Disable automatic retransmission
    A1 - Enable automatic retransmission (default)
    TIIIIIIIILDD... - Transmit data frame (Extended ID) [ID, length, data]
    tIIILDD... - Transmit data frame (Standard ID) [ID, length, data]
    RIIIIIIIIL - Transmit remote frame (Extended ID) [ID, length]
    rIIIL - Transmit remote frame (Standard ID) [ID, length]
    V - Returns firmware version and remote path as a string



## demo 

- https://x.com/electro_phoenix/status/1651872392791093249





## ref 
- legacy reference - https://w.electrodragon.com/w/Category:CAN#CAN_USB
- https://canable.io/getting-started.html
- https://github.com/normaldotcom/canable-fw
