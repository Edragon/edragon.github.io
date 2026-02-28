
# motor-dat

- [[motor-driver-dat]]

- [[RC-kits-dat]]

- [[gearbox-dat]]


## motor specs 

- [[torque-dat]] - [[start-capacitor-dat]]

- [[RPM-dat]] - [[physics-dat]] - [[gear-dat]] - [[Sprocket-dat]] 

- [[wheel-hub-dat]] - [[wheel-dat]] - [[bearing-dat]]


## motor type 

brushed

- [[motor-brushed-dat]] == Permanent Magnet Brushed DC Motor

- [[reduction-Gear-Motor-dat]] - [[TT-motor-dat]] - [[MG540-dat]] - [[MG513-dat]] - [[reduction-Gear-Motor]]

- [[coreless-motor-dat]] 
  

[[motor-brushless-dat]]

- [[BLDC-motor-dat]]

- [[stepper-dat]] - [[servo-dat]]

- [[motor-Drum-brake-dat]]

- [[vibrator-dat]]

- [[FPV-motor-dat]]

- [[motor-linear-dat]]

| Type                           | Brushed / Brushless | Key Traits                                     | Application                              |
| ------------------------------ | ------------------- | ---------------------------------------------- | ---------------------------------------- |
| **Coreless DC motors**         | Brushed             | Very lightweight, fast acceleration            | Drones, medical tools, high-end RC       |
| **DC gear motors**             | Brushed             | Built-in gearbox for torque                    | Robotics, automation, lifting mechanisms |
| **Brushless DC motors (BLDC)** | Brushless           | Efficient, no brushes, often sensorless        | E-bikes, drones, industrial fans         |
| **Stepper motors**             | Brushless           | Precise, incremental rotation (not continuous) | 3D printers, CNC, camera sliders         |
| **Servo motors**               | Brushed / Brushless | DC motor + feedback + control board            | RC, robotics, automation                 |
| **Industrial DC motors**       | Brushed             | High voltage/power, long-duty cycles           | Conveyor belts, mills, elevators         |

## 🧱 Common Types

| Motor Type       | Gearbox Type     | Used For                     |
| ---------------- | ---------------- | ---------------------------- |
| Brushed DC motor | Planetary / Spur | Robotics, automation, wheels |
| Coreless motor   | Micro spur gear  | Micro robots, drones         |
| Stepper motor    | Harmonic / Worm  | Precision gear movement      |




## coreless Motor vs. Brushless Motor


| Feature                | Coreless Motor (Coreless DC Motor)               | Brushless Motor (BLDC)                       |
| ---------------------- | ------------------------------------------------ | -------------------------------------------- |
| **Rotor Design**       | No iron core (hollow cup winding)                | Rotor has permanent magnets                  |
| **Commutation**        | **Brushed** (mechanical commutator with brushes) | **Electronic** (uses sensors or controller)  |
| **Inertia**            | Very **low**, allowing fast response             | Moderate, depending on design                |
| **Efficiency**         | High (especially in low-power apps)              | Very high (especially at medium/high power)  |
| **Noise**              | Very **quiet** at low speed                      | Quiet, can produce high-frequency noise      |
| **Speed Response**     | Extremely **fast** acceleration/deceleration     | Fast, depends on controller and load         |
| **Lifespan**           | Limited (due to brush wear)                      | Long (no brushes = less wear)                |
| **Maintenance**        | May need brush replacement                       | Minimal maintenance                          |
| **Control Complexity** | Simple (direct voltage control)                  | Requires motor controller (ESC)              |
| **Size / Weight**      | Very compact and lightweight                     | Can be compact but larger for same power     |
| **Typical Voltage**    | Low (e.g. 3V, 6V, 12V)                           | Can handle higher voltages (12V–60V+)        |
| **Cost**               | Generally cheaper                                | More expensive due to controller and design  |
| **Best For**           | Micro motors, medical devices, toys, robotics    | Drones, RC vehicles, electric tools, e-bikes |


## brushed vs brushless 

Brushed PMDC vs. Brushless (BLDC) Motors

