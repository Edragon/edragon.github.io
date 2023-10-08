# NWI1119

- R7 ESP32-C3 Version

#### R7 ESP32-C3 Version

- programmerable LED IO10
- programmerable / Flash Button IO9
- Reset Button
- Relay Pin IO6 / IO7
- ADC Port Pin IO0
- Default Pull up IO2 IO8
- I2C Expand Pin Headers IO4 IO5 3V3 GND

### Pin Definitions

| Pin                    | Function                       |
| ---------------------- | ------------------------------ |
| IO0                    | ADC                            |
| IO2 / IO8 with pull-up | on-board resistors for booting |
| IO4 / IO5 with pull-up | on-board resistors for I2C     |
| IO6                    | relay 1                        |
| IO7                    | relay 2                        |
| IO09                   | PROG Button                    |
| IO10                   | on board LED, via jumper       |

![](39-39-16-07-02-2023.png)

### demo video

- https://www.youtube.com/watch?v=6Zk3WIVSvyM
- https://twitter.com/electro_phoenix/status/1622874731493072897

### ref

- [[ESP-SDK-dat]] - [[arduino-esp32-dat]]
- [[ESP32-USB]]
- [[ESP32-C3-WROOM-02-DAT]]
