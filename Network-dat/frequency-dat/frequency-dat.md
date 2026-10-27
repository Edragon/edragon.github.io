
# frequency-dat


- [[PPL-dat]] - [[frequency-dat]] - [[Digital-Synthesizer-dat]] - [[CLOCK-SYNTHESIZER-dat]] - [[clock-dat]]


- [[VSWR-dat]] - [[bands-dat]] - [[frequency-dat]]


- [[27mhz-dat]] - [[frequency-dat]] - [[frequency-rc-dat]] - [[RF-dat]] - [[RF-2.4Ghz-dat]] - [[RF-1Ghz-dat]]

- [[antenna-dat]] - [[antenna-linear-dat]]

- [[PPL-dat]] - [[PLL-dat]]

- [[oscillator-dat]] - [[Oscilloscope-dat]]



- [[frequency-dat]]





## common frequency 

VHF == Very High Frequency - [[VHF-dat]] - [[UHF-dat]] 


V段与 U段的直观对比

| 频段名称         | 英文缩写 | 频率范围         | 波长范围    | 典型业余频段             | 特点小结                                      |
| ---------------- | -------- | ---------------- | ----------- | ------------------------ | --------------------------------------------- |
| **V段** (甚高频) | VHF      | 30 MHz – 300 MHz | 1米 – 10米  | 144–148 MHz (2米波段)    | 绕射稍好，适合空旷地带或城市远距离通联        |
| **U段** (特高频) | UHF      | 300 MHz – 3 GHz  | 1分米 – 1米 | 430–440 MHz (70厘米波段) | 天线尺寸小，穿透/多径好，广泛用于现代无线设备 |





- [[27mhz-dat]]

- [[50mhz-dat]] - [[antenna-yagi-dat]]

- [[315mhz-dat]] - [[RF-dat]]
- [[433mhz-dat]] - 470 / 490 mhz - [[lora-dat]] - [[frequency-dat]] - [[RF-dat]]
- [[900mhz-dat]] - 800 / 1800 mhz == [[4G-dat]] - [[3G-dat]] - [[LTE-dat]] - [[GPRS-dat]] - [[NBIOT-dat]] - [[GSM-dat]] - [[frequency-dat]] - [[CDMA-dat]] - [[RFID-dat]]
- 2200 - [[LTE-dat]]
- 2400 - [[wifi-dat]] - [[bluetooth-dat]] - [[RF-dat]] - [[zigbee-dat]] - [[2.4ghz-dat]]
- [[GPS-dat]] - [[GNSS-dat]] - [[location-dat]]


- [[5.8Ghz-dat]] - [[frequency-dat]] - [[VTX-dat]] - [[frequency-dat]] - [[VRX-analog-dat]]

- [[VRX-analog-dat]]

- [[1.2Ghz-dat]]
- [[3.3Ghz-dat]]
- [[5.8Ghz-dat]]
- [[7.2ghz-dat]]


## common analog bands 


### 0. TL;DR

```
1. "Lower frequency goes farther" is only true at EQUAL ANTENNA GAIN.
2. At EQUAL ANTENNA SIZE, the four bands are essentially TIED — antenna gain
   cancels the free-space path loss difference almost exactly (1.3 G and 7.2 G
   both land within ~0 dB of 5.8 G).
3. Beyond each band's two-ray breakpoint the bands CONVERGE: at 30 km the
   1.3 G vs 5.8 G gap shrinks from 13.0 dB to 3.3 dB, and 3.3 G fully ties 1.3 G.
4. The real differentiators are: diffraction/vegetation penetration (low freq wins),
   interference environment (7.2 G cleanest), antenna real estate (high freq wins),
   component ecosystem (5.8 G by a mile), and REGULATION (3.3 G is a hard no).
```

---

### 1. Assumptions

| Parameter                      | Value                                                          | Note                  |
| :----------------------------- | :------------------------------------------------------------- | :-------------------- |
| Airborne height `h_t`          | 120 m                                                          | typical legal ceiling |
| Ground antenna height `h_r`    | 1.5 m                                                          | hand-held / tripod    |
| Antenna gain (equal-gain case) | 2 dBi both ends                                                | λ/2 dipole class      |
| Receiver sensitivity           | −92 dBm                                                        | typical analog VRX    |
| Fade margin                    | 10 dB                                                          | design margin         |
| Feed/cable loss                | 2 dB                                                           | short pigtails        |
| Model                          | Free space inside the two-ray breakpoint, **40·log(d)** beyond | see §2                |

**Formulas used**

```
FSPL(dB)   = 20·log10(d_m) + 20·log10(f_Hz) − 147.55
λ(m)       = 0.3 / f_GHz
d_bp(m)    = 4π · h_t · h_r / λ          (two-ray breakpoint)
F1(m)      = 17.32 · sqrt(d1·d2 / (f_GHz · D))    (first Fresnel radius, d in km)
G_aperture = 10·log10(4π·A·η / λ²)        (aperture antenna gain, η = 0.6)
```

