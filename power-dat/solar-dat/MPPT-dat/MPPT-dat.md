
# MPPT-dat

The MPPT pin is used for solar cell maximum power point tracking.

When a solar panel is used as the input power source, the CN3306 adopts a constant voltage method to track the solar panel's maximum power point. On the solar panel's current-voltage characteristic curve, when the ambient temperature is constant, the output voltage corresponding to the maximum power point remains nearly the same under different sunlight intensities. 

That is, by keeping the output voltage of the solar panel at a constant value, the panel can output maximum power at that temperature regardless of light intensity.

The voltage at the [[CN3306-dat]] MPPT pin for solar panel maximum power point tracking is regulated to 1.205V (typical). With two external resistors (R5 and R6 in Figure 1) forming a voltage divider network, the input voltage is regulated to track the solar panel's maximum power point.

The solar panel maximum power point voltage is determined by the following formula:

 Vmpp = 1.205 × (1 + R5 / R6)

**if R6 == 100K and Vmpp == 18V, then R5 = 1.4M**

for Vmpp = 1.04 × (1 + R5 / R6) in [[CN3722-dat]]

**if R6 = 16K, and R5 = 220K, then Vmpp = 14.3V**

MPPT pin for adaptive charging current

The MPPT pin can also be used to automatically adjust the charging current to suit input power sources with limited load capacity. For example, when a weak adapter or USB port is used as the input power source, the MPPT pin and two external resistors (R5 and R6 in Figure 1) form a voltage divider network to regulate the input voltage to a value lower than the rated voltage VL (such as 4.75V). In this way, even if the set charging current exceeds the load capacity of the adapter or USB port, the CN3306 will automatically reduce the charging current to match the input power source. The VL voltage is set by the following formula:

 Vl = 1.205 × (1 + R5 / R6)


## ref 

- [[solar-dat]]