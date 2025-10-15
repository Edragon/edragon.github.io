
# power-dat.md

- [[power-dat]] 

- [[battery-dat]] - [[li-battery-dat]]- [[BMS-dat]]

- [[battery-drainer-dat]] - [[acdc-dat]] - [[power-sensor-dat]]
  
- [[DC-dat]] - [[dcdc-dat]] - [[dcdc-down-dat]] - [[dcdc-boost-dat]] - [[LDO-dat]]

- [[low-power-dat]]

- [[battery-pack-dat]]

- [[CONN-power-dat]]

- [[power-isolated-module-dat]]

- [[ti-power-dat]] - [[diodes-dat]]

- [[current-limit-switch-dat]]

- [[AC-mains-dat]] - [[ACDC-dat]]

- [[solar-dat]] - [[solar-power-dat]]

- [[Power-distribution-dat]]


## workflow

1. design: [[power-dat]] 

1. consider power jack [[power-jack-dat]]

2. [[power-protection-dat]]


## Info 

- [[breadboard-power-dat]]

- [[wireless-charge-dat]]

- [[dcdc-down-dat]] - [[dcdc-dat]]

- [[LDO-dat]]

- charger-pump


| Parts | Common Value | Note |
| ----- | ------------ | ---- |


## Power selection 

By switching from 5V to 3.3V, you can achieve up to 34% power savings in circuits where the current remains the same. In practice, the actual savings may be higher because some components draw less current at lower voltages.


## power tree for D1-H

![](2025-08-07-14-48-23.png)



## Integrated PDB (Power Distribution Board)

An **Integrated PDB** is a circuit board built **into a drone’s flight controller or frame** that distributes power from the battery to all electronic components, such as:

- ESCs (Electronic Speed Controllers)
- Motors
- Flight Controller (FC)
- Video Transmitter (VTX)
- LEDs and other accessories



## other chips 

[LM3880 == LM3880 Three-Rail Simple Power Supply Sequencer](https://www.ti.com/lit/ds/symlink/lm3880.pdf?ts=1757470644079&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252Fja-jp%252FLM3880%252Fpart-details%252FLM3880MF-1AE%252FNOPB)


## ref 

- [[power]]