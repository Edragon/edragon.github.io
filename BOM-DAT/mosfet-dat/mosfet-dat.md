
# mosfet-dat



## model selections 


| Model    | Mark | Manufactuers      |          | CH type | Descriptions                                |
| -------- | ---- | ----------------- | -------- | ------- | ------------------------------------------- |
| AOD403   | D403 | [[AOSMD-dat]]     |          |         |                                             |
| AOD4184A | 4184 | [[AOSMD-dat]]     |          | N       | 40V N-Channel MOSFET                        |
| IRF540N  |      | [[[Infineon-dat]] |          |         |                                             |
| NCE6050  |      | [[ncepower-dat]]  | TO-252-2 | N       | NCE N-Channel Enhancement Mode Power MOSFET |
| AO3401   | A19T | [[AOSMD-dat]]     |          |         |                                             |
| 2N7002   | 7002 |                   |          | N        |                                             |
| SI2301   |      |                   |          |         |                                             |
| SI2307   |      |                   |          |         |                                             |
| IRF5305  | 5305 | [[Infineon-dat]]  |          |         |
| IRFR1205 |      | [[IOR-dat]]       |          |         |


### dual channel 

| Model   | Mark | Manufactuers     | Descriptions |
| ------- | ---- | ---------------- | ------------ |
| IRF8313 |      | [[Infineon-dat]] |


### high power mosfet 

![](2024-08-28-14-43-36.png)


## circuit guides 


### load switching 

![](2024-10-06-15-13-53.png)

### Power switching is better with N-type devices

Because N-type transistors in general can carry more current than P-types, they are preferable for switching heavy loads. Low-side switching with N-type devices is easier than high-side switching and can often be done by microcontroller ports without the need for special drivers. Using an N-type transistor for high-side switching is possible but requires a control voltage higher than the load voltage connected to the source/emitter. Some sort of charge pump is needed to pull the gate/base above the source/emitter voltage. This complicates the design, not only making it more expensive but also increasing its sensitivity to noise and interference. Controlling such a high-side switch using PWM can be problematic because of the charge pump.

- ref - https://www.elektormagazine.com/articles/high-side-low-side-switching




## Parallel using Mosfet for higher performance 

![](2024-08-28-14-44-40.png)


## ref 

- [[mosfet]]