
# diode-flyback-dat

- [[diode-freewheeling-dat]] == FWD - [[diode-flyback-dat]]


In an **AC-DC converter (rectifier)** supplying an **inductive load** (such as a motor, relay coil, or transformer), **freewheeling** is the process where stored magnetic energy in the inductor is safely discharged through a local closed loop—usually via a **freewheeling diode (FWD)**—when the AC voltage swings negative or the active switches (thyristors/MOSFETs) turn off.

The diode used for this path is commonly called a **freewheeling diode (FWD)**, flyback diode, or kickback diode.

---

## Why Freewheeling is Necessary

An inductor opposes rapid changes in current ($v_L = L \frac{di}{dt}$). When the main AC rectifying switches or diodes turn off, the inductive load current cannot instantly drop to zero. Without a dedicated freewheeling path, several severe issues occur:

1. **High-Voltage Spikes (Flyback Spike):** The rapidly collapsing magnetic field generates a massive inductive voltage spike ($V = -L \frac{di}{dt}$), which can easily destroy rectifier diodes, thyristors, or transistors.
2. **Negative Output Voltage:** In controlled phase rectifiers (e.g., thyristor bridges), an inductive load pulls current past the AC zero-crossing, forcing the output voltage negative during parts of the cycle and lowering the net average DC output voltage and efficiency.
3. **High Current Ripple / Discontinuity:** The lack of a continuous path causes the load current to decay sharply, leading to torque ripples in motors or output instability in DC supplies.

---

## How It Works

A freewheeling diode (FWD) is connected in **anti-parallel** (reverse biased) across the inductive load:


            Main AC-DC Rectifier
            +----------------------+
      AC ~--|                      |---------+-------(+) Load
            | (Thyristors / Diodes)|         |
      AC ~--|                      |    [FWD Diode]   (Inductive Load: L + R)
            +----------------------+    (Anti-parallel) (e.g., Motor Winding)
                                          |
                                          +-------(-) Load


1. **Power Delivery Phase (Normal Conduction):** During the positive AC cycle when the rectifier supplies power, the freewheeling diode experiences a reverse bias voltage and remains **OFF (non-conducting)**, having no effect on normal operation.
2. **Freewheeling Phase (Energy Release):** When the AC input drops below zero or the switching device turns OFF, the polarity across the inductor instantly reverses (acting as a temporary power source). This **forward-biases** the freewheeling diode into conduction, allowing current to circulate internally through the "Load - FWD" loop until the stored magnetic energy is depleted.

---

## Key Benefits in Rectifier Circuits

| Aspect | Benefits of Freewheeling |
| :--- | :--- |
| **Component Protection** | Clamps high-voltage inductive transients to a safe forward voltage (~0.7 V) across the load. |
| **Increased Average Voltage** | Eliminates negative voltage regions in controlled rectifiers, boosting the overall average DC output voltage ($V_{dc}$). |
| **Continuous Current Flow** | Maintains continuous conduction mode (CCM), reducing current ripple, motor heating, and torque vibration. |
| **Improved Power Factor** | Prevents reactive energy from feeding back into the AC supply mains, enhancing the displacement power factor. |



## info 

== SS510 == [[RZ7886-dat]] 





## exaple == MBRF20100 == 🔧 Role of MBRF20100 in a Motor Driver

### 📘 Component Overview

| Parameter        | Value                    |
|------------------|--------------------------|
| Part Number      | MBRF20100                |
| Type             | Schottky Barrier Diode   |
| Max Voltage (VR) | 100V                     |
| Max Current (IF) | 20A                      |
| Package          | TO-220AC (or similar)    |
| Forward Drop     | ~0.75V (low Vf)          |

---

### 🔌 Purpose in Motor Driver Circuits

#### 1. 🛡️ Flyback (Freewheeling) Diode

**Motor coils are inductive.** When you suddenly switch off current, the collapsing magnetic field generates a **high voltage spike** (back-EMF) in the opposite direction.

🔁 The MBRF20100 provides a **safe path** for this current to flow:
- Prevents **voltage spikes**
- Protects **MOSFETs / BJTs / ICs**
- Helps motor **coast down smoothly** rather than abruptly stop

> Usually placed **in parallel with the motor or across switching MOSFETs**, with reverse polarity.

---

#### 2. 🔄 Freewheeling Path in H-Bridge

In an H-Bridge or half-bridge circuit:
- When one MOSFET turns off, the inductor (motor winding) forces current to keep flowing.
- MBRF20100 acts as a **freewheeling diode**, conducting the residual current until it dissipates.

This helps:
- Reduce switching losses
- Avoid voltage spikes
- Improve efficiency

---

### 3. ⚡ Reverse Polarity Protection

Sometimes used as a **reverse polarity protection diode** at the power input stage:
- Blocks current if polarity is reversed
- Protects the entire driver circuit

But note: This isn’t its most common role — it's more often used for **inductive load handling**.

---

### ✅ Why MBRF20100 Specifically?

- **20A / 100V** rating suits many medium/high-power motors
- **Schottky type** → fast switching, low forward voltage drop
- **High efficiency** (less heat vs. regular diodes)
- **TO-220** package → easy to heatsink for high current use

---

### 📐 Schematic Snippet (Freewheeling Example)

```
 V+ ---+
       |
      [Motor]
       |
      +++---+
      |     |
     GND   [MBRF20100]
             | |
             +-+
             |
            GND
```

- The MBRF20100 is in reverse-bias across the motor
- When the motor coil releases energy, the diode **conducts** to safely dissipate it

---

### 🧪 Summary

| Role                     | Description                                    |
|--------------------------|------------------------------------------------|
| Flyback diode            | Protects switch from inductive kickback        |
| Freewheeling diode       | Allows current to circulate in bridge drivers  |
| Reverse polarity guard   | Prevents damage on wrong power connection      |
| High current Schottky    | Fast, efficient, and heat-manageable           |



## ref 

- [[diode-dat]]