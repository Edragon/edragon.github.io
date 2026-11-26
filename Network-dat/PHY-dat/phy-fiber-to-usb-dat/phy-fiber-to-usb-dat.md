


# phy-fiber-to-usb-dat

- [[phy-fiber-to-usb-dat]] - [[phy-fiber-to-copper-dat]] - [[phy-dat]]


- [[phy-fiber-to-usb-dat]] - [[RTL8153-dat]] - [[realtek-dat]] - [[RTL8156-dat]] - [[serdes-dat]]

- [[phy-fiber-to-usb-dat]] - [[microchip-dat]] - [[LAN7800-dat]] - [[LAN7801-dat]] - [[serdes-dat]]

把配对的 **SM1310 / SM1510** 光模块连接到 PC 的 USB 接口，主要有 **3 种常见方案**（从最省事的商业成品到自研硬件方案）：

---

### 方案一：成品“USB 3.0 转 SFP 光纤网卡”（最直接、单设备集成）

市面上有专门的 **Open SFP（开放式光口）USB 光纤网卡**，它就像一个自带 SFP 笼子的 USB 网卡，直接插在电脑 USB-A 或 Type-C 口上，再把你的 **SM1310**（或 **SM1510**）模块插进它的 SFP 槽即可。

* **内部核心原理：** 绝大多数千兆成品使用的是 **Realtek RTL8153**（或带 SerDes 输出的版本）配合光电转换前端。Windows 10/11、Linux 和 macOS 基本免驱或自带驱动。
* **购买时注意：** 一定要选标注 **"Open SFP"（不锁模块、空光口）** 的型号，这样才能插你自己的 SM1310/SM1510 单纤双向模块（部分低价成品把双纤光模块焊死在里面，无法替换）。

StarTech US1GA30SFP 是一款标准的商业级 USB 3.0 转开放式 SFP 千兆光纤网卡，内置 RTL8153 主控，支持直接插入单模或双模 SFP 光模块并由 USB 直接供电。

Zhpuostd USB-C 转 SFP 光纤网卡 采用金属外壳与 Type-C 接口，支持标准 1000BASE-X SFP 插槽，拔出自带双纤模块后即可兼容单纤双向模块。



### 方案二：通用组合（光纤收发器 + 普通 USB 网卡，性价比最高）

- [[TP-LINK-dat]] - [[UE300-dat]]

如果成品“USB 转 SFP 网卡”价格偏高（尤其是大牌工控款），日常或工程上最常用的组合是拆分两步：
`PC USB` $\rightarrow$ `普通 USB 千兆网口转接器` $\rightarrow$ `短网线` $\rightarrow$ `SFP 光纤收发器 (插 SM1310/SM1510)`

* **优点：** 成本最低（光纤收发器约 30~50 元人民币，USB 网卡约 30~60 元），散热好（光模块功率较大，独立收发器有独立电源，不会把笔记本 USB 口拖到供电不足或过热）。
* **注意：** 购买光纤收发器时，选带 **1 个 SFP 空槽 + 1 个 RJ45 电口** 的千兆光猫/收发器，且确认收发器支持 **1000M 固定速率**（部分老式百兆收发器插千兆模块会协商失败）。

TP-Link UE300 是一款常用的折叠式 USB 3.0 转千兆 RJ45 网卡，配合任意支持开放 SFP 插槽的千兆光纤收发器即可在 PC 上稳定跑满千兆。

---

### 方案三：自己设计 PCB 实现（USB 转 SFP 硬件方案）

如果你打算自己画板子把 USB 信号直接转成 SFP 光口，有两种硬件架构：

1. **双芯片架构（最稳妥、资料最全）：**
* **链路：** `USB 3.0` $\$rightarrow **USB 转 RGMII 网卡芯片**（如 **Realtek RTL8153B** 或 **Microchip LAN7800**） $\rightarrow$ `RGMII` $\$rightarrow **光口 PHY 芯片**（如 **RTL8211FS**，配置为 1000BASE-X 模式） $\rightarrow$ `SFP Cage`。


2. **单芯片直出架构（极简 BOM）：**
* **链路：** `USB 3.0` $\$rightarrow **带原生 SerDes/SGMII 输出的 USB 网卡芯片**（如 **Realtek RTL8153-VC** / **RTL8156B** 的特定 SerDes 模式，或 **Microchip LAN7801** 外接 SerDes PHY） $\rightarrow$ `SFP Cage`。
* **注意：** 芯片的 SerDes 必须通过 EEPROM 或配置引脚设为 **1000BASE-X** 协议（而非电口常用的 SGMII），且 USB 3.0 接口需提供足额的 **3.3V / 500mA+** 独立 LDO/DC-DC 供电给 SFP 光模块（单模长距光模块瞬时功耗可达 1W~1.5W）。



---

### 选型小建议

* **移动办公 / 外接笔记本调试：** 直接买支持 Open SFP 的 **USB 3.0 / Type-C 转 SFP 网卡**（注意确认 SFP 速率同为 1.25G 千兆；如果是 10G 万兆模块，则需要找基于 Intel/Aquantia 芯片的 USB4/雷电转 SFP+ 网卡）。
* **固定工位 / 工业长距离传输：** 优先用 **“独立供电的光纤收发器 + 普通 USB 网卡”**，避免光模块发热量直接传导至电脑 USB 接口。





## ref 


