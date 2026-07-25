

# PFC-active-dat

- [[ACDC-dat]] - [[PFC-active-dat]]

## Can Active PFC Work with a Center-Tapped Full-Wave Rectifier?

**In theory, yes; in practical power supply engineering, almost never.**

While you *can* technically interface an Active PFC stage with a Center-Tapped Full-Wave Rectifier, doing so is **uneconomical, bulky, and inefficient** compared to using a standard single-phase Bridge Rectifier.

---

### Technical & Practical Impediments

#### 1. Transformer Requirement Before the PFC Stage
* **Standard Active PFC:** Operates directly on the rectified AC mains using a simple, un-isolated Diode Bridge Rectifier ($85\text{ VAC} - 265\text{ VAC}$).
* **Center-Tapped Rectifier:** **Requires a center-tapped transformer** right at the AC input line (operating at line frequencies like $50\text{ Hz} / 60\text{ Hz}$).
* **Consequence:** Heavy $50/60\text{ Hz}$ line transformers are massive, expensive, and heavy. Putting a bulky line transformer *before* high-frequency switching defeats the primary size and weight advantages of Active PFC.

#### 2. High Voltage & PIV Limitations
* In a Center-Tapped configuration, each diode experiences a **Peak Inverse Voltage (PIV)** of **$2 \times V_{m}$**.
* Active PFC Boost converters typically step up the output DC bus to **$380\text{V} - 400\text{V DC}$**.
* Trying to achieve a high DC bus voltage via a Center-Tapped secondary forces you to use diodes rated for **over $800\text{V} - 1000\text{V}$**, whereas a Bridge Rectifier only subjects its diodes to $V_m$.

#### 3. Transformer Utilization
* In a Center-Tapped transformer, each half of the secondary winding carries current for only **50% of the AC cycle**.
* Active PFC relies on drawing a **continuous, smooth, sinusoidal current** throughout the full $360^\circ$ AC period. The asymmetrical winding conduction in a center-tapped secondary complicates current sensing and lowers transformer efficiency.

---

### Where Each Configuration Belongs

Standard High-Efficiency Architecture:

[AC Mains] ---> [Full Bridge Rectifier] ---> [Boost Active PFC (400V DC)] ---> [Isolated DC-DC (Forward/Bridge)]

Center-Tapped Application (Secondary Side Only):

[AC Mains] ---> [Active PFC] ---> [Primary Switches] ---> [High-Freq Transformer] ---> [Center-Tapped Rectifier] ---> [Low-Voltage High-Current DC Output]

1. **Standard Active PFC Placement (Mains Input):** 
   Always paired with a **4-diode Bridge Rectifier** (or active/bridgeless MOSFET rectifiers). This configuration yields the highest efficiency, smallest form factor, and lowest component stress.

2. **Center-Tapped Rectifier Placement (Isolated Secondary):**
   Center-tapped rectifiers are exclusively used on the **secondary (low-voltage, high-current) side** of an isolated DC-DC converter (like a Push-Pull, Forward, or Half-Bridge stage operating at high frequencies like $100\text{ kHz}$). 
   
   *At low output voltages (e.g., $3.3\text{V}$ or $5\text{V}$ outputs), passing current through only ONE diode drop ($\sim 0.7\text{V}$) instead of TWO bridge diode drops ($\sim 1.4\text{V}$) saves substantial power.*

---

### Summary Comparison

| Parameter                      | Active PFC + Bridge Rectifier        | Active PFC + Center-Tapped Rectifier                |
| :----------------------------- | :----------------------------------- | :-------------------------------------------------- |
| **Feasibility**                | Industry Standard                    | Technically Possible, Practically Obsolete          |
| **Line Transformer Needed?**   | No (Direct off-line operation)       | **Yes** ($50/60\text{ Hz}$ bulky input transformer) |
| **System Size & Weight**       | Compact, lightweight                 | Very heavy and bulky                                |
| **Diode Voltage Stress (PIV)** | $V_m$ (~400V)                        | $2 V_m$ (>800V)                                     |
| **Primary Use Case**           | All modern $75\text{W}+$ SMPS inputs | Low-voltage high-current secondary outputs          |

## Active Power Factor Correction (Active PFC)

