# PWM-motor-control-dat


## code 


- [[wifi-dat]]




## Basics

A brushed DC motor (e.g. a 130-size motor) has speed that mainly depends on:
- the average voltage applied across the motor
- the mechanical load on the motor

The essence of PWM (Pulse Width Modulation) is:
- using a high-frequency switching square wave to change the effective (average) voltage seen by the motor

For example (assuming a 5 V supply):

| PWM duty | Equivalent voltage | Speed      |
|---------:|-------------------:|------------|
| 0%       | 0 V                | stopped    |
| 25%      | ≈1.25 V            | very slow  |
| 50%      | ≈2.5 V             | medium     |
| 100%     | 5 V                | full speed |

Note: due to rotor inertia and the motor's inductance, the motor won't follow the PWM pulses as on/off flashes — it rotates smoothly.

---

## Warning: Do NOT connect a PWM pin directly to the motor

Very important:

❌ Do NOT connect an MCU / Arduino / ESP PWM output pin directly to a 130 motor.

Reason:
- A 130 motor can draw a start (stall) current of around 1 A to 2 A.
- A PWM pin can only source/sink a few milliamps.
- Connecting directly will likely burn the IO pin or cause the MCU to reset.

---

## Recommended Solutions

### Solution 1 — PWM + N-channel MOSFET (most recommended)

Schematic (conceptual):

```
MCU PWM --- R_gate (100 Ω ~ 1 kΩ) --- Gate (N-MOSFET)

Drain --- Motor --- +V

Source --- GND
```

Motor: reverse (flyback) diode across motor terminals (cathode to +V, anode to MOSFET drain)

Key points:
- Use a logic-level N-channel MOSFET (fully enhances at logic-level gate voltage): examples — AO3400, IRLZ44N, IRLZ34N.
- Add a flyback diode across the motor to clamp inductive spikes: examples — 1N5819, SS14 (Schottky), FR107.
- Place a small gate resistor (100 Ω ~ 1 kΩ) between the MCU PWM pin and the MOSFET gate to reduce ringing and limit gate charge current.
- PWM frequency: typically 1 kHz ~ 20 kHz for small DC motors.

Notes on diode orientation: the diode should be placed reverse-biased across the motor in normal operation (cathode to +V, anode to the MOSFET side) so it conducts when the MOSFET switches off.


### Solution 2 — PWM + Motor Driver IC (easy, supports direction)

Suitable for forward/reverse control plus speed control.

Common driver ICs and notes:
- L298N: old design, significant power loss (drop), but widely used.
- TB6612FNG: very suitable for 130 motors (low loss, easy to use).
- DRV8833: efficient for low-voltage motors.

Control method:
- PWM -> EN (enable)
- IN1 / IN2 -> direction control


### Solution 3 — Relay (NOT suitable for PWM)

- Relays can only switch on/off and are not suitable for high-frequency PWM.
- Using relays for PWM will cause contact chattering and quickly wear or burn the contacts.

---

## Summary

- Use a MOSFET or motor driver IC between the MCU PWM pin and the motor.
- Always include a flyback diode across the motor.
- Choose a logic-level MOSFET and appropriate PWM frequency (1 kHz–20 kHz).
- Avoid driving motors directly from MCU IO pins or using relays for PWM.

## PWM frequency recommendations (important)

| Frequency | Result |
|---------:|--------|
| < 200 Hz | Motor will produce audible humming |
| 500 Hz – 5 kHz | Usable |
| 5 kHz – 20 kHz | ✅ Best (inaudible) |
| > 30 kHz | MOSFET heating increases |


## Common problems and explanations

Q: When I change PWM a little, the motor speed suddenly jumps?

Possible causes:
- Motor starting voltage threshold (there is a minimum voltage needed to overcome static friction)
- Duty cycle too low to overcome friction or load
- MOSFET is not a logic-level type and doesn't fully turn on at the MCU's gate voltage

Solutions:
- Ensure a minimum PWM duty (e.g., >= 20%) for reliable startup
- Implement a soft-start by ramping PWM gradually
- Use a proper logic-level MOSFET or a suitable motor driver IC


## ref 

- [[motor-driver-dat]]