# ESP32-GPIOs-dat

## Sub Functions

### DAC

- IO25 IO26

## Note

### Input only

- 36/39/34/35

### Strapping

ESP32 共有 5 个 Strapping 管脚，可参考章节 6 电路原理图：

| Func. | IO  | default   |
| ----- | --- | --------- |
| MTDI  | 12  | pull-down |
| GPIO  | 0   | pull-up   |
| GPIO  | 2   | pull-down |
| MTDO  | 15  |           |
| GPIO  | 5   |           |

## Template

| Pin | Prerequisite | Used for |
| --- | ------------ | -------- |
| 36  | input_only   |          |
| 39  | input_only   |          |
| 34  | input_only   |          |
| 35  | input_only   |          |
| 32  |              |          |
| 33  |              |          |
| 25  | DAC          |          |
| 26  | DAC          |          |
| 27  |              |          |
| 14  |              |          |
| 12  |              |          |
| 13  |              |          |
| 15  | strapping    |          |
| 2   | strapping    |          |
| 0   | strapping    |          |
| 4   |              |          |
| 16  |              |          |
| 17  |              |          |
| 5   | strapping    |          |
| 18  |              |          |
| 19  |              |          |
| 20  |              |          |
| 21  |              |          |
| 3   | U0R          |          |
| 1   | U0T          |          |
| 22  |              |          |
| 23  |              |          |
