
# MP-ESP32-dat

- [[ESP32-SDK-dat]] - [[ESP32-S3-SDK-dat]]

## For ESP32


https://micropython.org/resources/firmware/ESP32_GENERIC-20250415-v1.25.0.bin

- [[ESP32-SDK-dat]] - [[ESP32-dat]]

esp32 

    esptool --port COM6 erase_flash
    esptool --port COM6 --baud 460800 write-flash 0x1000 ESP32_GENERIC-20250415-v1.25.0.bin
    esptool --port COM6 --baud 460800 write_flash 0 ESP32_BOARD_NAME-DATE-VERSION.bin

esp32-s3 

    esptool --port COM14 --baud 460800 --before default_reset --after hard_reset --chip esp32s3  write_flash --flash-mode dio --flash-size detect --flash-freq 80m 0x0 firmware.bin


## For ESP32-S3 

- [[ESP32-S3-dat]]

- [[ESPtool-dat]] - [[ESP-SDK-dat]]

https://micropython.org/download/ESP32_GENERIC_S3/

- after flash [[ESP32_GENERIC_S3-20250415-v1.25.0.bin]], re-open new COM port and find: 

    MicroPython v1.25.0 on 2025-04-15; Generic ESP32S3 module with ESP32S3
    Type "help()" for more information.
    >>> 

try 

    >>> import machine
    >>> machine.freq() 
    160000000
    >>> 

## code 

- [[micropython-dat]] code section 

## ref 

- [[micropython-dat]]