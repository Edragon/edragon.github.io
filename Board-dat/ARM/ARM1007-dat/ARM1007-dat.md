
# ARM1007-dat

HC32L136 Low-Power Cortex-M0+ Mini Dev. Board

https://www.electrodragon.com/product/hc32l136-low-power-cortex-m0-mini-dev-board/

- legacy wiki page - https://w.electrodragon.com/w/HDSC_SDK


## Board map 

![](2024-03-22-16-21-34.png)


## USB-TTL selection (on the top left pins)

[[SWD-dat]]
- PA13 - UART0_RXD
- PA14 - UART0_TXD

[[ISP-dat]]
- PA09 - UART0_TXD
- PA10 - UART0_RXD

misc
- chip reset - USB_DTR

BOOT0
- default pull down / or jumper pull up

## Power supply 

- by back jumper: +5V or 3V3
- power ON/OFF: by backside top right switch 
- [[Power-distribution-dat]]: select power via USB or battery 


## Programmer IOs 

- button: reset / PD4
- LEDs: PD5


## ref 

- [[HC32L136-dat]]

- [[Power-distribution]]