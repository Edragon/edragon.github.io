

# power-backfeeding-dat

- [[LDO-dat]]

When a quadruped robot attempts a dynamic movement like a diagonal trot, it can trigger a critical power failure sequence known as **backfeeding** or **reverse current**. This typically unfolds in four phases:

**1. The Transient Load**
When the four servos start moving simultaneously, they create a massive, instantaneous demand for electrical power. In engineering, this sudden spike in power demand from the motors is called a **transient load** or **peak current draw**.

**2. The Voltage Sag**
Because the battery and the boost converter cannot supply this massive amount of current instantly, the electrical "pressure" in the main power line drops. This sudden drop in the supply voltage is called a **voltage sag** (or **voltage dip**). For example, a stable 5V line might briefly collapse to 3V.

**3. Backfeeding / Reverse Current**
Because the main power line has sagged to 3V, the capacitor sitting next to the microcontroller (which is still fully charged at 5V) suddenly has a *higher* voltage than the main line. Since electricity always flows from high to low voltage, the energy stored in the capacitor flows backward, dumping into the main line to feed the hungry servos. The action of power flowing backward is called **backfeeding**, and the electricity itself is the **reverse current**.

**4. The Brownout Reset**
As the capacitor's energy is instantly drained by the servos, the voltage available to the microcontroller drops below its minimum operating requirement. Detecting this critically low voltage, the microcontroller triggers an automatic safety reboot. This specific type of crash is called a **Brownout Reset (BOR)**.

---
*Solution: Adding a Schottky diode between the main line and the capacitor acts as a one-way valve. It physically blocks the backfeeding so the capacitor's energy stays exclusively with the microcontroller, preventing the brownout.*


## ref 

