
# Realtek-dat



## chip info 


### RTL8522/8822 

RTL8522 / RTL8822 系列 (如 RTL8822CS / RTL8822BU)
频段：支持 2.4 GHz / 5 GHz 双频 (802.11 a/b/g/n/ac，Wi-Fi 5)。

接口类型：根据具体后缀不同分为 SDIO (如 RTL8822CS，常用于板载模块) 和 USB (如 RTL8822BU，常用于高性能外置网卡)。

速率：双天线（2x2 MIMO），最高物理速率可达 867 Mbps。

特点：性能强劲，5GHz 频段在 FPV 图传和高速数据传输中表现优异，带宽大、延迟低。

缺点：功耗和发热量相对较大，对硬件供电和散热设计有一定要求。

### RTL8189 

RTL8189 (如 RTL8189FTV / RTL8189ES)
频段：仅支持单频 2.4 GHz (802.11b/g/n)。

接口类型：通常为 SDIO 或 USB。

速率：单天线（1x1 MIMO），最高物理速率通常在 150 Mbps。

特点：属于非常经典、低成本的物联网 Wi-Fi 芯片。功耗低、驱动在 Linux 内核中极其成熟。

缺点：带宽较低，2.4G 频段在现代城市或复杂无线环境下抗干扰能力极差，容易丢包，无法满足高质量的数字图传需求。


### RTL8733 

频段支持：支持 2.4 GHz / 5 GHz 双频（IEEE 802.11a/b/g/n），相比老旧的单频芯片（如 RTL8189），它能够使用干扰较小的 5G 频段。

速率与天线：采用单天线设计（1T1R），最高物理速率通常为 150 Mbps（属于 11n 时代的单通道规格，并非高速 Wi-Fi 5 或 Wi-Fi 6）。

接口类型（根据后缀不同而异）：

RTL8733BS：采用 SDIO 2.0 接口（WLAN）和 UART 接口（蓝牙），常被做成板载焊盘式模块。

RTL8733BU：采用 USB 2.0 接口，常被做成外置 USB 无线网卡或模块。

蓝牙规格：集成蓝牙（通常支持 BT 4.2 / 5.2 视具体版本而定）。




## chips 


- [[RTL9210-dat]] - [[disk-driver-dat]]

The RTL9210B is a high-speed controller (up to 10Gbps). If you are using a very high-capacity NVMe drive inside it, ensure you are using a high-quality cable, as some SSDs can "drop out" if they don't get enough power from a weak USB port.


- [[RTL8761-dat]] - [[BLE5-dat]] - [[bluetooth-dat]] - [[BLE-dat]]

- [[RTL8723-dat]]

- [[RTL8710-dat]]

- [[RTL8367-dat]]

- [[RTL8305-dat]]

- [[RTL8201-dat]]

- [[RTL8213-dat]]

- [[RTL8211-dat]]  - [[ethernet-dat]]

- [[RTL8192-dat]] 

- [[RTL8188-dat]] - [[RTL8189-dat]] - [[TL8189FQB2-DS.pdf]] - [[wifi-dat]]

- RTL8152B - [[RPI-SBC-dat]] - friendly - [[RTL8152-dat]] - [[wifi-dat]]

### RTS

- [[RTS5411-dat]] - [[realtek-dat]] == USB 3.0 Super-Speed HUB Controller

- [[USB-SDK-dat]] - [[USB-3.0-dat]] - [[RTS5411-dat]] - [[realtek-dat]] - [[digital-dat]] - [[DSP-dat]]



## Boards 

- [[MPC1070-dat]] - [[MPC1003-dat]]


## driver 

- [linux kenel driver ](https://github.com/lwfinger/rtw88)


Compatibility

Compatible with Linux kernel versions 5.4 and newer as long as your distro hasn't modified any kernel APIs. RHEL and all distros based on RHEL will have modified kernel APIs and are unlikely to be compatible with this driver.

Supported Chipsets

- PCIe: RTL8723DE, RTL8821CE, RTL8822BE, RTL8822CE, RTL8814AE
- SDIO: RTL8723CS, RTL8723DS, RTL8821CS, RTL8822BS, RTL8822CS
- USB : RTL8723DU, RTL8811AU, RTL8811CU, RTL8812AU, RTL8812BU, RTL8812CU
- USB : RTL8814AU, RTL8821AU, RTL8821CU, RTL8822BU, RTL8822CU






## repo 

https://github.com/Edragon/RTL8710



## ref 

- [[realtek]]

- [[802.11-dat]] - [[WIFI-DAT]]

- [[chip-dat]]

- [[TI-power-dat]]