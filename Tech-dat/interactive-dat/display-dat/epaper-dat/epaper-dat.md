
# e-paper-dat



## repo 

- display - https://github.com/Edragon/RPI_Display
- display 2 - https://github.com/Edragon/Display-E-paper
- epaper - https://github.com/Edragon/Display-E-paper


## E-paper 2.13"

please find demo code in epaper repo above, we have V1, V2, V3 versions, currently selling version is V3. If not working please try from the V3 version to the V1.

![](2025-06-12-20-42-41.png)

## command 

[[C-dat]] == ./epd

[[python-dat]] 

    root@raspberrypi:/home/pi/RPI-Display-main/2.13inch_e-Paper_HAT-code/raspberrypi/python# python epd2in13.py

    python /home/pi/RPI-Display-main/2.13inch_e-Paper_HAT-code/raspberrypi/python/epd2in13.py





## SCH 

ESP8266 drive 

![](2025-08-19-15-06-08.png)

![](2025-08-19-15-06-34.png)


### BS 

BS = 0 = GND = 4 line spi 默认
BS = 1 = 3V3 = 3 line spi

the main control part 

![](2025-08-19-15-14-11.png)

| dimension          | resistor |
| ------------------ | -------- |
| 1.54               | 3R       |
| 2.13               | 3R       |
| 2.9                | 3R       |
| 2.7                | 0.47R    |
| 4.2                | 0.47R    |
| 7.5                | 0.47R    |
| 以及所有尺寸三色屏 | 0.47R    |

## ESP8266 

| EPD      | ESP8266 |
| -------- | ------- |
| EPD_BUSY | 105     |
| EPD_RST  | 102     |
| EPD_DC   | 104     |
| EPD_CS   | 1015    |
| EPD_CLK  | 1014    |
| EPD_DIN  | 1013    |
| 3V3      | 3V3     |
| GND      | GND     |




## ref 

- [[display-dat]]

