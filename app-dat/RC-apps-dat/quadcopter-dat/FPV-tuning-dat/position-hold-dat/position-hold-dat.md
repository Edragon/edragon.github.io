

# position-hold-dat

- [[position-hold-dat]]

- [[altitude-hold-dat]] - [[location-hold-dat]] - [[indoor-hold-dat]]

- [[location-dat]] - [[indoor-fly-dat]]

- [[DJI-quadcopter-dat]]

## Hold Summary

| Scenario              | Best Combo            | Achievable Accuracy             |
| --------------------- | --------------------- | ------------------------------- |
| Outdoor, recreational | GPS + barometer       | Horizontal ±2m / Vertical ±1m   |
| Outdoor, professional | RTK + laser           | Horizontal ±2cm / Vertical ±2cm |
| Indoor                | Optical flow + laser  | Horizontal ±5cm / Vertical ±2cm |
| Indoor, professional  | VIO (Visual Odometry) | ±1–3cm                          |

```
Standard GPS hover:     ● ← quad slowly circles in a 2–3m radius
RTK hover:              ● ← barely moves, imperceptible to the naked eye
Indoor optical flow:    ● ← basically nailed in place, slight breathing
```


## Flight Control System


`Betaflight`'s design philosophy is "the pilot controls attitude" — wind fighting is not within its scope. What you want, "sense the wind + fight it automatically," is INAV/ArduPilot's specialty (wind estimation + feedforward tilting).

This points to the same conclusion again: if you seriously want "hold position + fight wind," you need to switch quads + flash INAV + add GPS (a 3.5"–5" quad is the standard platform). INAV's support on the Mobula8 micro is weak — not worth the trade-off.


Key physics: wind causes position drift, not attitude tilt. Betaflight only reads the gyro/accelerometer (attitude), not position → when wind carries the quad sideways, it has no idea.

---

Wind-Fighting Mechanism Comparison

**Betaflight**
- Can it sense wind? ❌ No, not directly
- Mechanism: only "corrects after it's blown off-level"; doesn't care about sideways drift

**INAV**
- Can it sense wind? ✅ Yes — Wind Estimation
- Mechanism: infers wind direction/speed from GPS velocity difference, automatically pre-tilts to counter it

**ArduPilot**
- Can it sense wind? ✅ Yes — wind estimation
- Mechanism: similar, more mature

---

How INAV Fights Wind (This Is What You Want)

1. GPS measures the actual ground speed (speed after being blown by the wind)
2. Compare it with the "commanded speed" (expected speed)
3. The difference = wind speed/direction (inferred)
4. The FC automatically pre-tilts into the wind (bank into wind)
5. Result: the quad braces against the wind before it gets blown away


This is feedforward control — fighting back before drift happens, not after. This is exactly how INAV's Position Hold mode works once enabled: the stronger the wind, the harder it banks into it — which looks like "staying put."





## Position Hold — Holding the Quad "Locked in the Air"

Achieving "staying put in the air" (Position Hold) — FPV quads don't have this feature by default; you need to add hardware and swap firmware. Solutions by scenario:

---

## Option 1: Outdoor + GPS (Most Common)

**Principle:** Add a GPS module → flash INAV firmware (replacing Betaflight) → enable Position Hold / Altitude Hold

| Component                       | Details                                           |
| ------------------------------- | ------------------------------------------------- |
| GPS module (e.g., M10 / BN-880) | 3–5g, ~¥30–50                                     |
| Firmware                        | Betaflight → INAV (supports position hold)        |
| Modes                           | PosHold (position hold) + AltHold (altitude hold) |

**Effect:** Holds position within GPS accuracy (±1–2m), auto-corrects against wind.

**Limitations:**
- ⚠️ Needs 6+ satellites; drifts under trees or between buildings
- Mobula8 is too small — the GPS antenna must go on top of the frame, and interference needs handling
- INAV's tuning support for 85mm micro quads is mediocre; flight performance is not as good as Betaflight

---

## Option 2: Indoor + Optical Flow (No-GPS Environment)

**Principle:** An optical flow sensor reads ground texture to compute displacement + laser/ultrasonic for altitude hold

| Component                                              | Details           |
| ------------------------------------------------------ | ----------------- |
| Optical flow module (e.g., PMW3901 / open-source flow) | 5–8g              |
| Laser rangefinder / ultrasonic                         | Altitude hold     |
| Firmware                                               | INAV or ArduPilot |

**Effect:** Indoor hover accuracy ±10cm — practically nailed in place.

**Limitations:**
- Needs texture on the ground (solid-color floors cause loss of lock)
- Altitude generally limited to 1–3m
- For the Mobula8, optical flow + laser = an extra 10g+, straining the power system

---

## Option 3: True "Nailed Down" — RTK + Multi-Sensor Fusion (Professional Grade)

| System                                | Accuracy         | Cost      |
| ------------------------------------- | ---------------- | --------- |
| Standard GPS                          | ±1–2m            | ¥30–50    |
| **RTK GPS**                           | ±2cm             | ¥500–2000 |
| RTK + optical flow + barometer fusion | Centimeter-level | ¥1000+    |

RTK is the real "lock-down": base station + rover differential correction gives centimeter-level position accuracy. It suits aerial photography / surveying — too heavy and too expensive for recreational FPV.

---

## Option 4: Software-Level Approximation of "Staying Put" (Zero Cost, Try First)

Approximate effects achievable without changing firmware:

1. **Angle mode + higher throttle to maintain:** hold altitude manually, position depends on pilot input (not true hold)
2. **Betaflight's GPS Rescue:** return-to-home can auto-fly back to the launch point, but it's not position hold (return only)
3. **"Hover practice" mindset:** practice Acro low-throttle hovering and manually hold position when wind is light

---

## My Recommendation (For You)

**Want outdoor point-hovering (shooting scenery / observing)**
- Recommended: switch to a 3.5–5" quad + GPS + INAV; adding GPS to a micro isn't worth it

**Want indoor lock-down (practice / demos)**
- Recommended: optical flow setup, but the Mobula8's power system can't carry much extra payload

**Want to first experience what "staying put" feels like**
- Recommended: flash INAV on a 5" quad and try PosHold

Honest take: the Mobula8 is a "freestyle toy" — position hold is asking too much of it: not enough payload capacity + weak INAV support for micro quads. If you seriously want "stay put," this is another reason to move to a 3.5"/5" quad (GPS + INAV is the standard setup there).





## ref 


