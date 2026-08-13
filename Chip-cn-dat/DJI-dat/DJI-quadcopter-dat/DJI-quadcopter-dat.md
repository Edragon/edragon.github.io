

# DJI-quadcopter-dat

- [[DJI-neo-dat]] - [[DJI-dat]] - [[DJI-quadcopter-dat]]

- [[quadcopter-dat]]

- [[DJI-neo-dat]]



## tech summary 

- [[location-dat]] - [[GNSS-dat]] 

- [[IMU-dat]] - [[sensor-barometer-dat]] - [[sensor-motion-dat]] - [[6D-accelerometer-gyroscope-dat]] 

- [[sensor-camera-vision-dat]] - [[sensor-camera-dat]] - [[vision-dat]] 

- [[sensor-proximity-IR-dat]] - [[DJI-quadcopter-dat]]



## Alternative (Open-Source Ecosystem)

Yes — the open-source drone ecosystem is actually very complete. Most of what DJI can do, open-source solutions can do too; the difference is just "integration" and "ease of use." Layer-by-layer introduction:

---

## 1. Open-Source Flight Firmware (DJI's "Brain," Open-Source Edition)

**ArduPilot**
- Positioning: full-featured autopilot
- DJI-like features: ✅ position hold / return-to-home / waypoints / obstacle avoidance
- Characteristics: the most complete; supports cars, boats, planes, and multirotors

**PX4**
- Positioning: academic / professional grade
- DJI-like features: ✅ same as above + visual odometry
- Characteristics: clean code, mainstream in the professional drone community

**INAV**
- Positioning: FPV quads / fixed-wing
- DJI-like features: ✅ PosHold / return-to-home / wind estimation
- Characteristics: forked from Betaflight, lightweight

These three firmwares = the open-source version of DJI's flight control system. For your "wind resistance + hold position" needs → ArduPilot is the best fit (highest maturity).

---

## 2. Open-Source Flight Controller Hardware (DJI's "Hardware," Open-Source Edition)

| Hardware | Details | Price |
|----------|---------|-------|
| **CubePilot (Pixhawk family)** | ArduPilot's official hardware, industrial grade | ¥800–3000 |
| **Holybro Pixhawk series** | Mainstream open-source FC | ¥500–1500 |
| **Matek / SpeedyBee** | FPV-oriented open-source FCs | ¥200–600 |
| **Modular combo** | Choose your own MCU + GPS + power module | Flexible |

The `Pixhawk` architecture is the benchmark for open-source hardware — modular, repairable, no locked-zone restrictions (DJI has no-fly zones/restrictions).

---

## 3. Open-Source Ground Stations (DJI's "Remote App," Open-Source Edition)

**Mission Planner**
- Features: waypoint planning / parameter tuning / maps
- Platform: Windows

**QGroundControl**
- Features: cross-platform ground station
- Platform: Win / Mac / Linux / mobile

**ArduPilot Mission**
- Features: mobile ground station
- Platform: Android

Covers most of DJI's functionality: live video feed, telemetry, one-touch return-to-home, route planning.

---

## 4. Open-Source Video/Telemetry Links (Open-Source Alternative to DJI OcuSync)

- [[VTX-dat]] - [[OpenHD-dat]] - [[ELRS-dat]] - [[CRSF-dat]] - [[ghost-dat]] - [[mavlink-dat]]
 

**OpenHD**
- Details: Raspberry Pi + WiFi video link, open-source digital FPV, supports long range

**ExpressLRS (ELRS)**
- Details: open-source RC link (the one your Mobula8 uses)

**Ghost / CRSF**
- Details: open-source protocols

**Mavlink**
- Details: open-source communication protocol (the "USB" of the drone world)

---

## 5. Open-Source RTK (DJI's Centimeter-Level Positioning, Open-Source Edition)


- [[RTK-dat]] - [[arduRTK-dat]] - [[RTKlib-dat]]

**ArduRTK / u-blox RTK**
- Details: u-blox F9P module + open-source base station

**RTKLIB**
- Details: open-source RTK solving software

Cost
- Details: ¥500–1500 (F9P module), ~10× cheaper than DJI RTK

---

## 6. Open-Source Complete Aircraft Projects (Reference Designs)

- [[crazyflie-dat]] - [[arducopter-dat]] - [[PX4-dat]] - [[F450-dat]] - [[F550-dat]]

**Crazyflie**
- Details: open-source micro drone (standard for university labs)

**ArduCopter standard frames**
- Details: complete open-source drawings + configurations

**PX4 reference frames**
- Details: officially validated complete aircraft designs

**F450/F550 + Pixhawk**
- Details: the most classic DIY open-source builds

---

## The Gap vs DJI (Honest Assessment)

| Aspect | DJI | Open Source |
|--------|-----|-------------|
| Out of the box | ✅ Unbeatable | ❌ Requires self-tuning |
| Integration | ✅ All-in-one | ❌ Assemble it yourself |
| Support / warranty | ✅ | ❌ You're on your own |
| **Flexibility / programmability** | ❌ Closed | ✅ Fully open |
| No-fly-zone restrictions | ❌ Has them | ✅ None |
| Cost | High | 50–70% lower |
| Repairs | Send back to factory | Fix yourself, cheap |

