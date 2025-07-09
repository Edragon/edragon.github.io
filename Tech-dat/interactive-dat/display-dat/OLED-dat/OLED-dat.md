
# OLED-dat



[legacy wiki page](https://www.electrodragon.com/w/0.96%27%27_128*64_OLED_Display)

drive interface - [[I2C-dat]] - [[SPI-dat]]

## boards 

- [[IOD1003-dat]] - [[IOD1001-dat]] - [[IOD1004-dat]] - [[IOD1005-dat]]


- [[ESP32-ISO-dat]]

- [[MPC1090-dat]]





## PCB OLED 

### 0.96"

- [[IOD1003-dat]] - [[IOD1001-dat]]

https://www.electrodragon.com/product/0-96-12864-oled-display-iicspi/

![](2025-06-13-13-04-15.png)

![](2025-06-13-13-04-55.png)

#### specs 

![](2025-06-13-13-04-37.png)

#### Pin definitions and Wiring  

![](2025-06-13-13-05-20.png)

![](2025-06-13-13-06-20.png)

#### Dimension 

![](2025-06-13-13-06-08.png)


### 1.3"

- [[IOD1004-dat]] - [[IOD1005-dat]]

https://www.electrodragon.com/product/1-3-12864-blue-oled-display-iicspi/

![](2025-06-13-12-56-54.png)

![](2025-06-13-13-01-36.png)

#### specs 

![](2025-06-13-13-02-02.png)

#### Pin definitions and Wiring

![](2025-06-13-13-02-28.png)

![](2025-06-13-13-03-18.png)

#### Dimension 

![](2025-06-13-13-02-46.png)


### demo video 

- https://www.youtube.com/watch?v=-S0XRB664-M&feature=youtu.be

- https://www.youtube.com/watch?v=-S0XRB664-M&feature=youtu.be





## RAW OLED 

### 0.96"



![](2025-06-13-12-47-55.png)

#### Specs

![](2025-06-13-12-48-39.png)

#### Pin Definitions, dimensions 

![](2025-06-13-12-49-07.png)

![](2025-06-13-12-49-32.png)

### 1.3"


![](2025-06-13-12-52-44.png)

#### Specs 

![](2025-06-13-12-53-14.png)

#### Pin Definitions, dimensions

![](2025-06-13-12-54-41.png)

![](2025-06-13-12-55-00.png)

## OLED Driver 

- [[SH1106-dat]] - [[SSD1306-dat]] - [[oled-driver-dat]] - [[SSD1315-dat]]


## code 



### init 

    SSD1306Wire display(0x3c, 12, 2);   // ADDRESS, SDA, SCL , ESP32 pin IO12 for SDA and IO2 for SCL
    SSD1306Wire display(0x3c, 15, 13);

### arduino OLED library 

- [SSD1306ascii](https://github.com/greiman/SSD1306Ascii)

### ESP8266_and_ESP32_OLED_driver_for_SSD1306_displays

code

    display.init();
    delay(50);
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);

    display.setFont(ArialMT_Plain_16);
    display.drawString(0, 0, "Temp: ");
    display.drawString(50, 0, String(temperature));

    display.setFont(ArialMT_Plain_16);
    display.drawString(0, 20, "Press: ");
    display.drawString(50, 20, String(pressure));


### common OLED I2C address

- 0x3C = the version we are selling

## SCH 

### using with STM32 SPI2 

![](2024-01-13-17-43-38.png)


### SCH 2 I2C+RESET 

![](2025-07-09-18-51-53.png)



## repositories 

- https://github.com/Edragon/Display_OLED-HDK
- https://github.com/Edragon/Display_OLED
- demo code - https://github.com/Edragon/Arduino-ESP32/tree/master/Sketchbook/driver-interactive/OLED/SSD1306SimpleDemo

- [oled](https://github.com/Edragon/Interactive-Display_OLED)





## ref 

- [[display-dat]]

- [[arduino-lib-dat]]

- [[display]] - [[OLED]] 