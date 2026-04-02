

# ESP32-WROVER-DAT

- [[ESP32-dat]] 

- [[NWI1103-dat]]


https://www.electrodragon.com/product/esp32-wrover-v4-module-based-esp32/

- development board - [[NWI1100-dat]] by swaping the module

- [[PSRAM-dat]]



## sale version 



IPEX-ANT
[[NWI1137-dat]] - Default RVI: ESP-WROVER-I, IPEX-ANT, 4MB
[[NWI1192-dat]] - RVI: ESP-WROVER-I, IPEX-ANT, 8MB - [[Board-stock-out]]
[[NWI1193-dat]] - RVI: ESP-WROVER-I, IPEX-ANT, 16MB

PCB-ANT
[[NWI1136-dat]] - Default RVB: ESP-WROVER, PCB-ANT, 4MB 
[[NWI1190-dat]] - RVB: ESP-WROVER, PCB-ANT, 8MB
[[NWI1191-dat]] - RVB: ESP-WROVER, PCB-ANT, 16MB

## version ESP32-WRover-E

![](2026-04-02-20-49-28.png)

| Module Model | Built-in ESP32 Chip | SRAM | ROM | Espressif Recommendation |
| ------------ | ------------------- | ---- | --- | ------------------------ |
| ESP32-WROVER-B | ESP32-D0WD | 512K | 512K | Not recommended for new designs |
| ESP32-WROVER-E | ESP32-D0WD-V3 | 448K | 448K | Recommended for new designs in 2024 |

该链接核心板使用是乐鑫2024年推荐用于新设计的ESP32-WROVER-E模组。该模组有3种不同的外置fash配置，常说的ESP32其实不用外置fash就可以使用，因为ESP32芯片本身内置了448KB的ROM，对于一般应用这448KB的ROM就足够了，但是涉及到一些需要储存的数据还是需要依赖外部储存Flash的，这里可以提供4M，8M，16M外置flash可以选择。大的外部Flash容量模组可以无缝兼容小容量Flash的模组的程序，无需修改。外扩RAM都是8M.

![](2026-04-02-20-54-55.png)

- N8R8(8M Flash)
- N16R8(16M Flash)


## Pin map 

![](2024-12-26-18-38-26.png)

19x19 




## Chip Version 

About ESP32 chips and modules Espressif company's recommendation description

| Module         | model built-in ESP32 chip model | built-in sram | built-in rom | Espressif recommended status        |
| -------------- | ------------------------------- | ------------- | ------------ | ----------------------------------- |
| ESP32-WROVER-B | ESP32-D0WD                      | 512K          | 448K         | Not recommended for new designs     |
| ESP32-WROVER-E | ESP32-D0WD-V3                   | 512K          | 448K         | Recommended for new designs in 2024 |

| Board Link      | Description               |          | Memory | Notes               |
| :-------------- | :------------------------ | -------- | ------ | :------------------ |
| [[NWI1137-dat]] | Default RVI: ESP-WROVER-I | IPEX-ANT | 4MB    |                     |
| [[NWI1192-dat]] | RVI: ESP-WROVER-I         | IPEX-ANT | 8MB    | [[Board-stock-out]] |
| [[NWI1193-dat]] | RVI: ESP-WROVER-I         | IPEX-ANT | 16MB   |                     |
| [[NWI1136-dat]] | Default RVB: ESP-WROVER   | PCB-ANT  | 4MB    |                     |
| [[NWI1190-dat]] | RVB: ESP-WROVER           | PCB-ANT  | 8MB    |                     |
| [[NWI1191-dat]] | RVB: ESP-WROVER           | PCB-ANT  | 16MB   |                     |

## new version 

ESP32-WROVER-E 和 ESP32-WROVER-IE 是两款通用型 Wi-Fi+BT+BLE MCU 模组，功能强大，用途广泛，可以用于低功耗传感器网络和要求极高的任务，例如语音编码、音频流和 MP3 解码等。ESP32-WROVER-E 采用 PCB 板载天线，ESP32-WROVER-IE 采用 IPEX 天线。两款模组均配置了 4 MB (还有 8 MB, 16 MB两种规格) SPI flash和 8 MB SPI PSRAM。

ESP32-WROVER-E 和 ESP32-WROVER-IE 采用的芯片是 ESP32 系列的 ESP32-D0WD-V3。具有可扩展、自适应的特点。两个 CPU 核可以被单独控制。时钟频率的调节范围为 80 MHz 到 240 MHz。模组集成了传统蓝牙、低功耗蓝牙和 Wi-Fi，组具有行业领先的技术规格，在高集成度、无线传输距离、功耗以及网络联通等方面性能佳。



## certificate 

![](2026-04-02-20-51-55.png)


![](2026-04-02-20-52-47.png)



## ref 

