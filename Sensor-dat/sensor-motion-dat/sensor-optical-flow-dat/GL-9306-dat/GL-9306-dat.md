


# GL-9306-dat

- [[PMW3901-dat]] - [[GL-9306-dat]] - [[sensor-optical-flow-dat]] - [[sensor-motion-dat]] - [[sensor-dat]] - [[betaflight-dat]]




## ❌ Not recommended — the deciding factor is not the specs, it is the protocol mismatch

### 1. ⭐⭐⭐ Read this rule first: Betaflight recognises only two devices

Betaflight's optical-flow support was **only added in 2026.6** — before that it did not exist at all.

> 📚 Exact wording from r/fpv:
> "BetaFlight doesn't support optical flow until version 2026.6 which is currently in release candidate."

The source file `src/main/sensors/opticalflow.c` has only two cases:

| Enum | Device |
| --- | --- |
| `OPTICALFLOW_MT` | **MicoAir** — MTF series (PMW3901 + ToF) |
| `OPTICALFLOW_UPT1` | **Upixel** — UP-T1-001-Plus |
| `OPTICALFLOW_NONE` | — |

> ⚠️⚠️ Every other optical-flow module (CXOF / bare PMW3901 over SPI / ThoneFlow / LC-302 …) **cannot connect and is not recognised** by Betaflight.

### 2. What the GL-9306 is

_(spec table missing in the original source — to be re-added)_

> ⭐⭐⭐ The full wording from that iNav PR:
> "Tested sensors from Ali Express: SERIAL: (CXOF) GL-9306 - low quality, UP-FLOW-LC-302 - bad sensor, SPI: CJMCU Optical Flow 1.0 - good sensor"

**⚠️⚠️ Against Betaflight: incompatible**

- The GL-9306 speaks the **CXOF** protocol
- Betaflight requires **MSP** (both MTF and UPT1 are MSP)

→ ❌ Wrong protocol → BF does not recognise it → flashing it in still gives you no data.

**Against iNav / ArduPilot: connectable, but quality is doubtful**

- iNav supports CXOF-class serial optical flow → ⭐ technically connectable
- ⚠️ but the measured verdict is "low quality"
- ⚠️ and it has no laser rangefinder → you still need a second sensor for altitude hold

### 3. ⭐ If you really want optical flow, buy this

**Betaflight route — requires firmware 2026.6+**

_(module comparison table missing in the original source — to be re-added)_

**Key configuration points**

- ⭐ You must use **MicoAssistant** to set the module's firmware protocol to **MSP**
  - ⚠️ The factory setting may be Mavlink / Micolink; if you don't switch it, BF will not detect the module
- ⭐ The optical-flow lens faces **down**, and the small arrow on the lens edge points towards the **nose**
- ⭐ Modes: enable ANGLE + POSITION HOLD + ALT HOLD at the same time
- ⭐ Baud rate **115200**

### 4. ⚠️⚠️ The four hard requirements for optical flow (you can buy it and still not be able to fly it)

1. ⚠️ **Illumination > 60 lux**
   Too dark → it fails completely. No flying with the lights off indoors, or at dusk.

2. ⚠️ **The ground must have texture**
   Plain white tiles / solid-colour carpet / glass / water / snow → fails.
   ⭐ If your floor is polished tile, it very likely does not qualify.

3. ⚠️ **Working-distance limit**
   The PMW3901 needs the lens more than 8 cm above the ground.
   ⭐ The VL53L1X version is <4 m; the VL50X version only <2 m.

4. ⚠️ **Speed limit around 7.4 rad/s**
   ⚠️ A 5-inch quad overruns the range easily in wind → the data jumps.
   ⭐ That is why optical flow is basically a "small quad, indoors" game.

### 5. ⭐ Fit against your 7 quads

_(per-quad fit table missing in the original source — to be re-added)_

📌 Ask yourself first:

- Want "no drift indoors" → optical flow makes sense (but first check whether the flight controller runs BF or iNav)
- Want "long range outdoors" → ❌ optical flow is completely useless, go for GPS

📌 One-line verdict

- ❌ **Do not buy the GL-9306.**
- Three hard reasons:
  1. Betaflight only accepts MTF / UP-T1; the GL-9306 is CXOF → incompatible
  2. An iNav contributor measured it as "low quality"
  3. Optical flow but no rangefinder → you still have to buy another sensor for altitude hold
- ✅ If you are buying, buy the **MicoAir MTF-01** (¥150–250): officially supported by BF, built-in 8 m laser, 100 Hz, 4.5 g
- ⚠️ But be clear first: optical flow for indoor position hold, GPS for outdoor long range — the two are not interchangeable




## ref 