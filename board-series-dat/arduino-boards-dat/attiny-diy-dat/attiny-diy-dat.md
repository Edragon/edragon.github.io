
# diy-attiny-dat

- https://raw.githubusercontent.com/sleemanj/optiboot/master/dists/package_gogo_diy_attiny_index.json

### avrdude commands 

C:\Users\Administrator\AppData\Local\Arduino15\packages\arduino\tools\avrdude\6.3.0-arduino17/bin/avrdude -CC:\Users\Administrator\AppData\Local\Arduino15\packages\diy_attiny\hardware\avr\2023.4.19-gcc7.3/avrdude.conf -v -pattiny13 -cstk500v1 -PCOM245 -b19200 -Uflash:w:C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_572672/rf-motor.ino.hex:i 


- C:\Users\Administrator\AppData\Local\Arduino15\packages\arduino\tools\avrdude\6.3.0-arduino17/bin/avrdude
- -CC:\Users\Administrator\AppData\Local\Arduino15\packages\diy_attiny\hardware\avr\2023.4.19-gcc7.3/avrdude.conf 
- -v 
- -pattiny13 
- -cstk500v1 
- -PCOM245 
- -b19200 
- -Uflash:w:C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_572672/rf-motor.ino.hex:i


### write 

        C:\Users\Administrator\AppData\Local\Arduino15\packages\arduino\tools\avrdude\6.3.0-arduino17/bin/avrdude -CC:\Users\Administrator\AppData\Local\Arduino15\packages\diy_attiny\hardware\avr\2023.4.19-gcc7.3/avrdude.conf -v -pattiny13 -cstk500v1 -PCOM245 -b19200 -Uflash:w:C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_572672/rf-motor.ino.hex:i 

        avrdude: Version 6.3-20190619
                Copyright (c) 2000-2005 Brian Dean, http://www.bdmicro.com/
                Copyright (c) 2007-2014 Joerg Wunsch

                System wide configuration file is "C:\Users\Administrator\AppData\Local\Arduino15\packages\diy_attiny\hardware\avr\2023.4.19-gcc7.3/avrdude.conf"

                Using Port                    : COM245
                Using Programmer              : stk500v1
                Overriding Baud Rate          : 19200
                AVR Part                      : ATtiny13
                Chip Erase delay              : 4000 us
                PAGEL                         : P00
                BS2                           : P00
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
                eeprom        65     5     4    0 no         64    4      0  4000  4000 0xff 0xff
                flash         65     6    32    0 yes      1024   32     32  4500  4500 0xff 0xff
                signature      0     0     0    0 no          3    0      0     0     0 0x00 0x00
                lock           0     0     0    0 no          1    0      0  4500  4500 0x00 0x00
                calibration    0     0     0    0 no          2    0      0     0     0 0x00 0x00
                lfuse          0     0     0    0 no          1    0      0  4500  4500 0x00 0x00
                hfuse          0     0     0    0 no          1    0      0  4500  4500 0x00 0x00

                Programmer Type : STK500
                Description     : Atmel STK500 Version 1.x firmware
                Hardware Version: 2
                Firmware Version: 1.18
                Topcard         : Unknown
                Vtarget         : 0.0 V
                Varef           : 0.0 V
                Oscillator      : Off
                SCK period      : 0.1 us

        avrdude: AVR device initialized and ready to accept instructions

        Reading | ################################################## | 100% 0.02s

        avrdude: Device signature = 0x1e9007 (probably t13)
        avrdude: NOTE: "flash" memory has been specified, an erase cycle will be performed
                To disable this feature, specify the -D option.
        avrdude: erasing chip
        avrdude: reading input file "C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_572672/rf-motor.ino.hex"
        avrdude: writing flash (278 bytes):

        Writing | ################################################## | 100% 0.59s

        avrdude: 278 bytes of flash written
        avrdude: verifying flash memory against C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_572672/rf-motor.ino.hex:
        avrdude: load data flash data from input file C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_572672/rf-motor.ino.hex:
        avrdude: input file C:\Users\ADMINI~1\AppData\Local\Temp\arduino_build_572672/rf-motor.ino.hex contains 278 bytes
        avrdude: reading on-chip flash data:

        Reading | ################################################## | 100% 0.26s

        avrdude: verifying ...
        avrdude: 278 bytes of flash verified

        avrdude done.  Thank you.