---

## Recommendation for Your Needs

You want "wind resistance + position hold" — the optimal open-source path:

```
ArduPilot firmware
+ Pixhawk/Cube FC (or budget SpeedyBee F405)
+ GPS (M10, ¥50)
+ Optical flow module (¥80, optional)
+ Mission Planner ground station
─────────────────────────────────
Total cost ¥500–1500, capability ≈ DJI Mini-level positioning
```


Summary: open source isn't "similar to DJI" — it's "the DIY version of DJI." It has basically all the features; the price you pay is that you tune it and fix it yourself. In return you get: fully controllable + cheaper + unrestricted. Given your development background (you can solder boards and read code), the open-source route suits you better than DJI.



## Tech




DJI's positioning system is "multi-sensor redundancy + intelligent switching" — each sensor has its own strengths, and they complement each other after fusion. Breakdown one by one:

---

## 1. GPS (Satellite Positioning) — Long-Range "Coarse Positioning"

| Property      | Details                                                       |
| ------------- | ------------------------------------------------------------- |
| Principle     | Receives 4+ satellite signals, triangulation                  |
| Accuracy      | ±1.5–3m                                                       |
| Update rate   | 5–10Hz (slow)                                                 |
| Advantages    | No range limit, all-terrain outdoors                          |
| Disadvantages | Low accuracy, slow updates, fails indoors / between buildings |

Role: provides global coordinates so the drone knows "which part of the sky it's in." Using it alone for hover = circling drift.

---

## 2. Downward Vision — Short-Range "Fine Positioning"

| Property         | Details                                                                                                    |
| ---------------- | ---------------------------------------------------------------------------------------------------------- |
| Principle        | Bottom camera films the ground, recognizes feature points (texture/corners)                                |
| Algorithm        | Visual-Inertial Odometry (VIO): feature-point displacement across consecutive frames → infers drone motion |
| Accuracy         | ±1–3cm (close range)                                                                                       |
| Update rate      | 30–100Hz (fast!)                                                                                           |
| Effective height | ~0.5–10m (blurrier higher up)                                                                              |
| Disadvantages    | Loses lock on solid-color ground / water / at night                                                        |

Role: the secret workhorse of DJI's stable hovering. Feature-point matching + IMU fusion (VIO), 100Hz refresh, detects gusts within milliseconds.

---

## 3. Optical Flow — The "Lite Version" of Vision

| Property          | Details                                                                            |
| ----------------- | ---------------------------------------------------------------------------------- |
| Principle         | Films the ground, computes pixel movement of the whole frame (simpler than VIO)    |
| Difference vs VIO | Optical flow only computes "overall displacement," doesn't reconstruct 3D features |
| Accuracy          | ±5–10cm                                                                            |
| Update rate       | 50–100Hz                                                                           |
| Effective height  | 0.5–3m                                                                             |

Role: on small platforms where VIO is too heavy/expensive (Mini series), optical flow substitutes part of the vision positioning. Essentially a "budget VIO."

---

## 4. Infrared (IR) — Altitude Positioning + Support

| Property         | Details                                                         |
| ---------------- | --------------------------------------------------------------- |
| Principle        | Emits infrared downward, measures distance by reflection time   |
| Accuracy         | ±2–5cm                                                          |
| Effective height | 0.2–5m                                                          |
| Role             | Precise altitude hold (vertical), works with vision positioning |
| Note             | Fails in bright light / on transparent surfaces                 |

Role: handles "vertical" positioning. Vision/GPS handle horizontal X/Y; infrared (or laser) handles vertical Z.

---

## 5. Fusion Logic: Sensor Voting + Confidence Weighting

The core of DJI's Sensor Fusion:

```
                    ┌── GPS (global, slow, coarse) ──────────┐
                    │                                        │
  Real-time position = ├── Downward Vision VIO (near, fast, fine) │
  weighted fusion   │                                        │
                    ├── Optical Flow (near, fast, mid) ──────┤
                    │                                        │
                    └── IMU (dead-reckoned, ultra-fast) ─────┘
                         ↑
                 the "common referee" of all sensors
```

Fusion process:

1. IMU is the master clock: integrates 1000×/sec to estimate position (inertial dead-reckoning)
2. Vision/GPS correction: every 10–100ms, real measurements "correct" IMU's accumulated drift
3. Confidence weighting: use whichever sensor has the best signal (clear vision → vision dominates; flying too high → GPS dominates; at night → GPS+IMU only)
4. Kalman filter: models both noise and latency, outputs the smoothest estimate

---

## Real-World Scenario Examples

Takeoff (0–1m)
- Dominant positioning: IR altitude hold + optical flow positioning (centimeter-level)

Low-altitude hover (2–5m)
- Dominant positioning: downward vision VIO dominates (±2cm, 100Hz)

High-altitude flight (50m+)
- Dominant positioning: GPS dominates (±2m), vision fails

