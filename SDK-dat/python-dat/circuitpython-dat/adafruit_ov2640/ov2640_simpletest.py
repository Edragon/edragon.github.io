# SPDX-FileCopyrightText: 2017 Scott Shawcroft, written for Adafruit Industries
# SPDX-FileCopyrightText: Copyright (c) 2021 Jeff Epler for Adafruit Industries
#
# SPDX-License-Identifier: Unlicense

"""Capture an image from the camera and display it as ASCII art.

This demo is designed to run on the Kaluga, but you can adapt it
to other boards by changing the constructors for `bus` and `cam`
appropriately.

The camera is placed in YUV mode, so the top 8 bits of each color
value can be treated as "greyscale".

It's important that you use a terminal program that can interpret
"ANSI" escape sequences.  The demo uses them to "paint" each frame
on top of the prevous one, rather than scrolling.

Remember to take the lens cap off, or un-comment the line setting
the test pattern!
"""

import sys
import time

import board
import busio

import adafruit_ov2640

# mpremote connect COM6 fs put adafruit_ov2640.py :
# mpremote connect COM6 fs put ov2640_simpletest.py :
# mpremote connect COM6 fs run ov2640_simpletest.py


# Pin definitions adapted from ESP1000-2-dat.py
# d0=5, d1=18, d2=19, d3=21, d4=36, d5=39, d6=34, d7=35
# href=23, vsync=25, sioc=27, siod=26, xclk=0, pclk=22
data_pins = [board.GP5, board.GP18, board.GP19, board.GP21, board.GP36, board.GP39, board.GP34, board.GP35]

bus = busio.I2C(scl=board.GP27, sda=board.GP26)  # sioc=27, siod=26

cam = adafruit_ov2640.OV2640(
    bus,
    data_pins=data_pins,
    clock=board.GP22,      # pclk=22
    vsync=board.GP25,      # vsync=25
    href=board.GP23,       # href=23
    mclk=board.GP0,        # xclk=0
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