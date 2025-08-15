# battery-tester-dat


## Q: Can I determine a lead‑acid battery's capacity by measuring its voltage with a multimeter for a fixed short time (e.g., 5 minutes)?

A: No. A 5‑minute voltage reading cannot reliably determine battery capacity.

Why:
- **Battery voltage is not a direct, linear indicator of remaining capacity**; voltage changes little across much of the discharge curve.

- Capacity is defined by total charge delivered: Capacity (Ah) = Current (A) × Time (h). You must discharge with a known constant current to a cutoff voltage to measure capacity.

- A multimeter alone cannot integrate current over time (coulomb counting).

- Short tests can only give rough hints; extrapolating capacity from a 5‑minute test (even at high current) yields large errors.

Quick practical checks for battery health:

- Resting (open‑circuit) voltage: charge fully, wait ~12 hours, then measure. ≳12.6 V indicates generally healthy for a 12 V lead‑acid battery.
- Internal resistance test: fast and useful indicator of capacity degradation.
- Short high‑current load test (starter test): observe voltage sag under load.

### To measure capacity accurately:

- Use a constant‑current electronic load or a dedicated battery capacity tester and discharge to a defined cutoff (e.g., 10.5 V for 12 V batteries); record current × time.
- Or use a device that logs current over time (coulomb counter) while discharging.

### Q: How does a lead‑acid battery's internal resistance typically change after ~200 charge/discharge cycles?

A: Internal resistance generally increases after repeated cycling, but the magnitude depends on usage conditions.

Why:

- Repeated charge/discharge causes sulfation (lead sulfate crystallization 硫化), active‑material shedding, separator aging, and electrolyte stratification — all of which reduce ionic/electronic pathways and raise internal resistance.

Typical trend (example: small 12 V sealed lead‑acid):
- Factory/new: ~7–9 mΩ (milliohms)
- After ~200 cycles at deep discharge (≈80% DOD): can rise to ~12–18 mΩ

Notes on variation:

- Shallow cycling (≈30% DOD) and moderate temperature: resistance may only increase modestly (e.g., 20–30%).
- Deep cycling combined with high temperature: resistance can increase much more, potentially doubling.

Practical scenarios (examples):

1) Vehicle or high‑current starter load

- New battery (low internal resistance): turning the key holds voltage ≳11 V and the engine cranks easily.
- Aged battery (internal resistance increased): voltage may collapse to ~9 V or lower on crank, motor may fail to turn.
- Symptoms: weak cranking sounds, slow or no crank.

2) Supplying an inverter / UPS under heavy load

- New battery: inverter sustains heavy load and can deliver ≳80% of nominal capacity.
- High‑resistance battery: voltage drops quickly under load, inverter alarms or shuts down early.
- Symptoms: frequent alarms, early shutdown while capacity still remains in the battery.

3) Electric scooter / light EV acceleration

- New battery: small voltage dip on acceleration, smooth power delivery.
- High‑resistance battery: large voltage drop on throttle, controller may trigger low‑voltage protection and cut power intermittently.
- Symptoms: sudden power loss under acceleration, power returns when throttle is released.

4) Charging behavior

- New battery: accepts high charge current initially, charges efficiently.
- High‑resistance battery: charge current is limited, charger may switch to float early and report a finished charge even though usable capacity is low.
- Symptoms: charging appears to finish quickly but the battery discharges rapidly in use.


## Testing methods

Detecting capacity and health of used lead‑acid batteries can be divided into quick checks and accurate tests. Below is a complete procedure you can choose from depending on available tools.

1) Quick checks (minutes)

- Resting (open‑circuit) voltage — rough check:
  - Charge fully, then rest for ~12 hours before measuring.
  - ≳12.6 V: generally healthy
  - 12.4–12.5 V: moderate degradation
  - ≤12.3 V: likely aged or discharged
  - Note: This only indicates state of charge/obvious aging, not true capacity.

- Internal resistance test (recommended):
  - Use a battery internal‑resistance meter (inexpensive handheld units to mid‑range testers).
  - Example guidance:
    - Small 12 V, 7 Ah battery: <20 mΩ healthy; 30–40 mΩ fair; >50 mΩ scrap.
    - Automotive starting batteries: internal resistance is on the order of tens of milliohms; a noticeable increase vs. new indicates degraded performance.

- Instant voltage‑drop (load) test — simple practical check:
  - Connect a known heavy load (e.g., high‑beam headlight or ~100 W resistor) and observe the instantaneous voltage drop.
  - New battery: drop typically ≤0.4–0.5 V
  - Aged battery: instantaneous drop may exceed 1.0 V

2) Accurate testing (hours)

- Constant‑current discharge capacity test (gold standard):
  - Fully charge the battery (use appropriate charger, e.g., 14.4 V CV for 12 V lead‑acid until absorption/current falls).
  - Rest the battery with charger disconnected for ≥2 hours.
  - Discharge at a constant current (recommended 0.05C–0.1C; e.g., for 100 Ah battery use 5–10 A) down to the cutoff voltage (commonly 10.5 V for 12 V batteries).
  - Calculate capacity: Capacity (Ah) = Discharge current (A) × Discharge time (h).
  - Example: 5 A discharge to 10.5 V took 15 h → capacity = 5 × 15 = 75 Ah. If measured capacity < 80% of rated, the battery is significantly aged.

3) Good / bad reference (example thresholds)

| Status   | Resting voltage (12 V battery) | Internal resistance (automotive, mΩ) | Measured capacity | Conclusion |
|----------|-------------------------------:|-------------------------------------:|------------------:|-----------|
| Excellent| ≥ 12.6 V                        | ≤ 8 mΩ                               | ≥ 90%             | Healthy   |
| Moderate | 12.4–12.5 V                     | 9–15 mΩ                              | 70–90%            | Usable    |
| Poor     | ≤ 12.3 V                        | 15–25 mΩ                             | 50–70%            | Marginal  |
| Scrap    | ≤ 12.0 V                        | ≥ 25 mΩ                              | < 50%             | Replace   |



## testing tools 

- capacity - [[electronic-loader-dat]]
- internal resistance == discharge current - [[internal-resistance-meter-dat]]



## ref 

- [[battery-dat]] - [[power-dat]]