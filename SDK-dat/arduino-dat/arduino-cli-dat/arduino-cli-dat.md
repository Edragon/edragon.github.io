
# arduino-cli-dat


https://github.com/arduino/arduino-cli

https://arduino.github.io/arduino-cli/1.2/getting-started/


install on windows 

https://downloads.arduino.cc/arduino-cli/arduino-cli_latest_Windows_64bit.zip

- [[win-sys-env]]

Create a configuration file and a new sketch:

    $ arduino-cli config init
    Config file written: /home/luca/.arduino15/arduino-cli.yaml

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


    arduino-cli compile --fqbn arduino:samd:mkr1000 0220-BMx280_I2C


## library 

arduino-cli lib search debouncer

arduino-cli lib install FTDebouncer
