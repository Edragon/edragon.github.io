
# UF2-dat

uf2 - https://github.com/Microsoft/uf2


UF2 is a file format, developed by Microsoft for PXT (also known as Microsoft MakeCode), that is particularly suitable for flashing microcontrollers over MSC (Mass Storage Class; aka removable flash drive).




Making your own UF2

To create your own UF2 DFU update image, simply use the Python conversion script on a .bin file or .hex file, specifying the family as 0xADA52840 (nRF52840) or 0x621E937A (nRF52833).

nRF52840

    uf2conv.py firmware.hex -c -f 0xADA52840


How to compile and build

You should only continue if you are looking to develop bootloader for your own. You must have have a J-Link available to "unbrick" your device.

Prerequisites
- [[ARM-GCC-dat]]
  
- Nordic's nRF5x Command Line Tools - [[nrf5x-sdk-dat]]

- [[Python-IntelHex-dat]] - [[python-dat]]



## ref 

- [[nrf5x-sdk-dat]]