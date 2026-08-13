
# RTK-dat

- [[RTK-dat]] - [[arduRTK-dat]] - [[RTKlib-dat]]


# What Is RTK? (Real-Time Kinematic)

RTK (**Real-Time Kinematic**) is a technique that boosts GPS positioning from meter-level down to **centimeter-level** (±2cm), in real time. It's the technology behind DJI's "cm-level positioning" and professional surveying drones.

---

## The Problem It Solves

Standard GPS is only accurate to ±1–2m because of satellite clock errors, ionosphere/troposphere delays, and orbit errors. For a hovering drone, that means "circling drift" in a 2–3m radius — fine for navigation, useless for precise hold.

RTK removes those shared errors and gets position to ±2cm.

| System | Accuracy |
|--------|----------|
| Standard GPS | ±1–2m |
| SBAS (e.g., EGNOS/WAAS) | ±0.5–1m |
| **RTK GPS** | **±2cm** |
| RTK + multi-sensor fusion | centimeter-level |

---

## How It Works (Base + Rover Differential Correction)

```
       ┌──────────┐   correction data   ┌──────────┐
       │  BASE     │ ──────────────────→ │  ROVER    │
       │ (fixed)   │  (RTCM over radio/ │ (moving)  │
       └──────────┘   4G/WiFi)          └──────────┘
```

1. **Base station (fixed):** sits at a known surveyed location, measures its GPS position, and computes the *error* (the difference between measured and true position).
2. **Rover (moving):** receives its own GPS signal **plus** the base's correction data over a radio/4G/WiFi link.
3. **Carrier-phase measurement:** instead of just the code signal (meter-level), RTK tracks the *carrier wave phase* (wavelength ~19cm), which is far more precise.
4. **Ambiguity resolution:** the receiver figures out the exact integer number of wavelengths → locks in centimeter-level position.

The two must be **within ~10–30km** of each other, because atmospheric errors only correlate well at short baselines.

---

## Key Requirements & Limitations

- **Base + rover pair required** — you need a base station (or an NTRIP correction service over the internet)
- **Data link** — corrections must reach the rover in near-real-time (RTCM messages)
- **Clear sky** — needs good satellite visibility; fails under trees / in urban canyons / indoors
- **Lock time** — can take several seconds to resolve ambiguity ("RTK fix")
- **Cost** — RTK modules (e.g., u-blox F9P) are ~10× more expensive than plain GPS

---

## Applications

- **Surveying & mapping** — cm-level ground coordinates
- **Precision agriculture** — auto-steering tractors
- **Drone positioning** — DJI's cm-level hover / mapping drones
- **Autonomous vehicles** — lane-level localization

---

## Related Open-Source Notes

- [[arduRTK-dat]] — the open-source ArduRTK base/rover (u-blox F9P based)
- [[RTKlib-dat]] — RTKLIB, the open-source RTK solving software

> For a drone FPV context: RTK is what turns "GPS hold (±2m)" into a true "lock-down (±2cm)" — see [[DJI-quadcopter-dat]] and [[position-hold-dat]].

