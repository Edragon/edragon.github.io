# e-paper-dat


## board

- [[MPC1091-dat]]

## controller mainly by bluetooth

- [[TELINK-dat]] - [[da14585-dat]]

- [[NRF5x-dat]] - [[nordic-dat]]


## working principle 


Electronic ink screens, also known as e-paper, commonly use "microcapsule electrophoretic display" technology (EPD). The basic principle is that charged nanoparticles suspended in liquid migrate under the influence of an electric field. Electronic ink is coated onto a layer of plastic film, which is then laminated with a thin-film transistor (TFT) circuit. The pixel pattern is formed by controlling the drive IC.

Electronic ink consists of millions of microcapsules, each about the diameter of a human hair. Each microcapsule contains electrophoretic particles—negatively charged white particles and positively charged black particles—suspended in a transparent liquid.

Using the principle of attraction between positive and negative charges, when the electric field is applied, the corresponding black or white particles move to the top of the microcapsule, allowing the user to see white or black in that area.

![](EDP-1.gif)

Most common e-paper is black and white. Electronic price tags also use a type of three-color e-ink screen, which operates similarly to the two-color system. By applying different voltages, different colored particles move to the top layer, allowing different colors to be seen.

![](EDP-1.gif)

常见的电子纸是黑白色的，电子价签还有一种三色电子墨水屏，系统运作原理与双色系统类似，施加不同的电压，使不同颜色的粒子移动至上层，看见不同的颜色。

![](EPD-CN.gif)


## Advantages and Applications

E-paper screens are easy to read: e-paper displays rely on reflecting ambient light to show images, giving them a print-like effect similar to paper.

Lightweight and flexible: Due to their simple structure and the fact that e-paper is based on soft plastic film material, they are naturally flexible and bendable, and can be cut into various shapes as needed.

Energy-saving: When displaying static images, e-paper consumes no power at all. Even if all power is disconnected, the e-paper display can still retain the last image.

For example, the smart card below uses e-paper technology and can display the balance.

![](2025-08-19-15-20-54.png)

There is also this type of NFC passive smart tag, which can refresh its display content via a mobile phone's NFC. It can be used as an electronic pet tag, electronic luggage tag, to display payment QR codes in stores, or to show a contact number for moving a car.

![](2025-08-19-15-21-10.png)

## second-hand epaper module 

![](2025-08-19-15-22-15.png)




## HDK 

墨水屏内置驱动器 IC，采用 COG 封装， IC 厚度 300um，根据 FPC（柔性电路板）宽度的不同，分为 24P 和 34P。墨水屏正面朝向自己，排线朝左边，从上往下分别是引脚 1-24。


## E-paper 2.13"

please find demo code in epaper repo above, we have V1, V2, V3 versions, currently selling version is V3. If not working please try from the V3 version to the V1.

![](2025-06-12-20-42-41.png)

## command 

[[C-dat]] == ./epd

[[python-dat]] 

    root@raspberrypi:/home/pi/RPI-Display-main/2.13inch_e-Paper_HAT-code/raspberrypi/python# python epd2in13.py

    python /home/pi/RPI-Display-main/2.13inch_e-Paper_HAT-code/raspberrypi/python/epd2in13.py







### BS 

BS = 0 = GND = 4 line spi 默认
BS = 1 = 3V3 = 3 line spi

the main control part 

![](2025-08-19-15-14-11.png)

| dimension          | resistor |   |
|--------------------|----------|---|
| 1.54               | 3R       |   |
| 2.13               | 3R       |   |
| 2.9                | 3R       |   |
| 2.7                | 0.47R    |   |
| 4.2                | 0.47R    |   |
| 7.5                | 0.47R    |   |
| 以及所有尺寸三色屏 | 0.47R    |   |

When RESE is set to 0.47 :

