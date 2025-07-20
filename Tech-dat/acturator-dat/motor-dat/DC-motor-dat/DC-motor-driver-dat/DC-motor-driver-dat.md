
# DC-motor-driver-dat

- [[ULN2003-dat]] - [[ULN2803-dat]]

- [[Darlington-transistor-array-dat]] - [[transistor-array-dat]] - [[transistor-dat]] - [[MOSFET-dat]] - [[IGBT-dat]]

- [[L9110S-dat]]

- [[L298-dat]] - [[L293-dat]]

- [[TB6612-dat]]

- [[DRV8833-dat]] / [[DRV8871-dat]] / [[DRV8835-dat]] / [[DRV8825-dat]] == [[TI-motor-dat]]

- [[LV8548-dat]] == [[onsemi-dat]]


## 🧾 Summary Table

| Chip          | Max Current         | Motor Voltage | Direction | PWM Speed | Footprint / Package         | Notes                                |
| ------------- | ------------------- | ------------- | --------- | --------- | --------------------------- | ------------------------------------ |
| **L9110S**    | ~800 mA             | 2.5–12V       | ✅         | ✅         | DIP-8 / SOP-8 Module        | Compact, easy to use, basic driver   |
| **L298N**     | 2A (peak: ~3A)      | 5–35V         | ✅         | ✅         | Multiwatt-15 / Module board | Large, needs heat sink               |
| **L293D**     | 600 mA (peak: 1.2A) | 4.5–36V       | ✅         | ✅         | DIP-16 / SOIC-16            | Basic H-bridge with built-in diodes  |
| **TB6612FNG** | 1.2A (3.2A peak)    | 2.5–13.5V     | ✅         | ✅         | SSOP-24 / Module breakout   | Efficient, compact, modern choice    |
| **DRV8833**   | 1.5A (peak: 2A)     | 2.7–10.8V     | ✅         | ✅         | HTSSOP-16 / QFN             | Compact, protected, 2-channel driver |
| **DRV8871**   | 3.6A (peak: 6A)     | 6.5–45V       | ✅         | ✅         | SOIC-8 / MSOP               | Single channel, higher power         |

- THB6128




### # ✅ Common Features of DC Motor Driver Chips

These are essential or desirable features for a DC motor driver IC, especially for brushed DC motors (like 130/230 motors):

### 🔁 1. Bidirectional Drive
- Allows motor to rotate **clockwise (CW)** and **counter-clockwise (CCW)**
- Requires an **H-bridge** circuit internally

### 🎚️ 2. PWM (Pulse Width Modulation) Support
- Enables **speed control** by adjusting duty cycle
- Most drivers support PWM input on EN or IN pins

### 🧠 3. Input Logic Compatibility
- Accepts standard **3.3V or 5V** logic signals from microcontrollers (Arduino, Raspberry Pi, ESP32, etc.)

### 🔐 4. Built-in Protection Features
- **Overcurrent protection**: Prevents damage from short circuits or heavy loads
- **Thermal shutdown**: Protects the IC from overheating
- **Undervoltage lockout**: Disables the chip if supply voltage drops too low

### 📈 5. Current Rating
- Should handle the **motor's stall current** without damage (e.g., 1A+ for 230 motor)

### 🧲 6. Brake Mode (Optional)
- Allows fast motor stop by shorting terminals
- Useful for precise or quick motion control

### 🔄 7. Sleep or Enable Pin
- Allows putting the driver in low-power mode or turning off the motor without cutting power

### 🔌 8. Separate Motor and Logic Supply
- Often supports **dual power rails** (e.g., 5V logic and 6–12V motor power)

### ⚡ 9. Flyback Diodes (Freewheeling Diodes)
- Either **built-in or required externally**
- Protects the driver from voltage spikes caused by motor inductance

### 🧩 10. Compact Footprint / Module Availability
- Available as SMD ICs or in **breakout boards** for prototyping

### 📘 Bonus Features (Advanced Chips)
- **Current sensing** output (e.g., DRV8871)
- **I2C/SPI control** (e.g., DRV8830 has I2C)
- **Phase/Enable or IN1/IN2 logic modes**
- **Soft start** / controlled acceleration



## alternative 

- HR8833 == 2x H-bridge

![](2025-05-04-14-07-37.png)


## ref 

- [[motor-driver-dat]] - [[dc-motor-dat]]

- [[DC-motor-driver]] - [[motor-driver]]