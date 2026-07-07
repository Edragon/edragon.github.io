
# battery-capacity-dat


- [[energy-dat]]

- [[18650-dat]] - [[26650-dat]] - [[battery-dat]]


# Understanding "One Kilowatt-Hour" (1 kWh) vs "Ampere-Hour" (Ah)

The terms **"One kilowatt-hour" (一度电)** and **"Ampere-hour" (Ah)** belong to different physical dimensions. They **cannot be converted directly** without knowing the operational **Voltage (V)** of the system.

*   **Kilowatt-hour (kWh):** This is a unit of **Energy (Electrical Work)**. It represents the total amount of electricity consumed by a 1000-watt appliance running for exactly 1 hour. (Note: 1 kWh = 1000 Wh).
*   **Ampere-hour (Ah):** This is a unit of **Battery Capacity (Electric Charge)**. It indicates how much current a battery can deliver continuously for 1 hour.

The formula linking these two units is defined by Ohm's Law and electrical power equations:

Capacity (Ah) = Energy (Wh) / Voltage (V)

---

## 1. Calculation for Your 20S LFP Battery Pack

Since you are assembling a **20-Series (20S) Lithium Iron Phosphate (LFP)** battery pack, we can calculate exactly how many Ampere-hours equal "one kilowatt-hour" of energy for your specific setup:

*   **Nominal Cell Voltage:** 3.2 V
*   **Total Pack Voltage (20S):** 3.2 V * 20 = 64 V
*   **Conversion Calculation:**
    Capacity = 1000 Wh / 64 V = 15.63 Ah

**Conclusion:** For your custom 64V battery pack, **1 kWh (一度电) is equivalent to approximately 15.63 Ah**.

---

## 2. Reference Table Across Different Voltage Systems

Because voltage acts as the multiplier, 1 kWh of energy translates to vastly different Ah ratings depending on the device or vehicle platform:

| Device / Vehicle Type     | Nominal Voltage (V)  | Equivalent Ah for 1 kWh (一度电)        |
| :------------------------ | :------------------- | :-------------------------------------- |
| **Smartphone Power Bank** | 3.7 V (汇单一锂电池) | 1000 / 3.7 = 270.27 Ah (or 270,270 mAh) |
| **Car Starter Battery**   | 12 V (标准铅酸电池)  | 1000 / 12 = 83.33 Ah                    |
| **Electric Motorcycle**   | 72 V (高功率电摩)    | 1000 / 72 = 13.89 Ah                    |
| **Electric Vehicle (EV)** | 400 V (标准电车平台) | 1000 / 400 = 2.5 Ah                     |



## Summary for Your Project

To find out how many Ampere-hours you need for any targeted energy storage level, simply divide your target Watt-hours (Wh) by your operating voltage (64 V). 

Since you are configuring a 20S2P array, what is the rated Ah capacity of the individual 3.2V LFP cells you plan to use?




## battery test 

| voltage | cutoff voltage | min.VOLT | ad. capacity | time | current |
| ------- | -------------- | -------- | ------------ | ---- | ------- |
| 12V     | 9V             | 7.5V     | 20000 mAH    | 10h  | 2A      |
| 3.7V    | 3V             | 2.5V     |


### 2. Example for a Typical Li-ion 26650 (5000 mAh)
- Discharge Current: **0.5 A** (500 mA)
- Expected Capacity: **5000 mAh**
Time = 5000 mAh ÷ 500 mA = 10 hours


### 3. Practical Notes
- **Cutoff Voltage**:  
  - Li-ion NMC/NCA: ~2.5–3.0 V  
  - LiFePO₄: ~2.0–2.5 V  
- **Temperature**: Test at room temp (~25 °C) for rated results.
- **CC Test**: Your tester should log voltage & time; capacity is the area under the discharge curve.






## Car Sedan Lead-Acid battery 

- [[battery-Lead-acid-dat]]

- Typical Voltage (V): 12 V
- Typical Capacity Range (Ah): 40 Ah to 70 Ah

Calculating Energy (Wh) = Voltage (V) × Capacity (Ah)

- Minimum Energy: 12 V × 40 Ah = 480 Wh
- Maximum Energy: 12 V × 70 Ah = 840 Wh

So, the energy stored in a typical car lead-acid battery is usually between 480 Wh and 840 Wh.

## 20000 mAh * 3.7V 

Energy (Wh) = 20 Ah × 3.7 V = 74 Wh

## 2.6Ah * 12V

Energy (Wh) = 2.6 Ah × 12 V = 31.2 Wh

## 1000 Wh 

1000 watt-hours (Wh) == 1 度

Runtime = 1000 Wh / 5V * 1A = 1000 Wh / 5W = 200 hours

## quick calculation 

2000 mAh = 2 Ah 
Runtime ≈ (2 Ah * 3.7 V * 0.85) / (1 A * 5 V) ≈ 1.26 hours

for 20000 mAh, == 12.6 hours

## Calculating Runtime for a 2000mAh Power Bank Supplying a 1A @ 5V Device

Here's a breakdown of how to estimate the runtime:

### 1. Power Bank Energy

*   **Capacity:** 2000 mAh (milliampere-hours) = 2 Ah (ampere-hours)
*   **Nominal Voltage:** 3.7 V (typical for lithium-ion/polymer batteries)
*   **Total Energy (Watt-hours, Wh):** Capacity (Ah) × Voltage (V)
    *   `2 Ah * 3.7 V = 7.4 Wh`

### 2. Device Power Consumption

*   **Current:** 1 A (ampere)
*   **Voltage:** 5 V (standard USB output)
*   **Power Needed (Watts, W):** Current (A) × Voltage (V)
    *   `1 A * 5 V = 5 W`

### 3. Efficiency Consideration

Power banks are not 100% efficient when converting their internal battery voltage (3.7V) to the required 5V output. Energy is lost, primarily as heat, during this conversion.
*   **Estimated Efficiency:** Let's assume an average efficiency of **85%** (or 0.85). This can vary between 80% and 95% depending on the quality of the power bank circuitry.

### 4. Effective Energy Available

This is the amount of the power bank's stored energy that can actually be delivered to the device after accounting for conversion losses.
*   **Effective Energy:** Total Energy (Wh) × Efficiency
    *   `7.4 Wh * 0.85 ≈ 6.29 Wh`

### 5. Calculate Runtime

*   **Runtime (hours):** Effective Energy Available (Wh) / Device Power Consumption (W)
    *   `6.29 Wh / 5 W ≈ 1.26 hours`

### Conclusion

A 2000mAh, 3.7V power bank can theoretically supply a device drawing 1A at 5V for approximately **1.26 hours**, or about **1 hour and 15 minutes**.

**Disclaimer:** This is an estimate. Actual runtime depends on factors such as:
*   The precise efficiency of the specific power bank.
*   The age and health of the battery cells.
*   The quality of the charging cable (resistance losses).
*   Ambient temperature.
*   Whether the device's power draw is constant or fluctuates.
   

## ref 

- [[battery-Lead-acid-dat]]