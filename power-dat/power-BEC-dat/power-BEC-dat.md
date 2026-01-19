
# power-BEC-dat

**BEC power** is a **low-voltage regulated power supply** that:
- Takes power from a **main battery** (high voltage)
- Converts it to a **safe, stable low voltage**
- Powers **control electronics** so a separate battery is not needed

---

## Where BEC Is Commonly Used

- **RC ESCs** (Electronic Speed Controllers)
- **Drones / UAVs**
- **RC cars, boats, planes**
- **Robotics control systems**

Typical loads:
- Receiver
- Servos
- Flight controller
- Sensors

## Typical BEC Output

| Parameter | Common Values |
|---------|---------------|
| Output voltage | 5 V / 6 V / 7.4 V |
| Output current | 0.5 A – 10 A |
| Input voltage | 2S–12S LiPo (7.4 V–50 V) |
| Regulation type | Linear or Switching |

---

## Why It’s Called “Battery Eliminator”

Without BEC:

    Main battery → Motor/ESC
    Small battery → Receiver & servos

With BEC:

    Main battery → ESC → BEC → Receiver & servos




## ref 

- [[RC-dat]] - [[power-dat]]