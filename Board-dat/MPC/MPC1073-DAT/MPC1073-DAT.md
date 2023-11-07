
## hardware

https://www.electrodragon.com/product/rgb-matrix-panel-drive-board-raspberry-pi/

- [[MPC1073-design-error]] - [[MPC1073-OS-error]] - [[MPC1073-ref-dat]]


## Board Map 

![](2023-11-06-17-41-05.png)

Output Control Chains 
- TOP - P0
- Middle - P1
- Bottom - P3

JP3 Power Supply Pins 
- 3.3V
- GND
- 5V

Switch SW1 
- Left to I2C RTC 
- right to use on board P3 chain output 

GND - RX
- ROW_E to GND
- or RX debug output 

JP1 / JP2 / JP3 
- ROW_E buffer select to 
  - pin 4 
  - or pin 8 
  - or gnd 



## Board Functions 

- [[RTC-dat]] - [[EEPROM-dat]]


## software 

- code: https://github.com/hzeller/rpi-rgb-led-matrix/tree/master/adapter

## Product Series 

- [[MPC1073-dat]] - [[MPC1119-dat]]

## ref 

- https://w.electrodragon.com/w/RPI_RMP_Guide
- https://w.electrodragon.com/w/RPI_RMP_HDK

- [[ds1307-dat]] - [[hub75-dat]]

- [[MPC1073]]