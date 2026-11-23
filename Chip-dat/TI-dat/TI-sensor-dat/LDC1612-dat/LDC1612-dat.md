


# LDC1612-dat.md

- [[sensor-LDC-dat]] - [[sensor-motion-dat]] - [[LDC1612-dat]] - [[ti-sensor-dat]]


The **LDC1612** is a **2-channel, 28-bit Inductance-to-Digital Converter (LDC)** made by **Texas Instruments (TI)**. In practical engineering and DIY circles, it is commonly referred to as an **inductive eddy-current sensor chip**.

In short, it allows a microcontroller to measure tiny, contactless changes in the position, distance, or angle of any conductive metal object with extreme precision.

---

### 1. How It Works (Inductance & Eddy Currents)

The LDC1612 chip pairs with an external **LC tank resonator**—typically just a flat spiral coil etched directly onto a PCB and a single SMD capacitor:

1. **Alternating Magnetic Field:** The LDC1612 drives the PCB coil to generate a high-frequency alternating magnetic field.
2. **Eddy Current Generation:** When a conductive metal target (steel, aluminum, copper, brass, etc.) enters this field, the magnetic field induces circulating electrical currents on the surface of the metal called **eddy currents**.
3. **Inductance Shift:** Those eddy currents create an opposing magnetic field that reduces the effective inductance ($L$) of the PCB coil and shifts its resonant frequency ($f$) upward as the metal gets closer.
4. **High-Resolution Measurement:** The LDC1612 features an internal **28-bit frequency counter** capable of detecting nanohenry (nH) to picohenry (pH) changes in inductance, outputting the raw digital frequency ratio over **I2C** to your MCU (e.g., ESP32, STM32).

---

### 2. Key Features & Specifications

* **Sub-Micron Resolution (28-bit):** Under stable thermal and mechanical conditions, it can detect sub-micron (and even nanometer-scale) displacements—far more sensitive than standard Hall-effect sensors.
* **2 Independent Channels:** Supports two separate coils (the sister chip, **LDC1614**, supports 4 channels). You can use one channel for sensing and the second as a reference coil to cancel out temperature drift.
* **No Magnets Needed:** Unlike magnetic/Hall sensors, it detects **any conductive metal** (even non-magnetic aluminum or copper foil).
* **Contactless & Wear-Free:** Immune to dust, oil, dirt, moisture, and non-conductive barriers (plastic, glass, wood).
* **Wide Frequency Range:** Supports sensor oscillation frequencies from **1 kHz to 10 MHz** over a **2.7V–3.6V** supply.

---

### 3. Common Real-World Applications

* **3D Printer Eddy-Current Bed Probes:** It is the core chip behind modern high-speed contactless bed-leveling probes (such as **BTT Eddy** and **Cartographer** on Voron/Klipper printers), rapidly scanning steel PEI build plates without physical contact.
* **Solid-Metal Touch/Force Buttons:** Mounted behind an aluminum or stainless-steel panel, it detects microscopic deflection (a few microns) when a finger presses the metal surface, enabling completely waterproof, seamless metal buttons.
* **Rotary Encoders & Eccentric Wheel Angle Sensing:** Measuring the rotation angle of a metal gear, cam, or **eccentric metal wheel** without mechanical contact.
* **Linear Slide & Vibration Monitoring:** Tracking fine linear motion or high-speed mechanical vibration of a metal shaft.

---

### 4. Practical Design Caveats

* **Short Sensing Range:** The effective sensing distance scales with the PCB coil's diameter—as a rule of thumb, the maximum useful range is roughly **50% of the coil diameter** (e.g., a 15 mm diameter PCB coil has a reliable range of about 0–7 mm).
* **Thermal Drift:** Copper trace resistance and capacitor values shift with temperature. For precision distance measurements, you either need a temperature sensor for firmware compensation or use the second channel as a differential reference coil.



## ref 