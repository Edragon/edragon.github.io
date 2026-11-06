
# breaker-circuit-dat

- [[RCD-dat]] - [[RCBO-dat]]

- [[MCB-dat]] - [[RCBO-dat]] - [[break-circuit-dat]]


In everyday home renovation and distribution-board configuration, these **three devices cover
essentially everything** — they are standard equipment in virtually every household:

## 1. The three core devices

### 1.1 Miniature circuit breaker (MCB) — colloquially the "air switch"

| Aspect | Detail |
|-----------------|-------------------------------------------------------------------------------------------------------------|
| **Role** | The absolute mainstay — carries the vast majority of whole-house protection duties. |
| **Used for** | **Lighting circuits** and **general socket circuits**. |
| **Core function** | **Overload protection** (trips automatically when load exceeds capacity) and **short-circuit protection** (instant trip when conductors touch). |

### 1.2 Residual current circuit breaker with overcurrent protection (RCBO) — the "air switch with earth-leakage protection"

| Aspect | Detail |
|-----------------|-------------------------------------------------------------------------------------------------------------------------------------|
| **Role** | The safety line — mandatory for wet areas and socket outlets in modern installations. |
| **Used for** | **Bathrooms, kitchens, air conditioners**, and **all socket circuits people may touch directly**. |
| **Core function** | Combines **earth-leakage protection** (cuts power within 0.1 s on shock or appliance leakage, preventing injury) with **overload / short-circuit protection**. |

### 1.3 Main switch / isolator — the "master breaker"

| Aspect | Detail |
|-----------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Role** | The "main gate" for the whole house supply. |
| **Used for** | Installed at the very front (incoming side) of the distribution board. |
| **Core function** | Purely **manual physical disconnection**. For full circuit maintenance, long trips away, or grid repairs, pulling it down completely isolates all indoor power and provides safe physical separation. |

---

### 💡 Minimal summary — the classic home distribution-board layout

| Circuit | Device | Why |
|-----------------------------------------------|---------------------------|--------------------------------------------------------------------------------------------------------------|
| **Main incoming** | 1× **main switch / isolator** | Whole-house isolation in one action. |
| **Kitchen, bathroom, all socket outlets** | **RCBO** | Protects against short circuit + overload *and* electric shock. |
| **General lighting** | Plain **MCB** | Overload / short circuit only — RCD is not mandatory on lighting, and omitting it avoids nuisance-trip blackouts. |

## 2. Terminology: RCD, RCBO, GFCI, "air switch"

| Term | Full name / meaning | Where the name is used |
|---------------------|---------------------------------------------------------------------------------------------|-----------------------------------------------------------------------|
| **RCD** | **R**esidual **C**urrent **D**evice — the generic term for any earth-leakage protective device. | Most universal professional name in international and Commonwealth standards (UK, Europe, Australia, etc.). |
| **RCBO** | **R**esidual-current **C**ircuit **B**reaker with **O**vercurrent protection — integrates RCD (leakage) + MCB (short circuit / overload) in one unit. | International / IEC. |
| **GFCI** | **G**round **F**ault **C**ircuit **I**nterrupter — the North American equivalent. | North America: socket-integrated leakage protection is simply called **GFCI**; a panel-mounted leakage breaker is called a **GFCI circuit breaker**. |

**"Air switch" (空气开关) = "air-type circuit breaker"** — that colloquial name comes from its
arc-quenching medium being **air** (as opposed to oil-immersed, vacuum, or SF₆); it is not a
switch with some kind of "air sensing". The official name is spelled out in the national
standard: **GB/T 10963.1** applies to "AC air-break circuit breakers"
(identical adoption of **IEC 60898-1:2015**).

The little push-and-flip block in a household distribution board is simply its miniaturised
form — formally an **MCB (Miniature Circuit Breaker)**.

## 3. What actually makes it trip

Inside there are **two independent tripping mechanisms in series**:

| Mechanism | Principle | Protects against | Speed |
|-----------|--------------------------------|--------------------------------------|------------------------------|
| Thermal | Bimetal strip bends when heated | Overload (current slightly over In, sustained heating) | Slow — minutes to an hour |
| Magnetic | Solenoid force directly trips the latch | Short circuit (current spikes instantly) | Fast — < 0.1 s |

During a short circuit the current can reach **tens of times In**, far too fast for the thermal
element — which is exactly why the magnetic element must exist.

**Arc quenching is a separate job**: separating the contacts creates an arc. The arc chute's
stacked plates stretch, split, and cool it until it extinguishes at **current zero**. *That* is
the step the "air" in "air switch" refers to.

## 4. How to read the numbers on the nameplate

Taking a common **C16 / 6kA** as the example:

| Marking | Meaning | How to read it |
|----------------|------------------------------------------|--------------------------------------------------------------|
| C16 | C curve, rated current In = 16 A | 16 A is the continuous carrying capacity — *not* "trips at 16 A" |
| 6kA | Rated short-circuit breaking capacity Icn | Can safely interrupt a 6000 A short circuit without exploding |
| 1P / 1P+N / 2P | Number of poles | 1P breaks live only; 1P+N has a solid neutral; 2P breaks both |
| 230/400V | Rated voltage | — |

The B / C / D curves differ **only in the magnetic trip threshold** (the thermal part is
identical for all three):

| Curve | Instantaneous trip current | Typical loads |
|-------|----------------------------|----------------------------------------------------------|
| B | 3–5 × In | Lighting, resistive loads, electronic instruments |
| C | 5–10 × In | General socket outlets, ordinary motors, fans, pumps |
| D | 10–20 × In | Large transformers, welders, large motors, X-ray machines |

**Why the distinction matters**: a motor's inrush current reaches **6–8 × In**, so a B curve
trips the moment it starts; conversely, using a D curve on a purely resistive circuit makes
short-circuit protection far too sluggish.

**Two easily-forgotten standard figures** (identical in ABB and Eaton catalogues):

- **1.13 × In** for 1 hour → must **not** trip (conventional non-tripping current)
- **1.45 × In** → must trip **within 1 hour** (conventional tripping current)

So a 16 A breaker will carry 18 A for an hour, but must trip at 23 A.

## 5. ⚠️ The most misunderstood point: it does NOT protect against electric shock

| Device | Protects against | Does not protect against |
|-----------------------|-----------------------------|------------------------------|
| Air switch (MCB) | Overload, short circuit | **Electric shock to people** |
| Residual-current device (RCD / RCCB) | Earth leakage (30 mA class) | Overload |
| RCBO (combined unit) | **Both** | — |

Touch a live wire and a plain MCB will not trip — the current only flows from live through your
body to earth, and the **circuit** current never exceeds In. That job belongs to residual-current
protection.

If your home's main switch is a separate "MCB + RCD" pair, it is the **RCD** leg that saves lives.

## 6. Selection quick reference

| Scenario | Recommendation |
|-------------------------------|-------------------------------------|
| Household lighting | B10 / B16 |
| Household socket outlets | C16 / C20 |
| Air conditioners, pumps | C20 / C25 (check inrush current) |
| Welders, large transformers | D curve |
| Breaking capacity | Domestic ≥ 6 kA; shops near a transformer ≥ 10 kA |
| Main incoming | 2P or 1P+N, matched to the meter capacity |

**Key point**: do **not** pick In by simply doing `power ÷ 220` — that number is only the
running current. You need headroom *and* you must consider inrush current. Common pairings are
**1.5 mm² copper → C10** and **2.5 mm² copper → C16** (installation method matters too: in
conduit, poorer heat dissipation means you must derate).



## ref 
