
# mpremote connect COM6 fs cp mp-ssd1306-1-dat.py :
# mpremote connect COM6 run mp-ssd1306-1-dat.py

from machine import I2C, Pin
import ssd1306

i2c = I2C(0, scl=Pin(13), sda=Pin(15))
oled = ssd1306.SSD1306_I2C(128, 64, i2c)

oled.text("Hello, ESP32!", 0, 0)
oled.show()