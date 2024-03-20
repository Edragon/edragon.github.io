
# ESP-12F-DAT

![](43-27-15-15-12-2022.png)

Dimension 

![](2024-03-20-18-38-13.png)

## ref 

- legacy chip wiki page here - https://w.electrodragon.com/w/Category:ESP8266
- legacy module page - https://w.electrodragon.com/w/ESP-12F_ESP8266_Wifi_Board



## Internal SCH

![](07-54-23-22-03-2023.png)

![](2023-11-28-17-17-46.png)

## Pin Definitions 

| left | --                         | right | --                 | func        |
| ---- | -------------------------- | ----- | ------------------ | ----------- |
| RST  | external pull-up, with cap | TXD   |                    |             |
| ADC  |                            | RXD   |                    |             |
| EN   | external pull-up           | IO5   |                    |             |
| IO16 |                            | IO4   |                    |             |
| IO14 |                            | IO0   | external pull-up   | mode select |
| IO12 |                            | IO2   | external pull-up   |             |
| IO13 |                            | IO15  | external pull-down |             |
| VCC  |                            | GND   |                    |             |


- on module LED IO2: low to on


## Periperhal design 

![](2023-11-28-17-17-01.png)


## datasheet 

- [[ESP-12F-DS.pdf]]
- [[ESP-12F-DS2-dat]]
- 
## ref 

- [[ESP8266-dat]]