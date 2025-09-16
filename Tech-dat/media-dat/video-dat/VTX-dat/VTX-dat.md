
# VTX-dat

The Video Transmitter (VTX) is a crucial component of the FPV system, wirelessly transmitting camera images to FPV goggles.

- [[FPV-dat]]

- [[antenna-dat]] - [[antenna-lolipop-dat]]

- [[camera-FPV-dat]]


## standalone VTX module

- [[TX800-dat]]



## digital camera + VTX integrated alone system ? 

- [[camera-digital-dat]]

- [[DJI-dat]] - [[DJI-air-unit-dat]] - [[DJI-O4-dat]] == 100 usd - [[DJI-O3-dat]] 

- [[runCAM-dat]]

- [[caddxFPV-dat]]





## other info 

- [[fiber-analog-video-dat]]

- [[video-transmission-dat]]

- [[goggles-dat]]


## chip solutions 

### 1. RF / Video Transmitter Chips
| Chip / IC                 | Function                        | Notes / Typical Use                       |
| ------------------------- | ------------------------------- | ----------------------------------------- |
| **MAX1476**               | RF Power Amplifier              | Low-power analog VTX, 25–200 mW           |
| **MAX2606 / MAX2608**     | VCO / PLL / Frequency Generator | Generates carrier frequency, used with PA |
| **RFPA022 / RFPA023**     | RF Power Amplifier              | Popular in 600 mW–1 W micro/mini VTX      |
| **AVT / TX5823 / TX5828** | Integrated VTX module ICs       | Often in “all-in-one” VTX PCBs            |

### 2. Video Input / Processing
| Chip / IC                                  | Function                                    | Notes / Typical Use              |
| ------------------------------------------ | ------------------------------------------- | -------------------------------- |
| **LMH1980 / LMH1981**                      | Sync separator / video input                | For analog video sync processing |
| **MAX7456**                                | OSD (On-Screen Display)                     | Overlay telemetry / battery info |
| **Microcontrollers (STM8 / ATtiny / PIC)** | Channel selection, power control, OSD logic | Common in Tramp / SmartAudio VTX |

### 3. Voltage Regulation & Power
| Chip / IC                  | Function                     | Notes / Typical Use                        |
| -------------------------- | ---------------------------- | ------------------------------------------ |
| **LM2596 / LM1117**        | Linear / Switching Regulator | Provides stable voltage for VTX            |
| **AMS1117**                | Linear Regulator             | Low-cost 5V or 3.3V rail for low-power VTX |
| **Inductors / Capacitors** | Filtering & smoothing        | Reduce RF noise on power lines             |

### 4. RF Output / Matching Components
- **Discrete components**: Inductors, capacitors, microstrip traces for impedance matching (50 Ω).
- Sometimes **MMCX / U.FL / SMA connector ICs** for external antennas.

---

### 💡 Notes
- Many **modern VTX modules** combine RF PA + PLL + video input + microcontroller in a **single small IC or module**, like those found on Mobula8.  
- High-end HD digital VTX (DJI, Walksnail) use **custom ASICs** rather than discrete PA chips.  
- For typical analog 5.8 GHz micro drones: MAX1476/MAX2606 + LMH1980 + STM8 is a very common combo.


## FAQ 

### Running a 1 W Analog VTX for Extended Periods

1. **Heat**
- 1 W VTX produces significant heat.
- On tiny drones like the Mobula8, heat can **damage the VTX, FC, or battery** if there’s poor airflow.
- Risk increases in warm indoor environments.

2. **Battery Drain**
- 1 W output draws **more current**, reducing flight time significantly.
- Tiny cinewhoops may overheat their small LiPo packs if flown at full power for long periods.

3. **Legal Limits**
- Many regions **restrict 5.8 GHz analog power** (often max 25–600 mW).
- Flying 1 W indoors or near populated areas could **violate regulations**.

4. **Interference**
- High-power VTX can **interfere with nearby electronics** and even your own control link.
- On tiny drones, the ELRS RX is very close to the VTX, so interference risk is higher.

5. **Practical Recommendation**
- For **indoor flying**: 25–100 mW is sufficient.
- For **small outdoor fields**: 200–400 mW is usually enough.
- Only use 1 W for **long-range outdoor FPV** with proper cooling and larger drones.

### ✅ Summary
- Running 1 W for hours is **possible**, but not recommended on micro drones due to **heat, battery drain, and interference risks**.  
- Stick to lower VTX power for safe and reliable indoor/outdoor use.






## what is the VTX in FPV?

- VTX = video transmitter, the device that transmits the video signal from the drone to the goggles or monitor.
- AIO = all in one, a flight controller that integrates multiple components into a single unit, including the flight controller, ESC (electronic speed controller), and sometimes the VTX.
- smart audio = a feature that allows you to control the VTX settings (such as frequency and power) from the flight controller or goggles, without needing to access the VTX directly.
- IRC Tramp = a type of smart audio protocol used by some VTXs, allowing for remote control of the VTX settings.

- TBS UNIFY PRO 32 HV V2 = a high-voltage version of the TBS UNIFY PRO 32 VTX, which supports higher power output and is designed for use with high-voltage battery systems.


## VTX -- The TBS Unify Pro32 Nano 5.8GHz

The TBS Unify Pro32 Nano 5.8GHz VTX is a compact and feature-rich video transmitter designed for FPV (First-Person View) drone enthusiasts, particularly those involved in racing and freestyle flying. Manufactured by Team BlackSheep, this VTX offers a blend of performance, size, and advanced functionalities.


🔧 Key Specifications

- Operating Voltage: 3–13V (recommended 5V input)
- Dimensions: 15 x 13 x 2 mm
- Weight: 1g
- Antenna Connector: u.FL socket
- Video Format: NTSC/PAL
- Video Input Impedance: 75 Ohm
- Output Power: 14dBm (25mW), 20dBm (100mW), 26dBm (400mW), 28dBm (500+mW)


- BlackSheep TBS UNIFY PRO32 NANO 5G8 32-bit Video Transmitter
- With the TBS UNIFY PRO32 Nano, we have increased the output power, improved robustness, lowered
- power consumption, added powerful features, and perfected its installation in multi-rotors. In
- short, it is the highest quality, best overall performing nano VTx ever.
- Main features:
- Smallest and lightest video transmitter on the market
- Output power up to 400mW
- Ultra-clear transmission (up to 16 pilots at once!)
- PitMode - power up your quad during a race. Now with team race capability!
- Easy OSD, FC, and RC channel changes, with fallback button menu
- Robust RF amplifier allows powering up without an antenna for hours!
- Clean power-up and video switching
- CE certified
- Specifications:
- Operating voltage: 4.5 - 5.5V
- Operating temperature: ensure normal airflow
- Video input impedance: 75 Ohm
- Weight: 1 gram
- Antenna connector: u.FL socket
- Video format: NTSC/PAL
- Output power: 
    - 14dBm (25mW), 
    - 20dBm (100mW), 
    - 26dBm (400mW)







## ref 

- [[VTX-dat]] - [[camera-dat]] - [[wireless-camera-dat]]

- [[FPV-dat]]