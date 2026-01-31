
# OLED-SDK-dat

- [[OLED-driver-dat]] 


## OLED Libs for arduino 

    Name                                               Installed Available   Location Description
    ACROBOTIC SSD1306                                  1.0.1     -           user     -
    ESP8266 and ESP32 OLED driver for SSD1306 displays 4.6.1     -           user     -
    SSD1306wire                                        2.0.1     -           user     -





## OLED Memory Layout 

The following diagram shows the display memory layout: **64×128 bits**

![](2025-07-30-16-40-52.png)

### Data Types

Data written to the OLED screen is divided into two types:

1. **Command Type:** Controls cursor position and other settings
   - Format: `0x00 + command_value`
   - Example: Setting cursor position

2. **Data Type:** Writes values to the display buffer
   - Format: `0x01 + data_value`
   - Example: Writing pixel data

### Display Principle

The display works by:

1. **Buffer Allocation:** Create a buffer matching the screen size
   - **Buffer Size:** `64 × 128 ÷ 8 = 1024 bytes`
   
2. **Buffer Modification:** Update the buffer content as needed

3. **Display Refresh:** Send the entire buffer content to display memory
   - **Refresh Method:** Update all columns in the display memory simultaneously







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

## library

```
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
```


## ref 

- [[OLED-dat]]