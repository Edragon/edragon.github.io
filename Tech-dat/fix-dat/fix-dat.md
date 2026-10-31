

# fix-dat

- [[commerial-dat]] - [[fix-dat]] - [[fab-workspace-dat]]




## Disassembly of battery-powered devices

- [[battery-lithium-dat]]

Heating is possible, but **75 °C is too close to the safety limit** — the temperature must be reduced.

### 1. Lithium battery temperature thresholds — thermal runaway triggers in stages

| Cell temperature | What happens internally | Risk level |
| --- | --- | --- |
| < 60 °C | Normal operating / storage range | ✅ Safe |
| 60–80 °C | Accelerated aging, electrolyte decomposition begins | ⚠️ Capacity loss |
| **80–85 °C** | **SEI film starts to decompose (exothermic onset)** | ⚠️⚠️ Hard limit for heating |
| 120–140 °C | Separator shutdown / begins to melt | 🔴 Escalating |
| 140–180 °C | Separator collapses → internal short circuit | 🔴🔴 Critical |
| 180 °C+ | Thermal runaway, venting, fire | 🔥 Runaway |

### 2. ⭐ Conclusion: 75 °C is unsuitable — drop to 55–65 °C

```text
75 °C plate → only 5–10 °C margin below the 80–85 °C SEI onset   ⚠️ far too tight
              The GO 2 body is only 20 mm thick, no internal air gap, low thermal resistance
              → the cell is probably right against the shell, so its temperature
                is close to the plate-side surface temperature
        ↓
⭐⭐ For any device containing a lithium battery, drop to 55–65 °C.
   Trade 【time】 for 【temperature】.
   65 °C for 8–10 min  ≫  80 °C for 3 min (the former is far safer)
   ⚠️ The temperature you measure must be the 【device surface】, not the plate.
```

### 3. Three mandatory pre-steps (do them in order)

**① ⭐⭐ First discharge the cell to 30–50 %**

The literature is explicit: *thermal runaway is more severe at higher SOC.*
→ 【A fully charged cell has the worst thermal stability】 — never heat a full pack.
(For the GO 2, just power it on and record for a while until it drops to mid-level.)

**② ⭐ Measure the 【device surface】 temperature with an IR thermometer** (not the plate)

Stop heating when the surface reaches 65 °C; resume only after it falls back to 50 °C.

**③ ⚠️ Confirm there is no swelling**

A swollen cell has dramatically lower thermal stability → hard red line for this skill: **never heat a swollen cell**.
(For the GO 2, any shell deformation or an abnormally opening seam is the warning sign.)

### 4. ⭐⭐ Four safer alternatives (sorted by safety)

| Rank | Method | Notes |
| --- | --- | --- |
| 1 (safest) | Warm water bag (~45 °C) in a sealed bag, pressed on the body; replace when cool | Doable at home, no hot spots |
| 2 | Hair dryer on low heat, kept moving and at a distance | Never hold still on one spot |
| 3 | Warm room / hot towel wrap, long duration | Slow but very gentle |
| 4 | Heating plate at 55–65 °C, longer dwell time | Only after steps ①–③ |

> 💡 The warm water bag method can be done at home: put ~45 °C water in a sealed bag, press it onto the device, and swap the water when it cools. For the "battery + small body" combination it is far safer than a heating plate.

### 5. ⚠️ Heating and charging are mutually exclusive (easily overlooked)

- ❌ Do **not** charge while heating.
- ❌ Do **not** charge immediately after heating → wait until the device is back to room temperature.
  (Charging at high temperature is one of the most dangerous operating conditions for a lithium cell.)
- ⚠️ If you smell a sweet or pungent odour while heating, or the shell becomes abnormally soft → cut power immediately, move away, ventilate.
- 🔥 A lithium battery fire **cannot be put out with water**: use dry powder / sand / a fire blanket; a small cell can be dropped into a metal bucket and left alone.

## ref 