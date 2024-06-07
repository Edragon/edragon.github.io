
# dcdc-bulk-output-dat


when Vref = 0.6V

Vout = Vref * (R2/R3+1)

for 5V = 0.6V * (100K / ? + 1 )

100K / R3 = 5V/0.6V - 1 = 7.3333
100K / R3 = 5.2V/0.6V - 1 = 7.6666

R3 = 13.633K or below 13.3K for 5.2V


| output | rough | Rbot  | Rtop | Vref |
| ------ | ----- | ----- | ---- | ---- |
| 5V     | 5.2V  | 13.3K | 100K | 0.6V |
| 4V     | 3.93V | 18K   | 100K | 0.6V |