


# VOFA-plus-dat


- [[SDK-dat]] - [[serial-dat]] - [[SDK-serial-dat]] - [[VOFA-plus-dat]]


**VOFA+** is a free, plugin-driven **serial & network debugging tool (上位机)** widely used in embedded systems and microcontroller development (such as STM32, ESP32, and Arduino).

* **Gutega** is the developer/author behind VOFA+ (their open-source plugin and widget repository is hosted under `[gitee.com/gutega/Vodka](https://gitee.com/gutega/Vodka)`).
* **1.3.10** is a specific software release version of VOFA+.

### What it is used for

Instead of just printing raw text like a basic serial monitor, VOFA+ lets you visualize and interact with real-time data coming from a microcontroller over **Serial (UART)** or **TCP/UDP**:

* **Real-Time Waveforms / Oscilloscope:** Plot sensor data, motor speeds, or filter outputs (like a Kalman filter's raw vs. filtered curve) live as graphs.
* **Interactive Controls:** Drag sliders, toggle buttons, and turn knobs on your screen to tune parameters—like PID gains—on the fly without reflashing firmware.
* **3D Attitude & Image Viewing:** Visualize 3D orientation (pitch, roll, yaw) from IMU sensors or stream camera frames directly from embedded boards.
* **Custom Protocols:** Supports simple text/CSV formatting (`FireWater`), high-speed binary floats (`JustFloat`), or raw serial text (`RawData`).



## ref 