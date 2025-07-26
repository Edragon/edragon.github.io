


## python CLI version 

- [[python-dat]]

https://github.com/espressif/esptool


## install python 3 

  pip3 install esptool

or python2 == pip install esptool




## basic usage 

first erase the entire flash using:

    esptool erase_flash
    esptool.py erase_flash

log 

  C:\Users\Administrator>esptool erase_flash
  Warning: Deprecated: Command 'erase_flash' is deprecated. Use 'erase-flash' instead.
  esptool v5.0.1
  Connected to ESP32-S3 on COM3:
  Chip type:          ESP32-S3 (QFN56) (revision v0.2)
  Features:           Wi-Fi, BT 5 (LE), Dual Core + LP Core, 240MHz, Embedded PSRAM 8MB (AP_3v3)
  Crystal frequency:  40MHz
  USB mode:           USB-Serial/JTAG
  MAC:                f0:9e:9e:22:1d:d0

  Stub flasher running.

  Flash memory erased successfully in 28.6 seconds.

  Hard resetting via RTS pin...



esptool.py will try to detect the serial port with the ESP32 automatically, but if this fails or there might be more than one Espressif-based device attached to your computer then pass the --port option with the name of the target serial port. For example:

Flashing

Then deploy the firmware to the board, starting at address 0:

  esptool.py --baud 460800 write_flash 0 ESP32_BOARD_NAME-DATE-VERSION.bin
  esptool --baud 460800 write_flash 0 ESP32_GENERIC_S3-20250415-v1.25.0.bin

log 

  esptool --baud 460800 write-flash 0 ESP32_GENERIC_S3-20250415-v1.25.0.bin
  esptool v5.0.1
  Connected to ESP32-S3 on COM3:
  Chip type:          ESP32-S3 (QFN56) (revision v0.2)
  Features:           Wi-Fi, BT 5 (LE), Dual Core + LP Core, 240MHz, Embedded PSRAM 8MB (AP_3v3)
  Crystal frequency:  40MHz
  USB mode:           USB-Serial/JTAG
  MAC:                f0:9e:9e:22:1d:d0

  Stub flasher running.
  Changing baud rate to 460800...
  Changed.

  Configuring flash size...
  Flash will be erased from 0x00000000 to 0x00198fff...
  Compressed 1673008 bytes to 1096502...
  Writing at 0x0006b8d1 [====>                         ]  17.9% 196608/1096502 bytes...

Troubleshooting

  If flashing starts and then fails partway through, try removing the --baud 460800 option to flash at the slower default speed.


### ESP32C3 log 

  C:\Users\Administrator\AppData\Local\Arduino15\packages\esp32\tools\esptool_py\4.2.1/esptool.exe --chip esp32c3 --port COM12 --baud 921600 --before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 80m --flash_size 4MB 0x0 C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_867944/NWI1119-AP-1.ino.bootloader.bin 0x8000 C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_867944/NWI1119-AP-1.ino.partitions.bin 0xe000 C:\Users\Administrator\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.6/tools/partitions/boot_app0.bin 0x10000 C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_867944/NWI1119-AP-1.ino.bin 

segmented 

C:\Users\Administrator\AppData\Local\Arduino15\packages\esp32\tools\esptool_py\4.2.1/

    esptool.exe 
    --chip esp32c3 
    --port COM12 
    --baud 921600 
    --before default_reset 
    --after hard_reset write_flash 
    -z --flash_mode dio 
    --flash_freq 80m 
    --flash_size 4MB 
    0x0 C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_867944/NWI1119-AP-1.ino.bootloader.bin 
    0x8000 C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_867944/NWI1119-AP-1.ino.partitions.bin 
    0xe000 C:\Users\Administrator\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.6/tools/partitions/boot_app0.bin 
    0x10000 C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_867944/NWI1119-AP-1.ino.bin 


C:\Users\Administrator\AppData\Local\Arduino15\packages\esp32\tools\esptool_py\4.2.1/esptool.exe --chip esp32c3 --port COM7 --baud 921600 --before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 80m --flash_size 4MB 0x0 C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_562933/basic-2.ino.bootloader.bin 0x8000 C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_562933/basic-2.ino.partitions.bin 0xe000 C:\Users\Administrator\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.6/tools/partitions/boot_app0.bin 0x10000 C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_562933/basic-2.ino.bin 



C:\Users\Administrator\AppData\Local\Arduino15\packages\esp32\tools\esptool_py\4.2.1/

esptool.exe --chip esp32c3 --port COM7 --baud 921600 --before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 80m --flash_size 4MB

