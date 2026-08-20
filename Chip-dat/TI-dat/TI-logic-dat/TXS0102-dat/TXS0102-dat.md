
# TXS0102-dat

- [[voltage-dat]] - [[logic-level-shifter-dat]] - [[VBAT-dat]] - [[VDD_ext-dat]] == 1.8V 




`TXS0102DCUR` - `VSS0P-8`

TXS0102DCUT

TXS0102 DCUR


TXS0102 DQER `X2SON-8` 

mark == `NFER`

- [[PCB-footprint-dat]]


## test 

- 3.3V/5V set to 5V VUSB 
- wiring VBUS, TXD RXD, GND 
- 
![](2025-07-03-20-22-06.png)


## wiring 

Normal Operation: Both $V_{CCA}$ and $V_{CCB}$ must be actively powered within their specified operating ranges ($1.65\text{V} \le V_{CCA} \le 3.6\text{V}$ and $2.3\text{V} \le V_{CCB} \le 5.5\text{V}$), keeping the condition that $V_{CCA} \le V_{CCB}$. Decoupling capacitors (e.g., $0.1\,\mu\text{F}$) should be placed close to each supply pin.


## ref 

- [[serial-dat]]