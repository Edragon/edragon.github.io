
# power-flow-contro-dat

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