### bootloader 

C:\Users\Administrator\AppData\Local\Arduino15\packages\arduino\tools\avrdude\6.3.0-arduino17/bin/avrdude -CC:\Users\Administrator\AppData\Local\Arduino15\packages\diy_attiny\hardware\avr\2023.4.19-gcc7.3/avrdude.conf -v -pattiny13 -cstk500v1 -PCOM245 -b19200 -e -Ulock:w:0x3F:m -Uhfuse:w:0b11111011:m -Ulfuse:w:0x79:m 

C:\Users\Administrator\AppData\Local\Arduino15\packages\arduino\tools\avrdude\6.3.0-arduino17/bin/avrdude -CC:\Users\Administrator\AppData\Local\Arduino15\packages\diy_attiny\hardware\avr\2023.4.19-gcc7.3/avrdude.conf -v -pattiny13 -cstk500v1 -PCOM245 -b19200 -Ulock:w:0x3F:m 

> -e == Tells avrdude to perform a chip erase before any programming actions (like writing flash or EEPROM).


### lock 

    C:\Users\Administrator\AppData\Local\Arduino15\packages\arduino\tools\avrdude\6.3.0-arduino17/bin/avrdude -CC:\Users\Administrator\AppData\Local\Arduino15\packages\diy_attiny\hardware\avr\2023.4.19-gcc7.3/avrdude.conf -v -pattiny13 -cstk500v1 -PCOM245 -b19200 -Ulock:w:0x3F:m 

    avrdude: Version 6.3-20190619
            Copyright (c) 2000-2005 Brian Dean, http://www.bdmicro.com/
            Copyright (c) 2007-2014 Joerg Wunsch

            System wide configuration file is "C:\Users\Administrator\AppData\Local\Arduino15\packages\diy_attiny\hardware\avr\2023.4.19-gcc7.3/avrdude.conf"

            Using Port                    : COM245
            Using Programmer              : stk500v1
            Overriding Baud Rate          : 19200
            AVR Part                      : ATtiny13
            Chip Erase delay              : 4000 us
            PAGEL                         : P00
            BS2                           : P00
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
            eeprom        65     5     4    0 no         64    4      0  4000  4000 0xff 0xff
            flash         65     6    32    0 yes      1024   32     32  4500  4500 0xff 0xff
            signature      0     0     0    0 no          3    0      0     0     0 0x00 0x00
            lock           0     0     0    0 no          1    0      0  4500  4500 0x00 0x00
            calibration    0     0     0    0 no          2    0      0     0     0 0x00 0x00
            lfuse          0     0     0    0 no          1    0      0  4500  4500 0x00 0x00
            hfuse          0     0     0    0 no          1    0      0  4500  4500 0x00 0x00

            Programmer Type : STK500
            Description     : Atmel STK500 Version 1.x firmware
            Hardware Version: 2
            Firmware Version: 1.18
            Topcard         : Unknown
            Vtarget         : 0.0 V
            Varef           : 0.0 V
            Oscillator      : Off
            SCK period      : 0.1 us

    avrdude: AVR device initialized and ready to accept instructions

    Reading | ################################################## | 100% 0.02s

    avrdude: Device signature = 0x1e9007 (probably t13)
    avrdude: reading input file "0x3F"
    avrdude: writing lock (1 bytes):

    Writing | ################################################## | 100% 0.01s

    avrdude: 1 bytes of lock written
    avrdude: verifying lock memory against 0x3F:
    avrdude: load data lock data from input file 0x3F:
    avrdude: input file 0x3F contains 1 bytes
    avrdude: reading on-chip lock data:

    Reading | ################################################## | 100% 0.01s

    avrdude: verifying ...
    avrdude: 1 bytes of lock verified

    avrdude done.  Thank you.
