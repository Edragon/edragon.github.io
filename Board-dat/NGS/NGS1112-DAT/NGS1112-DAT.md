# GNS1112 DAT

[STM32 Low-Power Wireless System Board](https://www.electrodragon.com/product/stm32-nb-iot-rs-232-wireless-control-board-stm32l151-bc35g/)


## Hardware

![](51-19-17-18-04-2023.png)

- [[STM32L151-dat]] == STM32L151C8T6



### Board Features 

- Pre-included board RS-232 [[DPR1084-DAT]]
- Optional stack board:
  - based on our current [[M2M-interface-dat]]
  - [[SIM7020-dat]]
  - [[SIM7070-dat]]
  - [[SIM7080-dat]]



### Pin Definitions 

Sensors pins from top to bottom: 3V3 PA7 xx GND

SIM Interface: 
- PB14 = power enable 
- PB10 = SIMRXD
- PB11 = SIM TXD
- PB13 = module boot 

RS-232 Interface:
- PB10
- PB9

Debug Interface: 3V3 GND PA2 PA3

Programming Interface: CLK DIO GND 3V3 BOOT


### Stackable with SIM7070G

![](36-12-18-18-04-2023.png)

- [[SIM7070-dat]]



### Ref 

- [[STM32L151]]

- [[NGS1112]]