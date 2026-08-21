
# FPV-load-dat

- [[FPV-purpose-dat]] - [[FPV-types-dat]] - [[FPV-load-dat]] - [[indoor-fly-dat]]


== [[TX800-dat]] + [[MS-519-dat]] + [[camera-action-dat]] = RMB 250 + 500 = 750


- [[thrust-dat]]


**续航一样是"比例关系"，载重是"绝对数量"**，两者逻辑完全不同。拆开：

---

**载重 = 绝对能力，跟着"基础重量"走**

关键概念：**载重能力 ≈ 基础重量的固定比例**（由推重比决定）

| 尺寸   | 基础重量 | 可挂载                           | 挂载占比 |
| :----- | :------- | :------------------------------- | :------- |
| 3.5 寸 | 250g     | ~100-150g（GoPro 勉强）          | 40-60%   |
| 5 寸   | 500g     | **~300-400g（GoPro 轻松+云台）** | 60-80%   |
| 7 寸   | 1000g    | ~500-800g（微单云台）            | 50-80%   |

**推重比相同（比如都是 3:1）时：**

```text
3.5寸：推力 750g - 自重 250g = 可载 500g？不，实际不是这样
```

等等——实际可载不是简单减法，因为**挂载会恶化桨盘载荷和机动性**。简化理解：

---

**为什么 5 寸能轻松挂 GoPro，3.5 寸勉强？**

**① 绝对余量不同**

同样挂 100g 的 GoPro：

|              | 3.5 寸 (250g)         | 5 寸 (500g)            |
| :----------- | :-------------------- | :--------------------- |
| 挂载前推重比 | 3.5:1                 | 3.5:1                  |
| 挂载后推重比 | (875)/(350)=**2.5:1** | (1750)/(600)=**2.9:1** |
| 影响         | ⚠️ 明显下降，手感变肉  | ✅ 影响小，依然灵活     |

**同样的 100g，对小机是"25% 增重"，对大机只有"10% 增重"。**

**② 桨盘载荷的恶化程度不同**

```text
桨盘载荷 = 总重 ÷ 桨盘面积

3.5寸挂GoPro: 350g ÷ 小桨盘 = 载荷激增 → 要更高转速 → 效率暴跌
5寸挂GoPro:   600g ÷ 大桨盘 = 载荷温和 → 转速增加不多 → 效率损失小
```

**③ 结构强度余量**

- 5 寸机架碳板更厚、臂更长，天然为挂载设计
- 3.5 寸挂重物后机动响应迟钝、容易"头重脚轻"

---

**为什么续航一样但载重不同？—— 核心逻辑**

```text
续航：能量 ÷ 功率 → 都是"自身比例" → 按比例放大后不变 ✅
载重：绝对克数 → 由基础重量决定 → 基础重量翻倍，载重翻倍 ✅
```

|          | 续航                   | 载重             |
| :------- | :--------------------- | :--------------- |
| 本质     | **相对量**（自身比例） | **绝对量**（克） |
| 3.5 vs 5 | 相同                   | 5 寸 ≈ 2-3 倍    |

---

**类比**

> **续航 = "油箱能跑多远"（和车大小无关，按比例都一样）；载重 = "能拉多少货"（大车就是能多拉）。**
> 
> 3.5 寸和 5 寸是"小车和大车"，油耗效率相同（续航一样），但**大车的额定载重就是大**。

---

**实际影响**

| 场景            | 结论                             |
| :-------------- | :------------------------------- |
| 挂 GoPro 裸机   | 5 寸轻松，3.5 寸勉强（手感变差） |
| 挂 GoPro + 云台 | **只有 5 寸+**，3.5 寸带不动     |
| 挂微单/大相机   | 7 寸+                            |

**这就是为什么航拍至少选 5 寸、最好 7 寸**——不是续航问题，是**载重余量**问题：3.5 寸挂上相机就"飞不动了"，5/7 寸挂上相机依然从容。

## higher weight for human control feeling 

### Human Control Feel & Flight Dynamics Breakdown

| Flight Characteristic        | Stock Mobula8 (43g Dry / ~69g AUW)                                    | Your Build (50g Dry / ~76g AUW)                                                           |
| :--------------------------- | :-------------------------------------------------------------------- | :---------------------------------------------------------------------------------------- |
| **Thrust-to-Weight Ratio**   | **~7.5 : 1**                                                          | **~6.4 : 1**                                                                              |
| **Hover Throttle Point**     | **18% – 20%**                                                         | **23% – 25%**                                                                             |
| **Dive Recovery & Catching** | Instant, violent stop. Catches momentum near the ground effortlessly. | Has slight momentum "hang". Requires applying throttle **10–15% earlier** to catch dives. |
| **Cornering & Momentum**     | Extremely snappy; changes direction on a dime.                        | Minor outward drift on sharp 90° turns due to higher inertia.                             |
| **Roll/Pitch Snaps**         | Twitchy and ultra-fast.                                               | Slightly smoother, "heavier" feeling transitions.                                         |
| **Wind Resistance**          | Easily bumped around by light wind.                                   | **Better**. Extra mass carries momentum through wind gusts outdoors.                      |