**Active Power Factor Correction (Active PFC)** is an electronic circuit technique used in AC-DC power supplies to align the AC input current waveform with the AC voltage waveform, making the power supply look like a pure resistor to the electrical grid.

By using high-frequency switching semiconductors (like MOSFETs/IGBTs) and a dedicated control IC, active PFC eliminates current harmonics and boosts the **Power Factor (PF)** close to the ideal value of **1.0 (typically 0.95–0.99)**.

---

### The Problem: Why Power Factor Correction is Needed

In a conventional AC-DC supply without PFC (or with passive PFC), a bridge rectifier feeds directly into a large electrolytic smoothing capacitor. 

* The capacitor charges **only at the peak** of the AC voltage wave.
* This draws short, high-amplitude **current pulses** rather than a smooth sinusoidal current.
* **Consequences:** Low Power Factor ($\text{PF} \approx 0.5 - 0.7$), heavy harmonic distortion ($\text{THD}$), reduced grid efficiency, and excess heat in distribution wiring.

Without Active PFC (Pulsed Current):
AC Voltage:  /¯¯_/¯¯_/¯¯

AC Current:   ||    ||    ||   (Narrow, high-peak current spikes)

With Active PFC (Sinusoidal Current):
AC Voltage:  /¯¯_/¯¯_/¯¯

AC Current:  /¯¯_/¯¯_/¯¯\  (In-phase, smooth sinusoidal current)

### How Active PFC Works

An Active PFC stage sits **immediately after the main AC bridge rectifier** and **before the primary DC-DC converter** (like a Forward, Half-Bridge, or Full-Bridge stage). 

The most common Active PFC topology is a **Boost Converter operating at high switching frequency (50 kHz – 200+ kHz)**:

    AC Input ---> [Bridge Rectifier] ---> [Boost Inductor] ---> [Diode] ---> [DC Bus Cap] ---> DC-DC Converter
    |                |           (400V DC)
    [MOSFET]          [Control]
    |                 |
    GND <--------------+ (Voltage/Current Sensing)

1. **Voltage Sensing:** The PFC controller senses the rectified AC voltage waveform to establish a reference shape.
2. **Current Shaping:** The controller drives the MOSFET rapidly ON and OFF, forcing the inductor current to continuously trace the exact shape of the AC sinusoidal voltage.
3. **Voltage Boosting:** The boost topology steps up the rectified DC voltage to a regulated **high-voltage DC bus (typically ~380V – 400V DC)**, regardless of whether the AC input is $100\text{ V}$ or $240\text{ V}$.

---

### Active PFC vs. Passive PFC

| Feature                        | Passive PFC                                             | Active PFC                                                                      |
| :----------------------------- | :------------------------------------------------------ | :------------------------------------------------------------------------------ |
| **Circuit Method**             | Uses large LC filters (heavy inductors/capacitors)      | Uses active switches (MOSFETs) & control ICs                                    |
| **Power Factor ($\text{PF}$)** | $0.70 \sim 0.85$                                        | **$0.95 \sim 0.99+$**                                                           |
| **Weight & Size**              | Heavy, bulky                                            | Lightweight, compact                                                            |
| **AC Input Range**             | Voltage-specific (requires a 115V/230V selector switch) | **Full-Range / Universal Input ($85\text{ VAC} - 265\text{ VAC}$)**             |
| **Cost & Complexity**          | Low cost, low complexity                                | Higher component count & control complexity                                     |
| **Target Power Range**         | Low power ($< 100\text{ W}$)                            | Mandatory for mid-to-high power ($> 75\text{ W}$ in EU/international standards) |

---

### Key Benefits

1. **Universal AC Input (Full Range):** Because the boost stage regulates the output to $\sim 400\text{ VDC}$, the power supply automatically accepts any voltage from $85\text{ VAC}$ to $265\text{ VAC}$ without manual switches.
2. **Regulatory Compliance:** Essential for meeting global EMC and harmonic emissions standards (such as **IEC 61000-3-2**).
3. **Higher Efficiency & Lower Heat:** Reduces peak RMS currents drawn from the wall, reducing $I^2R$ conduction losses across cables and connectors.
4. **Stable Downstream Operation:** Providing a constant ~400V DC bus to the main isolated DC-DC converter (Forward, LLC, or Full-Bridge) allows downstream switches to be optimized for tight efficiency.



## ref 