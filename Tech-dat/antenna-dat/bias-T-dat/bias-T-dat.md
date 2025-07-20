
# bias-T-dat

## What is a Bias-T (DC Injection)?

A **Bias-T** is a simple circuit that combines:

- **DC power** (to power a device like an LNA or active antenna)
- **RF signal** (like from an antenna)

It allows both to **travel over the same coaxial cable** without interfering with each other.

---

### ⚙️ Basic Components
- **Inductor (L):** Passes DC but blocks RF.
- **Capacitor (C):** Passes RF but blocks DC.

---

### 🔁 How It Works

```
DC Input ───┬── L ──┬────────────→ To device (DC + RF)
            │       │
            │       C
            ▼       │
         (Power)    └── RF Signal Input
```

- **Inductor (L):** Injects DC power into the line, while blocking RF from entering the power supply.
- **Capacitor (C):** Lets RF signal pass through but blocks DC.

---

### 📦 Common Uses
- Powering **active antennas** or **LNAs** over a single cable.
- Used in **satellite dishes**, **radio receivers**, **remote sensors**.
- Reduces need for extra power wiring.

---

### 🧠 Why It’s Useful
- Simplifies installation — just **one cable** for signal and power.
- Helps power **remote or hard-to-reach** RF devices.

## ref 

- [[antenna-active-dat]]