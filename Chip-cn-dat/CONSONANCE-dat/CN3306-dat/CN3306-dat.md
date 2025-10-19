
# CN3306-dat

- [[MPPT-dat]] - [[solar-dat]]

CN3306 is a current-mode, fixed-frequency PWM boost-type multi-battery charging management IC. The CN3306 features an input voltage range of 4.5V to 32V, requires few external components, and is simple and flexible to use. It can be applied to charging management for lithium batteries, lithium iron phosphate batteries, or lithium titanate batteries.

Features:
- PWM boost mode charging management
- Input voltage range: 4.5V to 32V
- Adaptive charging current function
- Supports solar panel maximum power point tracking, can be powered by solar panels
- Switching frequency: 330kHz

![](2025-08-27-17-23-04.png)

- [[resistor-feedback-dat]]

- [[resistor-dat]]

- [[CN3306-CONSONANCE.pdf]]


## setup 

output voltage setting: == VREG ＝ 1.205 × (1＋R1／R2) == 24.8

output charge current == Ich == 120mV / Rcs == 2A 

The Maximum Power Point Tracking  == VMPPT ＝ 1.205×(1＋R5／R6) == 13.3V 

MPPT Pin Used for Adaptive Charge Current ==  VL ＝ 1.205×(1＋R5／R6) 




## ref 

- [[MPPT-dat]]

- [[diode-dat]] - [[DCDC-down-dat]] - [[resistor-feedback-dat]] - [[resistor-dat]]

- [[consonance-dat]] - [[consonance]]

- [[CN3306]]