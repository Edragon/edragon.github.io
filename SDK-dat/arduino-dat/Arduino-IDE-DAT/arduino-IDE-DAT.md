
## arduino-ide-dat

- [[arduino-boards-dat]] - [[arduino-app-dat]]

- [[arduino-lib-dat]]

## Library list 

multi-task 

SchedTask -2
https://github.com/Nospampls/SchedTask
TaskScheduler - 744
https://github.com/arkhipenko/TaskScheduler

- [[softwareserial-dat]]

- [[arduino-lib]]




## ESP32

- https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json

## ESP8266

- https://arduino.esp8266.com/stable/package_esp8266com_index.json



## tips 



### include 


use include “test.h” to add variables




### snippet

    // Periodically blink the onboard LED while listening for serial commands
    if ((int)(millis()/500) > lastPeriod)
    {
        lastPeriod++;
        pinMode(LED, OUTPUT);
        digitalWrite(LED, lastPeriod%2);
    }


### common folder 

windows

ETH.h 
- C:\Users\Administrator\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.6\libraries\Ethernet\src\eth.h
- C:\Users\Administrator\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.6\libraries\Ethernet\src\eth.cpp


## arduino15 

You can open it by pressing Win + R, typing: %LOCALAPPDATA%\Arduino15

Cut the Arduino15 folder.

Paste it somewhere on D drive, for example: D:\Arduino15

Open Command Prompt as Administrator and run: mklink /D "%LOCALAPPDATA%\Arduino15" "D:\Arduino15"



## export compiled binary 

    cmd /C copy C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_572672\rf-motor.ino_attiny13a_4800000L.lst E:\Git-category\Git-Arduino\arduino-main2\Sketchbook\attiny-app\rf-motor 
            1 file(s) copied.

    rf-motor.ino.with_bootloader_attiny13a_4800000L.hex
    rf-motor.ino_attiny13a_4800000L.hex
    rf-motor.ino_attiny13a_4800000L.lst

- [[avrdude-dat]]

## ref 


- [[arduino-code-v1-dat]]
- [[arduino-code-v2-dat]]


our repositories
- https://github.com/Edragon/Arduino-ESP32
- https://github.com/Edragon/Arduino-ESP8266


- [[arduino-ide]]