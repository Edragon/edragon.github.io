
# indoor-fly-dat

- [[mobula8-dat]] - [[indoor-fly-PID-tuning-dat]]

- the way to fly indoor = do not control your throttle, use pitch 

- [[motor-fan-ducted-dat]] - [[motor-dat]] - [[fan-dat]] - [[FPV-whoop-cine-dat]] - [[FPV-dat]] - [[FUS-X111-dat]] - [[indoor-fly-dat]]

## updated V2

### First, figure out the cause

**Voltage sag (VBat Sag)**
• Symptom: after a while it climbs / drops on its own (same throttle, different thrust)

**Throttle curve too linear**
• Symptom: coarse feel in the hover range (one click and it shoots up)

**Too much usable travel**
• Symptom: only 30-45% of the 0-100% range is used (wasted precision)

**Ground effect**
• Symptom: pushed up by an "air cushion" within 30cm of the ground

**Stick technique / radio hardware**
• Symptom: throttle ratchet teeth, gimbal precision

### Solutions (ranked by value for effort)

#### VBat voltage compensation ⭐️ Most effective (fixes "drifts more the longer you fly")

```bash
set vbat_sag_compensation = 100
save
```

- Principle: when voltage drops it automatically adds throttle → hover point stays constant
- You already validated this on the Mobula8 ✅

#### Throttle expo + midpoint ⭐️ Refined stick feel

```bash
set thr_expo = 25          # 0-100 (default 0), makes the mid range finer
set throttle_mid = 0.5     # hover throttle position (default 0.5)
save
```

- ⚠️ Prerequisite: first find your actual hover throttle value (check OSD or Betaflight data)
- If it hovers at 40% → `set throttle_mid = 0.4` (the expo curve flattens around that point)
- For indoor filming you can raise thr_expo to 25-35

#### Limit max motor output ⭐️ Improves precision across the whole travel

```bash
set motor_output_limit = 85    # use only 0-85%
save
```

- Indoor flying never needs full throttle → cut the useless top range → smaller change per click of stick

