
# NE555-Astable-dat



## ⚙️ Mode 1: Astable (Oscillator)

### 🔁 Generates a continuous square wave

### 🔧 Wiring:

```
 VCC
  |
 [R1]
  |
  +------ Pin 7 (DIS)
  |            |
 [R2]         [C1]
  |            |
 Pin 6 -----+  |
 Pin 2 -----|--+
            |
           GND

- Pin 4 (RESET) → VCC
- Pin 5 (CTRL) → 0.01µF to GND
- Pin 3 = Output
```

### 🧮 Frequency & Duty Cycle:

```
T = 0.693 × (R1 + 2×R2) × C1  
f = 1 / T  
Duty Cycle ≈ (R1 + R2) / (R1 + 2×R2)
```

---

## example 1.  

This is a **PWM generator circuit** using a 555 Timer IC configured in **astable mode**, used to control a DC motor via a MOSFET. The duty cycle is adjustable using a potentiometer.

---

## 📦 Circuit Summary

| Pin | Name            | Description                                                 |
| --- | --------------- | ----------------------------------------------------------- |
| 1   | GND             | Connected to ground                                         |
| 2   | Trigger         | Connected to timing capacitor C2 via noise filters (C3, C2) |
| 3   | Output          | PWM signal output to MOSFET gate                            |
| 4   | Reset           | Tied to VCC to avoid accidental reset                       |
| 5   | Control Voltage | Decoupled with 0.01 µF (C4) for noise immunity              |
| 6   | Threshold       | Connected to timing network                                 |
| 7   | Discharge       | Discharges timing capacitor via R1                          |
| 8   | VCC             | Power supply (with decoupling capacitor C1 = 220 µF)        |

---

## 🧩 Key Components

| Component | Value      | Function                              |
| --------- | ---------- | ------------------------------------- |
| R1        | 1 kΩ       | Sets discharge time                   |
| R2        | 100 kΩ pot | Sets charge time (duty cycle control) |
| D1        | 1N4148     | Separates charge and discharge paths  |
| C1        | 220 µF     | Power decoupling                      |
| C2, C3    | 1 nF       | Trigger debounce / noise filtering    |
| C4        | 0.01 µF    | Filters pin 5 (control voltage)       |
| MOS       | N-channel  | PWM-driven motor control              |

---

## 🔄 Operation

1. **C2 charges** through **R2** and **D1**.
2. When voltage on C2 reaches 2/3 VCC → 555 output turns **LOW**.
3. **C2 discharges** through **R1** and pin 7.
4. When voltage drops below 1/3 VCC → 555 output goes **HIGH**.
5. This loop creates a **PWM signal** at pin 3.
6. PWM signal drives the **MOSFET**, which controls motor speed.

---

## ⚙️ Features

- Adjustable **duty cycle** via R2 (100k potentiometer)
- Stable operation with **decoupling capacitors**
- Simple and low-cost motor control solution
- Output PWM can be used to drive **DC motors**, **LEDs**, or other loads via a **MOSFET**

---

## ✅ Notes

- Make sure the MOSFET is appropriate for your motor's voltage and current.
- You can add a **flyback diode** across the motor for protection.








## example 2. ⚙️ NE555 as PWM Generator with Potentiometer

### 📌 Purpose

Generate a variable PWM (Pulse Width Modulated) signal using an NE555 timer. Adjust the duty cycle with a potentiometer to control devices like:
- Motor speed
- LED brightness
- Servo-like applications (via low-pass filtering)

---

### 📦 Parts Required

| Part           | Value                                                    |
| -------------- | -------------------------------------------------------- |
| NE555 Timer IC | 1×                                                       |
| Potentiometer  | 10kΩ or 100kΩ                                            |
| Diodes         | 2× 1N4148 (or any fast switching diodes)                 |
| Capacitor      | 1× 1µF to 10µF (electrolytic or ceramic)                 |
| Power Supply   | 5V or 12V DC                                             |
| Load           | Optional (e.g. LED + resistor, transistor + motor, etc.) |

---

### 🔌 Schematic (Text Diagram)

```
   VCC (+)
     |
     +------+
     |      |
    [R]   [D1]
     |      |
     +------+
     |      |
    [POT]  [D2]
     |      |
     +------+
        |
       Pin 7 (DIS)
        |
      [C1] to GND
        |
Pin 6 --------+
Pin 2 --------+
Pin 4 → VCC
Pin 5 → 0.01µF to GND
Pin 1 → GND
Pin 3 → PWM Output
```

#### Pin Functions
- **Pin 3**: PWM output
- **POT**: Varies charge/discharge ratio, changing duty cycle
- **Diodes (D1/D2)**: Separate charge/discharge paths

---

### ⚙️ How It Works

- The NE555 is in **astable mode**.
- The **two diodes** split the charge/discharge paths.
- The **potentiometer** controls the ratio of charge to discharge time.
- This changes the **duty cycle** while keeping frequency fairly stable.

---

### 📐 Formulas (Approximate)

#### Charge time (output HIGH):
```
T_high = 0.693 × (R1 + variable portion of POT) × C1
```

#### Discharge time (output LOW):
```
T_low = 0.693 × (fixed portion of POT) × C1
```

#### Frequency:
```
f = 1 / (T_high + T_low)
```

#### Duty Cycle:
```
Duty = T_high / (T_high + T_low)
```

By adjusting the potentiometer, you change the ratio between T_high and T_low → **controlling duty cycle**.

---

### ✅ Tips

- Use **small capacitor** (like 1µF) for higher frequency PWM (kHz range).
- Add a **buffering transistor** on output if driving a motor or power load.
- For smoother motor/LED control, consider adding a **low-pass filter** (R + C) on output to convert PWM to analog-like voltage.

---

### 🧪 Use Case: DC Motor Speed Control

1. NE555 PWM output → base of NPN transistor (e.g., 2N2222 or TIP120)
2. Motor connected to collector and power supply
3. Adjust POT → duty cycle changes → motor speed changes




## ref 

- [[NE555-dat]]