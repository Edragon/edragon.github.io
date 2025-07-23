
# MicroCore-dat


== https://github.com/MCUdude/MicroCore == star 580

Enter the following URL in Additional Boards Manager URLs: 

    https://mcudude.github.io/MicroCore/package_MCUdude_MicroCore_index.json

- Open the Tools > Board > Boards Manager... menu item.
- Wait for the platform indexes to finish downloading.
- Scroll down until you see the MicroCore entry and click on it.
- Click Install.
- After installation is complete close the Boards Manager window.





- [[avrdude-dat]]



    System wide configuration file is C:\Users\Administrator\AppData\Local\Arduino15\packages\MicroCore\tools\avrdude\8.0-arduino.1\etc\avrdude.conf

    set AVRDUDE_CONF="C:\Users\Administrator\AppData\Local\Arduino15\packages\MicroCore\tools\avrdude\8.0-arduino.1\etc\avrdude.conf"

avrdude -v -C %AVRDUDE_CONF% -c arduino -P com245 -p t13 -b 19200
avrdude -v -C %AVRDUDE_CONF% -c stk500v1 -P com245 -p t13 -b 19200

> C:\Users\Administrator\AppData\Local\Arduino15\packages\MicroCore\tools\avrdude\8.0-arduino.1\bin\avrdude.exe -v -C "C:\Users\Administrator\AppData\Local\Arduino15\packages\MicroCore\tools\avrdude\8.0-arduino.1\etc\avrdude.conf" -c stk500v1 -P com245 -p t13 -b 19200


    C:\Users\Administrator>C:\Users\Administrator\AppData\Local\Arduino15\packages\MicroCore\tools\avrdude\8.0-arduino.1\bin\avrdude.exe -v -C "C:\Users\Administrator\AppData\Local\Arduino15\packages\MicroCore\tools\avrdude\8.0-arduino.1\etc\avrdude.conf" -c stk500v1 -P com245 -p t13 -b 19200

    Avrdude version 8.0-arduino.1
    Copyright see https://github.com/avrdudes/avrdude/blob/main/AUTHORS

    System wide configuration file is C:\Users\Administrator\AppData\Local\Arduino15\packages\MicroCore\tools\avrdude\8.0-arduino.1\etc\avrdude.conf

    Using port            : com245
    Using programmer      : stk500v1
    Setting baud rate     : 19200
    AVR part              : ATtiny13
    Programming modes     : SPM, ISP, HVSP, debugWIRE
    Programmer type       : STK500
    Description           : Atmel STK500 v1
    HW Version            : 2
    FW Version            : 1.18
    Topcard               : Unknown
    Vtarget               : 0.0 V
    Varef                 : 0.0 V
    Oscillator            : Off
    SCK period            : 0.0 us
    XTAL frequency        : 7.372800 MHz

    AVR device initialized and ready to accept instructions
    Device signature = 1E 90 07 (ATtiny13, ATtiny13A)

    Avrdude done.  Thank you.

> Processing -U hfuse:w:0xeb:m
Reading 1 byte for hfuse from input file 0xeb
in 1 section [0, 0]
Writing 1 byte (0xEB) to hfuse, 1 byte written, 1 verified

write fuse 

    C:\Users\Administrator\AppData\Local\Arduino15\packages\MicroCore\tools\avrdude\8.0-arduino.1\bin\avrdude.exe -v -C "C:\Users\Administrator\AppData\Local\Arduino15\packages\MicroCore\tools\avrdude\8.0-arduino.1\etc\avrdude.conf" -c stk500v1 -P com245 -p t13 -b 19200 -U hfuse:w:0xeb:m

C:\Users\Administrator\AppData\Local\Arduino15\packages\MicroCore\tools\avrdude\8.0-arduino.1\bin

    avrdude.exe -v -C "C:\Users\Administrator\AppData\Local\Arduino15\packages\MicroCore\tools\avrdude\8.0-arduino.1\etc\avrdude.conf" -c stk500v1 -P com245 -p t13 -b 19200 -U hfuse:w:0xeb:m

![](2025-07-09-17-31-30.png)