#### Radio throttle curve (EdgeTX side)
- Inputs → Throttle → Curve: build a curve that flattens the hover region
- Example: a 5-point curve that makes the 35-45% segment almost flat (fine adjustments don't shoot up)

#### Remove the throttle ratchet ⚠️ Key at the physical level
- Many radios have ratchet teeth on the throttle stick (click by click) → for indoor filming you must switch to smooth mode
- RadioMaster Pocket can be adjusted: remove the ratchet strip / adjust the friction screw → continuous smooth feel

#### Airmode settings

```bash
set dshot_idle_value = 550    # idle (keeps attitude control effective)
```

- Keep Airmode on (attitude stays controlled at low throttle, resists disturbance)
- But don't set idle too high (it makes the quad "want to float up")

#### Avoid ground effect
- Within <30cm of the ground the airflow bounces back → you get pushed up
- For indoor filming keep 0.5-1m altitude (stay out of the air-cushion zone)

#### Stick technique (free, but needs practice)
- Pinch grip (thumb + index finger) is twice as precise as thumb only
- Correct altitude with "taps" (small, repeated) instead of continuous push/pull

### Recommended combo (indoor filming standard)

1. vbat_sag_compensation = 100   ← must do
2. thr_expo = 25~30              ← must do
3. motor_output_limit = 85       ← recommended
4. Set the radio throttle stick to smooth (remove ratchet) ← must do, physical
5. Flatten the hover region in the radio throttle curve      ← nice to have


### 📌 Tuning order (don't mix it up)

Step 1: Fly once and read your actual hover throttle value from the OSD (e.g. 42%)
Step 2: Set throttle_mid (0.42) + thr_expo based on that value
Step 3: Set vbat_sag_compensation
Step 4: Fine-tune the radio curve + remove the ratchet




## obseleted 


### Motor Output Limit


Many pilots set Motor Output Limit around 65–75% for whoops.

50% is safe if you’re flying indoor cruising / training.


✅ Benefits

Much easier to hover and cruise smoothly indoors.

Prevents sudden “rocket up” when you accidentally push throttle too much.

Extends battery life (you don’t spike current as hard).

Motors run cooler.





### updates 

- RC smoothing == [PT3 based RC smoothing](https://betaflight.com/docs/wiki/tuning/4-3-Tuning-Notes)

    set rc_smoothing = ON
    set rc_smoothing_setpoint_cutoff = 10
    set rc_smoothing_feedforward_cutoff = 10

- Random wobbles in HD footage == [PT3 based RC smoothing](https://betaflight.com/docs/wiki/tuning/4-3-Tuning-Notes)

- turn off air mode indoor

- airmode strengh = 10 in [[betaflight-PID-dat]] - https://www.youtube.com/shorts/PBAo4fW7DDQ


### presents combination test 


== filters + tune + rates + RC_LINK



#### filters 

- [] [[Chris-Rosser-filter-AOS-cine20-dat]]

#### tune 

- [] [[mobula8-presents-dat]] == default not for indoor fly 

- [] [[uav-tech-tune-cinewhoop-dat]] 

- [] [[Chris-Rosser-filter-AOS-cine20-dat]]

- [] [[reddit-cine-present]]

#### rates 

- [] [[uav-tech-rates-dat]]

- [] [[Chris-Rosser-rates-AOS-dat]]

#### RC_LINK

- [] [[bf-presents-rc_link-dat]]

- [] expressLRS 250Hz





### Mobula8 Betaflight Indoor Setup Guide (Beginner-Friendly)

#### 1. Install and Connect
1. Install [Betaflight Configurator](https://github.com/betaflight/betaflight-configurator/releases) on your PC.
2. Connect Mobula8 via USB.
3. Flash the latest compatible Betaflight firmware for **F4 FC** (Mobula8 usually F4 1S or 2S version).
4. After flashing, reconnect to Betaflight Configurator.



#### 2. Ports Tab
- **UART1**: Serial RX (for FrSky or other receiver)
- **UART2**: Blackbox (optional)
- **UART3**: Unused
- Save and reboot.



#### 3. Configuration Tab

- **Mixer**: `Quad X`
- **ESC/Motor protocol**: `DSHOT600`
- **Gyro Update Frequency**: `8 kHz`
- **PID Loop Frequency**: `4 kHz` (smooth indoor flight)
- **Motor Stop**: `ON`
- **Air Mode**: `ON`
- **Small Angle Mode**: `ON` (helps beginner indoor flying)
- **Arming Angle Limit**: `180°`
- **Gyro Lowpass Filter**: default



#### 4. Modes Tab
- **ARM**: assign a switch on your transmitter
- **ANGLE / HORIZON Mode**: assign a switch for beginner-friendly flight
- **BEEPER**: assign for lost quad alert

#### 5. PID / Rate Profiles (Indoor Smooth)


- Lower **Roll / Pitch / Yaw rates** for smooth, slow indoor flight  


##### Tune PID*

- Indoor: **slightly lower P** to avoid twitchy oscillations  -- 以避免抖动和震荡  
- Indoor: **keep moderate I** → prevents slow drift without overcompensating   -- 防止慢速漂移且不过度补偿  
- Indoor: **lower D** slightly → avoids jitter from small prop wash   -- 可减少小范围螺旋桨气流引起的抖动

- Start with stock values  
- Reduce **P / D** slightly to avoid oscillation  
- Test hover → watch for drift or tilt  
- Adjust **I term** to reduce slow drift  


##### Rate Profile: Indoor Smooth

- RC Rate: 0.60
- Super Rate: 0.45
- Expo: 0.30

**PID Values**

ROLL / PITCH P: 38 / I: 40 / D: 18

YAW P: 55 / I: 50 / D: 0

- Low and soft values for smooth response.
- Adjust slightly if oscillation occurs.
- Lower values = smoother, less twitchy flight.





##### 6. Filters Tab


→ **Check Filters**  
- Low-pass filters reduce high-frequency jitters  
- Keep aggressive filtering low to maintain smooth control  

- **Gyro Lowpass / Dynamic Filter**: default
- **Dterm Lowpass**: default
- **Motor Lowpass / Boost**: default
- Avoid aggressive filtering indoors (may introduce lag).



#### 7. Receiver Tab
- **Channel Map**: usually `AETR1234`
- Verify RX is responding in real-time graph.
- **Deadband**: 5 (smooth small stick movements)

#### 8. Battery and Power
- Indoor 1S or 2S: use 3.7V–7.4V 300–450mAh LiPo
- Enable **Battery Voltage Monitoring** in Configuration
- Safe cut-off for 1S: 3.5V

#### 9. Motor Test / Prop Safety
- Remove props before testing.
- Test each motor spins in correct direction.
- Reverse motors in Motors tab if needed.

#### 10. Tips for Indoor Flying
- Fly in **ANGLE or HORIZON** mode for smooth control.
- Gentle stick movements only; avoid aggressive flips indoors.
- Lower rates = easier for beginners.
- Slightly increase I term (+5) if drifting too much.

#### 11. Optional Enhancements
- **Blackbox**: record and analyze PID tuning.
- **Battery Beeper**: low voltage alert.
- **LED Strip**: orientation aid indoors.


### tune 2 - Indoor Cinematic Whoop PID Tuning


| Category           | Parameter         | Value / Tip                 | Purpose                      |
| ------------------ | ----------------- | --------------------------- | ---------------------------- |
| **Basic Setup**    | AirMode           | Enabled                     | Control at low throttle      |
|                    | Throttle MID      | 0.48–0.52                   | Balanced hover               |
|                    | RC Rate           | 0.7–0.9                     | Smooth stick response        |
|                    | Super Rate        | 0.5–0.7                     | Prevent overshoot            |
|                    | Expo              | 0.2–0.4                     | Soft center stick            |
| **PID Gains**      | P Gains           | Slightly lower than stock   | Reduce twitchiness           |
|                    | I Gains           | Moderate                    | Correct slow drift           |
|                    | D Gains           | Lower than stock            | Reduce propwash oscillations |
|                    | Feedforward (FF)  | 0.8–1.0                     | Smooth stick response        |
|                    | Master Multiplier | 1.5–1.6                     | Global PID/FF scale          |
| **Filters & Axis** | Filters           | Moderate (dynamic optional) | Reduce propwash              |
|                    | Pitch = Roll      | Keep equal                  | Balanced indoor control      |
|                    | Yaw               | Slightly lower rates & D    | Smooth cinematic turns       |



### Motor Output Limit


Many pilots set Motor Output Limit around 65–75% for whoops.

50% is safe if you’re flying indoor cruising / training.


✅ Benefits

Much easier to hover and cruise smoothly indoors.

Prevents sudden “rocket up” when you accidentally push throttle too much.

Extends battery life (you don’t spike current as hard).

Motors run cooler.



## ref 

- [[betaflight-dat]]

- [[indoor-fly]]