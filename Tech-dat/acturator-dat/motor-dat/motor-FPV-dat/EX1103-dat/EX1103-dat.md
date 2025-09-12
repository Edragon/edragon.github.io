
# EX1103-dat

- Mode: EX1103
- KV options: 6000KV 7000KV 8000KV 12000KV
- Configu-ration:9N12P
- Stator Diamter:11mm
- Stator Length:3mm
- Shaft Diameter: Φ1.5mm
- Motor Dimension(Dia.*Len):Φ13.5mm*16mm
- Weight(g):3.7g
- No. of Cells(Lipo):
- 6000KV support 3-4S
- 7000KV support 2-3S original motors for Larva X
- 8000KV support 2-3S
- 12000KV support 1-2S


- EX1103-12000	
- 0.44A 
- 24750RPM	
- 65mm bi-blades

- [[Thrust-dat]]

| Voltage (V) | Throttle (%) | Thrust (g) | Power (W) | Efficiency (g/W) | RPM  |
|-------------|--------------|------------|-----------|------------------|------|
| 7.4         | 1            | 22.5       | 7.4       | 3.041            | 1298 |
| 7.4         | 2            | 40         | 14.8      | 2.703            | 1425 |
| 7.4         | 3            | 58.4       | 22.2      | 2.631            | 1554 |
| 7.4         | 4            | 72.3       | 29.6      | 2.443            | 1649 |
| 7.4         | 5            | 87.6       | 37        | 2.368            | 1750 |
| 7.4         | 6            | 98.6       | 44.4      | 2.221            | 1830 |
| 7.4         | 7            | 109.3      | 51.8      | 2.110            | 1918 |
| 7.4         | 8            | 119.9      | 59.2      | 2.025            | 1988 |
| 7.4         | 8.3          | 121.2      | 61.42     | 1.973            | 2200 |



## Can EX1103 run with 96 kHz ESC PWM?


Short answer: Yes — the EX1103 motor itself can run while the ESC is switching at 96 kHz, but whether you should run 96 kHz depends entirely on your ESC hardware and firmware and the resulting ESC switching losses / heating. Below are the practical reasons, recommendations, and a safe test procedure.


### 1) Motor side
- Small brushless motors (1103 size) are electrically simple and **will run** with high PWM switching rates.
- Higher PWM gives smoother torque and quieter operation at low RPMs.

### 2) ESC side (the limiting factor)
- **ESC hardware + firmware** must support 96 kHz (BLHeli_32 or BLHeli_S with Bluejay can provide higher frequencies).
- Higher PWM = much higher switching frequency for the MOSFETs → **more switching losses** → ESC gets hotter and may fail if it’s not designed for it.
- On tiny whoop ESCs (very small boards), 96 kHz often causes significantly higher ESC temps; some tiny ESCs only safely handle up to 48 kHz.

### 3) Practical verdict
- **Motor: OK.**
- **ESC: maybe** — only if ESC hardware & firmware explicitly support 96 kHz and you verify temperatures are safe.
- **Recommended default:** try **48 kHz** first (good balance). Move to 96 kHz only if ESC is known to handle it and bench tests pass.

### Safe test procedure to verify 96 kHz on your stack

1. **Check ESC firmware & hardware**
   - If you have BLHeliSuite32, check available PWM options.
   - If BLHeli_S, consider Bluejay to unlock higher frequencies (only if your ESC is compatible).

2. **Set conservative limits**
   - Limit max throttle to ~80% for the first tests (use throttle cut or governor).
   - Reduce flight-time/hover duration for initial tests.

3. **Bench test (props off or props on with restraint)**
   - Arm and run at varying throttle pulses (hover-ish and full throttle bursts).
   - Monitor ESC temperature and motor temperature after 30–60 seconds bursts.

4. **Acceptable temperature thresholds (practical guidance)**
   - **ESC temp:** keep **below ~80°C** ideally; if it climbs toward 90–100°C, it's unsafe.
   - **Motor temp:** keep **below ~70°C** for small motors; <60°C is better.
   - If temps rise quickly, stop and drop PWM to 48 kHz or 24 kHz.

5. **Flight test**
   - Short, conservative indoor flights; watch for ESC heating, desyncs, reduced thrust, or smoke.
   - If you see any sign of ESC stress (thermal cut, brownouts, smoke), revert immediately.

6. **Telemetry / logs**
   - Use any ESC telemetry (current, voltage, temp) to evaluate switching losses.
   - Check motor RPM and efficiency—if thrust drops or current skyrockets, higher PWM may be harmful.

### Additional notes
- High-KV motors (e.g., 12,000KV) spin very fast on 1–2S — higher PWM helps smooth low-speed control but brings less benefit at very high RPMs while still stressing ESCs.
- For cine / smooth indoor whoop flying, many pilots prefer **48 kHz** (smooth + safer). Use 96 kHz only if your ESC is proven to handle it on your exact build.

### Short recommendation
- **Try 48 kHz first.** If you want to experiment with **96 kHz**, ensure your ESC firmware/hardware supports it and do careful bench/temperature tests. If the ESC runs cool and performance improves, you’re good; if it heats up, drop back down.


## ref 

- [[motor-FPV-dat]]