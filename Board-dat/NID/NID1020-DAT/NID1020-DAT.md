

# NID1020 DAT - EL125



## pin definitions 

| pin | name                                                           | note                 |
| --- | -------------------------------------------------------------- | -------------------- |
| 1   | antenna 1                                                      | **MUST CONNECT**     |
| 2   | antenna 2                                                      | **MUST CONNECT**     |
| 3   | high-level election serial port, low-level selection of Wigan, | **THIS MUST SELECT** |
| 4   | buzzer output, no card low, a card output 2.7k square wave     |                      |
| 5   | Serial TX output or Wigan 26 data D1                           | data out             |
| 6   | Wigan 26 data D0                                               |                      |
| 7   | reset terminal, active low to repeat reading                   |                      |
| 8   | ground                                                         | **MUST CONNECT**     |
| 9   | power supply                                                   | **MUST CONNECT**     |


- pin 1/2 antenna 
- pin 3 data type output selection, normally put to VCC
- pin 5 tx output data
- pin 8/9 power supply 



## read info 

- baudrate 9600
- EL125 tag read:  02 30 44 30 30 36 36 37 38 38 36 95 03 
- EM4100 tag read: 02 32 37 30 30 39 44 41 36 43 45 D2 03 
- test2:           02 30 39 30 30 37 43 42 32 43 30 07 03 


## Ref 

- [[125khz]]
- https://w.electrodragon.com/w/Category:EL125
- [[NID1020]]


## demo code 

- https://w.electrodragon.com/w/Category:EL125
- or Arduino demo code here: https://github.com/Edragon/Arduino-main/tree/master/Sketchbook/RF/16-RFID/125KHZ/EL-125

### Arduino
* Use software serial pin 6/7, connect RFID TX data pin to Arduino RX pin 6 or 7
* Module output selection pin should set to High for serial output

* To avoid interferences, use different power supply for RFID and arduino, but connect share common ground GND



## FAQ 

other RFID cards or keys 
- no guarantee the same performance, high quality RFID cards or tags are required!

performance
- Any microcontrollers should work, and lithium batteries also work, just add more capacitors to filter the noise in the power supply. The performance only changes a little or not if you do good filtering.

