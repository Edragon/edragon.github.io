
# flash


## Nand Flash 

- Raspberry Pi CM Module 4 - [[RMP-RPI-CM4-dat]]

## Nor Flash 

## What is NOR Flash?
NOR flash is a type of non-volatile memory that allows random read access. It is commonly used for storing firmware and allows executing code directly from flash (XIP - Execute In Place).

---

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

## SCH 

- flash with bypass button 

![](2025-10-08-15-52-28.png)


## SPI NAND 

![](2025-08-07-12-50-03.png)


## SPI Nor VS. NAND Flash 

### ✅ Summary Table

| Feature           | SPI NOR       | SPI NAND            |
| ----------------- | ------------- | ------------------- |
| Capacity          | Low to medium | Medium to very high |
| Random read speed | ✅ Fast        | ❌ Slower            |
| Write/erase speed | ❌ Slower      | ✅ Faster            |
| Reliability       | ✅ High        | ❌ Needs ECC         |
| Bootable (XIP)    | ✅ Yes         | ❌ No                |
| Cost per bit      | ❌ Higher      | ✅ Lower             |

---

### TL;DR

- 🧠 **SPI NOR Flash** = small, reliable, fast reads → great for firmware.
- 📦 **SPI NAND Flash** = large, cheaper, needs ECC → great for data storage.


## 📦 Common Winbond SPI NOR Flash Models

Winbond's SPI NOR flash chips are usually labeled **W25Q** or **W25X** series.  
They vary by **capacity**, **voltage**, **speed**, and **features** like Dual/Quad SPI.

---

### 🧰 Common W25Q Series (Most Popular)

| Model         | Capacity | Voltage | Features                     |
|---------------|----------|---------|------------------------------|
| **W25Q16JV**  | 16 Mbit  | 2.7–3.6V| Standard SPI, Dual/Quad SPI  |
| **W25Q32JV**  | 32 Mbit  | 2.7–3.6V| Very popular, common in MCUs |
| **W25Q64JV**  | 64 Mbit  | 2.7–3.6V| Standard/Dual/Quad SPI       |
| **W25Q128JV** | 128 Mbit | 2.7–3.6V| XIP, dual/quad SPI support   |
| **W25Q256JV** | 256 Mbit | 2.7–3.6V| Larger firmware/data storage |



## un-sort 

TC58FVM7(T/B)2AFT(65/80) - 128-MBIT (16M × 8 BITS / 8M × 16 BITS) CMOS FLASH MEMORY

AM29LV116DT-90EI - 	IC FLASH 16MBIT PARALLEL 40TSOP

## ref 

- [[flash-dat]]