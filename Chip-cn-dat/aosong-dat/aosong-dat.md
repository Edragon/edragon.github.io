# aosong-dat

![](2024-02-28-16-16-27.png)


- [[STH1010-dat]] - [[STH1046-dat]] == [[DHT11-dat]] - [[STH1036-dat]]  - [[STH1020-dat]]

- [[STH1063-dat]]

- [legacy wiki page ](https://www.electrodragon.com/w/AM_Sensor)

- [[STH1033-dat]] - [[AMT1001-dat]] - [[AM1011-dat]]

AM2322
https://www.electrodragon.com/product/am2322-iic-temperaturehumanity-sensor/

AM2301 
https://www.electrodragon.com/product/am2301-dht21-digital-temperature-humidity-sensor/


- [[AM2320-dat]] - [[AM2322-dat]]

- [[sensor-temp-hum-dat]] - [[aosong-dat]]

## Humidity & Temperature Sensor Series — Quick Specs

| Specification           |                  AMT1001 |                   AM1011 |                   AM2011 |
| ----------------------- | -----------------------: | -----------------------: | -----------------------: |
| Humidity range (%RH)    |                    20–95 |                   0–99.9 |                   0–99.9 |
| Temperature range (°C)  |                     0–60 |                  -40–+80 |                  -40–+80 |
| Humidity accuracy       |                   ±5 %RH |                   ±3 %RH |                   ±3 %RH |
| Temperature accuracy    |                  ±0.5 °C |                  ±0.3 °C |                    ±1 °C |
| Supply voltage (V)      |                4.75–5.25 |                4.75–5.25 |                  4.2–5.5 |
| Output signal           | 0–3 V analog + 10 kΩ NTC | 0–3 V analog + 10 kΩ NTC | 0–3 V analog + 10 kΩ NTC |
| Product size (mm L×W×H) |       44.4 × 20.2 × 12.9 |       44.4 × 20.2 × 12.9 |       44.4 × 20.2 × 12.9 |

### General characteristics

- Temperature drift: < 0.1 °C / year
- Humidity drift: < 0.5 %RH / year
- Response time: Temperature ≈ 5 s; Humidity ≈ 5 s (1/e, 63% step)
- Sensor element: high-quality capacitive humidity sensor (silicon-based)
- Housing: ABS plastic
- Typical current consumption: ≈ 2 mA



## Specs 

| Model         | func    | status    | Interface   | temperature range | temperature precisions | humidity range | humidity precisions | SKU             |
| ------------- | ------- | --------- | ----------- | ----------------- | ---------------------- | -------------- | ------------------- | --------------- |
| [[DHT11-dat]] | T+H     | yes       | 1-wire      | -20~60 C          | +/-2 C                 | 5~95 % RH      | +/-5 % RH           | [[STH1046-dat]] |
| AM2301        | T+H     | yes       | 1-wire      | -40~80 C          | +/-0.5 C               | 0~99.9 % RH    | +/-3 % RH           | [[STH1036-dat]] |
| AM2302        | T+H     | yes       | 1-wire      | -40~80 C          | +/-0.5 C               | 0~99.9 % RH    | +/-3 % RH           | [[STH1010-dat]] |
| AM2320        | T+H     | yes       | IIC         | -40~80 C          | +/-0.5 C               | 0~99.9 % RH    | +/-3 % RH           | [[STH1024-dat]] |
| AHT10         |         |           | IIC         | -40~85 C          | +/-0.3 C               | 0~99.9 % RH    | +/-2 % RH           |                 |
| AHT15         | off-PCB |           | IIC         | -40~85 C          | +/-0.3 C               | 0~99.9 % RH    | +/-2 % RH           |                 |
| DHT10         |         | obseleted | IIC         |                   |                        |                |                     |                 |
| DHT12         |         | obseleted | IIC 1-wire  |                   |                        |                |                     |                 |
| AM2322        |         | yes       | IIC 1-wire  | -40~80 C          | +/-0.3 C               | 0~99.9 % RH    | +/-2 % RH           | [[STH1020-dat]] |
| AM2011        |         | x         | 0~3V analog |                   |                        |                |                     |                 |
| AM1011        |         | x         | 0~3V analog |                   |                        |                |                     |                 |
| AMT1001       | T+H     | yes       | 0~3V analog |                   |                        |                |                     | [[STH1033-dat]] |
| AM1001        | T       | x         | 0~3V analog |                   |                        |                |                     |                 |

- [[AHT20-dat]]




## ref 

- [[sensor-temperature-dat]]
