# DDS-dat

- [[filter-dat]] - [[DAC-dat]] 


DDS, or Direct Digital Synthesis, is a specific method used by modern signal generators to create these waveforms digitally.


## How DDS Works


Unlike old-school analog generators that use physical capacitors and inductors to oscillate, DDS builds a wave "by the numbers."

1. **Phase Accumulator:** Think of this as a digital wheel spinning at a set speed. The faster it spins, the higher the frequency.
2. **Lookup Table (ROM):** This stores the digital "coordinates" of a perfect wave (e.g., a Sine wave). The accumulator tells the table which coordinate to look at next.
3. **DAC (Digital-to-Analog Converter):** Converts those digital coordinates into an actual voltage level.
4. **Low-Pass Filter:** Smooths out the "staircase" steps from the digital conversion into a clean, smooth wave.




## Chips

### AD9833 — Programmable Waveform Generator

- Module: AD9833 Programmable Waveform Generator Module (Sine, Triangle, Square)
- Link: [[AD-signal-dat]]

Short description: The AD9833 from Analog Devices is a low-power (≈12.65 mW) programmable DDS waveform generator that produces sine, triangle and square waves. It operates from 2.3 V to 5.5 V and is controlled over a simple 3-wire SPI-compatible interface for easy microcontroller integration.

Key specifications

| Parameter | Value |
|---|---:|
| Supply voltage | 2.3 V – 5.5 V |
| Typical power | ≈12.65 mW |
| Waveforms | Sine, Triangle, Square (square via MSB toggling) |
| Maximum output frequency | Up to 12.5 MHz (depending on clock) |
| Interface | 3-wire SPI (compatible with Arduino, DSP) |
| Frequency resolution | 28-bit frequency register (≈0.1 Hz resolution with 25 MHz clock) |
| Output | Unbuffered; typical up to ~0.65 Vpp (sine/triangle) depending on supply and load |
| Special modes | Power-down (SLEEP) mode |

Notes

- The AD9833 provides a frequency tuning word (28-bit) that gives very fine frequency resolution when driven by a stable reference clock (example: ~0.1 Hz resolution with a 25 MHz clock).
- The raw output is unbuffered; add a buffer/amplifier or filtering stage (LPF) if you need larger amplitude or lower harmonic content.

Common uses

- Low-cost frequency and waveform generation for test rigs
- Excitation signals for flow meters and sensors
- Sensing, actuation, and time-domain reflectometry (TDR)
- Impedance spectroscopy and other lab instrumentation


## ref

- [[signal-dat]] - [[DDS-dat]]