1.54 inch ：GDEW0154T8、GDEW0154I9F、GDEW0154Z17、GDEW0154Z04、GDEW0154C39
2.13 inch ：GDEW0213T5、GDEW0213I5F、GDEW0213Z16、GDEW0213C38
2.6 inch ：GDEW026T0、GDEW026Z3
2.7 inch ：GDEW027W3、GDEW027C44
2.9 inch ：GDEW029T5、GDEW029I6F、GDEW029Z10、GDEW029C32
3.71 inch ：GDEW0371W7、GDEW0371Z80
4.2 inch ：GDEW042T2、GDEW042Z15、GDEW042C375.83 inch ：GDEW0583T8、GDEW0583Z21、GDEW0583Z83、GDEW0583C64
7.5 inch ：GDEW075T7、GDEW075Z08、GDEW075Z09、GDEW075C21、GDEW075C64

When RESE is set to 3 :

1.54 inch ：GDEP015OC1、GDEH0154D67、GDEM0154E97LT2.04 inch ：GDE021A1
2.13 inch ：GDEH0213B73、GDEH0213D30LT、GDEM0213E28LT2.9 inch ：GDEH029A1、GDEH029D56LT、GDEM029E27LT5.83 inch ：GDEW0583T7
7.5 inch ：GDEW075T8

## ESP8266 

| EPD      | ESP8266 |
| -------- | ------- |
| EPD_BUSY | 5     |
| EPD_RST  | 2     |
| EPD_DC   | 4     |
| EPD_CS   | 15    |
| EPD_CLK  | 14    |
| EPD_DIN  | 13    |
| 3V3      | 3V3     |
| GND      | GND     |


    /* SPI pin definition --------------------------------------------------------*/
    // SPI pin definition
    #define CS_PIN 15
    #define RST_PIN 2
    #define DC_PIN 4
    #define BUSY_PIN 5

    /* Pin level definition ------------------------------------------------------*/
    #define LOW 0
    #define HIGH 1

    #define GPIO_PIN_SET 1
    #define GPIO_PIN_RESET 0


## e-paper versions 

l"54
- 1"54_V2
- 1"54b_V2
- 1"54b
- l"54c
- l"54

2"7
- 2"7b_V2
- 2"7b
- 2"7

2"9
- 2"9_V2
- 2"9b_V2
- 2"9bc
- 2"9d
- 2"9

2"13
- 2"13_V2
- 2"13_V3
- 2"13b_V3
- 2"13bc
- 2"13d
- 2"13

- QYEG0213BNS800

| Brand         | Model           | Type | Size | Color   | Note   | Resolution   | Interface | Pins | Controller | Extra     |
|---------------|----------------|------|------|---------|--------|--------------|-----------|------|------------|-----------|
| Good Display  | GDEW0213C38    | EINK | 2.13 | B/W/Y   |        | 212 x 104    | SPI       | 24   | IL0373     |           |
| Good Display  | GDEW0213Z16    | EINK | 2.13 | B/W/R   |        | 212 x 104    | SPI       | 24   | IL0373     |           |
| Good Display  | GDEH0213B72    | EINK | 2.13 | B/W     |        | 250 x 122    | SPI       | 24   | SSD1675A   | EOL       |
| Good Display  | GDEH0213B1     | EINK | 2.13 | B/W     |        | 250 x 122    | SPI       | 24   | SSD1675B   |           |
| Good Display  | GDEH0213B73    | EINK | 2.13 | B/W     |        | 250 x 122    | SPI       | 24   | SSD1675B   | EOL       |
| Good Display  | GDEH0213D30LT  | EINK | 2.13 | B/W     |        | 212 x 104    | SPI       | 24   | SSD1675B   | Freezer   |
| Good Display  | GDEH0213Z98    | EINK | 2.13 | B/W/R   |        | 250 x 122    | SPI       | 24   | SSD1680    |           |
| Good Display  | GDEM0213B74    | EINK | 2.13 | B/W/R   |        | 250 x 122    | SPI       | 24   | SSD1680    |           |
| Good Display  | GDEM0213C90    | EINK | 2.13 | B/W/Y   |        | 250 x 122    | SPI       | 24   | SSD1680    |           |
| Good Display  | GDEW0213I5F    | EINK | 2.13 | B/W     | 2bpp   | 212 x 104    | SPI       | 24   | UC8151c    | Flexible  |
| Good Display  | GDEW0213I5FV1  | EINK | 2.13 | B/W     | 2bpp   | 212 x 104    | SPI       | 24   | UC8151c    |           |
| Good Display  | GDEH0213Z19    | EINK | 2.13 | B/W/R   |        | 212 x 104    | SPI       | 24   | UC8151d    |           |
| Good Display  | GDEW0213M21    | DES  | 2.13 | B/W/R   |        | 212 x 104    | SPI       | 24   | UC8151d    |           |
| Good Display  | GDEW0213T5     | EINK | 2.13 | B/W     | 2bpp   | 212 x 104    | SPI       | 24   | UC8151d    |           |
| Good Display  | GDEW0213T5D    | EINK | 2.13 | B/W     | 2bpp   | 212 x 104    | SPI       | 24   | UC8151d    |           |
| Good Display  | GDEW0213V7LT   | EINK | 2.13 | B/W     |        | 212 x 104    | SPI       | 24   | UC8151d    | Freezer   |


