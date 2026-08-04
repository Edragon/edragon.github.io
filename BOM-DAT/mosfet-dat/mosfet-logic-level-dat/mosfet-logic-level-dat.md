
# mosfet-logic-level-dat.md


- [[motor-brushed-dat]] - [[motor-380-dat]] - [[motor-dat]] - [[mosfet-logic-level-dat]] - [[mosfet-dat]] - [[motor-driver-mosfet-dat]] - [[motor-driver-dat]] 



- **Use better MOSFET for 5V logic** - Replace with a true logic-level FET (e.g. **IRLZ44N**, **AOZ1284**, **AO3400**, **AOD4184A**). 



When using a 3.3V microcontroller (such as an ESP32, STM32, or Raspberry Pi Pico) to drive DC 380 motors via PWM, you must ensure the signal voltage matches the gate requirements of your MOSFETs.

---

## Key Terms Explained

### 1. Logic-Level MOSFET (e.g., IRLZ44N)
* **Standard MOSFETs (e.g., IRF540N, IRFZ44N)**: Require a gate-to-source voltage ($V_{gs}$) of **10V** to turn fully ON (achieve minimum internal resistance, $R_{ds(on)}$).
* **Logic-Level MOSFETs (e.g., IRLZ44N, AO3400)**: Specially designed to turn **fully ON** at low gate voltages (**3.3V to 5V**). The "L" in IRLZ44N stands for "Logic-level."

### 2. Intermediate Transistor / Gate Driver



* **Intermediate Transistor**: A low-cost NPN transistor (e.g., 2N2222 or S8050) used as a switch. The 3.3V GPIO pin controls the transistor, which then switches a higher voltage (e.g., 7.4V–12V from the battery) directly to the MOSFET gate.
* **Gate Driver IC (e.g., TC4420, EG2130)**: A dedicated driver chip that steps up the 3.3V GPIO signal to a higher voltage and delivers high peak current to rapidly charge and discharge the MOSFET gate capacitance.

---

## What Happens in Your RC Boat Circuit?

### Scenario A: Flawed Setup (3.3V MCU directly driving a Standard MOSFET like IRFZ44N)
1. **Signal Output**: The MCU pin outputs a 3.3V PWM signal.
2. **Partial Conduction**: Because a standard MOSFET requires 10V to fully saturate, 3.3V leaves it operating in its **linear (active) region**—it only turns "partially ON."
3. **High Resistance & Noise**: The MOSFET acts like a resistor in series with your motor. The 380 motor doesn't get enough current to turn at low PWM, causing it to **whine/buzz without spinning**.
4. **Overheating**: Electrical energy turns into heat inside the MOSFET, causing it to **get extremely hot and potentially burn out**.

### Scenario B: Fixed Setup with Logic-Level MOSFET (e.g., IRLZ44N)
1. **Signal Output**: The MCU pin outputs 3.3V.
2. **Full Conduction**: The logic-level MOSFET saturates completely at 3.3V, dropping its internal resistance ($R_{ds(on)}$) to a few milliohms.
3. **Result**: Full current flows to the 380 motor. Low-speed startup torque improves significantly, and the **MOSFET remains cool**.

### Scenario C: Fixed Setup with Intermediate Transistor / Gate Driver
1. **Signal Output**: The MCU pin outputs 3.3V to turn ON an intermediate transistor or gate driver.
2. **Voltage Step-Up**: The driver switches the main battery voltage (e.g., 7.4V–12V) directly to the MOSFET gate.
3. **Full Conduction**: The standard MOSFET receives 7.4V–12V on its gate, turning fully ON and providing maximum power to the motor without overheating.

---

## Action Plan

* **Check Your MOSFET Part Number**:
  * If using **IRFZ44N** or **IRF540N**: Replace them with **IRLZ44N** or **AO3400** (logic-level), OR add a transistor driver stage between your GPIO pin and the MOSFET gate.
  * If using **IRLZ44N**: Driven directly by 3.3V, it should perform well. Focus on adding a **20ms kickstart PWM pulse** in software to overcome motor static friction.



## ref 


