

# oil-mineral-dat.md

- [[oil-soaking-dat]]


## Mineral Oil vs Air: Thermal Conductivity & Cooling Performance Comparison

### 1. Thermal Conductivity (W/m·K)
| Medium        | Thermal Conductivity | Meaning |
|---------------|----------------------|---------|
| **Air**       | ~0.024               | Very low heat transfer |
| **Mineral Oil** | ~0.12–0.15         | About 5–6× better than air |

**Conclusion:**  
Mineral oil transfers heat better than air *through direct conduction*.

---

### 2. Heat Capacity (kJ/kg·K)
| Medium        | Heat Capacity | Meaning |
|---------------|---------------|---------|
| **Air**       | ~1.0          | Low heat storage |
| **Mineral Oil** | ~1.6–2.0    | Can absorb more heat per unit mass |

**Conclusion:**  
Mineral oil absorbs more heat before increasing temperature.

---

### 3. Convection (Cooling by Moving Fluid)
#### Air
- Very low viscosity → moves easily  
- Natural convection is strong  
- Fans blow heat away efficiently  
**Air = Good for passive cooling**

#### Mineral Oil
- High viscosity → moves slowly  
- Natural convection is weak  
- If not pumped, heat accumulates near the chip  
**Oil = Poor natural convection unless circulated**

---

### 4. Real-World Cooling Performance

#### With active flow (fan/pump)
**Mineral Oil > Air**
- Lower operating temperature  
- Used in oil-cooled servers & transformers  

#### With no movement (sealed container)
**Mineral Oil < Air**
- Heat gets trapped around components  
- Components overheat in small electronics  
- Can cause long-term damage to chips & capacitors  

---

### 5. Final Conclusions

- **For passive cooling:**  
  Air cools better because it convects well.

- **For active cooling (oil pump or circulation):**  
  Mineral oil cools better due to superior conduction & heat absorption.

- **For small electronics in still oil:**  
  Mineral oil can **cause overheating**, because heat cannot escape from the local area.


## cool 

### Can a Normal Computer Fan Run in Mineral Oil?

#### ✅ 1. Yes, a standard PC fan can operate in mineral oil
- Mineral oil is **non-conductive** → does not short-circuit electronics.
- Many hobbyists run **oil-submerged PCs** with normal fans.
- Brushless DC fans generally continue spinning fine in oil.

---

#### ⚠️ 2. BUT: The fan's **speed will decrease a lot**
Reason:
- Oil is ~800× denser than air.
- The blades have to "push" thick oil → heavy resistance.

Typical results:
- A 120 mm fan normally spins at 1200–2000 RPM in air.
- In mineral oil, it may drop to **100–300 RPM** (or even stall).

So it *moves oil*, but **slowly**.

---

#### ⚠️ 3. Fan lifespan will be shorter
Problems you may encounter:
- Motor works harder → more heat.
- Oil may seep into bearings → increase friction.
- Rubber seals may swell over time.

It may still last **months to years**, but not as long as in air.

---

#### ⚠️ 4. The fan moves OIL, not AIR
In oil:
- No airflow.
- Instead you get **liquid circulation**, which is good for cooling.

But:
- Movement is much slower.
- Large fans are more effective than small ones.


## ref 

- [[mechanics-dat]]