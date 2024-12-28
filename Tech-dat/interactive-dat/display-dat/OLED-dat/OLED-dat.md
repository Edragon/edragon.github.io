

# oled-dat 

drive interface - [[I2C-dat]] - [[SPI-dat]]

## boards 

- [[IOD1001-dat]] - [[IOD1003-dat]] - [[ESP32-ISO-dat]]

## init 

SSD1306Wire display(0x3c, 12, 2);   // ADDRESS, SDA, SCL , ESP32 pin IO12 for SDA and IO2 for SCL


# arduino OLED 


- SSD1306ascii


## common OLED I2C address

- 0x3C = the version we are selling

## SCH 

using with STM32 SPI2 

![](2024-01-13-17-43-38.png)

## repositories 

- https://github.com/Edragon/Display_OLED-HDK
- https://github.com/Edragon/Display_OLED
- demo code - https://github.com/Edragon/Arduino-ESP32/tree/master/Sketchbook/driver-interactive/OLED/SSD1306SimpleDemo


## ref 

- [[display-dat]] 
  
- [[arduino-lib-dat]]

- [[display]] - [[OLED]] 