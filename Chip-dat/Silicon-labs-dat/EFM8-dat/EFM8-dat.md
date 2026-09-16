


# EFM8-dat

- [[EFM8-dat]] - [[MCU-dat]] - [[silicon-labs-dat]]



## tech 

- [[USB-SDK-dat]]

## info EFM8 UB1 0


- [[USB-SDK-dat]]

https://www.silabs.com/mcu/8-bit-microcontrollers/efm8-universal-bee/device.efm8ub10f16g-qfn20?tab=specs

EFM8UB10F16G-QFN20

EFM8 USB Capable Universal Bee 8-bit Microcontrollers (MCUs)

The USB capable EFM8UB10F16G-QFN20 8-bit MCUs are built on top of a low power platform this device operates at 48 MHz. In addition to USB support, the EFM8UB10F16G-QFN20 includes 16 kB Flash, 2 kB RAM, 13 Dig I/O Pins, 5 x 16-bit timers, 3 PCA Channels, and additional communication peripherals.

## info EFM8 BB2 1 

EFM8BB21F16G-QFN20

EFM8 Busy Bee 8-bit Microcontrollers (MCUs)

https://www.silabs.com/documents/public/data-sheets/efm8bb2-datasheet.pdf

## marking 

![](2026-09-15-02-28-32.png)


## footprint 

QFN20

![](2026-09-16-22-15-51.png)

BB21 F16G

![](2026-09-15-02-47-55.png)

## use 

- [[X12-dat]]

- [[ESC-dat]] - [[Dshot-dat]] input // drive output - [[mosfet-drive-dat]] // [[reset-dat]]



### pins

- [[FC-AIO-dat]] - [[X12-dat]] - [[ESC-SDK-dat]]

在 X12 AIO 采用的 EFM8BB21（QFN-20 封装） 上，刷入 Z-H-30 固件后：

*   引脚名称：P0.5
*   物理引脚编号：第 17 脚（Pin 17）
*   功能：在 BLHeli_S / Bluejay 源码中定义为 RTX_PIN EQU 5（Port 0, Bit 5），兼作 UART0_RX 与 DShot / PWM 信号输入端。
*   


## ref 