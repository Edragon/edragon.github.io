
# Xboot-dat

xboot秉持一次编写到处运行的理念，集成各类驱动支持，支持lua虚拟机，是一款优秀的bootloader；xboot无需额外配置直接上手！

请到 xboot 下载README中给出的官方交叉编译器；请下载5.3.1版本，其5.3.0版本貌似不支持软浮点配置命令。

    git clone https://github.com/xboot/xboot.git
    cd xboot
    make CROSS_COMPILE=/path/to/arm-eabi- PLATFORM=arm32-f1c100s  #请自行修改到本机地址

烧写到RAM中并运行

    sunxi-fel spl xboot.bin
    sunxi-fel -p write 0x80000000 xboot.bin
    sunxi-fel exec 0x80000000;

或烧写到SPI Flash

    sunxi-fel -p spiflash-write 0 xboot.bin

进入命令行后输入地址 /application/examples 将启动lua虚拟机运行Demo，可以算是xboot的酷炫小惊喜~