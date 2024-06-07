
# HC32F003-dat


## Features 


### Low power 
-  5μA @ 3V  深度睡眠模式：所有时钟关闭，上电复位有效，IO  状态保持，IO  中断有效，所有寄存器、RAM  和  CPU  数据保存状态时的功耗 
-  10μA @32KkHz  低速工作模式：CPU  和外设模块运行中，从  Flash  运行程序 
-  30μA/MHz@3V@16MHz  睡 眠 模 式 ：CPU  停止工作，外设模块运行，主时钟运行 
-  150μA/MHz@3V@16MHz  工作模式：CPU  和外设模块运行，从  Flash  运行程序 
-  3μS  低功耗唤醒时间，使模式切换更加灵活高效，系统反应更为敏捷 
-  上述特性为室温下典型值，具体的电气特性，功耗特性参考电气特性一章

## Specs 

- 通用引脚数 GPIO  16 
- CPU 内核  Cortex M0+ 
- 频率  32MHz 
- 电源电压范围  1.8 ~5.5V 
- 单/双电源  单电源 
- 温度范围  -40 ~ 85℃




## Applications

For [[mesh-node-dat]] - [[NBL1107-dat]]

![](2024-05-15-16-48-43.png)


## Demo codes 

- AT: send AT commands to [[BLE-dat]] module [[NBL1101-dat]]
- [[I2C-dat]]: I2C data write and read 
- [[GPIO-dat]]: read write GPIO relay 



## ref 

- [[HDSC-SDK-dat]]