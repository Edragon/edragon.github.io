
# SDR1096 DAT


## info 

[Arduino Zero Samd21 Compatible Motor Drive Board M21](https://www.electrodragon.com/product/arduino-zero-samd21-compatible-motor-drive-board/)


## hardware 

![](48-28-16-17-04-2023.png)

### Pin Info 

Middle 4 columns * 3 rows pins, column from left to right : 

- V+: motor power supply 
- GND: ground 
- VIN: USB 5V Input 
- 3V3: 3.3V output from regulator

Other peripheral 
- Programmable LED pin D13 


#### A4954: motor driver
- D4 Vref2
- D5 IN3
- D6 IN4
- D7 IN2
- D8 IN1
- D9 Vref1

- [[A4954-dat]]

#### AS5047D: decoder, provding close-loop feedback
- A2 SPI_SS
- D11 SPI_MOSI
- D12 SPI_MISO
- D13 SPI_SCK



## ref 
- https://github.com/Misfittech/nano_stepper/
- https://github.com/NiryoRobotics/niryo_stepper
- [[AS5047-DAT]]

### demo code please find at 
- [[arduino-code-v2-dat]]
- or reference design Mechaduino



### main chips 
- [[SAMD21-dat]] - SAMD21G18A-AUT: main controller 
- [[A4954-DAT]]
- Magnetic Encoder [[AS5047D-dat]]


### other info 
- [[power-flow-control-dat]]
- [[SDR1096]]
- [legacy wiki page link](https://w.electrodragon.com/w/SDR1096_Motor_Drive_Board)

