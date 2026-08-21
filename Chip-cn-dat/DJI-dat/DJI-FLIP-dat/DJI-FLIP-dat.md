

# DJI-FLIP-dat

- [[DJI-FLIP-dat]] - [[DJI-dat]] - [[FPV-dat]]




## info 

| Item | Size |
| :--- | :--- |
| Propeller | 6 in (fits in the enclosed ducts) |
| Folded body | 136 × 62 × 165 mm (~5.4 × 2.4 × 6.5 in) |
| Unfolded body | 233 × 280 × 79 mm (~9.2 × 11.0 × 3.1 in) |
| Takeoff weight | Under 249 g (with battery + microSD) |
| Battery | 3110 mAh / 22.3 Wh, ~83.5 g |

## endurance 

The DJI Flip can fly for 30+ minutes (officially up to ~30 minutes of hovering; the 1-hour figure is a theoretical low-load cruise value). The core reason is that it follows a completely different design philosophy from an FPV racer: **“efficiency first, performance just good enough”**.


| Comparison | DJI Flip | 5-inch FPV Racer | Why Flip wins on endurance |
| :--- | :--- | :--- | :--- |
| Weight | 249 g | ~500 g | Lighter airframe needs less power to stay up |
| Rotor disk loading | Extremely low (249 g over 4 × ~6-inch fully enclosed ducts) | High (2-3x higher) | Low disk loading → slower prop RPM → higher efficiency → lower hover power |
| Thrust-to-weight ratio | ~2-2.5:1 | 5-8:1 | Low ratio → smaller, lighter motors run near their efficiency peak (60-80% load vs 30-50%) |
| Battery weight share | ~45-50% (~120 g of 249 g) | 30-40% | Max battery share = the battery itself is the endurance |
| Motor | Custom low-KV, high-torque, direct-drive (85%+ efficiency) | High-KV, high-speed (70-80% efficiency) | Low RPM, high-torque operation has lower copper and iron losses |
| Props | Fully enclosed ducted props | Open 5-inch props | Ducts cut tip-vortex losses → +5-10% efficiency (and safety) |
| Hover power per gram | Very low | High | Less energy per gram of mass → longer flight |
| Endurance | ~30 min | 5-8 min | All the above add up to a much longer hover time |
| Maneuverability | Stable but sluggish | Aggressive / agile | Flip trades agility for efficiency; racing drones do the opposite |


**In short:** the DJI Flip is the product of “giving everything up for endurance”: low thrust-to-weight ratio + low rotor disk loading + a large battery share + efficient low-KV motors. It never tries to do freestyle — every gram of weight budget goes to the battery and efficiency. The FPV racer is a performance machine; the Flip is an endurance machine.

---

**Takeaways for your own build:**

If your goal is long hover/photo endurance, copy the Flip’s approach:

| # | Principle |
| :-: | :--- |
| 1 | Use low-KV motors with larger props and a low thrust-to-weight ratio (~2:1 is enough — do not stack on power) |
| 2 | Push the battery weight share toward ~50% |
| 3 | Pick efficient motors (low KV, high torque) |
| 4 | Use ducted props if possible |

This again confirms that a 5-inch racing architecture (high thrust-to-weight ratio) is inherently bad for long endurance — either change the architecture (e.g., a 7-inch low-KV cruiser) or accept ~5 minutes.




## ref 