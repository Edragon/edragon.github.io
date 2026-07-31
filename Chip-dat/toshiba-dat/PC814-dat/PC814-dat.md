

# PC814-dat

- [[PC817-dat]] - [[PC814-dat]]

Both the **PC817** and **PC814** are popular 4-pin DIP phototransistor optocouplers manufactured by Sharp (and second-sourced by brands like Lite-On, ON Semiconductor, etc.). 

The primary difference lies in their input structure: **PC817 is designed for DC inputs**, while **PC814 is designed for AC inputs**.

---

## Technical Specifications Comparison

| Parameter | PC817 | PC814 |
| :--- | :--- | :--- |
| **Input Type** | **DC Input** (Single IR LED) | **AC Input** (2 Anti-Parallel IR LEDs) |
| **Input Pinout** | Pin 1: Anode, Pin 2: Cathode | Pin 1 & Pin 2: Non-polarized AC inputs |
| **Output Pinout** | Pin 3: Emitter, Pin 4: Collector | Pin 3: Emitter, Pin 4: Collector |
| **Current Transfer Ratio (CTR)** | **50% – 600%** (at $I_F = 5\text{ mA}$) | **20% – 300%** (at $I_F = \pm 1\text{ mA}$) |
| **Collector-Emitter Voltage ($V_{CEO}$)** | **$80\text{ V}$** (standard Sharp spec) | **$35\text{ V}$ – $70\text{ V}$** (variant dependent) |
| **Max Forward Current ($I_F$)** | $50\text{ mA}$ | $\pm 50\text{ mA}$ |
| **Max Collector Current ($I_C$)** | $50\text{ mA}$ | $50\text{ mA}$ |
| **Isolation Voltage ($V_{ISO}$)** | $5,000\text{ V}_{\text{rms}}$ | $5,000\text{ V}_{\text{rms}}$ |
| **Rise/Fall Time ($t_r / t_f$)** | $4\,\mu\text{s} / 3\,\mu\text{s}$ (Typical) | $4\,\mu\text{s} / 3\,\mu\text{s}$ (Typical) |
| **Cut-off Frequency ($f_c$)** | $80\text{ kHz}$ | $80\text{ kHz}$ |

## ref 

