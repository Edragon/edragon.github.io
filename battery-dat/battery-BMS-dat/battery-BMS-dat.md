
# battery-BMS-dat


- [[li-battery-dat]] - [[battery-BMS-dat]] - [[battery-pack-dat]] - [[battery-dat]]


- [[passive-BMS-dat]] - [[active-BMS-dat]]

- [[fast-charge-methods-dat]] - [[USB-PD-dat]]


- [[BMS]]



## charge and supply 2in1 

- CD42

- [[power-bank-dat]] 



## 3. Protection Features

Look for these essential protections:

| Protection Type          | Description                              |
|--------------------------|----------------------------------------|
| Overcharge protection     | Stops charging if cell voltage too high|
| Overdischarge protection  | Prevents deep discharge that damages cells |
| Overcurrent protection    | Cuts off current if it exceeds safe limits |
| Short circuit protection  | Immediate cutoff on short circuit detection |
| Balancing                | Balances cells to keep voltages equal (especially important for multi-cell packs) |
| Temperature protection    | Monitors temperature to avoid overheating |

- also check the board's temperature rising when dishcarging 


## BMS

- 锂电池保护板是对串联锂电池组的充放电保护；
- 在充满电时能保证各单体电池之间的电压差异小于设定值，之实现电池组各单体电池的均充，有效地改善了串联充电方式下的充电效果；
- 同时检测电池组中各个单体电池的过压欠压、过流、短路、过温状态，保护并延长电池使用寿命
- 欠压保护使每一单节电池在放电使用时避免电池因过放电而损坏。


## 🔋 Active vs. Passive BMS

A **Battery Management System (BMS)** monitors and protects battery packs, especially lithium-based ones, from overcharging, overdischarging, and overheating. It also performs **cell balancing** to maintain consistent voltage across cells.



---

### ✅ 1. Passive BMS

#### 🔧 How It Works:
- **Dissipates excess energy** from high-voltage cells as **heat** using resistors.
- Bleeds off charge from full cells so others can catch up during charging.

#### ⚙️ Features:
- Simple and inexpensive
- Uses resistors and MOSFETs
- Common in e-bikes, power tools, and budget battery systems

#### ⚠️ Downsides:
- Wastes energy
- Balancing is slower
- Less efficient for large or high-performance systems

---

### ✅ 2. Active BMS

#### 🔧 How It Works:
- **Transfers charge** from higher-voltage cells to lower-voltage ones using capacitors, inductors, or DC-DC converters.
- Recycles energy instead of burning it off.

#### ⚙️ Features:
- High efficiency
- Faster, more accurate balancing
- Used in electric vehicles (EVs), drones, and large battery banks

#### ⚠️ Downsides:
- More complex and expensive
- Requires advanced control circuitry

---

### 🔄 Summary Table

| Feature            | **Passive BMS**                   | **Active BMS**                       |
| ------------------ | --------------------------------- | ------------------------------------ |
| Energy Handling    | Dissipates as heat                | Transfers charge between cells       |
| Efficiency         | Low                               | High                                 |
| Complexity         | Simple                            | Complex                              |
| Cost               | Low                               | High                                 |
| Speed of Balancing | Slow                              | Fast                                 |
| Common Use Cases   | E-bikes, power tools, small packs | EVs, solar storage, high-end systems |

---

### 🤔 Which Should You Use?

- **Passive BMS**: Ideal for small to medium systems with basic balancing needs.
- **Active BMS**: Best for large, high-value, or performance-critical battery systems.


## BMS Charging 

🔌 Can I Use a 12V AC-DC Plug to Charge a 3S1P Lithium Battery Pack with BMS?

### 🔋 Battery Overview: 3S1P Lithium-Ion Pack

- **3S** = 3 cells in series → 3.7V × 3 = **11.1V nominal**
- **Full charge voltage** = 4.2V × 3 = **12.6V**
- **Charging voltage required**: **12.6V constant voltage (CV)**
- **Typical charging current**: 1A–2A (depending on cell & BMS)

---

### ⚠️ Can You Use a 12V AC-DC Plug?

| **Plug Output Voltage**  | **Can You Use It?** | **Explanation**                               |
| ------------------------ | ------------------- | --------------------------------------------- |
| **12.0V**                | ⚠️ Not ideal         | Will undercharge the pack (only ~90–95% full) |
| **12.6V regulated**      | ✅ Yes               | Perfect match for 3S lithium pack             |
| **>12.6V (e.g., 13.8V)** | ❌ No                | May overcharge and damage the battery/BMS     |
| **Unregulated output**   | ❌ No                | Unsafe — may exceed safe voltage limits       |

---

### ✅ Best Practice: Use a Dedicated 3S Lithium Charger

- **Output Voltage**: 12.6V DC (constant voltage)
- **Current Limit**: 1A–2A (match your BMS and battery spec)
- **Charging Profile**: CC/CV (Constant Current / Constant Voltage)

