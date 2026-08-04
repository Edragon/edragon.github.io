
# PID-dat.md

- [[motor-driver-dat]] - [[PID-dat]]

### 3. Closed-Loop PID Speed Control (Precise Speed Control with an Encoder)

If you need very high output-speed precision (e.g., speed must not fluctuate when the load changes), open-loop PWM control alone is not enough.

* **Setup:** Add an optical or magnetic encoder to the rear of the DC motor, forming a closed-loop system: **DC gear motor + encoder**.
* **Principle:** The encoder detects the actual speed of the motor (or the gearbox output shaft) in real time and feeds it back to the controller. The controller compares the "actual speed" against the "target speed," then uses a **PID algorithm** to dynamically adjust the PWM duty cycle — when the load increases and speed drops, it automatically raises the duty cycle to compensate, keeping the output shaft speed constant.



## ref 