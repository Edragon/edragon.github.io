
# NWI1254-dat

- this is a succsessor of [[NWI1252-dat]], further add [[RS232-dat]] interface

- [[RS485-dat]]

## Info

product url - [[NWI1252-dat]]

### Board Map, Dimension, Pins, chip info, Use Guide, Setup Jumper, etc.


![](2024-09-26-22-14-43.png)

- set red and yellow jumpers for [[RS485-dat]]
- set blue jumpers for [[RS232-dat]]


red box 
- data communication LED indicator 
- spare pins 
  - IO6 IO7 IO8 
  - ADC IO2 D+ TXD 3V3
  - IO1 IO3 D- RXD GND
- EN button and flash button = IO10
- power LED
- flash button programmable LED = IO9

yello box
- Power input 

Green Box 
- USB A native USB
- micro USB native USB, same

Blue box 
- jumper, RS232 / RS485 output selector 
- GND / +5V 
- DB9 connector, includes a jumper selector for pin2 
- cable terminal output RS232 / RS485, 






- [[DB9-dat]] 

- [[dcdc-down-dat]] == 3A, Wide Input Range, Step-Down Converter 

Wide input voltage range:

– TPS5430: 5.5V to 36V

- [[resistor-feedback-dat]]

main controller part SCH 

![](2026-01-08-16-01-20.png)





## Applications, category, tags, etc. 



## Demo Code and Video

![](2025-12-30-14-22-20.png)

note the [[RS232-dat]] interface should be twisted, wire as TX-RX and RX-TX

## update logs and issues 

- [[CONN-USB-micro-vertical-dat]]

## ref 

- [[NWI1254]] - [[NWI1252]]

- legacy wiki page 
