


# true-diversity-dat

- [[true-diversity-dat]] - [[antenna-diversity-dat]] - [[video-analog-dat]] - [[VRX-analog-dat]]



## C5VRX == ESP32-C5 

- [[ESP32-C5-dat]] - [[5.8Ghz-dat]] - [[ESP32-dat]] - [[WIFI6-dat]]

```
ESP32-C5 has a built-in Wi-Fi 6 radio (5.8 GHz)
   → MODEM_DIAG mode captures raw IQ samples
   → the BitScrambler peripheral performs the WBFM demodulation
   → a 6-bit passive resistor DAC converts it to CVBS
   → output to goggles / monitor
```

> ⭐ No RX5808, no SDR, and no external RF components of any kind

### 2. ⭐️ Hardware BOM (key parameters)

| Item | Spec |
|---|---|
| MCU | Seeed XIAO ESP32-C5 (the only chip) |
| DAC | 6-bit passive resistor DAC (6 resistors, not a chip) |
| Pins | D4..D9 = GPIO 23, 24, 11, 12, 8, 9 (LSB first) |
| Resistors | 8.2k / 3.9k / 2k / 1k / 470R / 240R + 200 Ω load |
| Power | USB-C or the 5 V pin; the DAC needs no separate supply |
| Reserved (must stay DNP = not fitted) | D10/GPIO10 = 15 kΩ, D3/GPIO7 = 33 kΩ (for a future 7/8-bit DAC) |

> ⭐️ Cost per unit: XIAO ¥35-60 + resistors ¥2-5 + socket ¥5-15 ≈ ¥45-80

### 4. Feature list (far beyond the RX5808)

**9 items in the OSD menu:**

```
BAND · CHANNEL · SCAN · VIDEO (AUTO/NTSC/PAL) · CALIBRATE (QUICK/FULL) · OUTPUT (0.5-5.0×) · GAIN (AUTO/LEVEL/RSSI/MAX/fixed) · DAC TEST · EXIT
```

**Other:** AGC automatic gain · AFC automatic frequency control · C/N (carrier-to-noise) display · flight log (~7 hours stored in flash) · serial console at 115200 · web interface

**Measured filter noise bandwidth**

| Setting | Noise bandwidth |
|---|---:|
| XNARROW | 10.6 MHz |
| NARROW | 12.0 MHz |
| NORMAL | 13.2 MHz |
| WIDE | 16.3 MHz |

## 2x RX5808 


That said, while there is no off-the-shelf "`RX3364PRO` dedicated true-diversity open-source project", from a technical and hardware-DIY point of view the idea is entirely feasible and there is a well-trodden path to follow.

We can look at why such projects are rare along a few dimensions, and how you would build one if you wanted to:

### 1. Why are finished "RX3364PRO true diversity" projects so rare?

- **The band is a niche:** the `RX3364PRO` is an analog receiver module for the **3.3 GHz band (typically 3060–3500 MHz)**, mainly used to escape the crowded 1.2G/5.8G bands or to serve specific long-range / interference-resistant analog video needs. By contrast, traditional 5.8G solutions (FatShark, RapidFire, SteadyView) and 1.2G/1.3G true-diversity setups have huge user bases — which is exactly why plenty of open-source or commercial projects exist for them.
- **The module's own characteristics:** modules such as `RX3364PRO-SPI` usually come with an SPI interface and an RSSI (signal-strength) output. Their output is a standard analog baseband video (and audio) signal, which means the module is essentially a "front-end receiver head" — true diversity cannot be done with it alone; external circuitry is needed to do the video switching or the picture fusion.

### 2. If you want to DIY "true diversity", how is it done technically?

In the analog video world there are two mainstream ways to implement "true diversity":

**① RF front-end fast switching (Switching Diversity — the classic diversity receiver principle)**

- **Principle:** use two `RX3364PRO` modules, each feeding an antenna with a different direction or polarization (e.g. one directional panel, one omni mushroom).
- **Core control:** an MCU (STM32, ESP32 or Arduino) reads the **RSSI** (signal-strength voltage) from both modules in real time and compares them.
- **Switching action:** when antenna A weakens and B becomes stronger, a high-speed video switch chip (e.g. `FST3253` or a dedicated video switch IC) seamlessly cuts over to the stronger module's video output during vertical sync (or within a very short window), feeding the display or DVR.
- **Open-source reference:** look at the early open-source ***Diversity_RX*** project (an Arduino/STM32 multi-channel RSSI-switching receiver), swap its receiver heads for the RX3364PRO, and retune the RSSI sampling thresholds.

**② Audio/video two-path fusion (fairly rare)**

- Analog signals cannot be packet-aggregated perfectly the way digital signals can, so almost every analog diversity setup is the "compare RSSI and switch to the winner" scheme described above.

### 3. Practical DIY advice

If you have `RX3364PRO` modules on hand and want to build a 3.3G true-diversity receive system, you can work along these lines:

**Hardware**

- 2 × `RX3364PRO` modules.
- One MCU (e.g. ESP32 or STM32) to read the RSSI and make the logic decision.
- An analog video switching circuit.

**Antenna pairing**

- Since this is diversity, put a high-gain directional antenna (e.g. a 3.3G panel or Yagi) on one module and an omni antenna (e.g. a 3.3G whip or folded dipole) on the other — this gives you long-range directional gain plus close-in / all-round coverage with no blind spots.

If you are looking for a specific open-source repository (a GitHub project name), no major vendor or mainstream open-source circle currently has a hit project named "RX3364PRO Diversity". Most hackers playing with 3.3 GHz video simply modify a generic diversity control board (or write a few lines of Arduino code to read RSSI).



## ref