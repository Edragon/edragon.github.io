


# bluejay-dat

- [[ESC-SDK-dat]] - [[BLHeli-dat]] - [[bluejay-dat]]

Startup Power Threshold Set Too Low

Issue: Bluejay defaults to low startup power levels optimized for larger 5-inch motors.

Mechanism: Tiny 1S/2S whoop motors have high coil resistance and need a stronger startup punch. If Startup Power (Min Protection) in Bluejay is set to standard defaults, the ESC gives up trying to turn the rotor before it even spins up.

Fix: Increase Startup Power in Bluejay to 1010–1050 (or 11–12 depending on the UI scale).


for [[mobula8-dat]]


Fix: Flash Bluejay with `24kHz` PWM frequency. 

Fix: Force the protocol to `DSHOT300` (or even DSHOT150) in Betaflight.

Minimum Startup Power(Boost) == `1020~1040`
Maximum Startup Power (Protection) == `1100~1200`

## compare 

## Why 24 kHz Fits EX1103 11000KV Well

* **Stronger Low-End Torque and Reliable Startup**: 
  * High-KV, low-turn micro motors like the 11000KV have low coil resistance. At 24 kHz, the conduction time per PWM pulse is longer, delivering more instantaneous energy per pulse. This helps the motor easily overcome static friction, **resolving startup stutters, twitching, or 100% telemetry error rates** commonly experienced on F411 boards with Bidirectional DShot.
* **Punchier Low-End Response**: 
  * Lower frequency switching gives a more immediate, aggressive initial response when punching the throttle compared to 48 kHz.

---

## 24 kHz vs. 48 kHz Comparison (2S 11000KV Setup)

| Performance Metric                   | **24 kHz (Recommended)**                            | **48 kHz**                                                               |
| :----------------------------------- | :-------------------------------------------------- | :----------------------------------------------------------------------- |
| **Startup Reliability & Sync**       | **Excellent** (Fewer sync losses or stutter stalls) | Weaker (lower low-end torque, prone to startup failures on micro motors) |
| **Low-Throttle Punch / Response**    | **Strong & Direct**                                 | Smoother, more gradual                                                   |
| **Throttle Linearity**               | Good                                                | **Extremely Smooth**                                                     |
| **Flight Time / Battery Efficiency** | Standard                                            | **Slightly Longer** (lower switching losses)                             |
| **ESC / Motor Heat**                 | Slightly higher (within safe limits)                | Slightly lower                                                           |



## ref 