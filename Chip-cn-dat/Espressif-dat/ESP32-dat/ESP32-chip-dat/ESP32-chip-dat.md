
# ESP32-chip-dat

- [[ESP32-compare-dat]] - [[ESP32-old-dat]] - [[ESP32-chip-error-dat]]

| Feature             | [[ESP32-S3-dat]]                                | [[ESP32-C3-dat]]                                |
| ------------------- | ----------------------------------------------- | ----------------------------------------------- |
| **CPU**             | Dual-core Xtensa LX7, up to 240MHz              | Single-core RISC-V, up to 160MHz                |
| **AI Acceleration** | Yes (vector instructions for AI)                | No                                              |
| **RAM**             | Up to 512KB SRAM                                | 400KB SRAM                                      |
| **Flash**           | External (SPI/Quad SPI/Octal SPI)               | External (SPI/Quad SPI)                         |
| **Wireless**        | Wi-Fi 4 (802.11 b/g/n), Bluetooth 5 (LE)        | Wi-Fi 4 (802.11 b/g/n), Bluetooth 5 (LE)        |
| **GPIO**            | Up to 44                                        | Up to 22                                        |
| **USB**             | USB OTG (Full Speed)                            | USB Serial/JTAG                                 |
| **Security**        | Secure Boot, Flash Encryption, H/W Cryptography | Secure Boot, Flash Encryption, H/W Cryptography |
| **Ultra Low Power** | Yes                                             | Yes                                             |


Most ESP32 chips are dual-core. Here’s a summary:

| Chip Series | Cores  | Core Type            | Pin Count |
| ----------- | ------ | -------------------- | --------- |
| ESP32       | Dual   | Tensilica Xtensa LX6 |           |
| ESP32-S2    | Single | Tensilica Xtensa LX7 |           |
| ESP32-S3    | Dual   | Tensilica Xtensa LX7 | 57        |
| ESP32-C3    | Single | RISC-V               |           |
| ESP32-C6    | Single | RISC-V               |           |
| ESP32-C5    | Single | RISC-V               |           |
| ESP32-H2    | Single | RISC-V               |           |
| ESP32-P4    | Dual   | RISC-V               |           |

**Dual-core ESP32 chips:**  
- ESP32 (original)
- ESP32-S3
- ESP32-P4

**Single-core ESP32 chips:**  
- ESP32-S2
- ESP32-C3
- ESP32-C6
- ESP32-C5
- ESP32-H2
