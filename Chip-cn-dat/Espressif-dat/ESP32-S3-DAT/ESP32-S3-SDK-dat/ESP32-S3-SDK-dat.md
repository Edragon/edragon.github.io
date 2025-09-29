
# ESP32-S3-SDK-dat.md

- [[ESP32-S3-dat]]

- [[ESP-SDK-dat]] - [[ESP32-SDK-dat]]

- [[circuitpython-ESP32-s3-dat]]


    esptool erase-flash
    esptool v5.0.1
    Connected to ESP32-S3 on COM14:
    Chip type:          ESP32-S3 (QFN56) (revision v0.2)
    Features:           Wi-Fi, BT 5 (LE), Dual Core + LP Core, 240MHz, Embedded PSRAM 8MB (AP_3v3)
    Crystal frequency:  40MHz
    MAC:                cc:ba:97:04:db:c0


REPL is on the USB-OTG connector.

## resources 

- [[protocols-dat]]


## features 

- [[USB-MSC-dat]] 
- [[USB-MTP-dat]] 

- [[USB-dat]] - [[USB-OTG-dat]] - [[tinyUSB-dat]]

- [[zigbee-dat]]

- [[ESP32-USB-dat]]





## ESP32-S3


### USB CDC On Boot

The chip exposes a USB CDC (virtual COM) at boot via the ROM “USB Serial/JTAG” peripheral. You get serial console logs and can flash with

- [] enable 
- [] disable 
  
### USB DFU On Boot

The firmware enumerates as USB DFU class at boot (TinyUSB). You can update the app with dfu-util. Not the ROM bootloader.

- [] enable 
- [] disable 

Short answer: “App” means your firmware application image (factory/OTA slot like ota_0/ota_1), not the ROM bootloader.

- USB DFU on ESP32‑S3 is provided by your running app via TinyUSB.
- dfu-util updates the application partition(s) that your app exposes (factory or OTA slots).
- It does not use or update the ROM bootloader (immutable) and typically not the ESP‑IDF second‑stage bootloader in flash unless you explicitly implement that.
- To flash bootloader/partition table, use esptool via UART0 or USB Serial/JTAG (ROM downloader).

### USB Firmware MSC On Boot:

- [] Disabled
- [] Enabled (Requires USB-OTG Mode)

### USB Mode 

- [] Hardware CDC and JTAG - Uses the ROM “USB Serial/JTAG” composite device. Provides CDC (console/flashing) and JTAG debugging over the same USB. Lightweight, but limited to CDC+JTAG only.
- [] USB-OTG (TinyUSB) - Runs the full TinyUSB stack. Lets you expose CDC, MSC, MTP, HID, etc., or act as USB host. Incompatible with USB Serial/JTAG while active (no JTAG-over-USB).

### Upload Mode 

- [] UARTO / Hardware CDC - Official ROM download channels for esptool (UART0 pins or USB Serial/JTAG). Reliable for flashing and logs.
- [] USB-OTG CDC (TinyUSB) - App‑level CDC provided by TinyUSB. Good for REPL/console, but not for ROM flashing with esptool unless your app explicitly reboots to the ROM downloader.




## error log 

    E (291) quad_psram: PSRAM ID read error: 0x00ffffff, PSRAM chip not found or not supported, or wrong PSRAM line mode
    E (291) esp_psram: PSRAM enabled but initialization failed. Bailing out.
    MicroPython v1.25.0 on 2025-04-15; Generic ESP32S3 module with ESP32S3




## board 

- [[NWI1126-dat]]

## ref 

- [[ESP32-S3-dat]] 

- [[ESP32-S3]] - [[ESP32-S3-SDK]]