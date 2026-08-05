

# FPV-firmware-dat

- [[INAV-dat]] - [[ardupilot-dat]] - [[betaflight-dat]] - [[FPV-firmware-dat]] 


To make an FPV drone hover in a fixed position, lock its altitude, and automatically resist wind drift like a traditional camera drone, you cannot rely solely on standard Betaflight manual mode (Acro). 

You need a combination of **specialized hardware sensors**, a **navigation-focused flight controller firmware (such as INAV or ArduPilot)**, and correct **flight mode configurations**.



## 1. Hardware Requirements (Sensors)

To lock position in 3D space, the flight controller needs real-time spatial data from multiple sensors:

* **Latitude / Longitude Positioning (X/Y Axis Wind Resistance): GPS / GNSS Module** (M10 series recommended). The flight controller compares current GPS coordinates against the target position and automatically tilts the frame into the wind to counteract force vectors.
* **Altitude Holding (Z Axis): Barometer**. Standard GPS vertical accuracy is insufficient for precise altitude hold. A barometer measures subtle changes in atmospheric pressure to automatically modulate motor throttle.
* **Heading Lock (Yaw Axis): Compass / Magnetometer**. Prevents the drone from rotating or yawing off-target due to crosswinds. *(Required by INAV/ArduPilot for position hold).*
* **Indoor / Low-GPS Environments (Optional): Optical Flow + Rangefinder (Lidar/Ultrasonic)**. Tracks ground texture visually to eliminate position drift close to the ground or indoors where satellite signal is unavailable.

---

## 2. Flight Controller Firmware Comparison


- [[INAV-dat]] - [[ardupilot-dat]] - [[betaflight-dat]] - [[FPV-firmware-dat]] 



Standard FPV firmware varies in capability when it comes to autonomous position holding:

| Firmware | Position Hold Capability | Best Use Case |
| :--- | :--- | :--- |
| **INAV** *(Recommended)* | **Excellent**. Purpose-built for navigation. Native support for `NAV POSHOLD` and `NAV ALTHOLD` with smooth wind resistance algorithms. | Long-range FPV, cinematic cruising, observation platforms requiring stationary hovering. |
| **ArduPilot** | **Industrial Grade**. Highest accuracy and advanced features, but higher learning curve for setup and tuning. | Commercial inspection, heavy-lifter FPV, precise autonomous waypoints. |
| **Betaflight** | **Basic / Emergency Only**. Optimized for acro/freestyle and racing. BF 4.5+ has basic GPS Position Hold, but wind resistance is far less stable than INAV. | Freestyle drones using GPS strictly for emergency Return-to-Home (GPS Rescue). |

---

## 3. Flight Modes Configuration

In **INAV** or **ArduPilot**, map these flight modes to switches on your Radio Transmitter (e.g., RadioMaster):

1. **NAV ALTHOLD (Altitude Hold)**: 
   * The flight controller takes over throttle management using the barometer. 
   * Leaving the throttle stick centered keeps the drone at its current altitude automatically.
2. **NAV POSHOLD (Position Hold)**:
   * The flight controller manages Pitch, Roll, Yaw, and Throttle simultaneously.
   * When gusty winds push the drone away from its set coordinates, the PID navigation loop automatically tilts the frame to pull the drone back to the exact target location.

---

> **Pro-Tip to Avoid "Toilet Bowl Effect" (TBE):**  
> Install the GPS/Compass module on a elevated stalk away from high-frequency interference sources (such as the Video Transmitter / VTX or action cameras). Before taking off, ensure you have **10+ satellite locks** and an **HDOP lower than 1.5**.




## ref 


