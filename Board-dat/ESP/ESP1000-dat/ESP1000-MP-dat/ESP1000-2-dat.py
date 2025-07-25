# mpremote connect COM6 fs cp esp1000-1-dat.py :
# mpremote connect COM6 run esp1000-1-dat.py

from machine import I2C, Pin, UART
import machine  # type: ignore
import camera  # type: ignore
import ssd1306
from bmp280 import *
import time
import gc  # type: ignore

# init_i2c: use fixed bus without scanning devices
def init_i2c():
    # I2C setup (bus 1, 400kHz)
    i2c = I2C(1, scl=Pin(13), sda=Pin(15), freq=400000)
    return i2c


def init_oled(i2c):
    # Use fixed address 0x3C for SSD1306
    try:
        oled = ssd1306.SSD1306_I2C(128, 64, i2c, addr=0x3C)
        print("OLED initialized at 0x3C.")
        return oled
    except Exception as e:
        print("OLED init failed:", e)
        return None


def init_bmp(i2c):
    print("Initializing BMP280 at fixed address 0x76...")
    try:
        bmp = BMP280(i2c, 0x76)
        bmp.use_case(BMP280_CASE_WEATHER)
        bmp.oversample(BMP280_OS_HIGH)
        bmp.temp_os = BMP280_TEMP_OS_8
        bmp.press_os = BMP280_PRES_OS_4
        bmp.standby = BMP280_STANDBY_250
        bmp.iir = BMP280_IIR_FILTER_2
        bmp.spi3w = BMP280_SPI3W_ON
        bmp.power_mode = BMP280_POWER_NORMAL
        print("BMP280 initialized.")
        return bmp
    except Exception as e:
        print("BMP280 init failed:", e)
        return None


def read_bmp(bmp):
    try:
        bmp.force_measure()
        temp = bmp.temperature
        pressure = bmp.pressure
        # power down sensor after reading
        bmp.sleep()
        return temp, pressure
    except Exception as e:
        print("BMP read error:", e)
        return None, None


def read_gpio(pin):
    return pin.value()


def init_camera():
    try:
        camera.init(0,
            d0=5, d1=18, d2=19, d3=21, d4=36, d5=39, d6=34, d7=35,
            format=camera.JPEG,
            framesize=camera.FRAME_QQVGA,
            xclk_freq=camera.XCLK_20MHz,
            href=23, vsync=25, reset=-1, pwdn=32,
            sioc=27, siod=26, xclk=0, pclk=22
        )
        print("Camera initialized.")
        return True
    except Exception as e:
        print("Camera init failed:", e)
        return False


def capture_image():
    buf = camera.capture()
    print("Captured image size:", len(buf))
    ts = time.localtime()
    filename = 'capture_{:04d}{:02d}{:02d}_{:02d}{:02d}{:02d}.jpg'.format(*ts[:6])
    with open(filename, 'wb') as f:
        f.write(buf)
    print("Saved file:", filename)
    return filename


def update_display(oled, temp, pressure, gpio_status, filename=None):
    if not oled:
        return
    oled.fill(0)
    if filename:
        oled.text(filename[:16], 0, 0)
        oled.text(filename[16:], 0, 16)
        oled.text("GPIO3: {}".format(gpio_status), 0, 32)
        if temp is not None:
            oled.text("T={:.1f}C".format(temp), 0, 48)
    else:
        oled.text("BMP280 Sensor:", 0, 0)
        if temp is not None:
            oled.text("T={:.2f}C".format(temp), 0, 16)
        if pressure is not None:
            oled.text("P={:.2f}hPa".format(pressure), 0, 32)
        oled.text("GPIO3: {}".format(gpio_status), 0, 48)
    oled.show()


def main():
    i2c = init_i2c()
    # oled = init_oled(i2c)
    bmp = init_bmp(i2c)
    gpio3 = Pin(3, Pin.IN, Pin.PULL_DOWN)
    camera_ready = False

    while True:
        temp, pressure = (read_bmp(bmp) if bmp else (None, None))
        gpio_status = read_gpio(gpio3)

        if gpio_status:
            if not camera_ready:
                camera_ready = init_camera()
            if camera_ready:
                filename = capture_image()
            else:
                filename = None
            update_display(oled, temp, pressure, gpio_status, filename)
        else:
            update_display(oled, temp, pressure, gpio_status)

        print("Loop end, free mem:", gc.mem_free())
        time.sleep(2)


# Entry point
main()