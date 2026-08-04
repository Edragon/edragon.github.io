

# differential-steering-boat-dat

- [[differential-steering-dat]] - [[differential-steering-boat-dat]] - [[motion-control-dat]] - [[rc-boat-motion-dat]]

- [[motor-driver-dat]]

## How to Fix Motor Asynchrony (Startup & Speed Differences) in Dual-Motor RC Boats

If your dual-motor RC boat hesitates during launch or veers off course instead of traveling straight, the motors are not starting simultaneously or operating at identical RPMs. Here is a systematic troubleshooting and repair guide:

---

### 1. Physical & Mechanical Inspection (Check Friction)


- [[propeller-dat]] - [[shaft-dat]] - [[lubrication-dat]]

Before tweaking electronics, ensure both drivetrain sides experience equal mechanical resistance.

* **Check Shafts and Lubrication:**
  * Spin both propellers by hand to feel for unequal friction.
  * Inspect drive shafts for bends or improper alignment.
  * Re-apply waterproof marine grease inside the shaft sleeves. Uneven or dried grease adds drag.
* **Inspect Propellers & Debris:**
  * Look for minor blade deformations, chips, or tangled debris (fishing line, weeds).
* **Check Couplers:**
  * Verify that shaft couplers/joint connectors are tightly centered. Off-center couplers create excessive rotational resistance.

---

### 2. Electronic & ESC Calibration (Crucial Step)

- [[ESC-dat]] 

Minor manufacturing tolerances in Electronic Speed Controllers (ESCs) and motors often cause speed mismatch.

* **ESC Throttle Range Calibration:**
  * Calibrate the throttle endpoints for both ESCs so they register zero and maximum throttle at the exact same stick positions.
  * *Standard Process:* Throttle stick to MAX → Power ON ESC → Wait for signal chimes → Throttle stick to MIN.
* **ESC Parameter Matching (For Programmable ESCs like BLHeli):**
  * **Increase Startup Power:** Prevents one motor from stalling at low RPMs due to static friction.
  * **Align Timing & PWM Frequency:** Ensure both ESCs run identical timing and PWM frequency settings.

---

### 3. Transmitter (Radio) Tuning

- [[edgeTX-dat]]


If you use a programmable transmitter (e.g., OpenTX, EdgeTX, or multi-channel surface radio):

* **Endpoint Adjustment (EPA / Travel Limit):**
  * If one motor achieves a higher top speed, reduce the output limit on that specific channel to match the slower motor.
* **Sub-Trim and Trim Adjustment:**
  * Use channel trims to compensate for slight yaw drift during straight runs.
* **Deadband & Idle Offset:**
  * If one motor responds later at low throttle, adjust the sub-trim or deadband settings so both motors trigger simultaneously.

---

### 4. Advanced Solution: Hardware Gyro / Flight Controller

To maintain a straight line automatically in windy conditions or moving water:

* **Install a Heading Hold Gyro or Flight Controller (e.g., ArduPilot):**
  * Wire a gyro into the ESC steering control path. When it detects unintended yawing, it dynamically adjusts differential thrust between the motors to auto-correct the course.





## ref 


