
# u-boot-dat

- [[arm-compiler-dat]]

    git clone -b nano-lcd800480 https://gitee.com/LicheePiNano/u-boot.git

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


## ref 

- [[allwinner-dat]]