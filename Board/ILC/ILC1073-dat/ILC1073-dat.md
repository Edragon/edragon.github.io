
# ILC1073 dat 

* Automatically support 1602 or 2004 type [char LCDs](https://w.electrodragon.com/w/Category:Char_LCDs)

* Install USB-driver libusb-win32 - [[usb-dat]]


## Use on Windows : 

- https://github.com/harbaum/LCD2USB/blob/master/contrib/LCD2USB-smartie.zip
- libusb-win32 need to be installed 


## Firmware flash command

    avrdude -c usbasp-clone -p m8 -U flash:w:"E:\Git-category\Git-AVR\AVR_firmware\Firmware\LCD2USB\firmware.hex":a -U lfuse:w:0x9F:m -U hfuse:w:0xC9:m 

method 2 

    avrdude -c usbasp -p atmega8 -U lfuse:w:0x9f:m -U hfuse:w:0xc9:m -U flash:w:firmware-avrusb.hex


## Schematic 

![](2023-08-31-17-52-56.png)


## Debug 

- tune the brightness if nothing show up


## ref 

- origin project - https://github.com/harbaum/LCD2USB
