

# FPV-interface-dat

- [[FPV-interface-dat]] - [[FPV-dat]] - [[FPV-types-dat]] - [[FPV-fleet-dat]] - [[FPV-build-dat]] - [[FPV-fix-dat]]




- [[PPM-dat]] - [[PWM-dat]]


## CC3D 

CC3D 有三个扩展口（不只是两个）：

① MainPort（4 针 JST-SH）
• 串口：SBUS（⚠️ 需反相器）/ 遥测 / GPS
• ⭐️ 你的机上已被摄像头+图传占用

② FlexiPort（4 针 JST-SH）
• 可配 I2C / 串口（遥测 / GPS / Spektrum 卫星）
• 默认不用

③ ReceiverPort ⭐️ （8 针 JST-SH）
• ⭐️ 接收机专用口！
• PWM×6 输入 或 PPM 输入（Pin 3 白线）

⭐️ 所以：你的接收机应该接这个 8 针口 —— 在飞控上找一下（可能被线束遮住/在另一侧）



8 针的 ReceiverPort（接收机专用口）

## main port 

SBUS 接收机 → MainPort
⚠️ CC3D 官方明确：SBUS 需要【反相器适配器】
→ 多一个硬件 + 要改线（MainPort 已被占）
❌ 不推荐


## flex port 





## ref 