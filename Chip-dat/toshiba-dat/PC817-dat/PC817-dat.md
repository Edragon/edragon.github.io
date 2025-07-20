
# PC817-dat




## PIN 4 current-limit resistor 

### 🔌 Understanding Pin 4
- **Pin 4** is the **collector** of the phototransistor inside the PC817.
- Typically connected to **Vcc** through a **pull-up resistor**.
- **Pin 3** (emitter) is usually connected to **ground**.
- When the internal LED is ON, the transistor conducts and pulls Pin 4 low.

---

### 📐 Key Factors to Consider
1. **Vcc voltage level** (e.g., 3.3V or 5V)
2. **Desired output current** from the transistor (1–20 mA typical)
3. **Speed requirement** (lower resistance = faster switching)
4. **Input requirements** of the following stage (e.g., microcontroller)

---

### ⚙️ General Pull-Up Resistor Range
| Vcc  | Recommended Pull-Up Resistor |
|------|------------------------------|
| 5V   | 2.2kΩ – 10kΩ (default: 4.7kΩ) |
| 3.3V | 1kΩ – 4.7kΩ (default: 2.2kΩ)  |

---

### 🧮 Optional Calculation (Ohm’s Law)

```text
R = (Vcc - Vce(sat)) / Ic
```

- Vce(sat) ≈ 0.2V (when transistor is ON)
- Ic = desired collector current (e.g., 1 mA)

**Example for 5V system:**

```text
R = (5V - 0.2V) / 0.001A = 4.8kΩ → Use 4.7kΩ standard value
```

---

### ✅ Summary
- **Use 4.7kΩ** for 5V as a safe default.
- Choose **lower resistance** for faster switching.
- Choose **higher resistance** for lower power consumption.



## ref 

- [[PC817]]

- [[optical-coupler-dat]]