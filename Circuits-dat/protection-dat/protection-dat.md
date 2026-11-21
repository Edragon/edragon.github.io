
# protection-dat

- [[protection-power-dat]] 

- [[power-protection-Vmotor-dat]]


- [[signal-protection-dat]]

- [[USB-ESD-dat]]

- [[battery-protection-dat]]

- [[current-limit-dat]]

- [[ESD-dat]]


- [[Conformal-Coating-dat]] - [[silicon-grease-dat]]



## board 

- [[B-S-1W-dat]]


## protection module 

LGDS-300 - Hi-Rel Grade, DC/DC Transient Protection Module, 300 W




## 4-layer PCB protection


Protection has to be built in layers. You cannot bolt on one component and call it safe. The whole design reduces to a single criterion: no single component failure may cause a fire or a shock — that is IEC 62368-1's phrasing, not my opinion.


### First define what you are defending against

- ① Load-side faults        output short, overload, capacitive inrush, reverse connection
- ② Power-device failures   rectifier diode short, MOSFET short, secondary diode short
- ③ Feedback-loop failures  opto ageing/open, divider resistor open → output overvoltage kills the load
- ④ Transformer failures    inter-winding short, insulation breakdown, overheating
- ⑤ Input-side failures     varistor ageing to short, X-cap failure, lightning surge
- ⑥ Environment & build     poor cooling, blocked vents, foreign objects, creepage contamination, PCB carbonisation

These six fail in completely different ways and are handled by different layers. No single fuse covers all of them.

###  A four-layer architecture (for your 5 V / 1 A, 5 W supply)

#### L1 — AC input: stop the input side from catching fire


| Part              | Your spec                                 | Role and caveats                                                                                                                                                                                           |
| ----------------- | ----------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Fuse F1           | 250 V / 0.5 A time-lag (T)                | Must sit in the live (L) conductor, not only in N. Breaking capacity ≥ prospective short-circuit current (1.5–3 kA class). I²t must exceed the turn-on inrush but stay below what downstream parts survive |
| Fusible resistor  | 33 Ω / 1 W (AC01-CS)                      | Having both is better: the resistor limits inrush, the fuse interrupts                                                                                                                                     |
| Varistor MOV/TMOV | 07D471K (MCOV ≥ 300 V, i.e. 1.25 × 240 V) | Must be in series with the fuse — MOVs fail short, and the fuse is what clears that failure                                                                                                                |
| X2 cap + bleeder  | 0.22 µF / 275 VAC + 1 MΩ                  | τ ≈ 0.22 s, so the plug is discharged quickly after unplugging (omitting the bleeder is a classic compliance miss)                                                                                         |
| Y2 cap            | 2.2 nF                                    | Across primary-secondary, safety-rated (Y2, 5 kV)                                                                                                                                                          |


Digi-Key's 62368-1 guidance is explicit that fuse + thermally-protected MOV (TMOV) is the standard differential-mode scheme — the TMOV has an internal thermal element that opens on overheating.

#### L2 — Power stage: stop device failures from spreading

- Rectifier      IFSM ≥ 30 A (a 1 A bridge such as KBP206 gives 60 A) — do not size on IF(AV) alone
- Bulk cap       22 µF / 400 V, 105 °C long-life; check ripple current
- Primary MOS    600 V, Vds margin ≥ 1.5 × (reflected voltage + spike), plus an RCD clamp
- Transformer    class B/F insulation · triple-insulated wire · margin tape ≥ 3 mm
               ★ an embedded 130 °C thermal fuse in the winding — the only effective defence
                 against a slow inter-winding short cooking the core
- Secondary      SS34 / SB540 (5 A / 40 V Schottky) with copper area for heatsinking

Critical point: a MOSFET usually fails short, turning the primary into a piece of wire. Only the L1 fuse can clear that. L1 and L2 are therefore a series chain — you need both.


#### L3 — Output: stop load faults from destroying the supply

| Protection      | Threshold (5 V / 1 A case)           | Response            | Recovery                   |
| --------------- | ------------------------------------ | ------------------- | -------------------------- |
| SCP             | fast comparator, threshold below OCP | ≤ 5 µs              | hiccup / auto-retry        |
| OCP             | 105–150 % of rating → 1.1–1.5 A      | ms                  | hiccup or constant-current |
| OVP             | 110–130 % → 5.5–6.5 V                | ≤ 10 µs             | latch or auto              |
| OTP             | 80–110 °C at the hot spot            | seconds             | auto with hysteresis       |
| PPTC (optional) | hold current 1.1 A                   | seconds — very slow | self-resetting             |

