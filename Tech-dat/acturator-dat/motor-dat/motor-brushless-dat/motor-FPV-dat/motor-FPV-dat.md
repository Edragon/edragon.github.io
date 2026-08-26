
# motor-FPV-dat


- [[motor-brushless-dat]] - [[motor-FPV-dat]] - [[motor-FPV-mount-dat]] 

- [[FPV-build-dat]] - [[FPV-frame-dat]] - [[flight-controller-dat]] - [[motor-FPV-dat]] - [[propeller-FPV-dat]] - [[camera-FPV-dat]]

- [[motor-FPV-dat]] - [[DJI-neo-dat]]


- [[motor-dat]]

- [[motor-coreless-dat]] - [[propeller-dat]]

- [[ESC-dat]] - [[motor-FPV-dat]] - [[propeller-FPV-dat]]

## type by size 

### type 1106 

6～12A电调

### type 1306 

6～12A电调 == 10A 四寸桨 - [[ESC-dat]] - [[motor-FPV-dat]] - [[propeller-FPV-dat]]

### types 1504 

- 1x 1504 2300KV (4 mounting holes)
- 4x 1504 2300KV a set (4 mounting holes)
- 4x 1504 2300KV + insurance a set (4 mounting holes)

- 1x 1504 3600KV (4 mounting holes)
- 4x 1504 3600KV a set (4 mounting holes)
- 4x 1504 3600KV + insurance a set (4 mounting holes)

- 1x 1504 3800KV (3 mounting holes)
- 4x 1504 3800KV a set (3 mounting holes)
- 4x 1504 3800KV + insurance a set (3 mounting holes)


- [Benefits [and down sides] of HIGHER PWM Frequency! 🙀💪](https://www.youtube.com/watch?v=v3806Incpvo)

## types 220x

2204 

2212

2216 

1400KV / 980KV / 1250KV 

10寸浆 推荐3s 2200

## How to Reverse a 3-Wire Brushless Motor

### 1. Identify the motor wires

- Typically **3 wires** connected to ESC  
- Colors may vary → A, B, C (or random colors)  

---

### 2. Swap any **two wires**

- Example: swap **A and B**, leave C unchanged  
- This reverses motor rotation direction  




## how to prevent motor burning

- Don’t run **96 kHz** unless you’re sure your ESC can handle it.  
- Set **Motor Idle Throttle ~6%** to prevent stalling.  
- Keep an eye on **motor temperature after indoor flights** (touch test). Warm = ok, too hot to touch = dangerous.  
- Avoid flying with props bent / rubbing ducts indoors (adds load).  

## What Does 1400KV Mean in an FPV Motor?

In FPV drones, **KV** is a motor specification that indicates the motor’s speed constant.  

---

### ⚡ Definition of KV
- **KV (RPM/Volt)** = How many **Revolutions Per Minute (RPM)** the motor will spin **per 1 Volt applied**, without any load (no propeller).  

For example:  
- A **1400KV motor** spins **1400 RPM per Volt**.  
- If powered by a **4S LiPo (14.8 V)**:  
  
    1400 KV × 14.8 V ≈ 20,720 RPM (no load)

### 🔧 What It Means in Practice

1. **Lower KV (e.g., 1400KV)**
 - Spins slower per volt.
 - Provides more **torque** (good for larger props, longer flight times, heavy drones, cinewhoops).
 - Better for **efficiency** and carrying loads.

2. **Higher KV (e.g., 2800KV, 4000KV)**
 - Spins faster per volt.
 - Provides less torque, but more **speed**.
 - Good for **small props, racing, and high agility**.

---

### 🛠️ Typical Use Cases
- **1400KV motors** are usually found on:
- **Cinewhoops** with 3–5 inch props.
- **Long-range FPV drones** where efficiency and endurance matter.
- Drones designed to carry heavier cameras (e.g., GoPro).

---

### ✅ **Summary**:  
A **1400KV FPV motor** means the motor spins about **1400 RPM per volt** (unloaded). It is a **low-KV motor** designed for **larger props, more torque, and efficiency**, rather than raw speed.

## ref 

- [[FPV]] - [[FPV-motor]]