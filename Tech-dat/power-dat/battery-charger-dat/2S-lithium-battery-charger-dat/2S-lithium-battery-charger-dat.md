
# 2S-lithium-battery-charger-dat


## IF the 2S pack battery does NOT have the BMS board 

These chargers are designed to charge 2S packs with balanced charging and proper voltage/current control.

🔧 Example:

IMAX B6 or similar smart chargers

Connect via the main power plug and balance plug (JST-XH, for example)


## IF the 2S pack battery has the BMS board 

== BMS (Battery Management System) + DC Power Supply


- need 2S BMS == 2S 锂电池保护板（BMS）

Example setup:

Use an 8.4V Li-ion charger (e.g., 8.4V/1A wall charger)

The BMS will:

- Protect against overcharge
- Balance the cells (if it's a balancing BMS)

## ref 

- [[battery-dat]]