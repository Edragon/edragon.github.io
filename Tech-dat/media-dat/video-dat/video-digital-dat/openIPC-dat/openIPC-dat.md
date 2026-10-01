

# openIPC-dat



== [[VRX-dat]] + [[VTX-dat]]

- [[openIPC-dat]] - [[camera-IP-dat]]

- [[opensource-dat]] - [[openIPC-dat]] ?? - [[IMX307-dat]] - [[VTX-dat]]

- [[camera-digital-dat]] - [[Sigmastar-dat]] - [[openHD-dat]] - [[opensource-dat]] - [[openIPC-dat]] - [[rubyFPV-dat]] - [[video-digital-dat]]



https://github.com/OpenIPC/firmware


- [[camera-IP-dat]] - [[sensor-camera-dat]]


## best support 

- [[openIPC-dat]] - [[HiSilicon-dat]] - [[SigmaStar-dat]] - [[Goke-dat]] - [[Ingenic-dat]]

- [[hi3516-dat]] - [[HiSilicon-dat]] - [[HI3518-dat]]



- [[goke-dat]] - [[GK7205V210-dat]] - [[camera-IP-dat]] - [[openIPC-dat]]

- [[Sigmastar-dat]] - [[SSC338-dat]] - [[openIPC-dat]]

test == 17db枫叶天线 == 50ms // 35km


## wifi

- [[realtek-dat]] - [[WIFI-USB-dat]] 

rtl8731成品模块+PA放大器 - [[RTL8731-dat]]

- [[RTL8812-dat]]

- [[wifi-dat]] - [[wifi-WFB-NG-dat]]

## camera 

- [[sensor-camera-dat]] 

- [[sony-dat]] - [[imx415-dat]] - [[IMX307-dat]]




## SDK 

- [[uboot-dat]] - [[openIPC-dat]] == unlock 





## info 

https://github.com/OpenIPC/wiki/blob/master/en/installation.md

https://docs.openipc.org/getting-started/homepage/

flash tool - https://github.com/OpenIPC/companion/releases



## branches 

- [[APFPV-dat]] - [[openIPC-dat]]

## parts 

- [[MCU-dat]] - [[SBC-dat]] 

- [[camera-digital-dat]] - [[Sigmastar-dat]]

- [[RF-modules-dat]] - [[RF-dat]]


- [[EMax-dat]] - [[runcam-dat]] - [[openIPC-dat]] - [[camera-IP-dat]]


- [[Eachine-dat]] - [[Eachine-Sphere-Link-dat]]




## build 



### build air-unit // [[VTX-dat]]


![](2026-10-01-18-34-30.png)

via - [[ethernet-dat]] - [[powervision-dat]]

![](2026-10-01-18-25-59.png)

OpenIPC 摄像机方案（主流黄金组合）

采用支持 OpenIPC 的安防/机器视觉模组（如 GK7205、SSC338 等芯片的 IPC 摄像机），机载直接运行 WFB-NG 将编码后的 H.265/H.264 视频通过发射网卡推出去，省去了额外的树莓派机载电脑，成本低且效率极高。

传统树莓派机载方案（较老）

早期用树莓派 + CSI 摄像头 + 树莓派官方系统的方案，目前在 OpenIPC 普及后逐渐被更低延迟的 IPC 方案替代。


### build ground-unit // [[VRX-dat]]

- [[serial-dat]]


#### 芯片方案确认：

TP-Link Archer T4U 根据硬件版本不同，历史上使用过 Realtek（如 RTL8812AU）等芯片。

WFB-NG 飞行图传对网卡有特殊要求：地面端网卡必须能够开启 Monitor 模式（混杂/监听模式） 并支持注入，才能正确解包无人机发出的 WFB-NG 射频流。

**Android 系统的驱动限制：**

原生 Android 系统内核并没有编译进绝大多数外置 USB 无线网卡的驱动（特别是需要支持 Monitor 模式的底层驱动，如 8812au 等）。

除非你的 Pixel 8 Pro 已经解锁 Bootloader 并刷入了经过特制、编译了无线网卡驱动与 Wireshark/Monitor 补丁的 Kernel（内核），否则标准的 Android 系统无法直接驱动这款 USB 网卡去接收 WFB-NG 图传

替代推演：通常玩 OpenIPC + WFB-NG 手机地面端时，大家更多会用 Android 手机连接一个车机/图传接收盒（例如用树莓派 Zero 2W、香橙派、或者专门的随身Wi-Fi刷机作为接收端）。接收端负责插 USB 网卡收图传，然后通过 Wi-Fi 热点把视频流发给 Pixel 8 Pro 显示。

##### WFB-NG

- [[wifi-dat]] - [[wifi-WFB-NG-dat]]

WFB-NG 对网卡有严格的底层要求（必须支持 Monitor 混杂监听模式 和 Packet Injection 数据包注入）。目前官方正式支持和维护的芯片方案主要有以下几种：

**Realtek RTL8812AU（最经典、最主流）**

特点：802.11ac 双频（主流跑 5GHz），市面上绝大多数长距离高清图传网卡（如 Alfa AWUS036ACH、BL-R8812AF1 等）均采用此方案。

注意：必须使用 WFB 社区打过补丁的专属驱动（如 rtl88xxau_wfb）才能开启高性能注入。你手头的 TP-Link Archer T4U 如果是早期 V1/V2 版本，部分批次曾采用过此芯片。

**Realtek RTL8812EU（新一代官方主力推荐）**

特点：性能强、射频表现优秀，是目前接替老旧芯片的主力方案（如 LB-LINK 的 BL-M8812EU2 模块）。同样需要特定的补丁驱动。

**Atheros AR9350 / ath9k 系列 SoC 方案（如高功率桥接网桥）**

特点：常见于 TP-Link CPE510 或 Ubiquiti 等户外 CPE 设备。支持 802.11n 及 LDPC，通常刷入 OpenWRT 后在集群模式（Cluster mode）下使用。

⚠️️ 社区明确不推荐或不支持的常见芯片：如 8811*、8812bu、8812cu、8814au 以及部分发热量大、射频设计 flawed 的型号（如 AC180）。




#### 二、 地面端与接收平台方案（怎么接屏幕）

WFB-NG 接收到无线射频并解包后，需要将视频流（RTP/UDP）输出给显示设备。目前主流的地面端承载方案有：

Linux 笔记本 / PC 方案（Ubuntu / Debian）

直接在电脑上插兼容网卡，运行 WFB-NG 接收端，配合 GStreamer 或 QGroundControl 显示，延迟最低、性能最强。

树莓派 / 嵌入式 Linux 盒子方案（Raspberry Pi / Radxa / 随身Wi-Fi）

采用小型的树莓派（如 Pi Zero 2W / Pi 4）或香橙派作为“图传接收盒”，插网卡收数传和图传，再通过局域网 Wi-Fi 将画面转发给平板或手机。

Android 手机 / 平板方案（如 PixelPilot 等开源地面站软件）

专门为 Android 开发的地面端显示软件，但它极少直接通过 USB OTG 驱动外置高功率网卡（因为 Android 内核限制），通常需要配合上述的“接收盒子”使用，或者使用特定移植了驱动的极少数定制 Android 开发板。


## ref 


- [[video-digital]] - [[openIPC]] - [[video]]