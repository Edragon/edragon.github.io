
# battery-balancer-dat


## Method 1. 

How to use single [[TP4056-dat]] to charge 2S lithium battery pack?

The battery should be built with all pins out: 

![](2025-05-09-12-59-06.png)

parallel charging by [[TP4056-dat]] directly 

![](2025-05-09-12-59-34.png)

Board looks like: 

![](2025-05-09-12-59-51.png)


## Method 2.

If building your own charger or pack, include a BMS, and use a charger with current limit and CV/CC behavior.

如果你自己DIY电池组或充电系统，务必使用保护板（BMS），并选择支持恒流恒压输出的充电器。




## ref 

- [[battery-charger-dat]]