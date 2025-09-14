
# indoor-fly-dat

- the way to fly indoor = do not control your throttle, use pitch 


## updates 

- RC smoothing == [PT3 based RC smoothing](https://betaflight.com/docs/wiki/tuning/4-3-Tuning-Notes)

    set rc_smoothing = ON
    set rc_smoothing_setpoint_cutoff = 10
    set rc_smoothing_feedforward_cutoff = 10

- Random wobbles in HD footage == [PT3 based RC smoothing](https://betaflight.com/docs/wiki/tuning/4-3-Tuning-Notes)

- turn off air mode indoor

- airmode strengh = 10 in [[betaflight-PID-dat]] - https://www.youtube.com/shorts/PBAo4fW7DDQ


## presents combination test 


== filters + tune + rates + RC_LINK



### filters 

- [] [[Chris-Rosser-filter-AOS-cine20-dat]]

### tune 

- [] [[mobula8-presents-dat]] == default not for indoor fly 

- [] [[uav-tech-tune-cinewhoop-dat]] 

- [] [[Chris-Rosser-filter-AOS-cine20-dat]]

- [] [[reddit-cine-present]]

### rates 

- [] [[uav-tech-rates-dat]]

- [] [[Chris-Rosser-rates-AOS-dat]]

### RC_LINK

- [] [[bf-presents-rc_link-dat]]

- [] expressLRS 250Hz





## Mobula8 Betaflight Indoor Setup Guide (Beginner-Friendly)

### 1. Install and Connect
1. Install [Betaflight Configurator](https://github.com/betaflight/betaflight-configurator/releases) on your PC.
2. Connect Mobula8 via USB.
3. Flash the latest compatible Betaflight firmware for **F4 FC** (Mobula8 usually F4 1S or 2S version).
4. After flashing, reconnect to Betaflight Configurator.



### 2. Ports Tab
- **UART1**: Serial RX (for FrSky or other receiver)
- **UART2**: Blackbox (optional)
- **UART3**: Unused
- Save and reboot.



### 3. Configuration Tab

- **Mixer**: `Quad X`
- **ESC/Motor protocol**: `DSHOT600`
- **Gyro Update Frequency**: `8 kHz`
- **PID Loop Frequency**: `4 kHz` (smooth indoor flight)
- **Motor Stop**: `ON`
- **Air Mode**: `ON`
- **Small Angle Mode**: `ON` (helps beginner indoor flying)
- **Arming Angle Limit**: `180°`
- **Gyro Lowpass Filter**: default



### 4. Modes Tab
- **ARM**: assign a switch on your transmitter
- **ANGLE / HORIZON Mode**: assign a switch for beginner-friendly flight
- **BEEPER**: assign for lost quad alert

### 5. PID / Rate Profiles (Indoor Smooth)


- Lower **Roll / Pitch / Yaw rates** for smooth, slow indoor flight  


#### Tune PID*

- Indoor: **slightly lower P** to avoid twitchy oscillations  -- 以避免抖动和震荡  
- Indoor: **keep moderate I** → prevents slow drift without overcompensating   -- 防止慢速漂移且不过度补偿  
- Indoor: **lower D** slightly → avoids jitter from small prop wash   -- 可减少小范围螺旋桨气流引起的抖动

- Start with stock values  
- Reduce **P / D** slightly to avoid oscillation  
- Test hover → watch for drift or tilt  
- Adjust **I term** to reduce slow drift  


#### Rate Profile: Indoor Smooth

- RC Rate: 0.60
- Super Rate: 0.45
- Expo: 0.30

**PID Values**

ROLL / PITCH P: 38 / I: 40 / D: 18

YAW P: 55 / I: 50 / D: 0

- Low and soft values for smooth response.
- Adjust slightly if oscillation occurs.
- Lower values = smoother, less twitchy flight.





#### 6. Filters Tab


→ **Check Filters**  
- Low-pass filters reduce high-frequency jitters  
- Keep aggressive filtering low to maintain smooth control  

- **Gyro Lowpass / Dynamic Filter**: default
- **Dterm Lowpass**: default
- **Motor Lowpass / Boost**: default
- Avoid aggressive filtering indoors (may introduce lag).



### 7. Receiver Tab
- **Channel Map**: usually `AETR1234`
- Verify RX is responding in real-time graph.
- **Deadband**: 5 (smooth small stick movements)

### 8. Battery and Power
- Indoor 1S or 2S: use 3.7V–7.4V 300–450mAh LiPo
- Enable **Battery Voltage Monitoring** in Configuration
- Safe cut-off for 1S: 3.5V

### 9. Motor Test / Prop Safety
- Remove props before testing.
- Test each motor spins in correct direction.
- Reverse motors in Motors tab if needed.

### 10. Tips for Indoor Flying
- Fly in **ANGLE or HORIZON** mode for smooth control.
- Gentle stick movements only; avoid aggressive flips indoors.
- Lower rates = easier for beginners.
- Slightly increase I term (+5) if drifting too much.

### 11. Optional Enhancements
- **Blackbox**: record and analyze PID tuning.
- **Battery Beeper**: low voltage alert.
- **LED Strip**: orientation aid indoors.


## tune 2 - Indoor Cinematic Whoop PID Tuning


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


## ref 

- [[betaflight-dat]]