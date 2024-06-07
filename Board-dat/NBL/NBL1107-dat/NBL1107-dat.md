
# NBL1107-dat

https://www.electrodragon.com/product/ble-5-0-mesh-sensor-node-mini-board-mesh-node/

legacy wiki page - https://w.electrodragon.com/w/Mesh-Node

## Board Map 

![](2024-05-15-17-38-57.png)

- SJ1 setup button output to either Reset or P32

## Pin Definitiosn 

| MCU pins   | BT Modules | Sensors    | Other                |
| ---------- | ---------- | ---------- | -------------------- |
| Reset      |            |            | Button Reset or PROG |
| U0_TXD     | BT_RXD     |            |                      |
| U0_RXD     | BT_TXD     |            |                      |
| P03        | -          | -          | NC                   |
| P15        | BT_IN2     |            |                      |
| P14        | BT_IN1     |            |                      |
| P23        | BT_stat    |            |                      |
| P24        |            |            | Button Alternative   |
| P25        |            | Sensor SDA |                      |
| P26        |            | Sensor SCL |                      |
| P27        |            |            | lead out free        |
| P31        |            |            | lead out free        |
| P32        | BT_PWRC    |            |                      |
| P33        |            |            | Bat_ADC              |
| P34        |            |            | Relay                |
| P35_U1_TXD |            |            | free or PROG         |
| P36_U1_RXD |            |            | free or PROG         |



## ref 

- [[AHT20-dat]] - [[KX023-1025-dat]] - [[I2C-dat]]

- [[HC32F003-dat]] - [[HDSC-dat]]

- [[JDY-25M-dat]] - [[signal-relay-dat]]

- [[NBL1107]]