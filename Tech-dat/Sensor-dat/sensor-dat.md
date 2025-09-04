
# sensor-dat 

- [[Camera-dat]] - [[sensor-microphone-dat]]

- [[sensor-motion-dat]] - [[sensor-PIR-dat]] - [[radar-sensor]] - [[3-axis-Accelerometer-dat]] - [[3-axis-gyroscope-dat]] - [[3-axis-magnetic-dat]] - [[6-axis-dat]]

- [[RCWL-dat]] - [[sensor-TOF-dat]] - [[angle-encoder-dat]]

- [[gas-sensor-dat]]

- [[Peltier-dat]] - [[sensor-pressure-dat]] 

- [[sensor-temp-hum-dat]] - [[humidity-sensor]]

- [[sensor-temperature-dat]] - [[thermocouple-dat]] - [[thermostat-dat]] - [[sensor-RTD-dat]]


- [[power-sensor-dat]] - [[dc-current-sensor-dat]] - [[AC-voltage-monitor-dat]] - [[dc-voltage-monitor-dat]] - [[voltage-supervisor-dat]]


- [[actuator-dat]] - [[relay-dat]]

- [[hall-sensor-dat]] - [[angle-encoder-dat]]

- [[liquid-sensor-dat]] 

- [[sensor-pressure-dat]]




## Sell 

- [[SVC1010-dat]]



## 30 commonly used types of sensors

Here’s a list of 30 commonly used types of sensors, categorized by their typical applications:

### Temperature Sensors

- Thermocouples
- RTDs (Resistance Temperature Detectors) - [[sensor-RTD-dat]]
- Thermistors
- Infrared (IR) Temperature Sensors


### Pressure Sensors
- Barometric Pressure Sensors
- Piezoelectric Pressure Sensors
- Strain Gauge Pressure Sensors

### Proximity Sensors
- Inductive Proximity Sensors
- Capacitive Proximity Sensors
- Ultrasonic Sensors
- Photoelectric Sensors

### Motion and Position Sensors
- Accelerometers
- Gyroscopes
- Magnetometers
- Hall Effect Sensors

### Optical Sensors
- Photodiodes
- Phototransistors
- LIDAR Sensors
- Image Sensors (CMOS, CCD)

### Environmental Sensors
- Humidity Sensors
- Gas Sensors (e.g., CO2, CH4, NOx)
- Dust/Particulate Matter Sensors
- UV Sensors

### Flow Sensors
- Mass Flow Sensors
- Ultrasonic Flow Meters
- Turbine Flow Meters

### Sound and Vibration Sensors
- Microphones
- Piezoelectric Vibration Sensors

### Force and Weight Sensors
- Load Cells
- Force Sensitive Resistors (FSRs)

### Other Specialized Sensors
- Touch Sensors (e.g., Capacitive Touch Screens)
- pH Sensors
- RFID Sensors
- Biosensors (e.g., Glucose Sensors)



## Barometer for FPV Indoor Hovering

### ✅ What works
- Barometer measures **air pressure** → estimates altitude.
- Indoors, it can detect vertical movement and stabilize height.
- If Mobula8 flight controller has a baro, Betaflight/INAV can enable **Altitude Hold**.

### ⚠️ Limitations Indoors
1. **Air pressure fluctuations**  
   - Fans, air conditioning, or doors opening can confuse baro.
2. **Ground effect**  
   - Prop wash near the floor disturbs readings.
3. **No position hold**  
   - Baro only helps with *up/down*, not sideways drift.

### 🚀 Better Indoor Hovering Solutions
- **Optical Flow sensor (PMW3901)** → reduces drift.
- **Ultrasonic / LiDAR sensor** → more accurate low-altitude hold.
- **Angle Mode + Throttle Curve** → simplest option for smooth hover.

### 👉 Conclusion
- Barometer can help indoors, but not very stable.
- For DJI-like hands-free hover, you need **optical flow** (indoor) or **GPS** (outdoor). - [[sensor-optical-flow-dat]]
- Manual tuning in Angle Mode is usually best for Mobula8.



## ref 

- [[sensor]]

- [[tech-dat]]