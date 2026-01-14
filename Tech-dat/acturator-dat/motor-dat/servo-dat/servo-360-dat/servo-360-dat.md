
# servo-360-dat


## servo 360 degree 

360° (continuous-rotation) servo
A 360° servo is effectively a geared DC motor with continuous-variable speed and direction control — it does not provide absolute angle positioning. It uses the same PWM control signal as a regular hobby servo, but the pulse width controls motor speed and direction instead of shaft angle. (Commonly used as a power source for modified robots and drivetrains.)

Control notes

- Typical PWM time base: ~20 ms period (50 Hz). Pulse width (high time) is usually in the ~0.5–2.5 ms range; 1.5 ms is the neutral/stop point for many servos.
- Behavior for continuous-rotation servos:
    - Pulse < center (e.g., 0.5 ms → 1.5 ms): forward rotation. The smaller the pulse, the faster the forward speed (0.5 ms → fastest forward).
    - ~1.5 ms: stop / neutral.
    - Pulse > center (e.g., 1.5 ms → 2.5 ms): reverse rotation. The larger the pulse, the faster the reverse speed (2.5 ms → fastest reverse).
- Some servos use narrower ranges (e.g., 1.0–2.0 ms). Always check with a servo-tester or measure the actual response for the specific model.

Example mapping (typical)

- 0.5 ms — fastest forward
- 1.0 ms — moderate forward
- 1.5 ms — stop
- 2.0 ms — moderate reverse
- 2.5 ms — fastest reverse

Arduino tip: use Servo.writeMicroseconds(x) to send precise pulse widths (e.g., 1000–2000 µs) and calibrate the stop point for your servo.


- [[N20-motor-dat]]

| Pulse (ms) | Pulse (µs) |  Angle (°) | degree           |
| ---------: | ---------: | ---------: | ---------------- |
|     0.5 ms |     500 µs |          0 | fastest forward  |
|     1.0 ms |    1000 µs |         45 | moderate forward |
|     1.5 ms |    1500 µs |         90 | stop             |
|     2.0 ms |    2000 µs |        135 | moderate reverse |
|     2.5 ms |    2500 µs | 180 or -90 | fastest reverse  |



## ref 

- [[servo-dat]]