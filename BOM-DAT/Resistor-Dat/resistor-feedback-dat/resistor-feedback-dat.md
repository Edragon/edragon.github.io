
# resistor-feedback-dat


## dcdc-bulk-output-dat


when Vref = 0.6V

Vout = Vref * (R2/R3+1)

for 5V = 0.6V * (100K / ? + 1 )

100K / R3 = 5V/0.6V - 1 = 7.3333
100K / R3 = 5.2V/0.6V - 1 = 7.6666

R3 = 13.633K or below 13.3K for 5.2V


| output | rough | Rbot  | Rtop | Vref |
| ------ | ----- | ----- | ---- | ---- |
| 5V     | 5.2V  | 13.3K | 100K | 0.6V |
| 4.35V  | 4.35V | 16K   | 100K | 0.6V |
| 4.2V   | 4.2V  | 16.6K | 100K | 0.6V |
| 4V     | 3.93V | 18K   | 100K | 0.6V |


## FB  = VBAT＝1.205×(1＋R1／R2) 

电池端对应的的电压为： VBAT＝1.205×(1＋R1／R2) 



### parallel resistor 

https://www.digikey.cn/zh/resources/conversion-calculators/conversion-calculator-parallel-and-series-resistor

2x 1.88 MΩ in parallel ≈ 940 kΩ.

1 MΩ and 15.67 MΩ in parallel ≈ 940 kΩ.

2 MΩ and 3.714 MΩ in parallel ≈ 1.3 MΩ.

3x 3.9 MΩ resistors in parallel = 1.3 MΩ


for - [[LFP-dat]] 

    = 1.205 x ( 1 + 510k ∕ 100k) = 1.205 ⅹ 6.1 = 7.36V
    = 1.205 x ( 1 + 800k ∕ 100k) = 1.205 ⅹ 9 = 10.845V
    = 1.205 x ( 1 + 1000k ∕ 90k) = 1.205 ⅹ 12.11 = 14.6V

for - [[li-battery-dat]]

    = 8.4 / 1.205 - 1 = 5.97, R4 = 5.97 ⅹ R5, if R5 = 100k, R4 = 597k, use 590k
    = 12.6 / 1.205 - 1 = 9.46, R4 = 9.46 ⅹ R5, if R5 = 100k, R4 = 946k, use 940k
    = 16.8 / 1.205 - 1 = 12.93, R4 = 12.93 ⅹ R5, if R5 = 100k, R4 = 1293k, use 1.2M + 100k in series
    = 25.2 / 1.205 - 1 = 19.9, R4 = 19.9 ⅹ R5, if R5 = 100k, R4 = 1990k, use 2M





## ref 

- [[battery-pack-dat]]

- [[dcdc-down-dat]] 

- [[CN3305-dat]]