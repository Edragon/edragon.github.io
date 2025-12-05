
# wifi-distance-dat.md

Long-Distance Wi-Fi — Best Antennas and Maximum Range

Below is the previous information rewritten cleanly in English Markdown.

---

# 🥇 Current Maximum Practical Wi-Fi Range (Real-World Achievable)

With legal transmission power:

### **2.4 GHz + High-Gain Directional Antennas (Point-to-Point)**
- 24–30 dBi parabolic dish antennas  
- 20–30 dBm transmit power  
- Full clear line-of-sight  

👉 **Typical range: 10–30 km**  
👉 **Under ideal conditions: 50+ km**

These are *point-to-point* wireless links, not normal routers.

---

# 🥈 Longest Range You Can Buy Commercially (Legal Power)

| Scenario | Hardware | Realistic Range |
|---------|----------|-----------------|
| Long-distance point-to-point | Ubiquiti NanoBeam / LiteBeam | 1–5 km |
| High-gain parabolic antennas | Ubiquiti RocketDish | 10–30 km |
| Standard omni Wi-Fi router | Typical router antenna | 100–300 m |
| Upgraded omni antennas (7–12 dBi) | High-gain stick antenna | 200–600 m |

---

# 🧭 Four Factors That Decide Maximum Wi-Fi Distance

## 1. **Antenna Gain = Distance**
Higher gain = longer reach  
Best antennas for extreme distance:

### **Parabolic Dish Antennas**
- 24–30 dBi  
- Very narrow beam (2°–7°)  
- Massive boost to link budget

Every +3 dBi ≈ **1.4× range increase**.

---

## 2. **2.4 GHz travels farther than 5 GHz**
- Longer wavelength  
- Better penetration  
- Better diffraction  

Best choice for long range: **2.4 GHz**

---

## 3. **Line-of-Sight Is Critical**
For long distance links you need:

✔ Enough height  
✔ Zero trees/buildings  
✔ Clean Fresnel zone  

No line-of-sight → no long-distance Wi-Fi.

---

## 4. **Your receiver matters too**
Phones = weak antennas (0–3 dBi)  
CPE devices = strong antennas (8–15 dBi)

For multi-km links → **use CPE on both ends**.

---

# 🏆 Best Practical Setups

## For **1–5 km**
- **Ubiquiti LiteBeam** (23 dBi)
- Point-to-point alignment

---

## For **10–30 km**
- **Ubiquiti Rocket + RocketDish (27–30 dBi)**  
- Full line-of-sight  
- Fast, stable link

---

## For **200–600 m general outdoor Wi-Fi**
- 7–12 dBi omni antennas  
- Outdoor AP (UniFi Mesh)