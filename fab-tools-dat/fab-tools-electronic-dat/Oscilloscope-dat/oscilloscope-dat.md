

# Oscilloscope-dat

An oscilloscope (informally called an `O-scope` or scope) is an electronic test instrument that graphically displays varying electrical voltages as a function of time. It essentially acts as a high-speed visual graphing tool for signals, allowing you to measure properties like amplitude, frequency, rise time, and distortion.



- [[Oscilloscope-dat]] - [[fab-tools-electronic-dat]]

- [[voltage-dat]] - [[voltage-reference-dat]]

- [[signal-dat]] - [[wave-dat]]


## target 

- [[Oscilloscope-dat]] - [[voltage-divider-dat]] - [[sensor-microphone-dat]]

## S2026-02-12-15-13-29.png

![](2026-02-12-15-13-29.png)

- [[STC-dat]]


## usage 

Scope: DC coupling, 1V/div, 5us/div, rising edge trigger ~1.5V

### Quick Setup Guide

**Probe connection:**
- Probe tip → signal pin (e.g. GPIO)
- Ground clip → GND

**Basic settings for digital signals (3.3V logic):**

| Setting | Value | Notes |
|---------|-------|-------|
| Probe | ×1 or ×10 | ×10 preferred for high-speed signals |
| Vertical (V/div) | 1 V/div | For 0~3.3V square wave |
| Coupling | DC | See full voltage levels |
| Trigger | Rising edge, ~1.5V | Stabilize waveform |

**Timebase by signal frequency:**

| Frequency | Period | Timebase | Why |
|-----------|--------|----------|-----|
| 4.096 MHz | 244 ns | **0.1 µs/div** | ~2.4 cycles per division |
| 512 kHz | 1.95 µs | **1 µs/div** | ~1 cycle per 2 divisions |
| 16 kHz | 62.5 µs | **20 µs/div** | ~3 cycles per division |

**Formula:**
$$T = \frac{1}{f}$$

**Expected waveform (clean square wave):**

```
3.3V ─┐   ┌───┐   ┌───┐   ┌───
      │   │   │   │   │   │
      │   │   │   │   │   │
0V   └───┘   └───┘   └───┘
      ← period T →
```

### I2C Bus Debugging

Probe SDA (data) and SCL (clock) separately, set timebase to **10 µs/div**, trigger on falling edge ~1.5V. Look for:
- SCL: clean clock pulses at 100 kHz (period = 10 µs)
- SDA: data transitions between SCL pulses
- Both lines should sit at 3.3V when idle (pull-up resistors present)

### Common Signal Check Table

| Signal | Expected | If Missing |
|--------|----------|------------|
| MCLK | Continuous square wave | I2S/LEDC not driving pin, check code |
| BCLK | Continuous square wave | I2S not started, check `i2s.begin()` |
| LRCK | Frame clock (50% duty) | I2S config issue |
| I2S Data | Bursty data aligned to LRCK | Codec not outputting, check I2C config |
| SDA/SCL idle | 3.3V DC | Missing pull-up resistors (need 4.7kΩ to 3.3V) |

### Same Method for Other Signals

Apply the same setup — probe tip to signal pin, ground clip to GND, DC coupling, 1 V/div, rising edge trigger ~1.5V — then set timebase by frequency:

| Signal | Pin | Frequency | Period | Recommended Timebase |
|--------|-----|-----------|--------|----------------------|
| MCLK | GPIO 6 | 4.096 MHz | 244 ns | **0.1 µs/div** |
| BCLK | GPIO 14 | 512 kHz | 1.95 µs | **1 µs/div** |
| LRCK | GPIO 12 | 16 kHz | 62.5 µs | **20 µs/div** |

$$T = \frac{1}{f}$$

If any pin shows no waveform, that peripheral (I2S / LEDC) is not driving it — recheck code and pin definitions.



## ref 


- [[instrument-dat]] - [[oscilloscope-dat]] - [[multimeter-dat]] - [[tools-dat]] - [[fab-workspace-dat]]





# oscilloscope-dat



## build 

- [[DSO201-dat]]

arduino oscilloscope
https://dbuezas.github.io/arduino-web-oscilloscope/

wave of UARTS Data

- 196678365

![](02-58-18-07-03-2023.png)


## spectrum analyzer 

[Spectrum Analyzer](https://academo.org/demos/virtual-oscilloscope/)

## Selection 

$299 12bit == https://youtu.be/3hyp0-0ns9U?t=680



## test demo 


normal mode - 5V - 50uS 

- [[ES8311-dat]] - [[oscilloscope-dat]]

pin MCLK

![](2026-07-23-15-36-27.png)

pin LRCK 

![](2026-07-23-15-37-52.png)

pin SCLK 

![](2026-07-23-15-38-21.png)

## ref 

- [[fab-tools-dat]]