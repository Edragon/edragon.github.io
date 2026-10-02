


# robot-target-following-dat

- [[robot-dat]] - [[robot-target-following-dat]]


- [[robot-target-following-dat]] - [[band-dat]] - [[band-UWB-dat]] - [[sensor-TOF-dat]] 

- [[AOA-dat]] - [[PDOA-dat]]


## 📡 1. What is UWB

**UWB = Ultra-Wideband**

```text
Uses extremely short pulses with ≥500 MHz bandwidth (NOT carrier modulation)
Frequency band: 3.1–10.6 GHz (commonly 6.5 / 8 GHz)
```

**Why it is good for positioning:**

1. **Very short pulses** (sub-nanosecond) → ⭐️ extremely high time resolution → centimeter-level ranging
2. **Wide bandwidth** → ⭐️ multipath resistance (multipath can be separated in time)
3. **Low power spectral density** → coexists well with other wireless systems
4. **Fairly strong penetration** (can pass through walls, but attenuated)

**Mainstream chips:** ⭐️ DW1000 / DW3000 (Qorvo, formerly DecaWave)

---

## 🧭 2. The Four Positioning Principles (know the family first)

### ① TOF / TWR (Two-Way Ranging)

```text
Measure the signal's round-trip time
        ↓
Distance = Time × Speed of light ÷ 2
        ↓
One measurement = only a 【distance】 (1 circle)
        ↓
Needs 3–4 anchors to determine a position
```

- ✅ High accuracy · ❌ Requires multiple points

### ② TDOA (Time Difference of Arrival)

```text
Multiple anchors measure the arrival time difference of the SAME signal
        ↓
Hyperbolic positioning
```

- ✅ Tag only transmits, never receives (power-saving / high capacity)
- ❌ Anchors must be **time-synchronized**

### ③ ⭐️ AOA (Angle of Arrival)

```text
Measure 【which direction】 the signal comes from → obtain an 【angle】
```

- ✅ ⭐️ A single base station can measure direction
- ❌ Requires an antenna array + is multipath-sensitive

### ④ ⭐️ PDOA (Phase Difference of Arrival)

```text
A concrete implementation of AOA (using 【phase difference】 to compute angle)
```

- ✅ Simple hardware, low power
- ❌ Limited by baseline (less accurate than a large array)

⭐️ **Key point:** TOF measures "how far", AOA/PDOA measures "which direction".

---

## 🎯 3. AOA (Angle of Arrival) in Detail

**Principle:**

```text
Use a 【multi-antenna array】 to receive the same signal
        ↓
Signals received by each antenna have a 【phase difference / time difference】
        ↓
Back-calculate the incoming angle θ
```

**Characteristics:**

- ✅ ⭐️ One base station is enough to measure direction (no multiple anchors)
- ✅ Can be fused with other methods (TOF) → gives "direction + distance" directly
- ❌ ⚠️ Requires an **antenna array**: multiple antennas + strict phase consistency
- ❌ ⚠️ Multipath is the deadliest: reflected signals "fool" the angle estimate
- ❌ ⚠️ Angular error grows with distance (lateral error ≈ distance × angular error)

**Implementation methods:** phase interferometry (PDOA) · MUSIC · beamforming

---

## 📐 4. PDOA (Phase Difference of Arrival) in Detail

⭐️ **PDOA is the "two-antenna simplified version" of AOA.**

**Math core:**

```text
Antenna spacing d
        ↓
Path difference Δr of the same signal arriving at the two antennas
        ↓
Phase difference Δφ = 2π × Δr / λ
        ↓
Angle θ = arcsin( Δφ × λ / (2π × d) )
```

In formula form:

$$
\Delta\phi = \frac{2\pi \cdot \Delta r}{\lambda}
\qquad\Rightarrow\qquad
\theta = \arcsin\!\left(\frac{\Delta\phi \cdot \lambda}{2\pi d}\right)
$$

**⭐️ Key constraint: d must be < λ/2**

