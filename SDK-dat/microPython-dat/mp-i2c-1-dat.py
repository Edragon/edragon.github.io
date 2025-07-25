
# mpremote connect COM6 fs cp mp-i2c-1-dat.py :
# mpremote connect COM6 run mp-i2c-1-dat.py

# I2C devices found: ['0x3c', '0x76']
# I2C devices found: ['0x3c', '0x76']


from machine import Pin, I2C
import time

# Define I2C pins (adjust to your wiring)
i2c = I2C(0, scl=Pin(13), sda=Pin(15), freq=100000)

# Scan and print all detected device addresses
while True:
    devices = i2c.scan()
    if devices:
        print("I2C devices found:", [hex(addr) for addr in devices])
    else:
        print("No I2C devices found.")
    time.sleep(2)