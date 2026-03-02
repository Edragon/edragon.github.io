# camera-DVP-dat

- [[LDO-2CH-dat]]

- [[OV2640-dat]] - [[OV3660-dat]] - [[OV560-dat]] - [[omnivision-dat]]



## DVP Pin Mapping & Functional Equivalents

In DVP (Digital Video Port) camera sensors, many pins have synonymous names depending on whether the manufacturer uses industry-standard or proprietary labels.

| Standard Protocol | Camera Sensor Label | Function Description                                                                                     |
| :---------------- | :------------------ | :------------------------------------------------------------------------------------------------------- |
| **SDA**           | **SIO_D**           | **Serial Data:** The data line for the I2C-compatible SCCB interface used to configure camera registers. |
| **SCL**           | **SIO_C**           | **Serial Clock:** The clock signal for the I2C-compatible configuration interface.                       |
| **HSYNC**         | **HREF**            | **Horizontal Reference:** High when a valid row of pixels is being transmitted.                          |
| **XMCLK / MCLK**  | **XCLK**            | **External Clock:** The master heartbeat (usually 24MHz) provided by the MCU to drive the sensor.        |

---

### Critical Technical Nuances

#### 1. SCCB vs. I2C (SIO_D / SIO_C)
While **SIO_D/C** is physically identical to I2C, it often uses the **SCCB** (Serial Camera Control Bus) protocol.
* **Compatibility:** Most modern MCU I2C peripherals work fine, but some older sensors do not generate an "Acknowledge" (ACK) bit.
* **Fix:** If your MCU throws an I2C error, try disabling "ACK checking" in your driver code.

#### 2. Timing Reference (HSYNC vs. HREF)
* **HSYNC** is technically the pulse *between* lines.
* **HREF** is a "gate" signal that stays HIGH while data is valid on the Y2-Y9 (D0-D7) pins.
* **Wiring:** Connect your MCU's HSYNC input directly to the Sensor's HREF pin.



#### 3. The Master Clock (XCLK)
* The sensor will **not** respond to I2C (SIO_D) commands until it receives a stable XCLK signal.
* **Pro-tip for Rover V2:** Keep XCLK and PCLK traces as short as possible. High-speed clock lines can create EMI that might interfere with your sensitive **BMI323** IMU or **DRV8701** gate drivers if they are routed too closely.

#### 4. Power Sequencing
1. Apply Power (DVDD, AVDD, DOVDD).
2. Start **XCLK**.
3. Pulse **RESET** low.
4. Begin **SIO_D/C** configuration.



## **Can Y0/Y1 be NC?**
  Yes. This effectively truncates a 10-bit or 12-bit sensor output to 8-bit.

* **Key Technical Rules:**
  1. **Bit Alignment:** You must map the Sensor MSBs to the Processor D-pins.
     * Sensor Y9 -> Processor D7
     * Sensor Y8 -> Processor D6
     * ...
     * Sensor Y2 -> Processor D0
  2. **Truncation:** Y0 and Y1 are the LSBs (fine detail). Leaving them NC simply discards the lowest 4 levels of pixel data, which is standard for most 8-bit MCU/SoC interfaces.

* **Important Considerations:**
  * **Register Configuration:** You MUST configure the camera sensor (via I2C/SCCB) to output in 8-bit mode (e.g., YUV422 or RGB565).
  * **EMI Mitigation:** While NC works, terminating with a high-value pull-down resistor can improve signal integrity if you notice noise.
  * **Clocking:** The PCLK frequency remains identical; ensure your timing constraints in your firmware account for the 8-bit throughput.

* **Comparison Table (10-bit vs 8-bit):**

| Feature       | 10-bit (Full)            | 8-bit (Truncated)     |
| :------------ | :----------------------- | :-------------------- |
| Dynamic Range | 1024 levels              | 256 levels            |
| Compatibility | High (Requires 10+ pins) | Universal (8-pin bus) |
| Use Case      | High-end imaging         | Navigation/Tracking   |



## ref 

- [[camera-dat]]
- 