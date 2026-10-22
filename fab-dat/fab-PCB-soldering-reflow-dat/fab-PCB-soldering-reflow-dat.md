


# fab-PCB-soldering-reflow-dat

- [[fab-dat]] - [[fab-PCB-soldering-reflow-dat]] - [[fab-PCB-soldering-dat]]

---

## II. Reflow Profile Control

An improper temperature profile is a direct cause of cold joints (e.g., insufficient solder on pins, tombstoning, or poor wetting).

* **Preheat Zone**:
  * Keep the ramp rate at **1.0 – 2.0 °C/s**. Ramping too fast causes violent solvent evaporation, leading to paste splatter or slump; ramping too slowly causes the flux to fail prematurely.

* **Soak Zone**:
  * Hold at **150 °C – 190 °C** for **60 – 120 seconds**. This stage must equalize the temperature across the PCB surface, fully activate the flux, and thoroughly remove oxides from pads and pins.

* **Reflow (Peak & TAL) Zone**:
  * Set the peak temperature to **235 °C – 245 °C** (for lead-free SAC305 paste).
  * Keep the time above liquidus (TAL) at **45 – 75 seconds** to ensure the paste fully melts and forms a good intermetallic compound (IMC) with the STM32 pins and PCB pads.

* **Cooling Zone**:
  * Keep the cooling rate at **1.5 – 3.0 °C/s**. Cooling too fast creates internal stress and embrittles the joint; cooling too slowly produces coarse grains and reduces joint mechanical strength.

---





## ref 