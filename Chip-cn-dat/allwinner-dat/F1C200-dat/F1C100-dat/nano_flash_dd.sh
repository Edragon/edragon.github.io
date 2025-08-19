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