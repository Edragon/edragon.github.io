
# microsd-dat

- [[microsd-card-holder-dat]] - [[sd-dat]]

Micro sd card pins are:

- CS-Card Select
- DI-Data In [MOSI]-Master, Out Slave Input
- VSS-Ground
- VDD-Power
- CLK-Clock [SCLK]-Serial Clock
- DO-Data Out [MISO]-Master Input, Slave Output
- NC (Memory Cards)

SD 

| pin | 4-bit SD | 1-bit SPI |
| --- | -------- | --------- |
| 9   | DAT2     | -         |
| 1   | CD/DAT3  | CS        |
| 2   | CMD      | DI        |
| 3   | VSS1     | VSS1      |
| 4   | VDD      | VDD       |
| 5   | CLK      | SCLK      |
| 6   | VSS2     | VSS2      |
| 7   | DAT0     | DO        |
| 8   | DAT1     | -         |


![](2025-03-14-18-43-47.png)


## ref 

