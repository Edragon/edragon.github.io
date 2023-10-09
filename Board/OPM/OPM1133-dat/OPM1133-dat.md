# OPM1133-dat

## Chip Features

- low noise, 150mA, 1.8-5V->3.3V
- quiescent current 1.77mA

## Board Dimension 

Pin Definitions: 
- Output, 
- GND, 
- Input, 
- Enable (pull-down to off)

![](2023-09-22-18-25-26.png)

![](2023-09-26-14-48-57.png)




## Updated to R2:
Added EN enable pin of the chip
EN default pull up to high level, connected by jumper VIN.
Set EN to low level, can simply connect to battery ground to shut power down, for power saving.


## Testing for reference:

- 1.8V VIN -> 3.3V output
- 1.5V VIN -> 3.1xV output, still can drive a lot MCUs.


## Applications 

- 2 AA Cell to 3.3V, tested can also get 3.2x V from a full 1.5V AA battery.
- USB On-The-Go Devices
- White LED Driver
- Handheld Devices


## ref

- [[battery-drainer-dat]]

- [[XA2320B]]
