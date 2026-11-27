
# CH340 DAT



## CH340 
- install driver with common CH340 driver 
- USB device should be found as: USB-SERIAL CH340K (COM161)


## DS 

| model  | link            | footprint | note                     |
| ------ | --------------- | --------- | ------------------------ |
| CH340G | [[CIC1030-dat]] | SOP-16    |                          |
| CH340C | [[CIC1031-dat]] | SOP-16    | no need external crystal |
| CH340B |                 | SOP-16    |                          |
| CH340K |                 | ESSOP-10  |                          |
| CH340E | [[CIC1029-dat]] | MSOP-10   |                          |
| CH340N |                 |           |                          |
| CH340T | 
| CH340X |

## Hardware 

V3 pin 
- 在3.3V 电源电压时连接VCC 输入外部电源， 
- 在5V 电源电压时外接容量为0.1uF 退耦电容




## datasheet and driver

- [[CH340N-dat]]

- [[WCH-Jiangsu-Qin-Heng-CH340.pdf]]

## SCH 

此电路用于用户连接系统调试中断使用，其功能为将TTL串口转换为USB接口，使得用户可以在电脑中连接该串口进行调试。

需要注意的是，由于F1C200S的UART0接口(PE0/PE1引脚)被触摸的I2C接口占用，所以本开发板将CH340的串口连接到了F1C200S的UART1(PA2/PA3引脚)上，后续编译U-Boot和内核时我们需要相应的修改代码。

![](2025-08-19-14-14-42.webp)

![](2025-08-19-14-14-53.webp)

如上图所示，该部分除了串口转USB外，还兼顾的系统的供电，用户通过Type-C线缆连接该调试口后，将同时为开发板供电。板上的5.1K电阻用于双头Type-C线缆识别从机，为其提供供电，如果R12,R13不焊接会导致使用双头Type-C线时板子没有供电。D2为TVS瞬态抑制二极管用于保护PCB板上原件，防止静电击穿原件。



## driver 

- [[CH340SER.zip]]


![](2026-05-27-13-29-08.webp)

for win 7 only to uninstall 

![](2026-05-27-13-30-02.webp)

for win 7 may need patch please note:

- [[WIN7-64bit-patch.zip]] - [[WIN7-32bit-patch.zip]]

**1. Windows 7 (32-bit System)**
Before installing the driver:
- Copy the `serenum.sys` file from the "WIN7-32-bit Driver Patch" folder to `C:\WINDOWS\system32\drivers`.
- *Note: For Windows XP and Vista, you can install the driver directly without this patch.*

**2. Windows 7 (64-bit System)**
- Copy the entire "WIN7-64-bit Driver" folder to the C: drive (e.g., `C:\WIN7-64-bit-Driver`).
- Connect the USB-to-Serial cable to the computer (do not connect the other end to the board yet).
- Open **Device Manager**, find the cable (often appears as an unknown device or under "Other devices" with a question mark), right-click and select **Update Driver**.
- Choose "Browse my computer for driver software" and point to the `DRIVER` subdirectory in your copied folder (e.g., `C:\WIN7-64-bit-Driver\DRIVER`) to complete the manual installation.

*Note: If Windows detects the new hardware automatically, simply point the wizard to the `DRIVER` directory.*

## info 

![](2026-11-26-02-14-10.webp)


上图是基于USB转串口的多模式MCU一键下载参考电路，无需手工设置或手动复位。

上图针对的MCU类型：MCU本身需支持串口一键下载，NRST为低电平有效的复位输入端，BOOTO
默认低电平选择应用程序，高电平选择Boot-Loader下载。例如32F103等。

图中为CH340X，4.7KQ下拉电阻可选范围3～5.6KΩ，该电阻兼做MCU的B00T0下拉电阻。对于
批号4开头且末3位大于B40的CH340C，可以用0UT#外加下拉电阻后作为第二DTR#接B00T0。
注：对于B00T模式电平相反的其它MCU，可以直接用CH340C/G的DTR#控制（默认高电平），或
者用6#与5#引I脚之间接了电阻的CH340X的DTR#控制（推挽DTR增强模式，默认高电平）。

MCU正常工作状态：下拉电阻使得CH340X进入开源DTR增强模式，6#引I脚切换为DTR#，DTR#默
认不输出，BOOTO保持低电平，RTS#默认高电平，MCU正常运行应用程序。

一键下载：计算机端下载工具程序打开串口，设置DTR#为高电平、设置RTS#为低电平、再高电
平，MCU进入BOOT下载程序。下载完成后，设置DTR#为低电平、设置RTS#为低电平、再高电平，MCU
正常运行应用程序，关闭串口前保持DTR#不变。注意，MODEM数据与引引脚电平是反相的。

统一供电方式：CH340X用MCU的同一5V或3.3V电源，缺点是CH340X将消耗数十uA的睡眠电
流。
独立供电方式：CH34OX使用USB的VBUS电源，完全不消耗MCU电源电流，CH34OX自身断电后基
本不影响MCU的IO，但要避免部分MCU因USB有电但MCU无电而向MCU倒灌电的情况。如果需要完
全防止CH340电源对失电MCU的电流外灌，那么参考7.7节的图加NMOS和二极管。

如果NRST引I脚需要支持额外的手动复位，那么可以在RTS#与NRST之间串一个1～2KQ电阻或者
阳极接NRST的二极管。



## board and code 

![](2026-06-04-17-00-24.webp)

- [[ARM1007-dat]]




## ref 

- legacy wiki page https://w.electrodragon.com/w/Category:CH340

