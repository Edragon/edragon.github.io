



# MT2523-dat


- [[MT2523SA-dat]] - [[MT2523-dat]] - [[mediatek-dat]] - [[NRF52810-dat]] - [[bluetooth-dat]] - [[ARM-dat]] - [[MIPI-dat]] - [[CSI-dat]]


The MediaTek MT2523SA (often cataloged as MT2523SA/A) is an ultra-low-power System-in-Package (SiP) microcontroller designed primarily for smartwatches, fitness trackers, and wearable IoT devices.
Part of the MediaTek MT2523 series, the "S" variant specifically omits the integrated GNSS/GPS module found in the MT2523G, focusing instead on compact Bluetooth and display-driven applications.

Core specifications


| Feature          | Specification                                                                 |
| ---------------- | ----------------------------------------------------------------------------- |
| Processor        | Single-core ARM Cortex-M4 with FPU (up to 208 MHz)                            |
| Wireless         | Dual-mode Bluetooth 4.2 (Classic BR/EDR and BLE)                              |
| Memory           | 160 KB SRAM, 32 KB L1 cache, and embedded flash/PSRAM                         |
| Display Support  | MIPI-DSI and serial interfaces with 2D graphics acceleration                  |
| Power Management | Integrated PMU with Li-ion battery charger, LDOs, and LED/backlight drivers   |
| Security         | Hardware AES (128/192/256-bit) crypto engine and True Random Number Generator |
| Operating        | Temp	-40°C to +85°C                                                           |


Key capabilities

• Ultra-low power architecture. Features dynamic voltage and frequency scaling (DVFS) from 0.7V (deep sleep at ~100nA) up to 1.3V (active at 208 MHz), with a 7µs wakeup time to maximize wearable battery life.
• Integrated sensor hub. Includes dedicated sensor DMA and standard interfaces (I2C, SPI, UART, I2S, PCM, PWM, USB 2.0, SDIO, and 12-bit AUXADC) for low-power continuous biometric and motion tracking.
• Audio processing. Supports dual PDM digital microphones alongside hardware AAC/SBC audio decoding and CVSD/mSBC speech coding.
• Development ecosystem. Supported by the MediaTek LinkIt Development Platform for RTOS, with full technical pinouts and electrical ratings detailed in the MediaTek MT2523 Series Datasheet.




## ref 