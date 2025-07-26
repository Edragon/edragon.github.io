
# mpremote connect COM6 fs cp esp1000-1-dat.py :
# mpremote connect COM6 run esp1000-1-dat.py

from machine import I2C, Pin, UART
import ssd1306
from bmp280 import *
import time

# I2C setup (adjust pins as needed)
i2c = I2C(0, scl=Pin(13), sda=Pin(15))

# OLED setup
oled = ssd1306.SSD1306_I2C(128, 64, i2c)

# BMP280 setup
bmp = BMP280(i2c)
bmp.use_case(BMP280_CASE_WEATHER)
bmp.oversample(BMP280_OS_HIGH)
bmp.temp_os = BMP280_TEMP_OS_8
bmp.press_os = BMP280_PRES_OS_4
bmp.standby = BMP280_STANDBY_250
bmp.iir = BMP280_IIR_FILTER_2
bmp.spi3w = BMP280_SPI3W_ON
bmp.power_mode = BMP280_POWER_NORMAL

# Deinit UART0 (GPIO3 is RX)
# uart0 = UART(0)
# uart0.deinit()
# GPIO3 setup with internal pull-down
gpio3 = Pin(3, Pin.IN, Pin.PULL_DOWN)

while True:
    try:
        bmp.force_measure()
        temperature = bmp.temperature
        pressure = bmp.pressure
        gpio3_status = gpio3.value()
        
        oled.fill(0)
        oled.text("BMP280 Sensor:", 0, 0)
        oled.text("T={:.2f}C".format(temperature), 0, 16)
        oled.text("P={:.2f}hPa".format(pressure), 0, 32)
        oled.text("GPIO3: {}".format(gpio3_status), 0, 48)
        oled.show()
    except Exception as e:
        oled.fill(0)
        oled.text("Error:", 0, 0)
        oled.text(str(e), 0, 16)
        oled.show()
    time.sleep(2)