```text
If d > λ/2 → phase difference > 2π → ⭐️ angle 【ambiguity / multiple solutions】 ⚠️
        ↓
So PDOA uses a 【short baseline】 (e.g. 2.4–3 cm @ 6.5 GHz)
        ↓
⭐️ Accuracy is limited by antenna spacing → worse than a large array
```

**Pros and cons:**

- ✅ Simple hardware (2 antennas + phase measurement)
- ✅ Low power, low cost, small size
- ⚠️ Limited accuracy (short baseline)
- ⚠️ Requires phase calibration (antenna / trace length differences)
- ⚠️ Multipath-sensitive

⭐️ **The DW3000 chip natively supports PDOA mode → a popular choice for auto-following solutions.**

---

## 🚗 5. How an Auto-Following Cart Uses It

```text
【Tag B】 carried by the target (person / object)
        ↓ UWB pulses
【Base station A】 mounted on the cart (with antenna array)
        ↓
① PDOA computes ⭐️【target bearing angle】
② TOF computes ⭐️【distance】
        ↓
Cart controller:
  • Turn toward the target (bearing angle)
  • Maintain the set distance (follow / stop)
        ↓
⭐️ Target moves → cart keeps following
```

**⭐️ Why must AOA/PDOA be used?**

```text
Pure TOF: a single base station only knows "how far", not "which direction"
        → infinitely many solutions on a circular locus ❌
        ↓
⭐️ PDOA: a single base station gives 【direction + distance】 at once
        → one base station on the cart is enough ✅
        (otherwise 3–4 anchors would be needed on the cart — cost/size infeasible)
```

---

## 📊 6. Solution Comparison

### Accuracy

| Method | Accuracy |
| --- | --- |
| TOF/TWR (multiple anchors) | 10–30 cm ⭐️ highest |
| TDOA (synchronized anchors) | 10–30 cm |
| ⭐️ PDOA (two antennas) | angle ±a few degrees (good at close range, large lateral error at long range) |

### Cost / Complexity

| Method | Cost / Complexity |
| --- | --- |
| TOF, multiple anchors | High (needs 3–4 synchronized anchors) |
| TDOA | High (requires time synchronization) |
| ⭐️ PDOA | ⭐️ Lowest (2 antennas + DW3000, ready to use) |

### Applicability

| Method | Applicability |
| --- | --- |
| TOF, multiple anchors | Indoor positioning systems (UWB base-station network) |
| TDOA | Large-area tag tracking (warehousing / people) |
| ⭐️ PDOA | ⭐️ Auto-following (suitcases / carts / robots) |

---

## ⚠️ 7. Pitfalls in Practice

1. **Multipath ⭐️ the biggest enemy**
   - Indoor metal / wall reflections → angle jumps
   - Countermeasures: antenna layout · algorithmic filtering · time gating (take the first-arriving path)

2. **Antenna calibration ⭐️ mandatory for PDOA**
   - Inconsistent antennas / trace lengths → fixed phase offset → angle deviation
   - Must be calibrated at the factory / on power-up

3. **Tag orientation**
   - The tag antenna is directional → when the target turns, the signal weakens / the angle drifts
   - Countermeasures: omnidirectional antenna + multi-antenna diversity

4. **Antenna spacing design**
   - < λ/2 (to avoid ambiguity) · but as large as possible (to improve accuracy)
   - Commonly 2.4–3 cm @ 6.5 GHz

5. **Refresh rate vs. accuracy**
   - High refresh rate (following needs 10–50 Hz) · but single samples are noisy → filtering required (Kalman)

---

## 📌 One-Sentence Summary

```text
UWB    = Ultra-Wideband ranging technology (centimeter-level) · chips DW1000/DW3000
TOF    = measures "how far" (needs multiple anchors)
AOA    = measures "which direction" (needs an antenna array)
PDOA   = the two-antenna implementation of AOA (phase difference → angle), ⚠️ baseline < λ/2
        ↓
⭐️ Auto-following cart = PDOA for direction + TOF for distance
   → a single base station can follow a person
```



## ref 