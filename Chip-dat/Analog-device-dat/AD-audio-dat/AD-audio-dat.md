# AD-audio-dat


## MAX97220

The MAX97220 is a high-fidelity DirectDrive® headphone amplifier and differential line driver from Analog Devices, designed for portable audio applications. It removes the need for large output coupling capacitors by using an on-chip charge pump to create a negative rail, allowing the outputs to be biased around ground.

Quick summary

- Input voltage: 2.5 V – 5.5 V
- Typical power consumption: ≈12.65 mW
- Output: DirectDrive (no large output caps required)
- Commonly used with DACs (example: CX31993) in USB-C to 3.5 mm DAC/amp dongles

Key specifications

| Parameter | Value |
|---|---:|
| Supply voltage | 2.5 V – 5.5 V |
| Typical power | ≈ 12.65 mW |
| Headphone output (typ.) | 125 mW into 32 Ω (VCC = 5 V) |
| Line output | 3 V RMS into 1 kΩ (VCC = 5 V) |
| High-impedance output | 2 V RMS into 600 Ω (VCC = 3.3 V) |
| Supported headphone impedance | Up to ~300 Ω (depends on required SPL) |
| THD+N | Low (typical values depend on operating point) |
| Turn-on time | A/C/E versions: ~5.5 ms; B/D versions: ~130 ms |
| Package | 16-pin TQFN (3 mm × 3 mm) |

Features

- DirectDrive® architecture (on-chip negative rail via charge pump)
- Eliminates large distortion-inducing output coupling capacitors
- Low noise and low THD+N
- Click-and-pop suppression circuitry
- Power-down (shutdown) modes for low-power applications

Typical applications

- USB-C to 3.5 mm DAC/amp dongles (paired with DACs such as CX31993)
- Portable audio players and mobile devices
- Set-top boxes and TV audio (slower turn-on variants)
- High-impedance headphone driving and balanced line outputs

Variants and notes

- Fast turn-on versions (A/C/E) are optimized for headphone use (~5.5 ms). Slower turn-on versions (B/D) are intended for applications like set-top boxes where longer startup is acceptable (~130 ms).
- The raw outputs are DirectDrive and may still require output filtering or buffers depending on system load and EMI requirements.



## ref 

- [[analog-device-dat]] - [[AD-audio-dat]]