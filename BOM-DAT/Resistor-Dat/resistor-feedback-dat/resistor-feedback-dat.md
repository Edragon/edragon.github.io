
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
| 5V     | 5.18V  | 13.3K | 100K | 0.6V |
| 5V     | 5.31V  | 13K | 100K | 0.6V |
| 4.35V  | 4.35V | 16K   | 100K | 0.6V |
| 4.2V   | 4.2V  | 16.6K | 100K | 0.6V |
| 4V     | 3.93V | 18K   | 100K | 0.6V |


## FB  = VBAT＝1.205×(1＋R1／R2) 

电池端对应的的电压为： VBAT＝1.205×(1＋R1／R2) 


## R2  = ( R1 x 1.221 ) / ( VOUT - 1.221 )

- = ( 10K x 1.221 ) / ( 5V - 1.221 ) = 3.23K ~ 3.24K

VOUT = ( R1 x 1.221 ) / R2 + 1.221 
= ( 10K x 1.221 ) / 3.3K + 1.221 = 4.921V
= ( 10K x 1.221 ) / 3K + 1.221 = 5.27V

= ( 12K x 1.221 ) / 3.3K + 1.221 = 5.661V
= ( 12K x 1.221 ) / 3.9K + 1.221 = 4.95V
= ( 12K x 1.221 ) / 4.7K + 1.221 = 4.34V
= ( 13K x 1.221 ) / 3K + 1.221 = 6.48V
= ( 14K x 1.221 ) / 4.7K + 1.221 = 5.61V

= ( 9.1K x 1.221 ) / 2.8K + 1.221 = 5.19V


### parallel resistor 

https://www.digikey.cn/zh/resources/conversion-calculators/conversion-calculator-parallel-and-series-resistor


## 1.205 x ( 1 + R4 ∕ R5) parallel 

| R1       | R2       | Rsum     |
| -------- | -------- | -------- |
| 2M       | 820K     | 581K     |
| **2M**   | **845K** | **594K** |
| 1.8M     | 845K     | 575K     |
| 1.6M     | 910K     | 580K     |
| 2M       | **1.8M** | **947K** |
| **1.2M** |          | 1.2M     |
| 2M       |          | 2M       |


2x 1.88 MΩ in parallel ≈ 940 kΩ.

1 MΩ and 15.67 MΩ in parallel ≈ 940 kΩ.

2 MΩ and 3.714 MΩ in parallel ≈ 1.3 MΩ.

3x 3.9 MΩ resistors in parallel = 1.3 MΩ

## 1.205 x ( 1 + R4 ∕ R5) series 

for - [[LFP-dat]] 

    = 1.205 x ( 1 + 510k ∕ 100k) = 1.205 ⅹ 6.1 = 7.36V
    = 1.205 x ( 1 + 800k ∕ 100k) = 1.205 ⅹ 9 = 10.845V
    = 1.205 x ( 1 + 1000k ∕ 90k) = 1.205 ⅹ 12.11 = 14.6V



## li-battery 

- [[resistor-feedback]]



8.4V 

- if R5 = 100k, R4 = 576k, voltage = 1.205 x (1 + 576k / 100k) = 8.14V 
- if R5 = 100k, R4 = 604k, voltage = 1.205 x (1 + 604k / 100k) = 8.48V

- if R5 = 110k, R4 = 576k, voltage = 1.205 x (1 + 576k / 110k) = 7.515V
- if R5 = 95.3k, R4 = 576k, voltage = 1.205 x (1 + 576k / 95.3k) = 8.488V


- if R5 = 97.6k, R4 = 576k, voltage = 1.205 x (1 + 576k / 97.6k) = 8.316

12.6V 

- if R5 = 97.6k, voltage = 12.6V, R4 = (12.6 / 1.205 - 1) * R5 = 946k, use 923k

- if R5 = 97.6k, R5 = 910K, voltage = 1.205 x (1 + 910k / 97.6k) = 12.44V

16.8V 
- if R5 = 97.6k, voltage = 16.8V, R4 = (16.8 / 1.205 - 1) * R5 = 1263k, use 1.2M 

- if R5 = 97.6k, R4 = 1.2M, voltage = 1.205 x (1 + 1200k / 97.6k) = 16.02V

6 * 4.2 = 25.2V

- if R5 = 97.6k, R4 = 2M, voltage = 1.205 x (1 + 2000k / 97.6k) = 25.9V
- if R5 = 100 k, R4 = 2M, voltage = 1.205 x (1 + 2000k / 100k) = 25.3V



## obseleted

| R4                | R5      | target Vout | actual Vout |
| ----------------- | ------- | ----------- | ----------- |
| 576K 1% + 13K 5%  | 100K 1% | 8.4V        | 8.3         |
| 940K 1% + 4.7K 5% | 100K 1% | 12.6V       | 12.59       |
| 1.2M 1% + 47K 5%  | 100K 1% | 16.8V       | 16.26       |
| 1.9M 1% + 47K 5%  | 100K 1% | 25.2V       | 24.1        |

for - [[li-battery-dat]]

    = 8.4 / 1.205 - 1 = 5.97, R4 = 5.97 ⅹ R5, if R5 = 100k, R4 = 597k, use 590k
    = 12.6 / 1.205 - 1 = 9.46, R4 = 9.46 ⅹ R5, if R5 = 100k, R4 = 946k, use 940k
    = 16.8 / 1.205 - 1 = 12.93, R4 = 12.93 ⅹ R5, if R5 = 100k, R4 = 1293k, use 1.2M + 100k in series
    = 25.2 / 1.205 - 1 = 19.9, R4 = 19.9 ⅹ R5, if R5 = 100k, R4 = 1990k, use 2M




## CN3722 

Vbat = 2.416 × (1 + R7 / R6)

where R7 = 14K 

| Battery Type | Vfb (kΩ) | Output Voltage (V) |
| ------------ | -------- | ------------------ |
| LIFEPO4      | 28.7     | 3.6                |
| LIFEPO4      | 7.5      | 7.2                |
| LIFEPO4      | 4.02     | 10.8               |
| Li+          | 19.1     | 4.2                |
| Li+          | 5.76     | 8.4                |
| Li+          | 3.3      | 12.6               |




## ref 

- [[resistor-feedback]]

- [[battery-pack-dat]]

- [[dcdc-down-dat]] 

- [[CN3305-dat]]

- [[resistor]]