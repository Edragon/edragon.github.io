
# ESP32-compare-dat.md

- [[ESP32-C3-dat]] - [[ESP32-S3-dat]] - [[ESP32-P4-dat]]

| Feature                   | **ESP32-C3**                 | **ESP32-S3**                            |
| ------------------------- | ---------------------------- | --------------------------------------- |
| **Processor**             | Single-core RISC-V (160 MHz) | Dual-core Xtensa LX7 (240 MHz)          |
| **Architecture**          | RISC-V                       | Xtensa                                  |
| **Performance**           | Moderate for basic IoT tasks | High-performance for AI/ML tasks        |
| **Wi-Fi**                 | 2.4 GHz (802.11b/g/n)        | 2.4 GHz (802.11b/g/n)                   |
| **Bluetooth**             | Bluetooth 5.0 (LE + Mesh)    | Bluetooth 5.0 (LE + Mesh)               |
| **SRAM**                  | 400 KB                       | 512 KB                                  |
| **Flash**                 | Up to 4 MB embedded          | External Flash support up to 16 MB      |
| **PSRAM Support**         | No                           | Yes                                     |
| **GPIO Pins**             | 22                           | 45                                      |
| **USB Support**           | No native USB support        | Native USB OTG                          |
| **Camera Interface**      | No                           | Yes                                     |
| **AI/ML Acceleration**    | Limited                      | Yes (vector instructions support)       |
| **LCD Interface**         | No                           | Yes (parallel RGB or SPI)               |
| **I2S (Audio Support)**   | Yes                          | Yes                                     |
| **Security**              | RSA, AES, SHA, HMAC          | RSA, AES, SHA, HMAC, Digital Signature  |
| **Temperature Range**     | -40°C to 85°C                | -40°C to 125°C                          |
| **Power Efficiency**      | Better for low-power needs   | Higher power consumption when active    |
| **Deep Sleep Power**      | ~5 µA                        | ~10 µA                                  |
| **Wake-Up Sources**       | Timer, GPIO, ULP             | Timer, GPIO, ULP, USB                   |
| **Peripheral Interfaces** | SPI, I2C, I2S, UART, ADC     | SPI, I2C, I2S, UART, ADC, CAN, Parallel |
| **Clock Frequency**       | 160 MHz                      | 240 MHz                                 |
| **Package Options**       | QFN28, QFN32                 | QFN48, QFN68                            |
| **Applications**          | Basic IoT, BLE tasks         | AI/ML, image processing, advanced IoT   |
| **Price**                 | Lower                        | Higher due to advanced features         |

## VS [[ESP32-Wrover-dat]]

| Feature                   | **ESP32-C3**                 | **ESP32-S3**                            | **ESP32-WROVER**                     |
| ------------------------- | ---------------------------- | --------------------------------------- | ------------------------------------ |
| **Processor**             | Single-core RISC-V (160 MHz) | Dual-core Xtensa LX7 (240 MHz)          | Dual-core Xtensa LX6 (240 MHz)       |
| **Architecture**          | RISC-V                       | Xtensa                                  | Xtensa                               |
| **Performance**           | Moderate for basic IoT tasks | High-performance for AI/ML tasks        | High-performance for general IoT     |
| **Wi-Fi**                 | 2.4 GHz (802.11b/g/n)        | 2.4 GHz (802.11b/g/n)                   | 2.4 GHz (802.11b/g/n)                |
| **Bluetooth**             | Bluetooth 5.0 (LE + Mesh)    | Bluetooth 5.0 (LE + Mesh)               | Bluetooth 4.2 (LE + Mesh)            |
| **SRAM**                  | 400 KB                       | 512 KB                                  | 520 KB                               |
| **Flash**                 | Up to 4 MB embedded          | External Flash support up to 16 MB      | Up to 16 MB                          |
| **PSRAM Support**         | No                           | Yes                                     | Yes (4 MB external PSRAM)            |
| **GPIO Pins**             | 22                           | 45                                      | 34                                   |
| **USB Support**           | No native USB support        | Native USB OTG                          | No                                   |
| **Camera Interface**      | No                           | Yes                                     | Yes (with external modules)          |
| **AI/ML Acceleration**    | Limited                      | Yes (vector instructions support)       | No                                   |
| **LCD Interface**         | No                           | Yes (parallel RGB or SPI)               | Yes (SPI-based LCD support)          |
| **I2S (Audio Support)**   | Yes                          | Yes                                     | Yes                                  |
| **Security**              | RSA, AES, SHA, HMAC          | RSA, AES, SHA, HMAC, Digital Signature  | RSA, AES, SHA, HMAC                  |
| **Temperature Range**     | -40°C to 85°C                | -40°C to 125°C                          | -40°C to 85°C                        |
| **Power Efficiency**      | Better for low-power needs   | Higher power consumption when active    | Moderate                             |
| **Deep Sleep Power**      | ~5 µA                        | ~10 µA                                  | ~6 µA                                |
| **Wake-Up Sources**       | Timer, GPIO, ULP             | Timer, GPIO, ULP, USB                   | Timer, GPIO, ULP                     |
| **Peripheral Interfaces** | SPI, I2C, I2S, UART, ADC     | SPI, I2C, I2S, UART, ADC, CAN, Parallel | SPI, I2C, I2S, UART, ADC             |
| **Clock Frequency**       | 160 MHz                      | 240 MHz                                 | 240 MHz                              |
| **Package Options**       | QFN28, QFN32                 | QFN48, QFN68                            | Module with built-in PSRAM           |
| **Applications**          | Basic IoT, BLE tasks         | AI/ML, image processing, advanced IoT   | General IoT, multimedia applications |
| **Price**                 | Lower                        | Higher due to advanced features         | Moderate                             |


