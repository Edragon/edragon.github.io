## ESP32 ISO board

## Board Pin Definitions

### Version V2

![](2023-10-20-16-11-07.png)

### Version V1

![](2023-09-26-15-08-07.png)

## Pin Definitions Template

| Pin | Prerequisite | Used for   |
| --- | ------------ | ---------- |
| 36  | input_only   | ~ lead-out |
| 39  | input_only   | ~ lead-out |
| 34  | input_only   | ~ lead-out |
| 35  | input_only   | ~ lead-out |
| 32  |              | IN1        |
| 33  |              | IN2        |
| 25  | DAC          | IN3        |
| 26  | DAC          | IN4        |
| 27  |              | OUT1       |
| 14  |              | OUT2       |
| 12  | strapping    | ~ lead-out |
| 13  |              | I2C        |
| 15  | strapping    | I2C        |
| 2   | strapping    | ~ lead-out |
| 0   | strapping    | ~ lead-out |
| 4   |              | OUT4       |
| 16  |              | U2         |
| 17  |              | U2         |
| 5   | strapping    | VSPI       |
| 18  |              | VSPI       |
| 19  |              | VSPI       |
| 20  |              | OUT3       |
| 21  |              | U1         |
| 3   | U0R          | U0         |
| 1   | U0T          | U0         |
| 22  |              | U1         |
| 23  |              | VSPI       |

## breakout daughter board

- RS232 [[DPR1084-dat]] - RS485 [MSP1076-dat]] - DCDC [[OPM1153-dat]]

## Use Guide

- connect IO0 to GND to enter into programming mode

## ref

- [[inductive-load-dat]]

- [[ESP32-dat]]

- [[ESP32-ISO]]

- [[interface-dat]]

## Demo video

- RS485 / RS422 / RS232 / CAN brekaout board with ESP32 ISO Board test - [youtube here](https://www.youtube.com/watch?v=ea_zn8Yjx-0&t=3s&ab_channel=Electrodragon).
