



# ESC-telemetry-dat

- [[motor-drive-protocols-dat]] - [[ESC-telemetry-dat]] - [[telemetry-dat]] - [[ESC-dat]]


**RPM Telemetry** is the English term for **RPM 遥测** (Rotational Speed Telemetry).

### Brief Overview:

* **Definition:** RPM telemetry is the technology where the Electronic Speed Controller (ESC) measures the motor's rotational speed (revolutions per minute, RPM) in real-time and transmits that data back to the flight controller via a signal line.
* **Core Functions:**
* **Dynamic Filtering (RPM Filter):** The flight controller uses real-time RPM data to precisely eliminate motor-induced vibrations and noise at specific frequencies, significantly improving flight stability and reducing motor heating.
* **Status Monitoring:** Allows pilots and ground stations to monitor the motor's rotational status in real-time.


* **Implementation:** In modern FPV setups, this is typically achieved by enabling the **Bidirectional DShot** protocol, which allows a single signal wire to handle both outgoing throttle commands and incoming telemetry data simultaneously.



## ref 

