
# betaflight-motors-dat

- [[ex1103-dat]] - [[motor-fpv-dat]] - [[ESC-SDK-dat]]

- [[betaflight-dat]] - [[betaflight-motors-dat]] 

## motors 

- mixer 

### ✅ Recommended ESC/Motor Protocol for Mobula8
- **DSHOT600** → most common, reliable, and default for Mobula8.

### ⚡ Alternatives (if you have issues)
- **DSHOT300** → safer fallback if you experience desyncs or motor twitching.  
- **DSHOT1200** → possible on some boards, but not necessary (no real benefit on Mobula8).  

test 
- [x] DSHOT 300
- [x] DSHOT 600






### settings 

`DSHOT300` -- ESC/Motor protocol

[] - MOTOR_STOP Don't spin the motors when armed 
[] - ESC_SENSOR Use KISS/BLHeli_32 ESC telemetry over a separate wlre
[x] - `Bidirectional Dshot (requires supported ESC firmware)`
12 - Motor poles (number of magnets on the motor bell)
0 - Dynamic Idle Value [* 100 RPM]
8% - Motor Idle ( %, static)


### Motor Idle ( %, static)

Motor idle (or **Disarm Throttle / Idle Throttle**) is the minimum rotational speed (RPM or throttle percentage) applied to the motors the moment you arm your drone, *before* you push the throttle stick. 

* **Why it matters**: Without an idle speed, motors would completely stop spinning when the throttle is at absolute zero mid-flight. When you pull the throttle down to descend quickly, the props would stop generating aerodynamic control authority, making the quad **unresponsive or twitchy** to roll/pitch/yaw commands. Having an active idle keeps the motors spinning slowly so the flight controller maintains full stabilization control at zero throttle.

---

### Recommended Setting for Mobula 8 (EX1103)

For a 2S micro whoop like the Mobula 8 running EX1103 motors, the recommended idle value in Betaflight is:
* **`5.0%` to `5.5%`** (Standard starting point)
* If your motors occasionally twitch, fail to spin up uniformly, or stop when descending rapidly, bump it up to **`6.0%`**.


### Motor poles

- [[EX1103-dat]]

EX1103 - KV11000 == Standard tiny whoop motors like EX1103 11000KV have 6 poles / 3-phase, but some high-torque variations may use 12 poles.






### ESC Bi-Directional DShot

**Mechanism: Standard BLHeli_S only receives control signals (one-way). Bluejay with Bidirectional DShot enabled requires the FC to send and receive telemetry packets every cycle.**

- [[bluejay-dat]] == ESC firmware

#### 1. DShot Protocol (normal)
- A **digital protocol** to send throttle signals from the flight controller (FC) to the ESC.
- More reliable than analog PWM or Oneshot/Multishot.
- Normally one-way: FC → ESC only.

#### 2. Bi-Directional DShot
- Extension of DShot where communication is **two-way**:
  - FC → ESC (throttle command)
  - ESC → FC (motor feedback data)

#### 3. What Data Comes Back?
- **RPM (motor speed)** in real-time
- **Current, voltage, temperature** (if ESC supports it)
- This allows the FC to know exactly how fast each motor is spinning.

#### 4. Why is it Useful?
- Enables **RPM Filtering** in Betaflight / INAV:
  - Filters gyro noise at exact motor frequencies.
  - Makes flight smoother and more efficient.
- More accurate telemetry than traditional ESC sensors.
- Helps with diagnostics (e.g., if one motor is desyncing).

---

#### Summary

**Bi-Directional DShot = digital two-way protocol between FC and ESC.**  
It not only controls motors, but also lets ESC report **real-time motor RPM & telemetry** back, enabling advanced features like **RPM filtering** for smoother flights.

#### 2. How to Check in Betaflight
1. Plug Mobula8 into Betaflight Configurator.
2. Go to **Configuration tab → ESC/Motor Features**.
3. Look for **"Bidirectional DShot"** checkbox.
   - If available, try enabling it.
4. Save & reboot.

#### 3. Verify in Motors Tab
- Go to **Motors tab** in Betaflight.
- If bi-directional DShot works, you should see **motor RPM values** in real time.
- If you only see throttle % but no RPM, your ESC firmware doesn’t support it.


## ref 

- [[betaflight-dat]]