
# OLED-dat

- [[OLED-I2C-dat]] - [[AMOLED-dat]] - [[OLED-driver-dat]] - [[OLED-raw-dat]] - [[OLED-SPI-dat]]

- [[OLED-SDK-dat]]

[legacy wiki page](https://www.electrodragon.com/w/0.96%27%27_128*64_OLED_Display)

drive interface - [[I2C-dat]] - [[SPI-dat]]



## boards 

- [[IOD1003-dat]] - [[IOD1001-dat]] - [[IOD1004-dat]] - [[IOD1005-dat]]


- [[ESP32-ISO-dat]]

- [[MPC1090-dat]]



## OLED Libs for arduino 

    Name                                               Installed Available   Location Description
    ACROBOTIC SSD1306                                  1.0.1     -           user     -
    ESP8266 and ESP32 OLED driver for SSD1306 displays 4.6.1     -           user     -
    SSD1306wire                                        2.0.1     -           user     -




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



## SCH 

### using with STM32 SPI2 

![](2024-01-13-17-43-38.png)


### SCH 2 I2C+RESET 

![](2025-07-09-18-51-53.png)



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





## repositories 

- https://github.com/Edragon/Display_OLED-HDK
- https://github.com/Edragon/Display_OLED
- demo code - https://github.com/Edragon/Arduino-ESP32/tree/master/Sketchbook/driver-interactive/OLED/SSD1306SimpleDemo

- [oled](https://github.com/Edragon/Interactive-Display_OLED)





## ref 

- [[display-dat]]

- [[arduino-lib-dat]]

- [[display]] - [[OLED]] 