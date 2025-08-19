
# ESP-12F-DAT


## Definitions

![](43-27-15-15-12-2022.png)

## Dimension 

![](2024-03-20-18-38-13.png)

- pitch 2.0 mm 
- width 16 mm 


## ref 

- [legacy chip wiki page here](https://w.electrodragon.com/w/Category:ESP8266) 
- [legacy module page ](https://w.electrodragon.com/w/ESP-12F_ESP8266_Wifi_Board)



## Internal SCH

![](07-54-23-22-03-2023.png)


## Pin Definitions 

| left | template | boot mode    | func | right | template | boot mode | func         |
| ---- | -------- | ------------ | ---- | ----- | -------- | --------- | ------------ |
| RST  |          | ext.u, w/cap |      | TXD   |          |           |              |
| ADC  |          |              |      | RXD   |          |           |              |
| EN   |          | ext.u        |      | IO5   |          |           | I2C          |
| IO16 |          |              |      | IO4   |          |           | I2C          |
| IO14 |          |              | SCK  | IO0   |          | ext.u     | boot         |
| IO12 |          |              | MI   | IO2   |          | ext.u     | on-board LED |
| IO13 |          |              | MO   | IO15  |          | ext.d     | SS           |
| VCC  |          |              |      | GND   |          |           |              |

- [[NWI1083-dat]]


## Periperhal design 

![](2023-11-28-17-17-01.png)


## datasheet 

- [[ESP-12F-DS.pdf]]
- [[ESP-12F-DS2-dat]]


## ref 

- [[ESP8266-dat]]