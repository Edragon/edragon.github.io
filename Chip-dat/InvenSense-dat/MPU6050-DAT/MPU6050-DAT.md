
# MPU6050 DAT

- interface [[I2C-dat]] 

- [[sensor-motion-dat]]

https://invensense.tdk.com/products/motion-tracking/6-axis/mpu-6050/


- Accelerometer (AX/AY/AZ) — converted to g by: accel_g = raw / 16384.0
- Gyroscope (GX/GY/GZ) — converted to °/s by: gyro_dps = raw / 131.0
- Temperature — converted to °C by: T = (raw / 340.0) + 36.53


## boards 

- [[MPU6050-dat]]




## SCH 

![](2024-03-26-16-29-25.png)

![](2025-08-19-17-08-52.png)



## code 

- [[MPU6050-code-1.ino]]

## ref 

- [[sensor-motion-dat]] - [[invensense-dat]]