The response-time column is the one that matters. A PPTC takes 1–2 seconds to trip; relying on it for a short circuit guarantees it arrives too late. It is a second line of defence against sustained overload, while the real short-circuit protection is the controller's cycle-by-cycle current limit.

Prefer hiccup over latch: your equipment is presumably unattended, so auto-recovery after the fault clears is friendlier than "power-cycle to reset". Under a persistent fault, hiccup duty-cycles at 5–10 %, keeping average dissipation low so the supply does not cook itself.

#### L4 — Construction and thermal: stop a fault from becoming a fire

- PCB            FR-4, V-0 (not HB)
- Enclosure      V-1 or better; ≥ 6 mm clearance to hot parts, or a metal shield
- Openings       size-limited by the standard (foreign-object ingress and flame containment)
- Creepage       primary-secondary ≥ 6.4 mm (reinforced insulation, 250 V working — check the
               standard's table); fuse terminals and MOV leads count as mains creepage too
- Potting        optional; helps thermally and with humidity, but blocks repair
- Temperature    touch temperature per the standard's table (plastic enclosures typically ≤ 70 °C)

### "Make the failure mode safe" — four design rules

- ① Use two resistors in series for the feedback divider

    R_top = two in series (e.g. 2 × 47 kΩ)
    One resistor opening → loop loses regulation → output climbs past 12 V → every downstream chip dies
    With two in series, a single open only shifts the output modestly, giving OVP time to act

This is the most frequently missed rule: the failure mode of a divider resistor is an open, and an open drives the output overvoltage.

- ② Do not reuse the regulation optocoupler for OVP
Opto CTR degrades over years — an OVP derived from the same opto can drift its trip point by ~20 % and fail exactly when needed. Give OVP its own branch (separate TL431, or a Zener + SCR crowbar).
- ③ The fuse is not "the overcurrent protection" — it is the last line
Its job is to open after every other protection has failed. Size it on the I²t under fault current versus downstream withstand, not on "normal current times a fudge factor".
- ④ Put the temperature sensor on the heat source
An NTC in the airflow or on the enclosure measures ambient; by the time it trips, the hot spot has already burned. Mount it on the transformer core or the MOSFET heatsink.

### Which hazard class your supply falls into

IEC 62368-1 classifies power sources:

| Class | Power limit | Requirement                                  |
| ----- | ----------- | -------------------------------------------- |
| PS1   | ≤ 15 W      | Low ignition risk, open construction allowed |
| PS2   | ≤ 100 W     | Basic safeguards                             |
| PS3   | > 100 W     | Fire enclosure mandatory, V-1/V-0 materials  |

5 V × 1 A = 5 W puts you in PS1 — good news: no expensive fire-enclosure scheme required, but output short-circuit and single-component short-circuit tests still have to pass. The pass criterion is "no fire", not "no damage".
If you want to relax downstream wiring and enclosure requirements further, design to LPS (Limited Power Source): output stays ≤ 8 A / ≤ 100 VA under any fault. A 5 W design meets that by construction.

### Six tests you must actually run

- ① Output short, 1 hour     Clamp the output, watch enclosure temperature and smoke the whole time
- ② Single-component short   Short, one at a time: rectifier diode, bulk cap, feedback resistor,
                           optocoupler, secondary diode. Every case must be "no fire, no shock" —
                           this is the core abnormal-operation test in 62368-1
- ③ Output overload          1.5 A sustained; verify OCP enters hiccup rather than burning up
- ④ Temperature rise         Worst case: max ambient (e.g. 40 °C) + min input (115 V, highest current)
                           + full load. Watch transformer windings, MOSFET, secondary diode, output cap
- ⑤ Hi-pot                   Primary-secondary reinforced insulation, 3 kVAC / 1 min (per the standard's table)
- ⑥ Surge                    IEC 61000-4-5, 1.2/50 µs: 2 kV differential / 4 kV common mode
                           ★ run this with the final certified parts — never conclude from a substitute
- ② is the one most often skipped and most likely to expose a design. Short one rectifier diode and plenty of designs smoke on the first attempt.

###  Five design mistakes that only show up during a fault

1. Opto ageing drifts the OVP threshold → make OVP independent of the regulation opto
2. Oversizing the sense resistor "for margin" → 0.05 Ω at 5 A already dissipates 1.25 W; you have created a heat source
3. Hiccup retry too fast → repeated hammering of the fault, accumulating stress in the switch; keep off-time at 100–200 ms
4. Latch mode with no documented reset → users hit "unplug for 5 s to restart" and file complaints
5. NTC not on the heat source → OTP always arrives one step late
6. Protection BOM for your 5 V / 1 A supply




## ref 

- [[circuits-dat]]

- [[protection]]

