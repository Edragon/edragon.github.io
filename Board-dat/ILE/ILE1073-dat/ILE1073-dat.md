
# ILE1073-dat

- legacy wiki page - https://w.electrodragon.com/w/HP25_LED_Panel

## hardware 

![](2023-10-11-15-24-50.png)

![](2023-10-11-15-42-45.png)

## Pin Definitions 

Solar Panel Input = un-regulated higher DC input
- SO+
- SO-

Infrared Control
- V = VCC
- G = GND
- R = Infrared input 

Battery In  
- B+ = LED+
- B- = GND

Other Pins 
- TXD/VCC/GND - debug only 
- UPDI - flash chip 

## Power Supply 

- SO+ via diode to B+/LED+
- B+/LED+ via LDO to system VCC

## LED Drive

- On low side mosfet 

## Chip Pin Definitions 

- [[ainyAVR-dat]] 0-series

![](2023-10-11-15-31-05.png)

## Demo 

- https://www.electrodragon.com/w/Demo_Video

- demo code - https://github.com/Edragon/Arduino-attiny

## ref 

- [[ILE1073]]