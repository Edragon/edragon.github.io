import camera
import machine
import time



# Initialize camera with debug and smaller frame size
print("Initializing camera...")
try:
    camera.init(0,
        d0=5, d1=18, d2=19, d3=21, d4=36, d5=39, d6=34, d7=35,
        format=camera.JPEG,
        framesize=camera.FRAME_QQVGA,
        xclk_freq=camera.XCLK_20MHz,
        href=23, vsync=25, reset=-1, pwdn=32, sioc=27, siod=26, xclk=0, pclk=22
    )
    print("Camera initialized successfully.")
except Exception as e:
    print("Camera init failed:", e)
    # Stop further execution
    while True:
        machine.idle()


# Initialize IO4 (GPIO4) as output
led = machine.Pin(4, machine.Pin.OUT)


while True:
    print("Starting capture cycle...")
    # Blink LED for status
    for _ in range(2):
        led.value(1)
        machine.idle()
        time.sleep(0.05)
        machine.idle()
        led.value(0)
        machine.idle()
        time.sleep(0.05)
        machine.idle()

    machine.idle()
    print("Capturing image...")
    try:
        buf = camera.capture()
        print("Captured image, size =", len(buf))
    except Exception as e:
        print("Capture failed:", e)
        # wait before retry
        time.sleep(1)
        continue
    machine.idle()

    # Generate a timestamped filename
    ts = time.localtime()
    filename = 'capture_{:04d}{:02d}{:02d}_{:02d}{:02d}{:02d}.jpg'.format(ts[0], ts[1], ts[2], ts[3], ts[4], ts[5])
    print("Saving to file:", filename)
    try:
        with open(filename, 'wb') as f:
            f.write(buf)
            machine.idle()
        print("File saved.")
    except Exception as e:
        print("File write error:", e)
    machine.idle()
    print("Sleeping before next cycle...")
    for _ in range(50):
        time.sleep(0.05)
        machine.idle()




