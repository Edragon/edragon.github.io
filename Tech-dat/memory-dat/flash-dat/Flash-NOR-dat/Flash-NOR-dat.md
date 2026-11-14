

# Flash-NOR-dat


- [[Flash-SPI-dat]] - [[Flash-NAND-dat]] - [[Flash-NOR-dat]] - [[flash-dat]]

- [[micron-dat]] - [[SDram-dat]]




## build 

- [[PCB-footprint-dat]] - [[flash-nor-dat]]

- [[flash-NOR-dat]] - [[audio-receiver-dat]] - [[audio-dat]] 


- [[WSON-8-dat]] - [[PCB-footprint-dat]] - [[flash-nor-dat]] 


根据芯片表面的丝印和封装特征，这颗芯片的基本信息如下：
 * 制造商：GigaDevice（兆易创新），芯片右侧的图形标志是兆易创新的经典“G”字Logo。
 * 丝印信息：
   * `1936` ：代表生产日期（Date Code），即 2019年第36周。
   * `25CE`.（首位数字“2”被红色标记点部分遮挡，完整型号通常为 25Q... 或 25D...，结合末位字母推测极有可能是 GD25Q16CE 或 GD25Q32CE / GD25Q64CE 系列）。
 * 芯片类型与封装：这是一颗 SPI NOR Flash（串行闪存） 芯片，采用 `WSON-8`（无引脚扁平封装，尺寸通常为 6×5mm 或 8×6mm）。
 * 
判断依据与用途：
它紧邻下方的大型主控芯片（MCU/SoC）和右侧的晶振（H24...），在电路中主要作为外部存储器，用于存放主控芯片的启动代码（Bootloader）、固件程序或配置参数。

如何确认具体容量型号：

由于最关键的容量数字位被红点漆（通常用于标记已烧录固件）遮挡，如果需要准确知道它是 16Mbit、32Mbit 还是 64Mbit：
 * 可以用酒精或洗板水轻轻擦除表面的红点漆，露出完整丝印（例如 25Q32CE 或 25Q64CE）。
 * 或者使用编程器（如 CH341A 等）夹住引脚直接读取其 JEDEC ID 来确认精确型号与容量。





## chip 




- [[flash-nor-dat]] - [[XMC-dat]] - [[XM25QH128C-dat]] - [[hi3516-dat]] == 
128Mbit == 16MB 



`MT25QL256ABA1EW9`-0SIT TR - FLASH - NOR Memory IC 256Mbit SPI - Quad I/O 133 MHz 8-WPDFN (8x6) (MLP8)

Micron Serial NOR Flash Memory

3V, Multiple I/O, 4KB, 32KB, 64KB, Sector Erase MT25QL256ABA


`MT25QU02GCBB8E12`-0SIT TR == IC FLASH 2GBIT SPI 24TPBGA - [[SPI-dat]]

`MT40A512M16TB`-062E:R == SDRAM - DDR4 記憶體 IC 8Gbit 並行 1.6 GHz 19 ns 96-FBGA (7.5x13)



## Nor Flash 

## What is NOR Flash?
NOR flash is a type of non-volatile memory that allows random read access. It is commonly used for storing firmware and allows executing code directly from flash (XIP - Execute In Place).






## Comparison Table

| Feature               | Parallel NOR Flash                  | SPI NOR Flash (SPI Flash)      |
| --------------------- | ----------------------------------- | ------------------------------ |
| **Interface**         | Parallel (8/16-bit bus)             | Serial (SPI: MOSI, MISO, SCLK) |
| **Speed**             | High (fast random access)           | Lower (due to serial nature)   |
| **Pins Required**     | Many (20+ pins)                     | Few (4–6 pins)                 |
| **Physical Size**     | Larger                              | Smaller                        |
| **Cost**              | More expensive                      | Cheaper                        |
| **Power Consumption** | Higher                              | Lower                          |
| **Read Access**       | Random access (byte-wise)           | Page-based, sequential access  |
| **Write Access**      | Sector/page erase/write             | Sector/page erase/write        |
| **XIP Support**       | Yes (native)                        | Limited or requires mapping    |
| **Use Cases**         | Boot code, firmware (MCUs, routers) | Microcontrollers, IoT, sensors |
| **Typical Capacity**  | Up to 512 MB                        | Up to 2 GB                     |

---

## Summary

- **SPI Flash** is a type of **NOR Flash** that uses a **serial interface (SPI)**.
- SPI NOR Flash sacrifices speed and flexibility for **lower cost, lower pin count, and small size**.
- **Parallel NOR Flash** is better for **code execution** and high-speed access.

S29GL128P90TFIR10 - NOR Flash 128Mb 3V 90ns Parallel NOR Flash





## ref 

