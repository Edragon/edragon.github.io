


# FHSS-dat


- [[ELRS-dat]] - [[FHSS-dat]] - [[rc-protocols-dat]]

- [[FPV-dat]] - [[FHSS-dat]] - [[fiber-optic-dat]]



## Solution 1: Use Receiver Voltage (RX-V) instead of RSSI


The HT-8A screen displays RX-V (Receiver Voltage) and transmits basic telemetry / link status, but standard budget FHSS setups often do not pass a clean digital RSSI packet through to Betaflight via traditional SBUS.

Instead of displaying an RSSI percentage that may not work without a dedicated analog line, many pilots using this hardware combination simply disable the RSSI element in Betaflight OSD and rely on Craft Name, Battery Voltage (Main LiPo), or Fly Time.

## Solution 2: Check if Analog RSSI Pad is Available on Your Flight Controller


If you absolutely must have an RSSI indicator on your OSD with this budget receiver:

Check your FPV receiver (e.g., Hotrc F-08A or similar) to see if it has an RSSI or PWM/Analog output pad.

If it does, run a physical signal wire from that pad to an RSSI or ADC pad on your flight controller.

In Betaflight Configuration tab, enable RSSI ADC Analog.

In the OSD tab, enable the RSSI Value element.




## CN 

**跳频技术**（Frequency-Hopping Spread Spectrum，简称 **FHSS**）是无线通信领域中一种非常经典的**扩频通信**技术。它的核心思想是：**通信双方的载波频率在伪随机码（跳频序列）的控制下，按一定的规律不断地跳变、切换。**

简单来说，就是收发双方不同步地在多个不同的频率信道上“高速捉迷藏”。只有双方掌握了相同的跳频规律（密钥/跳频图案），才能准确无误地收发数据。

---

### 一、 跳频技术的工作原理

在传统的固定频率通信中，信号只占用一个固定的窄带信道。而跳频系统的工作流程如下：

1. **信道分割**：将可用的总频段划分为几十个、几百个甚至上千个微小的跳频信道（频率槽）。
2. **伪随机跳变**：发射机的载波频率在跳频控制器（由伪随机码发生器驱动）的指挥下，每隔一段极短的时间（称为**驻留时间**，Dwell Time，通常为毫秒或微秒级）就从一个频率“跳”到另一个频率。
3. **同步接收**：接收端必须拥有完全相同的跳频序列和精准的时钟同步，像跳双人舞一样，以相同的规律在相同的频率上同步接收信号。如果接收端的频率没有对准，收到的就只是一段毫无意义的噪声。



### 二、 跳频技术的四大核心优势

1. **极强的抗干扰与抗截获能力（ECCM）**
* **抗干扰**：如果某个频率上的信道受到了强烈的外界电磁干扰或敌方定向Jamming（干扰机）压制，跳频系统只会在这一两个频点上瞬间丢包，随后立刻跳到下一个干净的频率。整体通信不会中断。
* **抗截获/低截获概率（LPI）**：因为信号能量被分散到了宽阔的频段上，且频率在不断高速切换，敌方很难通过传统的窄带侦察设备锁定信号源并长时间监听。


2. **多址能力与频谱共享**
* 不同的通信网络或用户可以分配使用不同的**跳频图案（Hopping Patterns）**。即使在同一个大频段内、甚至空间重叠，由于大家的跳频轨迹不同，彼此之间也不会产生持续的同频干扰。


3. **隐蔽性与安全性高**
* 数据在传输时被“碎片化”在不同的频率上，如果没有掌握跳频序列（密码），即使截获了部分电磁波也无法拼凑出原始信息。


4. **抗多径衰落**
* 无线电波在传播过程中常因反射产生多径效应（导致某些特定频率出现深度衰落）。跳频机制使得信号不断更换频率，从而有效避免了因某一固定频率衰落造成的通信彻底瘫痪。



### 三、 典型应用场景

* **军事无线电通信**：跳频技术最初和最核心的应用领域。军用单兵电台、战术车载电台常采用高速跳频（每秒跳变数百次甚至上千次），以防止敌方电子对抗、定位和窃听（例如美军的 **SINCGARS** 战术电台）。
* **民用蓝牙技术（Bluetooth）**：经典蓝牙（Bluetooth Classic）采用了自适应跳频技术（AFH, Adaptive Frequency Hopping）。蓝牙工作在 2.4GHz 的 ISM 频段，为了避开该频段内 Wi-Fi 和微波炉的巨大干扰，蓝牙设备会以 **1600次/秒** 的速度在 79 个可用信道之间疯狂跳频。
* **工业、科学与医疗频段（ISM）**：许多工业无线遥控器、物联网（IoT）私有协议、无线数传电台为了保证在复杂的电磁环境中稳定传输，也会采用低速或中速跳频技术。


## ref 


