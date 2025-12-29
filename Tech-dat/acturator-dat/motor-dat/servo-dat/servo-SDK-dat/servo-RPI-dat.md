# servo-RPI-dat.md

A minimal Raspberry Pi Python demo to rotate a standard hobby servo left and right using BCM GPIO5 (physical pin 29).

Save the script below as `servo_demo_gpio5.py` on your Pi and run it with `sudo python3 servo_demo_gpio5.py`.

```python
#!/usr/bin/env python3
"""Servo demo on BCM GPIO5 (physical pin 29).
Uses RPi.GPIO to generate 50Hz PWM and maps angle 0-180 to duty cycle.
Adjust MIN_DUTY / MAX_DUTY if your servo needs different values.
"""
import time
import RPi.GPIO as GPIO

SERVO_PIN = 5  # BCM numbering
FREQ = 50      # 50Hz for standard servos

# Duty cycle values may need tuning per servo (these are common defaults)
MIN_DUTY = 2.5   # ~0 degrees
MAX_DUTY = 12.5  # ~180 degrees

GPIO.setmode(GPIO.BCM)
GPIO.setup(SERVO_PIN, GPIO.OUT)

pwm = GPIO.PWM(SERVO_PIN, FREQ)
pwm.start(0)

def angle_to_duty(angle: float) -> float:
    """Convert 0-180 angle to duty cycle between MIN_DUTY and MAX_DUTY."""
    if angle < 0:
        angle = 0
    if angle > 180:
        angle = 180
    return MIN_DUTY + (angle / 180.0) * (MAX_DUTY - MIN_DUTY)


def set_angle(angle: float, settle: float = 0.5) -> None:
    duty = angle_to_duty(angle)
    pwm.ChangeDutyCycle(duty)
    time.sleep(settle)
    # Stop driving PWM to reduce jitter on some servos
    pwm.ChangeDutyCycle(0)


try:
    print('Press Ctrl-C to exit. Sweeping servo by angle: 0 -> 90 -> 180')
    while True:
        set_angle(0)
        time.sleep(1)
        set_angle(90)
        time.sleep(1)
        set_angle(180)
        time.sleep(1)
except KeyboardInterrupt:
    pass
finally:
    pwm.stop()
    GPIO.cleanup()
```

Notes:
- Use BCM numbering (GPIO5). Physical pin 29 corresponds to BCM GPIO5.
- Run the script on the Pi (not on Windows): `sudo python3 servo_demo_gpio5.py`.
- If the servo jitters or doesn't reach endpoints, adjust `MIN_DUTY` and `MAX_DUTY` slightly.

