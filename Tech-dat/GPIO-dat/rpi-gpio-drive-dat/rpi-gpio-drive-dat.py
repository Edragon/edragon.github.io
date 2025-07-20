
# rpi-gpio-drive-dat.py

import RPi.GPIO as GPIO
from time import sleep

GPIO.setmode(GPIO.BOARD)
GPIO.setup(29, GPIO.OUT) # set a port/pin as an output   


try:  
    while True:  
        GPIO.output(29, 1)         # set GPIO24 to 1/GPIO.HIGH/True  
        sleep(2)                 # wait half a second  
        GPIO.output(29, 0)         # set GPIO24 to 0/GPIO.LOW/False  
        sleep(2)                 # wait half a second  
  
except KeyboardInterrupt:          # trap a CTRL+C keyboard interrupt  
    GPIO.cleanup()                 # resets all GPIO ports used by this program  