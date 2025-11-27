
# motor-driver-dat

[find all products here.](https://www.electrodragon.com/product-category/actuator/actuator-module/)

- [[motor-dat]] - [[thermal-disppation-dat]] - [[PCB-design-dat]] - [[switching-dat]]

[legacy wiki page](https://www.electrodragon.com/w/Category:Driver_Board) 

- [[cable-dat]] - [[conn-cable-terminal-dat]] - [[wire-2-wire-dat]]



- [[BLDC-dat]]

## tech 

- [[PWM-chopper-type-motor-driver]] - [[FOC-dat]] - [[CC-CCW-control-dat]]

- [[AC-mains-dat]] - [[motor-dat]] drive - [[IGBT-dat]]




## Board 

- [[SDR1102-dat]] - [[SDR1109-dat]] - [[SDR1048-dat]] - [[SDR1059-dat]] - [[SDR1050-dat]]

- [[SDR1090-dat]] - [[SDR1079-dat]] - [[SDR1062-dat]]

- [[SDR1060-dat]] - [[SDR1076-dat]]

- [[SDR1096-dat]]

- [[TB6612-dat]] - [[SDR1059-dat]] - [[SDR1087-dat]] - [[MPC1114-dat]]

- [[arduino-shields-dat]]

- [[L298-dat]] - [[SDR1093-dat]] - [[SDR1048-dat]]

- [[DRV8871-dat]] - [[SDR1117-dat]]

- [[DRV8825-dat]] - [[SDR1040-dat]] - [[SDR1113-dat]]

- [[L293-dat]] - [[SDR1064-dat]]

- [[relay-dat]] control == 

- [[mosfet-dat]] and [[PWM-dat]] control == [[SDR1073-dat]]

## chips 

- [[ti-motor-dat]] 
  
- [[toshiba-dat]] - [[TB6612-dat]] - [[TB6600-dat]] - board - [[SDR1059-dat]]

- [[LW556-dat]] - [[TB6600-dat]] - [[DM430-dat]] - [[DM542-dat]]

- [[allegro-dat]] - [[A4988-dat]] - [[A4954-dat]]

- [[Infineon-dat]] - [[BTS7960-dat]]


## stepper motor 

- [[stepper-dat]]

- [[TB67H450-dat]] - [[TB6612-dat]] - [[toshiba-dat]]
 
- [[A4988-dat]]

- [[LV8729-dat]] 

- [[L293-dat]] - [[L298-dat]] 

- [[TI-motor-dat]] - [[DRV8833-dat]] - [[DRV8825-dat]] - [[drv8837-dat]] - [[drv8313-dat]] - [[DRV8871-dat]] - [[DRV8876-dat]] - [[DRV84x2-dat]]

- [[ULN2003-dat]]


## and more 

- [[MC33887-dat]]

## Chip function lists 

- overcurrent / thermal shutdown protection / microstepping / precise motor control

## advanced control 

- [[PCA9685-dat]]

## Comparison 

TB6612FNG vs. L298N

| Feature                 | TB6612FNG           | L298N               |
| ----------------------- | ------------------- | ------------------- |
| Motor Voltage Range     | 2.5V – 13.5V        | 5V – 46V            |
| Logic Voltage Range     | 2.7V – 5.5V         | 5V – 7V             |
| Continuous Current / ch | ~1.2A               | 2A                  |
| Peak Current / ch       | 3.2A (short bursts) | 3A (non-repetitive) |
| Efficiency              | High (CMOS)         | Low (Bipolar)       |
| Voltage Drop            | ~0.2V               | ~1.8V – 3V          |
| Heat Output             | Low                 | High                |
| PWM Frequency Support   | Up to 100 kHz       | <25 kHz             |
| Size                    | Small, modern       | Large, bulky        |
| Cost                    | Moderate            | Low                 |


more options

| Chip/Module   | Voltage Range | Continuous Current  | PWM Freq.    | Features & Notes                                                           |
| ------------- | ------------- | ------------------- | ------------ | -------------------------------------------------------------------------- |
| **TB6612FNG** | 2.5V – 13.5V  | 1.2A/ch (3.2A peak) | Up to 100kHz | Efficient CMOS, low heat, great for small robots                           |
| **DRV8833**   | 2.7V – 10.8V  | 1.5A/ch (2A peak)   | Up to 250kHz | Compact, efficient, built-in protection, ideal for small DC motors         |
| **DRV8871**   | 6.5V – 45V    | 3.6A (6A peak)      | ~100kHz      | Single-channel, robust, good for mid-power motors                          |
| **DRV8876**   | 4.5V – 37V    | 3.5A (5A peak)      | ~100kHz      | Smart current regulation, overtemp/short protection                        |
| **MC33926**   | 5V – 28V      | 3A (5A peak)        | Up to 20kHz  | Automotive-grade, robust with fault reporting                              |
| **VNH5019**   | 5.5V – 24V    | 12A (30A peak)      | ~20kHz       | High-power, onboard protection, great for large motors                     |
| **BTN7960B**  | 5.5V – 27V    | 43A (55A peak)      | ~25kHz       | High-current half-bridge, excellent for industrial/heavy-duty applications |



## Relay-Based H-Bridge

you **can control a high current DC motor** using relays to switch it ON/OFF and to control **clockwise (CW)** and **counter-clockwise (CCW)** rotation by reversing the polarity with an **H-Bridge** made from relays.

---

### How It Works: Relay-Based H-Bridge

A DC motor reverses direction by reversing the polarity of the voltage applied to its terminals. An H-Bridge uses **4 relays** to achieve this.

---

### Relay-Based H-Bridge Configuration (4-Relay Method)

#### Components
- 4 relays (DPST or SPST) rated for motor voltage and stall current
- Flyback diodes across relay coils
- Flyback diodes across motor terminals (recommended)
- Control logic (manual switches or microcontroller)

#### Operation Modes

| Relay 1 | Relay 2 | Relay 3 | Relay 4 | Motor Direction   |
| ------- | ------- | ------- | ------- | ----------------- |
| ON      | OFF     | ON      | OFF     | Clockwise         |
| OFF     | ON      | OFF     | ON      | Counter-Clockwise |
| OFF     | OFF     | OFF     | OFF     | Motor OFF         |

> **Important:** Never activate relays that create a short circuit (e.g., Relay 1 and Relay 2 ON simultaneously). Use interlock logic.

---

### Important Considerations

1. **Relay Ratings:** Must handle the motor's voltage and stall current (stall current can be 5–10× running current).
2. **Flyback Diodes:** Required across relay coils and motor terminals to protect from voltage spikes.
3. **Logic Interlock:** Ensure relays cannot be activated in conflicting states.
4. **Switching Delay:** Turn OFF all relays briefly before changing direction to avoid shorts and damage.

---


## High Current DC Motors (CW/CCW + ON/OFF)

### 🔋 1. Solid-State H-Bridge Using Power MOSFETs or IGBTs

#### ✅ Best for:
- High current (10A–100A+)
- Fast and frequent switching (PWM)
- Compact, efficient control

#### 📦 Components:
- 4 N-channel power MOSFETs (e.g., IRF1404, IRF3205)
- Gate driver ICs (e.g., IR2104, HIP4081)
- Microcontroller (Arduino, STM32, etc.)
- Heat sinks or cooling fans
- Protection: flyback diodes, current sensors

#### 🟢 Pros:
- Very fast switching (PWM possible)
- Silent, no moving parts
- Low power loss
- Scalable

#### 🔴 Cons:
- More complex (requires driver circuitry)
- Thermal design required

---

### 🧱 2. Prebuilt H-Bridge Driver Modules (MOSFET or IGBT-based)

#### ✅ Best for:
- Medium to high current (15A–75A)
- Fast setup and integration

#### Examples:
- **BTS7960** (43A/channel) - [[BTS7960-dat]]
- **VNH2SP30** (30A motor driver) - [[VNH2SP30-dat]] - [[sdr1070-dat]]
- **Sabertooth motor drivers** (robust, configurable)
- **IGBT driver modules** (for large motors)

#### 🟢 Pros:
- Built-in protections (thermal, overcurrent)
- Logic-level control (PWM + direction)
- Compact and reliable

#### 🔴 Cons:
- May be more expensive
- Power limits based on model

---

### 🔌 3. High-Power DC Contactor + Polarity Reversing Circuit

#### ✅ Best for:
- Very high current motors (100A+)
- Infrequent switching (e.g., industrial/vehicle systems)

#### Setup:
- 2 contactors for direction (polarity reversal)
- 1 contactor for ON/OFF
- Optional soft-start or precharge circuit

#### 🟢 Pros:
- Very robust and durable
- Handles surge current well
- Galvanic isolation

#### 🔴 Cons:
- Bulky and expensive
- Mechanical wear
- Slower switching

---

### 🏆 Summary Table

| Use Case                            | Recommended Method                       |
| ----------------------------------- | ---------------------------------------- |
| Compact, efficient motor control    | MOSFET H-Bridge with gate drivers        |
| Easy integration, plug-and-play     | BTS7960 or Sabertooth driver module      |
| Extreme current (100A+), rugged use | DC contactor with polarity control       |
| PWM speed control + direction       | Solid-state H-Bridge                     |
| Low-speed control, basic CW/CCW     | Relay-based H-Bridge (least recommended) |

---

### ⚠️ Tips and Safety

- ✅ Use **flyback diodes** (or body diodes in MOSFETs).
- ✅ Include **gate resistors** and **dead-time logic** to avoid shoot-through.
- ✅ Add **current sensing** (e.g., Hall sensors) for protection.
- ✅ Ensure **good thermal design** (heatsinks, fans, or active cooling).


## more driving chips 


## ✅ Quick Comparison Table

| Chip/Module                     | Current      | Voltage   | Type            | Notes                        |
| ------------------------------- | ------------ | --------- | --------------- | ---------------------------- |
| [[BTS7960-dat]]                 | 43A peak     | ~24V      | Half-Bridge     | Needs 2 for full H-Bridge    |
| [[VNH2SP30-dat]]                | 14A/30A peak | 5.5–16V   | Full H-Bridge   | Compact, good protection     |
| [[MC33932-dat]]                 | 5A/8A peak   | 5–28V     | Dual H-Bridge   | Diagnostics and protection   |
| [[DRV84x2-dat]] | 6–12A        | Up to 50V | Dual H-Bridge   | High-efficiency PWM          |
| [[L298N-dat]]                   | 2A           | Up to 46V | Dual H-Bridge   | NOT for high current         |
| Sabertooth                      | Up to 120A   | 6–30V     | Dual H-Bridge   | Best for industrial/robotics |
| Cytron MD30C                    | 30A          | 5–30V     | Single H-Bridge | Reliable and simple          |
| IBT-2                           | 43A          | 6–27V     | Full H-Bridge   | BTS7960 module variant       |
| AMC8832                         | 15A+         | Up to 50V | Full H-Bridge   | Advanced high-efficiency     |


- [[NE555-motor-driver-dat]] - [[NE555-dat]] 

- [[motor-driver-dat]] - [[mosfet-dat]]

- [[CC-CCW-control-dat]]

- [[mosfet-motor-control-dat]] - [[relay-motor-control-dat]]

## Other Tech

- [[FOC-dat]]

## ref 

- [[motor-dat]]

- [[motor-driver]] - [[motor]]

- [[FOC-dat]]