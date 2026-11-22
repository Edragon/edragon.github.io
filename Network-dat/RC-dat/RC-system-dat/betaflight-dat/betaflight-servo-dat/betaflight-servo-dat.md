


# betaflight-servo-dat

- [[motor-servo-dat]] - [[betaflight-servo-dat]] - [[betaflight-dat]]

- [[rc-dat]] - [[rc-trainer-dat]] 



**有，Betaflight 调参软件（Betaflight Configurator）中有 `Servos`（舵机）页面。** 不过默认情况下它常常处于**隐藏状态**，需要手动开启或通过 CLI 重映射引脚后才会正常生效。

### 为什么有时看不到 `Servos` 页面？

1. **未开启专家模式（Expert Mode）：** 在 Betaflight Configurator 右上角，如果没有打开 **Enable Expert Mode**，部分进阶标签页（包括 `Servos`）可能不会显示。
2. **固件构建选项未包含舵机支持（BF 4.4+）：** 在 Betaflight 4.4 及更高版本的云端编译中，如果刷写固件时没有勾选舵机（Servo）相关选项，飞控固件本身可能不包含完整的舵机混控支持。

---

### 如何显示并配置 `Servos` 页面

1. **开启专家模式:** 调参软件右上角.
打开 Betaflight Configurator 并连接飞控，点击右上角的 **Enable Expert Mode** 开关，查看左侧边栏是否出现 **Servos** 标签页。
*Verification:* 左侧菜单栏出现 `Servos` 图标，点击后可进入舵机通道与行程设置界面。


2. **检查并分配舵机引脚资源:** CLI 命令行.
Betaflight 默认不会自动把普通焊盘分配给舵机，需在 **CLI** 标签页输入 `resource` 查看可用引脚（如空闲的电机焊盘或 LED 焊盘），再用 `resource SERVO <编号> <引脚>` 映射。例如将空闲的 `MOTOR 5`（假设对应引脚 `C09`）改为舵机 1：
`resource MOTOR 5 NONE`
`resource SERVO 1 C09`
`save`
*Verification:* 飞控重启后再次在 CLI 输入 `resource`，确认对应引脚已显示为 `SERVO 1`。


3. **绑定接收机通道与测试:** Servos 页面.
进入 **Servos** 页面，注意界面里的舵机编号从 `0` 开始（CLI 的 `SERVO 1` 对应页面的 `Servo 0`）。勾选对应的控制通道（如头追映射到的 `AUX 3`），调整 MIN/MID/MAX 行程，必要时开启 **Live mode** 测试（接电池测试前务必拆桨或断电调输出）。
*Verification:* 拨动遥控器对应通道或转动头追时，Servos 页面通道条响应，且舵机按设定方向与角度偏转。


> ⚠️ **注意**
> 飞控 BEC 的 5V 供电能力通常有限，驱动舵机时建议**不要直接从飞控 5V 焊盘拉取大电流**，尽量使用独立的 5V BEC 给舵机供电，仅将信号线（S）接到飞控映射好的舵机焊盘、地线（G）共地。如果你只是想把头追数据传给飞控做其他处理或走 **INAV / ArduPilot**，舵机控制逻辑和资源映射会略有不同。



## ref 