2"66
- 2"66b
- 2"66

3"7
- 3"7

4"01
- 4"01f

4"2
- 4"2b_V2
- 4"2bc
- 4"2

5"65
- 5"65f

5"83
- 5"83_V2
- 5"83_V2
- 5"83b_V2
- 5"83bc
- 5"83

7"5

- 7"5_HD
- 7"5_V2
- 7"5b_HD
- 7"5bc_V2
- 7"5bc
- 7"5




## common pins 


**GDR (Gate Driver Reset)**: This pin is typically used to reset the gate driver circuitry inside the ePaper module. It helps initialize or clear the gate driver logic before starting a new display update.

**RESET**: This pin resets the entire ePaper display controller, putting it into a known default state. It is usually toggled during power-up or before communication to ensure reliable operation.

- [[test-point-dat]]


## repo 




- display - https://github.com/Edragon/RPI_Display
- epaper - https://github.com/Edragon/Display-E-paper

arduino library == esp8266-waveshare-epd

https://github.com/CursedHardware/epd-datasheet/tree/main

https://github.com/waveshareteam/e-Paper

https://github.com/adafruit/Adafruit_EPD
- support SSD1675B / SSD1675 / SSD1680


## 4.Problems of designing drive circuit

- 4.1 Self-made drive board cannot drive e-papers
- Measure the voltage of PREVGH and PREVGL to see if it boost successfully. If it doesn’t boost successfully, check if the boostpart of the schematic is correct and the components meet therequirements. (Make sure the max voltage of the booster capacitor is adequate. If it is not enough, the capacitor will beburned out during boost.) Check the welding, the most likelyproblem is the MOS tube. If it boost successfully, please checkwhether there is virtual welding in FPC socket and so on, andfinally check the software.
- 4.2 Inductors selection for e-paper drive circuit
- A 10uH 1A winding inductor is recommended.
- 4.3 MOS tube selection for e-paper drive circuit
- Si1304BDL or Si1308EDL is recommended. If these two aredifficult to get, AO3400 can be a substitute.
- 4.4 Diode selection for e-paper drive circuit
- A schottky diode equivalent to the MBR0530 parameters isrecommended. And the switching frequency should meet theactual requirements.



- [[epaper-database-dat.csv]]



## SCH 

ESP8266 drive 

![](2025-08-19-15-06-08.png)

![](2025-08-19-15-06-34.png)

### basic SCH 

![](2025-08-26-20-59-36.png)

## driver chip 

[[SSD1673A]] 
- Holitech,HINK-E0213A01,EINK,2.13,B/W,,250 x 122,SPI,24,SSD1673A,,

[[SSD1675B]]
- Holitech,HINK-E0213A09,EINK,2.13,B/W,,212 x 104,SPI,24,SSD1675B,,
- Holitech,HINK-E0213A07,EINK,2.13,B/W/R,,212 x 104,SPI,24,SSD1675B,,


## tools 

设计工具 https://epd.eled.top/



## ref 

- [[display-dat]] - [[epaper]]

- [[FPC-dat]] - [[test-point-dat]] - [[diode-dat]] - [[mosfet-dat]]

- [[arduino-cli-dat]]


