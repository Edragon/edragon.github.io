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


### regarding GPIO20 

for newer ESP32 variants
- Enable IO20 on ESP32
- Some newer ESP32 variants (like ESP32-PICO-V3 and ESP32-PICO-MINI-02) do implement this pin and it can be used as a normal GPIO.

https://github.com/espressif/esp-idf/commit/6deaefde69c3f068d39b76d628b05b21fd142b79

for classic ESP32 
- IO20 = NC

