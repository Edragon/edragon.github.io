
# MPPT-dat



## board 

- [[CN3306-dat]] - [[CN3722-dat]]

## 1. MPPT: Maximum Power Point Tracking

**Definition:**  
MPPT is a technology used in solar charge controllers and photovoltaic (PV) systems to maximize the power output from a solar panel. It continuously adjusts the electrical operating point of the panels so that they deliver the **maximum possible power** to the load or battery.

**Why it’s needed:**  
- Solar panels have a **non-linear voltage-current (V-I) curve**.  
- The power output (P = V × I) changes depending on sunlight, temperature, and load.  
- There’s a single point on this curve called the **Maximum Power Point (MPP)** where the product of voltage and current is highest.  
- MPPT controllers track this point in real-time.

**Benefits:**  
- Can increase solar energy harvest by 10–30% compared to traditional charge controllers.  
- Adapts to changing sunlight and temperature conditions.  






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




当太阳能板作为输入电源时，CN3306采用恒电压法跟踪太阳能板的最大功率点。在太阳能板的伏安特性曲线中，当环境温度一定时，在不同的日照强度下，输出最大功率点所对应的输出电压基本相同，亦即只要保持太阳能板的输出端电压为恒定电压，就可以保证在该温度下光照强度不同时，太阳能板输出最大功率。

CN3306太阳能板最大功率点跟踪端MPPT管脚的电压被调制在1.205V(典型值)，配合片外的两个电阻(图1中的R5和R6)构成的分压网络，调制输入电压，实现对太阳能板最大功率点进行跟踪。



## ref 

- [[solar-dat]]

- [[resistor-feedback-dat]]