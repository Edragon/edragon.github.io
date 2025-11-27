
# Trapezoidal-control-dat


## 1. What is Six-Step Commutation?
Six-step commutation is a common control method for **BLDC (Brushless DC) motors**.
- Commutation happens every **60° electrical**
- Voltage waveform is **trapezoidal / square-like**
- Uses **Hall sensors** or **back-EMF zero crossing** for timing

Main idea: **simple, low-cost, strong startup torque**.

---

## 2. Six-Step Commutation vs. Sinewave / [[foc-dat]] Control

### Control Method
- **Six-step**: abrupt commutation every 60°, current jumps
- **Sinewave / [[foc-dat]]**: continuously shaped current, smooth transitions

### Noise & Vibration
- **Six-step**: louder, more vibration
- **[[foc-dat]]**: quiet and smooth

### Torque Ripple
- **Six-step**: significant torque ripple (6 peaks per revolution)
- **[[foc-dat]]**: almost no torque ripple

### Efficiency
- **Six-step**: medium efficiency
- **[[foc-dat]]**: highest efficiency, especially at low speed

### Cost
- **Six-step**: cheap, simple hardware, light firmware
- **[[foc-dat]]**: more expensive, needs stronger MCU and complex algorithm

---

## 3. Advantages of Six-Step Control
- Very simple control logic  
- Low cost  
- Good high-speed performance (fans, tools)  
- Strong startup torque  

---

## 4. Disadvantages of Six-Step Control
- Higher noise  
- Noticeable torque ripple  
- Current spikes during commutation  
- Lower efficiency than [[foc-dat]]  
- Poor low-speed smoothness (can jitter)  

---

## 5. When to Use Six-Step Control
Good for:
- Brushless fans  
- Power tools  
- RC model motors (many ESCs use six-step)  
- Pumps and simple BLDC applications  

Not good for:
- Applications requiring **quietness** and **smooth motion** (gimbals, service robots)

---

## Summary (one sentence)
**Six-step = low cost, simple, but noisy and less efficient.  
[[foc-dat]] = higher cost, complex, but smooth, quiet, and efficient.**


## ref 

- [[motor-driver-dat]]