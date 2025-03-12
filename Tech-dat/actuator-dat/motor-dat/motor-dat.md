
# motor-dat

## How to identify the common port of a 4-wire motor: 

Use the resistance * 1 position of the multimeter to measure the four terminals separately. 

If the resistance value of one terminal is the smallest and equal to that of the other three terminals, then this terminal is the COM terminal, which is the common terminal. 

The driver board automatically identifies 3-wire or 4-wire brushless motors,  

4-wire brushless motors can also be connected without COM lines.


## BLDC motor with Hall sensors


### Hall Sensor Brushless Motor (有感无刷有霍尔马达)

A "**Hall Sensor Brushless Motor**" (有感无刷有霍尔马达) refers to a **BLDC motor with Hall sensors**, also known as a **sensored BLDC motor**.  

#### Explanation  
- **Brushless (BLDC):** The motor operates without carbon brushes, using electronic commutation, making it more durable and efficient than brushed motors.  
- **Sensored (Hall Sensors):** The motor has **Hall effect sensors** that detect the rotor's position, enabling precise commutation signals. This ensures **smooth operation, better torque control, and easier startup** compared to sensorless BLDC motors.  

#### Comparison: Sensored vs. Sensorless BLDC Motors  

| **Type** | **Sensored BLDC (With Hall Sensors)** | **Sensorless BLDC (Without Hall Sensors)** |
|---------|----------------------------------|---------------------------------|
| **Startup Performance** | Smooth startup, stable at low speeds | Difficult startup, vibrations at low speed |
| **Control Complexity** | Easier control, good for high-load applications | Requires advanced algorithms |
| **Common Applications** | E-bikes, electric scooters, industrial tools | High-speed, low-load applications like drones & fans |

#### Typical Applications  

- **Electric Vehicles (E-bikes, E-scooters):** Requires smooth low-speed control and high torque.  
- **Industrial Automation:** Used in robotics, CNC machines, and power tools.  
- **Home Appliances:** Found in inverter air conditioners and high-end fans.  

- [[hall-sensor-dat]]



## NEMA 23 Motor 

### NEMA 23 Motor Overview

A **NEMA 23** motor is a **stepper motor** with a standard **mounting flange size** defined by the **National Electrical Manufacturers Association (NEMA)**. It is widely used in CNC machines, 3D printers, robotics, and automation systems.

#### Key Features of NEMA 23 Motor

##### 1. Frame Size
- The **NEMA 23** standard specifies that the motor has a **2.3-inch (57.15mm) x 2.3-inch (57.15mm) faceplate size** for mounting.
- The **length of the motor varies**, affecting torque and power output.

##### 2. Stepper Type
- Most **NEMA 23 motors are stepper motors**, typically **1.8° per step** (200 steps per revolution), but variations exist.
- Some models have finer step angles (e.g., **0.9° per step**, 400 steps per revolution).

##### 3. Torque & Power
- The **torque** varies based on the motor length and current rating, typically ranging from **0.3 Nm to over 3.0 Nm**.
- Higher torque versions are often **longer and require higher current**.

##### 4. Voltage & Current
- Operates typically on **12V to 48V** (varies based on driver and application).
- Current ratings range from **2A to 6A per phase**, depending on the winding configuration.

##### 5. Shaft & Wiring
- Shaft diameter is usually **6.35mm (1/4 inch) or 8mm**.
- Common wiring configurations: **4-wire, 6-wire, or 8-wire** for unipolar or bipolar operation.

#### Common Applications of NEMA 23 Stepper Motors
- **CNC Machines** (milling, laser cutters, engraving machines)
- **3D Printers** (especially for larger or industrial-grade machines)
- **Robotics & Automation Systems**
- **Textile and Packaging Machines**
- **Conveyor Belt Systems**
