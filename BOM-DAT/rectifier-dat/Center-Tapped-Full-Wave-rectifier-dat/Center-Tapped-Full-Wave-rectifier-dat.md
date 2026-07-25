

# Center-Tapped-Full-Wave-rectifier-dat

- [[CR6842-dat]] - [[Center-Tapped-Full-Wave-rectifier-dat]]

A **Center-Tapped Full-Wave Rectifier** is an AC-DC converter circuit that converts both the positive and negative half-cycles of an AC input voltage into a continuous positive DC output. 

It achieves full-wave rectification using only **two diodes**, but it requires a specialized **center-tapped transformer**—a transformer whose secondary winding is split into two equal halves with a wire tap connected to the exact midpoint.

---

## Circuit Configuration

The center tap of the secondary transformer winding acts as the **common ground (0V reference)** for the load circuit.

            Center-Tapped Secondary
            +------------------+----->|------+  (Diode D1)
        )|  +               | (Anode)    |
    AC ~   )| V_sec/2          |            |
        )|  -               |            +-----+----(+) DC Load
            |                  |            |     (Output)
    Primary |----(CT)----------+------------|----(-) Load / Ground
            |                  |            |
        )|  -               |            +-----+----(-) Load / Ground
    AC ~   )| V_sec/2          |            |
        )|  -               | (Anode)    |
            +------------------+----->|------+  (Diode D2)


## How It Works

The circuit operates in two distinct phases depending on the AC input polarity:

1. **Positive Half-Cycle:**
   * The top terminal of the secondary winding becomes positive relative to the center tap (CT), while the bottom terminal becomes negative.
   * **Diode D1 is forward-biased (ON)** and conducts current.
   * **Diode D2 is reverse-biased (OFF)** and blocks current.
   * Current flows from D1, through the load resistor to the CT ground.

2. **Negative Half-Cycle:**
   * The polarity reverses: the bottom terminal becomes positive relative to the CT, while the top terminal becomes negative.
   * **Diode D1 is reverse-biased (OFF)** and blocks current.
   * **Diode D2 is forward-biased (ON)** and conducts current.
   * Current flows from D2, through the load resistor in the **exact same direction** to the CT ground.

Because current flows through the load in the same direction during both half-cycles, the output is a continuous pulsating DC waveform at **twice the AC line frequency ($f_{out} = 2 f_{in}$)**.

---

## Key Characteristics & Equations

* **Average DC Voltage ($V_{dc}$):**
  $$V_{dc} = \frac{2 V_m}{\pi} \approx 0.637 \, V_m$$
  *(where $V_m$ is the peak AC voltage of half the secondary winding, i.e., from CT to one end).*

* **Peak Inverse Voltage (PIV):**
  $$\text{PIV} = 2 V_m$$
  When one diode conducts, the non-conducting diode must withstand the full end-to-end secondary voltage. This requires diodes with a voltage rating **twice** that of a Bridge rectifier for the same output voltage.

* **Ripple Frequency:**
  $$f_{ripple} = 2 \times f_{in}$$
  *(e.g., $100\text{ Hz}$ output ripple for a $50\text{ Hz}$ AC input).*

---

## Comparison: Center-Tapped vs. Bridge Rectifier

| Parameter | Center-Tapped Full-Wave | Full-Wave Bridge Rectifier |
| :--- | :--- | :--- |
| **Number of Diodes** | 2 | 4 |
| **Transformer Required** | Yes (Center-tapped, bulky & expensive) | Optional (Standard secondary) |
| **Diode Voltage Drop** | $1 \times V_F$ ($\sim 0.7\text{ V}$) | $2 \times V_F$ ($\sim 1.4\text{ V}$) |
| **Peak Inverse Voltage (PIV)** | $2 V_m$ (Higher diode voltage rating needed) | $V_m$ |
| **Transformer Utilization** | Lower (Each half winding conducts only 50% of the time) | Higher |
| **Best Used For** | Low-voltage, high-current outputs (where diode drop matters) | General-purpose AC-DC supplies |


## ref 