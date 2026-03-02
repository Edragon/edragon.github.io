# servo-RPI-angle0-dat.md

A minimal script to hold a hobby servo at 0° (zero degrees) using BCM GPIO5 (physical pin 29).

Save as `servo_hold_0_gpio5.py` on the Pi and run with `sudo python3 servo_hold_0_gpio5.py`.

```python
#!/usr/bin/env python3
"""Hold servo at 0° on BCM GPIO5 until Ctrl-C."""
import time
import RPi.GPIO as GPIO

SERVO_PIN = 5  # BCM numbering
FREQ = 50

# Tune these for your servo if needed
MIN_DUTY = 2.5
MAX_DUTY = 12.5

def angle_to_duty(angle: float) -> float:
    a = max(0.0, min(180.0, float(angle)))
    return MIN_DUTY + (a / 180.0) * (MAX_DUTY - MIN_DUTY)

GPIO.setmode(GPIO.BCM)
GPIO.setup(SERVO_PIN, GPIO.OUT)

pwm = GPIO.PWM(SERVO_PIN, FREQ)
# Start PWM and keep the duty cycle that corresponds to 0° so the servo actively holds position
duty_0 = angle_to_duty(0)
pwm.start(duty_0)

try:
    print('Holding 0° on GPIO5 (pin 29). Press Ctrl-C to stop.')
    while True:
        time.sleep(1)
except KeyboardInterrupt:
    pass
finally:
    pwm.stop()
    GPIO.cleanup()
```

Notes:
- Keep the PWM running (do not set duty to 0) so the servo actively holds position.
- Ensure servo V+ is powered by a suitable 5V supply and servo GND is tied to Pi GND.
- Remove or weaken any external pull-down on the signal line—strong pull-downs prevent the Pi from driving the PWM.

