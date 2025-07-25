
# mpremote connect COM6 fs cp mp-i2c-dat.py :
# mpremote connect COM6 run mp-i2c-dat.py

import machine
import ssd1306
import time

# create I2C interface
i2c = machine.I2C(1, sda=machine.Pin(15), scl=machine.Pin(13)) # I have my display hooked up to pins 14 and 15 (for I2C)
print(i2c.scan()) # 0x3c is the I2C address of the SSD1306. As an integer, 60.

# create SSD1306 interface
display_width:int = 128
display_height:int = 64
oled = ssd1306.SSD1306_I2C(128, 64, i2c)

# turn on all pixels
oled.fill(1) # make the change
oled.show() # show the update
time.sleep(1)

# turn off all pixels (blank display)
oled.fill(0)
oled.show()
time.sleep(1)

# fill in a single pixel
oled.pixel(0, 0, 1) # turn on pixel at (0, 0) (top left)
oled.pixel(64, 0, 1) # turn on pixel at (64, 0), middle top
oled.pixel(127, 63, 1) # turn on pixel at (127, 63) (absolute bottom right on my 128x64 display)
oled.show() # show the update
time.sleep(1)

# turn off all pixels again
oled.fill(0)
oled.show()
time.sleep(1)

# display text
oled.text("Hello, world!", 0, 0) # print text "Hello, world!" at position (0, 0) (top left)
oled.show()
time.sleep(1)

# turn off all pixels again
oled.fill(0)
oled.show()
time.sleep(1)