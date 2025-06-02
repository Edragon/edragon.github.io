
# thermal-disppation-dat

- [[heatsink-dat]]

## ⚙️ Key Factors

The current-carrying capacity of a 2.54mm (0.1 inch) wide PCB trace depends on:

- **Copper thickness** (measured in oz/ft²)
- **Temperature rise allowed**
- **Trace location** (internal vs. external)

---

## 📊 General Guidelines (Based on IPC-2221)

| Copper Thickness | Trace Type     | Temp Rise | Approx. Max Current |
|------------------|----------------|-----------|----------------------|
| 1 oz (35µm)      | External trace | 10°C      | ~2.6 A               |
| 1 oz (35µm)      | External trace | 20°C      | ~3.8 A               |
| 2 oz (70µm)      | External trace | 20°C      | ~5.0–6.0 A           |
| 1 oz (35µm)      | Internal trace | 20°C      | ~2.0–2.5 A           |

> 📏 Rule of thumb: For **1 oz copper**, every **1mm width** can safely carry **~1 A** (for external traces and ~10–20°C temp rise).

---

## 🧠 Tips

- Use **wider traces or thicker copper** if higher current is needed.
- Consider **thermal relief**, **via stitching**, or **multiple layers** for better performance.
- For high currents (>5 A), use **solid copper pours** or **bus bars**.

---

## 🛠️ Example

For a **2.54mm wide**, **1 oz copper** external trace with **20°C rise**:
- Safe current = ~3.5–4.0 A

## ref 

- [[PCB-design-dat]]