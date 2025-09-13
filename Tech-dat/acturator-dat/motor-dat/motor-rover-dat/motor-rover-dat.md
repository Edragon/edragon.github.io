
# motor-rover-dat

- [[rover-dat]]

- [[BLDC-motor-dat]]

# Choosing a Motor for a Heavy-Duty Off-Road RC Crawler (Tracked Vehicle)

## ✅ Quick Answer
- **Best Type**: **Sensored brushless outrunner (BLDC) with 4 poles or more**  
- **KV Range** (depends on gearing and battery):  
  - **Direct drive / low gearing** → 200–600 KV (on 3S–4S)  
  - **With gearbox (3:1–6:1)** → 800–1500 KV  
- **Poles**: 4-pole or higher → more torque at low RPM  
- **Gearing**: Strongly recommended to use **planetary or spur gearbox (3:1–6:1)**  
- **ESC**: 60–150A, sensored FOC capable (for smooth startup & crawling)  

---

## 🔎 Why This Choice
1. **Outrunner BLDC** → Large diameter = higher torque at low RPM.  
2. **Low KV & multi-pole** → Delivers strong torque instead of excessive speed.  
3. **Sensored control** → Smooth startup, stable torque at very low speed (essential for crawling).  
4. **Gear reduction** → Multiplies torque, improves efficiency, avoids motor overheating.  

---

## ⚙️ Example Spec (for 1/8–1/5 scale tracked builds)
- **Motor**: Sensored brushless outrunner, size **3650 / 3660 / 4274**  
- **KV**: 300–800 KV (with 3:1–5:1 gearbox on 3S–4S battery)  
- **ESC**: 80–120A FOC capable, sensored input  
- **Battery**: 3S–4S LiPo, C-rating high enough to handle current draw  

---

## 📐 Speed Calculation Example
Motor: **1000 KV**, Battery: **3S (11.1V)**, Gear ratio: **5:1**, Track wheel diameter: **120 mm**

1. Motor RPM = KV × Voltage = 1000 × 11.1 = **11,100 RPM**  
2. Wheel RPM = 11,100 ÷ 5 = **2,220 RPM**  
3. Wheel circumference = π × 0.12 m = **0.377 m**  
4. Speed = (2,220 × 0.377) ÷ 60 = **13.95 m/s = 50.2 km/h**

➡ Too fast for crawler use → better to lower KV or increase gear ratio.  

---

## 🚀 Practical Build Options
1. **Budget** → 3650/3660, 4-pole, ~1500 KV + 4–6:1 gearbox + 80–120A ESC  
2. **Balanced (Recommended)** → 4274 sensored outrunner, 300–800 KV + 3–5:1 gearbox + 100A ESC  
3. **Heavy Load Extreme** → Dual 300 KV motors + planetary reduction + dual 120A ESCs, 4S LiPo  

---

## 📌 What You Can Do Next
I can either:  
1. **Do full torque/speed calculation** if you give me:  
   - Vehicle total weight (kg)  
   - Desired maximum slope angle (°)  
   - Target top speed (km/h)  
2. **List 3–5 real motor + ESC combos** with model numbers and where to buy.  

👉 Tell me which one you prefer, and I’ll prepare the detailed setup.



## ref 

- [[motor]]