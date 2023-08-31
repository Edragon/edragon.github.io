
# ILC1073 dat 

* Automatically support 1602 or 2004 type [[char LCDs]]
* Github Original Project - https://github.com/harbaum/LCD2USB
* Install [[USB-Driver]] libusb-win32



## Firmware flash command

    avrdude -c usbasp-clone -p m8 -U flash:w:"E:\Git-category\Git-AVR\AVR_firmware\Firmware\LCD2USB\firmware.hex":a -U lfuse:w:0x9F:m -U hfuse:w:0xC9:m 



## Schematic 

![](2023-08-31-17-52-56.png)

## ref 

- origin project - https://github.com/harbaum/LCD2USB

