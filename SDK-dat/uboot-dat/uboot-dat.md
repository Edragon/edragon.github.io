
# u-boot-dat

## prequiresite 

- [[arm-compiler-dat]]


## clone 

    git clone -b nano-lcd800480 https://gitee.com/LicheePiNano/u-boot.git

U-Boot源码托管在github平台上，我们可以直接使用git命令将其取回。

U-Boot源码地址：https://github.com/u-boot/u-boot/tree/master

作者适配好的U-Boot源码地址：https://gitee.com/fhcloud/f1-c200-s-uboot

作者适配的U-Boot目前使用了master分支的U-Boot。由于后续master分支代码可能会存在更新，所以本指南将使用最近的一个U-Boot版本（v2023.10），指导用户进行修改和配置，编译出自己的U-Boot。

    git clone https://github.com/u-boot/u-boot.git -b v2023.10 --depth=1


图4.x U-Boot克隆过程

其中：

-b v2023.10 指定Tags为v2023.10

--depth=1下载深度为1，可以不下载之前的git commit，可以可以加快下载速度。

输入cd u-boot，进入源码目录，这里提示我们目前是头分离模式，我们直接按照要求创建新分支，在新分支下开发即可：

he@DESKTOP-EP0P00N:~$ cd u-boot

u-boot/ u-boot-master/

he@DESKTOP-EP0P00N:~$ cd u-boot

he@DESKTOP-EP0P00N:~/u-boot$ git checkout -b dev

Switched to a new branch 'dev'

如果不使用Git管理代码，则不需要上面操作，直接忽略提示即可。


## compile 

了解u-boot大致结构后，我们就可以开始尝试编译了；

    # 此处告知make采用arm-linux-gnueabi下的所有交叉编译工具，目标架构为Arm，设定各项默认配置为 nano 的spiflash支持版
    
    make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- f1c100s_nano_uboot_defconfig

    # 若不带spi-flash的板子，请换成 licheepi_nano_defconfig

    # 进行可视化配置
    
    make ARCH=arm menuconfig

## LCD include 

若要在套餐中附带的LCD上输出显示，请通过配置 

    ARM architecture --> Enable graphical uboot console on HDMI, LCD or VGA 为 Y

接着配置同级的 LCD panel timing details 为：

    x:800,y:480,depth:18,pclk\khz:33000,le:87,ri:40,up:31,lo:13,hs:1,vs:1,sync:3,vmode:0

注：此块屏为为 800*480 规格，如为 480*272 请尝试如下配置:

    x:480,y:272,depth:18,pclk\khz:10000,le:42,ri:8,up:11,lo:4,hs:1,vs:1,sync:3,vmode:0

并将 LCD panel backlight pwm pin 设为：

    PE6 （查自 Nano 原理图）

## 开始编译

    make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- -j8

编译完成后，可一看到目录下多了一堆以u-boot带头的文件，我们只需取

    u-boot-sunxi-with-spl.bin 即可；



## info 


U-Boot Overview

U-Boot (Universal Boot Loader) is an open-source bootloader widely used in embedded device startup processes. As a powerful and versatile boot tool, it supports multiple processor architectures and embedded platforms.

During system startup, U-Boot is responsible for initializing various hardware components, including but not limited to the CPU, memory controller, interrupt controller, and timer. It also loads the operating system kernel and root filesystem. U-Boot provides an interactive command-line interface for configuration, debugging, and maintenance.

Typically, U-Boot serves as the first-stage bootloader, with its main task being to load and execute the operating system from different storage media (such as flash, SD card, or network). This makes U-Boot a key role in the embedded device boot process.

Features and Functions of U-Boot:

- Cross-platform compatibility: Supports a wide range of processor architectures, including ARM, x86, PowerPC, and MIPS, and can run on various embedded platforms. It adapts flexibly to different hardware configurations and system requirements.
- Highly customizable: Offers rich configuration options and extensibility, allowing developers to tailor and optimize U-Boot for specific embedded system needs.
- Multiple boot methods: Supports serial boot, network boot (via TFTP or NFS), SD card boot, and flash boot.
- Interactive command-line interface: Users can perform device initialization, memory tests, filesystem operations, network configuration, and more.
- Diverse filesystem support: Supports FAT, EXT2/3/4, UBIFS, and other filesystems, enabling loading and booting of different root filesystems.
- Powerful debugging and diagnostic tools: Provides features for system debugging and troubleshooting, such as memory tests, device registration info display, and log recording.

F1C200S Chip Boot Process:

1. When power is applied, the internal BROM (non-erasable chip ROM) of the F1C100S starts.
2. It first checks if an SD card is inserted in slot 0. If present, it reads data at an 8K offset to determine if it is valid boot data. If valid, BROM boot ends; otherwise, it proceeds to the next step.
3. It checks for the presence of SPI0 NOR FLASH (e.g., W25QXXX or MX25LXXX) and verifies if valid boot data exists. If found, BROM boot ends; otherwise, it continues.
4. It then checks for SPI0 NAND FLASH and validates if it contains valid boot data. If found, BROM boot ends; otherwise, it moves to the next step.
5. If no bootable media is found in the above steps, the system switches to USB FEL mode, allowing USB programming.
6. After BROM boot ends, the SPL (Second Program Loader) is loaded. SPL loads U-Boot into RAM, and U-Boot is then fully loaded.

U-Boot Startup Sequence:

- Upon starting, U-Boot loads the device tree configured at compile time, loads the corresponding drivers, locates the stored kernel or configuration files, and then starts the kernel according to user-defined boot commands and Linux kernel parameters.
- After the kernel starts, U-Boot's role is complete.
- Note: U-Boot also requires a device tree, mainly to help load memory and basic peripherals. This device tree does not need to be complex—usually, only memory and UART nodes are required.



## ref 

- [[allwinner-dat]]