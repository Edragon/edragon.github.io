

# altitude-hold-dat


- [[altitude-hold-dat]] - [[vision-VIO-dat]]

- [[sensor-proximity-dat]] 
  
- [[sensor-optical-flow-dat]]

- [[sensor-barometer-dat]]


## Vertical Positioning (Altitude Hold) Accuracy

| Sensor                | Accuracy | Notes                                  |
| --------------------- | -------- | -------------------------------------- |
| **Barometer**         | ±0.5–1m  | Drifts with weather / wind             |
| **Laser rangefinder** | ±1–2cm   | Most accurate, within 3–5m range limit |
| **Ultrasonic**        | ±3–5cm   | 2–3m range limit, affected by noise    |

> Note: altitude hold is usually more accurate than horizontal position hold, because the barometer / laser is better than GPS in the vertical axis.

---

## The Barometer's Role in the DJI Neo

**Mid/high-altitude vertical hold:** once beyond the bottom IR/vision range-finding limit (typically >5–10m), the downward vision sensor can no longer sense height relative to the ground accurately. The drone then relies on the barometer measuring atmospheric pressure changes to maintain a stable flight altitude.

**Multi-sensor data fusion (sensor redundancy):**
- Near the ground (0.5–10m): mainly the bottom IR/vision range-finding module handles centimeter-level precise altitude hold and palm launch/landing control.
- Mid/high altitude (>10m): mainly the barometer, combined with GPS/BeiDou satellite data, handles altitude hold and ascent/descent estimation.

**Fast altitude response & wind resistance:** the barometer senses altitude changes in real time, helping the flight controller apply power compensation — preventing sudden climbs or drops from air turbulence.

---

## Downward Sensing System

The drone's Downward Sensing System achieves low-altitude precise positioning and hovering by fusing two core technologies:

- **Optical Flow** (velocity estimation)
- **Range Finding** (distance measurement)

---

## Failure & Limitation Conditions

The downward vision system is highly dependent on the environment and tends to drift or fail in these scenarios:

- **No-texture / solid-color surfaces:** e.g., pure white floors, mirrors, polished marble — the camera can't extract valid feature points.
- **Dynamic / flowing surfaces:** e.g., water, wind-blown rice paddies — the vision system mistakes "water flow" for "airframe drift" and misjudges.
- **Extreme lighting:** too-dark environments (insufficient light to image) or specular reflections from strong light.
- **Exceeding sensing range:** when flight altitude surpasses the vision sensor's working limit (typically 10–30m, depending on the model), the downward vision system automatically hands positioning over to GPS/GNSS.




## ref 


