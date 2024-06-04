

# SIMCOM-PSM-Dat.md


NB-IoT 支持三种省电模式：

| mode | name                    | cn-name            | differences                            |
| ---- | ----------------------- | ------------------ | -------------------------------------- |
| PSM  | Power Saving Mode       | 省电模式           | 可能需要一两天才能找到设备。           |
| DRX  | Discontinuous Reception | 不连续接收模式     | 能够随时随地找到设备。                 |
| eDRX | Extended DRX            | 扩展不连续接收模式 | 需要花几分钟至一两个小时才能找到设备。 |

- [[SIMCOM-PSM-dat]] - [[SIMCOM-eDRX-dat]]

## sleep mode 
AT+CSCLK=1
OK

AT+CSCLK?
+CSCLK: 1

OK


## Boards 

- [[NGS1095-dat]] - [[NGS1096-dat]]


## ref 

- [[SIM7020-low-power-app_V1.05.pdf]]