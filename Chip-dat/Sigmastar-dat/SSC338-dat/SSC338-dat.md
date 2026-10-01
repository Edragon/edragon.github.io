


# SSC338-dat



- [[IMX415-dat]] - [[SSC338-dat]] - [[RTL8812-dat]] - [[PCB-design-complex-dat]]



- [[Sigmastar-dat]] - [[SSC338-dat]] - [[openIPC-dat]] - [[wifi-dat]]

- [[SSC338-dat]] - [[wifi-dat]] - [[wifi-USB-dat]]

- [[Realtek-dat]] - [[RTL8812-dat]] - [[RTL8822-dat]]


## feature

功能特点：
- 1、1/2.8英寸800万像素黑光CMOS传感器；
- 2、带1T算力，可外挂算法；
- 3、支持H.265+、H.265、H.264编码；
- 4、支持2种灯光信号控制：CDS、PWM信号；
- 5、支持软光敏：全彩模式、红外模式、双光模式：
- 6、支持图像翻转，支持HDR；
- 7、支持智能分析：人形检测，自定义区域；
- 8、支持语音对讲、语音播报、自定义语音；
- 9、支持Onvif；
- 10、支持字符叠加；
- 11、IP地址过滤；
- 12、支持POE扩展；
- 13、提供SDK（WINDOWS，Android，Linux）开发包


## tuto 

电脑操作软件
1.把摄像头的尾线接DC12V电源，看到尾线上绿色灯闪烁，说明摄像头开始工作。
2.安装客户端软件LMS做监控使用
http://www.anjvision.com:8021/client/LMS_install_v5.5.0_20250922.exe
安装AjDevTools做修改摄像头的IP和参数使用
http://online.anjvision.com/client/AjDevTools_V6.0.4_20260430.exe
3.手机客户端：搜索AC18ProinAppleStore;

## 关于RTSP

The RTSP URL格式如下(假设摄像头的IP地址是192.168.0.123)：
主码流：rtsp://admin:123456@192.168.0.123/stream0
辅码流:rtsp://admin:123456@192.168.0.123/stream1

如果摄像头接入了咪头，那么视频流就包括了音频编码

如果只是需要视频流不包括音频则用URL：
主码流纯视频流：rtsp://admin:123456@192.168.0.123/video1
辅码流纯视频流：rtsp://admin:123456@192.168.0.123/video2
音频流：rtsp://admin:123456@192.168.0.123/audio

- [[sony-dat]] - [[IMX415-dat]]

SSC338Q == processor 



## pin out 

![](2026-10-01-03-19-56.png)

![](2026-10-01-03-31-17.png)

![](2026-10-01-03-31-28.png)

## board info 

Parameter	Value
Processor (SoC)	SigmaStar SSC338Q
Sensor	Sony IMX415, 1/2.8" 8 MP
Resolution	Up to 3840×2160 (4K UHD)
Video encoding	H.265 / H.264
Frame rate	Up to 30 fps at 4K
IR filter	Mechanical IR-Cut (ICR)
Interfaces	Ethernet 100 Mbps, USB 2.0 (Wi-Fi support)
Audio	Microphone or line input (depending on version)
RTSP stream	rtsp://<ip>:554/av0_0
Power	DC 12V or PoE (optional)
Wi-Fi support	Via external USB Wi-Fi module (e.g. AUF1, EU2)
OpenIPC support	Yes
IQTool support	Yes
Protocols	RTSP, ONVIF, HTTP, SSH
Form factor	Modular board (no enclosure)


## build 

- [[SSC338-dat]] - [[conn-DF56C-dat]] - [[IMX415-dat]]

![](2026-10-02-01-46-37.png)



## tech 

- [[ethernet-dat]] - [[corechips-dat]] - [[chip-cn-dat]]

- [[microsd-dat]]

- [[serial-dat]]

- [[conn-data-dat]] - [[CONN-BTB-dat]]

- [[TMI-dat]] - [[TMI3411-dat]]

- [[rychip-dat]] - [[ry3408-dat]] - [[chip-cn-dat]] - [[dcdc-down-dat]]

- [[power-dat]] - [[power-sequence-dat]] - [[SSC338-dat]]

- [[fitipower-dat]] - [[FP6185-dat]] - [[LDO-dat]]

## SCH 

main 

![](2026-10-02-02-13-50.png)

peripherals - [[flash-dat]] - [[MIPI-dat]]

![](2026-10-02-02-12-03.png)


## ref 

https://oshwhub.com/cheng_jun/ssc338q-diao-can-yi-ti