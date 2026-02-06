
# 6-axis-dat


Accelerometer + Gyroscope == Inertial Measurement Unit

- [[3-axis-Accelerometer-dat]] + [[3-axis-gyroscope-dat]]

[legacy wiki page ](https://w.electrodragon.com/w/MPU)



## board 


- [[DAS1043-dat]]

- [[SMO1020-dat]] - [[MPU6050-dat]]


## chip 


- [[BMI323-dat]]

- [[ICM45686-dat]]

- [[ICM42688-dat]] - [[ICM42686-dat]] - [[invensense-dat]] - [[ICM20689-dat]]

- [[BMI270-dat]] == 3-4 usd 

- [[BMI160-dat]] == 1 usd
  
- [[bosch-dat]] 

- [[MPU6500-dat]] - [[MPU6050-dat]] - [[invensense-dat]] 

- [[MPU9250-dat]] 



- [[LSM6DS3-dat]] - [[ST-dat]] - [[ST-sensor-dat]] 

- QMI8658A == QMI8658A是一款完整的6D MEMS惯性测量单元（IMU）。QMI8658A的板级陀螺仪灵敏度偏差低至±3%，陀螺仪噪声密度为13 mdps/√Hz，且具有低延迟特性，非常适合消费类和工业应用。QMI8658A集成了一个3轴陀螺仪和一个3轴加速度计

- [[3-axis-Accelerometer-dat]] - [[3-axis-gyroscope-dat]]



The BMI160 integrates:

- 16 bit digital, triaxial accelerometer  
- 16 bit digital, triaxial gyroscope




## BMI160 BMI323 

The **BMI323** is the direct technological successor to the **BMI160**. While they share the same physical footprint, the BMI323 offers significant improvements in power efficiency, data handling, and ease of integration—especially for battery-operated projects like your Rover V2.

Expanded Comparison Table

| Feature              | **BMI160**     | **BMI323**          | **MPU6500**        | **LSM6DS3**     |
| :------------------- | :------------- | :------------------ | :----------------- | :-------------- |
| **Resolution**       | **16-bit**     | **16-bit**          | **16-bit**         | **16-bit**      |
| **Current (Active)** | ~925 µA        | **~790 µA**         | ~3.4 mA            | ~1.25 mA        |
| **FIFO Buffer**      | 1024 Bytes     | 2048 Bytes          | 512 Bytes          | **8000 Bytes**  |
| **Gyro Noise**       | 0.007 dps/√Hz  | **0.007 dps/√Hz**   | 0.01 dps/√Hz       | 0.008 dps/√Hz   |
| **Interface**        | I2C, SPI       | I2C, SPI, **I3C**   | I2C, SPI           | I2C, SPI        |
| **Self-Calibration** | Manual         | **Self-Trim (CRT)** | Factory Trim       | Manual          |
| **Key Advantage**    | Legacy support | Power efficiency    | **Onboard Fusion** | **Buffer Size** |



## APP 

- [[sensor-gesture-dat]]

## tech 

- [[I2C-dat]] - [[SPI-dat]]


## relevant 

- [[3-axis-gyroscope-dat]]


## ref 

- [[sensor-motion-dat]]

- [[sensor-motion]] - [[6-axis]]