
# choke-rf-dat

- [[inductor-dat]] - [[choke-dat]] - [[choke-rf-dat]] - [[bias-t-dat]]

Using a high-frequency inductor (commonly referred to as a **multilayer ceramic inductor** or **wirewound high-frequency inductor**, such as standard 0402 or 0603 packages) is **highly recommended** in GPS active antenna circuits.

In a GPS active antenna circuit, this type of high-frequency inductor primarily functions as a **Bias Tee / RF Choke**. Here are its core roles and key selection criteria:

---

### I. Core Functions of the High-Frequency Inductor

1. **RF and DC Isolation (RF Choke)**
   * GPS active antennas (which typically integrate an internal Low-Noise Amplifier, or LNA) require an external DC power supply (usually 3.0V, 3.3V, or 5V).
   * DC power is "injected" into the antenna's RF signal transmission line through this inductor. The high-frequency inductor exhibits **very low resistance to Direct Current (DC)**, allowing the power to pass smoothly. However, it presents **extremely high inductive reactance (impedance) to GPS high-frequency RF signals (L1 band around 1575.42 MHz)**, preventing the high-frequency RF signals from leaking back into the power supply circuit and causing signal attenuation or interference.

2. **Preventing RF Energy Leakage**
   * It acts as a "gatekeeper," trapping the weak GPS satellite RF signals securely within the signal path and guiding them toward the downstream GPS receiver chip rather than letting them waste away at the power supply terminal.

---

### II. Why Must It Be a "High-Frequency" Inductor? Can Regular Inductors Be Used?

Standard power filtering inductors (such as large-value drum/power inductors, ferrite beads, or large-package inductors) **must not** be used in the GPS RF path for the following reasons:

* **Self-Resonant Frequency (SRF) Requirements**:
  GPS operates at a high frequency of 1.575 GHz. High-frequency inductors are designed to have an **SRF well above the working frequency**. At 1.575 GHz, a high-frequency inductor maintains stable high impedance. A regular inductor at this frequency would likely become capacitive, lose its inductive properties, and potentially short-circuit the RF signal altogether.
* **Minimal Parasitic Parameters (Stray Capacitance)**:
  High-frequency inductors feature extremely small parasitic capacitance and low loss (high Q factor) at high frequencies, avoiding severe insertion loss on weak GPS satellite signals (typically around -130 dBm to -160 dBm).

---

### III. Selection and Design Considerations

1. **Inductance Value**:
   * Typical GPS feeding inductors range from **10 nH to 47 nH** (commonly 22 nH or 33 nH). You should calculate or simulate to ensure the impedance is sufficiently high at 1.575 GHz.
2. **Current Rating**:
   * The LNA power consumption in active antennas is generally very low (around 10 mA to 30 mA), so a massive saturation current is not required, but it must comfortably handle the load.
3. **Q Factor (Quality Factor)**:
   * Choose high-Q ceramic or wirewound high-frequency inductors. A higher Q factor means lower RF signal loss, which helps preserve receiving sensitivity.
4. **Circuit Companion**:
   * In practical schematics, this is usually deployed as a combination of "Inductor (for biasing) + DC Blocking Capacitor" (typically a few dozen pF NP0/C0G capacitor to prevent DC voltage from entering the receiver chip's RF input pin).

---

For GPS active antennas, a high-frequency inductor is an essential component that enables powering the antenna's internal LNA via "DC pass, RF block" without compromising RF signal integrity.


## ref 

