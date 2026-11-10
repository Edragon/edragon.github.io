
# CONN-SIM-dat

- [[SIM]] - [[CONN-SIM-dat]]




## circuits 

![](2025-03-24-17-28-21.webp)






## pin definitions 

![](17-19-14-27-02-2023.webp)

![](06-19-14-27-02-2023.webp)

C1 = VCC
C2 = RST
C3 = CLK
C5 = GND
C6 = VPP
C7 = IO


## sim-card-dat

SIM_VDD

w/current limit resistor, filter cap
- SIM_DATA -> pull-up to SIM_VDD by 1K
- SIM_RST
- SIM_CLK

![](2024-07-10-01-16-22.webp)



## sim holder dat 

- [[sim-card-dat]] - [[SIM_Holder-dat]] - [[SIM-dat]] - [[SIM]]


We only use one kind of sim card, which is the nano type. It is the normal type used on iphone or most common modern phone.

### Nano Sim 


### micro sim

![](40-45-15-26-07-2023.webp)

![](51-45-15-26-07-2023.webp)

![](16-47-15-26-07-2023.webp)


### Common Sim




## REF 

- [[SIM_Holder-dat]] - 注意事项 = [[SIM]]