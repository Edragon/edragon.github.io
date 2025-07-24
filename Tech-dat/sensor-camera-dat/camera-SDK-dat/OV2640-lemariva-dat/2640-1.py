import camera
import machine
import time

# Initialize IO4 (GPIO4) as output
led = machine.Pin(4, machine.Pin.OUT)

camera.init(0, format=camera.JPEG, fb_location=camera.PSRAM, xclk_freq=camera.XCLK_20MHz)

while True:
    # Blink IO4 while capturing
    for _ in range(2):
        led.value(1)
        time.sleep(0.1)
        led.value(0)
        time.sleep(0.1)

    machine.idle()  # Yield to system
    buf = camera.capture()
    machine.idle()  # Yield to system

    with open('capture.jpg', 'wb') as f:
        f.write(buf)
    
    machine.idle()  # Yield to system
    
    # Sleep in small intervals, yielding to system
    for _ in range(100):
        time.sleep(0.1)
        machine.idle()