> ⚠️ **Sensitivity is not constant across bands in practice.** Real analog VRX
> sensitivity degrades with frequency (−92 dBm is optimistic for 7.2 GHz).
> This analysis uses a flat −92 dBm to isolate the propagation physics.

---

### 2. Physical Baseline

| Band        | λ        | λ/2 dipole   | FSPL @1 km | Δ vs 1.3 G   | **Two-ray breakpoint** | **Fresnel F1 @2 km** |
| :---------- | :------- | :----------- | :--------- | :----------- | :--------------------- | :------------------- |
| **1.3 GHz** | 230.8 mm | **115.4 mm** | 94.7 dB    | baseline     | **9.80 km**            | 10.7 m               |
| **3.3 GHz** | 90.9 mm  | 45.5 mm      | 102.8 dB   | +8.1 dB      | **24.9 km**            | 6.7 m                |
| **5.8 GHz** | 51.7 mm  | 25.9 mm      | 107.7 dB   | +13.0 dB     | **43.7 km**            | 5.1 m                |
| **7.2 GHz** | 41.7 mm  | 20.8 mm      | 109.6 dB   | **+14.9 dB** | **54.3 km**            | 4.6 m                |

**⭐ Two counter-intuitive facts already visible here:**

1. **Higher frequency has a LONGER two-ray breakpoint.** The breakpoint scales as
   `1/λ ∝ f`. So at 120 m altitude, 1.3 GHz drops into the steep 40·log regime at
   only 9.8 km, while 7.2 GHz stays in the gentle 20·log regime out to 54 km.
   This structurally erodes the low-band advantage at long range.
2. **Higher frequency needs LESS Fresnel clearance.** A smaller first Fresnel zone
   means the link is easier to keep clear over terrain and trees.

---

### 3. Path Loss vs Distance (includes two-ray breakpoint)

| Band        | 1 km  | 5 km  | 10 km | 20 km | 30 km     |
| :---------- | :---- | :---- | :---- | :---- | :-------- |
| **1.3 GHz** | 94.7  | 108.7 | 114.9 | 126.9 | **134.0** |
| **3.3 GHz** | 102.8 | 116.8 | 122.8 | 128.8 | **134.0** |
| **5.8 GHz** | 107.7 | 121.7 | 127.7 | 133.7 | **137.3** |
| **7.2 GHz** | 109.6 | 123.6 | 129.6 | 135.6 | **139.1** |

**Δ relative to 1.3 GHz (dB)**

| Band        | 1 km  | 5 km  | 10 km | 20 km    | 30 km    |
| :---------- | :---- | :---- | :---- | :------- | :------- |
| **3.3 GHz** | +8.1  | +8.1  | +7.9  | **+1.9** | **+0.0** |
| **5.8 GHz** | +13.0 | +13.0 | +12.8 | **+6.8** | **+3.3** |
| **7.2 GHz** | +14.9 | +14.9 | +14.7 | **+8.7** | **+5.2** |

> ⭐ **Read the bottom rows.** The 13–15 dB low-band advantage at 1 km collapses
> to 0–5 dB by 30 km. **Past every breakpoint all bands converge**, because the
> 40·log(d) coefficient is geometry-only and identical for all frequencies.
> Frequency selection therefore matters most in the **near-to-mid range** and for
> **obstruction tolerance** — not for raw long-range reach.

---

### 4. Maximum Range at Equal Gain (both ends 2 dBi)

| Band        | 400 mW     | 1 W        | 10 W        |
| :---------- | :--------- | :--------- | :---------- |
| **1.3 GHz** | **5.8 km** | **9.2 km** | **16.9 km** |
| **3.3 GHz** | 2.3 km     | 3.6 km     | 11.5 km     |
| **5.8 GHz** | 1.3 km     | 2.1 km     | 6.5 km      |
| **7.2 GHz** | 1.0 km     | 1.7 km     | 5.3 km      |

At equal gain the low band leads by ~4.5×. **That is the misleading number — see §5.**

---

### 5. ⭐⭐ The Two-Assumption Trap

The same four bands, now with **equal antenna physical size** (100 × 100 mm patch, η = 0.6):

| Band        | Gain from 100 mm patch | Δ vs 5.8 G | **Net link delta (FSPL + gain)** |
| :---------- | :--------------------- | :--------- | :------------------------------- |
| **1.3 GHz** | 1.5 dBi                | −13.0 dB   | ⭐ **≈ 0 dB (tied)**              |
| **3.3 GHz** | 9.6 dBi                | −4.9 dB    | **−3.2 dB (slightly worse)**     |
| **5.8 GHz** | 14.5 dBi               | baseline   | baseline                         |
| **7.2 GHz** | 16.4 dBi               | +1.9 dB    | ⭐ **≈ 0 dB (tied)**              |

**Aperture needed to match 5.8 GHz at 100 mm:**

| Band        | Required aperture |
| :---------- | :---------------- |
| **1.3 GHz** | **446 mm** square |
| **3.3 GHz** | 176 mm square     |
| **5.8 GHz** | 100 mm square     |
| **7.2 GHz** | **81 mm** square  |

