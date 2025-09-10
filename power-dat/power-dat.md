
# power-dat.md

- [[power-dat]] - [[battery-drainer-dat]] - [[acdc-dat]] - [[power-sensor-dat]]
  
- [[dcdc-dat]] - [[dcdc-buck-dat]] - [[dcdc-boost-dat]] - [[LDO-dat]]

- [[low-power-dat]]

- [[battery-dat]] - [[li-battery-dat]]- [[BMS-dat]]

- [[battery-pack-dat]]

- [[CONN-power-dat]]

- [[power-isolated-module-dat]]



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




## ref 

- [[power]]