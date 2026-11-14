
# TP4056-dat

- [legacy wiki page](https://w.electrodragon.com/w/TP4056)

- [[battery-dat]] - [[battery-pack-dat]]

- [[battery-protector-1s-dat]] - [[battery-charger-1s-dat]] - [[battery-1s-dat]]

- [[battery-protector-dat]] - [[battery-charger-dat]] - [[battery-packs-dat]]



## boards 

- [[OPM1156-dat]] - [[OPM1083-dat]]



## tutorial

how to use single [[TP4056-dat]] to charge - [[battery-charger-2s-dat]] - [[2S-lithium-battery-charger-dat]]

## Parameters 


cacultation: 

    Ibat = charge current = Vprog / Rprog * 1200

    where Vprog = 1V 


| Rprog | Ibat   | calculation   |
| ----- | ------ | ------------- |
| 1.2K  | 1A     | 1.2/1.2 = 1   |
| 120 R | 10 A   | 1.20.12 = 10  |
| 2.4K  | 500 mA | 1.2/2.4 = 0.5 |
| 2K    | 580 mA |
| 1.5K  | 780 mA |

![](2026-03-07-13-02-20.webp)


## SCH 

build SCH `LGS4056` - [[legend-SI-dat]]

![](2026-09-05-01-42-45.webp)


SCH 1 

![](2023-12-21-16-08-28.webp)

![](2023-12-21-16-08-42.webp)


## Solar Type-C Solutions 

![](2025-07-09-12-51-28.webp)


## batter options than 

- [[MCP73871-dat]] - [[CN3791-dat]]


## demo 

![](2026-04-28-13-07-41.webp)


## build 


- [[HX4004-dat]] - [[TP4056-dat]] - [[dcdc-boost-dat]] - [[battery-charger-1s-dat]]

build 4 

- TC4056 

![](2026-09-22-20-50-52.webp)

![](2026-09-22-20-51-10.webp)




build 3 SCH 

![](2026-08-01-16-36-44.webp)

- CHG_STAT == to [[ESP32-dat]]
- STBY_STAT == to [[ESP32-dat]]



build 2 

![](2026-07-31-19-18-27.webp)

![](2026-07-31-19-18-17.webp)

unknown drive board 

![](2026-07-31-19-18-44.webp)


build 1 

![](2026-06-17-15-02-16.webp)


## ref 

- datasheet - [[TP4056.pdf]]

- [[TP-dat]]