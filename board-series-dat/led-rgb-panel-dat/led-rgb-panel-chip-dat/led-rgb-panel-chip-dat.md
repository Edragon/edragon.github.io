
# led-rgb-panel-chip-dat

- [[led-rgb-panel-chip-log-dat]]

## direct ABCDE addressing

### DP5125D

In the second order #65705, the panels came with the DP5125D driver chip. These panels work fine and do not have this issue in the exact same hardware/software environment. 


## ABC panels 

ref - https://github.com/hzeller/rpi-rgb-led-matrix/issues/823

https://community.pixelmatix.com/t/smartmatrix-doesnt-support-fm6126a-driver-chips/421

### FM6124DJ driver chip

In the first order #65388, the panels had the FM6124DJ driver chip. These panels have issues with the drive board: They display glitches/artefacts around the borders of objects like the red horizontal lines next to the object on the attached photo.

![](2025-01-06-16-42-51.png)

### ICN2037

### SM5368 - SM16208S

https://github.com/hzeller/rpi-rgb-led-matrix/issues/1774


### DP5125 - DP32020A




## other 

### chip check

- probably NOT supported Panels: ICN2153 ICN2053 chips

- Check the chip type (FM6126A)


## ref 

- [more chip list reference list DMD_STM32](https://github.com/board707/DMD_STM32/wiki/Led_drivers)
