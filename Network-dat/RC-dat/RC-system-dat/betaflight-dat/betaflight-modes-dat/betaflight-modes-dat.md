
# betaflight-modes-dat


- [[betaflight-dat]] - [[betaflight-receiver-dat]] - [[betaflight-modes-dat]]


- [[radiomaster-dat]] - [[radiomaster-pocket-dat]]

## Modes 

| Mode               | AUX         | radiomaster | set  | Notes |
| ------------------ | ----------- | ----------- | ---- | ----- |
| ARM                | AUX 1       | SA          | HIGH |       |
| Angle              | AUX 2  HIGH | SB          | HIGH |       |
| Horizon            | AUX 2       | SB          | MID  |       |
| acro Mode          | AUX 2       | SB          | x    |       |
| Air Mode           | AUX 3       | SC          | MID  |       |
| Flip After a Crash | AUX 3       | SC          | HIGH |       |
| Beeper             | AUX 4       | SD          | HIGH |       |


AETR1234

- CH1 - steering 
- CH2
- CH3 - throttle
- CH4

- CH5 / SA - 2/switch - AUX1 - ARM 
- CH6 / SB - 3/switch - AUX2 - Angle / Horizon / Acro Mode
- CH7 / SC - 3/switch - AUX3 - Air Mode / Flip After a Crash
- CH8 / SD - 2/switch - AUX4 - Beeper

- [[radiomaster-pocket-dat]]

- [[BF-beeper-dat]]


- [[FPV-stability-dat]] - [[betaflight-modes-dat]]

- [[BF-flight-mode-air-dat]] - [[BF-flight-mode-horizon-dat]] - [[BF-flight-mode-acro-dat]] - [[BF-flight-mode-angle-dat]]




## most user-friendly mode == Angle mode

**Angle mode** is the most user-friendly for a beginner. 

### Why Angle Mode Fits Beginners Best
* **Self-Leveling:** As soon as you center the right control stick, the drone automatically returns to a completely flat, level position. 
* **Tilt Limits:** It restricts how far the drone can pitch or roll, preventing you from accidentally flipping it upside down.
* **Intuitiveness:** It flies much like a traditional GPS camera drone or a video game flying simulator where letting go of the sticks brings you to a safe hover.

### How the Three Modes Compare
* **Angle Mode:** Self-leveling with hard banks/tilt limits. Perfect for your very first hover and line-of-sight flights.
* **Horizon Mode:** Acts like Angle mode when sticks are near the center (self-leveling), but allows full flips and rolls if you push the sticks all the way to the edges. It can feel twitchy and unpredictable for true beginners.
* **Acro Mode (Rate Mode):** Has no self-leveling and no angle limits. The drone stays at whatever angle you leave the sticks until you actively push it back. It has a steep learning curve like flying a real helicopter, but it is how FPV drones are ultimately meant to be flown.







## mixer mode 

This passage explains how Betaflight (or a similar flight controller firmware) handles motor output **saturation** and **clipping** in the standard mixer mode. 

Here is a breakdown of what it means in plain terms:

### 1. What is Motor Saturation?
When you fly an FPV drone, the flight controller constantly calculates adjustments for **roll, pitch, and yaw** (using PID values) and combines them with your throttle command to tell each motor how fast to spin. 
* Sometimes, these calculations demand that a motor spin faster than its maximum possible speed or slower than its minimum allowed speed (e.g., trying to spin a motor below idle or past 100% throttle). This is called **saturation**.

### 2. Equal Reduction (Desaturation)
When a motor command asks for more than 100% throttle, the flight controller has to prevent math errors or overflow. In the standard mixer mode, it handles this by **reducing all motor outputs equally** so the relative differences between them stay proportional, keeping your attitude control intact as much as possible.

### 3. Low-End Clipping and Power Loss
When a motor command drops *below* the minimum throttle (idle) limit, it gets **clipped** (forced to stay at the minimum idle speed rather than going lower). 
* **The example given:** If your throttle is very low and you suddenly command a quick roll, the motors on one side need to drop lower to tilt the drone. But because they hit the minimum idle floor and get clipped, they can't go any lower. This results in you losing about half of your intended control authority (half of your PID gain) for that maneuver.

### 4. Breaking Symmetry
If your stick movements demand a massive change (more than a 100% difference between the highest and lowest motors), the low-end motors get clipped while the high-end motors keep scaling. This **breaks the mathematical symmetry** of the motor balance, unevenly reducing your PID control gain and potentially causing the drone to feel sluggish, twitchy, or unresponsive during extreme maneuvers.

*(Note: Modern firmware often uses advanced mix algorithms like **Dynamic Idle** or **RPM Filter-based mixing** to prevent or mitigate these exact clipping and symmetry issues.)*


In the standard mixer/ mode, when the roll, pitch and yaw gets calculated and saturates a motor, all motors will be reduced equally. 

When a motor goes below minimum it gets clipped off. Say you had your throttle just above minimum and tried to pull a quick roll - since two motors can't go any lower, you essentially get half the power (half of your PID gain). 

If your inputs would have asked for more than a 100% difference between the high and low motors, the low motors would get clipped, breaking the Symmetry of the motor balance by unevenly reducing the gain




## ref 

