

# antenna-polarization-dat



by - [[antenna-polarization-dat]] - [[antenna-type-dat]]




- [[antenna-dat]] Polarization == - [[antenna-RHCP-dat]] // [[antenna-patch-dat]] - [[antenna-linear-dat]] - [[antenna-polarization-dat]] - [[antenna-helical-dat]]

- [[antenna-diversity-dat]]




## polarization mismatch 

🔬 Basic principle

Antenna polarization comes in two types:
- Linear: ordinary "rod/vertical" antennas (your stock VR03 antenna is one) - [[antenna-linear-dat]]
- Circular: mushroom, disc, Cloverleaf types (your maple-leaf disc) - [[antenna-RHCP-dat]]

Matching rules:

| TX (VTX) polarization | VRX (goggles antenna) polarization | Result                     | Loss   |
| --------------------- | --------------------------------- | -------------------------- | ------ |
| Linear                | Linear (aligned)                  | ✅ Best                     | 0dB    |
| Linear                | Circular                          | ⚠️ Power cut in half       | -3dB   |
| Circular              | Circular (same handedness)        | ✅ Good (and pose-tolerant) | 0dB    |
| Circular              | Circular (opposite handedness)    | ❌ Disaster                 | -20dB+ |

🎯 Your case is most likely

X111 VTX antenna = Linear (rod)
Stock VR03 antenna = Linear → matched ✅ best performance
Maple-leaf disc antenna = Circular → mismatch -3dB ❌ so it feels worse


-3dB = signal power cut in half → your feeling matches physics exactly, it's not an illusion ✅

### linear TX + linear RX

飞机直线飞 → 天线垂直 → 匹配 ✅

飞机一转弯/倾斜 → 天线角度偏 → 极化失配
  偏 45° → -3dB（3dB 优势全没了）
  偏 90° → -20dB（信号暴跌，直接失控）



## polarization for antenna diversity 

混用极化会怎样？

1 根线极化 + 1 根圆极化
• 结果: ⚠️ 不会更差（系统选强的），但圆极化那根会长期不被选中（因为 -3dB）→ 白占一个位

**2 根圆极化（同旋向）**
• 结果: ✅ 最佳（分集增益 + 抗多径 + 抗姿态）

2 根线极化
• 结果: ✅ 好（但怕飞机姿态变化）




## apps 

- [[antenna-FPV-dat]] - [[antenna-location-dat]] 

- [[antenna-long-range-dat]] - [[RF-long-range-dat]] - [[FPV-long-range-dat]]


## ref 