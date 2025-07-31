
import sys
import time
import board
import busio
import adafruit_ov2640

# Pin mapping based on ESP32-S3-cam-dat.md
# D0-D7: GPIO43, GPIO44, GPIO1, GPIO2, GPIO42, GPIO41, GPIO40, GPIO39
data_pins = [
    board.GP43,  # D0
    board.GP44,  # D1
    board.GP1,   # D2
    board.GP2,   # D3
    board.GP42,  # D4
    board.GP41,  # D5
    board.GP40,  # D6
    board.GP39,  # D7
]

# I2C for camera control (SIOD/SIOC)
bus = busio.I2C(scl=board.GP21, sda=board.GP20)  # Adjust if needed

cam = adafruit_ov2640.OV2640(
    bus,
    data_pins=data_pins,
    clock=board.GP45,      # PCLK (example: VSPI, adjust if needed)
    vsync=board.GP36,      # VSYNC (example: PSRAM, adjust if needed)
    href=board.GP35,       # HREF (example: PSRAM, adjust if needed)
    mclk=board.GP48,       # XCLK (example: WS2812, adjust if needed)
    mclk_frequency=20_000_000,
    size=adafruit_ov2640.OV2640_SIZE_QQVGA,
)
cam.colorspace = adafruit_ov2640.OV2640_COLOR_YUV
cam.flip_y = True
# cam.test_pattern = True

buf = bytearray(2 * cam.width * cam.height)
chars = b" .:-=+*#%@"
remap = [chars[i * (len(chars) - 1) // 255] for i in range(256)]

width = cam.width
row = bytearray(2 * width)

sys.stdout.write("\033[2J")
while True:
    cam.capture(buf)
    for j in range(cam.height // 2):
        sys.stdout.write(f"\033[{j}H")
        for i in range(cam.width // 2):
            row[i * 2] = row[i * 2 + 1] = remap[buf[4 * (width * j + i)]]
        sys.stdout.write(row)
        sys.stdout.write("\033[K")
    sys.stdout.write("\033[J")
    time.sleep(0.05)
    
    
