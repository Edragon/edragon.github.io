from machine import I2C, Pin
import time

import bmp280_1 as bmp280

b = bmp280.BMP280(I2C(1, scl=Pin(13), sda=Pin(15)))

while True:
    time.sleep_ms(500)
    b.get()
