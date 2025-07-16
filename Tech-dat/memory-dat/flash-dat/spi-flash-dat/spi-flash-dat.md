

# spi-flash-dat


## WSON 

![](2025-07-14-01-14-33.png)


## SPI Flash SCH

w/STM32
![](2024-01-13-17-38-48.png)

w/arduino
![](2025-01-16-19-51-20.png)

basic 
![](2024-12-26-15-22-43.png)

### w/linux 

![](2025-07-16-12-33-43.png)

bypass flash 

若flash中已有系统，可通过：

- 短接flash的 1、4 两脚，然后重新上电，上电后松开短接，即可重新进入fel模式，进行再次下载
- 在启动到内核前，回车进入 [[uboot-dat]]，执行 sf probe 0;sf erase 0 0x100000;reset即可重新进入fel模式


## ref 

- [[memory]]