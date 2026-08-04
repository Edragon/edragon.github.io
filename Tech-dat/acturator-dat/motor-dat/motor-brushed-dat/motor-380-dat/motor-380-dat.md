


# motor-380-dat

- [[motor-380-dat]] - [[motor-130-dat]] 

- [[rc-boat-dat]] - [[motor-380-dat]] - [[motor-brushed-dat]] - [[motor-dat]] - [[TA6586-dat]] - [[MC10_10A-dat]] - [[BTS7960-dat]]



## hardware 

Check Hardware & Power Delivery

1. Add Flyback Diodes: Ensure a fast-recovery diode (like an 1N5819 or Schottky diode) is connected in parallel across each 380 motor's terminals (cathode to $+$, anode to $-$). This handles inductive kickback from the motor coils, protecting the MOSFETs and stabilizing low-speed current.

2. MOSFET Gate Drive: Ensure your MOSFETs are fully turning ON at low PWM. If driving them directly from a $3.3\text{V}$ microcontroller pin, use Logic-Level MOSFETs (e.g., IRLZ44N) or an intermediate transistor/gate driver. If the gate voltage is too low, the MOSFET operates in its linear region, dissipating power as heat instead of driving the motor.

3. Decoupling Capacitors: Solder three $0.1\,\mu\text{F}$ ceramic capacitors to each 380 motor (one between motor positive and case, one between negative and case, and one across the motor terminals) to suppress electrical noise and voltage spikes.

## ref 


