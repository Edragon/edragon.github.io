# mpremote connect COM6 fs cp ov2640_micropython_test.py :
# mpremote connect COM6 run ov2640_micropython_test.py

import camera  # type: ignore
import time
import sys

# Initialize camera with ESP1000 pin definitions
try:
    camera.init(0,
        d0=5, d1=18, d2=19, d3=21, d4=36, d5=39, d6=34, d7=35,
        format=camera.JPEG,
        framesize=camera.FRAME_QQVGA,  # 160x120
        xclk_freq=camera.XCLK_20MHz,
        href=23, vsync=25, reset=-1, pwdn=32,
        sioc=27, siod=26, xclk=0, pclk=22
    )
    print("Camera initialized successfully")
except Exception as e:
    print("Camera init failed:", e)
    sys.exit()

# Simple test - capture and save images
count = 0
while True:
    try:
        print("Capturing image", count)
        buf = camera.capture()
        print("Image size:", len(buf), "bytes")
        
        # Save image
        filename = f"test_{count:03d}.jpg"
        with open(filename, 'wb') as f:
            f.write(buf)
        print("Saved:", filename)
        
        count += 1
        time.sleep(2)
        
        # Stop after 5 images for testing
        if count >= 5:
            break
            
    except Exception as e:
        print("Capture error:", e)
        break

print("Test completed")
camera.deinit()
