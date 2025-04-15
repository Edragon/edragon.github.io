
# ILC1073 dat 

## Info 
* Automatically support 1602 or 2004 type [char LCDs](https://w.electrodragon.com/w/Category:Char_LCDs)

* Install USB-driver libusb-win32 - [[usb-dat]]

[1602 LCD USB Mini Drive Board, RPI Driver Free](https://www.electrodragon.com/product/1602-lcd-usb-mini-drive-board-rpi-driver-free/)



## hardware 

Schematic 

![](2023-08-31-17-52-56.png)



Board Map 

![](2025-04-15-16-08-08.png)

Pin Definitions 

- 2-way jumper connect the button to MISO or Reset PE4-RST
- 1-way jumper connect PC4 (EN1) to +5V

- Programmer Buttons Key1 == PB0 and Key2 == PB1


## Software 

### Use on Windows : 

- https://github.com/harbaum/LCD2USB/blob/master/contrib/LCD2USB-smartie.zip
- libusb-win32 need to be installed 

![](2023-09-13-13-48-16.png)

### Firmware flash command

    avrdude -c usbasp-clone -p m8 -U flash:w:"E:\Git-category\Git-AVR\LCD2USB-master\firmware\firmware.hex":a -U lfuse:w:0x9F:m -U hfuse:w:0xC9:m 
    avrdude -c usbasp -p atmega8 -U lfuse:w:0x9f:m -U hfuse:w:0xc9:m -U flash:w:firmware-avrusb.hex

- [[usbasp-dat]]

### Debug 

- tune the brightness if nothing show up
- contrast is also set in default firmware, pre-uploaded
  
lcd2USB.c 
  
    /* target is value to set */
    #define LCD_SET_CONTRAST   (LCD_SET | (0<<3))
    #define LCD_SET_BRIGHTNESS (LCD_SET | (1<<3))
    #define LCD_SET_RESERVED0  (LCD_SET | (2<<3))
    #define LCD_SET_RESERVED1  (LCD_SET | (3<<3))

## Demos 

Need to set contrast 
- https://twitter.com/electro_phoenix/status/987251467861061632

python with lcd2usb 
- pip install lcd2usb

test application 
- https://github.com/harbaum/LCD2USB/tree/master/testapp

![](2023-09-19-18-48-30.png)


## ref 

- origin project - https://github.com/harbaum/LCD2USB
- python library - https://github.com/xyb/lcd2usb
- [[avrdude-dat]]

- [[atmega8]]