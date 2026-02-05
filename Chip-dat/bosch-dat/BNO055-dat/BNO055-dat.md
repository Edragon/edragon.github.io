
# BNO055-dat


- [[9-axis-IMU-dat]] - [[bosch-dat]]

- [[logic-level-shifter-dat]]


Data Output
The BNO055 can output the following sensor data:

- Absolute Orientation (Euler Vector, 100Hz)
Three axis orientation data based on a 360° sphere

- Absolute Orientation (Quaterion, 100Hz)
Four point quaternion output for more accurate data manipulation

- Angular Velocity Vector (100Hz)
Three axis of 'rotation speed' in rad/s

- Acceleration Vector (100Hz)
Three axis of acceleration (gravity + linear motion) in m/s^2

- Magnetic Field Strength Vector (20Hz)
Three axis of magnetic field sensing in micro Tesla (uT)

- Linear Acceleration Vector (100Hz)
Three axis of linear acceleration data (acceleration minus gravity) in m/s^2

- Gravity Vector (100Hz)
Three axis of gravitational acceleration (minus any movement) in m/s^2

- Temperature (1Hz)
Ambient temperature in degrees celsius

The BNO055 is a smart sensor implementing an intelligent 9-axis absolute orientation sensor, which includes sensors and sensor fusion in a single package.

- 9DoF sensor
- Integrated MCU and Flash
- Integrated sensor data fusion


## SCH 

![](2026-02-05-20-25-27.png)


## ref 

- [[bosch-dat]]
