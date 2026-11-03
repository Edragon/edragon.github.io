


# betaflight-blackbox-dat

- [[betaflight-ports-dat]] - [[betaflight-blackbox-dat]] - [[blackbox-dat]] - [[betaflight-CLI-dat]]
- [[betaflight-blackbox-dat]] - [[betaflight-dat]] - [[flash-dat]] - [[memory-dat]]

## CLI

```text
set blackbox_device = SPIFLASH      # onboard flash (SD card would be SDCARD)
set blackbox_sample_rate = 1/8      # F4 + 8kHz gyro → ~1kHz log rate
set blackbox_mode = NORMAL          # record only after ARM
set blackbox_record_acc = ON        # log accelerometer, useful for vibration analysis
set debug_mode = GYRO_SCALED        # ⭐ log UNFILTERED raw gyro — required for filter/vibration analysis
save
```

## GUI

**Betaflight Configurator → Blackbox tab**

- Logging device = Onboard Flash (SPIFLASH)
- Logging rate   = matching preset
- Debug mode     = GYRO_SCALED
- Save and Reboot

## Verification Checklist

1. Run `version` in the CLI → confirm the firmware version
   - BF 4.3+ uses `blackbox_sample_rate`; older versions use `blackbox_p_ratio`
2. Configurator → Blackbox page
   - "Dataflash" should show **16MB**
   - ⚠️ Shows `NONE` or cannot be read → the firmware lacks the flash driver, need a different target
3. Check the current value of `blackbox_device`

> ⭐️ Good news: onboard flash means Blackbox logging is available.
>
> 16Mbit (2MB) SPI Flash → ⭐️ Blackbox logging works on Betaflight 3.2.5
>
> Tuning tool: record flight data → analyze vibration / filtering / PID
> (older quads can still do professional tuning)

## Analyzer Tools

| Tool | Purpose |
| --- | --- |
| Betaflight Blackbox Explorer (standalone app) | Waveforms, PID response, gyro noise spectrum |
| ⭐️ [blackbox.betaflight.com](https://blackbox.betaflight.com) (web version) | No install needed, just drag the file in |
| `blackbox_decode` | Convert to CSV for your own Python analysis |

## Issue Analysis

The G5 quad still has three items to verify: **motor direction · channel alignment · range test**

⭐️ blackbox + `GYRO_SCALED` directly reveals:

- Whether the four motor outputs are balanced
  (one motor anomalously high → that corner has high drag / weak motor)
- Gyro noise spectrum (to judge whether filtering needs adjustment)
- Presence of excess vibration (prop imbalance / frame resonance)

## Ref


