
# BTB dat 

- [[FPC-dat]]

- [[ESP32-SPI-dat]]

mount the concave part on the bottom, and convex part on the top

https://www.electrodragon.com/w/ED-BTB


## BTB 12 pins connector 

| ESP32 Pin | Function | Lora       |
| --------- | -------- | ---------- |
| IO14      | SPI_SCK  |            |
| IO12      | SPI_MISO |            |
| IO13      | SPI_MOSI |            |
| IO15      | SPI_CS   |            |
| IO4       | IO       | LORA_IRQ   |
| IO27      | IO       | LORA_RESET |



| ESP8266 | func     | conn.L | conn.R | func         | ESP8266 |
| ------- | -------- | ------ | ------ | ------------ | ------- |
| io16    | IO0      | L-1    | R-1    | serial / IO5 | TXD     |
| io14    | SPI_SCK  | L-2    | R-2    | serial / IO4 | RXD     |
| io12    | SPI_MISO | L-3    | R-3    | SCL / IO3    | io5     |
| io13    | SPI_MOSI | L-4    | R-4    | SDA / IO2    | io4     |
| +5V     | power    | L-5    | R-5    | SPI_CS       | io15_d  |
| 3V3     | power    | L-6    | R-6    | power        | GND     |

- 1x 4-line [[SPI-dat]] + 5x [[GPIO-dat]]
- 1x 4-line [[SPI-dat]] + 1x [[Serial-dat]] + 1x [[I2C-dat]] + 1x [[GPIO-dat]]
- 1x 4-line [[SPI-dat]] + 1x [[Serial-dat]] + 3x [[GPIO-dat]]

- [[ESP8266-HDK-dat]]

- [[LORA-HDK-dat]] - [[SX1262-MD1-dat]]

## connectors 

- total height = 3.0
- 12P, 0.8mm pitch 


![](2024-10-02-20-05-38.png)

![](2024-10-02-20-05-52.png)

## base board

- [[ESP32-dat]]

![](40-27-15-02-08-2023.png)

- [[NWI1230-dat]] == [[ESP8266-dat]]

![](2025-07-16-15-24-50.png)


## supported boards 



- [[NGS1128-DAT]] == [[SIM7080-dat]]



## attach board ref 

### lora


- [[Lora-dat]] - [[ESP32-SPI-dat]]


- use UART as main interface 

![](47-32-15-02-08-2023.png)




### SIM7020 

- use UART as main interface 

![](54-48-15-02-08-2023.png)


### SIM7080

- [[NGS1128-dat]]
- removed, due to less popular 

![](2024-04-11-16-24-27.png)



## ref 

- [[BTB]]