


# rc-trainer-dat


- [[servo-dsc-dat]] - [[rc-trainer-dat]]


- [[rc-dat]] - [[rc-trainer-dat]] - [[motor-servo-dat]] - [[betaflight-servo-dat]] - [[betaflight-dat]]




要把一路自定义的头追（Head Tracker）数据信号通过 **RadioMaster Pocket** 的内置 ELRS 模块发送到远端飞控（如 Betaflight / INAV / ArduPilot），最稳定、低延迟的标准方案是：**走遥控器底部的 DSC 教练口（3.5mm 音频口）或 USB 串口，将头追信号伪装成“教练信号（Trainer）”，在 EdgeTX 系统中映射到空闲的 AUX 通道，最后通过 ELRS 协议打包发往接收机。**

下面提供最实用的两种接入方式（优先推荐 **方案一：教练口 PPM 接入**，抗干扰强且无需额外协议转换）。

---

### 方案一：通过 DSC 教练口注入（推荐，最稳定）

RadioMaster Pocket 底部有一个 **3.5mm DSC 教练口**，支持直接读取标准的 **PPM（脉冲位置调制）** 信号。

#### 1. 硬件准备与信号格式要求

* **信号协议：** 你的自定义头追（MCU/IMU模块）需要输出 **3.3V 电平的标准 PPM 信号**（通常包含 2~3 个通道，如 Pan 水平、Tilt 俯仰、Roll 横滚）。
* **接线方式：** 准备一根 3.5mm 两段式（TS）或三段式（TRS）音频线。
* **尖端（Tip）：** 接头追的 PPM 信号输出脚（TX/Signal）。
* **屏蔽环/根部（Sleeve）：** 接头追的共地（GND）。
* *注意：中间环（Ring）悬空不接，千万不要将电源正极接入音频口。*



#### 2. RadioMaster Pocket（EdgeTX）系统配置

在遥控器上开启教练功能，并把头追通道混控到 ELRS 发送的通道中（假设头追占用了 PPM 的 CH1 和 CH2，远端飞控用 CH7 和 CH8 控制云台）：

1. **开启教练输入模式:** 系统设置.
长按遥控器 **SYS** 键进入系统菜单，翻页找到 **硬件（HARDWARE）** 或在模型设置中进入 **模型设置（MODEL SETUP）**。将 **教练模式（Trainer）** 设置为 **Master/Jack（主控/教练口输入）**。
*Verification:* 转动头追设备，观察教练菜单底部的通道数值条（CH1/CH2），数值应随头部转动实时跳动。


2. **校准头追中心点与行程:** 系统菜单 - 教练.
进入 **SYS -> 教练（TRAINER）** 页面，让头追保持正前方静止，点击 **Cal（校准）** 将中位归零；根据舵机/云台实际转动角度调整倍率（Multiplier，默认 100%）。
*Verification:* 校准后，头追回正时对应通道显示为 `0.0`，左右/上下转动到极限时接近 `-100` 和 `+100`。


3. **将教练通道映射至 ELRS 发送通道:** 混控器（MIXES）.
按 **MDL** 键进入模型设置，翻页到 **混控器（MIXES）**。选择未被占用的通道（例如 **CH7** 和 **CH8**），新建混控：将 **信号源（Source）** 分别设为 `TR1`（教练通道1）和 `TR2`（教练通道2）。
*Verification:* 切换到遥控器主屏幕的通道监视器（Channel Monitor），确认 CH7 和 CH8 的输出条随头追动作同步变化。


4. **设置 ELRS 发射通道模式:** ELRS Lua 脚本.
在 SYS 菜单中打开 **ExpressLRS** Lua 脚本，将 **Switch Mode（开关模式）** 设置为 **Wide（宽模式）** 或 **16ch Rate/2**（确保 AUX 通道传输的是全分辨率比例信号，而非仅有 2/3 档位的开关量）。
*Verification:* 接收机端连接飞控地面站（如 Betaflight/INAV 的接收机页面），确认 AUX3（CH7）和 AUX4（CH8）平滑连续变化，无阶梯跳跃感。


---

### 方案二：通过蓝牙 / 串口（CRSF/SBUS）无线或有线注入

如果你的自定义头追具备蓝牙 BLE 功能（例如基于开源 **HeadTracker** 固件的 Arduino Nano 33 BLE），或者不支持输出 PPM，可以采用以下方式：

* **蓝牙教练模式（完全无线）：**
如果给 Pocket 升级或加装支持蓝牙的模块（部分版本需外接或确认内部芯片支持），在 **Trainer** 中选择 `Master/BT`，与头追蓝牙配对后，同样作为 `TR1/TR2` 混入 CH7/CH8。
* **CRSF 串口直通（适合自定义协议）：**
如果你需要传输的不是云台角度，而是**自定义的传感器字节流/遥测数据**，则不能走 PPM 通道映射（会被采样率限制）。此时需要将头追接入外置高频头仓的 **S.Port / CRSF 串口**，将自定义数据封装进 **CRSF 协议的自定义帧（Custom Telemetry Frame `0x7F` 或 `0x80`）**，通过 ELRS 链路透传到远端飞控的 UART 串口，再由飞控的自定义脚本（如 ArduPilot Lua 脚本）解析。

---

### 远端飞控端应用（以云台控制为例）

1. **硬件连接：** 接收机通过 CRSF 协议（TX/RX 交叉接飞控空闲 UART）连接飞控。
2. **飞控映射：**
* **Betaflight / INAV：** 在 **舵机（Servos）** 页面，将对应的 PWM 舵机输出口（如 Servo 1、Servo 2）分别绑定到接收机的 **AUX 3（CH7）** 和 **AUX 4（CH8）**。
* **ArduPilot：** 将 `SERVO9_FUNCTION` 设为 `6`（Mount Pan），`SERVO10_FUNCTION` 设为 `7`（Mount Tilt），并将 `RC7_OPTION` / `RC8_OPTION` 对应云台控制通道。



> ⚠️ **注意：ELRS 通道分辨率陷阱**
> ELRS 默认的 `Hybrid`（混合开关模式）为了降低延迟，会把 CH5 设为 2 档开关，CH6~CH8 压缩为 6 档或 7 档位！**用作头追控制舵机时，必须进入 ELRS 脚本把 Switch Mode 改为 `Wide` 模式**，否则云台转动会一顿一顿的（只有几个固定角度）。







## ref 