
# MPU6050 DAT

- interface [[I2C-dat]] 

- [[sensor-motion-dat]] - [[6-axis-dat]]

https://invensense.tdk.com/products/motion-tracking/6-axis/mpu-6050/


- Accelerometer (AX/AY/AZ) — converted to g by: accel_g = raw / 16384.0
- Gyroscope (GX/GY/GZ) — converted to °/s by: gyro_dps = raw / 131.0
- Temperature — converted to °C by: T = (raw / 340.0) + 36.53

Plus derived values computed in the code:

Roll and Pitch from accelerometer (tilt relative to gravity).

Notes:

- Raw values are signed 16-bit (two registers per axis).
- For stable orientation you must fuse accel + gyro (complementary, Madgwick, Kalman) because accel gives inclination (no yaw) and gyro integrates to angle but drifts over time.
- You can change full-scale ranges (ACCEL_CONFIG / GYRO_CONFIG) — if you do, update the scale factors.



## boards 

- [[DAS1043-dat]]




## SCH 

![](2024-03-26-16-29-25.png)

![](2025-08-19-17-08-52.png)



## code 

- [[MPU6050-code-1.ino]]


## demo video 

- https://t.me/electrodragon3/428


## ref 

- [[sensor-motion-dat]] - [[invensense-dat]]