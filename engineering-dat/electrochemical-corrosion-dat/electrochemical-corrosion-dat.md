# electrochemical-corrosion-dat


- [[oil-mineral-dat]] - [[oil-soaking-dat]]  

##  What actually works (ranked by effectiveness)

✅ 1. Remove the water source (most critical)

Vacuum bake PCB before coating (e.g. 80–100 °C, many hours)

Dry mineral oil before use

Seal the oil container

Without this, no coating will succeed.

✅ 2. Eliminate wet components

Replace electrolytic capacitors with:

Solid polymer capacitors

Ceramic capacitors

This alone often stops the problem.

✅ 3. Use a true moisture barrier (if immersion is required)

Conformal coatings are insufficient. Better options:

Parylene (C) coating (near-hermetic)

Fully potted power section (epoxy or silicone gel)

- [[PCB-potted-dat]] - [[oil-soaking-dat]]


## 4. Oil immersion changes coating behavior

In mineral oil:
- Coatings can swell or soften
- Adhesion to copper decreases
- Micro-cracks form (not visible)

These micro-paths are enough for ion migration.

---

## 5. Why green deposits can appear “on top” of coating

What often happens:
- Copper ions migrate under the coating
- They precipitate at coating defects or edges
- The deposit appears external, but origin is beneath

---

## 6. This confirms the dominant mechanism

This behavior strongly confirms:
```text
Electrochemical Migration (ECM)
driven by:
- trapped moisture
- continuous DC bias
- electrolyte vapor from capacitors
```



## Unsealed oil = moisture absorption (major cause)

Since the oil is not sealed:

Mineral oil slowly absorbs moisture from air

Humidity continuously diffuses into the oil

Daily temperature changes cause condensation

⚠️ This creates a persistent micro-electrolyte environment.




**This is very likely NOT classic electrolysis.**  
It is most likely **electrochemical corrosion combined with ion migration**, caused by **trace water and contaminants** in the mineral oil, and it is **most visible at the power-supply area**.

---

## Overview

The green buildup observed on PCBs immersed in mineral oil is primarily a form of copper corrosion driven by electrochemical processes enabled by trace moisture and contaminants. It is most apparent near the power input where electric fields and current densities are high.

---

## 1. Why does green residue appear?

Green deposits on PCBs are **typically copper corrosion products**, such as:

- Basic copper carbonate (verdigris)
- Copper oxides / hydroxides
- Copper salts
- Copper soaps (reaction between copper and degraded oil additives)

These deposits commonly appear:
- Green or blue-green in color
- Powdery or paste-like in texture

---

## 2. Can mineral oil itself undergo electrolysis?

**Pure mineral oil cannot be electrolyzed**, because it:
- Is non-polar
- Is electrically insulating
- Contains no free ions

However, **real systems are never perfectly pure** — trace water and contaminants can enable electrochemical reactions.

---

## 3. Key real-world causes (most important)

### 3.1 Trace moisture (critical factor)

Even very small amounts of water can come from:
- Air humidity
- Cable interfaces and connectors
- Leakage or outgassing from electrolytic capacitors
- Moisture absorbed by PCB materials

Once **water + voltage + metal** are present,  
**electrochemical reactions become possible**.

---

### 3.2 Strong electric field at the power section

The issue is often **at the power input**, which is typical because:
- Voltage is highest
- Current density is highest
- Electric field gradient is strongest

This promotes:
- **Electrochemical Migration (ECM)**
- Localized corrosion

This is similar in mechanism to electrolysis, but **not a true electrolyte bath**.

---

### 3.3 Mineral oil contamination and aging

Over long-term immersion:
- Mineral oil can oxidize slowly
- Sulfur compounds or organic acids may form
- These react with copper surfaces

Result:
- Formation of green copper compounds

---

## 4. Is this electrolysis?

Strictly speaking:

❌ **Not electrolysis in pure mineral oil**  
✅ **Electrochemical corrosion + ion migration enabled by moisture and contaminants**

Common engineering terms:
```text
Electrochemical corrosion
Electrochemical Migration (ECM)
Copper corrosion in insulating oil
```

---

## 5. Why is the residue green?

Because PCB traces and pads are mainly copper, and copper corrosion products are naturally green or blue-green.

---

## 6. Is it dangerous or progressive?

⚠️ Yes, it can worsen if left untreated.

Possible risks:
- Continued corrosion
- Conductive dendrite growth
- Increased contact resistance
- Leakage currents
- Short circuits

Risk is highest under continuous power and in sealed oil immersion where moisture and contaminants persist.

---

## 7. Mitigation (high-level, safe recommendations)

- Avoid exposed bare copper
- Apply conformal coating on critical areas
- Minimize moisture ingress (sealed system)
- Thoroughly dry PCBs before immersion
- Use electronics-grade mineral oil or transformer oil

---

## Summary

The green buildup is not classic electrolysis, but moisture-enabled electrochemical corrosion that is intensified at the power section. Drying, contamination control, and protective coatings reduce risk and slow or prevent progression.
