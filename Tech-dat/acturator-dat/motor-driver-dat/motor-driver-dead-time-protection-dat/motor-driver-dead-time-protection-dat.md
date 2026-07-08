

# motor-driver-dead-time-protection-dat


- [[motor-driver-dead-time-protection-dat]] - [[motor-driver-dat]] - [[ELRS-TX-setup-motor-dual-dat]] - [[motor-driver-design-dat]] - [[mosfet-dat]]    




## issue 

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

## fix 

### Fix 1: Switch from "Add" to "Multiply" (The Safest Software Fix)

The safest way to handle tank steering on IN1/IN2 setups is to use **Multiplex ➔ Multiply (*)** instead of **Add** for your steering lines.

When you use Multiply, steering doesn't try to force the opposite pin high or fight the throttle physics. Instead, it acts like a brake—it smoothly reduces power to one side to make a turn. 

Change your **Line 2** mixing values to this:

```text
CH1 (Left Fwd): Line 2 ➔ Source = Ail, Weight = -100%, Multiplex = Multiply
CH3 (Right Fwd): Line 2 ➔ Source = Ail, Weight = 100%, Multiplex = Multiply
```

(Do the same for the reverse channels CH2 and CH4, matching the steering polarities).

**Why this fixes it:** If you are moving forward, IN1 is active and IN2 is completely dead at $0\text{V}$. When you steer, **Multiply** simply reduces the voltage on IN1 toward $0\text{V}$ to slow that track down. It never commands IN2 to turn on while moving forward, eliminating shoot-through short circuits entirely!


To guarantee **100% absolute hardware protection** and prevent blowing another MOSFET or driver board, you need layered hardware containment. This setup physically protects your components from configuration mistakes, microsecond timing glitches, and mechanical stalls.

### extra fix 

#### 🧱 1. Safe Hardware Interlocking (Eliminates Shoot-Through)

Relying entirely on remote control mixing leaves a tiny risk during receiver boot-up or unexpected signal losses. The single best defense is swapping out unprotected, fragile H-bridge chips (like the MX1508) for chips with **inherent cross-conduction protection**:

* **DRV8871 / DRV8871-Q1:** Features automatic shoot-through protection and dead-time logic. Even if your software accidentally sends 3.3V to both `IN1` and `IN2` at the exact same time, the chip safely switches to internal brake mode instead of short-circuiting.
* **AT8236:** Includes a hardware input interlock system and dead-time insertion, making it completely immune to software configuration errors.

---

#### ⚡ 2. Over-Current Isolation (Resettable Fuses)

If a motor stalls or gets stuck mechanically, its current draw spikes instantly by $5\times$ to $10\times$, melting silicon before you can react.

* **Action:** Solder a **PPTC Resettable Fuse (Polyfuse)** in series onto the positive power wire (`V+`) going to each motor.
* **How it works:** When current spikes past a safe limit (e.g., matching your motor's nominal draw, like 2A), the polyfuse turns highly resistive and chokes the current down instantly. Once it cools down, it resets automatically. No blown MOSFETs.

---

#### 🛡️ 3. Optocoupler Signal Isolation (Protects the Receiver)

When a driver board shorts, high voltage from the main battery line back-feeds through the burned Gate pins and destroys the receiver. 

* **Action:** Wire a small **4-channel Optocoupler Isolation Module** (like a `TLP281` or `PC817` board) between the receiver's physical output pins and the driver board's inputs.
* **How it works:** The receiver passes signals across an actual physical air gap inside the chip using a built-in infrared LED. There is **zero direct electrical connection** between the two sides. If the driver board fails, the damage is 100% contained—your ELRS receiver remains completely safe.

---

#### 📋 The Ultimate "Zero-Risk" Wiring Layout



```text
 [ Battery ] ──► [ Polyfuse ] ──► [ Safe Driver Board (DRV8871/AT8236) ]
                                      ▲                  ▲
                                      │ (IN1)            │ (IN2)
                                 ┌────────────────────────────┐
                                 │   4-Channel Optocoupler    │
                                 └────────────────────────────┘
                                      ▲                  ▲
                                      │ (CH1)            │ (CH2)
                                 [ ELRS 6xPWM Receiver Pinout ]


```

Software: Keep your RadioMaster Pocket configured to Multiply (*) mixing.

Signal: Insert a cheap Optocoupler module between your receiver and driver. - [[Optocoupler-dat]]

Driver: Swap out to a `DRV8871` or `AT8236` based driver board.

Power: Add a Polyfuse to the motor lines. - [[fuse-dat]]




## ref 