Building clusters / shade
- Dominant positioning: GPS poor → vision assists to save the day

Night
- Dominant positioning: vision fails → relies entirely on GPS + IMU

---

## One-Sentence Summary

DJI positioning = IMU as the "stopwatch" (fast but drifts), vision/GPS as the "ruler" (accurate but slow), Kalman filter fuses them: estimate with the fast one, correct with the accurate one.

So the core of DJI's wind resistance is: the vision ruler measures at 100Hz, the IMU stopwatch computes at 1000Hz — a gust is detected and corrected within 10ms.

---

## What You Can Borrow (How Much FPV Can Copy)

| Tech                       | Copyable on FPV                | Cost    |
| -------------------------- | ------------------------------ | ------- |
| GPS + INAV position loop   | ✅ Copyable                     | ¥30–50  |
| Optical flow module        | ✅ Copyable (supported by INAV) | ¥50–100 |
| VIO visual odometry        | ⚠️ Hard (needs compute power)   | High    |
| Multi-sensor Kalman fusion | ✅ Built into INAV              | 0       |

Best FPV "copy homework": GPS + optical flow + INAV = low-cost way to get "position loop + multi-source fusion" — it's the simplified version of DJI positioning.


## position-hold 

- [[position-hold-dat]]




DJI's wind resistance is a system-level engineering effort — it doesn't have a "wind sensor" either, but it pushes wind-fighting to the extreme using "precise positioning + multi-level control + large thrust headroom." Here's the breakdown:

---

## 1. How DJI "Senses" Wind: Reverse-Inferring from Position Error

DJI doesn't measure wind, but senses it indirectly through position/velocity error:

```
Wind pushes the quad right → position drifts → vision/GPS reports position error
→ Position loop (outer) computes "the velocity command needed to fly back"
→ Velocity loop (inner) compares "actual velocity vs commanded velocity"
→ Difference = drift velocity caused by wind → tilts compensation in the opposite direction
```


Core idea: it doesn't look at "is the quad tilted?" (attitude), but "is the quad moving?" (position + velocity) — this is exactly the piece Betaflight is missing.

---

## 2. Three-Layer Cascaded Control (DJI's Specialty)

```
┌──────────┐  position error  ┌──────────┐  velocity error  ┌──────────┐  tilt command
│ Position │ ───────────────→ │ Velocity │ ───────────────→ │ Attitude │ ──────────→ Motors
│   loop   │                  │   loop   │                  │   loop   │
│ (outer)  │                  │  (mid)   │                  │ (inner)  │
└──────────┘                  └──────────┘                  └──────────┘
  GPS+vision                    IMU+vision                    Gyroscope
  10-30Hz                      100-500Hz                      1000Hz
```


- Position loop: slow but accurate (GPS/vision) → decides "where it should fly to"
- Velocity loop: medium speed → decides "how hard to counter"
- Attitude loop: extremely fast (gyro) → actually executes the tilt

Wind is a "steady-state disturbance." The integral term (I) of the position loop continuously accumulates error → outputs a constant counter-tilt angle to brace against the wind. This is the source of "the stronger the wind, the harder it banks."

---

## 3. DJI's Unique Advantages (What the Mobula8 Can't Replicate)

**Multi-source positioning**
- DJI: GPS + downward vision + optical flow + infrared fusion
- Your FPV: GPS only (or none)

**Vision positioning rate**
- DJI: vision 30–100Hz, millisecond-level latency
- Your FPV: GPS 5–10Hz, 100ms+ latency

**Thrust-to-weight ratio**
- DJI: 3–5:1 (large prop disc)
- Your FPV: 2.8–3.7:1 (tight)

**IMU precision**
- DJI: industrial grade (temperature-compensated)
- Your FPV: consumer grade

**Power redundancy**
- DJI: ample, can tilt freely
- Your FPV: strained, tilting means losing altitude

The most critical gap is positioning rate: DJI's vision positioning refreshes at 100Hz and detects + corrects within 10ms of a gust; your GPS only reports once every 100ms — by the time it notices, the quad has already drifted tens of centimeters.

---

## 4. Simplified Understanding

Where does the wind come from?
- DJI's answer: doesn't measure it, looks at "how much it got pushed"

How to fight it?
- DJI's answer: position loop → velocity loop → attitude loop, pulling back level by level

Why is it so fast?
- DJI's answer: vision at 100Hz + industrial IMU

Why is it stable?
- DJI's answer: high thrust-to-weight ratio, so tilting costs nothing

---

## What This Means for You

To "approach DJI's wind resistance," the lowest-cost path:

1. Add GPS + flash INAV → get a position loop + velocity loop (Betaflight has no position loop — this is the fundamental gap)
2. Switch to a 5" quad → thrust-to-weight ratio goes up, so there's headroom for tilting
3. Vision positioning (optical flow / stereo vision) → hard on micro quads, a pro-level play

In one sentence: DJI's secret isn't "sensing wind" — it's "sensing displacement fast enough + having enough power to correct it." Adding INAV to an FPV quad gives you the position loop; the remaining gap is positioning rate and power headroom.

## ref 

