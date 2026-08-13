

# thrust-to-weight-ratio-dat.md

- [[thrust-to-weight-ratio-dat]] - [[FPV-stability-dat]] - [[FPV-tuning-dat]]


In your case (86g → 75g), shedding weight will make outdoor flight *more* stable, not more "floaty." However, extreme weight reduction really can make a quad feel floaty. Here's the explanation:

---

## The Key Physics: Wind Resistance = Thrust-to-Weight Ratio × FC Correction Speed, Not Just Weight

**Inertia (Weight)**
- Wind effect on the aircraft: The heavier it is, the less acceleration the wind can impart.

**Thrust Headroom (Thrust-to-Weight Ratio)**
- Wind effect on the aircraft: The higher it is, the faster the flight controller can correct attitude.

When wind makes a quad "float/drift," what's actually happening is: wind knocks the airframe off-level → the FC must spend thrust to pull it back. That recovery depends on **thrust**, not weight.

---

## Why Your Weight Reduction Is "More Stable," Not "More Floaty"

The key metric is the thrust-to-weight ratio:

| Metric | Current | After Reduction to 75g |
|--------|---------|------------------------|
| All-up weight | 86g | 75g |
| Thrust-to-weight ratio | 2.8–3.7 : 1 | 3.2–4.3 : 1 |
| Wind disturbance | Small (heavy) | Slightly larger |
| Correction capability | Weak (no headroom) | Strong (has headroom) |
| Result | ❌ Drifty | ✅ Stable |

Your current situation: the quad is genuinely heavy with lots of inertia, so wind can't easily push it around — but the FC also has **no spare thrust to pull it back to level!** Wind tips the airframe over and there isn't enough power to recover → it manifests as "drifting."

After weight reduction: the wind-induced tipping acceleration is slightly higher, but the FC's corrective force is much greater → the net effect is **more stable**.

---

## When Does Weight Reduction Actually Make It Drift?

When the thrust-to-weight ratio is already very high (>5:1), further weight loss only reduces inertia without adding correction benefit:

**Thrust-to-Weight Ratio vs. Wind Resistance (Conceptual Curve)**

```
Wind resistance
  │          ╱← Sweet spot (~4:1 optimal)
  │        ╱
  │      ╱   ← Your position (2.8–3.7:1, left rising segment)
  │    ╱
  │  ╱
  └────────────→ Thrust-to-weight ratio
     low       high
```

- **Left side (your 2.8–3.7:1):** weight reduction = climbing the curve, lighter = more stable
- **Sweet spot (~4:1):** best balance
- **Right side (>5:1):** over-reduced weight, insufficient inertia, light and floaty — a gust sets it wobbling (like a paper airplane)

---

## Conclusion

1. Reducing to 75g (450mAh) moves you *toward* the sweet spot — outdoor flight will be noticeably more stable, not more floaty.
2. If you overdo it (e.g., switching to an ultra-light 1S build under 60g), only when the thrust-to-weight ratio climbs past ~4.5:1 might "light-float" begin — but your 75g target is nowhere near that.
3. Sweet-spot reference: the Mobula8's official design uses a 450mAh configuration, which suggests ~75g is this airframe's design-optimal point.

In short: you're on the "too heavy" side, so weight reduction only makes it more stable; only cutting down to "too light" would make it float. Feel free to shed the weight.

