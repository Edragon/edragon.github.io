

# mpremote connect COM6 fs cp bmp280-2-dat.py :
# mpremote connect COM6 run bmp280-2-dat.py

from machine import I2C, Pin
from bmp280 import *
import time

bus = I2C(0, scl=Pin(13), sda=Pin(15))
bmp = BMP280(bus)

bmp.use_case(BMP280_CASE_WEATHER)
bmp.oversample(BMP280_OS_HIGH)

bmp.temp_os = BMP280_TEMP_OS_8
bmp.press_os = BMP280_PRES_OS_4

bmp.standby = BMP280_STANDBY_250
bmp.iir = BMP280_IIR_FILTER_2

bmp.spi3w = BMP280_SPI3W_ON

bmp.power_mode = BMP280_POWER_FORCED
# or 
bmp.force_measure()

bmp.power_mode = BMP280_POWER_NORMAL
# or 
bmp.normal_measure()
# also
print("In normal mode:", bmp.in_normal_mode)

# Infinite loop to continuously read sensor data
while True:
    try:
        print("Loop start: measuring:", bmp.is_measuring, "updating:", bmp.is_updating)
        # Force a measurement
        print("Before force_measure")
        bmp.force_measure()
        print("After force_measure")
        # Read temperature
        print("Before temperature read")
        temperature = bmp.temperature
        print("After temperature read, value:", temperature)
        # Read pressure
        print("Before pressure read")
        pressure = bmp.pressure
        print("After pressure read, value:", pressure)
        # Display the readings with simple string formatting
        print("Before printing readings")
        print("Temperature:", temperature, "°C")
        print("Pressure:", pressure, "hPa")
        print("Is measuring:", bmp.is_measuring)
        print("Is updating:", bmp.is_updating)
        print("------------------------------")
    except Exception as e:
        print("Exception occurred:", repr(e))
    # Wait 2 seconds before next reading
    time.sleep(2)
