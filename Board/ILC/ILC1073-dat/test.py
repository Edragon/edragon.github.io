
# pip install lcd2usb
# https://github.com/xyb/lcd2usb

from lcd2usb import LCD
lcd = LCD()
lcd.info()

print (lcd.version)

lcd.write('Flying with PYTHON', 0, 1)