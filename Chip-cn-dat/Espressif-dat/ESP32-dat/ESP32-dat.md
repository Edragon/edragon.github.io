

# ESP32 

## software 

- [[ESP-SDK-dat]] - [[ESP32-SDK-dat]] - [[ESP8266-SDK-dat]] - [[arduino-ESP32-dat]]

- [[ESP32-FAQ]]

- [[ESP32-boot-log-dat]]

- [[OTA-dat]]

## Hardware 

- [[ESP32-HDK-dat]] 


### modules

- [[ESP32-WROOM-dat]] - [[ESP32-WROVER-dat]]

## chips 

- [[ESP32-chip-error-dat]]

- [[ESP32-S3-dat]] - [[ESP32-S2-dat]] 

- [[ESP32-C3-dat]] - [[ESP32-C2-dat]] 

- [[ESP32-C6-dat]]

- [[ESP32-P4-dat]]

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




### Boards and APP 

- [[IDD1023-dat]] - [[SCM1030-dat]]

DEV Baords 
- [[NWI1100-dat]] - [[NWI1145-dat]] - [[NWI1206-dat]] 

- [[ESP32-S3-dat]] == [[NWI1243-dat]]

- [[SCM1030-dat]]

### Shields (stack boards) 
- [[NWI1245-dat]]

### In Development
- [[ESP32-ISO-dat]]


## Models selector 选型工具 
- https://products.espressif.com/#/product-selector?language=zh&names=
- https://products.espressif.com/#/product-selector?language=en


## Chip Info 

### datasheet

- chip datasheet
- https://www.espressif.com.cn/sites/default/files/documentation/esp32_datasheet_en.pdf

- esp32 technical_reference_manual CN
- https://www.espressif.com/sites/default/files/documentation/esp32_technical_reference_manual_cn.pdf

- ESP32 Chip Revision v3.0 - User Guid
- https://www.espressif.com/sites/default/files/documentation/esp32_chip_revision_v3_0_user_guide_en.pdf






## coding 

- [[micropython-dat]] - [[arduino-ide-dat]] - [[c-dat]]

## ref 

- [[ESP32-FAQ]]

- [[ESP32]]