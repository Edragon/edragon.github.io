
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