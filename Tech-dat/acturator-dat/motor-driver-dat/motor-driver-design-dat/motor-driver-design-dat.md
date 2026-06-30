

# motor-driver-design-dat

- [[motor-driver-design-dat]] - [[motor-driver-dat]] - [[motor-driver-rc-dat]] - [[ESC-dat]]


## issues analysis 


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


