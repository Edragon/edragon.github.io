


# energy-dump-dat


- [[energy-dump-dat]] - [[rc-snubber-dat]]

"Flyback capacitor + resistor" is an RC snubber. It is not a decoration: an inductive load generates a voltage spike the instant you switch it off, and a capacitor alone makes the spike worse, not better.
1. How violent the spike is
Inductor current cannot change instantly: V = L·di/dt.
Take a 24 V relay coil: L ≈ 1 H, I = 40 mA, interrupted in 1 µs:
V = 1 H × 0.04 A / 1 µs = 40,000 V  (theoretical)
Parasitic capacitance and the switch's avalanche behaviour clamp that to a few hundred volts in practice — but a few hundred volts is already enough to exceed a MOSFET's Vds, destroy a BJT, draw an arc across relay contacts and carbonise them.
An inductive load must be given a path to dump that energy. An RC network is only one of the options.




2. Four ways to do it — picking the wrong one bites you

- [[diode-freewheel-dat]] - [[diode-zener-dat]] - [[Varistor-dat]] - [[TVS-dat]]

Method	Where it fits	Upside	Cost
Freewheel diode	DC (first choice)	Cheap, clamps at 0.7 V	Slow release: current decays as L/R, a relay can take 5–10× longer to drop out
Diode + Zener	DC, fast release needed	Clamps at Vz + 0.7, releases quickly	The Zener absorbs all the energy — must be sized for it
RC snubber	The only option for AC; also usable on DC	Bidirectional, doesn't reverse current, kills contact arcing	Burns energy every cycle — loss scales with frequency
MOV / TVS	AC contacts	High energy, fast	Degrades with age, loose clamping tolerance


Key fact: you cannot use a diode in an AC circuit — it short-circuits on the reverse half-cycle. Littelfuse puts it plainly:
Quote (DC) inductive circuits typically use a diode to prevent the high voltage… However, a diode cannot be used in an alternating current (AC) circuit. AC arc suppression requires the use of a metal-oxide varistor (MOV), a bidirectional transient voltage suppressor (TVS) diode, or an RC suppression network. An RC suppression network is also called a snubber.
So your RC is most likely on the AC side (contacts / relays / contactors), or on DC where fast drop-out matters more than efficiency.



## ref 