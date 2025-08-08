
# PCIE-dat

Low-profile PCIe cards still use 1.57 mm thickness; only the bracket changes.


## PCIE vs mini-PCIE

## 📏 1. Physical Size

| Feature         | PCIe (Desktop)                 | Mini PCIe (Mini PCI Express)     |
|-----------------|--------------------------------|----------------------------------|
| Form Factor     | Add-in card (e.g., x1, x4, x16) | Small card (30 × 50.95 mm)       |
| Connector       | Edge connector (gold fingers)   | 52-pin card edge                 |
| Mounting        | Slot + bracket                  | Screwed to standoffs             |

---

## 🔌 2. Interface & Lanes

| Feature            | PCIe                          | Mini PCIe                        |
|--------------------|-------------------------------|----------------------------------|
| PCIe Lanes         | x1, x4, x8, x16, etc.         | Only **x1 PCIe lane** supported  |
| USB Support        | ❌ No (PCIe only)             | ✅ Optional USB 2.0 integrated    |
| SATA Support       | ❌ Not directly                | ✅ Optional SATA support (rare)  |
| Electrical Standard| PCIe Gen 1/2/3/4/5/6          | PCIe Gen 1 or 2 (typically)      |

🧠 **Mini PCIe** may carry **PCIe + USB** or even **SATA**, depending on system wiring.


## ref 

- [[CONN-dat]]