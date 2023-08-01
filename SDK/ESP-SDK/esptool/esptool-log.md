

## Possible serial noise or corruption.

    C:\Users\Administrator\AppData\Local\Arduino15\packages\esp32\tools\esptool_py\4.5.1/esptool.exe --chip esp32 --port COM186 --baud 921600 --before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 80m --flash_size 4MB 0x1000 C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_175220/Blink.ino.bootloader.bin 0x8000 C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_175220/Blink.ino.partitions.bin 0xe000 C:\Users\Administrator\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9/tools/partitions/boot_app0.bin 0x10000 C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_175220/Blink.ino.bin 



    esptool.py v4.5.1
    Serial port COM185
    Connecting....
    Chip is ESP32-D0WDQ6 (revision v1.0)
    Features: WiFi, BT, Dual Core, 240MHz, VRef calibration in efuse, BLK3 partially reserved, Coding Scheme 3/4
    Crystal is 40MHz
    MAC: b4:e6:2d:c8:0d:29
    Uploading stub...
    Running stub...
    Stub running...
    Changing baud rate to 921600
    Changed.
    WARNING: Failed to communicate with the flash chip, read/write operations will fail. Try checking the chip connections or removing any other hardware connected to IOs.
    Configuring flash size...
    Flash will be erased from 0x00001000 to 0x00005fff...
    Flash will be erased from 0x00008000 to 0x00008fff...
    Flash will be erased from 0x0000e000 to 0x0000ffff...
    Flash will be erased from 0x00010000 to 0x00049fff...
    Compressed 18960 bytes to 13073...
    Writing at 0x00001000... (100 %)

    A fatal error occurred: Serial data stream stopped: Possible serial noise or corruption.
    A fatal error occurred: Serial data stream stopped: Possible serial noise or corruption.



