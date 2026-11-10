
# capacitor-dat 


- [[capacitor-dat]] - [[capacitor-dc-blocking-dat]] - [[capacitor-MLCC-dat]] - [[sensor-microphone-dat]]

- [[circuits-dat]] - [[PCB-design-dat]] - [[resistor-dat]] - [[capacitor-dat]] - [[RCL-dat]]


- [[capacitor-decoupling-dat]] - [[capacitor-ac-coupling-dat]]

- [[capacitor-dat]] - 100UF / 450V - [[power-adapter-dat]]

- [[capacitor-X2-dat]] - [[power-adapter-dat]] == 47K 300V-40/105/21 - [[capacitor-x-y-dat]]



- [[ESR-capacitor-dat]] - [[MLCC-dat]] - [[Electrolytic-cap-dat]] - [[tantalum-dat]]


- [[capacitor-X2-dat]] - [[capacitor-dat]] - [[capacitor-x-y-dat]] - [[capacitor-safety-dat]] - [[capacitor-x-y-dat]] - [[capacitor-dat]]



[[capacitor-dat]] - [[capacitor-safety-dat]]





## 0.1UF ( C0805 )

容差 ±5%（J），用于替代 ±10%（K）。

注意：Class II 陶瓷的温漂本身就是 ±15%，所以 J 只在 25°C 标称条件下更接近 100 nF，并不会让整机更稳定。

- “优质 / 普通”：卖家自行给品质分档，行业内没有定义，必须问清具体含义
- “三环”：指潮州三环（CCTC），是国产 MLCC 一线厂牌，属于品牌指定，并非品质级别

- 0805   封装 2.0 × 1.25 mm
- 104    容值 = 10 × 10⁴ pF = 100 nF = 0.1 µF
- K      容差 ±10%（J = ±5%，M = ±20%）
- 50V    额定直流电压
- 4K/盘  每盘 4000 只（2K = 2000 只）

1）介质材质没写 —— 这是最大的坑

104K 既可能是 `X7R（-55~125°C，±15%）`，也可能是 `Y5V（-30~85°C，+22/−82%）`。

- 在直流偏压下，Y5V 的容值下降更猛：同样 6.3V 耐压、1.8V 偏置时，X5R 掉约 10%，Y5V 掉约 40%（Murata 实测）
- X7R 也不能只看标称值：0805 的 X7R 4.7µF 在 12V 偏压下典型只剩 32.6%（Analog Devices 实测表），此时换成 1206 封装才能达到 73%

所以“104”从来不等于“在电路里真的有 100 nF”。




## brands 

common brand: 	Chemi-Con, Vishay, TDK, Pansonic, KEMET, Nichicon



## function 

- [[capacitor-decoupling-dat]]

- [[capacitor-start-dat]] - [[capacitor-CBB-dat]]

- [[capacitor-x-y-dat]]






## Aluminum Electrolytic Capacitors - Radial Leaded

UPM1C102MPD

