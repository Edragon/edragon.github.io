

# MAVlink-dat



- [[OSD-dat]] - [[OSD-MSP-dat]]




How It All Connects Together


    [ Flight Controller ]  --(MAVLink Data)-->  [ ELRS Receiver ]
                                                    |
                                        (Wireless RF Signal)
                                                    v
    [ EdgeTX Screen / Yaapu ]  <--(Telemetry)--  [ ELRS Transmitter ]
                |
        (Wi-Fi / Bluetooth)
                v
    [ Ground Control Station ]



MAVLink transfers **much more than just telemetry data**. While real-time telemetry (GPS, battery, attitude, speed) is its most common use case, MAVLink is a complete bi-directional communication protocol designed to handle nearly every interaction between a drone, its components, and a ground station.

---

### What Data Does MAVLink Transfer?

MAVLink messages are divided into several functional categories:

#### 1. Telemetry and Status (Monitoring)

* **Vehicle State:** Position (lat/lon/alt), ground speed, heading, and attitude (pitch, roll, yaw).
* **Health & Diagnostics:** Battery voltage, current draw, remaining capacity, CPU load, and sensor status (IMU, compass, GPS lock).
* **Flight Mode:** Current mode (e.g., *Loiter*, *Return-to-Launch*, *Auto*, *Manual*).

#### 2. Command and Control (Action)

* **Flight Actions:** Arming/disarming motors, taking off, landing, triggering a parachute, or initiating an emergency RTL.
* **Mode Changes:** Switching the autopilot mode remotely.
* **Gimbal and Camera Control:** Pointing a camera, triggering the shutter for aerial photography, or starting/stopping video recording.

#### 3. Mission Planning and Waypoints (Navigation)

* **Upload/Download Waypoints:** Sending a full autonomous flight path (waypoints, altitude, speed, loiter times) from a ground control station to the drone.
* **Geofences and Safe Areas:** Uploading boundary coordinates to keep the drone within a specific operating zone.
* **Mission Progress:** Monitoring which waypoint the drone is currently heading toward or if it has encountered an error.

#### 4. Parameter Management (Configuration)

* **Reading/Writing Parameters:** Accessing thousands of low-level configuration settings inside the flight controller (e.g., PID tuning gains, failsafe voltage thresholds, sensor calibration offsets) directly from a laptop or phone without plugging in a USB cable.

#### 5. Payload and Companion Computer Data

* **Custom Dialects:** Developers use MAVLink to pass custom data packets between the flight controller and on-board companion computers (like a Raspberry Pi or AI vision module) for things like obstacle avoidance, target tracking, or spraying/dropping payloads.

---

### Summary

Think of MAVLink as the **operating system's network language** for the drone. It doesn't just broadcast how the drone is doing (telemetry); it also tells the drone *what to do* (commands/missions) and allows you to configure *how it thinks* (parameters).


## ref 

