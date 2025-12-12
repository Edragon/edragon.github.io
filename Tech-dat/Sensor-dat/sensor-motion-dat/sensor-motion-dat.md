
# motion-sensor-dat

- [[3-axis-gyroscope-dat]] - [[3-axis-Accelerometer-dat]] - [[3-Axis-Magnetic-dat]]
 
- [[6-axis-dat]] - [[bosch-dat]]

- [[sensor-hall-dat]]


## chips 

- [[isentek-dat]] - [[st-sensor-dat]] - [[bosch-dat]] - [[InvenSense-dat]] - [[amsys-sensor-dat]]

- [[qstcorp-dat]]

## sensor proximity 

- [[sensor-lidar-dat]] - [[sensor-radar-dat]] - [[sensor-pir-dat]] - [[sensor-ultrasonic-dat]] - [[sensor-TOF-dat]] 

- [[sensor-radar-Millimeter-wave-dat]]

- [[sensor-camera-dat]]


## Sensor Comparison Table

- [[sensor-radar-dat]]

|                   | **PIR**                                                                                                             | **RCWL**                                                                                      | **Radar**                                                                                                 | **Lidar**                                                                                                       |
| ----------------- | ------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------- |
| **Features**      | - Detects infrared radiation from warm objects<br>- Simple motion sensor                                            | - Microwave Doppler radar<br>- Detects motion through some materials                          | - Uses radio waves<br>- Measures distance, speed, direction                                               | - Uses laser pulses<br>- Creates 3D maps<br>- High accuracy                                                     |
| **Advantages**    | - Low cost<br>- Low power<br>- Reliable for basic motion detection                                                  | - Works in darkness<br>- Senses through plastic/glass<br>- Wide angle<br>- Sensitive movement | - Works in all lighting/weather<br>- Long range<br>- Detects moving/stationary<br>- Penetrates fog/smoke  | - Detailed 3D mapping<br>- Fast response<br>- Accurate shape/surface detection                                  |
| **Disadvantages** | - Limited range<br>- Cannot detect through walls/glass<br>- Affected by temperature<br>- Only detects living things | - False positives (fans, pets)<br>- Affected by metal<br>- May trigger on non-human motion    | - More expensive<br>- Complex<br>- Needs calibration<br>- Can be affected by electromagnetic interference | - Expensive<br>- Affected by rain/fog/dust<br>- Limited in bright sunlight<br>- Cannot penetrate opaque objects |


For detecting a wide range of moving objects, radar sensors are generally the best choice. According to your comparison table, radar sensors offer:

- Long range detection
- Ability to detect both moving and stationary objects
- Operation in all lighting and weather conditions
- Penetration through fog and smoke

These features make radar sensors highly suitable for wide-area motion detection, especially in environments where lighting or weather may vary.

Your table currently lists PIR, RCWL, Radar, and Lidar sensors. Common motion-detecting sensors missing from this comparison include:

- Ultrasonic sensors (use sound waves for motion and distance detection) - [[sensor-ultrasonic-dat]]
- TOF (Time-of-Flight) sensors (use light pulses for distance and motion detection) - [[sensor-TOF-dat]]
- Camera-based (vision) sensors (detect motion via image processing) == [[camera-dat]] - [[vision-dat]]
- Accelerometers (detect movement or vibration, often used in mobile devices) - [[3-axis-accelerometer-dat]]
- Gyroscopes (detect rotational motion) - [[3-axis-gyroscope-dat]]


## distance measurement 



## board 

most simple motion sensor 

- [[SMO1040-dat]]



## Chip 

- [[VI5300-dat]]

| Models   | price      |
| -------- | ---------- |
| LIS3DHTR | 30+: ￥2.17 |

- [[3-Axis-Magnetic-Sensor-dat]] - [[3-axis-Accelerometer-dat]] - [[3-axis-gyroscope-dat]] - [[sensor-pressure-dat]]

- [[6-axis-dat]][[sensor-TOF-dat]]

- [[RCWL-sensor-dat]] - [[TOF-sensor-dat]] - [[LiDAR-sensor-dat]]

- [[ultrasonic-sensor-dat]]


## Motion sensor types 

[[sensor-TOF-dat]]

- [[accelerometer-dat]] - [[gyroscope-dat]] - [[magnetometer-dat]] - [[PIR-sensor-dat]] - [[radar-sensor]] - [[TOF-sensor-dat]] - [[LiDAR-sensor-dat]] - [[compass-sensor-dat]]




## sensor combination  

| Board           | sensor 1         | func1                  | sensor 2       | func2                                                |
| --------------- | ---------------- | ---------------------- | -------------- | ---------------------------------------------------- |
| [[SMO1011-dat]] | [[HMC5983-dat]]  | [[compass-sensor-dat]] | [[BMP180-dat]] | [[sensor-pressure-dat]] - [[temperature-sensor-dat]] |
| [[SMO1013-dat]] | [[MAX30102-dat]] | [[pulse-rate-dat]]     |                |                                                      |  


## other 

Principle of Tilt Sensors

Tilt sensors are often used for horizontal measurement in systems. Based on their working principles, they can be divided into three types: "solid pendulum" type, "liquid pendulum" type, and "gas pendulum" type tilt sensors. Their working principles are introduced below.



## ref 

- [[sensor]] - [[motion-sensor]] - [[m]]


