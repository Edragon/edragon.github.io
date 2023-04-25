
## demo code 

- https://github.com/Edragon/Arduino-main


### boards 

ESP8266
https://arduino.esp8266.com/stable/package_esp8266com_index.json

MegaCoreX - megaTinyAVR
https://mcudude.github.io/MegaCoreX/package_MCUdude_MegaCoreX_index.json
https://github.com/MCUdude/MegaCoreX

ESP32
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json

megaTinyCore
http://drazzy.com/package_drazzy.com_index.json
https://github.com/SpenceKonde/megaTinyCore

ATTinyCore
https://github.com/SpenceKonde/ATTinyCore

nulllab
https://nulllab.coding.net/p/lgt/d/nulllab_lgt_arduino/git/raw/master/package_nulllab_boards_index_zh.json
https://cdn.jsdelivr.net/gh/nulllaborg/arduino_nulllab/package_nulllab_boards_index_zh.json



### library

- [[softwareserial]]

- [[arduino-lib]]




### include 


use include “test.h” to add variables




## snippet

    // Periodically blink the onboard LED while listening for serial commands
    if ((int)(millis()/500) > lastPeriod)
    {
        lastPeriod++;
        pinMode(LED, OUTPUT);
        digitalWrite(LED, lastPeriod%2);
    }


## common folder 

windows

ETH.h 
- C:\Users\Administrator\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.6\libraries\Ethernet\src\eth.h
- C:\Users\Administrator\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.6\libraries\Ethernet\src\eth.cpp