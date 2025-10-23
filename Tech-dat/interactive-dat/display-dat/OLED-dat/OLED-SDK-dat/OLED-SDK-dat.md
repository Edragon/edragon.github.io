
# OLED-SDK-dat



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


## ref 

- [[OLED-dat]]