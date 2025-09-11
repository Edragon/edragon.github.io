
# battery-capacity-dat


- [[18650-dat]] - [[26650-dat]] 





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

- [[lead-acid-battery-dat]]

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

- [[Lead-acid-battery-dat]]