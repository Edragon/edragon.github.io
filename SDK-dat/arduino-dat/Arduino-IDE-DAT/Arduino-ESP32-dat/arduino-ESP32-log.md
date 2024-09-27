
## Arduino ESP32 C3 

    ESP-ROM:esp32c3-api1-20210207
    Build:Feb  7 2021
    rst:0x1 (POWERON),boot:0xd (SPI_FAST_FLASH_BOOT)
    SPIWP:0xee
    mode:DIO, clock div:2
    load:0x3fcd5810,len:0x438
    load:0x403cc710,len:0x91c
    load:0x403ce710,len:0x25b0
    entry 0x403cc710
    Testing LEDs .. 
    test ..
    test ..
    test ..
    test ..
    test ..
    test ..
    test ..
    test ..
    test ..
    test ..

    ....
    Connected to 111
    IP address: 192.168.8.197
    MDNS responder started
    HTTP server started



## output code 

    C:\Users\Administrator\AppData\Local\Arduino15\packages\esp32\tools\esptool_py\4.6/esptool.exe --chip esp32c3 --port COM287 --baud 921600 --before default_reset --after hard_reset write_flash -e -z --flash_mode keep --flash_freq keep --flash_size keep 0x0 C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_235099/NWI1252-receiver-1.ino.bootloader.bin 0x8000 C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_235099/NWI1252-receiver-1.ino.partitions.bin 0xe000 C:\Users\Administrator\AppData\Local\Arduino15\packages\esp32\hardware\esp32\3.0.4/tools/partitions/boot_app0.bin 0x10000 C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_235099/NWI1252-receiver-1.ino.bin 
