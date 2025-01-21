
# ESP1000-dat

Module based on [[SCM1030-dat]]




## Pin Map 

| L_Pin | ESP32_CAM | tori     | M_Pin | ESP32_CAM | tori   | R_Pin | ESP32_CAM      | tori |
| ----- | --------- | -------- | ----- | --------- | ------ | ----- | -------------- | ---- |
| GND   |           |          | GND2  |           |        | GND   |                |      |
| 3V3   |           |          | 13    | microSD   | SCL    | 23    | CAM            |      |
| EN    |           |          | SD2   | PSRAM     |        | 22    | CAM            |      |
| 36    | CAM       |          | SD3   | PSRAM     |        | TXD0  |                |      |
| 39    | CAM       |          | CMD   |           |        | RXD0  |                | PIR  |
| 34    | CAM       |          | CLK   |           |        | 21    | CAM            |      |
| 35    | CAM       |          | SD0   | PSRAM     |        | --    |                |      |
| 32    | CAM_PWR   |          | SD1   | PSRAM     |        | 19    | CAM            |      |
| 33    |           |          | 15    | microSD   | SDA    | 18    | CAM            |      |
| 25    |           |          | 2     | microSD   | I2S_WS | 5     | CAM            |      |
| 26    | CAM       |          |       |           |        | 17    | PSRAM          |      |
| 27    | CAM       |          |       |           |        | 16    | PSRAM          |      |
| 14    | microSD   | I2S_SD   |       |           |        | 4     | microSD, flash |      |
| 12    | microSD   | I2S_SCLK |       |           |        | 0     | CAM            |      |





## In Use 

- [[I2S-dat]] - [[I2S-microphone-dat]]

- [[PIR-sensor-dat]] - [[BME280-dat]] - [[OLED-dat]] 

- [[sensor-dat]]

- [[consonance-dat]] - [[solar-power-dat]]

- [[ESP32-dat]] - [[SCM1030-dat]]



## Not in Use  

- [[SD-dat]]

- [[IP5306-dat]]


## Demo Code 

- https://github.com/Edragon/Arduino-ESP32/tree/master/BSP/APP/ESP32-tori

## Demo Video 

- [default camera log, powered by battery](https://x.com/electro_phoenix/status/1881569671020949656) 
- [I2S camera sound detect](https://x.com/electro_phoenix/status/1877590478109159437)
- [PIR sensor detector](https://x.com/electro_phoenix/status/1877256534687650008)

## ref 

- [[ESP1000]]