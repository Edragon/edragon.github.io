## ESP32 ISO board

## Board Pin Definitions

![](2023-09-26-15-08-07.png)

## Pin Definitions Template

| Pin | Prerequisite | Used for |
| --- | ------------ | -------- |
| 36  | input_only   |          |
| 39  | input_only   |          |
| 34  | input_only   |          |
| 35  | input_only   |          |
| 32  |              | IN1      |
| 33  |              | IN2      |
| 25  | DAC          | IN3      |
| 26  | DAC          | IN4      |
| 27  |              | OUT1     |
| 14  |              | OUT2     |
| 12  |              |          |
| 13  |              | I2C      |
| 15  | strapping    | I2C      |
| 2   | strapping    |          |
| 0   | strapping    |          |
| 4   |              | OUT4     |
| 16  |              | U2       |
| 17  |              | U2       |
| 5   | strapping    | VSPI     |
| 18  |              | VSPI     |
| 19  |              | VSPI     |
| 20  |              | OUT3     |
| 21  |              | U1       |
| 3   | U0R          | U0       |
| 1   | U0T          | U0       |
| 22  |              | U1       |
| 23  |              | VSPI     |

## breakout daughter board

- [[DPR1084-dat]] - [[rs485-autoboard-1]] - [[OPM1153-dat]]

## Use Guide

- connect IO0 to GND to enter into programming mode

## ref

- [[inductive-load-dat]]

- [[ESP32-dat]]

- [[ESP32-ISO]]
