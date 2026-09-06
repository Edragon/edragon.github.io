


# betaflight-sensors-dat.md


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


## ref 