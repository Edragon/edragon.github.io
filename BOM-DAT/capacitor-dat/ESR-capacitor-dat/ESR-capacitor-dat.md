
# ESR-capacitor-dat.md


**ESR** stands for **Equivalent Series Resistance**.  
A capacitor is not ideal — it behaves like it has a small resistor in series with its capacitance. This resistor is called ESR.

---

## 1. Definition

**ESR capacitor** = a capacitor with **low equivalent series resistance**, designed to supply or absorb high-frequency current spikes efficiently.

Mathematically: ESR = Resistive component in series with the capacitor

In circuit models: Capacitor → [ Ideal Capacitance C ] — [ ESR ] — [ Inductance ]

## 2. Why ESR Matters

When a capacitor is used for **power supply smoothing**, such as powering a SIMCom module:

- The module draws **high peak current** during transmission bursts (up to ~2A).
- The ESR creates a **voltage drop**:

    V_drop = I_peak × ESR

- High ESR means more drop → poor voltage stability → possible **module reboot**.

    I_peak = 2 A
    ESR = 0.5 Ω
    V_drop = 2 × 0.5 = 1 V drop

If VBAT is 4.2 V, a 1 V drop means the module sees 3.2 V → unstable operation.


## 3. Low ESR Capacitor

A **low ESR capacitor** has:
- Very small ESR (often < 0.1 Ω).
- Better performance for high-frequency pulses.
- Less heat generated under load.

### Typical types:
| Type               | ESR           | Application                      |
|--------------------|---------------|-----------------------------------|
| Ceramic MLCC      | < 0.01 Ω      | High frequency decoupling        |
| Tantalum          | 0.1 – 0.5 Ω  | Bulk filtering in low-voltage    |
| Low-ESR Electrolytic | 0.01 – 0.1 Ω | Bulk power supply smoothing      |

## 4. Application in GSM/4G Modules
For GSM/4G power stability:
- Use **low ESR capacitors** close to VBAT pin.
- Typical combination:

    - 470 µF – 1000 µF low ESR electrolytic/tantalum
    - 10 µF ceramic MLCC
    - 0.1 µF ceramic MLCC

## ref 

- [[capacitor-dat]]

- [[PCB-design-dat]]