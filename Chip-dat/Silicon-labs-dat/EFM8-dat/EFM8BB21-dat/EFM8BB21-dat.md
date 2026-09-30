


# EFM8BB21-dat


- [[EFM8BB21-dat]] - [[EFM8-dat]] - [[MCU-dat]] - [[silicon-labs-dat]]


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
   



## ref 

