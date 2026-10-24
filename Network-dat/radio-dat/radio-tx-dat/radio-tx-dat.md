

# radio-tx-dat

- [[radio-dat]] - [[radio-tx-dat]] - [[radio-rx-dat]]  - [[radiomaster-pocket-dat]] 



## 1. How much power do you have

Official manual (verbatim):

> "The POCKET's built-in ELRS has an adjustable range of 25 mW–250 mW, with a maximum power of 250 mW.
> For use outside extreme conditions, it is recommended to limit power to 100 mW and use a 500 Hz rate."

| Item | Value |
|---|---|
| Adjustable steps | 25 / 50 / 100 / 250 mW |
| Upper limit | ⭐ 250 mW (24 dBm) |
| Measured (Oscar Liang) | 7.3 / 25 / 60 / 113 / 270 mW |
| Official recommendation | 100 mW + 500 Hz for everyday flying |

**⚠️ Version differences (critical)**

- FCC version (China / Americas) → full 250 mW unlocked ✅
- LBT version (EU / CE) → firmware-locked at 100 mW ❗
  - → no matter what you set, it stays at 100 mW unless you flash FCC firmware

## 2. How to configure it (EdgeTX → ELRS Lua script)

**How to get there**

EdgeTX main screen → press `SYS` → find ExpressLRS → enter
(the script lives on the SD card at `/SCRIPTS/TOOLS/ExpressLRS.lua`; the Pocket normally ships with it)

**Four key settings**

1. **Packet Rate** ← the biggest lever
2. **Max Power**
3. **Telem Ratio**
4. **Dynamic**

> *Source note: the original document has only a placeholder here instead of a settings table — the four items above are the ones referenced throughout the rest of this page.*

## 3. ⭐⭐ The real ranking for gaining range (don't just stare at power)

| # | Measure | Gain | Range effect | Cost | Note |
|---|---|---|---|---|---|
| ① | Packet rate 500 Hz → 50 Hz | +10 dB | ×1.78 | ¥0 | ⭐⭐ biggest lever |
| ② | RX antenna external / away from interference | +3~8 dB | ×1.3-1.6 | ¥0 | ⭐⭐ best value |
| ③ | Ground position (raise it / open area / don't turn your back) | +3~6 dB | ×1.2-1.4 | ¥0 | |
| ④ | TX power 100 mW → 250 mW | +4 dB | ×1.27 | ¥0 | ⭐ free but a small gain |
| ⑤ | Swap the antenna (Pocket can't — see below) | +6~12 dB | ×1.4-2.0 | — | ❌ |

> ⭐ The first four you can do right now, all free, together worth more than range ×2.5 —
> while maxing power alone (100 → 250 mW) gives only ×1.27

**Reference data:** Oscar Liang's measurements — on 2.4G, 100 mW already flies 33 km (with a good antenna and a low packet rate), so power was never the weak link.

## 4. ⚠️ Two hard limits of the Pocket

**① The antenna is internal and cannot be swapped directly**

The Pocket's ELRS antenna is hidden inside the body (there is no external SMA connector).

```
Want a high-gain antenna = you must open the radio and convert it to an IPEX connector
  → modding guides exist (Bilibili); some people even build "the world's smallest 1 W internal RF module"
  → ⚠️ but opening it up = lost warranty + risk of damage
```

> ⭐ The safer route: don't touch the body, just plug in an external module (Nano bay):
> Ranger Nano 1 W (¥290 / 48 g / plug-in)

**② The real cost of running 250 mW**

- Single 18650 cell → noticeably faster drain (especially long flights at 50 Hz)
- Heat (the internal antenna has no heat-sinking structure)
- Even the manufacturer itself recommends 100 mW for everyday flying

> ⭐ Suggestion: use 250 mW only for long-range flights; 100 mW is plenty day to day

## 5. Concrete steps (just follow them)

1. Check the firmware: `SYS` → version info, note the ELRS version (3.x recommended)
2. Open the Lua: `SYS` → ExpressLRS → wait for it to read the module info
3. Set **Packet Rate** = 50 Hz
4. Set **Max Power** = 250 mW
5. Set **Telem Ratio** = Std (or 1:64)
6. Set **Dynamic** = Off (for long range) / or bind it to an AUX12 switch
7. Confirm BIND status (the Lua shows Binding / Connected)
8. Before takeoff, check the Betaflight receiver page: LQ should be close to 100%

## 6. ⭐ How to verify the settings really took effect

**Method A (ground range test):**

```
Power up the aircraft and leave it on the ground → walk away with the radio
Record the distance where LQ falls to 70% / 50%
→ measure once before and once after changing the packet rate; the gap is visible (expect 1.5–1.8×)
```

**Method B (read it in the Lua):**

```
The ExpressLRS script screen shows the actual current TX Power step
⚠️ Note: with Dynamic on it shows the current dynamic value, not Max
```

**Method C (in flight):**

```
Put RSSI and LQ on the OSD and watch LQ during long-range flights
⭐ your notes already follow this habit (the 400 mW video -50 → -80 dBm curve)
```

## 📋 One-sentence summary

Your power: 25 / 50 / 100 / 250 mW adjustable, 250 mW max (the LBT version is locked at 100 mW).

The correct order for gaining range:

```
① Packet rate 500 Hz → 50 Hz   (+10 dB, ×1.78)  ⭐ do this first
② External RX antenna          (+3~8 dB)        ⭐ do this second
③ Power maxed at 250 mW        (+4 dB, ×1.27)   do this last
```

> ⭐ The Pocket's antenna cannot be changed — for higher gain the only option is an external Ranger Nano (1 W).
> But honestly: 50 Hz + a good antenna + 250 mW already lets you fly FPV farther than you dare to.





   ## ref 


