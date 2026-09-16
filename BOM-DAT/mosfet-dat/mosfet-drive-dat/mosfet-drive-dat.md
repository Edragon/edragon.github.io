


# mosfet-drive-dat

- [[mosfet-drive-dat]] - [[mosfet-driver-dat]]

- [[drive-dat]]

- [[mosfet-drive-dat]] - [[mosfet-drive-side-low-dat]] - [[mosfet-drive-side-high-dat]] 

- [[PCB-design-power-dat]]


- [[power-switch-dat]] - [[mosfet-drive-dat]] - [[mos-n-drive-dat]] - [[mos-n-dat]]



## build 

### drive method 1 

board - [[X12-dat]] - [[FPV-dat]] - [[FPV-fix-dat]]

- [[transistor-dat]] == 1N - [[resistor-dat]] - [[diode-dat]] == L1

                    【公共驱动供电轨 (V_DRIVE)】(通常挂在 5V、或由自举电容充到 ~10V/VBAT)
                                 │
                            [二极管 L1] ───► [电容 C] (自举/储能滤波电容)
                                 │                 │
                           [电阻 R1 (上拉)] ───────┘
                                 │
                                 ├───► 【主功率 MOSFET 的 G 极】
                                 │
                   [电阻 R2 (限流/阻尼)]
                                 │
  EFM8 (3.3V IO) ──► [三极管 1N (基极/栅极)]
                                 │
                                [GND]


各元件职责：
1. 三极管 1N（下管开关 / 放电通路）：
   - 丝印 1N（通常是 BSS138 等 N-MOS，或 NPN 三极管）。
   - 当 EFM8 发出高电平时，1N 导通，把主 MOSFET 的 G 极快速拉到 GND，迫使主功率管快速动作（或反相控制）。
2. 二极管 L1 + 电容（自举/防倒灌供电）：
   - 丝印 L1（如 BAS40 / BAT54 类肖特基二极管）。
   - 它的作用是从板载主电源吸取能量，给电容充电，维持主 MOSFET 栅极所需要的开启偏置电压（V_DRIVE）。
3. 2 个电阻：
   - R1（上拉电阻，通常几 kΩ ~ 10kΩ）：把 G 极拉高到开启电压。
   - R2（栅极限流/基极电阻，几十 Ω ~ 1kΩ）：抑制震荡并保护 EFM8 的 IO。


## ref 


