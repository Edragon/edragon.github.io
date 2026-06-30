

# motor-driver-design-dat

- [[motor-driver-design-dat]] - [[motor-driver-dat]] - [[motor-driver-rc-dat]] - [[ESC-dat]]

- [[battery-dat]]

## issues analysis 


### Tech Specs & Compatibility: DRV8871 H-Bridge vs. 380 DC Motor

- [[DRV8871-dat]] - [[motor-380-dat]] - [[motor-brushed-dat]]



The DRV8871 can drive a 380 DC motor, but its success depends entirely on the specific variant of the 380 motor and the mechanical load it faces. Because 380 motors range from low-power office equipment variants to high-drain RC hobby motors, you must match their current profiles.

---

#### 1. Specification Comparison

| Specification | DRV8871 Driver Limits | Standard 380 Motor | High-RPM RC 380 Motor |
| :--- | :--- | :--- | :--- |
| **Operating Voltage** | 6.5V to 45V | 6.0V to 12.0V *(Compatible)* | 7.2V to 11.1V *(Compatible)* |
| **Continuous Current** | ~2.0A (Thermal dependent) | 0.4A to 1.2A *(Compatible)* | 2.5A to 5.0A **(Overload Risk)** |
| **Peak / Stall Current**| 3.6A (Hard Limit) | 1.5A to 3.5A *(Safe)* | 8.0A to 15.0A+ **(Triggers Protection)** |

---

#### 2. Operational Scenarios

##### Scenario A: Successful Deployment (Low-Power / Geared 380)
* **Application:** Small robotics, desktop automation, highly-geared actuators, low-load DIY projects.
* **Why it works:** The motor's stall current stays under 3.5A. The DRV8871 handles the running current easily.
* **Safety Feature:** The DRV8871 features an `ILIM` pin. If the motor suddenly stalls, the driver clamps the current safely instead of burning out.

##### Scenario B: Driver Overload / Failure (High-Speed RC 380)
* **Application:** RC cars, boats, high-velocity fans, direct-drive heavy loads.
* **Why it fails:** Upon startup or under load, high-spec 380 motors pull over 4A instantly. 
* **Behavior:** The DRV8871 will enter **Overcurrent Protection (OCP)** or hard-clamp the current via its internal current-limiting resistor. The motor will stutter, drop voltage, or produce almost no startup torque.

---

#### 3. Configuration & Hardware Advice

##### Tuning the ILIM Resistor
The current limit ($I_{LIM}$) of the DRV8871 is set by an external resistor ($R_{ILIM}$) connected from the ILIM pin to GND. The formula for setting the limit is:

$$I_{LIM} = \frac{64,000}{R_{ILIM}}$$

* **Default Breakout Boards:** Most pre-made modules (like Adafruit) ship with a **30kΩ** resistor, capping the current at **~2.1A**.
* **Maximizing Output:** To push the driver to its safe peak of **3A**, swap the resistor to **~21kΩ**. Do not go below **18kΩ** ($3.5A$) to avoid unintended OCP tripping.

##### Thermal Management
If you run the DRV8871 close to 2A continuously:
* Ensure the bottom thermal pad of the IC is soldered to a generous copper pour on your PCB.
* Stick a miniature copper or aluminum heatsink onto the chip if it operates in a closed enclosure.

---

#### 4. Alternative Drivers (If your 380 motor demands more power)

If your 380 motor is a high-drain hobby variant, bypass the DRV8871 and use one of these beefier alternatives:
* **Discrete MOSFET ESC (Electronic Speed Controller):** 10A–30A rated, standard for RC applications.
* **BTS7960 / IBT-2:** High-current H-bridge capable of up to 43A peak (massive overkill, but very cool running).
* **VNH5019:** Robust automotive-grade driver handling up to 12A continuous and 30A peak.

### stuttering 

- [[power-dat]] - [[protection-power-dat]] - [[battery-protector-dat]] - [[motor-driver-design-dat]] - [[LVC-dat]]

This "stuttering" or intermittent rotation (spinning, stopping, then spinning again) at maximum throttle is a classic symptom in RC models. Here are the three most common causes, ranked from most likely to least likely:

---

#### 1. Low Voltage Cutoff (LVC) — The Most Common Cause
This is the most probable culprit.
* **The Mechanism:** When you push the throttle to maximum, the motors require a massive amount of **instantaneous current**. If the battery is low or aging (high internal resistance), its voltage will instantly drop below a safe threshold.
* **The Protection:** The receiver or ESC (Electronic Speed Controller) detects this voltage drop and **cuts off power** to protect the battery from over-discharging (especially critical for LiPo batteries).
* **The Loop:** Once the motors stop, the heavy load on the battery disappears, causing the battery voltage to bounce back up. The system thinks it's safe again and restores power. Since your throttle is still at max, the voltage instantly drops again, triggering another cutoff. This creates the continuous stuttering loop.

#### 2. Electromagnetic Interference (Brush Noise)
If your toy boat uses brushed motors (common in standard toys, characterized by two power wires connected directly to the motor):
* At full throttle, the carbon brushes inside the motor generate heavy **sparking and electromagnetic interference (EMI)**.
* If the motor lacks filtering capacitors (usually small ceramic discs soldered to the motor casing), this interference can travel up the wires and cause the RC receiver to glitch or reboot continuously. The motor cuts out during the reboot and kicks back in once it reconnects, causing a jerky motion.

#### 3. Over-Current or Over-Heat Protection
* **Over-Current Protection:** Running two motors at maximum throttle might exceed the maximum current rating of the main board. The board temporarily cuts power intermittently to prevent itself from burning out.
* **Mechanical Binding:** Check if the propeller shafts are tangled with seaweed, hair, or lack lubrication. Excessive resistance forces the motors to draw significantly more current, easily triggering the protection loops mentioned above.

---

#### 🛠️ Troubleshooting Steps:

1. **Test with a Fully Charged/New Battery:** Try again with a fresh, high-quality battery pack. If it works fine when fully charged but starts stuttering as the battery drains, it is purely a battery performance/capacity limitation.
2. **Perform a Dry Run (Out of Water):** Lift the boat out of the water and push the throttle to maximum. 
   * If it **spins normally in the air** but **stutters in the water**, the battery is definitely too weak or old to handle the high load (water creates much higher resistance and current draw than air).
3. **Check the Drivetrain:** Spin the propellers manually with your fingers. They should turn smoothly. If they feel stiff, clean the shaft and apply a drop of RC marine grease or lightweight oil.



## ref 


