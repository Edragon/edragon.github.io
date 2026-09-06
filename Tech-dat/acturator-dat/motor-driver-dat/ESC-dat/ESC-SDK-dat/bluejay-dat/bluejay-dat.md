


# bluejay-dat

- [[ESC-SDK-dat]] - [[BLHeli-dat]] - [[bluejay-dat]]

Startup Power Threshold Set Too Low

Issue: Bluejay defaults to low startup power levels optimized for larger 5-inch motors.

Mechanism: Tiny 1S/2S whoop motors have high coil resistance and need a stronger startup punch. If Startup Power (Min Protection) in Bluejay is set to standard defaults, the ESC gives up trying to turn the rotor before it even spins up.

Fix: Increase Startup Power in Bluejay to 1010–1050 (or 11–12 depending on the UI scale).


for [[mobula8-dat]]


Fix: Flash Bluejay with `24kHz` PWM frequency. 

Fix: Force the protocol to `DSHOT300` (or even DSHOT150) in Betaflight.

Minimum Startup Power(Boost) == `1020~1040`
Maximum Startup Power (Protection) == `1100~1200`

## ref 