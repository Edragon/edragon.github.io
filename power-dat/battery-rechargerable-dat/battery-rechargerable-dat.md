


# rechargerable-battery-dat

- [[battery-protection-dat]] - [[BMS-dat]]




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

- [[Lead-Acid-Battery-dat]] - [[li-battery-dat]]

- [[LFP-dat]] 
  
- [[NCA-dat]] - [[NCM-dat]] - [[Ternary-Lithium-Battery-dat]]


## ref 

- [[battery-dat]]