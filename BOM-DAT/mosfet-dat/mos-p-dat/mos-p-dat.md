
# P-MOS-dat

- [[mosfet-dat]]


- IRLML6402 TRPBF
- SI2318 A

## control 

- [[adc-dat]]




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



## parts 

- [[AO3401-dat]]


## ref 

- [[mosfet-dat]]