# battery drainer dat

- battery drainer
- https://twitter.com/electro_phoenix/status/1706211461562089835

## Battery Type Boost Chips

| Header text | Input Voltage | Vout / Iout | No Load Current | Perpherial | Shutdown Current | -     |
| ----------- | ------------- | ----------- | --------------- | ---------- | ---------------- | ----- |
| QX2304      | 0.9-5V        | -           | 15uA            | 3          |                  |       |
| HX4002B     | 2.7-5V        | 2-5V        | 250mA           | 1.8mA      | 3                | 0.2uA |
| XA2320B     | 2.7-5.5V      | 2-5V        | 250mA           | 1.77mA     | 3                | 0.6uA |
| TPS61221    | 0.7-5.5V      | 1.8-6V      | 400mA           | 5.5uA      | 3                | 0.2uA |
| MAX1797     | 0.7V~5.5V     | ~5.5V       | 550mA           | 25uA       | 3                |       |
| ME2108      | 0.9V~6.5V     | 2-7V        | 400mA           | 59-92 uA   | 4                | -     |
| ME2188      | 0.9-5V        | -           | 1000mA          | 13 uA      | 3                | -     |

* TPS61221

###  Selection guide 
* LM - http://www.ti.com/power-management/non-isolated-dc-dc-switching-regulators/step-up-boost/boost-converters-integrated-switch/products.html#p634min=10;200
* select only Vmax >= 60V


## boards

- [[OPM1133-dat]]
