
# DOD1119-dat 


mini-toy-board-dat

This board is a copy from a commerial toy product, so based on a real selling product, but used a more advanced [[RISC-V-dat]] chip



## Board map 

![](2024-08-25-18-15-59.png)

## Functions 

![](2024-11-18-17-39-20.png)


- the chip does not have a default running program, please design it yourself
- button and led need to be programmed to act, same for motor driver
- battery charger can work alone without a design

- default LED color in "shining high tech" blue 

## Applications 

- toy airplane, tanks, cars, etc


## SCH 

![](2023-10-26-15-43-28.png)

- PD6/PA1 - motor control 
- PC1 - led control 
- PC2 - button input 
- PD1/PD4/PD5 = pin 8 = SWIO 

## demo 

- https://www.youtube.com/watch?v=v3h-EoI-HIQ




## ref 

- [[CH32V003-dat]]

- [[mosfet-dat]] - [[battery-charger-dat]]

- [[DOD1119]]