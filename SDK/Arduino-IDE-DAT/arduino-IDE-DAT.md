
## demo code arduino


- [[Arduino-Code-V1]]
- [[Arduino-Code-V2]]


our repositories
- https://github.com/Edragon/Arduino-ESP32
- https://github.com/Edragon/Arduino-ESP8266

### boards 

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


## library 

multi-task 

SchedTask -2
https://github.com/Nospampls/SchedTask
TaskScheduler - 744
https://github.com/arkhipenko/TaskScheduler


## Core list 

## Atmega 

- [[megaCoreX-dat]] - atmega4808
https://mcudude.github.io/MegaCoreX/package_MCUdude_MegaCoreX_index.json

## LGT8F328 - nulllab

- [[logicgreen-dat]]

https://nulllab.coding.net/p/lgt/d/nulllab_lgt_arduino/git/raw/master/package_nulllab_boards_index_zh.json
https://cdn.jsdelivr.net/gh/nulllaborg/arduino_nulllab/package_nulllab_boards_index_zh.json


## Attiny 

- [[attiny-dat]]

DxCore - megaTinyCore
- by Spence Konde
- https://github.com/SpenceKonde/megaTinyCore
- https://github.com/SpenceKonde/megaTinyCore/blob/master/Installation.md
- https://github.com/SpenceKonde/DxCore
- https://github.com/SpenceKonde/DxCore/blob/master/Installation.md
- http://drazzy.com/package_drazzy.com_index.json
- AVR128

ATTinyCore
- by Spence Konde
- attiny 85
- https://github.com/SpenceKonde/ATTinyCore

MicroCore
- https://mcudude.github.io/MicroCore/package_MCUdude_MicroCore_index.json

DIY Attiny 
- https://raw.githubusercontent.com/sleemanj/optiboot/master/dists/package_gogo_diy_attiny_index.json

## ESP32

- https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json

## ESP8266

- https://arduino.esp8266.com/stable/package_esp8266com_index.json


- [[arduino-ide]]