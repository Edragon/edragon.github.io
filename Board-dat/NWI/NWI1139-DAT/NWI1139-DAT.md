

## Hardware 

This is a board similar to [[NWI1172-dat]], but more suitable for inductive load control, such as motor, solenoid, etc. - [[inductive-load-dat]]


## pin definitions 

    #define onModule_LED 2
    #define relay1 12
    #define relay2 13
    #define onBoard_LED 16

![](36-17-17-31-03-2023.png)

pin header: 

![](2025-07-15-15-01-07.png)

| L   | R    |
| --- | ---- |
| +5V | GND  |
| TXD | RXD  |
| IO5 | IO4  |
| 3V3 | IO2  |
| ADC | IO15 |
| --- | IO14 |


## SCH 

![](2023-09-05-18-16-05.png)


## AP demo code 

- hold down GPIO0 button and press reset button to enter into flash mode 


- https://github.com/Edragon/arduino-esp8266/tree/master/Sketchbook
- and into BSP folder - NWI1139

### control commands 

- find [[WIFI-DAT]] AP "ESP_Relay_Board"
    192.168.4.1
    http://192.168.4.1/r11 # turn on relay1 to 1 
    http://192.168.4.1/m1 # turn on module led to 1  (GPIO2)
    http://192.168.4.1/b1 # turn on board led to 1  (GPIO16)

## store BOM 

- [[OPM1110-dat]] 


## ref 

- [[relay-dat]]

- [[OPM1143-dat]] - [[RC-snubber-dat]] - [[inductive-load-dat]]

- [[esp-relay-board-dat]]

- [[NWI1139]]