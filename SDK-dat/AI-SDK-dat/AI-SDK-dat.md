
# AI-SDK-dat

promote 




- PSRAM == no 
- use freertos == yes -- good to avoid memory leak
- webserver == yes
- use SPIFFS == yes

## hardware 

main controller == esp32

camera type = OV2640

- pin definitions 

add hardware I2C SSD1306 OLED display, address 0x3C, SCL is pin 13 and SDA is pin 15

add hardware I2C BMP280, address 0x76, SCL is pin 13 and SDA is pin 15

another task to read bmp280 data and print by OLED display

add GPIO 33 and GPIO4, when capture image, both LED trigger to blink shortly twice 



## ref 

- [[ESP32-SDK-dat]]

- [[ESP1000-code-dat]]

- [[SDK]]