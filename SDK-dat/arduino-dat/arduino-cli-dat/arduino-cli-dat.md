
# arduino-cli-dat


https://github.com/arduino/arduino-cli

https://arduino.github.io/arduino-cli/1.2/getting-started/


install on windows 

https://downloads.arduino.cc/arduino-cli/arduino-cli_latest_Windows_64bit.zip

- [[win-sys-env]]

Create a configuration file and a new sketch:

    $ arduino-cli config init
    Config file written: /home/luca/.arduino15/arduino-cli.yaml

    C:\Users\Administrator>arduino-cli config init
    Config file written to: C:\Users\Administrator\AppData\Local\Arduino15\arduino-cli.yaml

    $ arduino-cli sketch new MyFirstSketch
    Sketch created in: /home/luca/MyFirstSketch


install boards 

    arduino-cli board list
    arduino-cli core list
    arduino-cli core install arduino:samd
    arduino-cli board listall mkr

    C:\Users\Administrator>arduino-cli core list
    ID                   Installed Latest Name
    arduino:avr          1.8.6     1.8.6  Arduino AVR Boards
    DxCore:megaavr       1.5.11    1.5.11 DxCore
    esp32:esp32          3.2.1     3.2.1  esp32
    esp8266:esp8266      3.1.2     3.1.2  ESP8266 Boards (3.1.2)
    megaTinyCore:megaavr 2.6.10    2.6.10 megaTinyCore

board manager 

    board_manager:
    additional_urls:
        - https://arduino.esp8266.com/stable/package_esp8266com_index.json
        - https://arduino.esp8266.com/stable/package_esp8266com_index.json
        - file:///absolute/path/to/your/package_nrf52832_index.json

search and udpate 

    $ arduino-cli core update-index
    Updating index: package_index.json downloaded
    Updating index: package_esp8266com_index.json downloaded
    Updating index: package_nrf52832_index.json
    Updating index: package_index.json downloaded

    $ arduino-cli core search esp8266
    ID              Version Name
    esp8266:esp8266 2.5.2   esp8266

compile and upload 

    arduino-cli compile --fqbn arduino:samd:mkr1000 MyFirstSketch

    arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:samd:mkr1000 MyFirstSketch

    

compile for esp32 dev module 

    arduino-cli compile --fqbn esp32:esp32:esp32 rtos-cam-web-2

    arduino-cli compile --fqbn esp32:esp32:esp32 --verbose rtos-cam-web-2

upload 

    esptool erase-flash

    arduino-cli upload -p COM7 --fqbn esp32:esp32:esp32 --verbose rtos-cam-web-2



## library 

arduino-cli lib search debouncer
arduino-cli lib search SSD1306Wire

    E:\Git-category\Git-Arduino\Arduino-ESP32\BSP\ESP\ESP1000-ESP32-tori>arduino-cli lib search SSD1306Wire
    Name: "SSD1306wire"
    Author: Alexander Pronin <Alexander.Pronin@gmail.com>
    Maintainer: Alexander Pronin <Alexander.Pronin@gmail.com>
    Sentence: Display text on OLED module SSD1306 with I2C.
    Paragraph: It allow dipslay text on SSD1306 communication with I2C.
    Website: https://gitlab.com/alexpr0/ssd1306wire.git
    Category: Display
    Architecture: avr
    Types: Contributed
    Versions: [2.0.1]

arduino-cli lib install FTDebouncer

arduino-cli lib install SSD1306Wire

    arduino-cli lib install SSD1306Wire
    Downloading SSD1306wire@2.0.1...
    SSD1306wire@2.0.1 downloaded
    Installing SSD1306wire@2.0.1...
    Installed SSD1306wire@2.0.1

"ESP8266 and ESP32 OLED driver for SSD1306 displays"

    arduino-cli lib install "ESP8266 and ESP32 OLED driver for SSD1306 displays"
    Downloading ESP8266 and ESP32 OLED driver for SSD1306 displays@4.6.1...
    ESP8266 and ESP32 OLED driver for SSD1306 displays@4.6.1 downloaded
    Installing ESP8266 and ESP32 OLED driver for SSD1306 displays@4.6.1...
    Installed ESP8266 and ESP32 OLED driver for SSD1306 displays@4.6.1

    arduino-cli lib search BMx280MI
    Name: "BMx280MI"
    Author: Gregor Christandl <christandlg@yahoo.com>
    Maintainer: Gregor Christandl <christandlg@yahoo.com>
    Sentence: A library for the Bosch Sensortec BME280 and BMP280 Digital Pressure Sensors.
    Paragraph: The library supports both the SPI (via the SPI Library) and I2C (via the Wire Library) interfaces. Use of other I2C / SPI libraries (e.g. software I2C) is supported by inheritance. Supports 64 bit pressure calculation.
    Website: https://bitbucket.org/christandlg/bmx280mi
    Category: Sensors
    Architecture: *
    Types: Contributed
    Versions: [0.0.1, 0.0.2, 1.0.0, 1.1.0, 1.1.1, 1.1.2, 1.2.0, 1.2.1, 1.2.2, 1.2.3]


### lib manage 

    If you're managing libraries manually (e.g., cloned to ~/Arduino/libraries/), make sure it's in the default path or explicitly reference it in your arduino-cli.yaml config if you moved it.

    Let me know if you need help installing manually or verifying the include paths.


### list lib 

arduino-cli lib list

    Name                                               Installed Available    Location Description
    BMx280MI                                           1.2.3     -            user     -
    ESP8266 and ESP32 OLED driver for SSD1306 displays 4.6.1     -            user     -
    SSD1306wire                                        2.0.1     -            user     -

== D:\HE\Documents\Arduino\libraries