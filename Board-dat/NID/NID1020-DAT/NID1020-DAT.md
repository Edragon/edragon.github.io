

# NID1020 DAT - EL125

- accessoires please read at page [[125khz-dat]]

- [product link - 125Khz RFID Long Distance Reader Module, 40CM, UART [Kit]](https://www.electrodragon.com/product/125khz-rfid-long-distance-module-40cm-serial/)
  
- card and accessories link - https://www.electrodragon.com/?s=125khz&post_type=product



## Notice:

**Notice demo video shows the BEST ideal setup**, different setup can not get the same good result. Read more details in our wiki instructions.

**Please ONLY use with high quality cards**, if you use other cards, it may not work as expected distance.

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





### Arduino
* Use software serial pin 6/7, connect RFID TX data pin to Arduino RX pin 6 or 7
* Module output selection pin should set to High for serial output

* To avoid interferences, use different power supply for RFID and arduino, but connect share common ground GND



## checklist 

- make sure there are not other metal materials too close to them, in case to avoid the interferences, which means you may need to clean up your table. 
- Power supply 5V / GND, use a pure AA *2 battery in case (100% reliable)
- hook pin 3 to 5V, and try to read serial data out from pin 5 TX


## demo code 

- https://w.electrodragon.com/w/Category:EL125
- or Arduino demo code here: https://github.com/Edragon/arduino-main2/tree/main/0-BSP/NID/NID1020-EL-125


## demo video 

- https://www.youtube.com/watch?v=9gzx0SZKJYE
- Test result is 20cm thin card, and 14cm key tag.: https://twitter.com/electro_phoenix/status/1001781336393175041



## Ref 

- legacy wiki page https://w.electrodragon.com/w/EL125_HDK

- more questions check at the - [[NID1020-faq-dat]] page

- [[125khz-dat]] - [[rfid-dat]]

- [[NID1020]]

