
# 4-layer-dat

## specs 

- inner layer == 0.5 oz 


## lamination 

The typical lamination order for a 4-layer PCB is:

- Top Layer: Signal layer
- Inner Layer 1: Power plane (e.g., VCC or GND)
- Inner Layer 2: Ground plane (e.g., GND or VCC)
- Bottom Layer: Signal layer

### lamination order 

"4-layer PCB stack-up:

- Top Layer: Signal
- Inner Layer 1: Power (VCC)
- Inner Layer 2: Ground (GND)
- Bottom Layer: Signal

Please follow this lamination order for manufacturing."

### 🔄 Typical 4-Layer Stackup (Example)

| Layer | Purpose                     |
|-------|-----------------------------|
| L1    | Signal (High-speed / Logic) |
| L2    | Ground Plane                |
| L3    | Power Plane (3.3V, etc.)    |
| L4    | Signal (Slower or routing)  |

This stackup helps with:
- Good **signal integrity** (especially PCIe or USB lines)
- **Controlled impedance** for high-speed routing
- **Noise reduction** and **EMI compliance**

---

## ⚙️ Why Use 4 Layers?

| Reason                        | Explanation                                 |
|-------------------------------|---------------------------------------------|
| Signal integrity              | PCIe and USB need impedance control         |
| Power distribution            | Separate plane ensures clean power          |
| Ground return path            | Reduces EMI / crosstalk                     |
| Compact routing               | Easier routing in tight Mini PCIe space     |

---

## 🔧 Considerations

- Use **controlled impedance** (50Ω for USB, 85Ω diff for PCIe)
- Ensure **gold fingers** are ENIG plated and follow **Mini PCIe spec**
- Route high-speed signals on **L1 and L4**, with ground under them
- Place components only on the **top layer**, per Mini PCIe mechanical spec
- Follow PCI-SIG or Mini PCIe spec for **connector layout** and **keep-outs**


## ref 

- [[PCB-dat]]