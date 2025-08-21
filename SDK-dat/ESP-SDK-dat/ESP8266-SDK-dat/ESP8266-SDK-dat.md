
# ESP8266-SDK-dat

- [[esp-idf-dat]] - [[ESP-dat]] - [[esp-sdk-dat]]

- [[ESP8266-HDK-dat]]

- [[flash-download-tool-dat]] - [[ESP8266-boot-log-dat]]

- [[display-SDK-dat]]

Bootloader / ROM output	74880	Default ESP8266 boot messages (after reset).

AT firmware 

https://www.espressif.com.cn/en/support/download/at


- --flash_mode dio means the ﬁrmware is compiled with ﬂash DIO mode.
- --flash_freq 40m means the ﬁrmware’s ﬂash frequency is 40 MHz.
- --flash_size 4MB means the ﬁrmware is using ﬂash size 4 MB.
- 0x10000 ota_data_initial.bin means downloading ota_data_initial.bin into the address 0x10000.


    PS D:\git-docs\edragon> esptool erase_flash
    Warning: Deprecated: Command 'erase_flash' is deprecated. Use 'erase-flash' instead.
    esptool v5.0.1
    Connected to ESP8266 on COM8:
    Chip type:          ESP8266EX
    Features:           Wi-Fi, 160MHz
    Crystal frequency:  26MHz        
    MAC:                44:17:93:0a:04:4d

    Stub flasher running.

    Flash memory erased successfully in 12.5 seconds.

cd D:\git-docs\edragon\edragon.github.io\SDK-dat\ESP-SDK-dat\ESP8266-SDK-dat\

esptool --chip esp8266 --port COM8 --baud 115200 write_flash -z --flash_mode dio --flash_freq 40m --flash_size 4MB 0x0 ESP8266-AT-firmware-v2.2.0.bin 0x10000 ota_data_initial.bin

esptool --chip esp8266 --port COM8 --baud 921600 write_flash -z --flash_mode dio --flash_freq 40m --flash_size 4MB 0x0 factory_WROOM-02.bin 


    Writing at 0x000c5455 [=========================>    ]  87.0% 491
    Writing at 0x000d0a94 [=========================>    ]  89.9% 507
    Writing at 0x000d8463 [==========================>   ]  92.8% 524
    Writing at 0x000e17ce [===========================>  ]  95.7% 540
    Writing at 0x000fa33f [============================> ]  98.6% 557
    Wrote 2097152 bytes (564855 compressed) at 0x00000000 in 54.0 seconds (311.0 kbit/s).
    Hash of data verified.


esptool --chip esp8266 --port COM8 --baud 460800 write-flash --flash-size=detect 0x0 factory_WROOM-02.bin

esptool --chip esp8266 --port COM8 --baud 460800 write-flash -z --flash-mode dio --flash-freq 40m --flash-size=detect 0x0 ESP8266_DIO_32M_32M_20160615_V1.5.4.bin


## prebuild firmware 

- https://github.com/Edragon/esp_firmware

## ref 

- [[ESP8266-dat]]