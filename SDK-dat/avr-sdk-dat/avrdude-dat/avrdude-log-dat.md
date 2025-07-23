
# avrdude-log-dat.md

arduino command 

    D:\arduino-1.8.19-windows\arduino-1.8.19\hardware\tools\avr\bin>C:\Users\Administrator\AppData\Local\Arduino15\packages\arduino\tools\avrdude\6.3.0-arduino17/bin/avrdude -CC:\Users\Administrator\AppData\Local\Arduino15\packages\arduino\tools\avrdude\6.3.0-arduino17/etc/avrdude.conf -v -patmega328p -cusbasp -Pusb -Uflash:w:D:\arduino-1.8.19-windows\arduino-1.8.19\hardware\arduino\avr/bootloaders/optiboot/optiboot_atmega328.hex:i -Ulock:w:0x0F:m

    avrdude: Version 6.3-20190619
            Copyright (c) 2000-2005 Brian Dean, http://www.bdmicro.com/
            Copyright (c) 2007-2014 Joerg Wunsch

            System wide configuration file is "C:\Users\Administrator\AppData\Local\Arduino15\packages\arduino\tools\avrdude\6.3.0-arduino17/etc/avrdude.conf"

            Using Port                    : usb
            Using Programmer              : usbasp
            AVR Part                      : ATmega328P
            Chip Erase delay              : 9000 us
            PAGEL                         : PD7
            BS2                           : PC2
            RESET disposition             : dedicated
            RETRY pulse                   : SCK
            serial program mode           : yes
            parallel program mode         : yes
            Timeout                       : 200
            StabDelay                     : 100
            CmdexeDelay                   : 25
            SyncLoops                     : 32
            ByteDelay                     : 0
            PollIndex                     : 3
            PollValue                     : 0x53
            Memory Detail                 :

                                    Block Poll               Page                       Polled
            Memory Type Mode Delay Size  Indx Paged  Size   Size #Pages MinW  MaxW   ReadBack
            ----------- ---- ----- ----- ---- ------ ------ ---- ------ ----- ----- ---------
            eeprom        65    20     4    0 no       1024    4      0  3600  3600 0xff 0xff
            flash         65     6   128    0 yes     32768  128    256  4500  4500 0xff 0xff
            lfuse          0     0     0    0 no          1    0      0  4500  4500 0x00 0x00
            hfuse          0     0     0    0 no          1    0      0  4500  4500 0x00 0x00
            efuse          0     0     0    0 no          1    0      0  4500  4500 0x00 0x00
            lock           0     0     0    0 no          1    0      0  4500  4500 0x00 0x00
            calibration    0     0     0    0 no          1    0      0     0     0 0x00 0x00
            signature      0     0     0    0 no          3    0      0     0     0 0x00 0x00

            Programmer Type : usbasp
            Description     : USBasp, http://www.fischl.de/usbasp/

    avrdude: auto set sck period (because given equals null)
    avrdude: warning: cannot set sck period. please check for usbasp firmware update.
    avrdude: AVR device initialized and ready to accept instructions

    Reading | ################################################## | 100% 0.03s

    avrdude: Device signature = 0x1e950f (probably m328p)
    avrdude: safemode: lfuse reads as 62
    avrdude: safemode: hfuse reads as D9
    avrdude: safemode: efuse reads as FF
    avrdude: NOTE: "flash" memory has been specified, an erase cycle will be performed
            To disable this feature, specify the -D option.
    avrdude: erasing chip
    avrdude: auto set sck period (because given equals null)
    avrdude: warning: cannot set sck period. please check for usbasp firmware update.
    avrdude: reading input file "D:\arduino-1.8.19-windows\arduino-1.8.19\hardware\arduino\avr/bootloaders/optiboot/optiboot_atmega328.hex"
    avrdude: writing flash (32768 bytes):

    Writing | ################################################## | 100% 0.03s

    avrdude: 32768 bytes of flash written
    avrdude: verifying flash memory against D:\arduino-1.8.19-windows\arduino-1.8.19\hardware\arduino\avr/bootloaders/optiboot/optiboot_atmega328.hex:
    avrdude: load data flash data from input file D:\arduino-1.8.19-windows\arduino-1.8.19\hardware\arduino\avr/bootloaders/optiboot/optiboot_atmega328.hex:
    avrdude: input file D:\arduino-1.8.19-windows\arduino-1.8.19\hardware\arduino\avr/bootloaders/optiboot/optiboot_atmega328.hex contains 32768 bytes
    avrdude: reading on-chip flash data:

    Reading | ################################################## | 100% 0.02s

    avrdude: verifying ...
    avrdude: 32768 bytes of flash verified
    avrdude: reading input file "0x0F"
    avrdude: writing lock (1 bytes):

    Writing | ################################################## | 100% 0.01s

    avrdude: 1 bytes of lock written
    avrdude: verifying lock memory against 0x0F:
    avrdude: load data lock data from input file 0x0F:
    avrdude: input file 0x0F contains 1 bytes
    avrdude: reading on-chip lock data:

    Reading | ################################################## | 100% 0.01s

    avrdude: verifying ...
    avrdude: 1 bytes of lock verified

    avrdude: safemode: lfuse reads as 62
    avrdude: safemode: hfuse reads as D9
    avrdude: safemode: efuse reads as FF
    avrdude: safemode: Fuses OK (E:FF, H:D9, L:62)

    avrdude done.  Thank you.