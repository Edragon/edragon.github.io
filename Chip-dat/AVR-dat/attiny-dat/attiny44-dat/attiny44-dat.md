
# attiny44-dat

- [[attiny85-dat]] - [[attiny13-dat]] - [[attiny44-dat]] - [[attiny-dat]] - [[USBASP-dat]]


## chip info log 

log 

    C:\Users\Administrator>%avrdude% -C %avrdude_conf% -c usbasp -p t44 -v

    avrdude.exe: Version 6.3-20190619
                Copyright (c) 2000-2005 Brian Dean, http://www.bdmicro.com/
                Copyright (c) 2007-2014 Joerg Wunsch

                System wide configuration file is "C:\Users\Administrator\AppData\Local\Arduino15\packages\arduino\tools\avrdude\6.3.0-arduino17\etc\avrdude.conf"

                Using Port                    : usb
                Using Programmer              : usbasp
    avrdude.exe: Warning: cannot open USB device: Function not implemented
                AVR Part                      : ATtiny44
                Chip Erase delay              : 4500 us
                PAGEL                         : P00
                BS2                           : P00
                RESET disposition             : possible i/o
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
                eeprom        65     6     4    0 no        256    4      0  4000  4500 0xff 0xff
                flash         65     6    32    0 yes      4096   64     64  4500  4500 0xff 0xff
                signature      0     0     0    0 no          3    0      0     0     0 0x00 0x00
                lock           0     0     0    0 no          1    0      0  9000  9000 0x00 0x00
                lfuse          0     0     0    0 no          1    0      0  9000  9000 0x00 0x00
                hfuse          0     0     0    0 no          1    0      0  9000  9000 0x00 0x00
                efuse          0     0     0    0 no          1    0      0  9000  9000 0x00 0x00
                calibration    0     0     0    0 no          1    0      0     0     0 0x00 0x00

                Programmer Type : usbasp
                Description     : USBasp, http://www.fischl.de/usbasp/

    avrdude.exe: auto set sck period (because given equals null)
    avrdude.exe: warning: cannot set sck period. please check for usbasp firmware update.
    avrdude.exe: AVR device initialized and ready to accept instructions

    Reading | ################################################## | 100% 0.03s

    avrdude.exe: Device signature = 0x1e9207 (probably t44)
    avrdude.exe: safemode: lfuse reads as 62
    avrdude.exe: safemode: hfuse reads as DF
    avrdude.exe: safemode: efuse reads as FF

    avrdude.exe: safemode: lfuse reads as 62
    avrdude.exe: safemode: hfuse reads as DF
    avrdude.exe: safemode: efuse reads as FF
    avrdude.exe: safemode: Fuses OK (E:FF, H:DF, L:62)

    avrdude.exe done.  Thank you.


    C:\Users\Administrator>



## ref 

