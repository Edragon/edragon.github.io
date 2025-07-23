
# power-flow-contro-dat


## 12/24V to 3.3V


- It is more reliable to use a 5V DC-DC converter first, then use a linear regulator chip to step down to 3.3V. Directly outputting 3.3V from a DC-DC converter can easily damage the microcontroller due to surge voltage.
- The output of a DC-DC module is not regulated; when powered on with a light load, the output voltage is higher than 3.3V. A load must be added to stabilize it at 3.3V, so an LDO should be connected afterward.
- My usual approach is to step down from 24V to 5V first, then use a [[B0505-dat]] module for isolation, and finally step down to 3.3V. The 0505 module is much cheaper than an isolated 24V-to-5V module.


## USB Logic control for [[SDR1096-DAT]]

[[logic-gate-dat]]


- OE stay off by pull up resistor (default)
- OE turn on by **USB_ID or PA28_USB_HOST_EN pull down**
  - **USB_ID or PA28_USB_HOST_EN pull down** further turn on [[mos-p]]
  - VBUS -> VIN via [[mos-p]] (default off by pull up resistor)


![](2023-12-18-15-43-51.png)



## P-ch Mosfet select for [[ARM1007-dat]]


![](2024-10-15-17-29-50.png)

working table 

| Input | mos-ctrl | working          |
| ----- | -------- | ---------------- |
| VBAT  | ON       | direct to +5V    |
| VBUS  | OFF      | via diode to +5V |


## P-ch Mosfet select V2 for [[ARM1003-dat]]

- [[mosfet-dat]]

| VBUS @ gate | p-mos | BAT | VCC    | note       |
| ----------- | ----- | --- | ------ | ---------- |
| ON          | OFF   | OFF | = VBUS | via diode  |
| OFF         | ON    | ON  | = VBAT | via mosfet |


![](2025-02-03-17-18-57.png)