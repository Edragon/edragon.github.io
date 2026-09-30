


# FPV-fix-dat





- [[PCB-fix-dat]] - [[FPV-fix-dat]] - [[electronic-consumer-fix-dat]]

- [[FPV-build-dat]]



- [[mosfet-drive-dat]] - [[X12-dat]] - [[FPV-dat]] - [[FPV-fix-dat]] - [[mosfet-dat]]


- [[EFM8-dat]]

- [[EFM8-dat]] - [[ESC-dat]] - [[FPV-fix-dat]]

- [[PCB-fix-dat]] - [[FPV-fix-dat]]

- [[betaflight-dat]]

- [[motor-FPV-dat]] - [[ESC-FPV-dat]] - [[ESC-dat]]





## replaceable parts 

- [[camera-FPV-dat]] - [[camera-FPV]] - [[camera]]





## fix scenario 



### scenario 7. - bumping after arming 

ARM 后（idle，零油门）
        ↓
Airmode 开启 → 飞控【持续做 PID 姿态修正】（电机不停微调）
        ↓
飞机躺在地面（受约束）+ 姿态有微小偏差
        ↓
飞控"努力"想摆平 → 电机轮流加力 → 蹦蹦蹦 ⭐️

蹦 1-2 下后稳定，推油门起飞正常
• 判断: ✅ 正常（地面约束 + Airmode 的正常反应）


### scenario 6. - ⭐️ "阻力大" 

可能 A：电调 MOSFET 击穿（短路）⭐️⭐️ 最符合你的症状组合

电调 MOSFET 击穿 → 电机三相被【短接在一起】
        ↓
手动转电机 → 反电动势在短路回路里产生电流 → 【电磁制动】→ 阻力大 ⭐️
        ↓
同时完美解释：
  ✅ 低速转不动（驱动被短路吃掉）
  ✅ 高速勉强能转
  ✅ 嗒嗒声（电调换相失败）
  ✅ 阻力大（电磁制动）


可能 B：电机本体问题
- 轴承磨损/卡死
- 转子扫膛（碰定子）
- 铁屑/异物卡入
- 线圈短路


测电机三根线两两之间的阻值：
├─ 三相应【相等且非零】（1103 约零点几欧到 1 欧）
└─ 某两相为 0 / 明显偏低 → 线圈短路 ⭐️

断开后阻力消失 + 电调相间短路
• 结论: 电调 MOSFET 击穿
• 修复: 换该通道 MOSFET（可能连带多个坏）或直接换板 ⭐️

断开后阻力仍在
• 结论: 电机本体
• 修复: 换电机（¥30-60）

电机三相阻值不对
• 结论: 电机线圈短路
• 修复: 换电机




### scenario 5. - 起飞瞬间会【翻机/摔机】


故障"跟随电机"→ 问题在电机本身 + 换位置后仍然向下压

把该电机 3 根线中的【任意 2 根对调】（重新焊接/插拔）
        ↓
转向立刻反转 → 与另外三个一致 ✅

反转电机 + 向下推力 → 起飞瞬间会【翻机/摔机】
→ 修好前别飞（卸桨测试转向即可）



### scenario 4. - 1 / 4 motor/propeller not running 

- [[mosfet-dat]] 

- [[FPV-fix-dat]] - [[PCB-fix-dat]] - [[X12-dat]] - [[FC-AIO-dat]]


### scenario 2. - desync

"Whining + spins briefly then stops" = classic "**desync**" ⭐️

Initial diagnosis:
1. ⭐️ Missing phase (one phase has a bad connection) → missing phase at startup → whine + desync protection (~40%)
2. Wrong ESC startup parameters (Bluejay startup power too low / timing mismatch) (30%)
3. Weak MOSFET drive on one ESC phase (20%)
4. Local short in motor winding (10%)

⚠️ Note: "each motor spins fine when tested alone" ≠ the motor is OK — no-load current is small and hides the desync under load.

Four steps to confirm:
① Check all solder joints on all 4 motors (focus on the one that whines)
② Swap test (same as below)
③ ESC Configurator tuning:
   - Startup Power ↑ (raise startup power)
   - Motor Timing adjustment
   - Enable Demag Compensation
④ Reflash Bluejay / try a different version to verify (you flashed firmware before)


### scenario 3. - RUNAWAY

1. ⭐️⭐️ Gyro detects motion:
   - The craft is not completely still / not level at ARM (held in hand, wobbling, wind)
   - Or faulty gyro (crashed board → false motion detection)
2. ⭐️⭐️ Wrong motor order / direction configuration
   - ⚠️ Note: a single-motor test can't catch this (it only checks "does it spin", not position/direction)
   - Wrong order → flight controller corrects direction after ARM → triggers protection
3. ⭐️ PID / filter too aggressive (output saturation)
4. Airmode + high idle combination
5. Faulty flight controller board (gyro/accelerometer)

check 

① Actual motor rotation direction (physical)
② Propeller type (CW / CCW)         ← must match ①
③ Flight controller setting `yaw_motors_reversed`  ← must match ①





### scenario 1. - VTX 

- [[FPV-fix-dat]] - [[PCB-fix-dat]] - [[betaflight-video-transmitter-dat]]

![](2026-09-17-16-29-14.png)

Your VTX is not configured or not supported. So you can't modify the VTX values from here. This will only be possible if the flight controller is attached to the VTX using some protocol like Tramp or SmartAudio and is correctly configured in the Ports tab if needed.


## power up checklist 

- power up self-check sound 
- [[sensor-motion-dat]] in [[betaflight-dat]] 
- [[ESC-dat]] - [[EFM8-dat]]
- [[PCB-fix-dat]] - [[FPV-fix-dat]]

- [[FC-AIO-dat]] - [[ESC-dat]] - [[X12-dat]] - [[test-point-dat]] == pin 4 (VCC) and 5 



## 为什么 4 路全部无输出、无自检音？

每路都有独立的一套 1N + L1 + R + C，它们绝不可能在撞击中 4 套同时坏掉！

唯一的可能：这 4 套驱动电路共同连接的「上游供电源」断了！

请顺着看二极管 L1 的阳极（Anode，没有白杠的一端），或者 上拉电阻 R1 的电源端：
- 它们必须并联到一个公共供电节点（V_DRIVE）上。
- 如果这个公共供电为 0V：
  - 二极管无法给电容充入驱动电荷。
  - 上拉电阻两端没有电压，主功率 MOSFET 的 G 极永远是 0V。
  - 1N 就算怎么开关，G 极依然是 0V，主功率 MOSFET 永远锁死在关闭状态！
  - 这就造成：EFM8 拼命发信号、发自检音波形，但主功率管纹丝不动，完全没有电流流过电机！



## common drive 

1. 公共地（GND）：MOSFET 的源极（S）到底通不通电池负极焊盘？（前面提到的测点一）
2. 公共驱动供电（V_drive）：给那 12 组驱动二极管/三极管供电的母线是否断裂？
3. 公共复位/使能（Reset/Enable）：EFM8 虽能与电脑通信，但功率输出是否被板级硬件引脚全部钳位？




## ref 


