
# RC-TX-dat

- [[ELRS-dat]]

- [[Flysky-dat]] == iBUS (FlySky)

- FRsky 



## Long-Range RC Links 

| System / Peer         | RF Type / Band                                 | Output Protocol (RX→FC)   |          Typical TX Power (selectable) |                                        Representative Line-of-Sight Range* | Notes                                                              |
| --------------------- | ---------------------------------------------- | ------------------------- | -------------------------------------: | -------------------------------------------------------------------------: | ------------------------------------------------------------------ |
| **ExpressLRS (ELRS)** | LoRA-style / 2.4GHz & 900MHz                   | CRSF (serial)             |             10 mW — 1 W (hw dependent) |                 **10–40+ km** (records much higher under ideal conditions) | Open-source, very low latency, configurable packet rates.          |
| **TBS Crossfire**     | Proprietary FHSS / 900MHz (main)               | CRSF (serial)             |          10 mW — 1 W (regional limits) |   **10+ km** typical (can exceed 20–30 km with high power & good antennas) | Mature long-range system, excellent link robustness.               |
| **TBS Tracer**        | 2.4GHz Tracer (LoRa + Crossfire engine)        | CRSF (serial)             |      10 mW — 100 mW (device dependent) | **~15+ km (15 mi+)** advertised for Nano RX / real results depend on setup | Low latency (250 Hz uplink/downlink), compact receivers.           |
| **FrSky R9 (R9M/R9)** | Narrowband / 868 / 915 MHz                     | SBUS (or CRSF on some RX) |         10 mW — 1 W (module dependent) |                        **~5–20+ km** depending on power/antenna/conditions | Widely used long-range option on 868/915 MHz bands.                |
| **ImmersionRC Ghost** | LoRa-style modulation / 2.4GHz                 | Serial (proprietary)      |   Device dependent (regulatory limits) |                           **10s of km** claimed / >27 km independent tests | High sensitivity LoRa mode, aims at race + long range.             |
| **DragonLink**        | Narrowband HF/UHF / 433 / 433-900 MHz variants | Serial / telemetry modem  | Typically high power (commercial kits) |                   **50+ km** (commercial claims / long-range aviation use) | Professional/RC hobby long-range system, heavier and more complex. |




## ref 

- [[RC-dat]]