
# ESC-dat

- [[ESC-dat]] - [[VESC-dat]] - [[motor-driver-dat]] - [[FOC-dat]]


- [[RC-kits-dat]]


- **Electronic Speed Controller (ESC)**: Controls the speed of the motors by adjusting the power supplied to them. ESCs are essential for smooth and responsive flight.


![](2025-09-13-15-48-28.png)



## Using a Single ESC for a 200W BLDC Motor

A **single ESC** (Electronic Speed Controller) is the standard way to control a 200W BLDC motor. Since you are aiming for high torque and smooth operation, here is how to select and use one professionally:

#### 1. Key Specifications to Match
To prevent the ESC from overheating, you must match the current (Amps) to your power goal:
* **The Math:** $Current (A) = \frac{Power (200W)}{Voltage (V)}$
* **Recommended Buffer:** Always choose an ESC with a current rating **2x higher** than your calculated continuous current to handle torque spikes.

| Battery Voltage | Continuous Amps | Recommended ESC Rating |
| :--- | :--- | :--- |
| **12V** | 16.7 A | **35A - 40A** |
| **24V** | 8.3 A | **20A - 25A** |
| **36V** | 5.5 A | **15A - 20A** |

---

#### 2. Why "Robotics" ESCs are better than "Drone" ESCs
For a project involving an 8mm shaft and gear reduction, **avoid standard Drone ESCs**. They are optimized for high RPM, not low-speed torque.

* **Best Professional Choice:** **VESC (Vedder ESC)**. It is designed for high-torque applications, supports **FOC** (silent and smooth), and is highly programmable.
* **Sensored Control:** If your motor has Hall sensors (5 small wires), use a **Sensored ESC**. This allows the motor to start smoothly under heavy load without "shuddering."



---

#### 3. Connection Setup
A single ESC acts as the "middleman" in your system:
1.  **Input:** Connected to your Battery (XT60 or XT90 connectors).
2.  **Output:** Three thick wires (Phases A, B, C) connected to the motor.
3.  **Control:** A signal wire (PWM/PPM or UART) connected to an Arduino, ESP32, or a remote receiver.

- [[VESC-dat]]

---

### Summary for your 200W Setup:
* **Driver Method:** Use **FOC** for the best torque delivery.
* **Hardware:** A **VESC 4.12** or **Mini VESC** is perfect for 200W.
* **Safety:** Ensure you have a common ground between the ESC and your controller.


## ref 

- [[acturator-dat]]