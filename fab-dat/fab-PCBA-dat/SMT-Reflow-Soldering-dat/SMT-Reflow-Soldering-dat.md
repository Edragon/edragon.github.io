
# SMT-Reflow-Soldering-dat

- [[pnp-machine-dat]]


## Reflow Solder Paste Comparison: 183°C vs 138°C

### 🔧 1. Basic Alloy Differences

| Property | Sn63/Pb37 | Sn42/Bi58 |
|-----------|------------|-----------|
| **Type** | Tin–Lead eutectic | Low-temp bismuth-based |
| **Melting Point** | **183 °C** | **138 °C** |
| **RoHS** | ❌ Not compliant | ✅ RoHS compliant |
| **Mechanical Strength** | High | Lower (more brittle) |
| **Thermal Fatigue Resistance** | Good | Moderate to poor |
| **Cost** | Low | Medium–high |

---

### 🌡️ 2. Typical Reflow Profile Comparison

| Stage | Sn63/Pb37 (183 °C) | Sn42/Bi58 (138 °C) | Key Difference |
|--------|--------------------|--------------------|----------------|
| **Preheat** | 100–150 °C for 60–120 s | 80–110 °C for 60–120 s | Lower ramp to avoid flux burnout |
| **Ramp Rate** | 1–3 °C/s | 0.5–2 °C/s | Gentler ramp for Bi alloy |
| **Soak (Flux Activation)** | 150–170 °C for 60–120 s | 110–130 °C for 60–120 s | Lower soak temperature |
| **Peak (Reflow)** | 210–225 °C | 160–170 °C | ~50 °C lower peak |
| **Time Above Liquidus (TAL)** | 30–90 s | 30–90 s | Similar duration |
| **Cooling Rate** | 2–4 °C/s | 2–4 °C/s | Avoid fast cooling to prevent cracks |

---

### ⚙️ 3. Process Considerations

| Factor | Sn63/Pb37 | Sn42/Bi58 |
|--------|------------|------------|
| **Heat Sensitivity** | Suitable for most PCBs | Safer for heat-sensitive components (e.g. LEDs, flexible PCBs) |
| **Joint Reliability** | Ductile, strong | Brittle — not ideal for high vibration or stress |
| **Storage Stability** | Good | Can age faster; store below 10 °C |
| **Rework Temp** | ~250 °C | ~180 °C | Easier to rework Bi-based solder |

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


