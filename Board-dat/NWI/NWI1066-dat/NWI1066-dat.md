# NWI1066-dat

https://www.electrodragon.com/product/d1wifi-arduino-based-board-arduino-nodemcu-compatible/

- legacy wiki page - https://w.electrodragon.com/w/Arduino-ESP8266
- legacy wiki page 2 - https://w.electrodragon.com/w/Category:ESP8266_Boards

## Pins

| 引腳        | 說明                                   | IC 內部引腳 |
| ----------- | -------------------------------------- | ----------- |
| D0(RX)      | 串口接收                               | GPIO3       |
| D1(TX)      | 串口發送                               | GPIO1       |
| D2          | I/O, 不支持中斷，PWM， I2C 以及 1-wire | GPIO16      |
| D3/SCL/D15  | I/O，默認模式下，I2C 的 SCL            | GPIO5       |
| D4/SDA/D14  | I/O，默認模式下，I2C 的 SDA            | GPIO4       |
| D5/SCK/D13  | I/O，SPI 的時鐘                        | GPIO14      |
| D6/MISO/D12 | I/O，SPI 的 MISO                       | GPIO12      |
| D7/MOSI/D11 | I/O，SPI 的 MOSI                       | GPIO13      |
| D8          | I/O，上拉，低電平時，進入 FLASH 模式   | GPIO0       |
| D9/TX1      | I/O， 上拉                             | GPIO2       |
| D10/SS      | I/O， 下拉，SPI 時，默認的片選（SS）   | GPIO15      |
| A0          | AD 輸入，0-3.3V                        | ADC         |


* 所有的 IO 工作電平為 3.3V，可瞬間承受 5V
* 除 D2 外，所有 I/O 都支持中斷，PWM，I2C，跟 1-wire


![](2023-12-04-18-06-06.png)

![](2023-12-04-18-06-26.png)

## ref


硬件包：http://pan.baidu.com/s/1qWUSNrY

- [[NWI1066]]
