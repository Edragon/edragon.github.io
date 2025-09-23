
# SWD-dat

- [[st-link-dat]]

- https://static.docs.arm.com/ihi0031/d/debug_interface_v5_2_architecture_specification_IHI0031D.pdf
- https://www.arm.com/files/pdf/Serial_Wire_Debug.pdf


https://stm32-base.org/guides/connecting-your-debugger.html

![](2024-07-05-17-37-28.png)


## wiring 

![](2025-09-23-13-27-22.png)

供电方式一般有三种：

- 1，使用5V-supply引脚经过目标板的LDO给McU供电。
- 2，直接将VOUT引I脚连接到MCU的VCC进行供电
- 3，用户也可以选择目标板自带供电。
- 注意：无论那种供电方式，VTREF引I脚都必须连接到MCU的VCC。

## Debug


* If SWD Serial-Wire is not enable, add reset line to force enter into debug mode

- [[USB-TTL-dat]]

- [[stm32-dat]]