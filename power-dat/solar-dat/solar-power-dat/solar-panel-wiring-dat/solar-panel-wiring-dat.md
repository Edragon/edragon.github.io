

# solar-panel-wiring-dat.md


## basic diode bypass protection 

![](2026-05-21-19-51-41.png)


you will need following accessories to connect the solar panel to your controller or battery:

- [[diode-dat]] - [[1N4007-dat]] 

- [[cable-dat]]


## solar panel series wiring 


You can think of each solar panel as an individual AA battery. When you connect them in series, their electrical characteristics change as follows:

---

### 1. Electrical Rules of Series Connection

*   **Voltage (V) Adds Up:** The total voltage is the sum of the voltages of each individual panel.
*   **Current (A) Stays the Same:** The total current remains equal to the current of a single panel (assuming all panels are identical).

> **Formulas:**
> V_total = V1 + V2 + ... + Vn
> I_total = I1 = I2 = ... = In

For example, if you have **two 18V 5A solar panels**:
*   **In Series:** The voltage becomes **36V**, while the current remains **5A**. The total power is 36V * 5A = 180W.
*   **Wiring Method:** Connect the **positive (+)** terminal of the first panel to the **negative (-)** terminal of the second panel. The remaining negative terminal of the first panel and the positive terminal of the second panel will then connect to your controller.

---

### 2. Key Advantages of Boosting Voltage via Series Connection

*   **Reduced Line Loss (Higher Efficiency):** Power loss in wires is proportional to the square of the current. By increasing the voltage and keeping the current low, you significantly reduce energy loss as heat, allowing you to use thinner wires over longer distances.
*   **Easier to Trigger Controller Charging:** Advanced controllers, like MPPT (Maximum Power Point Tracking) controllers, typically require the solar array voltage to be a few volts higher than the battery voltage (usually 2V to 5V higher) to begin charging. Boosting the voltage via series connection helps the system hit that startup threshold much earlier in the morning or during overcast days.

---

### 3. ⚠️ Critical Pitfalls to Avoid

While connecting panels in series is straightforward, there are two crucial pitfalls that can drastically drop efficiency or even damage your gear:

*   **The "Weakest Link" Effect (Barrel Philosophy):** The total current of a series string is bottlenecked by the **lowest current panel** in that string. If you connect a 5A panel in series with a 2A panel, the entire system's current is forced down to 2A. Furthermore, **if even one panel is partially shaded by a tree branch or debris, the output of the entire string drops drastically.** Because of this, panels in a series string should always have identical specs, face the same direction, and share the same angle.
*   **Never Exceed the Controller's Maximum Input Voltage (Voc):** When a solar panel is uncovered but disconnected from a load, its voltage hits a peak called Open-Circuit Voltage (Voc). When calculating your total series voltage, **you must add up the Voc values of the panels**. Ensure this total sum stays safely below the "Max DC Input Voltage" listed on your solar charge controller or inverter, otherwise, a bright sunny day could permanently fry your equipment.




## ref 

