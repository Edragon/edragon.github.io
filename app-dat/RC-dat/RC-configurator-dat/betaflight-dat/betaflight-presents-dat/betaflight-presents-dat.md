
# betaflight-presents-dat

- [[betaflight-dat]]

- [[Chris-Rosser-presents-dat]] - [[UAV-tech-presents-dat]]

- [[FPV-dat]]

## filters 

- [[Chris-Rosser-filter-AOS-cine20-dat]]

## tune 

- [[uav-tech-tune-cinewhoop-dat]] 

- [[Chris-Rosser-filter-AOS-cine20-dat]]

- [[reddit-cine-present]]

## rates 

- [[uav-tech-rates-dat]]

- [[Chris-Rosser-rates-AOS-dat]]

## RC_LINK

- [[bf-presents-rc_link-dat]]



## category 

- [] BNF
- [x] FILTERS
  - Gyro filters
  - D-term filters
  - RPM filters (if bidirectional DShot is enabled)
- [] LEDS
- [] MODES
- [] OSD
- [] OTHER
- [x] RATES
  - **Roll / Pitch / Yaw rates**
  - **Expo / RC rate**
  - **Rate profiles** for different flight styles
- [x] RC_LINK
- [x] TUNE == **PID controller settings**
- [] VTX

common used for a flight - [x] TUNE - [x] RATES - [x] FILTERS - [x] RC_LINK


## other tuner 

### FPV_CAM 


### tune 

- UWL 75mm Whoop Tune by Fresh Bread

- freestyle 

### RC_LINK

- ExpressLRS 250Hz


## info 

### Prop Wash Performance Booster (PWPF)

### 1) Prop Wash Performance Booster (PWPF)

### What it does
- Helps stabilize the quad in **prop wash / turbulence** (low-speed yaw/pitch/roll oscillations caused by disturbed airflow).
- Mainly improves **tiny whoop or cinewhoop stability** during hover or close-quarter flight.

### Requirements
- **FC:** Betaflight 4.3+ (most Mobula8 FCs can run this)
- **Motor & ESC:** Works with any brushless motors + DShot or multishot PWM ESCs
- **Notes:** Very useful for **indoor 1S Mobula8**, smooths hover & slow flight.

### How to enable
- Betaflight Configurator → Configuration → “Prop Wash Performance Booster” → enable
- Adjust “PWPF Strength” in PID tuning → Motor tab if needed

---

### 2) Dynamic Idle

### What it does
- Reduces idle motor throttle **automatically** during flight to reduce prop wash, save battery, and smooth low-throttle flight.
- Improves **hover stability**, especially in micro FPV like 85mm Mobula8.

### Requirements
- **FC:** Betaflight 4.3+ (Configurable in Motors tab)
- **ESC:** Must support **bidirectional DShot** or at least **telemetry** for accurate RPM sensing.
- If your Mobula8 has **BLHeli_S ESC without telemetry**, Dynamic Idle will be **limited or less effective**.
- Works better with **Bluejay or BLHeli_32 ESCs**.

### How to enable
- Betaflight Configurator → Configuration → Motors → Dynamic Idle → enable
- Adjust min motor idle and gain if necessary




## ref 

- [[betaflight-dat]]