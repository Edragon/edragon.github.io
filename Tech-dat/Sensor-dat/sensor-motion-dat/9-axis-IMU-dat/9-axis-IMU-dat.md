
# 9-axis-IMU-dat.md






## info 
- [[6-axis-dat]] + - [[3-Axis-Magnetic-dat]]


MPU6500 6 axis, Gyrometer & Accelerometer + QMC588s 3 axis, Magnetometer - [[3-Axis-Magnetic-dat]]

BMI270 6 axis, Gyrometer & Accelerometer + BMM150 3 axis, Magnetometer



LSM9DS1 9 Axis, Gyrometer, Accelerometer and Magnetometer

- BNO055

- [[MPU9255-dat]] - [[invensense-dat]]

- [[MPU9250-dat]]

- LSM9DS1


- [[3-axis-gyroscope-dat]] - [[3-Axis-Magnetic-dat]] - [[3-axis-Accelerometer-dat]]

The [[ITG320-dat]] (often paired as ITG3205) refers to a MEMS gyroscope IC, commonly found on the GY-85 sensor module, which integrates a 3-axis gyro (ITG3205), a 3-axis accelerometer ([[ADXL345-dat]]), and a 3-axis magnetometer ([[HMC5883L-dat]]) into a single 9-Degrees-of-Freedom (9DOF) Inertial Measurement Unit (IMU) for motion sensing in electronics projects, communicating via I2C. 

## AHRS VS IMU 

An AHRS (Attitude and Heading Reference System) sensor integrates 3-axis gyroscopes, accelerometers, and magnetometers to provide precise 3D orientation (pitch, roll, and yaw) for drones, robotics, and aircraft. These MEMS-based devices use sensor fusion algorithms (e.g., Kalman filters) to calculate orientation and correct for drift. 

Key Features and Functions
- 3D Orientation: Provides real-time data on pitch, roll, and heading (yaw).
- Sensor Fusion: Combines raw data from a 3-axis gyroscope (rate of rotation), 3-axis accelerometer (linear acceleration/gravity), and 3-axis magnetometer (magnetic north).
- Drift Correction: Uses algorithms to compensate for errors in individual sensors, reducing long-term inaccuracies.
- High-Rate Output: Delivers stable, dynamic orientation data, often used in autopilot and stabilization systems. 

Components of an AHRS
- Gyroscope: Measures angular velocity to track fast movements.
- Accelerometer: Measures gravitational force when stationary to determine tilt (pitch/roll).
- Magnetometer: Acts as a digital compass to determine heading (yaw). 

Applications
- Aviation: Provides solid-state, reliable attitude info to replace traditional mechanical gyros.
- Robotics & UAVs: Used for stabilization, navigation, and controlling unmanned vehicles.
- Marine: Used as a Motion Reference Unit (MRU) for navigation and maritime applications. 


### AHRS vs. IMU

While an Inertial Measurement Unit (IMU) only outputs raw data (acceleration/angular rate), an AHRS uses on-board processing to calculate and output actual orientation data (quaternions or Euler angles). 


## app 

- [[head-track]]


## ref 

- [[sensor-motion-dat]]