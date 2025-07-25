

# mpremote connect COM6 fs cp bmp280-1-dat.py :
# mpremote connect COM6 run bmp280-1-dat.py

from machine import I2C, Pin
from bmp280 import *

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

bmp.power_mode = BMP280_POWER_SLEEP
# or 
bmp.sleep()

print(bmp.temperature)
print(bmp.pressure)

#True while measuring
bmp.is_measuring

#True while copying data to registers
bmp.is_updating
