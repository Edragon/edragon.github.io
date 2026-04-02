
# SMT-Reflow-Soldering-dat

- [[pnp-machine-dat]] - [[solder-paste-dat]]


## Reflow Solder Paste Comparison: 183°C vs 138°C

### 🔧 1. Basic Alloy Differences

| Property                       | Sn63/Pb37         | Sn42/Bi58              |
| ------------------------------ | ----------------- | ---------------------- |
| **Type**                       | Tin–Lead eutectic | Low-temp bismuth-based |
| **Melting Point**              | **183 °C**        | **138 °C**             |
| **RoHS**                       | ❌ Not compliant   | ✅ RoHS compliant       |
| **Mechanical Strength**        | High              | Lower (more brittle)   |
| **Thermal Fatigue Resistance** | Good              | Moderate to poor       |
| **Cost**                       | Low               | Medium–high            |

---

### 🌡️ 2. Typical Reflow Profile Comparison

| Stage                         | Sn63/Pb37 (183 °C)      | Sn42/Bi58 (138 °C)      | Key Difference                       |
| ----------------------------- | ----------------------- | ----------------------- | ------------------------------------ |
| **Preheat**                   | 100–150 °C for 60–120 s | 80–110 °C for 60–120 s  | Lower ramp to avoid flux burnout     |
| **Ramp Rate**                 | 1–3 °C/s                | 0.5–2 °C/s              | Gentler ramp for Bi alloy            |
| **Soak (Flux Activation)**    | 150–170 °C for 60–120 s | 110–130 °C for 60–120 s | Lower soak temperature               |
| **Peak (Reflow)**             | 210–225 °C              | 160–170 °C              | ~50 °C lower peak                    |
| **Time Above Liquidus (TAL)** | 30–90 s                 | 30–90 s                 | Similar duration                     |
| **Cooling Rate**              | 2–4 °C/s                | 2–4 °C/s                | Avoid fast cooling to prevent cracks |

Sn63/Pb37

- preheat = 130C / 90s 
- soak = 160C / 60s
- peak = 220C 

### Optimized Reflow Profile (Lead-Free) == Sn63/Pb37 (183 °C)  

To ensure high-quality solder joints and minimize "dross" or solder beads, your profile should follow these specific timing and rate constraints:

| Phase | Temperature / Rate | Duration | Purpose |
| :--- | :--- | :--- | :--- |
| **Preheat** | 130°C | 90s | Evaporates solvents; prevents thermal shock. |
| **Soak** | 160°C | 60s | Activates flux; stabilizes board temperature. |
| **Ramp-to-Peak** | **1.5°C – 3°C / sec** | ~30s | Rapidly moves from soak to liquidus. |
| **Peak (TAL)** | **220°C - 235°C** | **30s – 60s** | Time Above Liquidus (TAL); ensures full wetting. |
| **Cooling** | **-3°C – -4°C / sec** | Until < 100°C | Rapid cooling creates a fine grain structure. |

---

### Critical Adjustments for your Profile:

1. **Time Above Liquidus (TAL):**
   For most lead-free pastes, the melting point is around **217°C**. Since your peak is **220°C**, you have a very narrow "window." 
   * **Advice:** Ensure the board actually stays above 217°C for at least **30 seconds**. If your oven has cold spots, you might want to bump the peak to **225°C** to ensure every joint melts fully.

2. **The Ramp-to-Peak Rate:**
   Once you leave the 160°C soak, you must heat up quickly. If you go too slow, the flux will "burn out" before the solder melts, leading to grainy joints or oxidation (dross). 

3. **Cooling is Often Forgotten:**
   Do not just leave the board in a closed oven to cool slowly. 
   * **Action:** Once the timer hits zero at peak, crack the oven door open slightly (if using a DIY toaster) to achieve a faster cooling rate. Fast cooling makes the solder joints **shiny and strong**; slow cooling makes them **dull and brittle**.



### ⚙️ 3. Process Considerations

