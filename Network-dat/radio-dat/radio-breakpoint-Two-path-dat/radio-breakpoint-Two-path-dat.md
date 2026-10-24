

# radio-breakpoint-Two-path-dat


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

