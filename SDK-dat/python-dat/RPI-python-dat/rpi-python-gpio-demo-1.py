
# rpi-python-gpio-demo-1.py

import RPi.GPIO as GPIO
import time

led = 29
switch = 31

GPIO.setmode(GPIO.BOARD)
GPIO.setup(led, GPIO.OUT)
GPIO.setup(switch, GPIO.IN)

for i in range(10):
    GPIO.output(led, GPIO.HIGH)
    time.sleep(5)
    GPIO.output(led, GPIO.LOW)
    time.sleep(5)
    print('Switch status = ', GPIO.input(switch))

GPIO.cleanup()




