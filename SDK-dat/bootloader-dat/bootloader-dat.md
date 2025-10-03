
# bootloader-dat


- [[xboot-dat]] - [[xfel-dat]] - [[uboot-dat]] - [[sunxi-fel-dat]]

- [[buildroot-dat]]

- [[TINA-dat]] - [[allwinner-SDK-dat]]



On Allwinner/Sunxi boards, the bootloader (often U-Boot) loads:

- Kernel image (zImage, uImage, etc.)
- Device Tree Blob (*.dtb)
- Boot script (boot.scr or boot.cmd)
- Root filesystem (from SD card/eMMC partition)


## boot.scr 

```
'Vyf6抌zEH   ?       P沙?                                    ?   setenv bootargs console=ttyS0,115200 console=tty0 panic=5 console=tty0 rootwait root=/dev/mmcblk0p2 earlyprintk rw
load mmc 0:1 0x41000000 zImage
load mmc 0:1 0x41800000 sun8i-v3x-yuzukick1n-linux.dtb
bootz 0x41000000 - 0x41800000
```



## ref 

- [[F133-dat]]