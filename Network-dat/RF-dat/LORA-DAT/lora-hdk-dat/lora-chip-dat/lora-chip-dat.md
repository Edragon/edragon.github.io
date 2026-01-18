
# lora-chip-dat


- [[lora-chip-dat]] - [[lora-modules-dat]]

## Chip 

- [[semtech-dat]] - [[sx1262-dat]] - [[LLCC68-dat]] - [[SX1278-dat]] - [[SX1268-dat]]

- [[ASR6500-dat]] - [[ASR-dat]] - [[ASR6601-dat]]


- [[crystal-dat]]

- [[PAN3031-dat]]



## SX1268 vs SX1262 — Feature & Advantage Comparison

| Category              | SX1268                 | SX1262                 | Advantage             |
| --------------------- | ---------------------- | ---------------------- | --------------------- |
| Manufacturer          | Semtech                | Semtech                | —                     |
| LoRa Modulation       | Yes (LoRa only)        | Yes (LoRa only)        | Tie                   |
| FSK Modulation        | Yes                    | Yes                    | Tie                   |
| Frequency Support     | 410–810 MHz            | 150–960 MHz            | **SX1262** (wider)    |
| Coverage Bands        | 433 / 470 / 868        | 433 / 868 / 915        | **SX1262**            |
| Package               | QFN-24                 | QFN-24                 | Tie                   |
| Pin Compatibility     | Same family            | Same family            | Tie                   |
| BUSY Pin Required     | Yes                    | Yes                    | Tie                   |
| Reset Pin             | Yes                    | Yes                    | Tie                   |
| IRQ Pins              | DIO1–DIO3              | DIO1–DIO3              | Tie                   |
| SPI Interface         | Mode 0, BUSY handshake | Mode 0, BUSY handshake | Tie                   |
| Max TX Power          | +22 dBm (external PA)  | +22 dBm (external PA)  | Tie                   |
| RX Sensitivity        | ~ -148 dBm             | ~ -148 dBm             | Tie                   |
| Sleep Current         | < 200 nA               | < 200 nA               | Tie                   |
| RX Current            | ~4.6 mA                | ~4.6 mA                | Tie                   |
| TX Efficiency         | High                   | High                   | Tie                   |
| RF Switch Control     | Internal               | Internal               | Tie                   |
| TCXO Support          | Yes                    | Yes                    | Tie                   |
| Register/Command API  | Command-based          | Command-based          | Tie                   |
| LoRaWAN Support       | Yes                    | Yes                    | Tie                   |
| Operating Temperature | -40°C → +85°C          | -40°C → +85°C          | Tie                   |
| Development Ecosystem | Growing                | Mature                 | Slight SX1262         |
| Typical Use           | Sub-GHz LoRa IoT       | Broad LoRa IoT         | **SX1262** (flexible) |

---

### Key Differences

#### 🌐 Frequency Range
- **SX1262 covers more bands**:
  - *150–960 MHz*
  - Allows 433, 868, 915, and some 780 MHz
- **SX1268 covers**:
  - *410–810 MHz*
  - Good for 433 / 470 / 868 (region-dependent)

👉 **SX1262 wins for global flexibility**

---

#### 📡 Regional Flexibility and Certification
- **SX1262** is widely supported in:
  - EU (868 MHz)
  - US (915 MHz)
  - AS (433 MHz)
- **SX1268** is often tuned for:
  - China / Asia sub-GHz bands

👉 **SX1262 better for multi-region deployment**






## SX1278 vs SX1268 — Feature & Advantage Comparison

| Category               | SX1278                 | SX1268                          | Advantage              |
| ---------------------- | ---------------------- | ------------------------------- | ---------------------- |
| Manufacturer           | Semtech                | Semtech                         | —                      |
| LoRa Modulation        | LoRa, FSK, OOK         | LoRa, (G)FSK                    | Tie                    |
| Frequency Band         | 137–525 MHz            | 410–810 MHz                     | Depends on region      |
| Typical Use Band       | 433 MHz                | 433 / 470 / 868 MHz             | SX1268 wider           |
| Package                | QFN-28                 | QFN-24                          | SX1278 easier breakout |
| Pin Compatibility      | ❌ No                   | ❌ No                            | —                      |
| SPI Interface          | SPI Mode 0             | SPI Mode 0 + BUSY pin           | SX1278 simpler         |
| BUSY Pin Required      | ❌ No                   | ✅ Yes                           | SX1278 simpler         |
| Reset Handling         | Simple RESET           | RESET + BUSY handshake          | SX1278 simpler         |
| IRQ Pins               | DIO0–DIO5 (flexible)   | DIO1–DIO3 (fixed roles)         | SX1278 more flexible   |
| Max Output Power       | +20 dBm (PA_BOOST)     | +22 dBm (external PA)           | SX1268                 |
| RX Sensitivity         | ~-148 dBm              | ~-148 dBm                       | Tie                    |
| RX Current             | ~10–12 mA              | **~4.6 mA**                     | **SX1268**             |
| TX Efficiency          | Moderate               | **High efficiency PA**          | **SX1268**             |
| Sleep Current          | ~1 µA                  | **< 200 nA**                    | **SX1268**             |
| Wake-up Time           | Slow                   | **Very fast**                   | **SX1268**             |
| RF Switch Control      | External logic         | **Internal control pins**       | **SX1268**             |
| TCXO Support           | Limited                | **Native TCXO control**         | **SX1268**             |
| Packet Engine          | Older                  | **Improved**                    | **SX1268**             |
| Register Map           | Direct register access | Command-based API               | SX1278 simpler         |
| Driver Complexity      | Simple                 | More complex                    | SX1278 easier          |
| Arduino / Pi Libraries | Very mature            | Mature but newer                | SX1278                 |
| LoRaWAN Support        | Yes                    | Yes                             | Tie                    |
| Power Optimization     | Basic                  | **Advanced sleep & duty-cycle** | **SX1268**             |
| Production Status      | Legacy                 | **Current generation**          | **SX1268**             |

---

### Summary

### SX1278 — Strengths
- Simple hardware design
- No BUSY pin required
- Very mature libraries
- Easy for hobby & legacy projects

### SX1268 — Strengths
- **Much lower power consumption**
- Better TX efficiency
- Internal RF switch control
- Native TCXO support
- Modern architecture
- Better for battery-powered devices