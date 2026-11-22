



# USB-3.1-dat

- [[USB-4.0-dat]] - [[USB-3.2-dat]] - [[USB-3.1-dat]] - [[USB-3.0-dat]] - [[USB-2.0-dat]] - [[conn-USB-type-c-female-24p-dat]]

- [[USB-converter-dat]] 



## speed 

❌ 两台都是 USB 2.0，都不支持 USB 3.1


一、规格核对
Table
⭐ 根因在 SoC（手机 USB 版本由芯片决定，厂商不会越级做）：
   · 骁龙 695（Z7x）：PhoneDB 明确「Supported USB Specification: USB 2.0」
   · 骁龙 680（U5x）：同为 6 系 → USB 2.0
   ⭐ 高通 6 系里只有【骁龙 6 Gen 1（SM6450）】才支持 USB 3.1

二、⭐⭐ 反直觉：对 T4 这种长线场景，USB 3.1 反而是坏消息
USB 无源线（不带芯片）的官方最大长度
Table
⭐⭐ 接口越快 → 无源线越短
        ↓
T4 用 8m 线 —— USB 3.1 连做梦都不可能
⭐ USB 2.0 才是唯一现实选择
   （8m USB 2.0 已超标准 5m，靠 tethering 专用线的信号调理才跑得动）

三、T4 需要多少带宽？USB 2.0 富余得过分

Table
分辨率 / 编码	典型码率	占 USB 2.0
1080p H.264	2-5 Mbps	0.4 - 1.7%
1080p H.265	1-3 Mbps	0.4 - 1.7%
4MP@20fps H.265（IPC 模组）	4-8 Mbps	1.3 - 2.7%

⭐ USB 2.0 理论 480 Mbps、实测约 280-320 Mbps
   T4 最多用 8 Mbps → 用掉不到 3%
        ↓
📌 【USB 3.1 对 T4 毫无价值】，纯粹是纸面参数


四、⚠️ 但 U5x 有一条要实测确认

Smartprix 对 `U5x` 的 USB Features 只写：
   "USB on-the-go, USB Charging"        ← ⚠️ 没列 USB Tethering

而 `Z7x` 写的是：
   "USB Tethering, USB on-the-go, USB Charging"   ← ✅ 明确有
⚠️ 但这更可能是【资料不全】而不是功能缺失（Android 11 系统层面支持）
        ↓
⭐ 实测判据：插上电脑，看下拉通知栏有没有「USB 网络共享」选项



五、⭐⭐ 对本项目的实际结论
✅ T4 用 USB 2.0 完全够（带宽只用 3%）
✅ 两台都能做 T4 的手机端
        ↓
📌 但要在两台里选一台当联网机：⭐ 【iQOO Z7x】更合适

Table
对比	iQOO Z7x	iQOO U5x
接口	⭐️ Type-C（能用现成 8m 线）	⚠️ microUSB（长线少见、卡扣更易松）
USB Tethering	✅ 官方明确列出	⚠️ 待实测
充电功率	⭐️ 80W（边推流边充不净掉电）	⚠️ 10W（可能掉电）
网络	5G	仅 4G

📌 一句话
两台都不支持 USB 3.1 —— 都是 USB 2.0
        ↓
⭐ 但对 T4 这不是缺陷，是必要条件
   USB 3.x 无源线只有 3m，8m 线根本做不了
        ↓
📌 要做 T4 联网机，选 iQOO Z7x（Type-C + 80W + 明确支持 Tethering）




## build 

### pixel2XL 

- [[conn-USB-type-c-dat]] - [[pixel2-dat]] - [[phone-pixel-dat]] - [[USB-3.1-dat]]


### 1. Pixel 2 XL Type-C Hardware Specs (How many signal lines?)

The Google Pixel 2 XL uses a **full 24-pin USB Type-C physical port** running the **USB 3.1 Gen 1 (5 Gbps)** standard.

Out of the 24 pins (excluding power `VBUS` and ground `GND`), there are **14 active signal lines**:

* **8 SuperSpeed Data Lines (USB 3.1):** Two pairs of `TX+/TX-` and two pairs of `RX+/RX-` (4 differential pairs total) for bidirectional 5 Gbps data transfer in either plug orientation.
* **2 Legacy Data Lines (USB 2.0):** `D+` and `D-` (1 differential pair) for standard USB 2.0 communication and initial handshakes.
* **2 Configuration Channel Lines (`CC1` and `CC2`):** The most critical lines for your setup—they negotiate USB-PD charging and tell the Pixel 2 XL whether to act as a **USB Host (OTG)** or a USB Device.
* **2 Sideband Use Lines (`SBU1` and `SBU2`):** Auxiliary lines used primarily for audio passthrough.

*(Note: Although the physical port has all 24 pins wired, Google disabled native DisplayPort Alt Mode in hardware/firmware, so HDMI video output on any hub will not work on the Pixel 2 XL.)*

---

### 2. Required Conditions When Buying an Adapter / Hub

If you want to connect your Pixel 2 XL to your router reliably (while avoiding power drops or connection failures), make sure the adapter meets these **5 criteria**:

1. **True Android OTG Host Support (Proper `CC1/CC2` Wiring)**
* Cheap charging-only adapters omit proper `CC` logic and won't trigger OTG host mode. Look for explicit **"Android OTG supported"** specs.


2. **Pass-Through PD Charging (`PD In` Port)**
* The Pixel 2 XL has weak OTG power output on its own, which causes USB network adapters or router tethering connections to randomly drop.
* Choose an adapter with a dedicated **Type-C PD charging port** so an external charger powers both the phone and the network interface simultaneously without resetting the OTG link.


3. **Driverless Ethernet Chipset Compatible with Android 11 (Linux 4.4 Kernel)**
* Because the Pixel 2 XL is capped at Android 11, newer **2.5Gbps Ethernet chips (like RTL8156)** often lack built-in kernel drivers and won't work.
* Whether built into the hub or plugged in separately, stick to classic plug-and-play **100M / 1000M chipsets**:
* **Best choice:** ASIX **AX88179** (Gigabit) or **AX88772A/B/C** (100 Mbps)
* **Second choice:** Realtek **RTL8153** (Gigabit) or **RTL8152B** (100 Mbps)




4. **Full USB 3.0 (5 Gbps) Data Wiring**
* Ensure the hub's data ports are wired for USB 3.0 (`TX/RX` lines present) rather than stripped-down USB 2.0, preventing bottlenecks or packet drops during local IP camera streaming.


5. **Short, Shielded Cable (10–15 cm / ~0.5 ft)**
* High-frequency USB 3.0 signals are sensitive to cable length and interference; a short pigtail cable keeps the connection rock-solid.



---

### Best Setup Recommendation

Instead of connecting through your router's USB port, the cleanest and most reliable setup for accessing `192.168.0.4:8080` is a **USB-C to RJ45 Gigabit Ethernet + PD Charging adapter** (built with an **AX88179** or **RTL8153** chip):

* **Wall Charger** $\rightarrow$ Adapter's **PD Port**
* **Router LAN Port (Ethernet cable)** $\rightarrow$ Adapter's **RJ45 Port**
* **Adapter USB-C Plug** $\rightarrow$ **Pixel 2 XL**

This bypasses router USB-tethering compatibility issues completely, keeps your Pixel 2 XL charged, and puts the phone directly onto your local LAN subnet (`192.168.0.x`).


- [[USB-converter-dat]] - [[USB-hub-dat]]


## ref 