
# P-MOS-dat


- [[mosfet-dat]] - [[mos-n-dat]] - [[mos-p-dat]]





## control 

- [[adc-dat]]


## parts 





- [[Alpha-omega-dat]]

- `AO4407A` == 30V P-Channel MOSFET == SOP8
    - VDS = -30V
    - ID = -12A


- [[AO3401-dat]]

- IRLML6402 TRPBF
- SI2318 A

- IRF4905
- IRF9540N

`SI4435` - SOIC-8 P沟道 -30V/-8.1A 贴片MOSFET

`SI2307` - P-CHANNEL MOSFET == 2.7A -30V == `A7SHB` 


IRLML6402TRPBF




## P-mosfet 

| gate | status | source | drain |
| ---- | ------ | ------ | ----- |
| OFF  | ON     | -      | -     |
| ON   | OFF    | -      | -     |



## high-side drive by P-mos

To use a P-channel MOSFET (P-MOS), you should use it as a high-side switch.

Explanation:

- A P-MOS turns ON when its gate voltage is lower than its source voltage (typically, gate pulled to ground or a lower voltage).
- In a high-side configuration, the source is connected to the positive supply (Vcc), and the drain connects to the load.
- When you pull the gate low, the P-MOS conducts, allowing current to flow from Vcc through the load to ground.

Low-side drive is typically used with N-channel MOSFETs, not P-channel.




## ref 

- [[mosfet-dat]]