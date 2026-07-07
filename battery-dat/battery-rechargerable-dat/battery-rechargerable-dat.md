


# rechargerable-battery-dat


- [[battery-li-dat]] - [[battery-LFP-dat]]

- [[battery-size-dat]] - [[18650-dat]]

- [[battery-protector-dat]] - [[battery-BMS-dat]] - [[battery-charger-dat]]


## charge time 

| **Battery Type**                 | **Typical Charge Time** | **Notes**                                               |
| -------------------------------- | ----------------------- | ------------------------------------------------------- |
| **Lead-acid**                    | 8-12 hours              | Slow charge time, can be faster with a fast charger.    |
| **LFP (Lithium Iron Phosphate)** | 2-4 hours               | Similar to lithium-ion but may take slightly longer.    |
| **Lithium-ion (Li-ion)**         | 1-3 hours               | Fastest charging, especially with modern fast chargers. |



## Common Rechargeable Battery Internal Resistance and Aging

| Battery Type                | Nominal Voltage | Capacity Range | Internal Resistance (New) | Internal Resistance After ~200 Cycles | Notes / Applications                            |
| --------------------------- | --------------- | -------------- | ------------------------- | ------------------------------------- | ----------------------------------------------- |
| **AA NiMH**                 | 1.2V            | 1800–2500 mAh  | 20–50 mΩ                  | 30–80 mΩ                              | Consumer electronics, toys                      |
| **AAA NiMH**                | 1.2V            | 600–1200 mAh   | 30–70 mΩ                  | 40–100 mΩ                             | Small electronics, remote controls              |
| **18650 Li-ion**            | 3.6–3.7V        | 2000–3500 mAh  | 30–80 mΩ                  | 40–120 mΩ                             | Laptops, power banks, flashlights               |
| **High-drain 18650 Li-ion** | 3.6–3.7V        | 1500–3000 mAh  | 15–30 mΩ                  | 25–50 mΩ                              | Power tools, e-cigarettes, high-current devices |
| **26650 Li-ion**            | 3.6–3.7V        | 4000–6000 mAh  | 10–40 mΩ                  | 20–60 mΩ                              | High-capacity flashlights, e-bikes              |
| **12V Lead-Acid (SLA/AGM)** | 12V             | 7–20 Ah        | 0.12–0.3 Ω                | 0.15–0.4 Ω                            | Scooters, UPS, emergency lighting               |
| **12V LiFePO4**             | 12.8V           | 10–20 Ah       | 5–20 mΩ                   | 10–30 mΩ                              | E-bikes, solar storage, UPS                     |
| **9V NiMH**                 | 8.4–9V          | 150–300 mAh    | 150–300 mΩ                | 200–400 mΩ                            | Smoke detectors, small electronics              |
| **NiCd AA**                 | 1.2V            | 600–1000 mAh   | 30–100 mΩ                 | 50–150 mΩ                             | Older toys, cordless phones                     |
| **LiPo (3.7V per cell)**    | 3.7V            | 500–5000 mAh   | 20–100 mΩ                 | 40–150 mΩ                             | Drones, RC cars, FPV drones                     |

### Notes on Internal Resistance Change:
- Internal resistance **increases gradually** with usage cycles and charging/discharging.  
- The amount of increase depends on:
  - Battery chemistry and quality
  - Depth of discharge and charging rate
  - Temperature and storage conditions  
- Higher resistance results in **lower peak current capability** and slightly reduced capacity over time.



## Types 

- [[battery-Lead-acid-dat]] - [[li-battery-dat]]

- [[LFP-dat]] 
  
- [[battery-NCM-NCA-dat/NCA-dat/NCA-dat]] - [[battery-NCM-NCA-dat/NCM-dat/NCM-dat]] - [[Battery-li-Ternary-dat]]



## Sodium-ion Battery

A common question is: "Since we already have Lithium Iron Phosphate (LFP) and Ternary Lithium batteries, why develop Sodium-ion batteries?"

### Advantages (Key Strengths)
- **Extremely Low Cost & Resource Independence**: Lithium resources are scarce with volatile prices, while sodium resources (from table salt) are abundant on Earth. Once scaled up, costs can be approximately 30% lower than LFP.
- **Superior Low-Temperature Performance**: Lithium batteries often struggle in outdoor temperatures of -20°C (rapid power drop, slow charging). Sodium-ion batteries can still maintain over 80% discharge capacity at -20°C, and charging speeds remain largely unaffected, making them ideal for cold climates.
- **Higher Safety**: Lower internal resistance and higher thermal runaway temperature make them less prone to fire or explosion.

### Disadvantages
- **Lower Energy Density**: The energy density of CATL's 1st/2nd generation sodium-ion batteries is around 160 Wh/kg. While this matches some low-end LFP batteries, it is still far behind ternary lithium batteries. Consequently, they are not suitable for high-end EVs requiring long range (e.g., over 700km).

## ref 

- [[battery-dat]]