
# ESC-dat




- [[ESC-dat]] - [[Dshot-dat]] input // drive output - [[mosfet-drive-dat]] // [[reset-dat]]



- [[ESC-SDK-dat]] - [[BLHeli-dat]] - [[bluejay-dat]]

== [[MCU-dat]] + [[mosfet-dat]]

- [[ESC-amp-dat]] - [[ESC-dat]] - [[power-physics-dat]]


- [[ESC-dat]] - [[RX-dat]] - [[VTX-dat]] [[FC-dat]] - [[AIO-dat]] - [[flight-controller-dat]] - [[crazybee-dat]] - [[whoop-dat]]


- [[DRV8301-dat]] - [[ESC-dat]] - [[FOC-dat]] - [[motor-brushless-dat]] - [[motor-driver-BLDC-dat]]


- [[ESC-dat]] - [[VESC-dat]] - [[motor-driver-dat]] - [[FOC-dat]]


- [[RC-kits-dat]]

- [[ESC-dat]] - [[power-BEC-dat]]

- [[ESC-dat]] - [[motor-brushless-dat]]

- [[ESC-dat]] - [[motor-FPV-dat]] - [[propeller-FPV-dat]]

- [[FPV-build-dat]]

## tech 

- [[AM32-dat]] - [[BLHeli_32-dat]]



## ESC build 

![](2026-08-05-20-59-10.png)

- [[PWM-dat]] - [[motor-brushless-dat]] - [[battery-3s-dat]]


build inside 

![](2026-08-05-21-06-47.png)

- [[atmega8-dat]] - [[AVR-dat]]

- [[LR8256-dat]] - [[mosfet-dat]] - [[IOR-dat]] - [[infineon-dat]] - [[ESC-dat]] - [[infineon-mosfet-dat]]

![](2026-08-05-21-07-24.png)

- [[LDO-dat]] - [[LM7805-dat]]

![](2026-08-05-21-11-25.png)



## info 

- **Brushed ESC**: Operates using an H-Bridge configuration. It outputs standard 2-wire DC power, adjusting speed simply by turning the DC voltage on and off rapidly via Pulse Width Modulation (PWM).  
- **Brushless ESC**: Operates using a 3-phase inverter circuit. It outputs 3-wire AC power (three-phase), sequentially switching the coils based on back-EMF or sensor feedback to rotate the magnets. 

- **VESC (Open Source ESC)**: The VESC framework natively supports configuring the hardware into brushed DC mode, enabling a heavy-duty brushless controller to drive large brushed motors.
- **AM32 / BlHeli custom firmware**: In combat robotics, builders frequently flash custom firmware onto cheap brushless ESCs to re-map the 3 phases, converting a single brushless ESC into a driver that can independently control one or even two brushed motors.  
- **Novak / Castle Creations RC Car ESCs**: Many legacy and modern high-end surface ESCs feature an auto-detect or programmable mode allowing drivers to save money when transitioning an RC chassis from a brushed setup to brushless.



## test demo wiring CN 

![](2026-06-05-01-01-28.png)

![](2026-06-05-01-03-41.png)

![](2026-06-05-01-01-51.png)

- 有的输入带SW端口是启动线要接电源正极
- 有的带L端口是LED线接负极点亮

## mini ESC board 

![](2026-06-05-00-57-48.png)

fw5271 2110A ?? 

03N07F - [[mosfet-dat]]

![](2026-06-05-01-00-07.png)

## info 

- **Electronic Speed Controller (ESC)**: Controls the speed of the motors by adjusting the power supplied to them. ESCs are essential for smooth and responsive flight.


![](2025-09-13-15-48-28.png)



## Using a Single ESC for a 200W BLDC Motor

A **single ESC** (Electronic Speed Controller) is the standard way to control a 200W BLDC motor. Since you are aiming for high torque and smooth operation, here is how to select and use one professionally:

#### 1. Key Specifications to Match
To prevent the ESC from overheating, you must match the current (Amps) to your power goal:
* **The Math:** $Current (A) = \frac{Power (200W)}{Voltage (V)}$
* **Recommended Buffer:** Always choose an ESC with a current rating **2x higher** than your calculated continuous current to handle torque spikes.

| Battery Voltage | Continuous Amps | Recommended ESC Rating |
| :--- | :--- | :--- |
| **12V** | 16.7 A | **35A - 40A** |
| **24V** | 8.3 A | **20A - 25A** |
| **36V** | 5.5 A | **15A - 20A** |

---

#### 2. Why "Robotics" ESCs are better than "Drone" ESCs
For a project involving an 8mm shaft and gear reduction, **avoid standard Drone ESCs**. They are optimized for high RPM, not low-speed torque.

* **Best Professional Choice:** **VESC (Vedder ESC)**. It is designed for high-torque applications, supports **FOC** (silent and smooth), and is highly programmable.
* **Sensored Control:** If your motor has Hall sensors (5 small wires), use a **Sensored ESC**. This allows the motor to start smoothly under heavy load without "shuddering."



---

#### 3. Connection Setup
A single ESC acts as the "middleman" in your system:
1.  **Input:** Connected to your Battery (XT60 or XT90 connectors).
2.  **Output:** Three thick wires (Phases A, B, C) connected to the motor.
3.  **Control:** A signal wire (PWM/PPM or UART) connected to an Arduino, ESP32, or a remote receiver.

- [[VESC-dat]]

---

### Summary for your 200W Setup:
* **Driver Method:** Use **FOC** for the best torque delivery.
* **Hardware:** A **VESC 4.12** or **Mini VESC** is perfect for 200W.
* **Safety:** Ensure you have a common ground between the ESC and your controller.




## code 

## fault detection


- 测量点: 电调 MCU VCC
- 正常值: 3.3V / 5V
- 说明: ⭐️ 关键！无电压 = 供电断


## test 

- [[EFM8-dat]] - [[ESC-dat]] - [[FPV-fix-dat]]


1️⃣ 「四个 EFM8 的 RX/DSHOT 互相不连通」—— ✅ 完全正确！必须不通！

*   原因：4 个电机是由飞控独立控制的。
    *   电机 1 对应飞控的 Motor 1 输出脚（定时器通道 A）。
    *   电机 2 对应飞控的 Motor 2 输出脚（定时器通道 B）。
    *   电机 3 对应 Motor 3，电机 4 对应 Motor 4。
*   它们是 4 根完全独立的专用走线，如果互相连通（短路），飞控一转电机 1 其它电机就会跟着乱转。
*   👉 因此它们彼此不通是 100% 正常的！

---

2️⃣ 「Pin 17 到 GND 阻值都在 1MΩ ~ 3MΩ 之间」—— ✅ 正常！高阻抗输入特性！

*   原因：
    *   EFM8 的引脚内部是 CMOS 结构，栅极输入阻抗极高（通常在几十兆欧以上）。
    *   当引脚没有接外部强下拉电阻时，在板测量测到的就是芯片内部的漏电流阻抗和板层分布电容。阻值在 1MΩ ~ 3MΩ 这个数量级，且没有一颗芯片被击穿短路（0Ω），说明：
        1. 4 颗 EFM8 的信号输入端口全部完好，没有被高压浪涌击穿！
        2. 4 根信号线对地都没有被撞变形搭连短路！
     1. 

## ref 

- [[acturator-dat]]