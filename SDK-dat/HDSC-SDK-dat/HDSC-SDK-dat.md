
# HDSC-SDK-dat

- [[HDSC-dat]] - [[HDSC-SDK-dat]] - [[HDSC-downloader-dat]] - [[ARM1007-dat]] - [[MDK-ARM-dat]] - [[HC32F003-dat]]



## HDSC ISP == programmer 

![](2024-05-15-17-46-45.png)

![](2024-05-15-17-50-41.png)

1) HC32x00x 和 HC32x11x 系列无 MODE/BOOT0 引脚，串行编程时需将串口模块的 RTS 或者 DTR 连接到目标 MCU 的 RESET 引脚。 
2) 不同型号芯片的 MODE/BOOT0 引脚的连接方式可能不一样，具体请参照表  1。 

![](2024-05-16-17-13-17.png)

### Flash for HC32F003

- better use our [[DPR1029-dat]] board, with DTR pin 
- DTR pin should be connected to MCU's reset pin 
- VDD 3.3V or 5V 
- Serial RXD to UART1_TXD_P35
- Serial TXD to UART1_RXD_P36

请确认目标芯片与串口模块的连接：
    MCU.VCC           <--->    串口模块.VCC
    MCU.GND           <--->    串口模块.GND
    MCU.TXD(P31/P35)  <--->    串口模块.RXD
    MCU.RXD(P27/P36)  <--->    串口模块.TXD
    MCU.RESET         <--->    串口模块.RTS/DTR





## MDK Support 

- HDSC.HC32F003.1.0.1.pack
- HDSC.HC32F005.1.0.1.pack



## SDK Driver and Examples 

- HC32F003 use HC32F005_SDK
- hc32f005_ddl_Rev1.9.0 Lite

- [[HDSC-dat]]



## CCID writer 

![](2026-02-21-15-54-34.png)


## demo 

demo images == - [[HDSC-dat]] - [[HC32F003-dat]] - [[HDSC-SDK-dat]] - [[NBL1107-dat]]

## repo

- [[HDSC-dat]]

- https://github.com/Edragon/MCU-HDSC-basic
- https://github.com/Edragon/MCU-HDSC-SDK
- https://github.com/Edragon/MCU-HDSC-HC32L110
- https://github.com/Edragon/MCU-HDSC-HC32F00X
- https://github.com/Edragon/MCU-HDSC-SDK-HC32L136
- https://github.com/Edragon/MCU-HDSC-APP
- E:\Git-category\git-MCU-HDSC



## ref 