- Capacitance:	1000 uF	
- Voltage Rating DC:	16 VDC	
![capacitor-x-y-dat/2026-01-25-20-38-52.png](capacitor-x-y-dat/2026-01-25-20-38-52.webp)
- Length:	31.5 mm	
- Lead Spacing:	5 mm
- Product:	Low Impedance Electrolytic Capacitors
- ESR:	47 mOhms
- [mouser](https://www.mouser.com/ProductDetail/Nichicon/UPM1C102MPD?qs=sGAEpiMZZMvwFf0viD3Y3asoeH%252BozipbRshjmM7HrXA%3D)

ESE476M063AG3AA

- Capacitance:	47 uF	
- Voltage Rating DC:	63 VDC	
- Diameter:	8 mm	
- Length:	11 mm	
- Lead Spacing:	3.5 mm	
- Product:	General Purpose Electrolytic Capacitors

## CPOL SMD == Aluminum Organic Polymer Capacitors

Tantium PTH capacitor 

![](2025-05-24-19-47-18.webp)


- 470nF_±10%_35V
- 1uF_±10%_50V
- 2.2uF_±10%_16V
- 2.2uF_±10%_35V
- 4.7uF_±10%_16V
- 4.7uF_±10%_25V
- 4.7uF_±10%_35V
- 4.7uF_±10%_50V
- 10uF_±10%_16V
- 10uF_±10%_25V
- 10uF_±10%_35V
- 10uF_±10%_50V
- 22uF_±10%_16V
- 22uF_±10%_35V
- 47uF_±10%_16V


### 10SVP150MX

- Capacitance:	150 uF
- Voltage Rating DC:	10 VDC
- Manufacturer:	Panasonic
- ESR:	35 mOhms
- [mouser](https://www.mouser.com/ProductDetail/Panasonic/10SVP150MX?qs=OE1iw1LrrPHivwvo07HIWQ%3D%3D&srsltid=AfmBOoo4rCaynTxtMDlHuMfp_wQLsJcUsBf7wrQTaFRQ64rotDMANhCK)
- Aluminum Organic Polymer Capacitors 10volts 150uF ESR 35mohm




## Specs 

The 3-Character Capacitor Code
The three-character code with the letter-number-letter format is used for capacitors with Class 2 and Class 3 dielectrics. C0G is a Class 1 dielectric, so it’s not included (more on this later). X5R and X7R are in Class 2, and Y5V is in Class 3.

- The first character indicates the lowest temperature that the capacitor can handle. The letter X (as in X7R, X5R) corresponds to –55°C.
- The second character indicates the maximum temperature. The theoretical range is from 45°C to 200°C; 5 (as in X5R) corresponds to 85°C, and 7 (as in X7R) corresponds to 125°C.
- The third character indicates the maximum amount of capacitance change over the part’s temperature range. The spec for --R capacitors (such as X5R and X7R) is ±15%. The capacitance of parts with a code ending in V can actually decrease by as much as 82%! This probably explains why Y5V capacitors are not so popular.


![](2023-12-29-18-18-14.png)






### DC blocking capacitor


## What is a DC Blocking Capacitor?

A **DC blocking capacitor** is an electronic component used to:

- **Block DC (direct current)** signals
- **Pass AC (alternating current)** signals

### How it works:
- Capacitors **do not allow DC** to flow through once fully charged.
- Capacitors **allow AC** to pass because the voltage across them is always changing.

### Common Usage:
- Audio circuits (to prevent DC offset)
- Signal coupling between stages of amplifiers
- Input protection for sensitive devices

### Symbol:

    ---||---

### Example:

In an audio amplifier:

The capacitor blocks DC from the source, letting only the AC audio signal pass.



##  None-Polarized Capacitors

### monolithic ceramic capacitor

![](2025-05-25-19-21-13.webp)

- 20pF_±10%_50V (50只)
- 22pF_±10%_50V (50只)
- 30pF_±10%_50V (50只)
- 33pF_±10%_50V (50只)
- 47pF_±10%_50V (50只)
- 100pF_±10%_50V (50只)
- 150pF_±10%_50V (50只)
- 200pF_±10%_50V (50只)
- 220pF_±10%_50V (50只)
- 330pF_±10%_50V (50只)
- 470pF_±10%_50V (50只)
- 680pF_±10%_50V (50只)
- 1nF_±10%_50V (50只)
- 2.2nF_±10%_50V (50只)
- 3.3nF_±10%_50V (50只)
- 4.7nF_±10%_50V (50只)
- 10nF_±10%_50V (50只)
- 22nF_±10%_50V (50只)
- 33nF_±10%_50V (50只)
- 47nF_±10%_50V (50只)
- 100nF_±20%_50V (50只)
- 150nF_±10%_50V (50只)
- 220nF_±10%_50V (50只)
- 330nF_±10%_50V (50只)
- 470nF_±10%_50V (50只)
- 1uF_±10%_50V (50只)
- 4.7uF_±10%_50V (50只)


## C0805 

- **100NF / 50V**
- **1UF / 16V**
- **10UF / 10V**


## C1206 

- **22UF / 35V**
- **22UF / 50V**
- **100UF / 10V**


## feed through capacitor 

657-PSM1-402Z-10B == Feed Through Capacitors 4000PF 10A PI - Surface Mount Low Pass Filters PSM Series



## JNC JN 222M 


| Parameter        | Value (typical)          |
|------------------|--------------------------|
| Capacitance      | 2.2 nF (2200 pF)         |
| Tolerance        | ±20%                     |
| Dielectric       | Ceramic (disc type)      |
| Voltage rating   | ~400 VAC (may vary)      |
| Package          | Radial ceramic disc      |


### Common applications

- EMI / noise suppression
- Snubber or filtering circuits
- High-voltage signal coupling
- Non-precision timing circuits


## decouple 

![](2026-03-04-20-26-20.webp)


## types 

### 3A222J 

- [[acdc-dat]]

The 3A222J is a high-voltage polyester (Mylar) film capacitor.

Specifications

- • Type: Polyester (Mylar) film capacitor (CL11 style)
- • Capacitance: 2.2 nF (2200 pF or 0.0022 µF)
- • Rated Voltage: 1000V DC
- • Tolerance: ±5% (indicated by the letter "J")
- • Common Uses: Audio equipment, power supplies, filtering, coupling, and decoupling circuits





## ref 



- [[capacitor]]


- [[BOM-dat]]