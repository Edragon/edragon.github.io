
# USB TTL Dat 

- legacy wiki page - https://w.electrodragon.com/w/Serial

## Usage 

from the perspective of the cable to the perspective of the target

- Green = TXD -> target RXD  
- White = RXD -> target TXD
- Red = VCC -> target +5V
- Black = GND - > target GND

![](32-40-17-24-07-2023.png)




## Product links 

- PL2303TA - [[DPR1041-dat]] 
- PL2303HX - https://w.electrodragon.com/w/PL2303HX


- CH340 - [[DPR1042-dat]] - [[DPR1039-dat]]

- CP2102 - [[DPR1003-dat]], [[DPR1002-DAT]]

- FT232RL - [[DPR1029-dat]]

- 4x channels - [[DPR1120-dat]]

## Use case 


### programming for ESP32 or ESP8266 : 
- TXD -> RXD
- RXD -> TXD
- 5V -> 5V
- GND -> GND. 

Booting Mode select

           Hold down IO0 button, and connect power supply to enter into flash  mode
    do NOT Hold down IO0 button, and connect power supply to enter into normal mode

- please note for [[ESP32-C3-dat]], the programming mode select pin is (button) IO9


### Programming Wiring 



- for [[NWI1126-dat]]

![](2023-09-27-16-07-06.png)


### Confirm selected Mode 

- The COM port monitor used below is [[com-monitor-dat]]
- if your actions are all correct, the module should enter into correct module, and print output as below
- In this mode, you can close the monitor, and further programming it with other SDK like [[arduino-esp32-dat]]

![](2023-09-27-16-05-42.png)


### troubleshooting checklist
- reverse TX RX in case wrong wiring of communication

## Applications 

### Flash target MCU microcontroller
![](2023-12-19-16-16-01.png)

### communicate with GPS module 
![](2024-01-13-12-35-57.png)

### FTDI FT232RL programming arduino pro mini 

- [[DPR1029-dat]] to [[DAR1010-dat]], [[DAR1007-dat]]
  
![](2024-04-03-15-04-50.png)

## ref 
software [[com-monitor-dat]]

- [[ESP-SDK-dat]]

## Compatibility 

replaceable 
- [[CP2102-dat]] - [[CP2104-dat]]



## other interface 
- [[RS485-DAT]] - [[RS232-dat]] - [[I2C-dat]]


- [[usb-ttl]]
