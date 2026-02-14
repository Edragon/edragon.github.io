
# arduino-esp8266-dat

https://arduino.esp8266.com/stable/package_esp8266com_index.json

## boards 

- Generic ESP8266 Module
- Generic ESP8285 Module
- 4D Systems gen4 loD Range
- Adafruit Feather HUZZAH ESP8266
- Amperka WiFi Slot
- Arduino
- DOIT ESP-Mx DevKit (ESP8285)
- Digistump Oak
- ESPDuino (ESP-13 Module)
- ESPectro Core
- ESPino (ESP-12 Module)
- ESPresso Lite 1.0
- ESPresso Lite 2.0
- ITEAD Sonoff
- Invent One
- LOLIN(WEMOS) D1 R2 & mini
- LOLIN(WEMOS) D1 mini (clone)
- LOLIN(WEMOS) D1 mini Lite
- LOLIN(WEMOS) D1 mini Pro
- LOLIN(WeMos) D1 R1 - [[NWI1083-dat]]
- Lifely Agrumino Lemon v4 
- NodeMCU 0.9 (ESP-12 Module)
- NodeMCU 1.0 (ESP-12E Module)
- Olimex MOD-WIFI-ESP8266(-DEV)
- Phoenix 1.0
- Phoenix 2.0
- Schirmilabs Eduino WiFi
- Seeed Wio Link
- SparkFun Blynk Board
- SparkFun ESP8266 Thing
- SparkFun ESP8266 Thing Dev
- SweetPea ESP-210
- ThaiEasyElec's ESPino
- WiFi Kit 8
- WiFiduino
- Wiflnfo
- XinaBox CW01

## config 

- Board: "Generic ESP8266 Module"
- Builtin Led: "2"
- Upload Speed: "115200"
- CPU Frequency: "80 MHz"
- Crystal Frequency: "26 MHz"
- Flash Size: "1MB (FS:64KB OTA:~470KB)"
- Flash Mode: "DOUT (compatible)
- Flash Frequency: "40MHz"
- Reset Method: "dtr (aka nodemcu)"
- Debug port: "Disabled"
- Debug Level: "None""
- IwlP Variant: "v2 Lower Memory”
- VTables: "Flash"
- C++ Exceptions: "Disabled (new aborts on oom)"
- Stack Protection:"Disabled"
- **Erase Flash: "All Flash Contents"**
- Espressif FW: "nonos-sdk 2.2.1+ 100 (190703)
- SSL Support: "All SSL ciphers (most compatible)"
- MMU: "32KB cache + 32KB IRAM (balanced)
- Non-32-Bit Access: "Use pgm_read macros for IRAM/PROGMEM"
- Port: "COM252 (Elecrow CrowPanel 7.0P)"
- Get Board Info


## Arduino flash 

commands 

    C:\Users\Administrator\AppData\Local\Arduino15\packages\esp32\tools\esptool_py\4.5.1/esptool.exe --chip esp32c3 --port COM162 --baud 921600 --before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 80m --flash_size 4MB 0x0 C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_749057/NWI1119-AP-1.ino.bootloader.bin 0x8000 C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_749057/NWI1119-AP-1.ino.partitions.bin 0xe000 C:\Users\Administrator\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9/tools/partitions/boot_app0.bin 0x10000 C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_749057/NWI1119-AP-1.ino.bin 



## files 

- 0x0 C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_749057/NWI1119-AP-1.ino.bootloader.bin 
- 0x8000 C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_749057/NWI1119-AP-1.ino.partitions.bin 
- 0xe000 C:\Users\Administrator\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9/tools/partitions/boot_app0.bin 
- 0x10000 C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_749057/NWI1119-AP-1.ino.bin 


## ref 

- [[arduino-boards-dat]]