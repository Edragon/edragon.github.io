# NWI1118-DAT

- new version please see at page [[NWI1119-dat]]


### hardware 

![](2023-10-09-13-55-10.png)

#### R6 

| pin-left | function   | pin-right | function    |
| -------- | ---------- | --------- | ----------- |
| IO15     | -          | ADC       | Analog Read |
| IO16     | status LED | RST       | Reboot      |
| RXD      |            | IO14      |             |
| TXD      |            | IO05      | pull-up     |
| +5V      |            | IO04      | pull-up     |
| GND      |            | 3V3       |             |


- IO13 = relay 1
- IO12 = relay 2 
- IO2 = status LED (also on module ESP-12F)
- IO0 = BTN2
- RST = BTN1


## installation 

- https://t.me/electrodragon3/319



## Other Obseleted Logs 

#### R5 

- IO2 = BTN1
- IO0 = BTN2

- IO13 = relay 1
- IO12 = relay 2 
- IO14 = IO14
- IO16  = status LED
- IO4, IO5 = I2C Pull up 


## ref 

- [[ESP-SDK-dat]]

- [[esp-relay-board-dat]]

- [[ESP-12F-DAT]] - [[ESP32-­C3-­WROOM-­02-DAT]] - [[ESP8266-dat]]

- [[ACDC-SM]] - [[voltage-divider-dat]]


- code reference - [[NWI1139-DAT]]


- [[NWI1118]]