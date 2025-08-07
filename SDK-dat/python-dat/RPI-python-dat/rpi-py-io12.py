import RPi.GPIO as GPIO
import time

# Use BCM numbering for GPIO12 (physical pin 32)
led = 12  # GPIO12
switch = 31  # Update as needed for your switch GPIO

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

GPIO.setup(led, GPIO.OUT)
GPIO.setup(switch, GPIO.IN)

for i in range(10):
    GPIO.output(led, GPIO.HIGH)
    time.sleep(5)
    GPIO.output(led, GPIO.LOW)
    time.sleep(5)
    print('Switch status = ', GPIO.input(switch))

GPIO.cleanup()




