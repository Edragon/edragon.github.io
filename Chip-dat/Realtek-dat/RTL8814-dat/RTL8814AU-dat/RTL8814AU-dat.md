


# RTL8814AU-dat


- [[antenna-MIMO-dat]] - [[RTL8814AU-dat]] - [[RTL8812AU-dat]] 

简单来说：**RTL8814AU 目前不能（或极不推荐）直接用于 OpenIPC 的数字图传（WFB-NG）系统。**

虽然它和 OpenIPC 广泛使用的 **RTL8812AU** 属于同一个芯片家族，但在 OpenIPC/WFB-NG 环境下，RTL8814AU 存在以下几个致命的技术瓶颈：


### 1. 核心原因解析

* **驱动缺失与内核兼容性问题：**
OpenIPC（特别是用于高清数字图传的 WFB-NG 固件）非常依赖无线网卡驱动在嵌入式 Linux 内核中的监听模式（Monitor Mode）**和**数据帧注入（Packet Injection）能力。RTL8814AU 的 Linux 开源/第三方驱动在嵌入式主控（如海思 Hisilicon、星宸 SigmaStar、瑞芯微 Rockchip 等 IPC 芯片）上的移植和优化极少，无法直接编译进 OpenIPC 有限的 Flash 固件空间中。

* **WFB-NG（图传协议）未对其进行适配：**
OpenIPC 底层使用的 WFB-NG 对网卡驱动有特定的修改（修改驱动以支持特定的帧注入速率、功率控制和低延迟传输）。目前社区所有的优化和测试都集中在 **RTL8812AU / RTL8822BU / RTL8812EU** 等芯片上，RTL8814AU 并不在支持列表中。

* **功耗与发热极大：**
RTL8814AU 是 4x4 MIMO（4天线）的网卡，功耗和发热量远超 2x2 MIMO 的 RTL8812AU。IPC 摄像机主板（天空端）的 GPIO 和 5V/3.3V 供电电路通常无法承受 RTL8814AU 高负载下的电流，极易导致 IPC 主板重启或网卡掉线。


- [[openIPC-dat]]



## ref 

