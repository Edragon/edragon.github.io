


# ZTE-dat

- [[ZTE-dat]] - [[USB-tethering-dat]] - [[USB-SDK-dat]] - [[WIFI-USB-pocket-dat]] - [[wifi-dat]] - [[wifi-dongle-dat]]

- [[vivo-iqoo-dat]] - [[vivo-dat]] - [[ZTE-dat]] 

## models support USB tethering 

- U12 U25 
- F40 need external power 
- 中兴 MU5001 / MU5120 等高端 5G 随身 Wi-Fi（MiFi）
- F50 == 400+ 

中兴随身WiFi（如F30、F31、TZ101等中兴微芯片设备）`去云控`和`切卡`通常需要先通过后台或特定链接开启ADB调试，再利用工具（如随身WiFi助手）执行移除远控指令。这能防止厂商远程限速或断网


中兴（ZTE）设备（如随身WiFi / CPE 或 中兴手机）的`刷机`与`改串号`（修改 IMEI）主要依赖设备所使用的芯片方案。中兴最常见的设备是基于中兴微（ZXIC）芯片或高通（Qualcomm）芯片的随身WiFi（例如中兴F50、F32 Pro、TZ101等）。核心结论：通过纯 ADB 命令行改串通常是临时的（重启后恢复），必须通过开启后台的 AT 串口驱动，使用 AT 指令直接写入基带芯片或固件，才能实现永久改串


## models not support USB tethering

- U10LS 
- U10S
- F30 
- MF936 
- MF935 

## ref 

