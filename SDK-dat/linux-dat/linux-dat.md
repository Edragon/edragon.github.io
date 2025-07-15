
# linux-dat

- [[ubuntu-dat]]

完整下载命令为：

    git clone https://gitee.com/LicheePiNano/Linux.git

    git clone --depth=1 -b master https://gitee.com/LicheePiNano/Linux.git

config == 使用./arch/arm/configs/f1c100s_nano_linux_defconfig 配置文件

compile

    make ARCH=arm f1c100s_nano_linux_defconfig

    make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- -j8

    make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- -j16 INSTALL_MOD_PATH=out modules

    make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- -j16 INSTALL_MOD_PATH=out modules_install

编译成功后，生成文件所在位置：

- 内核img文件：  ./arch/arm/boot/zImage
- 设备树dtb文件: ./arch/arm/boot/dts/suniv-f1c100s-licheepi-nano.dtb
- modules文件夹：./out/lib/modules

将zImage与dtb文件放入nano第一分区．

## ref 

- [[allwinner-dat]]