## VS [[ESP32-P4-dat]]

| Feature                   | **ESP32-C3**                 | **ESP32-S3**                            | **ESP32-WROVER**                     | **ESP32-P4**                                   |
| ------------------------- | ---------------------------- | --------------------------------------- | ------------------------------------ | ---------------------------------------------- |
| **Processor**             | Single-core RISC-V (160 MHz) | Dual-core Xtensa LX7 (240 MHz)          | Dual-core Xtensa LX6 (240 MHz)       | Dual-core RISC-V (up to 400 MHz)               |
| **Architecture**          | RISC-V                       | Xtensa                                  | Xtensa                               | RISC-V                                         |
| **Performance**           | Moderate for basic IoT tasks | High-performance for AI/ML tasks        | High-performance for general IoT     | High-performance for HMI and AIoT applications |
| **Wi-Fi**                 | 2.4 GHz (802.11b/g/n)        | 2.4 GHz (802.11b/g/n)                   | 2.4 GHz (802.11b/g/n)                | Not integrated                                 |
| **Bluetooth**             | Bluetooth 5.0 (LE + Mesh)    | Bluetooth 5.0 (LE + Mesh)               | Bluetooth 4.2 (LE + Mesh)            | Not integrated                                 |
| **SRAM**                  | 400 KB                       | 512 KB                                  | 520 KB                               | 768 KB HP L2MEM, 32 KB LP SRAM                 |
| **Flash**                 | Up to 4 MB embedded          | External Flash support up to 16 MB      | Up to 16 MB                          | External Flash support                         |
| **PSRAM Support**         | No                           | Yes                                     | Yes (4 MB external PSRAM)            | Yes (up to 32 MB)                              |
| **GPIO Pins**             | 22                           | 45                                      | 34                                   | 55                                             |
| **USB Support**           | No native USB support        | Native USB OTG                          | No                                   | USB 2.0                                        |
| **Camera Interface**      | No                           | Yes                                     | Yes (with external modules)          | MIPI-CSI                                       |
| **AI/ML Acceleration**    | Limited                      | Yes (vector instructions support)       | No                                   | AI instruction extensions                      |
| **LCD Interface**         | No                           | Yes (parallel RGB or SPI)               | Yes (SPI-based LCD support)          | MIPI-DSI                                       |
| **I2S (Audio Support)**   | Yes                          | Yes                                     | Yes                                  | Yes                                            |
| **Security**              | RSA, AES, SHA, HMAC          | RSA, AES, SHA, HMAC, Digital Signature  | RSA, AES, SHA, HMAC                  | Advanced security features                     |
| **Temperature Range**     | -40°C to 85°C                | -40°C to 125°C                          | -40°C to 85°C                        | -40°C to 85°C                                  |
| **Power Efficiency**      | Better for low-power needs   | Higher power consumption when active    | Moderate                             | Ultra-low-power modes available                |
| **Deep Sleep Power**      | ~5 µA                        | ~10 µA                                  | ~6 µA                                | Data not specified                             |
| **Wake-Up Sources**       | Timer, GPIO, ULP             | Timer, GPIO, ULP, USB                   | Timer, GPIO, ULP                     | Timer, GPIO, LP-Core                           |
| **Peripheral Interfaces** | SPI, I2C, I2S, UART, ADC     | SPI, I2C, I2S, UART, ADC, CAN, Parallel | SPI, I2C, I2S, UART, ADC             | SPI, I2C, I2S, UART, ADC, MIPI                 |
| **Clock Frequency**       | 160 MHz                      | 240 MHz                                 | 240 MHz                              | 400 MHz                                        |
| **Package Options**       | QFN28, QFN32                 | QFN48, QFN68                            | Module with built-in PSRAM           | Data not specified                             |
| **Applications**          | Basic IoT, BLE tasks         | AI/ML, image processing, advanced IoT   | General IoT, multimedia applications | HMI, AIoT, edge computing                      |
| **Price**                 | Lower                        | Higher due to advanced features         | Moderate                             | Data not specified                             |


### New Features of ESP32-P4:

- High-Performance Dual-Core RISC-V CPU: Operates up to 400 MHz, suitable for compute-intensive tasks. 
- AI Instruction Extensions: Enhances AI and machine learning capabilities. 
- Advanced Memory Subsystem: Includes 768 KB of HP L2MEM and 32 KB of LP SRAM, supporting large internal memory. 
- Integrated High-Speed Peripherals: Supports USB 2.0, MIPI-CSI for camera input, and MIPI-DSI for display output, facilitating rich Human-Machine Interfaces. 
- Low-Power Core (LP-Core): Operates up to 40 MHz, enabling ultra-low-power applications by allowing high-performance cores to remain dormant when not needed. 
- Enhanced Security Features: Provides robust security mechanisms suitable for applications requiring strong protection. 
- Extensive IO Connectivity: Offers 55 GPIOs, accommodating increased IO-connectivity demands. 