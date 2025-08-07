

# allwinner-D1-dat.md

- [[F133-dat]] == [[D1-S-dat]] 

- [[D1-H-dat]] - [[C906-dat]]

- [[D1-H-dat]] == C906 





## 操作步骤

1. 将所有文件拷贝到 Ubuntu系统的 ~ 目录下

2. 执行如下解压缩命令，等待解压缩 完成

>   cat tina-d1-h.tar.bz2.* | tar -jxv
> 
1. 解压缩完成后 继续参考 http://riscv64.dongshanpi.com/ 页面 Tina-SDK-V2.0相关资料

## 所有文件MD5校验值

> Ubuntu下输入 md5sum tina-d1-h.tar.bz2.* 查看

e755bae00cd76afc3fb276b4e3fd86ba  tina-d1-h.tar.bz2.00
cb60ecfdb51c624ff3cbd7b24552866f  tina-d1-h.tar.bz2.01
54e56a4cf1cef46ca0a94b85ea1d33a1  tina-d1-h.tar.bz2.02
4988fa08827c0f7af2dc170145e24b26  tina-d1-h.tar.bz2.03
a0463bcf8e73db27b5ecafaac593a919  tina-d1-h.tar.bz2.04
a87382ca16a8c12b3a94f1cad99ce77e  tina-d1-h.tar.bz2.05
5973530baa3b282108351818641c27fd  tina-d1-h.tar.bz2.06
ccd63e1d16534b364a101d2d44416261  tina-d1-h.tar.bz2.07
e0d72713565f4424ea43c07e15a38139  tina-d1-h.tar.bz2.08


## system image and SDK 

- contact and find in our google drive 

## flash 

全志官方工具
- 全志系统TF卡烧写工具：PhoenixCardv4.2.7.7z.7z
- 全志系统OTG烧写工具：AllwinnertechPhoeniSuitRelease20201225.zip.zip
社区版本烧写工具
- TF卡完整烧写工具： win32diskimager-1.0.0-install.exe
- TF卡格式化工具：SDCardFormatterv5_WinEN.zip


## after flash 

烧录完成以后，就可以弹出TF卡，并将其插到开发板正面 黑色字体序号 11.TF卡卡槽位置处，此时可以使用 杜邦线 连接 PE2 PE3 GND使用串口进行登录，也可以使用 adb shell 直接连接 ADB进行登录访问。

注意：D1s因TF卡和CKlink引脚存在复用关系，需将拨码开关 SW1 拨至数字方向，才可以支持TF卡启动

## ref 

- https://dongshanpi.com/DongshanPI-D1s/03-1_FlashSystem/#_7

- [[allwinner-dat]]