

# radio-breakpoint-Two-path-dat



- [[radio-dat]] - [[radio-FSPL-dat]] - [[radio-breakpoint-Two-path-dat]]



一句话答案：自由空间段更好（衰减慢一倍），但你在哪一段不是你能选的

---

一、两段到底是什么

① 自由空间段（20log 律）
损耗只来自"能量向四面八方扩散"（和你手电筒照远处变暗一个道理）
        ↓
距离翻倍 → −6 dB
公式：FSPL = 32.45 + 20log(f) + 20log(d)


② 40log 陡坡（双径远场）
地面反射波与直达波几乎完全【反相】→ 互相抵消
剩下的只是"抵消不彻底"的那一丁点残余能量
        ↓
功率 ∝ 1/d⁴ → 距离翻倍 → ⭐ −12 dB（衰减速度快一倍）
公式：L = 40log(d) − 20log(h₁) − 20log(h₂)   ← 注意：里面没有频率项


为什么会分成两段（心理图）
近距离：反射波多走的距离 = 几百个波长
        → 相位差乱转 → 干涉剧烈振荡（有深零点，也有增益峰）
        → 平均趋势 ≈ 自由空间损耗

远距离：路径差越来越趋近 0
        → 反射波几乎完全反相 → 抵消 → 只剩残余
        → 进入 1/d⁴ 的陡坡


---

二、分界线 = 断点 d_bp

d_bp = 4π·h₁·h₂ / λ  ≈ 12.6 · h₁ · h₂ / λ

飞机 120m / 地面 1.5m：
   2.4GHz  → 18.1 km
   915MHz  →  6.9 km
        ↓
⭐ 断点由【高度 + 频率】决定，与发射功率【完全无关】


---

三、哪个更好？—— 自由空间段，差距实打实

提升量        自由空间段(20log)    40log 陡坡      价值差
  +3 dB          ×1.41             ×1.19          1.2 倍
  +6 dB          ×2.00             ×1.41          1.4 倍
 +10 dB（功率×10） ×3.16            ×1.78          1.8 倍
 +20 dB（功率×100）×10.00           ×3.16          3.2 倍
        ↓
⭐ 同样的功率/同样的天线，在自由空间段的价值是陡坡段的 1.2-3.2 倍
⭐ 这就是"为什么在陡坡里加功率特别不划算"的量化解释


---

四、⭐⭐ 反直觉：频率越高，越容易"待在好段"

断点 ∝ 1/λ → 频率越高，断点越远
   2.4G：18.1 km   ｜  900M：6.9 km
        ↓
距离      2.4G 损耗／状态        900M 损耗／状态
 2 km    106.1 dB  自由空间       97.7 dB  自由空间
 5 km    114.0 dB  自由空间      105.7 dB  自由空间
10 km    120.1 dB  自由空间      114.9 dB  ⭐已进陡坡
20 km    126.9 dB  陡坡         126.9 dB  陡坡
40 km    139.0 dB  陡坡         139.0 dB  陡坡
        ↓
⭐ 在 7-18 km 这段，900M 已经在陡坡里跑，2.4G 还在自由空间段
   → 所以这个区间加功率，2.4G 的效率反而更高
   → 900M 的优势主要来自【遮挡绕射】和【近中距离】，不是开阔远距离


---

五、⭐⭐ 最实用的推论：如果你只飞 5 km，抬高度毫无收益

理想平地、无遮挡，2.4G：
   高度  50 m → 断点 7.5 km  → 5km 处：自由空间段（抬高无收益）
   高度 120 m → 断点 18.1 km → 5km 处：自由空间段（抬高无收益）
   高度 300 m → 断点 45.2 km → 5km 处：自由空间段（抬高无收益）
   高度1000 m → 断点 150.8 km→ 5km 处：自由空间段（抬高无收益）
        ↓
⭐ 5km 内，抬高天线在"双径衰减"这个账本上是【一分钱收益都没有】
   这段距离内真正有效的是：加功率、加天线增益、降包率


⚠️ 但要说清楚：这是"理想平地无遮挡"的结论。真实环境里抬高天线依然有价值 ——
因为那时你解决的是遮挡/菲涅尔区问题，不是双径衰减律问题。这两件事不能混。

---

六、判断口诀（怎么用这两段做决策）

① 先算断点：d_bp ≈ 12.6 × h₁ × h₂ / λ
② 目标距离 < 断点  → 你在自由空间段
      → 加功率/加增益效率最高（+6dB = ×2）
      → 抬高度对这个账本没用
③ 目标距离 > 断点  → 你在陡坡
      → ⭐ 抬高度/飞更高最划算（推远断点）
      → 加功率效率减半（+6dB 只 ×1.41）
④ 有遮挡            → 以上都次要，先解决视线（低频绕射/定向天线）


---

📋 一句话总结

自由空间段 = 损耗按"距离翻倍 −6dB"走      ← 好，你希望的
40log 陡坡 = 损耗按"距离翻倍 −12dB"走      ← 差，被地面反射抵消拖累

分界点 = 断点（由高度和频率决定，功率改不了）
        ↓
⭐ "哪个更好"：当然自由空间段。
   但真正的战术含义是：
   · 近处加功率划算（自由空间段）
   · 远处抬高最划算（把陡坡推远）
   · 5km 以内，高度这件事可以直接忽略





### 1. First, what "two-path" means

Scenario: the aircraft is up in the sky, you are on the ground

The receiver gets **two** waves at the same time:

- ① Direct wave ─── travels in a straight line
- ② Reflected wave ─── hits the ground first, then bounces back up (travels a longer path)

The two waves arrive with **different phase** → they superpose:

