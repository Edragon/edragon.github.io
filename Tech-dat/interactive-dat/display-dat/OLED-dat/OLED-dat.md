

# oled-dat 

drive interface - [[I2C-dat]] - [[SPI-dat]]

## boards 

- [[IOD1001-dat]] - [[IOD1003-dat]] - [[ESP32-ISO-dat]]

- [[MPC1090-dat]]


## init 

SSD1306Wire display(0x3c, 12, 2);   // ADDRESS, SDA, SCL , ESP32 pin IO12 for SDA and IO2 for SCL
SSD1306Wire display(0x3c, 15, 13);

# arduino OLED library 


- SSD1306ascii

### ESP8266_and_ESP32_OLED_driver_for_SSD1306_displays

display data 

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