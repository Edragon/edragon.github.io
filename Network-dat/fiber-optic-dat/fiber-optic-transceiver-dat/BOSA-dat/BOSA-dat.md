

# BOSA-dat

- [[fiber-optic-dat]] - [[BOSA-dat]] - [[fiber-optic-PCB-dat]]



### Option 2: Solder a Bare BOSA Component Directly onto the PCB (On-Board)

If you want a compact, permanent optical port without an SFP cage—similar to the internals of a media converter or ONU—you need to buy a **bare BOSA (Bi-Directional Optical Sub-Assembly)** instead of a packaged SFP module.

* **Form Factor:** A cylindrical metal barrel with an SC or LC optical receptacle (or pigtail) on one end, and 4 to 5 metal leads (`LD+`, `LD-`, `PD+`, `PD-`, `GND`) on the other end that solder directly onto your PCB.
* **Paired Wavelengths:** Just like SFP modules, you must buy them in matched pairs: one **1310nm TX / 1510nm (or 1550nm) RX BOSA** for Board A, and one **1510nm (or 1550nm) TX / 1310nm RX BOSA** for Board B.
* **Extra Circuitry Required:** Because a BOSA is purely an optoelectronic component, your PCB must also include a **Laser Diode Driver** and a **Limiting Amplifier** (e.g., MAX3735 / MAX3748) to drive the laser and condition the received signal—circuitry that is already built inside a finished SFP module.

---



## ref 