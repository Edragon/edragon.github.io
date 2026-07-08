

# motor-driver-dead-time-protection-dat


- [[motor-driver-dead-time-protection-dat]] - [[motor-driver-dat]] - [[ELRS-TX-setup-motor-dual-dat]] - [[motor-driver-design-dat]] - [[mosfet-dat]]    





The power capacitor did not explode, but the positive and negative terminals are shorted, and the MOSFET gates are also shorted.

This phenomenon confirms that a **"Shoot-Through" / "Cross-Conduction"** short circuit occurred in the H-bridge at the moment of switching, leading to an **"Avalanche Breakdown"** of the internal MOSFETs.

When a multimeter detects a short between the power terminals (V+ and GND) and the MOSFET gates, it indicates catastrophic physical destruction inside the chip.

### 1. Why do "Gate Shorts" and "Power Supply Shorts" occur simultaneously?

Inside a micro-motor driver chip (H-bridge), the High-side (Top MOSFET) and Low-side (Bottom MOSFET) are connected in series between the positive and negative power rails.

*   **"Add" Mixing Induced Shoot-Through:** When steering with "Add" mixing, IN1 and IN2 alternate between high and low signals within microseconds. Since basic driver boards lack hardware **"Dead-time" protection**, the high-side and low-side FETs turn on simultaneously for a fraction of a second.
*   **Silicon Melting:** Instead of passing through the motor's resistance, hundreds of amperes from the battery surge directly through both MOSFETs. This generates intense localized heat that instantly melts the silicon dies together.
*   **Gate Damage from High Voltage:** Once the Drain (high voltage) and Source (low voltage) fuse together, the high battery voltage pierces the extremely fragile Gate Oxide layer. This causes the Gate pins—which receive signals from the receiver—to short directly to the power rails.

**⚠️ Warning: Secondary Damage to the Receiver**
A gate short is extremely dangerous because battery voltage can backfeed through the damaged signal lines into your ESP8285 receiver, potentially frying its MCU. Before connecting a new driver board, use a multimeter to check pins 1-4 on the receiver to ensure they are still functional.

### 2. Why didn't the capacitor explode?

The capacitor is rated for 35V, while your battery (typically 1S-3S, ~4.2V - 12.6V) is far below its limit. During a shoot-through event, the current follows the extremely low-impedance path through the melting MOSFETs. The chip effectively becomes a "copper wire" for a few microseconds, absorbing all the energy before the voltage can spike high enough to burst the capacitor.

### 3. Ultimate Solution for a Permanent Fix

The burned board is non-repairable and must be replaced. To ensure the new board never fails, apply these two adjustments:

*   **Step 1: Modify Transmitter Mixing (Must use "Multiply")**
    Switch your RadioMaster Pocket to the **Multiplex = Multiply** scheme. By using Multiply, the reverse pin is physically locked at 0V while moving forward. No matter how aggressively you steer, the transmitter will never command both IN1 and IN2 to be high simultaneously, eliminating the root cause of H-bridge shoot-through.
*   **Step 2: Hardware Upgrade (Optional)**
    If purchasing a new driver, avoid "naked" H-bridge chips like the MX1508. Consider micro-driver boards with built-in **dead-time/hardware interlocking** (e.g., modules based on **AT8236**, **DRV8871**, or **DRV8701**). These chips feature internal logic that forces a "brake" or "shutdown" if both IN1 and IN2 are high, preventing shoot-through at the hardware level.

- [[AT8236-dat]] - [[DRV8871-dat]] - [[DRV8701-dat]] - [[motor-driver-dat]]


## ref 