0x0 C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_562933/basic-2.ino.bootloader.bin 
0x8000 C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_562933/basic-2.ino.partitions.bin 
0xe000 C:\Users\Administrator\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.6/tools/partitions/boot_app0.bin 
0x10000 C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_562933/basic-2.ino.bin 


C:\Users\Administrator\AppData\Local\Arduino15\packages\esp32\tools\esptool_py\3.3.0>esptool.exe
esptool.py v3.3
usage: esptool [-h]
               [--chip {auto,esp8266,esp32,esp32s2,esp32s3beta2,esp32s3,esp32c3,esp32c6beta,esp32h2beta1,esp32h2beta2,esp32c2}]
               [--port PORT] [--baud BAUD] [--before {default_reset,usb_reset,no_reset,no_reset_no_sync}]
               [--after {hard_reset,soft_reset,no_reset,no_reset_stub}] [--no-stub] [--trace]
               [--override-vddsdio [{1.8V,1.9V,OFF}]] [--connect-attempts CONNECT_ATTEMPTS]
               {load_ram,dump_mem,read_mem,write_mem,write_flash,run,image_info,make_image,elf2image,read_mac,chip_id,flash_id,read_flash_status,write_flash_status,read_flash,verify_flash,erase_flash,erase_region,merge_bin,get_security_info,version}
               ...

esptool.py v3.3 - Espressif chips ROM Bootloader Utility

positional arguments:
  {load_ram,dump_mem,read_mem,write_mem,write_flash,run,image_info,make_image,elf2image,read_mac,chip_id,flash_id,read_flash_status,write_flash_status,read_flash,verify_flash,erase_flash,erase_region,merge_bin,get_security_info,version}
                        Run esptool {command} -h for additional help
    load_ram            Download an image to RAM and execute
    dump_mem            Dump arbitrary memory to disk
    read_mem            Read arbitrary memory location
    write_mem           Read-modify-write to arbitrary memory location
    write_flash         Write a binary blob to flash
    run                 Run application code in flash
    image_info          Dump headers from an application image
    make_image          Create an application image from binary files
    elf2image           Create an application image from ELF file
    read_mac            Read MAC address from OTP ROM
    chip_id             Read Chip ID from OTP ROM
    flash_id            Read SPI flash manufacturer and device ID
    read_flash_status   Read SPI flash status register
    write_flash_status  Write SPI flash status register
    read_flash          Read SPI flash content
    verify_flash        Verify a binary blob against flash
    erase_flash         Perform Chip Erase on SPI flash
    erase_region        Erase a region of the flash
    merge_bin           Merge multiple raw binary files into a single file for later flashing
    get_security_info   Get some security-related data
    version             Print esptool version

optional arguments:
  -h, --help            show this help message and exit
  --chip {auto,esp8266,esp32,esp32s2,esp32s3beta2,esp32s3,esp32c3,esp32c6beta,esp32h2beta1,esp32h2beta2,esp32c2}, -c {auto,esp8266,esp32,esp32s2,esp32s3beta2,esp32s3,esp32c3,esp32c6beta,esp32h2beta1,esp32h2beta2,esp32c2}
                        Target chip type
  --port PORT, -p PORT  Serial port device
  --baud BAUD, -b BAUD  Serial port baud rate used when flashing/reading
  --before {default_reset,usb_reset,no_reset,no_reset_no_sync}
                        What to do before connecting to the chip
  --after {hard_reset,soft_reset,no_reset,no_reset_stub}, -a {hard_reset,soft_reset,no_reset,no_reset_stub}
                        What to do after esptool.py is finished
  --no-stub             Disable launching the flasher stub, only talk to ROM bootloader. Some features will not be
                        available.
  --trace, -t           Enable trace-level output of esptool.py interactions.
  --override-vddsdio [{1.8V,1.9V,OFF}]
                        Override ESP32 VDDSDIO internal voltage regulator (use with care)
  --connect-attempts CONNECT_ATTEMPTS
                        Number of attempts to connect, negative or 0 for infinite. Default: 7.

# read flash 
esptool.exe --baud 115200 --port COM66 --baud 115200 read_flash 0 2097152 output.bin

esptool.exe --baud 115200 --port COM66 --baud 921600 read_flash 0 2097152 output.bin



### ESP8266

C:\Users\Administrator\AppData\Local\Arduino15\packages\esp8266\tools\python3\3.7.2-post1/python3 -I C:\Users\Administrator\AppData\Local\Arduino15\packages\esp8266\hardware\esp8266\3.0.2/tools/upload.py --chip esp8266 --port COM162 --baud 921600 --before default_reset --after hard_reset write_flash 0x0 C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_397525/webserver-path-1.ino.bin

