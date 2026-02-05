
# NRF52840-dat


- [[NRF52840-mod-dat]] - [[NRF52840-board-1-dat]]



- [[NRF5x-dat]] - [[NRF52832-dat]] - [[NRF52840-dat]] - [[nordic-dat]]



| Feature                     | nRF52805 | nRF52810 | nRF52811 | nRF52820 | nRF52832 | nRF52833 | nRF52840 | nRF5340 |
| --------------------------- | :------: | :------: | :------: | :------: | :------: | :------: | :------: | :-----: |
| Bluetooth 5.3               |    X     |    X     |    X     |    X     |    X     |    X     |    X     |    X    |
| Bluetooth 2 Mbps            |    X     |    X     |    X     |    X     |    X     |    X     |    X     |    X    |
| Bluetooth Long Range        |          |          |    X     |    X     |          |    x     |    x     |    x    |
| Bluetooth Direction Finding |          |          |    X     |    X     |          |    X     |          |    x    |
| Bluetooth LE Audio          |          |          |          |          |          |          |          |    X    |
| Bluetooth mesh              |          |          |          |    x     |    x     |    x     |    x     |    X    |
| Thread                      |          |          |    X     |    X     |          |    x     |    x     |    X    |
| Zigbee                      |          |          |          |    X     |          |    x     |    x     |    X    |
| Matter                      |          |          |          |          |          |          |    X     |    X    |


## nRF52840 Features

- 32-bit ARM® Cortex®-M4F processor, 64 MHz
- 1 MB Flash, 256 KB RAM
- Bluetooth 5, Bluetooth mesh, Thread, Zigbee, 802.15.4, ANT, proprietary 2.4 GHz
- USB 2.0 full-speed (12 Mbps) device
- NFC-A tag support
- 48 programmable GPIOs
- SPI, I2C, UART, PWM, PDM, I2S, QSPI, and more
- 12-bit ADC, comparator, temperature sensor
- Crypto: AES, ECB, CCM, AAR, RNG, SHA-256
- On-chip DC-DC and LDO regulators
- Supply voltage: 1.7 V to 3.6 V
- Operating temperature: -40°C to +85°C
- Package: QFN73, 7x7 mm
- Arm TrustZone CryptoCell-310 security
- Flexible power management and low power consumption
- Direct Memory Access (DMA)
- Programmable Peripheral Interconnect (PPI)
- EasyDMA for peripherals
- 8/9/10/11/12-bit ADC, 200 ksps
- 4x 32-bit timers, RTC, watchdog, and more



## SDK 

- [[CONN-USB-dat]] - [[USB-dat]]


## drive 

- [[LCD-dat]]

## Pin Definitions 

![](2025-07-09-14-30-21.png)

## NRF52840 Pinout Table

| Pin Name | Default Func | Alt Func       | Notes              |
| -------- | ------------ | -------------- | ------------------ |
| P0.00    | GPIO         | *XL1, ADC, NFC |                    |
| P0.01    | GPIO         | *XL2, ADC, NFC |                    |
| P0.02    | GPIO         | ADC, NFC       |                    |
| P0.03    | GPIO         | ADC, NFC       |                    |
| P0.04    | GPIO         | ADC, NFC       |                    |
| P0.05    | GPIO         | ADC, NFC       |                    |
| P0.06    | GPIO         | ADC, NFC       |                    |
| P0.07    | GPIO         | ADC, NFC       |                    |
| P0.08    | GPIO         |                |                    |
| P0.09    | GPIO         | NFC1           | NFC antenna option |
| P0.10    | GPIO         | NFC2           | NFC antenna option |
| P0.11    | GPIO         |                |                    |
| P0.12    | GPIO         |                |                    |
| P0.13    | GPIO         |                |                    |
| P0.14    | GPIO         |                |                    |
| P0.15    | GPIO         |                |                    |
| P0.16    | GPIO         |                |                    |
| P0.17    | GPIO         |                |                    |
| P0.18    | RESET        | GPIO           | REST pin           |
| P0.19    | GPIO         |                |                    |
| P0.20    | GPIO         |                |                    |
| P0.21    | GPIO         |                |                    |
| P0.22    | GPIO         |                |                    |
| P0.23    | GPIO         |                |                    |
| P0.24    | GPIO         |                |                    |
| P0.25    | GPIO         |                |                    |
| P0.26    | GPIO         |                |                    |
| P0.27    | GPIO         |                |                    |
| P0.28    | GPIO         | ADC            |                    |
| P0.29    | GPIO         | ADC            |                    |
| P0.30    | GPIO         | ADC            |                    |
| P0.31    | GPIO         | ADC            |                    |
| P1.00    | GPIO         |                |                    |
| P1.01    | GPIO         |                |                    |
| P1.02    | GPIO         |                |                    |
| P1.03    | GPIO         |                |                    |
| P1.04    | GPIO         |                |                    |
| P1.05    | GPIO         |                |                    |
| P1.06    | GPIO         |                |                    |
| P1.07    | GPIO         |                |                    |
| P1.08    | GPIO         |                |                    |
| P1.09    | GPIO         |                |                    |
| P1.10    | GPIO         |                | Button             |
| P1.11    | GPIO         |                |                    |
| P1.12    | GPIO         |                |                    |
| P1.13    | GPIO         |                |                    |
| P1.14    | GPIO         |                |                    |
| P1.15    | GPIO         |                |                    |

The nRF52840 has two TWI (Two-Wire Interface/I2C) master instances: TWIM0 and TWIM1. You can configure them to use any pins through the Pin Selection Registers (PSEL). - [[I2C-dat]]

If you are using a development board, the software libraries (like Arduino or Zephyr) usually default to these:

nRF52840 Development Kit (PCA10056):

- SDA: P0.26
- SCL: P0.27

Adafruit Feather nRF52840:

- SDA: P0.25 (Physical Pin 25)
- SCL: P0.26 (Physical Pin 26)

## solutions 

- [[NRF52840+SX1262-dat]] - [[lora-dat]] - [[bluetooth-dat]]





## NRF52840 SCH 


![](2025-07-09-12-46-39.png)

- button == P1.10 
- REST == P0.18/RESET 

- I2C == P0.26 / P0.27 
- BAT_ADC == P0.04
- SPI == P1.12 ~ P1.15 

## SCH2 Module 

![](2025-07-09-15-30-56.png)



## ref 

- [[bluetooth-dat]] - [[nrf52840]]

- [[nordic-dat]]