```
⭐ Antenna gain cancels the FSPL difference almost exactly.
   "Low frequency goes farther" holds ONLY at equal gain.
        ↓
Real world sits between the two assumptions:
   · Airborne: antenna size is hard-limited by the airframe
              → high frequency buys more gain in the same volume   ⭐ HF wins
   · Ground:  size is unconstrained
              → low frequency can use a huge Yagi/patch           ⭐ LF wins
        ↓
⭐ This is exactly why fixed-wing long-range flies 1.3 GHz
   (with a 15 dBi Yagi on the ground), while racing quads fly 5.8 GHz
   (airborne antenna is only 26 mm).
```

---

### 6. Engineering Dimension Comparison

| Dimension                                | 1.3 GHz                            | 3.3 GHz          | 5.8 GHz                   | 7.2 GHz                      |
| :--------------------------------------- | :--------------------------------- | :--------------- | :------------------------ | :--------------------------- |
| FSPL (equal gain)                        | ⭐ best                             | medium           | poor                      | worst                        |
| Two-ray breakpoint                       | poor — 9.8 km                      | medium — 24.9 km | good — 43.7 km            | ⭐ best — 54.3 km             |
| **Diffraction / vegetation penetration** | ⭐ best                             | medium           | poor                      | worst                        |
| Fresnel clearance needed                 | large ≳6.4 m                       | 4.0 m            | 3.1 m                     | ⭐ smallest 2.7 m             |
| Airborne antenna feasibility             | ❌ 115 mm too big                   | medium           | ⭐ good                    | ⭐ best                       |
| **Interference environment**             | poor in cities (land mobile, DATV) | ❌ 5G band        | worst (every quad + WiFi) | ⭐ **cleanest**               |
| Component ecosystem / modules            | few (legacy 1.2/1.3 G)             | ❌ very few       | ⭐⭐ **richest by far**     | few (mostly high-power)      |
| Practical power ceiling                  | 1.5–5 W                            | rare             | 25 mW–2 W common          | ⭐ 10 W class modules exist   |
| Suitable use                             | fixed-wing long range, obstruction | —                | everything small/racing   | contested RF, clean spectrum |

---

### 7. ⚠️ Regulatory Red Lines

> Advisory only — verify against the rules of the country you fly in. The numbers above say nothing about whether you are allowed to transmit them.

| Band        | Status (CN)                                                            | Practical consequence                                                                                                                                      |
| :---------- | :--------------------------------------------------------------------- | :--------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **3.3 GHz** | ❌❌ **3300–3400 MHz is assigned to 5G / private networks**              | Not merely unlicensed — it **interferes with carrier infrastructure**. Operators direction-find and report these. **Hard veto regardless of link budget.** |
| **1.3 GHz** | ⚠️ amateur service (secondary)                                          | Requires an amateur radio licence. 1.2 G FPV is widely sold in CN but remains legally grey.                                                                |
| **5.8 GHz** | ✅ 5725–5850 MHz, licence-exempt low-power                              | FPV VTX power (hundreds of mW to 2 W) far exceeds the low-power limits → grey in practice.                                                                 |
| **7.2 GHz** | ⚠️ not on the licence-exempt list; overlaps fixed/satellite allocations | Highest regulatory risk of the four.                                                                                                                       |

**Universal safety rules** (apply to every band):

- **Never power a VTX without an antenna attached** — reflected power destroys the PA in tens of seconds.
- Match polarization (air VTX RHCP ⇒ ground RHCP). A linear antenna costs ~3 dB immediately.
- Match connector type: SMA ≠ RP-SMA.
- Keep the VTX away from GPS/receiver antennas — harmonics land in GNSS bands.

---

### 8. Selection Guide

| Scenario                           | Band                       | Why                                                                                    |
| :--------------------------------- | :------------------------- | :------------------------------------------------------------------------------------- |
| Small quads / whoops / racing      | **5.8 GHz**                | only realistic option: 26 mm antenna, largest ecosystem, cheap spares, plentiful VRX   |
| Fixed-wing long range              | **1.3 GHz** + 5.8 G backup | best diffraction; ground station can carry a 15 dBi Yagi worth +13 dB                  |
| Contested RF (events, many pilots) | **7.2 GHz**                | cleanest spectrum, highest gain per antenna size — accept the worst regulatory profile |
| **3.3 GHz**                        | ❌ **nobody**               | worst of both worlds on FSPL and antenna size, and it sits on 5G                       |





## ISM bands 

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

| Tag Type       | Frequency   | Use                         |
| -------------- | ----------- | --------------------------- |
| EAS RF         | 8.2 MHz     | Anti-theft (retail)         |
| EAS AM         | 58 kHz      | Anti-theft (retail)         |
| RFID HF        | 13.56 MHz   | Inventory, NFC, smart tags  |
| RFID UHF       | 860–960 MHz | Inventory, long-range scans |
| Microwave RFID | 2.45 GHz    | Rare, high-speed systems    |

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