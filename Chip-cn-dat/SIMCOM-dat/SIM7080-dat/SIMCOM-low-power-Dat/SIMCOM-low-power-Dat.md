

# SIMCOM-low-power-Dat.md

try our modules with [[SIMCOM-at-dat]]

NB-IoT technology supports three power-saving modes: 

- PSM (Power Saving Mode), 
- DRX (Discontinuous Reception Mode) 
- and eDRX (Extended DRX). 

In NB-IoT, PSM (Power Saving Mode) and eDRX (Extended Discontinuous Reception) are used to save power. In PSM mode, the terminal doesn't need to actively listen for paging messages to check for downstream data. On the other hand, eDRX mode has longer paging cycles compared to DRX mode, which can result in longer latency and potentially affect the real-time nature of data transmission. The choice between PSM and eDRX depends on the capabilities and configurations of both the terminal device and the network.

Regarding capabilities, it's important not to configure network features that the terminal does not support. Additionally, the terminal's supported capabilities may vary depending on the specific network conditions.


| No  | Mode | Description                                                                                                                                                                                                                                                       |
| --- | ---- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 1   | PSM  | Extremely save power, and do not receive any data.                                                                                                                                                                                                                |
| 2   | DRX  | Regularly turn off network services to find the device at any time.                                                                                                                                                                                               |
| 3   | eDRX | eDRX can further reduce the power consumption of NB-IoT devices and extend battery life compared to the traditional DRX mode. However, at the same time, the device may delay when receiving data due to the longer cycle and shorter reception duration of eDRX. |



NB-IoT 支持三种省电模式：

| mode | name                    | cn-name            | differences                            |
| ---- | ----------------------- | ------------------ | -------------------------------------- |
| PSM  | Power Saving Mode       | 省电模式           | 可能需要一两天才能找到设备。           |
| DRX  | Discontinuous Reception | 不连续接收模式     | 能够随时随地找到设备。                 |
| eDRX | Extended DRX            | 扩展不连续接收模式 | 需要花几分钟至一两个小时才能找到设备。 |

- [[SIMCOM-PSM-Dat]] - [[SIMCOM-eDRX-dat]]

## sleep mode - DRX

在休眠模式下，模块的电流消耗会降到最低，但模块仍能接收寻呼信息和 SMS。在 DRX 为 2.56s 的情况下耗流为 0.46mA。 

6.4.1  方法一 
 
    //sleep 模式示例 

    AT+CSCLK=1 
    
    OK 
    //进入慢时钟模式，然后拉高 DTR，模块就会进入休眠模式 
    //拉低 DTR，模块会退出休眠模式 

6.4.2  方法二 
 
    //sleep 模式示例 
    AT+CSCLK=2 
    
    OK 
    //自动进入慢时钟模式，当没有外部设备与模块交互时，模块会自动进入休眠模式 
    //发两次 AT 给模块即可唤醒模块 


## Boards 

- [[NGS1095-dat]] - [[NGS1096-dat]]


## ref 

- [[SIM7020-low-power-app_V1.05.pdf]]