
# frequency-dat

- [[PPL-dat]] - [[PLL-dat]]

China has several ISM (Industrial, Scientific, and Medical) bands available for low-power, short-range devices. The primary bands are:

- 470-510 MHz: This is the main band designated for LoRaWAN and other LPWAN technologies in China.
- 779-787 MHz: Another band available for short-range devices.
- 920-925 MHz: This band is also used, though it's narrower than in other regions.
- 433.05-434.79 MHz: The standard 433 MHz ISM band.
- 2.4 GHz: The global 2.4 GHz band is available.
- 5.8 GHz: The global 5.8 GHz band is also available.

For LoRaWAN applications, the 470-510 MHz band is the most significant and widely deployed in China.



## 🔐 1. Anti-Theft Tags (EAS – Electronic Article Surveillance)

These are common in retail stores to prevent theft. They are **not** RFID but use simpler tech.

- **Frequency:** **8.2 MHz** (RF system, most common)
- **Other types:**
  - **58 kHz** (AM system – Acousto-Magnetic)
  - **Radio Frequency (RF):** 8.2 MHz
  - **Microwave:** 2.45 GHz (rare)

---

## 📡 2. RFID Tags in Clothing

Used for inventory, supply chain, smart fitting rooms, etc.

### 🔸 a. **UHF (Ultra High Frequency) RFID**
- **Frequency:** **860–960 MHz**
- **Most common** in retail for clothing
- **Read range:** Up to 10 meters
- **Standard:** EPC Gen 2 / ISO 18000-6C

### 🔸 b. **HF (High Frequency) RFID**
- **Frequency:** **13.56 MHz**
- **Used in smart labels, near-field communication (NFC)**
- **Read range:** ~10 cm
- **Standard:** ISO 14443 or ISO 15693

---

## ✅ Summary Table

| Tag Type           | Frequency     | Use                          |
|--------------------|---------------|-------------------------------|
| EAS RF             | 8.2 MHz       | Anti-theft (retail)          |
| EAS AM             | 58 kHz        | Anti-theft (retail)          |
| RFID HF            | 13.56 MHz     | Inventory, NFC, smart tags   |
| RFID UHF           | 860–960 MHz   | Inventory, long-range scans  |
| Microwave RFID     | 2.45 GHz      | Rare, high-speed systems     |

---

## 👕 In Clothing Retail Today

Most clothing stores use:
- **EAS RF (8.2 MHz)** for anti-theft
- **UHF RFID (860–960 MHz)** for inventory tracking



## Synthesizer

ADF4377BCCZ - Microwave Wideband Synthesizer with Integrated VCO




## frequency operator 

HMC189AMS8E - Signal Conditioning Passive SMT Freq. Doubler, 2 - 4 GHz

HMC443LP4 / 443LP4E - The HMC443LP4 & HMC443LP4E are active miniature x4 frequency multipliers utilizing InGaP GaAs HBT technology in 4x4 mm leadless surface mount packages.

## PLL Frequency Synthesizer

AD4106 


## frequency multipiler 

HMC443LP4 / 443LP4E - SMT GaAs HBT MMIC x4 ACTIVE FREQUENCY MULTIPLIER, 9.8 - 11.2 GHz OUTPUT 




## ref 

- [[RF-dat]]