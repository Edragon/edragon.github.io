
# F1C100-SDK-dat

- [[F1C100-DTS-dat]] - [[F1C100-image-dat]]

- [[F1C100-SDK-dat]] - [[F1C100-HDK-dat]]

## SDK 

system 

- [[code-dat/linux-dat/linux-dat]]、[[RT-Thread-dat]] (CN)、[[Xboot-dat]] (CN)

use 

- [[sunxi-tools-dat]] - [[docker-dat]]

build 

- [[uboot-dat]] 

- [[ubuntu-dat]]

- [[buildroot-dat]]

- [[lvgl-dat]] - [[openwrt-dat]] - [[WIFI-DAT]]


## Note 

- esp8089以modprobe方式挂载，直接通过串口替换原来固件
- 第二个固件esp8089需要手动modprobe一下

- [[ESP8089-dat]]

- Nano 需要插卡启动（或者焊接spi flash），只插上 USB基本是无反应，屏幕无输出状态，但可在不插卡无 flash 状态下通过 USB 启动 U-boot
- Nano 的系统调试串口是 UART0 ，即板子丝印上的的 “U0：Tx Rx” 标识的两个引脚




## Image Flashing 

### uboot spl 

以 uboot file-with-spl形式进行（单次运行，测试时个人推荐）

    sunxi-fel uboot /your/path/to/u-boot-sunxi-with-spl.bin
    sunxi-fel uboot Nano_flash_800600.bin
    sunxi-fel uboot Nano_flash_800480.bin
    sunxi-fel uboot Nano_flash_480272.bin

### TF card == linux 

镜像包中的image文件夹下的dd文件，已包含了相应的Bootloader、Kernel、文件系统等等，只需简单两步即可完成烧录；

插上tf卡后，命令行执行 sudo fdisk -l 查看tf卡盘号；

执行 即可完成烧录 

    sudo dd if=/path/to/your-dd-image of=/your/tf-card && sync 



### TF card == WIN 

使用软件 win32disk 进行一键烧录，可到 [此处](http://www.onlinedown.net/soft/110173.html) 下载;


### Flash Empty 

- [[sunxi-tools-dat]]

在flash内容为空的情况下（fel模式下的一种情况）进行烧录时，通过micro-usb数据线将Nano与电脑连接，执行

    sudo sunxi-fel -p spiflash-write 0 Your-Flash-BIN

    cd /media/sf_share-folder/Nano_pub_V4/image


### Flash NOT Empty 

- [[spi-flash-dat]]




## how to make image flashimg.bin

- [[nano_flash_dd.sh]]

including 
- [[uboot-dat]] file
- [[code-dat/linux-dat/linux-dat]] DTB file
- [[code-dat/linux-dat/linux-dat]] kernel file
- [[code-dat/linux-dat/linux-dat]] modules file
- [[buildroot-dat]] rootfs file


code to get flashimg.bin

    #!/bin/sh
    UBOOT_FILE=./u-boot/u-boot-sunxi-with-spl.bin
    DTB_FILE=./Linux/arch/arm/boot/dts/suniv-f1c100s-licheepi-nano.dtb
    KERNEL_FILE=./Linux/arch/arm/boot/zImage
    ROOTFS_FILE=./buildroot-2021.02.4/output/images/rootfs.tar
    MOD_FILE=./Linux/out/lib/modules/4.15.0-rc8-licheepi-nano+

    dd if=/dev/zero of=flashimg.bin bs=1M count=16 &&\
    dd if=$UBOOT_FILE of=flashimg.bin bs=1K conv=notrunc &&\
    dd if=$DTB_FILE of=flashimg.bin bs=1K seek=1024 conv=notrunc &&\
    dd if=$KERNEL_FILE of=flashimg.bin bs=1K seek=1088 conv=notrunc &&\
    mkdir rootfs
    tar -xvf $ROOTFS_FILE -C ./rootfs &&\
    cp -r $MOD_FILE rootfs/lib/modules/ &&\

    #为根文件系统制作jffs2镜像包
    #--pad参数指定 jffs2大小
    #由此计算得到 0x1000000(16M)-0x10000(64K)-0x100000(1M)-0x400000(4M)=0xAF0000
    mkfs.jffs2 -s 0x100 -e 0x10000 --pad=0xAF0000 -d rootfs/ -o jffs2.img &&\
    dd if=jffs2.img of=flashimg.bin bs=1K seek=5184 conv=notrunc &&\
    rm -rf rootfs &&\
    rm jffs2.img

folder rootfs for [[buildroot-dat]]


## ref 

- https://pan.baidu.com/s/1smzuGS9#list/path=%2F

- [[F1C100-dat]]

- https://github.com/Zepan/ilichee/tree/master/资源文件/镜像烧写

- https://github.com/Zepan/ilichee

- https://mega.nz/folder/A8g1Hb4J#WcuoqvbpasKlVB8-YEpWPA

- [[sipeed-dat]]

- Nano_pub_V4.zip