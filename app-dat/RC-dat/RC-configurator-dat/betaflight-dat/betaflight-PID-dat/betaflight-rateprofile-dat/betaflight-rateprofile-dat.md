
# betaflight-rateprofile-dat

- Controls **stick sensitivity** and **how fast the quad responds**  
- Lower values = slower, smoother indoor control  
- Higher values = faster, more aggressive control  


## Rates Type == Betaflight

| set              | RC Rate | Rate RC | Expo | Max Vel [deg/s] |
| ---------------- | ------- | ------- | ---- | --------------- |
| Basic/Acro Rates |         |         |      |                 |
| ROLL             | 1.06    | 0.56    | 0.15 | 482             |
| PITCH            | 1.06    | 0.56    | 0.15 | 482             |
| YAW              | 1.06    | 0.56    | 0.05 | 482             |

Rates Type？ == Betaflight BETAFLIGHT == cinewhoop

| set              | RC Rate | Rate RC | Expo | Max Vel [deg/s] |
| ---------------- | ------- | ------- | ---- | --------------- |
| Basic/Acro Rates |         |         |      |                 |
| ROLL             | 0.6     | 0.6     | 0.3  | 300             |
| PITCH            | 0.6     | 0.6     | 0.3  | 300             |
| YAW              | 0.6     | 0.6     | 0.3  | 300             |

![](2025-09-06-12-32-30.png)

Lower **RC Rate** → overall slower stick response.  

- Roll:   RC Rate 1.0 | Super Rate 0.65 | Expo 0.25
- Pitch:  RC Rate 1.0 | Super Rate 0.65 | Expo 0.25
- Yaw:    RC Rate 0.8 | Super Rate 0.70 | Expo 0.30
- Throttle Mid: 0.30
- Throttle Expo: 0.25



## Rates Type == Actual

- **Center Sensitivity** → how responsive the quad is around stick center.  
- **Max Rate (deg/s)** → maximum rotation speed at full stick deflection.  
- **Expo** → how much the curve softens near center stick.  

### 1. Center Sensitivity

- Controls responsiveness near stick center.  
- Indoor flying → set **lower** than outdoor to avoid twitchiness.  
- Example: `Center Sensitivity = 120` (instead of 200+ for outdoors).

---

### 2. Max Rate
- Sets the maximum rotation speed (°/s).  
- Indoor = keep rotation slower to avoid overshooting in tight spaces.  
- Example: `Max Rate = 400–500°/s` (outdoor freestyle often 700–1000°/s+).

---

### 3. Expo
- Smooths stick center further while keeping full rate at stick ends.  
- Indoor = a bit more expo to help small corrections.  
- Example: `Expo = 0.3–0.4`.

- Roll:   Center Sensitivity = 120 | Max Rate = 450 | Expo = 0.35
- Pitch:  Center Sensitivity = 120 | Max Rate = 450 | Expo = 0.35
- Yaw:    Center Sensitivity = 100 | Max Rate = 400 | Expo = 0.30


| set              | RC Rate | Rate RC | Expo | Max Vel [deg/s] |
| ---------------- | ------- | ------- | ---- | --------------- |
| Basic/Acro Rates |         |         |      |                 |
| ROLL             | 70      | 670     | 0    | 670             |
| PITCH            | 70      | 670     | 0    | 670             |
| YAW              | 70      | 670     | 0    | 670             |

**Expo** (Exponential) adjusts the sensitivity of your stick inputs around the center position.

- **Expo** = 0: Stick response is linear—movements are directly proportional.
- **Higher Expo**: Makes the center of the stick less sensitive (smoother, easier for small corrections), while the ends remain more responsive.

This helps pilots make precise, gentle movements without sacrificing full stick authority for fast maneuvers.

optimized 

| set              | RC Rate  | Rate RC    | Expo     | Max Vel [deg/s] |
| ---------------- | -------- | ---------- | -------- | --------------- |
| Basic/Acro Rates |          |            |          |                 |
| ROLL             | 10 or 20 | 720 or 800 | 0 or 0.5 | 670             |
| PITCH            | 10 or 20 | 720 or 800 | 0 or 0.5 | 670             |
| YAW              | 10 or 20 | 720 or 800 | 0 or 0.5 | 670             |


![](2025-09-04-12-38-55.png)

| Throttle Limit | Throttle Limit %0 |
| -------------- | ----------------- |
| OFF            | 80                |

for the smooth indoor flying 
| Throttle MID | Throttle EXPO |
| ------------ | ------------- |
| 0.20         | 0.70          |

![](2025-09-04-12-45-34.png)


1. Enable **Throttle Expo**:
   - Set `Throttle Expo = 0.2–0.4`.  
   - Reduces sensitivity around mid-throttle.  
2. Adjust **Throttle Mid**:
   - If hover is at ~30% stick, set `Throttle Mid = 0.3`.  
   - Matches your hover point with expo curve.  

## optimized version 2 for indoor flying 

| Throttle Limit | Throttle Limit %0 |
| -------------- | ----------------- |
| SCALE          | 55                |

| Throttle MID   | Throttle EXPO     |
| ------------   | -------------     |
| 0.50           | 0.50              |


Throttle Limit

- `Scale`: reduces power evenly across whole range.  
- `Clip`: cuts off only top-end throttle.  


## hover == throttle mid 

→ **Throttle MID** controls how stick input translates to motor power  
- Lower = more sensitive at low throttle  
- Higher = more stable at low throttle  

→ **Test Flight**  
- Arm the quad, hover at mid-throttle  
- If drone rises too fast → increase Throttle MID slightly  
- If drone feels sluggish → decrease Throttle MID slightly  







## ref 

- [[betaflight-PID-dat]]