---

### 🔐 Role of the BMS

- Provides **protection** (overcharge, over-discharge, short circuit, etc.)
- **Does NOT regulate** the input voltage
- **Still requires** a proper 12.6V charger to function safely

---

### ✅ Summary

- You **can** charge your 3S1P pack with a **regulated 12.6V charger**.
- A **standard 12.0V plug** is **not recommended** — it won’t fully charge the battery.
- Avoid any charger **above 12.6V** unless it’s specifically designed for lithium charging.

### Charger 

| Requirement            | Needed? | Why                                   |
| ---------------------- | ------- | ------------------------------------- |
| Smart chip like TP4056 | ❌ No    | Your **BMS provides safety features** |
| Proper voltage (12.6V) | ✅ Yes   | Essential for full charge             |
| Current limiting       | ✅ Yes   | Prevents overheating or stress        |
| CC/CV charging         | ✅ Yes   | Ensures correct lithium charging      |


## Single Cell Protection solution 

### A1870 + 3GJG (bad quality combination)

A1870 - [[uc1870+ver1_x76b.pdf]]

G3JQ - S8261 - [[S8261_E.pdf]]

![](2025-02-21-18-52-52.png)

### DW01 + FM8205

### protection board 

- [[week-4-8-dat]]



## Precautions before applying BMS:

1. Before installing the protection board, make sure the batteries are matched:
   
- the voltage difference between each battery should not exceed 0.05V, 
- the internal resistance difference should not exceed 5mΩ
- and the capacity difference should be less than 30mAh. 

The smaller the voltage difference between the batteries, the better the performance of the protection board.

2. Connect the batteries in parallel first, then in series, and ensure correct welding (use nickel strips for spot welding on 18650 batteries, and solder for other batteries). 

Never use screws to fasten them, as this may damage the IC of the protection board.

3. If you are replacing the protection board on old batteries, please check whether the batteries are in good condition before purchasing.

4. During installation, use a multimeter to check whether the voltage of each battery in the series is the same. 
   
If the voltage difference exceeds 1.0V, it may indicate a fault such as poor range, power cut-off at startup, or short charging time, which are often caused by battery cell issues. 

A protection board fault typically results in: inability to charge, or the battery has voltage but cannot discharge.




## CN 

### 一、核心功能（最重要）

#### 1️⃣ 安全保护（最核心）
防止电池进入危险状态：
- 过充保护（Overcharge）
- 过放保护（Over-discharge）
- 过流保护（Over-current）
- 短路保护（Short Circuit）
- 过温 / 低温保护（Over / Under Temperature）

👉 **没有 BMS，锂电池是高度危险的**

---

#### 2️⃣ 电池状态监测（Monitoring）
实时监控电池关键参数：
- 单体电压（Cell Voltage）
- 总电压（Pack Voltage）
- 电流（Charge / Discharge Current）
- 温度（Cell / MOS / 环境）

---

#### 3️⃣ 电量估算（SOC）
- SOC（State of Charge，剩余电量）
- 有时包含 SOH（State of Health，健康状态）

👉 告诉系统 **“还剩多少电、还能不能用”**



## BMS use guide note 



- To reliably start a power tool (for example an electric drill), use either 2 high‑current cells rated 10C–20C, or 4 cells rated 5C–10C in appropriate parallel/series combinations. Recommended cells: Sony VTC4, VTC4A, VTC5, VTC6. Use wiring capable of the current (use >2 mm² copper wire; do not use thin foil or traces).
- On first-time assembly, charge the cells before use to ensure the pack provides output. Follow the wiring diagram exactly: connect 0 V, mid-point (4.2 V), and 8.4 V as shown. When soldering battery wires, avoid touching any board components and do not short the pack.
- During initial soldering or while charging, whenever a single cell exceeds ~4.2 V the resistor labeled “430” on the board will heat as it bleeds/discharges the cell (it will stop heating when the cell discharges to ~4.19 V). If the “430” resistor becomes excessively hot (too hot to touch), immediately check for wiring errors.

- 1.严格按图接线0V、4.2V、8.4V、12.6V，注意检查不要短路。
- 2.串联3组电池时，请保证每组电池的电压一样，如果不一样，请单独充满每组电池再串联使用。放电测试时，电压下降较快的那组电池是差电池，请用好的替换掉。
- 3.千万不要把好电池和差电池混在一起使用，新、旧电池也不能混在一起使用。
- 4.成功启动电钻需要3个15C-20C的动力电池，或6个10C-15C的动力电池（普通的18650不能启动电钻！！！）。
- 5.带有刷电机类的负载时，必须在电机的正负接线端并联一个无极性电容（耐压25V以上，容量10uF-100uF），防止电机产生的反向尖峰电压干扰保护板或击穿MOS管。





## ref 



- [[BMS]] - [[battery]]