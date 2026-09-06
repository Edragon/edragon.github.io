
# ELRS-frequency-dat.md

| Feature             | ELRS 915MHz (LoRa)          | ELRS 2.4GHz (LoRa/FLRC)      |
|---------------------|-----------------------------|------------------------------|
| Frequency Band      | 915 MHz                     | 2.4 GHz                      |
| Range (LOS, 100mW)  | ✅ 5–10+ km                  | ⚠️ 1–2 km                    |
| Penetration         | ✅ Strong (trees, buildings) | ⚠️ Moderate                  |
| Latency             | ❌ ~20–30 ms                 | ✅ ~2.5–13 ms                |
| Max Packet Rate     | ❌ ~50Hz                     | ✅ Up to 500Hz              |
| Antenna Size        | ❌ Large                     | ✅ Small                     |
| Interference Avoidance | ✅ Less crowded band      | ⚠️ More Wi-Fi/Bluetooth noise |
| Use Case            | Long-range, endurance        | Freestyle, racing            |
| Power Efficiency    | ✅ High (lower data rate)    | ✅ High (LoRa + FLRC modes)  |
| Hardware Support    | Older SX1276 modules         | Newer SX1280 + ESP modules   |


## ref 

- [[ELRS-dat]]