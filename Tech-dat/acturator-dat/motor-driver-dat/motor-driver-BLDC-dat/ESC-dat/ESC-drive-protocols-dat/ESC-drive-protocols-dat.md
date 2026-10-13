
# ESC-drive-protocols-dat


- [[ESC-drive-protocols-dat]] - [[ESC-telemetry-dat]] - [[telemetry-dat]] - [[ESC-dat]]

- [[betaflight-motors-dat]] - [[motor-dat]] - [[motor-driver-dat]] - [[ESC-drive-protocols-dat]]

- [[ESC-dat]] - [[ESC-FPV-dat]]


Common Motor Drive Protocols (Dshot, OneShot, PWM, etc.)

In the fields of drones, model aircraft, and robotics, the communication protocols between the Electronic Speed Controller (ESC) and the Flight Controller have evolved from **analog pulses** to **digital packets**. Understanding these protocols helps clarify their performance differences, latency, and stability.



### 1. PWM (Pulse Width Modulation)

* **Type:** Analog protocol
* **Working Principle:** Represents throttle magnitude through the duration of a high-level pulse (typically between **1ms and 2ms**).
* **Characteristics:**
* **Traditional & Universal:** Earliest used for traditional model servos and early ESCs.
* **Low Refresh Rate:** Frequencies typically range from 50Hz to 400Hz, resulting in higher latency (approx. a few to over ten milliseconds).
* **Requires Calibration:** Throttle ranges vary across ESCs, usually requiring manual throttle range calibration.



---

### 2. OneShot Protocols (OneShot125 / OneShot42)

* **Type:** Analog / pulse-width protocol
* **Classification:**
* **OneShot125:** Shortens the pulse width to **125μs to 250μs**.
* **OneShot42:** Further shortens the pulse width to **42μs to 84μs**.


* **Characteristics:**
* **Flight Controller Synchronization:** Allows the flight controller's looptime calculation to directly trigger a throttle pulse, avoiding waiting delays caused by mismatched traditional PWM frequencies.
* **Significant Latency Reduction:** Brought much more sensitive handling responses to multirotors of its era.
* **Still Requires Calibration:** Fundamentally relies on high-level pulse duration, thus requiring throttle calibration.



---

### 3. MultiShot

* **Type:** Analog pulse protocol
* **Working Principle:** Further compresses pulse widths down to **5μs to 25μs**.
* **Characteristics:**
* **Extremely High Refresh Rate:** Able to match extremely high-frequency flight controller loops at the time.
* **High Hardware Demands:** Extremely short pulses demand strict timing precision from both flight controller and ESC, making it prone to electromagnetic interference errors. It faded from mainstream use after DShot gained popularity.



---

### 4. DShot (Digital Shot) —— Modern Mainstream

* **Type:** **Pure digital protocol** (developed collaboratively by Flyduino and the Betaflight team)
* **Common Variants:** **DShot150**, **DShot300**, **DShot600** (numbers represent transmission speeds in kbps).
* **Characteristics:**
* **Digital Packets & CRC Error Checking:** Replaces pulse length dependency with digital packet transmission containing precise throttle values (0–2047). Includes built-in **CRC checking**; corrupted data packets from interference are automatically discarded, significantly boosting anti-interference capability and safety (preventing sudden full-throttle spikes from noise).
* **Calibration-Free:** Because data is transmitted digitally and quantitatively, all ESCs interpret the values identically, **eliminating the need for throttle range calibration**.
* **Bidirectional DShot (RPM Filtering):** Advanced modern feature where ESCs not only receive throttle instructions but also transmit **real-time motor RPM** back to the flight controller over the same signal wire. The flight controller uses these RPM data points for dynamic notch filtering (RPM Filter), effectively eliminating motor-induced vibrations and high-frequency noise while improving flight stability and reducing motor heat.



---

### 5. ProShot / Fettec / Other Proprietary Protocols

* **ProShot:** Combines the advantages of analog and digital by sending varying numbers of pulses within a fixed timeframe. Extremely fast, but currently less common due to the total dominance of the DShot ecosystem.
* **Closed-Loop Serial Protocols:** Used in industrial or specialized heavy-payload drone systems (such as select DJI or heavy-lift platforms), utilizing CAN bus or other serial communication protocols for motor control and dual-directional telemetry feedback.



### 📊 Core Performance Comparison Table

| Protocol Name       | Type         | Refresh Rate / Speed         | Throttle Calibration | Key Features & Advantages                                                                   |
| ------------------- | ------------ | ---------------------------- | -------------------- | ------------------------------------------------------------------------------------------- |
| **PWM**             | Analog       | 50Hz - 400Hz                 | Required             | Wide compatibility, but high latency and no error checking                                  |
| **OneShot125**      | Analog Pulse | Fast (up to several kHz)     | Required             | Significantly reduced latency, synchronized with flight controller main loop                |
| **MultiShot**       | Analog Pulse | Extremely Fast (down to 5μs) | Required             | Ultra-fast, but demanding on hardware precision and average anti-interference               |
| **DShot (300/600)** | **Digital**  | 300 / 600 kbps               | **Calibration-Free** | High noise immunity, CRC verification, supports bidirectional RPM telemetry (RPM Filtering) |



Currently, in FPV drones and modern model aircraft, **DShot600** (paired with Bidirectional DShot and RPM Filtering enabled) is the definitive industry standard and optimal solution.



## ref 

