
# construction-dat

- [[construction-dat]] - [[rod-wood-dat]] - [[tube-steel-square-dat]]





## II. Basic Capacity of 60mm Steel Pipes (Core Data)

Assuming circular steel pipe Ø60 mm, common wall thicknesses are as follows:

| OD x Wall Thickness | Cross-sectional Area | Single Column Axial Load Capacity (Conservative) |
|-------------------|----------------------|-------------------------------------------------|
| 60 × 2.0 mm       | ≈ 3.6 cm²            | ≈ 5–7 tons                                     |
| 60 × 3.0 mm       | ≈ 5.4 cm²            | ≈ 8–12 tons                                    |
| 60 × 4.0 mm       | ≈ 7.1 cm²            | ≈ 12–18 tons                                   |

⚠️ This is the theoretical capacity for short columns, axial compression, without instability.
⚠️ In actual engineering, 80% of failures are limited by "buckling instability".

## III. The Real Killer: Column Instability (Buckling)
4 Key Parameters Affecting Safety

1.  **Column Height**
    *   2.2 m vs 3.5 m: capacity difference is 2–3 times.
2.  **Presence of Lateral Support**
    *   No diagonal bracing ≈ "Slender stick"
3.  **End Connection Method**
    *   Welded > Flange Bolted > Plug-in
4.  **Eccentric Loading**
    *   Off-center by 5 mm ≈ Capacity cut in half

## IV. Determining Feasibility in a "Practically Available" Way
### ✅ Case A: Rational Design → Feasible

**Assumptions:**
*   Ø60 × 3.0 mm steel pipe
*   Total house weight ≈ 2 tons
*   4 columns
*   Story height ≤ 2.5 m

**Features:**
*   Top ring beam
*   Middle horizontal tie rod
*   X-shaped diagonal bracing
*   Welded or rigid bolted connection

**Result:**
*   Each column bears ≈ 500 kg
*   Actual safety factor > 5
*   ✅ Completely feasible, even conservative.

### ⚠️ Case B: "Looks Like It Can Stand", but Non-compliant

**Assumptions:**
*   Ø60 × 2.0 mm
*   Column height 3 m
*   No diagonal bracing
*   Concentrated roof load
*   Plug-in or spot welding

**Result:**
*   Statics might be fine
*   Wind load / Eccentric load / Vibration → Sudden buckling
*   ❌ Not recommended, risk of "failure without warning".

## V. If You Really Want to Use 60mm Pipes, Here is a Safe Practice Template
### ✅ Recommended Configuration (Empirical)

*   **Columns:** Ø60 × 3.0 mm or thicker
*   **Column spacing:** ≤ 2.5 m
*   **Story height:** ≤ 2.8 m

**Must have:**
*   Top closed ring beam
*   At least one layer of horizontal tie rods
*   At least one X bracing on each side

**Foundation:**
*   Concrete foundation
*   Bottom flange ≥ 8 mm thick
*   Target safety factor: ≥ 3







一、什么是「圈梁」（Ring Beam / Tie Beam）
直观理解一句话

👉 圈梁 = 把所有立柱“绑成一个整体的闭合框架”的梁

它长什么样？

位置：

在立柱的最上端（最常见）

有时也在中部或基础上部

形态：

沿房屋四周一整圈连续连接

材料：

钢管 / 方管 / 工字钢 / C 型钢都可以

俯视示意（圈梁）：

┌────────────┐
│            │
│   房屋平面  │
│            │
└────────────┘
↑ 这一整圈就是圈梁

圈梁的 3 个核心作用（非常重要）

防止立柱“各自为战”

没圈梁：每根柱子像一根筷子

有圈梁：所有柱子变成一个“盒子”

分散局部载荷

屋顶某处重 → 圈梁把力分到其他柱

抗风、抗晃

风一吹，不是某一根柱子在扛，而是整圈在扛

👉 没有圈梁的钢结构，严格来说不算完整结构

实操建议（你这种 60 mm 管）

圈梁建议：

≥ 60×40×2.5 方管

或 Ø48 / Ø60 圆管

连接方式：

焊接最好

法兰螺栓也可以（但必须刚性）

二、什么是「水平拉杆」（Horizontal Tie / Bracing）
一句话理解

👉 水平拉杆 = 防止立柱在中途“弯折”的横向约束

它在哪？

高度：

通常在立柱的：

1/2 高度

或 1/3 + 2/3 高度

方向：

水平连接相邻立柱

侧视示意（水平拉杆）：

││      ← 立柱
││
├───┤  ← 水平拉杆
││
││

水平拉杆的真实作用（很关键）

把：

“一根 3 米高的细柱”

变成：

“两段 1.5 米高的短柱”

⚠️ 屈曲承载能力 ≈ 和“有效长度的平方”成反比

👉 加一根水平拉杆，立柱抗压能力能提高 2～4 倍

它和圈梁的区别
项目	圈梁	水平拉杆
是否闭合	必须闭合一圈	不一定
主要作用	整体刚度、分力	防柱子中途弯
位置	顶部 / 底部	中部
是否必需	几乎必需	强烈建议
三、一个“错误但很常见”的理解（重点）

❌ 错误想法：

“钢管够粗，不用拉杆”

⚠️ 实际：

60 mm 管子

3 m 高

没拉杆
→ 可能只剩 20～30% 的理论承载力

钢结构失败 80% 不是压坏，是突然弯了

四、圈梁 + 水平拉杆 + 斜撑 = 稳定三件套

你可以这样记：

圈梁：防“散架”

水平拉杆：防“折腰”

斜撑（X）：防“侧倒”

正立面简图：

│╲  │╱
│ ╲ │╱   ← 斜撑
├───┤    ← 水平拉杆
│   │
└───┘    ← 顶部圈梁

五、结合你的“两吨级小房屋”，一句结论

如果用 60 mm 钢管：

❌ 只有立柱 → 不安全

⚠️ 有圈梁，无拉杆 → 勉强

✅ 圈梁 + 水平拉杆 + 斜撑 → 工程上成立