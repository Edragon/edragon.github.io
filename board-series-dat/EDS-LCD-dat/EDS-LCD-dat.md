# EDS-LCD-dat

legacy wiki page 
- https://w.electrodragon.com/w/Category:TFT_LCDs


## Versions 

- 1.8” SPI LCD, ST7735, 128*160, with SD card slot
- 2.2” SPI LCD, ILI9341 240*320, with SD card slot
- 2.4” SPI LCD, ILI9341 240*320,  with SD card slot, with touch panel
- 2.8” SPI LCD, ILI9341 240*320, with SD card slot, with touch panel
- 3.2” SPI LCD, ILI93141 240*320, with SD card slot, with touch panel
- 4.0” SPI LCD, ST7796S 480*320, with SD card slot, with touch panel


## Pin Definitions 

| Pins | Pins Funcs | Note                                                                                            |     |
| ---- | ---------- | ----------------------------------------------------------------------------------------------- | --- |
| 1    | VCC        | 5V/3.3V power input                                                                             |
| 2    | GND        | ground                                                                                          |
| 3    | CS         | LCD chip select signal, low level enable                                                        |
| 4    | RESET      | LCD screen reset signal, low level reset                                                        |
| 5    | DC/RS      | LCD screen register/data selection signal, 0: register, 1. data                                 |
| 6    | SDI(MOSI)  | SPI bus write data signal                                                                       |
| 7    | SCK        | SPI bus clock signal                                                                            |
| 8    | LED        | Backlight control, high level lights up, if no control is needed, connect to 3.3V to keep it on |
| 9    | SDO(MISO)  | SPI Bus read data signal, if no reading function is needed, it does not need to be connected    |
| 10   | T_CLK      | Touch SPI bus clock signal                                                                      |
| 11   | T_CS       | Touch screen chip select signal, low level enable                                               |
| 12   | T_DIN      | Touch SPI bus input                                                                             |
| 13   | T_DO       | Touch SPI bus output                                                                            |
| 14   | T_IRQ      | Touch screen interrupt signal, low level when touch is detected                                 |

Note: The 2.2-inch SPI module has no touch pins and has 9 PINs. The 2.4/2.8/3.2/3.5/4.0 modules with touch have 14 PIN standard pins.


## repo 

- https://github.com/Edragon/Display-LCD-SPI

- https://github.com/lcdwiki/LCDWIKI_gui.git


## ref

- [[ILC0011-dat]]

- [[EDS-LCD]]
