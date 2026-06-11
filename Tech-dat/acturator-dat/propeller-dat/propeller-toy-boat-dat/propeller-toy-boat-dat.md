

# propeller-toy-boat-dat

- [[propeller-toy-boat-dat]] - [[propeller-dat]] - [[rc-boat-dat]] - [[acturator-dat]] 

The propellers for Remote Control (RC) toy boats are primarily determined by two core parameters: **Diameter** and **Pitch**. Understanding these two parameters is crucial for optimizing the boat's speed and protecting the electronics.

When designing or modifying a boat's power system, it's much like calculating gear ratios and wheel diameters for a wheeled vehicle—the propeller size must perfectly match the motor's KV rating and the Electronic Speed Controller's (ESC) power capacity. Otherwise, it is very easy to burn out the hardware due to excessive load and current spikes.

Here is a detailed breakdown of the relationship between size and speed:

### 1. Common Propeller Sizes
Propeller sizes are usually denoted by "Diameter" or "Pitch Ratio × Diameter" (e.g., 35mm or 1.4×35).

* **Micro toy boats:** Diameter usually ranges from 15mm - 25mm.
* **Common racing boats (e.g., tens of centimeters long):** Diameter is mostly 30mm - 45mm.
* **Large/Custom power boats:** Diameter can reach 50mm - 70mm or more.
* **Shaft Diameter:** When purchasing, you also need to note the diameter of the center hole. Common motor shaft/drive shaft diameters are 3mm, 3.18mm (1/8 inch), 4mm, and 4.76mm (3/16 inch).

### 2. How Does Size Affect Speed?

The impact of the propeller on speed is a physical process that requires balancing **thrust, speed, and motor load**.

**1. Impact of Diameter**

Diameter refers to the width of the circle drawn by the propeller when it rotates.
* **Speed and Thrust:** The larger the diameter, the more water is displaced per revolution, providing greater thrust (water grip). Assuming the motor has sufficient performance, a larger diameter means a higher top speed and better acceleration.
* **Side Effects (Load):** For every slight increase in diameter, the demand for motor torque rises exponentially. If you forcefully put a large prop on a small motor (commonly known as "overloading"), the motor's RPM will be severely dragged down, leading to a massive increase in heat, which may eventually burn out the motor or the ESC.

**2. Impact of Pitch**

Pitch refers to the theoretical distance the propeller would advance forward in one revolution under ideal conditions (no slip). It is often expressed as a "Pitch Ratio" (Pitch / Diameter), with common ratios ranging from 1.2 to 1.6.
* **High Pitch (e.g., 1.6):** Yields a higher theoretical top speed. However, it struggles to "grip" the water at low speeds, resulting in slower off-the-line acceleration. It also significantly increases the current load on the motor.
* **Low Pitch (e.g., 1.2):** Provides great off-the-line explosive power, fast acceleration, lighter motor load, and lower heat generation, but the ultimate top speed is lower.

**3. Number of Blades: Two-Blade vs. Three-Blade Propellers**

* **Two-Blade Propellers:** Lowest resistance and highest efficiency. They typically achieve the highest top speed and are the standard setup for racing boats.
* **Three-Blade Propellers:** Smoother operation, better off-the-line acceleration, and stronger water grip due to the extra blade. However, water drag is slightly higher at high speeds, so the top speed is usually slightly inferior to a two-blade prop of the exact same size.

---

To help you visualize how these parameters interact, here is the interactive simulator code to calculate the theoretical speed and motor load based on your inputs:

```json?chameleon
{"component":"LlmGeneratedComponent","props":{"height":"600px","prompt":"Objective: Create an interactive RC boat propeller simulator to visualize the relationship between diameter, pitch, motor RPM, and the resulting speed and motor load.\n\nData State:\ninitialValues: {\n  diameter: 35,\n  pitchRatio: 1.4,\n  motorRpm: 25000\n}\n\nStrategy: Standard Layout.\n\nInputs:\n1. Slider for 'Propeller Diameter' ranging from 20 to 60 mm.\n2. Slider for 'Pitch Ratio' ranging from 1.0 to 1.8.\n3. Slider for 'Motor RPM' ranging from 10000 to 50000 RPM.\n\nBehavior:\n- Calculate 'Theoretical Speed': Speed (km/h) is roughly (Diameter * Pitch Ratio * Motor RPM * 60) / 1000000. Display this prominently.\n- Calculate 'Motor Load': Load is proportional to (Diameter^3 * Pitch Ratio * Motor RPM^2). Normalize this to a 0-100% scale based on the maximum possible slider values.\n- Display a visual gauge or progress bar for 'Motor Load'. As the load exceeds 75%, change the visual indicator to warn of 'Overheating Risk'.\n- Display a bar for 'Hole-shot Acceleration': Higher diameter and lower pitch ratio yield better acceleration. Higher pitch ratio decreases this score.\n- Ensure all text, labels, and warnings are in English.","id":"im_c21c8d50ea5cccb3"}}



## ref 