---

### Betaflight Throttle Curve Compensation

To make a 50g dry build feel closer to stock response on your transmitter sticks:

* **Throttle Mid (Midpoint):** Set to `0.25` (aligns the center of your control curve with your new hover point).
* **Throttle Expo:** Set to `0.15` (smooths out fine altitude adjustments around the hover point).




## mobula8 

- [[mobula8-dat]] - [[EX1103-dat]] - [[FPV-load-dat]] - [[Thrust-dat]]



- [[FPV-purpose-dat]] - [[FPV-types-dat]] - [[FPV-load-dat]] - [[indoor-fly-dat]]

- [[FPV-2.0in-dat]] == 85 mm - [[mobula8-dat]]

38g without [[camera-FPV-dat]]

![](2026-08-05-20-04-49.png)

[[camera-FPV-dat]] == 9g 

![](2026-08-05-20-05-22.png)


The stock analog camera on the Happymodel Mobula8 is the Caddx Ant Nano FPV Camera.  

Weight & Specs Comparison
| Component                    | Weight                   | Key Specs                                         |
| ---------------------------- | ------------------------ | ------------------------------------------------- |
| Stock Analog Cam (Caddx Ant) | ~2.0g – 2.7g (with wire) | 1200TVL resolution, 14x14mm nano size, 1.8mm lens |
| Your Current Camera          | 9.0g                     | ~6.3g to 7.0g heavier than stock                  |


- [[stand-dat]] == 3g

![](2026-08-05-20-05-38.png)


- Base Drone: 38g
- Camera: 9g
- Landing Gear / Ground Stands: 3g (0.75g each)
- Total Dry Weight: 50g

Performance Impact on a 2S 85mm Whoop

Stock Weight Reference: A factory analog Mobula8 weighs around 43g dry. At 50g, you are ~7g (or 16%) heavier than the base model.

All-Up Weight (AUW) with Battery:

- With a standard 2S 450mAh LiPo (~26g), your AUW is ~76g.

- With a 2S 550mAh LiPo (~29g), your AUW is ~79g.

- [[thrust-dat]]

`Flight Dynamics`: The EX1103 11000KV motors on the Mobula8 provide plenty of thrust for 50g dry weight. You will still have excellent power for outdoor freestyle and cruising, though aggressive punch-outs and freestyle recovers will feel slightly heavier.

Weight Optimization Recommendations

- Landing Gear: If you want to recover 3g easily, consider removing the ground stands and landing directly on the durable plastic ducts.

- Camera Mount: Ensure the 9g camera is mounted as close to the center of gravity as possible so it doesn't cause pitch bias.



## Can the BetaFPV Pavo25 (Bee25) Carry a 120g GoPro?

Yes, the **BetaFPV Pavo25** can carry a **120g GoPro** (like the HERO11 Mini), but **with limitations**.

---

### 🔋 Battery & Flight Time

- **Recommended battery**: 4S 650–850mAh LiPo
- **With a naked GoPro (~30g)**: ~4–5 minutes of flight
- **With a full GoPro (~120g)**: ~2–3 minutes of flight
- **Heavier load** = more power draw = **shorter flight time** and **higher heat**

---

### ⚙️ Hardware Requirements

- **Motors**: Stock 1404 4500KV can lift it, but performance drops
- **Battery**: Use a **high C-rate** (≥75C) to avoid voltage sag
- **Frame**: Strip off any unnecessary accessories to reduce weight

---

### 🛑 Potential Drawbacks

- **Increased ESC and motor temperature**
- **Reduced agility and climb rate**
- **Poor handling in wind**
- **Shorter battery life**
- **Risk of motor burnout** if pushed too hard

---

### ✅ Tips for Better Performance

- Use a **"naked GoPro"** (~30–35g) to lighten the load
- Fly in **calm weather**
- Limit aggressive maneuvers
- Consider switching to a **larger cinewhoop** (like Pavo30, Defender 25, or CineLog30)

---

### 📦 Summary

| Payload            | Flyable? | Flight Time | Notes                             |
| ------------------ | -------- | ----------- | --------------------------------- |
| Naked GoPro (~30g) | ✅ Yes    | ~4–5 min    | Best performance                  |
| Full GoPro (~120g) | ⚠️ Yes    | ~2–3 min    | Limited performance, extra strain |


## ref 

- [[FPV-dat]]