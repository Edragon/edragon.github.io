# mpremote connect COM6 run 2640-2.py
# mpremote connect COM6 reset 
# mpremote connect COM6 fs cp 2640-2.py :main.py

import camera
import machine
import time
import gc
import uos

# uos.dupterm(None, 1)  # Disable REPL on UART0

# Initialize IO4 (GPIO4) as output
led = machine.Pin(4, machine.Pin.OUT)

# IO3 (GPIO3) is also RXD0 of UART0. If UART0 is not used, we can safely use it as GPIO.
# If UART0 is active, this may cause conflicts. Deinitialize UART0 if necessary.
try:
    uart0 = machine.UART(0)
    uart0.deinit()  # Deinitialize UART0 to free GPIO3 for input use
except Exception:
    pass  # UART0 may not be initialized, ignore errors

trigger = machine.Pin(3, machine.Pin.IN, machine.Pin.PULL_DOWN)

# Flag to indicate capture request
capture_requested = False

def trigger_handler(pin):
    global capture_requested
    capture_requested = True

# Set up interrupt on rising edge of IO3
trigger.irq(trigger=machine.Pin.IRQ_RISING, handler=trigger_handler)

camera.init(0, format=camera.JPEG, fb_location=camera.PSRAM, xclk_freq=camera.XCLK_20MHz)

while True:
    if capture_requested:
        capture_requested = False
        
        # Blink IO4 while capturing
        for _ in range(2):
            led.value(1)
            time.sleep(0.1)
            led.value(0)
            time.sleep(0.1)

        buf = camera.capture()

        with open('capture.jpg', 'wb') as f:
            f.write(buf)
        
        # Clean up memory
        del buf
        gc.collect()
    
    # Long sleep since we're using interrupts
    time.sleep(0.1)




