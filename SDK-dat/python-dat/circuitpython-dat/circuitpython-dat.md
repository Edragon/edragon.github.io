
# circuitpython-dat

- [[circuitpython-esp32-s3-dat]]

- [[settings.toml]] setup and print wifi info [[w.py]]

circuitpython 
- board
- digitalio
- wws_74hc165


https://github.com/adafruit/circuitpython




## UF2 bootloader 


### Start the UF2 Bootloader

Nearly all CircuitPython boards ship with a bootloader called UF2 (USB Flashing Format) that makes installing and updating CircuitPython a quick and easy process. The bootloader is the mode your board needs to be in for the CircuitPython .uf2 file you downloaded to work. If the file you downloaded that matches the board name ends in uf2 then you want to continue with this section. However, if the file ends in .bin, you have to do a more complex installation - go to this page for details.

Espressif Boards without UF2 Bootloaders

See [this page](https://learn.adafruit.com/circuitpython-with-esp32-quick-start/installing-circuitpython) for how to load a .bin file on an ESP32 or ESP32-C3 board.

https://learn.adafruit.com/welcome-to-circuitpython/non-uf2-installation

https://circuitpython.org/board/doit_esp32_devkit_v1/

https://downloads.circuitpython.org/bin/doit_esp32_devkit_v1/en_US/adafruit-circuitpython-doit_esp32_devkit_v1-en_US-9.2.8.bin

The next step is to write your credentials to settings.toml. Make sure your board is running CircuitPython. If you just installed CircuitPython, you may to reset the board first.

Successfully Completed

You can edit files by going to http://000.0.0.0/code/.

If the keys CIRCUITPY_WIFI_SSID and CIRCUITPY_WIFI_PASSWORD are set in settings.toml, CircuitPython will automatically connect to the given Wi-Fi network on boot and upon reload.

## CircuitPython on ESP32 Quick Start

https://learn.adafruit.com/circuitpython-with-esp32-quick-start

    esptool.py --port COM13 erase_flash
    esptool.py --chip esp32 --port /dev/tty.usbserial-1144440 erase_flash
    esptool.py --port /dev/tty.usbserial-1144440 write_flash -z 0x0 firmware.bin

repl 

    rst:0x1�        �]I=9}IMQ�,boot:0x13 (SPI_FAST_FLASH_BOOT)
    configsip: 0, SPIWP:0xee
    �G��DIO, 덭LC!�+��0x3fff0040,len:400s0_drv:0x00,hd_drv80x00 7�E�v���0
    load:0x40078000,len:14048
    load:0x40080400,len:4
    lod:0x40080404,len: �z
    Adafruit CircuitPython 10.0.0-beta.0 on 2025-07-15; ESP32 Devkit V1 with ESP32
    Board ID:doit_esp32_devkit_v1
    UID:0125C196358A
    MAC:18:0E:FD:3F:20:38

    Auto-reload is on. Simply save files over USB to run them or enter REPL to disable.
    code.py output:
    Hello World!

    Code done running.

    Press any key to enter the REPL. Use CTRL-D to reload.

installing [[settings.toml]] and using wifi 

    import wifi

    print("My MAC addr: %02X:%02X:%02X:%02X:%02X:%02X" % tuple(wifi.radio.mac_address))
    print("My IP address is", wifi.radio.ipv4_address)


mpremote connect COM6 fs cp settings.toml :

    mpremote connect COM6 fs put w.py :                
    put :w.py
    put :

    mpremote connect COM6 run w.py     
    My MAC addr: 10:52:1C:69:53:A8
    My IP address is 192.168.79.226


## driver and libs 

https://docs.circuitpython.org/projects/bundle/en/latest/drivers.html

pip3 install adafruit-circuitpython-busdevice

Warning

This module requires the CircuitPython imagecapture module which is only in the unreleased development version ("Absolute Newest") of CircuitPython and is only supported on specific boards.

The CircuitPython build for your board must support the ``imagecapture`` module.

### OV2640 

- [[adafruit_ov2640.py]] - [[ov2640_micropython_test.py]] - [[ov2640_simpletest.py]]

- https://github.com/adafruit/Adafruit_CircuitPython_OV2640

- https://docs.circuitpython.org/projects/ov2640/en/latest/


### pycamera

- https://github.com/adafruit/Adafruit_PyCamera






## reference code 

- https://github.com/adafruit/Adafruit_Learning_System_Guides/tree/main/CircuitPython_Essentials

