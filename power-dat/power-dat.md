
# power-dat.md

- [[power-dat]] - [[battery-dat]] 

- [[li-battery-dat]]- [[battery-BMS-dat]]

- [[battery-drainer-dat]] - [[acdc-dat]] - [[power-sensor-dat]]
  
- [[DC-dat]] - [[dcdc-dat]] - [[dcdc-down-dat]] - [[dcdc-boost-dat]] 

- [[LDO-dat]]

- [[low-power-dat]]

- [[battery-pack-dat]]

- [[CONN-power-dat]]

- [[power-isolated-module-dat]]

- [[ti-power-dat]] - [[diodes-dat]]

- [[current-limit-switch-dat]]

- [[AC-mains-dat]] - [[ACDC-dat]]

- [[solar-dat]] - [[solar-power-dat]]

- [[Power-distribution-dat]]

- [[supervisory-dat]] - [[power-switch-dat]] - [[voltage-reference-dat]] - [[voltage-interverter-dat]] - [[power-detector-dat]] - [[power-amplifier-dat]]

- [[constant-current-dat]]



## power design workflow

1. design: [[power-dat]] 

1. consider power jack [[power-jack-dat]]

2. [[power-protection-dat]]


## over power protocols 

- [[POE-dat]] - Power Over Ethernet (POE)
- [[powerbus-dat]] - PowerBus - [[ITF1009-dat]]

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





### Sink and Source DDR Termination Regulator


- [[ti-power-dat]] == TPS51200DRC - TPS51200 Sink and Source DDR Termination Regulator - The TPS51200 device is a sink and source double data rate (DDR) termination regulator specifically designed for low input voltage, low-cost, low-noise systems where space is a key consideration.

### Power Supply Sequencer 

LM3880-Q1 Three-Rail Simple Power Supply Sequencer 

The LM3880-Q1 simple power supply sequencer offers the easiest method to control powerup sequencing and powerdown sequencing of multiple Independent voltage rails. By staggering the startup sequence, it is possible to avoid latch conditions or large in-rush currents that can affect the reliability of the system.



### transfomer driver 

- [[TI-power-dat]] SN6501DBVT - Low-noise, 350-mA, 410-kHz transformer driver for isolated power supplies


## other power chips 

### MT9700 

80 mΩ, Adjustable Fast Response

Current-Limited Power-Distribution Switch

The MT9700 is a cost-effective, low voltage,single P-MOSFET load switch,optimized for self-poweredand bus-powered Universal Serial Bus (USB)applications. This switch operates with inputs ranging from 2.4V to 5.5V, making it ideal for both 3V and 5V systems. 

The switch's low Rpson.80mQ ,meets USB voltage drop requirements. The MT9700 is also protected from thermal overload which limits power dissipation and junction temperatures. 

Current  limit   threshold  programmed with a resistor from SET to ground. The quiescent supply current is typically 15pA at switch on state. 

At switch off state the supply current decreases to less than 1μA.The MT9700 is available in S0T23-5 package. 

### ME1502

70mΩ， 5V USB 高侧可调门限限流负载开关

ME1502 是一款适用于5V应用的可调限流门限的USB接口输出保护芯片。芯片内部集成了过流保护、短路保护、过温保护、欠压保护等功能，在输出发生过流、短路或带大电容负载启动等情况时可以限制电流输出从而保护前级电源。

ME1502 70mΩ, 5V USB High-Side Adjustable Threshold Current Limit Load Switch



## ref 

- [[power]]