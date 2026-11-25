
# 6-axis-dat





Accelerometer + Gyroscope == Inertial Measurement Unit

- [[3-axis-Accelerometer-dat]] + [[3-axis-gyroscope-dat]]

[legacy wiki page ](https://w.electrodragon.com/w/MPU)



## board 


- [[DAS1043-dat]]

- [[SMO1020-dat]] - [[MPU6050-dat]]




## apps 

- [[flight-controller-dat]]


## chip 


其实， `MPU6050` 已经很老了

手上只有MPU6050，仍然能把原理学清楚。不过它已有正式停产通知，原厂列出的最后出货日期是2024年12月31日，新产品别再默认选它了。这里无广推荐结果我们使用过的产品，大家可以自行了解~

- ICM-42688-P:想在MCU上自己跑融合，可以评估；陀螺噪声较低，有官方驱动支持。
- ICM-45686:更在意功耗和较大量程，可以看它。
- LSM6DSV16X:提供片上六轴融合和四元数输出，可减少部分主机融合工作。
- BMI270:穿戴、手势和动作事件项目可以考虑，初始化注意配套配置数据和驱动。
它们都不是6050引脚、寄存器直接兼容的替换件。选型先看动作范围、噪声、功耗和接口，再查原厂资料与供货情况。


- [[ICM42605-dat]] - [[ICM20649-dat]] - [[ICM20689-dat]] - [[ICM45686-dat]] - [[ICM42688-dat]] - [[ICM42686-dat]] - [[invensense-dat]] - [[ICM20602-dat]]


- [[sensor-dat]] - [[sensor-motion-dat]] - [[6-axis-dat]]

- [[BHI360-dat]] - [[BMI323-dat]] - [[BMI270-dat]] - [[BMI088-dat]] - [[bosch-dat]] - [[6-axis-dat]] - [[BMI270-dat]] == 3-4 usd - [[BMI160-dat]] == 1 usd - [[BM1270-dat]] - [[BM160-dat]] 


- [[QMI8658A-dat]] - [[QST-dat]] - [[sensor-motion-dat]] - [[6-axis-dat]] 



- [[sensor-motion-dat]] - [[6-axis-dat]] - [[invensense-dat]]

- [[MPU6886-dat]] - [[MPU6500-dat]] - [[MPU6050-dat]] - [[invensense-dat]] - [[MPU9250-dat]] 


- [[LSM6DS3-dat]] - [[ST-dat]] - [[ST-sensor-dat]] - [[6-axis-dat]]

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