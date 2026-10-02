


# fab-PCBA-moisture-baking-dat






MSL = Moisture Sensitivity Level（湿敏等级），IPC/JEDEC J-STD-020 定义的 1-6 级分类，衡量塑料封装器件开封后能在车间空气中暴露多久还不至于在回流焊时损坏。

一、为什么会有这个东西

塑封（环氧模塑料）会从空气吸湿。回流焊峰值 260°C 时，内部吸收的水分瞬间汽化膨胀，产生巨大应力 → 结果：

- 爆米花开裂（popcorning） — 封装本体炸开
- 内部分层（delamination） — 塑封料与芯片/引线框架剥离
- 金线断裂 / 内部裂纹

最阴的地方：焊接当时外表看不出问题，几个月后才表现为间歇性故障、不明原因死机。所以这是"隐性报废"。

二、等级 = 车间寿命（floor life）

车间环境 ≤30°C / 60% RH 下的允许暴露时间：

- MSL 1 — 无限（≤30°C/85%RH）
- MSL 2 — 1 年
- MSL 2a — 4 周
- MSL 3 — 168 小时（7 天） ← 细间距 BGA、大 QFN、大 QFP 最常见的等级
- MSL 4 — 72 小时
- MSL 5 — 48 小时
- MSL 5a — 24 小时
- MSL 6 — 按标签，每次回流前都必须烘烤

注意非线性：MSL 2 → MSL 3 是从 1 年掉到 7 天（50 倍）。所以"MSL3"听着温和，其实是严格档。

三、两个标准的分工（容易搞混）

- J-STD-020 = 定级/测试标准，IC 厂负责（怎么测、怎么打标）
- J-STD-033 = 搬运/存储/烘烤标准，下游（分销、EMS、你自己）负责

J-STD-020 认定 MSL3 的器件，只有在 J-STD-033 全程合规下才真按 MSL3 表现。链条任何一环断了（袋子破、干燥剂丢、记录没写），器件就退回"已暴露"状态 → 必须烘烤。

四、干燥包装三件套

- 防潮袋（MBB） — 铝箔复合袋，密封
- 干燥剂 — 吸湿
- HIC（湿度指示卡） — 印有 5% / 10% / 60% 三个圆点，干燥时蓝色，吸湿后变粉
  - 10% 点变粉 = 判定已吸湿 → 必须烘烤（多数工厂以此触发）
  - 5% 变粉 = 预警（干燥剂开始负载）
  - 60% 变粉 = 包装严重受潮，可能要评估还能不能用

五、烘烤参数（关键：看封装厚度，不看 MSL 等级）

- ≤1.4mm 薄封装 → 125°C × 24 小时（通用判断）
- 中等厚度 → 时间延长
- ≥4.5mm → 最长 192 小时
- 低温替代：90°C × 60-96 小时（载带/托盘不耐 125°C 时用）
- 40°C / ≤5%RH 干燥柜 → 数天到数十天（温和，可作长期存放）

三个硬性注意：
1. 载带（tape & reel）不耐 125°C → 高温烘焙前必须先把料从载带取出，否则载带变形 → 飞达卡料
2. 烤箱温度要用热电偶放在载物内实测，不能只看面板设定值
3. 烘完立即进入干燥包装/干燥柜，没有"预存时间"

六、最容易被误解的一点 ⚠️

 重新封袋 ≠ 时钟归零。只有烘烤能重置。

把用了一半的卷盘重新封袋加干燥剂，只能停止继续吸湿，不能消除已经吸进去的水。已经暴露的时间是累计的——多次开封要累加。

七、对你的实操意义（手工/小批量）

- 买料看包装：正规渠道的防潮袋 + 干燥剂 + 标签上的 MSL 等级，别拆封后随便敞放
- 记时间：MSL3 就是 7 天窗口，累计计时
- 触发烘烤的三个条件：超时 / 袋子破损 / HIC 10% 变粉
- 没烤箱也行：干燥柜（≤5%RH）可停表；低温 40°C 慢烘也行，就是慢
- 手焊也要注意：热风枪虽然单点时间短，但慢速大范围加热的总受热时间常常比回流炉还长 → 水汽照样会激发
- 返修（rework）也算二次湿气循环：板子在空气里放久了再返修，值得先烘板（125°C 几小时，注意板上其他元件的耐温）
- 已经焊到板上的：一般不再受 floor-life 约束；但若要二次回流（双面贴装），可能需要烘板

八、常见错误清单

1. 部分用完的卷盘重新封袋就当"时钟归零"（最常见）
2. 不同 MSL 等级的料混放，却套用最宽松的烘烤参数
3. 袋子到手时已开封，仍跳过烘烤
4. 仓库荧光灯下误读 HIC 颜色（粉/淡紫分不清）

---

一句话：MSL 是"开封后能放多久"的等级（MSL3 = 7 天，最常见的细间距 QFN/BGA 档）；超时/袋子破/HIC 10% 变粉就要 125°C × 24h 烘烤；重新封袋不能重置，只有烘烤能重置。




In SMT (Surface Mount Technology) assembly and small-batch manufacturing, **moisture-baking (去潮) refers to both PCBs and components**, but for different reasons and with different standards.

## 1. PCB Bake-Out (For the Circuit Board itself)

**Why bake PCBs?**

PCB base materials (such as FR-4 epoxy glass cloth) are hygroscopic and absorb ambient moisture over time. When exposed to the high temperatures of reflow soldering (around $240^\circ\text{C}$ to $260^\circ\text{C}$), the trapped moisture turns into steam instantly, leading to:

- Micro-cracking
- Delamination / Blistering (起泡)
- Pad oxidation

**Standard practice:** PCBs that have been unsealed for a long time or stored in humid conditions are typically baked before assembly (e.g., at $105^\circ\text{C}$ for 2 to 4 hours, depending on board thickness and moisture exposure).

## 2. Component Bake-Out (For ICs and Package Devices)

**Why bake components?**

Many integrated circuits and packaged semiconductors (especially plastic-encapsulated ICs like QFP, BGA, QFN, and fine-pitch chips) are classified as MSDs (Moisture Sensitive Devices).

If moisture trapped inside the plastic package vaporizes rapidly during reflow, internal pressure increases, causing the package to crack or internal wire bonds to break—commonly known as the "Popcorn Effect."

**Standard practice:** Check the Humidity Indicator Card (HIC) and Moisture Sensitivity Level (MSL) label on the component packaging. If components have exceeded their floor life or spent too much time exposed to ambient air, they must be baked (commonly at $125^\circ\text{C}$ for several hours, or following the specific manufacturer's label instructions).

## Summary Recommendation for Small-Batch SMT

- **Prioritize IC Components (Especially QFN, BGA, MCUs):** Moisture-sensitive chips are critical. If they have been unsealed for a while or exposed to humidity, baking the components is essential to prevent hidden internal defects or soldering failures.
- **PCBs Are Optional (Depends on Storage):** If your PCBs are fresh in vacuum-sealed bags and stored properly, they can be printed and soldered directly without baking. Bake them only if they have been exposed to high humidity or open air for an extended period.

## ref 


