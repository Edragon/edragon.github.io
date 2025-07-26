
# ESP1000-MP-dat.md

- [[esp1000-dat]] - [[OV2640-lemariva-dat]]

- [[micropython-dat]]

- [[camera-sdk-dat]]

flash camera driver firmware 

    esptool --port COM6 erase_flash
    esptool --port COM6 --baud 460800 write-flash 0x1000 micropython_camera_feeeb5ea3_esp32_idf4_4.bin

    mpremote connect COM6 fs cp bmp280.py :
    mpremote connect COM6 fs cp ssd1306.py :
    mpremote connect COM6 fs cp esp1000-2-dat.py :


    mpremote connect COM6 run esp1000-2-dat.py

    mpremote connect COM6 fs cp 2640-1.py :
    mpremote connect COM6 run 2640-1.py

- [[micropython_camera_feeeb5ea3_esp32_idf4_4.bin]] - micropython camera driver firmware, has memory error with [[BMP280-dat]]

    Guru Meditation Error: Core  1 panic'ed (StoreProhibited). Exception was unhandled.

    Core  1 register dump:
    PC      : 0x400869fc  PS      : 0x00060031  A0      : 0x80086bb2 
    A1      : 0x3ffb1190
    A2      : 0x3ffaf894  A3      : 0x00000000  A4      : 0x00000000 
    A5      : 0x00000800
    A6      : 0x00060023  A7      : 0x00060021  A8      : 0x3ffbbf88 
    A9      : 0x00000901
    A10     : 0x3ffb1208  A11     : 0x00000001  A12     : 0x00000001 
    A13     : 0x3ffbbf8c
    A14     : 0x00000000  A15     : 0x3ff53000  SAR     : 0x0000000d 
    EXCCAUSE: 0x0000001d  
    EXCVADDR: 0x00000008  LBEG    : 0x4008d9a0  LEND    : 0x4008d9bc 
    LCOUNT  : 0x00000000


    Backtrace:0x400869f9:0x3ffb11900x40086baf:0x3ffb11d0 0x40083f85:0x3ffb1200 0x40089ea9:0x3ffca150 0x40091141:0x3ffca170 0x4012628b:0x3ffca1b0 0x40119b16:0x3ffca200 0x401169a9:0x3ffca230 0x40116a21:0x3ffca270 0x400e20bd:0x3ffca2b0 0x400e8819:0x3ffca2e0 0x400e8951:0x3ffca300 0x40085ca5:0x3ffca320 0x400e205a:0x3ffca3c0 0x400e8819:0x3ffca430 0x400e8951:0x3ffca450 0x40085ca5:0x3ffca470 0x400e205a:0x3ffca510 0x400e8819:0x3ffca580 0x400e8951:0x3ffca5a0 0x400e7641:0x3ffca5c0 0x400e725e:0x3ffca620 0x400e8819:0x3ffca640 0x40085c29:0x3ffca660 0x400e205a:0x3ffca700 0x400e8819:0x3ffca730 0x400e8842:0x3ffca750 0x40118bdd:0x3ffca770 0x40118d9a:0x3ffca800 0x400f89b6:0x3ffca850