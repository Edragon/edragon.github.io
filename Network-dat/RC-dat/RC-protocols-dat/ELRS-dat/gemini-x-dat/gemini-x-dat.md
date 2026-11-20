# Gemini X

- [[gemini-x-dat]] - [[radiomaster-dat]] - [[ELRS-dat]] - [[tech-advanced-dat]]

## Compatibility

✅ **ExpressLRS is an open protocol and has no vendor lock-in.**

The official ExpressLRS setup documentation states:

> “Via Lua, set both your TX and RX Antenna Modes to Gemini.”

- **RadioMaster Nomad** (dual LR1121) is compatible with **OpenRX-Gemini** (ESP32-C3 + dual LR1121).
- Their hardware architectures match, so GemX mode can operate correctly.
- A RadioMaster transmitter does not have to use a RadioMaster receiver.

## 1. Required Consistency Settings

⚠️ All of the following settings must match. Otherwise, the transmitter and receiver may fail to establish or maintain a link.

| Item | Requirement | Details |
|---|---|---|
| Firmware | ELRS 3.5 or later | Required for Gemini/GemX |
| Regulatory Domain | The same domain on both sides | FCC 915 MHz versus EU-LBT 868 MHz; mismatched domains can prevent binding |
| Antenna Mode | Gemini on both sides | Setting only the TX or RX to Gemini is not sufficient |

> ⚠️ Under X-modes such as X100 Full Res or X150, the Antenna Mode may be locked to Gemini.

## 2. GemX Receiver Requirements

⚠️ **A GemX-capable receiver is mandatory.**

The official documentation states:

> “A GemX-capable receiver will be required for this mode, and any single-band receiver will not get a sync.”

- ✅ OpenRX-Gemini uses an ESP32-C3 and 2× LR1121 modules, so it meets the requirement.
- ❌ The existing aircraft with ordinary 2.4 GHz ELRS receivers cannot synchronize in GemX mode.

### Using a Gemini transmitter with a single-antenna receiver

The official documentation explains:

> “The Receiver will only get the signal from the TX it has synchronized with. The other TX will still transmit uselessly in the other frequency.”

- In earlier ExpressLRS versions, this may waste approximately half of the transmitted power.
- ExpressLRS 4.0 and later can automatically manage this behavior through the TX module.

## 3. Gemini Does Not Increase Range

⭐⭐⭐ **This is the most important limitation.**

The official ExpressLRS FAQ, “Will Gemini increase my range?”, says:

> “No. The packet sensitivity remains the same for the RF Mode used. Gemini will help maintain a higher LQ to the point of failsafe. However failsafe will still happen at approximately the same distance e.g. the moon.”

- Gemini maintains higher Link Quality (LQ) for longer.
- It does not improve packet sensitivity.
- Failsafe will still occur at approximately the same distance.
- Gemini is not a range-extension feature.

This matches the findings of the FirstQuadcopter tests referenced elsewhere.

## 4. Improved Telemetry Link

⭐⭐ **Gemini can improve telemetry reception, even when GemX mode is not used.**

The official documentation states:

> “A Gemini TX has the advantage of not only sending simultaneous packets, but also receiving simultaneous packets. Or when used in single antenna mode (or switch mode) both antennas will listen for the same TLM packet…”

> “So your TLM link becomes stronger with fewer missed packets, even when not used in Gemini mode and with single antenna receivers.”

Key point: even with a non-Gemini mode or a single-antenna receiver, both antennas on the transmitter can listen for the same telemetry packet.

This is useful for:

- OSD RSSI and LQ data
- GPS telemetry
- MAVLink
- Bidirectional control links

Therefore, purchasing a Nomad may improve telemetry performance even if the aircraft receivers are not replaced.

## 5. Users Who Benefit

| User | Benefit |
|---|---|
| Freestylers | Better control in high-RF-noise environments and around interference |
| Racers | More stable links when six to eight pilots fly together and many transmitters are operating nearby |
| Telemetry users | Simultaneous bidirectional reception means fewer lost telemetry packets |
| Airport/MAVLink users | Losing a single link packet can otherwise cause many downstream data packets to be lost |

## 6. OpenRX-Gemini Project Status

⚠️ OpenRX-Gemini is an open-hardware project that still has several practical limitations.

| Item | Status |
|---|---|
| Hardware license | CERN-OHL-S-2.0, a strongly protective open-hardware license |
| Latest revision | Rev 2.1 (2026-09-01) |
| Repository activity | 12 stars, 15 forks, and 3 contributors; a small community |
| Project status | **status-alpha** |
| Repository contents | `firmware/` contains ELRS RX firmware; `hardware/` contains KiCad projects |
| Ready-made product | `opendrone.be/products/openrx` provides pairing information |

### Practical limitations

1. **Open hardware is not necessarily easy to obtain.**
   - You may need to manufacture and assemble the PCB yourself.
   - The LR1121 uses a QFN package, making manual soldering difficult.

2. **The project is in alpha status.**
   - It is still experimental and may contain defects or compatibility problems.

3. **The community is small.**
   - With only three contributors, troubleshooting help may be limited.

### Recommended option

- [[radiomaster-DBR4-dat]] - [[radiomaster-dat]] - [[LR1121-dat]] - [[QFN-dat]] - [[ELRS-dat]]

- ⭐ **For reliable GemX operation:** Purchase a complete product such as the RadioMaster DBR4.
- ⭐ **For experimentation or learning:** OpenRX-Gemini is a useful project to assemble and study.

## Conclusion

✅ **Nomad and OpenRX-Gemini are technically compatible.**

To make them work together:

1. Both devices must run ELRS 3.5 or later.
2. Both devices must use the same Regulatory Domain: FCC 915 MHz or EU-LBT 868 MHz.
3. Gemini must be configured on both the transmitter and receiver.
4. The receiver must use the matching ELRS target from the firmware repository.

Practical limitations remain:

- The project is at alpha status.
- Open hardware may require custom PCB fabrication and assembly.
- LR1121 QFN parts are difficult to solder manually.

> **Official statement:**
>
> “Will Gemini increase my range? — No.”
>
> Gemini is intended to improve **LQ stability**, not extend flight range or move failsafe farther away.

## Reference

