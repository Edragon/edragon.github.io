
# SDR1125-rover-1


- [[SDR1125-rover-1.ino]]

CRSF over UART (RX=17, TX=16). All channels send PWM-style 1000–2000 µs.

| Channel | Function                   | Command                                                               |
| ------- | -------------------------- | --------------------------------------------------------------------- |
| CH1     | Steering (Left/Right)      | 1000 = left · 1500 = center · 2000 = right (differential mix)         |
| CH3     | Throttle (Speed magnitude) | 1000 = 0 · 2000 = max (scaled by speed mode)                          |
| CH5     | MOSFET 1                   | >1500 = ON · <1500 = OFF                                              |
| CH6     | Direction switch           | 1000 = Forward · 1500 = Stop · 2000 = Backward                        |
| CH7     | Speed mode                 | <1300 = Low (cap 85) · <1700 = Mid (cap 170) · ≥1700 = High (cap 255) |
| CH8     | MOSFET 2                   | >1500 = ON · <1500 = OFF                                              |
| CH2     | Servo 1 (GPIO11)           | 1000–2000 → 0–180° (1500 = 90° center)                                |
| CH10    | Servo 2 (GPIO12)           | 1000–2000 → 0–180° (1500 = 90° center)                                |

## Operating notes
- Drive: CH3 sets speed amount, CH6 picks direction. Center CH6 = motors stopped.
- Steering CH1 mixes into left/right motor speeds.
- Servos start at 90° and hold position on failsafe.
- LED: Green = forward, Red = backward, Blue = turning, Off = stopped.
- Failsafe (link lost): MOSFETs OFF, motors stop, LED off.

## Hardware pins
- Motors: DRV8871 — M1 (GPIO15/18 left), M2 (GPIO7/8 right)
- Servos: SERVO1 = GPIO11, SERVO2 = GPIO12 (reserved: GPIO13/14)
- MOSFETs: GPIO5 / GPIO6 · Battery ADC: GPIO36 · RGB: GPIO48

