
# LVDT-dat

- [[analog-device-dat]] 

An **LVDT** is a robust, frictionless electromechanical transducer that converts the rectilinear motion of an object into a corresponding electrical signal.



## 1. The LVDT Signal

The LVDT does not produce a simple DC voltage. Instead, it operates on the principle of **magnetic induction**.

### Signal Generation
* **Excitation:** A primary coil is energized with an AC reference signal (typically 1–10 kHz).
* **Induction:** Two secondary coils, placed on either side of the primary, pick up the induced voltage via a movable ferromagnetic core.
* **Differential Output:** The secondaries are wired in "series-opposition." The output voltage is the difference between them: 
    $$V_{out} = V_{S1} - V_{S2}$$

### Signal States
1.  **Null Position:** When the core is centered, $V_{S1} = V_{S2}$, resulting in **0V output**.
2.  **Positive Displacement:** Moving one way increases $V_{S1}$ and decreases $V_{S2}$. The output is **in-phase** with the excitation.
3.  **Negative Displacement:** Moving the other way increases $V_{S2}$. The output is **180° out-of-phase** with the excitation.



## AD698

[Universal LVDT Signal Conditioner](https://www.analog.com/media/en/technical-documentation/data-sheets/ad698.pdf)

The AD698 is a complete, monolithic Linear Variable Differential Transformer (LVDT) signal conditioning subsystem. 

It is used in conjunction with LVDTs to convert transducer mechanical position to a unipolar or bipolar dc voltage with a high degree of accuracy and repeatability. 

All circuit functions are included on the chip. 

With the addition of a few external passive components to set frequency and gain, the AD698 converts the raw LVDT output to a scaled dc signal. The device will operate with half-bridge LVDTs, LVDTs connected in the series opposed configuration (4-wire), and RVDTs.


## 2. Common Applications

LVDTs are chosen for "mission-critical" environments where failure is not an option and precision is mandatory.

### **Aerospace & Aviation**
* **Fly-by-Wire Systems:** Feedback for flight control surfaces (ailerons, elevators).
* **Cockpit Controls:** Sensing pilot input on joysticks and pedals.
* **Engine Management:** Measuring fuel flow valve positions.

### **Industrial Automation**
* **Roll Gap Measurement:** Controlling the thickness of steel, paper, or plastic during manufacturing.
* **CNC Metrology:** Highly accurate dimensional inspection of machined parts.
* **Hydraulic Cylinders:** Integrated into actuators to provide precise position feedback.

### **Power Generation**
* **Turbine Control:** Monitoring the position of steam inlet valves in power plants.
* **Structural Health:** Measuring minute shifts in dam walls or bridge supports over decades.



## ref 

- [[signal-dat]]