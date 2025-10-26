
# RP2040-dat


RP2040 Pico介绍：

RP2040 Pico是一款低成本，高性能的微控制器开发板，具有灵活数字接口。硬件上，采用RaspberryPi官方自主研发的RP2040微控制器芯片，搭载了ARM Cortex MO+双核处理器，高达133MHz的运行频率，内置了264KB的SRAM和2MB的内存，还板载有多达26个多功能的GPIO引脚。软件上，可选择树莓派提供的C/C++SDK，或者使用MMicroPython进行开发，且配套有完善的开发资料教程，可方便快速入门开发，并嵌入应用到产品中。


## board info for RP2040 board 

- Dual-core Arm Cortex-M0+ processor, up to 133 MHz
- 264 KB on-chip SRAM
- Support for up to 16 MB of external QSPI flash
- USB 1.1 controller and PHY, device and host support
- 30 multifunction GPIO pins
- 2 × UART, 2 × SPI, 2 × I2C, 16 × PWM channels
- 3 × 12-bit ADC channels
- Programmable I/O (PIO) for custom peripheral support
- On-chip clock and PLL
- Low-power sleep and dormant modes
- Temperature sensor
- 8 × ground pins, 4 × ADC pins
- Built-in ROM with USB bootloader
- 2 × watchdog timers, real-time counter
- 2 × timer peripherals
- 3.3V operation


逻辑分析仪采用的是基于树莓派RP2040的方案，支持八通道（原方案是24通道，本项目引出了八通道）最大100MHz采样率，外挂FLASH为W25Q16JVSSIQ，2MB容量。


## min. Core SCH 

![](2025-08-19-17-00-21.png)

## ref 

- [[raspberry-pi-dat]]