- In phase → they add up, the signal gets stronger
- Out of phase → they cancel, the signal gets weaker

---

### 2. The key point: how the path difference varies with distance

Path difference:

```
Δ ≈ 2 · h₁ · h₂ / d        (h₁ = aircraft height, h₂ = antenna height, d = horizontal distance)
```

Short range (small d) → Δ is large (tens of wavelengths)
→ the phase difference swings wildly with distance → violent interference oscillation → ⭐ a series of "nulls" appears

Long range (large d) → Δ → 0
→ the two paths become almost the same length → and ground reflection flips the phase by 180°
→ ⭐ the direct and reflected waves **almost completely cancel each other**

This is the core of the whole thing: once you fly far, the ground-reflected wave no longer "helps" — it exists specifically to cancel the direct wave.

---

### 3. The "breakpoint" is where the attenuation law **changes gear**

Inside the breakpoint (short range): attenuation follows free space

```
doubling the distance → −6 dB        (20log law)
```

Beyond the breakpoint (long range): the reflected wave almost completely cancels the direct wave

```
received power ∝ (path difference)² ∝ 1/d⁴
doubling the distance → ⭐ −12 dB     (40log law)
```

⭐⭐ "Breakpoint" = the distance at which attenuation switches from 20log to 40log

**Formula**

```
d_bp = 4π · h₁ · h₂ / λ
```

> Textbooks often write it as `4 · h₁ · h₂ / λ`, differing only by the convention factor π ≈ 3.14;
> in the real world it is not a knife edge but a "transition region".

Physical meaning: breakpoint ∝ antenna height / wavelength

- Higher antenna → farther breakpoint (larger reflected path difference, so cancellation arrives later)
- Higher frequency (smaller λ) → farther breakpoint

---

### 4. Worked numbers (your scenario, 2.4 GHz)

| Case | Breakpoint `d_bp` |
|---|---:|
| Aircraft 120 m / ground 1.5 m | 18.1 km |
| Aircraft 50 m | 7.5 km |
| Aircraft 200 m | 30.2 km |

**What the real curve looks like (`h_t` = 120 m)**

| Distance | Exact two-ray (with interference) | Piecewise model (my calc) | Pure free space | Note |
|---:|---:|---:|---:|---|
| 0.1 km | 68.4 dB | 74.0 dB | 74.0 dB | |
| 0.2 km | 80.5 | 86.1 | 86.1 | |
| 0.5 km | 91.3 | 94.0 | 94.0 | |
| 1.0 km | 102.7 | 100.1 | 100.1 | |
| 2.0 km | 100.2 | 106.1 | 106.1 | ← interference peak (actually better) |
| 4.0 km | 108.3 | 112.1 | 112.1 | |
| 8.0 km | 113.0 | 118.1 | 118.1 | |
| 18.1 km | 125.5 | 125.2 | 125.2 | ← breakpoint, model matches measurement |
| 25 km | 131.0 | 130.8 | 128.0 | ← now clearly worse than free space |
| 40 km | 139.1 | 139.0 | 132.1 | ← 7 dB more loss than free space |

> ⭐ Beyond the breakpoint the real loss increasingly "beats" free space (40log is twice as steep as 20log)

**Near-field interference nulls (the source of "the signal comes and goes")**

Within the first 300 m there is a deep null every few tens of metres (−10 to −20 dB dips).
Examples: 21 m / 30 m / 40 m / 60 m / 80 m / 103 m / 144 m / 193 m / 263 m …

> ⭐ When flying low and close, the video link sometimes "glitches for no apparent reason and then recovers" — usually it is not the hardware, you just hit one of these nulls (moving 1 m in height or position makes it disappear)

---

### 5. ⭐⭐ Three most common misunderstandings

**① The breakpoint is not a "wall"**

It is not the point where the signal suddenly dies, and it is not a physical barrier.
It is only where attenuation gets steeper; the transition is continuous either side (with residual oscillation in between).

**② Power *cannot* move the breakpoint** ⭐⭐

Adding power → only lets you travel farther on the **same attenuation law**.
Changing height / frequency → that is what changes the **attenuation law itself**.

Which is why:

- At 50 m, going from 1 W to 10 W (+10 dB) only buys range ×1.78
- But raising the height from 50 m to 120 m (breakpoint 7.5 → 18.1 km) buys ×1.4~1.5 with no extra power draw

**③ Beyond the breakpoint it is not "hopeless the farther you go"**

40log is only a steeper slope, not a cliff.
In the 40log region, every +6 dB gives range ×1.41 (not ×2).

---

### 6. Why I bring it up every time (practical conclusions)

**① Explains "why 10× the power only gives 77% more range"**
→ because you are beyond the breakpoint, paying the 40log rate

**② Explains "why raising the antenna / flying higher is the best value"**
→ it pushes the breakpoint out, turning 40log segments into 20log segments — you switched to a cheaper price list

**③ Explains "why low-altitude video breaks up at 200 m"**
→ near-field interference nulls + entering the 40log region early

**④ Deciding whether to add power:**
push the breakpoint past the target distance first, then talk about power — doing it in the opposite order wastes money

---

### 📋 One-sentence summary

The two-path breakpoint is the distance at which the ground-reflected wave starts to *specifically cancel* the direct wave.

- Before it, attenuation runs at "−6 dB per doubling of distance" (20log)
- After it, attenuation runs at "−12 dB per doubling of distance" (40log)

```
d_bp = 4π · h₁ · h₂ / λ     →  the higher the antenna and the higher the frequency, the farther the breakpoint
```

> ⭐ It is the "price-list switch point for the power trade": adding power inside the breakpoint is a good deal; adding power outside it is a bad deal

## ref

