


# antenna-range-dat


**棒状（标配）** - [[antenna-linear-dat]] == omni 棒状（标配）
• 方向性: 全向
• 极化: 线极化
• 典型增益: 3dBi
• 5.8G 距离: 0.5-1km

蘑菇（skew planar）
• 方向性: 全向
• 极化: 圆极化
• 典型增益: 1-2dBi
• 5.8G 距离: 0.4-0.8km（-3dB）

Patch（平板） - [[antenna-patch-dat]] - [[antenna-RHCP-dat]]
• 方向性: 定向
• 极化: 圆极化/线极化
• 典型增益: 8dBi
• 5.8G 距离: 2-4km

**Helical（螺旋）** - [[antenna-helical-dat]]
• 方向性: 定向
• 极化: 圆极化
• 典型增益: 10-14dBi
• 5.8G 距离: 5-10km

**Yagi（八木）**
• 方向性: 定向
• 极化: 线极化
• 典型增益: 10-15dBi
• 5.8G 距离: 5-10km


High gain + high VTX power + high altitude
• Approximate range: 10km+

(A 3dB difference only accounts for ~14% of the range here; the gain difference dominates)

## Conclusion

Should long-range use linear polarization?

• Answer: ⚠️ Theoretically +3dB, but high risk (pose mismatch)

Does circular polarization lose range?

• Answer: Constant -3dB (×0.71 range), but the reliability gained from stability is worth more

First priority for long-range

• Answer: ⭐️ High-gain directional antenna (regardless of polarization type)

Recommended combination

• Answer: RHCP omni (aircraft) + RHCP high-gain directional (ground)

In one sentence: "Long-range = directional antenna + line of sight + altitude." Polarization just needs to match at both ends; instead of agonizing over the 3dB between linear and circular, raise the antenna gain.

- 线极化 yagi 和 圆极化 helical 都能飞 5-10km
- 差别只在：yagi 多 3dB 但怕姿态 / helical 稳但少 3dB
- ⭐️ 真正拉开距离的是"全向 → 定向"这步（+5~11dB），不是线/圆那 3dB



## ref 