| Factor                | Sn63/Pb37              | Sn42/Bi58                                                      |
| --------------------- | ---------------------- | -------------------------------------------------------------- |
| **Heat Sensitivity**  | Suitable for most PCBs | Safer for heat-sensitive components (e.g. LEDs, flexible PCBs) |
| **Joint Reliability** | Ductile, strong        | Brittle — not ideal for high vibration or stress               |
| **Storage Stability** | Good                   | Can age faster; store below 10 °C                              |
| **Rework Temp**       | ~250 °C                | ~180 °C                                                        | Easier to rework Bi-based solder |

---

### 🔍 4. When to Choose Each

- **Use 183 °C (Sn63/Pb37)** for:
  - Traditional boards
  - High mechanical or thermal cycling requirements
  - Non-RoHS projects

- **Use 138 °C (Sn42/Bi58)** for:
  - Low-temp, heat-sensitive assemblies (e.g. OLED, sensors, flex PCBs)
  - Second-stage soldering (after high-temp parts are mounted)
  - RoHS-compliant builds needing minimal thermal stress

---

### 🧭 5. Example Temperature Profile (for reference)

#### 🔹 Sn63/Pb37

   Preheat: 25 → 150 °C @ 2 °C/s
   Soak: 150–170 °C for 90 s
   Peak: 215 °C for 45 s (TAL ~60 s)
   Cool: 3 °C/s

#### 🔹 Sn42/Bi58

   Preheat: 25 → 110 °C @ 1.5 °C/s
   Soak: 110–130 °C for 90 s
   Peak: 165 °C for 45 s (TAL ~60 s)
   Cool: 2 °C/s






## Causes of Solder Splashes / Solder Balls After Reflow Soldering

### 1. Solder Paste Issues
- **Poor quality solder paste**: uneven particle size or wrong metal content.
- **Expired or improperly stored paste**: absorbs moisture, leading to solder spatter.
- **Excessive solder paste thickness**: too much solder causes overflow and splashes.

### 2. PCB and Component Cleanliness
- **Contaminated PCB surface**: dust, oil, or oxidation reduces flux activity.
- **Oxidized component leads or pads**: poor wetting leads to solder residues.

### 3. Reflow Process Parameters
- **Ramp-up too fast**: flux or moisture evaporates explosively, causing solder balls.
- **Insufficient preheat zone**: solvents not fully evaporated, bursting in reflow zone.
- **Peak temperature too high / soak too long**: excessive solder fluidity, splashes out.

### 4. Printing and Placement Process
- **Stencil design issues**: oversized or wrong-shaped apertures release too much solder.
- **Uneven printing**: paste smearing, stringing, or overflow.
- **Component misplacement**: misaligned parts squeeze solder during reflow.

---

### ✅ Solutions
1. Use high-quality solder paste, store under low temperature and dry conditions.
2. Optimize stencil aperture design and control paste thickness.
3. Adjust reflow oven profile:
   - Sufficient preheat for solvent/moisture removal.
   - Avoid temperature overshoot in peak zone.
4. Keep PCB and components clean, reduce oxidation.
5. Check placement machine accuracy to avoid component shift.






# PCBA-reflow-dat

- [[PCBA-reflow]] - [[PCBA]]

# PCB Reflow Oven Heat Profile Steps

| Step          | Temperature Range | Duration       | Purpose                                                   |
| ------------- | ----------------- | -------------- | --------------------------------------------------------- |
| Preheat       | ~150°C to ~180°C  | 60–120 seconds | Gradually warms the PCB, activates flux, removes moisture |
| Soak          | ~180°C to ~200°C  | 60–120 seconds | Evens out temperature across the PCB                      |
| Reflow (Peak) | ~230°C to ~250°C  | 30–90 seconds  | Solder melts, forms proper joints                         |
| Cooling       | Down to ~50°C     | 60–120 seconds | Solidifies solder joints, avoids thermal shock            |




## ref 

