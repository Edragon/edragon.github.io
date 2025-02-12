
# MCU-dat 

- [[CPLD-dat]] - [[RISC-V-dat]]

- [[WCH-dat]]

- [[STM32-dat]]

- [[AVR-dat]] - [[tinyAVR-dat]]

- [[STC-dat]]

- [[nuvoton-dat]]

## Common-used MCU 

| model             | price       | category       | footprint                      | features               | boards          |
| ----------------- | ----------- | -------------- | ------------------------------ | ---------------------- | --------------- |
| STM8S003F3P6TR    | 100+: 1.59  | [[stm8-dat]]   |                                |                        |                 |
| STM32F103C8T6     | 30+: 6.85   | [[stm32-dat]]  |                                |                        |                 |
| STM32F103RCT6     | 30+: 9.56   | [[stm32-dat]]  |                                |                        |                 |
| STM32F030F4P6TR   | 30+: 3.04   | [[stm32-dat]]  |                                |                        |                 |
| STM32G030x6/x8    |             | [[stm32-dat]]  | LQFP48 / LQFP32                |                        |                 |
| STM32G031x4/x6/x8 |             | [[stm32-dat]]  | UFQFPN28 / UFQFPN32 / UFQFPN48 | USART x2               |                 |
| ATmega4808        | 1+ 11.160   | [[attiny-dat]] | QFN                            |                        |                 |
| ATmega4808        | 1+ 11.160   | [[attiny-dat]] | QFN                            |                        |                 |
| ATtiny1604        |             | [[attiny-dat]] |                                |                        | [[SVC1039-dat]] |
| ATtiny1616        |             | [[attiny-dat]] |                                | USART x1               |                 |
| ATtiny416         | 25+ 4.760   | [[attiny-dat]] | QFN x20                        | USART x1 / I2C x1 /    |                 |
| ATtiny202         |             | [[attiny-dat]] |                                |                        | [[ILE1073-dat]] |
| ATttiny88         |             | [[attiny-dat]] |                                | USART x?               |                 |
| ATSAMD21-G18A     |             | [[SAMD21-dat]] |                                |                        | [[SDR1096-dat]] |
| ATSAMD21-E15L-MNT | 1 : 7.39000 | [[SAMD21-dat]] |                                | (USART+I2C+SPI+LIN) x6 |                 |
| HC32F00X          |             | [[HDSC-dat]]   | QFN x20                        | USART x2               | [[NBL1107-dat]] |
| RP2040            | 30+: 5.24   | [[RPI-dat]]    |                                |                        |                 |



## Dev Boards 

ATtiny 
- [[SVC1039-dat]] - [[ILE1073-dat]]

SAMD21 
[[SDR1096-dat]]



## Cheap High-operating temperature MCUs 

| MCU Model           | Core            | Operating Temp | Operating Current | Power Supply | Pins | Interfaces (SPI, UART, RTC) |
|---------------------|----------------|---------------|------------------|--------------|------|-----------------------------|
| Texas Instruments TMS570LS0432 | ARM Cortex-R4F | -40°C to 175°C | ~5-10mA       | 1.2V–3.3V  | 64   | SPI, UART (RX/TX), RTC     |
| Microchip ATSAMC21J18A | ARM Cortex-M0+ | -40°C to 180°C | ~5-8mA         | 1.62V–3.6V  | 64   | SPI, UART (RX/TX), RTC     |
| NXP S32K144 | ARM Cortex-M4F | -40°C to 175°C | ~7-10mA       | 1.71V–3.6V  | 64   | SPI, UART (RX/TX), RTC     |
| GigaDevice GD32A5xx           | ARM Cortex-M33   | -40°C to 125°C | ~5-8 mA           | 1.62V–3.6V   | 64   | SPI, UART (RX/TX), RTC      | 


- TMS570LS0432
- ATSAMC21J18A
- S32K144

- FS32K144HAT0MLHR == 10+: ￥29.48
- FS32K144HAT0MLHR == 10 usd 