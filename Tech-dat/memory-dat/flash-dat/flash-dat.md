
# flash


## Nand Flash 

- Raspberry Pi CM Module 4 - [[RMP-RPI-CM4-dat]]

## Nor Flash 

## What is NOR Flash?
NOR flash is a type of non-volatile memory that allows random read access. It is commonly used for storing firmware and allows executing code directly from flash (XIP - Execute In Place).

---

## Comparison Table

| Feature              | Parallel NOR Flash         | SPI NOR Flash (SPI Flash)       |
|----------------------|----------------------------|----------------------------------|
| **Interface**        | Parallel (8/16-bit bus)    | Serial (SPI: MOSI, MISO, SCLK)  |
| **Speed**            | High (fast random access)  | Lower (due to serial nature)    |
| **Pins Required**    | Many (20+ pins)            | Few (4–6 pins)                  |
| **Physical Size**    | Larger                     | Smaller                         |
| **Cost**             | More expensive             | Cheaper                         |
| **Power Consumption**| Higher                     | Lower                           |
| **Read Access**      | Random access (byte-wise)  | Page-based, sequential access   |
| **Write Access**     | Sector/page erase/write    | Sector/page erase/write         |
| **XIP Support**      | Yes (native)               | Limited or requires mapping     |
| **Use Cases**        | Boot code, firmware (MCUs, routers) | Microcontrollers, IoT, sensors |
| **Typical Capacity** | Up to 512 MB               | Up to 2 GB                      |

---

## Summary

- **SPI Flash** is a type of **NOR Flash** that uses a **serial interface (SPI)**.
- SPI NOR Flash sacrifices speed and flexibility for **lower cost, lower pin count, and small size**.
- **Parallel NOR Flash** is better for **code execution** and high-speed access.

