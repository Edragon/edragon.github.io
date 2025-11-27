# Hub Motor Data

A hub motor is a type of motor integrated with the wheel, commonly used in electric bicycles, scooters, and other light electric vehicles. The hub motor is built into the wheel hub, eliminating the need for a traditional transmission system. This design offers several advantages, including reduced mechanical complexity, lower maintenance requirements, and improved efficiency.

## Key Differences: Three-Phase Motor vs. Hub Motor

**Core Point:**

A hub motor is essentially a three-phase brushless motor (BLDC/PMSM) with a different structure. They are not two completely different motors, but differ in application scenario and physical structure.

## 1. Definition Comparison

| Item       | Three-Phase Brushless Motor (BLDC/PMSM)  | Hub Motor                                |
| ---------- | ---------------------------------------- | ---------------------------------------- |
| What is it | A type of motor (control method)         | A packaging structure                    |
| Shape      | Cylindrical, fixed shell, rotating shaft | Rotating shell (outer rotor)             |
| Function   | Provides power                           | Integrated motor + wheel                 |
| Control    | Needs controller                         | Also needs controller (same three-phase) |

So, a hub motor is not a different kind of motor, but:

👉 A special structure of three-phase brushless motor (outer rotor + integrated wheel)

## 2. Structural Differences (Key Point)

### Ordinary Three-Phase Brushless Motor (Inner Rotor)
- Stator outer ring → coil
- Center → rotor with magnets
- Rotor (shaft) rotates
- The whole motor is fixed to the vehicle body
- Similar to brushless RC motors, brushless drill motors

### Hub Motor (Outer Rotor)
- The wheel shell itself is the rotor (with magnets)
- The stator coil is fixed inside
- The whole shell rotates together, so "when the wheel turns, the motor turns"
- Thus, the motor and wheel are integrated, very compact

## 3. Different Application Scenarios

| Ordinary Three-Phase BLDC                | Hub Motor                                                 |
| ---------------------------------------- | --------------------------------------------------------- |
| Drones, robots, power tools, pumps, fans | Electric scooters, e-bikes, e-motorcycles, Xiaomi Ninebot |
| Not integrated with wheel                | Directly is the wheel                                     |
| Needs reduction gears or belt            | Mostly direct drive                                       |

## 4. Performance Differences

### ✔ Advantages of Hub Motors
- Quiet (sine wave + sealed structure)
- Maintenance-free
- Dustproof and waterproof
- High torque, good at low speed
- High space utilization (no need to place motor in frame)

### ❌ Disadvantages of Hub Motors
- Heavier (adds unsprung weight to the wheel)
- Harder to dissipate heat (heat is not easily transferred to the frame)
- Slightly lower efficiency at high speed (wheel is large and heavy)

### ✔ Advantages of Ordinary Three-Phase BLDC
- Light, good heat dissipation
- Can add reduction gear for more flexible speed/torque
- More commonly used in robots, EV drive axles
- More space for maintenance, easy to replace gears and bearings

### ❌ Disadvantages of Ordinary BLDC
- Needs transmission mechanism (gear/belt)
- Slightly noisier
- More parts, larger size

## 5. In One Sentence

A hub motor = a special structure (outer rotor) three-phase brushless motor used in wheels.
Three-phase motor is a category; hub motor is an application.



## ref 

- [[motor-BLDC-dat]] - [[FOC-dat]]