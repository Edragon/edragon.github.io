

# bead-dat

- [[NS4150-dat]] - [[bead-dat]]

- [[PCB-dat]] - [[PCB-design-dat]]


## 1. Decision Breakdown

| Scenario                                                                               | Ferrite Bead Needed?                                                                                                                                                     |
| :------------------------------------------------------------------------------------- | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Short Wires ($\le$ 100 mm / 10 cm)**                                                 | **No.** Speaker traces/wires under 100 mm can connect directly to the speaker and still pass FCC/CE radiated emissions standards.                                        |
| **Moderate Wires ($> 100\text{ mm}$)**                                                 | **Recommended.** Adding ferrite beads + small capacitors at the output suppresses high-frequency radiated EMI to comply with regulatory standards.                       |
| **Sensitive Wireless Onboard (Wi-Fi, BT, cellular)**                                   | **Recommended.** Ferrite beads help prevent Class-D high-frequency PWM switching noise from interfering with nearby RF antennas or sensitive traces.                     |
| **Long Wires ($> 1\text{ meter}$) or Extremely Sensitive Circuits ($< 1\text{ MHz}$)** | **Use a full LC Filter instead.** Ferrite beads only damp frequencies above ~30 MHz; an LC low-pass filter is better for long wire runs or low-frequency EMI compliance. |

---

## 2. Standard Ferrite Bead Circuit Setup

If you choose to populate ferrite beads on `VOP` and `VON`, place a **bead in series** on both output lines and a small decoupling capacitor to ground on each side after the bead:

```text
VOP --- [ Ferrite Bead ] ---+---> Speaker (+)
                            |
                         === 220pF - 1nF (to GND)
                            |
                           GND

VON --- [ Ferrite Bead ] ---+---> Speaker (-)
                            |
                         === 220pF - 1nF (to GND)
                            |
                           GND
```

3. Component Selection Criteria
 
If you decide to populate the beads, select components with the following specifications:

- High-Frequency Impedance: 600 Ω – 1200 Ω @ 100 MHz.

- Low DC Resistance (DCR): < 100 mΩ (ideally 10–50 mΩ) to avoid wasting output power as heat.

- Current Rating: Rated for at least 1 A – 1.5 A DC to avoid magnetic saturation during 3W peak outputs.


## ref 





