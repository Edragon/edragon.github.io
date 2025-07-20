
# quectel-SDK-dat

## firmware flash tools 

== [[Qflash-dat]]

[QFlash_V7.4_EN](https://www.quectel.com/download/qflash_v7-4_en/)


## For [[NGS1063-dat]], select the correct firmware: 

baudrate 921600, working with [[serial-dat]]

![](2025-05-13-18-09-38.png)

click start and wait

![](2025-05-13-18-33-52.png)

press boot button to start flashing 

![](2025-05-13-18-48-10.png)

AT firmware APP + Core need 300s at 115200, custom APP need ~60s at 921600

## errors 

FAIL, COM:348, FlashToolError:1011, S_COM_PORT_OPEN_FAIL

- some [[serial-dat]] chips are not fully supported error, probably, try another [[serial-dat]] board with a different chip 




## ref 

- [[quectel-dat]] - [[NGS1063-SDK-dat]]

- [[serial-dat]]