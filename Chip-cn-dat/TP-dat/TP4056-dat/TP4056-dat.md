
# TP4056-dat

- [legacy wiki page](https://w.electrodragon.com/w/TP4056)

- [[battery-dat]] - [[battery-pack-dat]]


## boards 

- [[OPM1156-dat]] - [[OPM1083-dat]]



## tutorial

how to use single [[TP4056-dat]] to charge - [[2S-lithium-battery-charger-dat]]

## Parameters 


cacultation: 

    Ibat = charge current = Vprog / Rprog * 1200

    where Vprog = 1V 


| Rprog | Ibat   | calculation   |
| ----- | ------ | ------------- |
| 1.2K  | 1A     | 1.2/1.2 = 1   |
| 120 R | 10 A   | 1.20.12 = 10  |
| 2.4K  | 500 mA | 1.2/2.4 = 0.5 |




## SCH 

![](2023-12-21-16-08-28.png)

![](2023-12-21-16-08-42.png)


## Solar Type-C Solutions 

![](2025-07-09-12-51-28.png)


## batter options than 

- [[MCP73871-dat]] - [[CN3791-dat]]


## ref 

- datasheet - [[TP4056.pdf]]