
# NWI1083-dat

https://www.electrodragon.com/product/d1-mini-wifi-dev-board-esp8266-esp12f/


https://w.electrodragon.com/w/Category:ESP8266_HDK


## SCH 

![](2024-01-02-17-55-10.png)

## Pin Definitions 

![](2024-01-02-17-56-37.png)

![](2024-01-02-17-56-55.png)

| mod. | note | left | L pin | L board | R board | R pin | right | note | mod. |
| ---- | ---- | ---- | ----- | ------- | ------- | ----- | ----- | ---- | ---- |
| p-u  |      | 1    | RST   | RST     | TX      | io1   | 22    |      |      |
|      | ADC  | 2    | A0    | A0      | RX      | io3   | 21    |      |      |
|      |      | 4    | io16  | D0      | D1      | io5   | 20    | SCL  |      |
|      | SCK  | 5    | io14  | D5      | D2      | io4   | 19    | SDA  |      |
|      | MISO | 6    | io12  | D6      | D3      | io0   | 18    |      | p-d  |
|      | MOSI | 7    | io13  | D7      | D4      | io2   | 17    |      | p-u  |
| p-d  | SS   | 16   | io15  | D8      | G       | G     | 15    |      |      |
|      |      | 8    | 3V3   | 3V3     | 5V      | 5V    | 5V    |      |      |

- [[ESP8266-HDK-dat]]

- [[arduino-esp8266-dat]]


## ref 

- [[ESP8266-dat]]

- [[NWI1083]] - [[m]]