
# SIM7028-dat

The SIM7028 module support LTE Category NB2, 2-HARQ. The physical dimension of SIM7028 is 17.6mm×15.7mm×2.3 mm. 

It is designed for applications that need low latency, Low throughput datacommunication in a variety of radio propagation conditions.

- [[bands-dat]] - [[SIMCOM-size-dat]]

- [[SIM7028-dat]] will be a successor of module [[SIM7020-dat]]

## Product advantages

- Low power consumption: The module supports PSM low power mode. Theoretically, two No. 5 batteries can support 10 years

- Wide coverage: Compared with GSM, NB-IoT has a strong gain and a wide signal coverage, which also enables the product to have wireless communication capabilities in locations such as basements

## Compare to the decedent SIM7020

- [[SIM7020-dat]]



| **Feature**                | **SIM7028**                                                                 | **SIM7020**                                                |
|----------------------------|---------------------------------------------------------------------------|-----------------------------------------------------------|
| **Network Support**        | LTE Cat M1 (eMTC), LTE Cat NB2 (NB-IoT), EGPRS (2G fallback)              | LTE Cat NB1 (NB-IoT), LTE Cat NB2 (NB-IoT)                |
| **2G Support**             | Yes                                                                      | No                                                        |
| **Maximum Uplink Speed**   | - LTE Cat M1: **375 kbps**<br>- LTE Cat NB2: **127 kbps**<br>- EGPRS: **85.6 kbps** | - LTE Cat NB1: **62.5 kbps**<br>- LTE Cat NB2: **62.5 kbps** |
| **Maximum Downlink Speed** | - LTE Cat M1: **375 kbps**<br>- LTE Cat NB2: **158 kbps**<br>- EGPRS: **85.6 kbps** | - LTE Cat NB1: **27.2 kbps**<br>- LTE Cat NB2: **27.2 kbps** |
| **Power Consumption**      | Moderate (higher due to Cat M1 and 2G)                                    | Very low (optimized for NB-IoT applications)              |
| **Best Use Cases**         | - Asset tracking<br>- Wearables<br>- Smart metering                     | - Smart agriculture<br>- Environmental monitoring<br>- Basic sensors |
| **Cost**                   | Higher (due to wider network support)                                     | Lower (optimized for cost-sensitive IoT applications)     |
| **Module Size**            | Similar form factor for both modules                                     | Similar form factor for both modules                      |
| **Physical Interfaces**    | UART, I2C, GPIOs                                                         | UART, I2C, GPIOs                                          |
| **AT Command Compatibility** | Yes (standard SIMCom AT commands)                                       | Yes (standard SIMCom AT commands)                        |
| **Market Availability**    | More expensive but offers broader coverage                               | Lower cost and tailored for NB-IoT-only markets           |
| **Data Rate Comparison**   | Higher data rates (Cat M1 and 2G support)                                | Lower data rates (NB-IoT only)                            |


## Diagram 

![](2025-01-18-14-32-56.png)

## Pin definitions 

![](2025-01-18-14-37-42.png)


### Comparison 

compare to [[SIM7020-dat]]
- no I2C, SPI
- USB in progress, early version 
- extra IO_1833_sel

![](2025-01-18-14-40-49.png)



## ref 

- hardware design manual - [[SIM7028-Hardware-Design-1.0.pdf]]

- [[SIMCOM-dat]] - [[Cortex-M3-dat]]

- https://cn.simcom.com/product/SIM7028.html


