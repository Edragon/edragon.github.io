
# TI-logic-dat

- [[TXS0102-dat]] - [[TXS0108-dat]] - [[TI-logic-dat]]


- [[SN75451-dat]] - [[transistor-array-dat]] - [[transistor-dat]]

- [[TI-dat]] - [[TI-logic-dat]] - [[logic-inverter-dat]] - [[logic-dat]]




- [[logic-XOR-dat]] - [[logic-NAND-dat]] - [[logic-inverter-dat]] - [[logic-gate-dat]]


## NAND 

SN74LVC2G00 Dual 2-Input Positive-NAND Gate



## inverter 


### SN74LVC1G04

SN74LVC1G04DBVR == Single 1.65-V to 5.5-V inverter | DBV | 5 | -40 to 125

SN74LVC1G04 Single Inverter Gate



### SN74LVC2G04 Dual Inverter Gate

![](2025-03-25-15-51-07.png)

https://www.ti.com/lit/ds/symlink/sn74lvc2g04.pdf


Table 1. Function Table (Each Inverter)

| INPUT (A) | OUTPUT (Y) |
| --------- | ---------- |
| H         | L          |
| L         | H          |



SN74LVC2G14 — Dual Schmitt-Trigger Inverter

The SN74LVC2G14 contains two independent Schmitt-trigger inverters and implements the Boolean function Y = 
¬A (inverter). Key features and corrected description:

- Supply voltage: 1.65 V to 5.5 V (VCC)
- Package: NanoFree™ package technology (die as the package)
- Function: Two inverters with Schmitt-trigger inputs (separate thresholds for rising and falling edges)
  - Positive-going threshold: Vt+
  - Negative-going threshold: Vt-
- Special feature: The Schmitt action provides hysteresis, improving noise immunity and signal clean-up on slow or noisy inputs.
- Power-down behavior: The device is specified for partial-power-down applications using Ioff outputs. The Ioff circuitry prevents damaging current backflow through the device when it is powered down while other parts of the system remain powered.

Notes:
- Use this device when you need level translation, input hysteresis, or signal conditioning across a wide VCC range.






## TXS010x vs TXB010x 

Both the **TXS0102** and **TXB0102** are 2-bit, dual-supply, bidirectional voltage-level translators from Texas Instruments that require **no external direction-control pin**. However, they use fundamentally different internal architectures, making them suited for different types of applications.

---

### 1. Core Architectural Difference

* **TXS0102 (Open-Drain / Pass-Gate Architecture):**
  * Features internal **pull-up resistors** (typically ~10 k$\Omega$) on both the A and B ports.
  * Designed specifically to handle **open-drain** interfaces (like **I2C**, SMBus, or MDIO), but can also support push-pull.
  * Uses an edge-rate accelerator (one-shot circuit) to help pull signals up quickly.

* **TXB0102 (Edge-Rate / Push-Pull Architecture):**
  * Uses an internal active **push-pull** architecture driven by one-shot circuits on both sides to actively drive lines high and low.
  * **Not suitable for open-drain interfaces** (like I2C) because the active pull-up will fight external pull-down devices or bus arbitration.

---

### 2. Key Specifications Comparison

| Feature                        | TXS0102                                                                             | TXB0102                                                                                                                   |
| :----------------------------- | :---------------------------------------------------------------------------------- | :------------------------------------------------------------------------------------------------------------------------ |
| **Primary Target Interface**   | Open-Drain (e.g., I2C) & Push-Pull                                                  | Push-Pull only (e.g., SPI, UART, GPIO)                                                                                    |
| **Max Data Rate (Push-Pull)**  | ~24 Mbps                                                                            | Up to 100 Mbps                                                                                                            |
| **Max Data Rate (Open-Drain)** | ~2 Mbps                                                                             | Not recommended / Unsupported for true open-drain                                                                         |
| **Internal Pull-ups**          | Yes (~10 k$\Omega$ built-in)                                                        | No                                                                                                                        |
| **Output Drive Current**       | Typically weaker (~1 mA low-level drive)                                            | Stronger push-pull drive (up to $\pm 50$ mA transient / standard CMOS levels)                                             |
| **External Pull-up Resistors** | Generally **not allowed** (or must be $\ge 50\text{ k}\Omega$ if strictly required) | **Strictly prohibited** (external pull-ups will break the edge-rate detection and cause logic lock-up)                    |
| **Output Enable (OE)**         | Has an OE pin (places outputs in high-Z when low)                                   | Typically lacks an OE pin on the 2-bit version (enabled automatically via VCC) — *note: verify specific package variants* |

---

### 3. When to Use Which?

* **Choose the TXS0102 if:**
  * You are bridging **I2C buses** or any open-drain communication protocol.
  * Your lines require internal pull-ups without crowding the board with external resistors.
  * Speeds are moderate (Standard/Fast-mode I2C or general GPIO up to a few MHz).

* **Choose the TXB0102 if:**
  * You are running **push-pull protocols** like SPI, UART, or general-purpose digital logic control signals.
  * You need higher data transmission speeds (up to 100 Mbps).
  * There are **no external pull-up or pull-down resistors** anywhere on the signal lines.


## TXS vs TXB replaceable 

Can the **TXB0102** replace the **TXS0102**, or vice versa? The short answer is: **It depends entirely on the protocol and circuit design.** Because their internal architectures are fundamentally different, swapping them blindly can cause communication failures or hardware lock-ups.

---

### 1. Can TXB0102 replace TXS0102?
**Generally, NO — especially for I2C or open-drain lines.**

* **Why it fails on I2C:** The TXB0102 uses an active push-pull architecture with edge-rate accelerators. I2C relies on **open-drain** communication, where multiple devices pull the bus low and rely on resistors to pull it high, allowing for clock stretching and bus arbitration. If you put a TXB0102 on an I2C bus, its active drivers will fight external pull-downs or other devices, breaking communication and potentially causing bus contention.
* **When it might work:** If the signal line is strictly a high-speed **push-pull** signal (like SPI or standard push-pull GPIO) and there are **no external pull-up or pull-down resistors** anywhere on the line, the TXB0102 can replace the TXS0102 and will actually provide a faster data rate (up to 100 Mbps vs. ~24 Mbps).

---

### 2. Can TXS0102 replace TXB0102?
**Yes, usually, but with performance trade-offs.**

* **Why it works:** The TXS0102 can handle both open-drain and push-pull signals because its pass-gate architecture allows push-pull signals to pass through while using its internal pull-ups and one-shot circuits to handle transitions.
* **The Caveats:**
  * **Slower Speed:** The TXS0102 is significantly slower (~24 Mbps max for push-pull) compared to the TXB0102 (up to 100 Mbps). If you are translating a high-speed SPI bus or UART stream, the TXS0102 might bottleneck your data rate.
  * **Drive Strength:** The TXS0102 has weaker output drive current because of its pass-gate design and internal ~10 k$\Omega$ pull-ups.

---

### Summary Checklist for Substitution

| Scenario | Can TXB0102 replace TXS0102? | Can TXS0102 replace TXB0102? |
| :--- | :--- | :--- |
| **I2C / Open-Drain Bus** | **No** (Will break bus operation) | **Yes** (Ideal application for TXS) |
| **SPI / UART / Push-Pull (High Speed > 24 Mbps)** | **Yes** | **No** (Too slow) |
| **GPIO / Push-Pull (Low Speed)** | **Yes** (Provided **no** external pull-up/down resistors exist) | **Yes** |




## ref 

- [[transistor-array-dat]] - [[transistor-dat]]

- [[BOM-dat]]