| Feature              | Brushed PMDC Motor (e.g., 775)         | Brushless DC Motor (BLDC)                        |
| :------------------- | :------------------------------------- | :----------------------------------------------- |
| **Commutation**      | Mechanical (via Carbon Brushes)        | Electronic (via ESC/Controller)                  |
| **Lifespan**         | Shorter (Brushes wear out over time)   | Very Long (Limited only by bearings)             |
| **Efficiency**       | Lower (Friction and heat from brushes) | Higher (Lower energy loss)                       |
| **Maintenance**      | Brushes may need replacement           | Maintenance-free                                 |
| **Complexity**       | Simple (Connect to DC power to run)    | Complex (Requires a specialized driver)          |
| **EMI/Noise**        | High (Arcing/sparks from brushes)      | Low (Clean electronic switching)                 |
| **Heat Dissipation** | Heat builds on the internal rotor      | Heat builds on the outer stator (easier to cool) |
| **Cost**             | Inexpensive                            | More Expensive                                   |


more comprehansive Brushed vs. Brushless DC Motors

| Feature               | Brushed PMDC Motor                  | Brushless DC Motor (BLDC)                        |
| :-------------------- | :---------------------------------- | :----------------------------------------------- |
| **Visual - Wires**    | **2 Wires** (Positive & Negative)   | **3 Wires** (Phases) + optional 5 sensor wires   |
| **Visual - Rotation** | Inrunner (Only the shaft spins)     | Inrunner or **Outrunner** (External shell spins) |
| **Commutation**       | Mechanical (Carbon Brushes)         | Electronic (Transistors/ESC)                     |
| **Internal View**     | Visible commutator and brush sparks | Copper coils (stator) and magnets (rotor)        |
| **Efficiency**        | ~75% - 80% (Lower due to friction)  | **~85% - 95%** (High efficiency)                 |
| **Lifespan**          | ~1,000 - 3,000 hours (Brushes wear) | **10,000+ hours** (Limited only by bearings)     |
| **Top Speed**         | Limited by brush friction/heat      | **Very High** (Limited by balance/bearings)      |
| **Torque/Weight**     | Moderate                            | **Superior** (High torque-to-weight ratio)       |
| **Control System**    | Simple DC Switch / PWM MOSFET       | Complex **ESC (Electronic Speed Controller)**    |
| **Cost**              | Low (Economy choice)                | Higher (Investment in controller + motor)        |
| **Example Models**    | 775, 550, 370 Motors                | Drone motors, Hoverboard Hubs, E-bike motors     |



## motor by purpose 

- [[motor-dat]] - [[waterpoof-dat]] - [[motor-waterproof-dat]]







## commerlized motor system demo 

![](2025-04-02-17-27-39.png)

![](2025-04-02-17-27-47.png)

![](2025-04-02-17-28-34.png)


## mechanical parts 

- [[shaft-coupler-dat]]



## Using Lower KV Motors on Mobula8

### 1. What KV Means
- KV = Motor RPM per volt (without load)
- Higher KV → faster motor spin → more aggressive flight
- Lower KV → slower spin → smoother, more controllable flight

---

### 2. Advantages of Lower KV Motors
- **Smoother indoor flight:** Slower response makes hovering and gentle maneuvers easier
- **Less vibration:** Easier to tune PID for stable flight
- **Lower heat & power draw:** Motors and ESCs run cooler, extending life
- **Longer flight time:** Less energy wasted on high-speed spinning

---

### 3. Disadvantages / Considerations
- **Less thrust:** Mobula8 might struggle with fast flips or aggressive maneuvers
- **Battery voltage match:** Lower KV may require slightly higher voltage (2S→3S) to maintain comparable thrust
- **Propeller size & pitch:** Lower KV works better with slightly larger or higher-pitch props, but Mobula8 frame limits size

---

### 4. Practical Notes
- Stock Mobula8 motors: **EX1103 KV11000**
- Lower KV options: **KV9000–KV10000** for smoother indoor flight
- ESCs must handle motor current; check your 4A–5A rating is sufficient

---

### 5. Summary
- ✅ **Indoor/cinematic flying:** Lower KV preferred
- ⚠️ **Freestyle/acro flying:** Might reduce agility
- Adjust **PID and throttle curves** in Betaflight after motor swap



## motor by voltage 

- [[li-battery-dat]] - [[4.2V-dat]] - [[motor-130-dat]]

- [[12V-dat]] - [[reduction-Gear-Motor-dat]]




## apps 

- [[vacuum-cleaner-dat]] - [[robot-dat]]



## ref 

- [[acturator-dat]]