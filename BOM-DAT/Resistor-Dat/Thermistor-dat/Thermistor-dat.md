
# Thermistor-dat

= （thermal + resistor)

- PTC 
- NTC 

NTC 5D-15 

An NTC thermistor is a temperature-dependent resistor whose resistance decreases as temperature increases.

Basic behavior

    Temperature ↑  →  Resistance ↓
    Temperature ↓  →  Resistance ↑


## usage 

## Resistor Classification
* **Component Type**: MELF (Metal Electrode Leadless Face) surface-mount resistor.
* **Package Style**: Micro/Mini MELF cylindrical package.
* **Estimated Resistance**: Approximately **47 Ω** (based on standard color-code reading).

---

## Primary Functions at AC Mains Input

### 1. Inrush Current Limiting & Fusible Protection
* **Inrush Suppression**: Limits the high initial surge current when power is turned on as the main bulk capacitors charge up.
* **Fail-Safe Fuse Action**: Specially coated MELF resistors in input stages often act as flameproof fusible resistors. If a downstream component (such as a rectifier bridge or switching MOSFET) short-circuits, this resistor safely blows open to prevent fire and catastrophic damage.

### 2. X-Capacitor Bleeder Resistor
* **Discharge Path**: Connected across the AC lines or in parallel with safety X-capacitors.
* **Shock Prevention**: Bleeds off residual high voltage (up to 300V+ DC) from the input capacitors within seconds after unplugging the device, protecting users from electric shocks when touching the plug pins.

### 3. Surge & EMI Snubber / Damping
* **Transient Absorption**: Works in conjunction with MOV (Metal Oxide Varistor) or snubber capacitors to dampen high-voltage spikes and electromagnetic interference (EMI) originating from the grid.

---

## Troubleshooting & Replacement Guidelines

* **Continuity Check**: Measure R3 using a multimeter (Ohm/Continuity mode). If it reads open circuit ($\infty$), it likely acted as a fuse and blew due to a downstream short circuit.
* **Safety Replacement Warning**: **Do NOT bypass or replace with a standard 0 Ω jumper or basic SMD chip resistor.** Always use an equivalent **anti-surge / fusible (flameproof)** MELF resistor to maintain proper safety protection.


### 1️⃣ Inrush current limiting (very common)

- Placed in series with AC input
- Cold → high resistance → limits surge current
- Heats up → resistance drops → normal operation


Typical applications:

- SMPS power supplies
- AC adapters
- LED drivers
- Motor controllers

connect 

    AC L ── NTC ── Bridge ── Bulk Capacitor


### 2️⃣ Temperature sensing

Used as a temperature sensor

Very sensitive, non-linear response

Used in:

- Battery packs
- Chargers
- Thermostats
- 3D printers
- HVAC systems


## ref 

- [[resistor-dat]]