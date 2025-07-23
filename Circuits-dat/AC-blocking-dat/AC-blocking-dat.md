
# AC-blocking-dat

## Types of AC Blocking Components

**AC blocking components** are used to **prevent AC signals from passing** while **allowing DC** to flow. These are useful in filtering, power supply, and signal control applications.

---

### 1. **Inductors (Coils) 🧲**

- **Function:** Oppose changes in current, especially high-frequency AC.
- **Blocks:** AC signals (especially high frequency), passes DC.
- **Usage:** 
  - Power supply filtering
  - Chokes in DC lines
  - EMI suppression

---

### 2. **Ferrite Beads**

- **Function:** Similar to inductors; resist high-frequency AC noise.
- **Blocks:** High-frequency AC interference
- **Passes:** DC and low-frequency signals
- **Usage:** Noise filtering in power lines and signal lines

---

### 3. **Low-Pass Filters (RC or LC)**

- **Function:** Combine resistors and capacitors/inductors to block AC above a certain frequency.
- **Blocks:** High-frequency AC
- **Passes:** DC or low-frequency signals
- **Usage:** Signal conditioning, analog circuits

---

### 4. **Zener Diodes or TVS Diodes (for AC spikes)**

- **Not direct AC blockers**, but suppress voltage spikes (AC noise).
- **Usage:** Surge protection on DC lines.

---

## Summary Table

| Component       | Blocks AC | Passes DC | Common Use Case               |
|------------------|-----------|-----------|--------------------------------|
| Inductor         | ✅        | ✅        | DC line filtering, power supply |
| Ferrite Bead     | ✅        | ✅        | High-frequency noise suppression |
| Low-Pass Filter  | ✅ (partial) | ✅     | Signal smoothing, power rails   |
| Zener/TVS Diode  | ✅ (spikes) | ✅     | Surge protection                |

> 🧲 **Inductors** are the most direct and widely used components for **AC blocking** while passing DC.

## ref 

- [[circuits-dat]]