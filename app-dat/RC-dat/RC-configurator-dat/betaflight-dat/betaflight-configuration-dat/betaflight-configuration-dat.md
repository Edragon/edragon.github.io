
# betaflight-configuration-dat

## options 

### Crash Recovery


if not work, try CLI set **crash_recovery = ON**

→ Connect flight controller → open **Betaflight Configurator** → click **Connect**  

→ Go to **Configuration Tab** → scroll to **Other Features**  

→ Tick **Crash Recovery** → click **Save and Reboot**  



## Configuration

### Accelerometer Trim

- Accelerometer Roll Trim
- Accelerometer Pitch Trim

| roll  | roll trim | pitch | pitch trim |
| ----- | --------- | ----- | ---------- |
| left  | --        | back  | --         |
| right | ++        | front | ++         |

#### 1. Accelerometer Trim
- General setting that shifts the "zero level" of the accelerometer.  
- Used if your quad drifts in Angle/Horizon mode even after calibration.  
- Instead of recalibrating, you can apply a small trim value here.

---

#### 2. Accelerometer Roll Trim
- Adjusts the accelerometer’s idea of "level" on the **Roll axis** (left ↔ right).  
- Example:
  - Drone drifts **right** in Angle Mode → add **positive Roll Trim**.  
  - Drone drifts **left** → add **negative Roll Trim**.  

---

#### 3. Accelerometer Pitch Trim
- Adjusts the accelerometer’s "level" on the **Pitch axis** (forward ↔ backward).  
- Example:
  - Drone drifts **forward** in Angle Mode → add **positive Pitch Trim**.  
  - Drone drifts **backward** → add **negative Pitch Trim**.  


### Board and Sensor Alignment

- 0 == Roll Degrees - 0 Pitch Degrees - 0 Yaw Degrees
- **First** GYRO/ACCEL - **CW 90°** First GYRO
- **Default** <MAG Alignment

### System configuration

Note: Make sure your FC is able to operate at these speeds! Check CPU and cycletime stability. Changing this may require PID re-tuning. TIP: Disable Accelerometer and other sensors to gain more performance.

- 8.00 kHzGyro update frequency
- 1.00 kHz PID loop frequency
- Accelerometer
- Barometer (if supported)
- Magnetometer (if supported)


### Dshot Beacon Configuration

Beacon Tone

- RX_LOST - Beeps when TX is turned off or signal lost (repeat until TX is okay)
- RX_SET - Beeps when aux channel is set for beep

### other features 

- air mode - consider turn this off, it may cause the whoop bump (hop round) when touch the ground

- [] INFLIGHT_ACC_CAL
- [] SERVO_TILT
- [x] SOFT SERIAL
- [] SONAR
- [] LED_STRIP
- [] DISPLAY
- [x] OSD
- [] CHANNEL_FORWARDING
- [] TRANSPONDER
- [] AIRMODE
- [?] DYNAMIC_FILTER


### Beeper Configuration


## ref 

- [[betaflight-dat]]