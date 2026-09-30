

# Flash-NOR-dat


- [[Flash-SPI-dat]] - [[Flash-NAND-dat]] - [[Flash-NOR-dat]] - [[flash-dat]]

- [[micron-dat]] - [[SDram-dat]]



## chip 

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

