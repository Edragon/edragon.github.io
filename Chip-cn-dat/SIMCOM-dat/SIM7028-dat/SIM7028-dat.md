
# SIM7028-dat

- order at [[NGS1135-dat]]


The SIM7028 module support LTE Category NB2, 2-HARQ. The physical dimension of SIM7028 is 17.6mm×15.7mm×2.3 mm. 

It is designed for applications that need low latency, Low throughput datacommunication in a variety of radio propagation conditions.

- [[bands-dat]] - [[SIMCOM-size-dat]]

- [[SIM7028-dat]] will be a successor of module [[SIM7020-dat]]

based on [[qualcomm-dat]] - [[A212-dat]] platform


## Product advantages

- Low power consumption: The module supports PSM low power mode. Theoretically, two No. 5 batteries can support 10 years

- Wide coverage: Compared with GSM, NB-IoT has a strong gain and a wide signal coverage, which also enables the product to have wireless communication capabilities in locations such as basements


## Chip Features Overview 

- Power supply Power supply voltage：2.2V～4.3V.
- Power saving
  - DRX:0.11mA (DRX=2.56s)
  - eDRX:0.018mA (PTW=25.6s；eDRX=163.84s；DRX=2.56s)
  - PSM mode Typical: 0.8uA
- Radio frequency bands Please refer to the table 1
- Transmitting power LTE power class: 3 (23dBm±2.7dB)
- Data Transmission Throughput
  - LTE CAT NB2: 127Kbps (DL).
  - LTE CAT NB2: 159Kbps (UL).
- Antenna LTE main antenna.
- SIM interface Support identity card: 1.8V/3V.
- UART1 interface
  - A full modem serial port by default
  - Can be used as the AT commands
  - Can be used for firmware upgrade and RF calibration
  - Baud rate: default:115200bps
- UART0 Software debugging and debugging log output. The default baud rate is 3Mbps.
- Firmware upgrade Firmware upgrade over UART1 interface
- Physical characteristics 
  - Size: 17.6mm×15.7mm×2.3 mm
  - Weight: 1.3g±0.2g
- Temperature range 
  - operation temperature: -40°C to +85°C
  - Storage temperature: -45°C to +90°C
- Note: When VBAT is lower than 3V, the radio frequency can work but the performance of some indicators
may not meet the 3GPP standard.

## Hardware Interface Overview

The interfaces are described in detail in the next chapters include:
- ● Power Supply
- ● UART Interface
- ● SIM Interface
- ● ADC
- ● Power Output
- ● GPIOs
- ● Antenna Interface





## Compare to the decedent SIM7020

compare to [[SIM7020-dat]]
- no I2C, SPI
- USB in progress, early version 
- extra IO_1833_sel
- NET LED will not blink 
- Module automatically ON when power supplied 



| **Feature**                  | **SIM7028**                                                                         | **SIM7020**                                                          |
| ---------------------------- | ----------------------------------------------------------------------------------- | -------------------------------------------------------------------- |
| **Network Support**          | LTE Cat M1 (eMTC), LTE Cat NB2 (NB-IoT), EGPRS (2G fallback)                        | LTE Cat NB1 (NB-IoT), LTE Cat NB2 (NB-IoT)                           |
| **2G Support**               | Yes                                                                                 | No                                                                   |
| **Maximum Uplink Speed**     | - LTE Cat M1: **375 kbps**<br>- LTE Cat NB2: **127 kbps**<br>- EGPRS: **85.6 kbps** | - LTE Cat NB1: **62.5 kbps**<br>- LTE Cat NB2: **62.5 kbps**         |
| **Maximum Downlink Speed**   | - LTE Cat M1: **375 kbps**<br>- LTE Cat NB2: **158 kbps**<br>- EGPRS: **85.6 kbps** | - LTE Cat NB1: **27.2 kbps**<br>- LTE Cat NB2: **27.2 kbps**         |
| **Power Consumption**        | Moderate (higher due to Cat M1 and 2G)                                              | Very low (optimized for NB-IoT applications)                         |
| **Best Use Cases**           | - Asset tracking<br>- Wearables<br>- Smart metering                                 | - Smart agriculture<br>- Environmental monitoring<br>- Basic sensors |
| **Cost**                     | Higher (due to wider network support)                                               | Lower (optimized for cost-sensitive IoT applications)                |
| **Module Size**              | Similar form factor for both modules                                                | Similar form factor for both modules                                 |
| **Physical Interfaces**      | UART, I2C, GPIOs                                                                    | UART, I2C, GPIOs                                                     |
| **AT Command Compatibility** | Yes (standard SIMCom AT commands)                                                   | Yes (standard SIMCom AT commands)                                    |
| **Market Availability**      | More expensive but offers broader coverage                                          | Lower cost and tailored for NB-IoT-only markets                      |
| **Data Rate Comparison**     | Higher data rates (Cat M1 and 2G support)                                           | Lower data rates (NB-IoT only)                                       |

![](2025-01-18-14-40-49.png)

## Diagram 

![](2025-01-18-14-32-56.png)

## Pin definitions 

![](2025-01-18-14-37-42.png)



## AT Commands Log

- use pre-built at commands from here [[SIMCOM-AT-dat]]

Boost test 

    LoadVerifyImageHead read(len=272), Time(ms)->0.
    test:VerifyImageHead skip
    VerifyImageBody sha256 skip

    *ATREADY: 1

    SIM Ready

    Network Available

    +CESQ: 99,99,255,255,31,70

    OK

    OK

    +QCPING: SUCC, dest: 59.111.160.244, RTT: 623 ms

    +QCPING: SUCC, dest: 59.111.160.244, RTT: 150 ms

    +QCPING: SUCC, dest: 59.111.160.244, RTT: 147 ms

    +QCPING: SUCC, dest: 59.111.160.244, RTT: 143 ms

    +QCPING: DONE

    +QCPING: dest: 59.111.160.244, 4 packets transmittted, 4 received, 0 % packet loss rtt min/avg/max = 143 / 265 / 623 ms




## ref 

- at commands manual - [[SIM7028 Series_AT Command Manual_V1.00.pdf]] - [[SIMCOM-AT-dat]]

- [[SIM7028-for-raspberrypi.zip]]

- hardware design manual - [[SIM7028-Hardware-Design-1.0.pdf]]

- [[SIMCOM-dat]] - [[Cortex-M3-dat]] - [[SIMCOM-PSM-Dat]]

- https://cn.simcom.com/product/SIM7028.html
