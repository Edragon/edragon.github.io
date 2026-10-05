

# Heat-Dissipation-dat




- [[heatsink-dat]] - [[heat-dissipation-dat]] - [[fan-dat]] - [[thermal-dat]]

- [[silicon-grease-dat]]

- [[TPLINK-dat]]



## Solutions

### 1. Basic formula (this is the only one you really need)

TJ = TA + P × Θja
     ↑       ↑    ↑
   Junction temperature    Ambient temperature    Junction-to-ambient thermal resistance (°C/W)
        ↓
Temperature rise: ΔT = P × Θja


⭐️ Key point: Θja (thermal resistance) is the deciding factor — and it depends on the package + PCB copper area.

---

### 2. Temperature rise of a 1W chip (typical measured / datasheet values)

SOT-23 (no thermal pad)      Θja 250 → temperature rise 250°C ⚠️ (it may actually burn; power must be limited)
SOT-23 (large copper area)    Θja 120 → temperature rise 120°C
SOIC-8 (ordinary)             Θja 160 → temperature rise 160°C
SOIC-8 (large copper area)    Θja  90 → temperature rise  90°C
QFN (exposed pad + thermal land) Θja  60 → temperature rise  60°C ✅
DPAK / TO-252                 Θja  55 → temperature rise  55°C ✅
TO-220 (without heatsink)     Θja  60 → temperature rise  60°C
TO-220 (with small heatsink)  Θja  25 → temperature rise  25°C ⭐️


⭐️ Short answer to your question:

A typical 1W chip mounted on a normal PCB with a thermal pad or copper area will rise about 60–120°C.
Take the middle value: ~80–100°C (ambient 25°C → junction temperature 105–125°C ⚠️)

⚠️ Notes:
• The calculation above is for junction temperature TJ, not case temperature.
• Small packages without a thermal path cannot handle 1W — the actual power must be limited.
• This is why a "5V 0.2A LDO" often feels too hot to touch.

---

### 3. How much can a small fan reduce it? (key answer)

Baseline: Θja 100 °C/W → 1W temperature rise 100°C (surface about 125°C)

Light airflow (not direct blowing)      → temperature rise 75°C   reduction 25%
⭐️ Small fan direct blow (30–40mm)     → temperature rise 55°C   reduction ~45%
⭐️ Small fan + heatsink                → temperature rise 40°C   reduction ~60%
High airflow / effective ducting       → temperature rise 25°C   reduction ~75%


⭐️ Direct answer:

Adding one small fan for direct cooling can reduce temperature rise by 40–55%
(100°C → 55°C, absolute reduction about 40–45°C)
Adding a small heatsink as well can reduce it by 60% (100°C → 40°C)

---

### 4. Why are fans so effective? (physical reason)

Convection heat transfer coefficient h:
  Natural convection (hot air rises)   h ≈ 5–10 W/(m²·K)
  Forced convection (fan blowing)      h ≈ 25–100 W/(m²·K)
        ↓
⭐️ h increases by 3–10× → thermal resistance drops proportionally
        ↓
So from "no airflow" to "with airflow" is a qualitative change,
while from "with airflow" to "more airflow" is a gradual change (diminishing returns)


⭐️ Engineering experience: the first step in thermal improvement is always to "get the air moving," which is more effective than simply using a larger heatsink.

---

### 5. Practical recommendations (for your 1W case)

1. Check the copper area first: add copper around the chip pad and use vias to the backside ground plane.
   → This is free, and it can reduce Θja from 250 to 90–120.

2. Add a small fan (5V, 30–40mm, very cheap).
   → Directly blow on the chip / heatsink to reduce another 40–55%.

3. Add an aluminum heatsink (with thermal silicone).
   → Together with the fan, the total reduction can reach 60%.

4. Watch for thermal traps:
   • Do not put the board inside a sealed enclosure (the fan becomes useless)
   • Do not reverse the fan direction (exhaust is okay, but there must be an inlet)
   • Do not let the airflow blow directly onto temperature-sensitive components (crystals / sensors)


---

### 6. One-line summary

1W chip temperature rise:
  Small package without heat dissipation → 120–250°C (cannot handle it; it may burn)
  Normal PCB → ~80–100°C  ← ⭐️ most common answer
  Good thermal layout → 55–60°C

With a small fan:
  ⭐️ Direct airflow → reduction 40–55% (≈ 40°C absolute drop)
  ⭐️ Fan + heatsink → reduction 60%
  ⭐️ Effective airflow path → reduction 75%

Formula: ΔT = P × Θja    |    Junction temperature TJ = TA + ΔT
⚠️ This is the junction temperature; the chip datasheet Tj(max) is typically 125–150°C




## Design

- [[Hi3516-dat]] Power consumption about 1–2W → heatsink / thermal pad; the temperature rise inside a closed enclosure will increase sensor dark current (more thermal noise points).






## Thermal Conductivity Comparison: 1.0 vs 2.3

---

## 1. Concept of Thermal Conductivity
- **Thermal conductivity (k)** is usually measured in W/(m·K).  
- **Higher k → better heat transfer** (heat moves faster).  
- **Lower k → worse heat transfer → better insulation**.

---

## 2. Comparison
- **1.0 vs 2.3:**  
  - 2.3 conducts heat faster than 1.0.  
  - 1.0 has slower heat transfer, so it provides better insulation.

---

## 3. Air as a Reference
- Air: k ≈ 0.024 W/(m·K) (very low, excellent insulation).  
- So both 1.0 and 2.3 are much higher than air.

---

## 4. Choosing Based on Application
- **Need heat dissipation → choose 2.3**  
- **Need insulation → choose 1.0**


## ref 

- [[waterproof-dat]] - [[silicon-grease-dat]]