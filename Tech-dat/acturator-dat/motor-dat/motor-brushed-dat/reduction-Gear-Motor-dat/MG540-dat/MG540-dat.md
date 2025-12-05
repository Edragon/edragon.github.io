
# MG540-dat

## Features 

| specs                  | value    |
| ---------------------- | -------- |
| Gear Ratio             | 1:30     |
| Speed before reduction | 10000rpm |
| Speed after reduction  | 330rpm   |
| Rated current          | 1.44A    |
| Rated voltage          | **12V**  |
| Rated power            | 15W      |
| Rated torque           | 2.6kg.cm |
| Rated speed            | 280rpm   |
| Stall torque           | 10kg.cm  |
| Stall current          | 9A       |



## 🔧 Recommended Motor Driver Chips / Modules

### 1. **Texas Instruments DRV8871**
- **Continuous Current**: ~3.6 A  
- **Peak Current**: ~6 A  
- **Voltage Range**: 6.5V – 45V  
- **Protections**: Overcurrent, thermal, undervoltage  
- **Notes**: Simple, robust for your rated current  
- **Datasheet**: [DRV8871](https://www.ti.com/product/DRV8871)

- [[DRV8871-dat]]
  
---

### 2. **Pololu G2 High-Power Motor Driver (e.g., 18v17 / 24v13)**
- **Continuous Current**: 13–17 A  
- **Peak Current**: Much higher (survives stall easily)  
- **Voltage Range**: Up to 24V  
- **Notes**: Compact breakout board, heatsink recommended  
- **Link**: [Pololu G2 Motor Drivers](https://www.pololu.com/category/82/motor-drivers)

---

### 3. **ST VNH5019**
- **Continuous Current**: 12 A  
- **Peak Current**: 30 A  
- **Voltage Range**: 5.5V – 24V  
- **Protections**: Current limiting, thermal shutdown, undervoltage  
- **Notes**: High power, excellent for stall current  
- **Module**: [Pololu VNH5019 Board](https://www.pololu.com/product/1451)

---

### 4. ❌ **L298N (Not Recommended)**
- **Max Current**: ~2 A  
- **Very inefficient**, no current protection  
- **Conclusion**: **Not suitable** for 9 A stall motors

- [[L298-dat]]
---

## ✅ Key Selection Tips
- **Heatsink / cooling**: Needed for high current
- **PWM support**: For speed control
- **Protection features**: Essential for motor safety
- **Check voltage range**: Match with your motor power supply

## ref 

- [[dc-gear-motor-dat]] - [[motor-driver-dat]]

- [[MG540]] - [[dc-gear-motor]]