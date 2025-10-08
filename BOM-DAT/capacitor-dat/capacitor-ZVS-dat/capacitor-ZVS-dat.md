# capacitor-ZVS-dat

**ZVS** stands for **Zero Voltage Switching**, a technique used in power electronics to reduce switching losses and electromagnetic noise.

A **ZVS capacitor** (sometimes called a **resonant capacitor** or **tank capacitor**) is a **high-frequency, high-current film capacitor** used in ZVS circuits — especially in **induction heaters**, **resonant converters**, and **DC–DC inverters**.

---

## ⚙️ Function

In a ZVS circuit:
1. The **inductor (L)** and **capacitor (C)** form an **LC resonant tank**.
2. The capacitor’s charge/discharge creates a **sinusoidal voltage waveform**.
3. MOSFETs or IGBTs switch **only when the voltage across them is near zero**, minimizing losses.

The ZVS capacitor:
- Stores and releases energy during switching cycles.  
- Ensures **phase alignment** between voltage and current for resonance.  
- Allows **soft switching**, reducing heat and EMI.

---

## 🧩 Typical Parameters

| Parameter                              | Typical Range            | Notes                                |
| -------------------------------------- | ------------------------ | ------------------------------------ |
| **Capacitance**                        | 0.1 µF – 5 µF            | Depends on frequency and power level |
| **Voltage rating**                     | 400 V – 2000 V DC        | Must handle resonant voltage peaks   |
| **Type**                               | Polypropylene film (MKP) | Low ESR, low ESL, high pulse current |
| **ESR (Equivalent Series Resistance)** | Very low (<0.01 Ω)       | Essential for low heating            |
| **Current handling**                   | 10–100+ A (RMS)          | Must survive continuous AC ripple    |

---

## ⚡ Why It Matters

ZVS capacitors enable:
- **High-efficiency** power conversion (90–98%)
- **Cooler MOSFETs**
- **Quiet operation** (less ringing)
- **Longer component life**

Without a proper ZVS capacitor:
- Switching occurs with high voltage still present
- MOSFETs overheat or fail
- Resonance breaks down

---

## 📘 Typical Uses

| Application              | Example                   |
| ------------------------ | ------------------------- |
| Induction heater driver  | LC tank capacitor         |
| Tesla coil / ZVS flyback | Energy transfer capacitor |
| Resonant converter       | Resonant link capacitor   |
| Class-E amplifier        | Output matching capacitor |

---

## 🧮 Example

In a 100 kHz ZVS induction heater:
```
L = 5 µH
C = 1 µF
f = 1 / (2π√(LC)) = ~71 kHz
```
The capacitor and coil oscillate at the resonant frequency, letting the MOSFETs switch right when voltage ≈ 0 V → **Zero Voltage Switching**.

---

## 🧠 Summary

| Term               | Meaning                                                         |
| ------------------ | --------------------------------------------------------------- |
| **ZVS**            | Zero Voltage Switching                                          |
| **Purpose**        | Reduce switching loss by turning on transistors at zero voltage |
| **Capacitor Role** | Maintain resonance and enable soft switching                    |
| **Preferred Type** | Polypropylene film (low ESR, high current)                      |


## ref 

- [[capacitor-dat]]