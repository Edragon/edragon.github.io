
# NID1005-DAT


[EM4100 125Khz RFID Card Read Module, UART](https://www.electrodragon.com/product/125khz-em4100-rfid-card-read-module-rdm630-uart-output-arduino-shield/)

[Legacy Documentation](https://w.electrodragon.com/w/RDM6300)


Order keys or cards: 

[em4100-125khz-rfid-keys](https://www.electrodragon.com/product/em4100-125khz-rfid-keys/)



[em4100-125khz-rfid-card-compatible-with-rdm630](https://www.electrodragon.com/product/em4100-125khz-rfid-card-compatible-with-rdm630/)

## wiring and guide 

Pins are defined as follows:

* P1 port : 1.TX 2.RX 3.reserve 4.GND 5.VCC<br />
* P2 port : Antenna coil<br />
* P3 port : 1.LED 2.VCC 3.GND<br />
 
The arduino connection:<br />

* With module :TX to RX ; RX to TX; VCC to 5V; GND to GND<br />
* With LCD: RS => pin 12   RW => pin 11  EN => pin 10<br />
* D4, D5, D6, D7 => pins 5, 4, 3, 2<br />



## datasheet 

- [[RDM630-Spec.pdf]]
- arduino library [[RFIDRdm630.zip]]
- Demo code please see at https://github.com/Edragon/Arduino/tree/master/Sketchbook/16-RFID

- broken: http://playground.arduino.cc/Main/RDM630RFIDReaderLibrary



## ref 

- [[EM4100-dat]] - [[125khz-dat]]

- [[RFID-dat]]