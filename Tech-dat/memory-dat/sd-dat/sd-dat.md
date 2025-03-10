
# sd-dat

## Comparison: SDIO vs. SPI Interface

Both **SDIO (Secure Digital Input Output)** and **SPI (Serial Peripheral Interface)** are used for communication with SD cards and other peripherals, but they have key differences in speed, complexity, and use cases.

### Feature Comparison

| Feature                  | **SDIO Interface**                                                          | **SPI Interface**                                                                       |
| ------------------------ | --------------------------------------------------------------------------- | --------------------------------------------------------------------------------------- |
| **Bus Type**             | Parallel (4-bit or 1-bit)                                                   | Serial (1-bit)                                                                          |
| **Speed**                | Faster (up to 100+ Mbps)                                                    | Slower (typically 1–25 Mbps)                                                            |
| **Data Lines**           | 4-bit mode: **CLK, CMD, DATA0-3** <br> 1-bit mode: **CLK, CMD, DATA0**      | **MOSI, MISO, SCK, CS** (1-bit communication)                                           |
| **Complexity**           | More complex (requires SD controller)                                       | Simpler (easier to implement in microcontrollers)                                       |
| **Performance**          | Higher data transfer rate                                                   | Lower data rate                                                                         |
| **Power Consumption**    | More efficient for high-speed transfers                                     | Can be less efficient due to longer transfers                                           |
| **Multi-Device Support** | Can support multiple devices efficiently                                    | Requires separate chip select (CS) lines for each device                                |
| **Use Cases**            | SD cards, Wi-Fi modules, Bluetooth modules, GPS, and high-speed peripherals | Simple microcontroller communication, low-speed SD card access, sensors, small displays |

### Summary

- **SDIO** is better for **high-speed data transfers** (e.g., Wi-Fi, SD cards in high-performance applications).  
- **SPI** is simpler, easier to implement, and works well for **low-speed, low-power applications** where high transfer rates are not required.  



## SPI inteface for ESP32-WROVER 

SP 4-wire - [[SPI-dat]]

    #define SD_CS IO13
    #define SD_MISO IO2
    #define SD_MOSI IO15
    #define SD_CLK IO14

- https://github.com/Edragon/Arduino-ESP32/tree/master/Sketchbook/driver-Data


This is how I connected my SD card:

https://github.com/espressif/arduino-esp32/tree/master/libraries/SD



## SDIO interface for ESP32 

SD (Secure Digital) card interface, specifically the SDIO (Secure Digital Input Output) or 4-bit SD mode.

Dat 0~4 used in [[SCM1030-dat]]

MicroSD Card Connections

The following pins are used to interface with the microSD card when it is on operation.

| MicroSD card | ESP32   |                       | extra      |
| ------------ | ------- | --------------------- | ---------- |
| CLK          | GPIO 14 |                       |            |
| CMD          | GPIO 15 | pull-up               |            |
| DATA0        | GPIO 2  | pull-up               |            |
| DATA1        | GPIO 4  | pull-up (not working) | flashlight |
| DATA2        | GPIO 12 | X                     |            |
| DATA3        | GPIO 13 | pull-up               |            |


![](2025-03-07-17-27-43.png)



## ref 

- [[memory-dat]] - [[interface-dat]]
