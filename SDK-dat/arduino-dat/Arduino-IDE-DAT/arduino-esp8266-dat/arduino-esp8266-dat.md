
# arduino-esp8266-dat


## Arduino flash 

commands 

    C:\Users\Administrator\AppData\Local\Arduino15\packages\esp32\tools\esptool_py\4.5.1/esptool.exe --chip esp32c3 --port COM162 --baud 921600 --before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 80m --flash_size 4MB 0x0 C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_749057/NWI1119-AP-1.ino.bootloader.bin 0x8000 C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_749057/NWI1119-AP-1.ino.partitions.bin 0xe000 C:\Users\Administrator\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9/tools/partitions/boot_app0.bin 0x10000 C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_749057/NWI1119-AP-1.ino.bin 



## files 

- 0x0 C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_749057/NWI1119-AP-1.ino.bootloader.bin 
- 0x8000 C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_749057/NWI1119-AP-1.ino.partitions.bin 
- 0xe000 C:\Users\Administrator\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9/tools/partitions/boot_app0.bin 
- 0x10000 C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_749057/NWI1119-AP-1.ino.bin 
