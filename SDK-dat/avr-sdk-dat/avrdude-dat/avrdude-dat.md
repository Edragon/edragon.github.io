

# avrdude-dat

AVR firmware - https://github.com/Edragon/AVR_firmware/tree/master/avrdude



* Program hex file into target IC with [[AVRDUDESS-dat]] or [[AVRDUDE-dat]]

![](2023-12-13-14-39-13.png)





## Version

- avrdudess 

## examples


* Arduino as ISP (UNO) = programmer
* target customized board atmega328p
* ersult efuse FD, high fuse DA, low fuse FF

test: 

    D:\avr-gcc\bin>avrdude -c avrisp -p m328p -P com4 -b 19200
    avrdude: AVR device initialized and ready to accept instructions
    Reading | ################################################## | 100% 0.04s
    avrdude: Device signature = 0x1e950f (probably m328p)
    avrdude: safemode: Fuses OK (E:FD, H:DA, L:FF)
    avrdude done.  Thank you.




## AVRDUDE + Arduino-ISP

avrdude == D:\arduino-1.8.19-windows\arduino-1.8.19\hardware\tools\avr\bin\avrdude.exe

add to system environment

set PATH=%PATH%;D:\arduino-1.8.19-windows\arduino-1.8.19\hardware\tools\avr\bin

config file == -CD:\Git-code\arduino\arduino-1.8.19-windows\arduino-1.8.19\hardware\tools\avr\etc\avrdude.conf

set AVRDUDE_CONF="D:\Git-code\arduino\arduino-1.8.19-windows\arduino-1.8.19\hardware\tools\avr\etc\avrdude.conf"

avrdude -v -C %AVRDUDE_CONF% -c arduino -P com245 -p t13

find version 

    D:\Git-code\arduino\arduino-1.8.12-windows\arduino-1.8.12\hardware\tools\avr\bin>avrdude -v -CD:\Git-code\arduino\arduino-1.8.12-windows\arduino-1.8.12\hardware\tools\avr\etc\avrdude.conf
    avrdude -v -CD:\Git-code\arduino\arduino-1.8.12-windows\arduino-1.8.12\hardware\tools\avr\etc\avrdude.conf

PROG

    D:\Git-code\arduino\arduino-1.8.12-windows\arduino-1.8.12\hardware\tools\avr\bin>avrdude -CD:\Git-code\arduino\arduino-1.8.12-windows\arduino-1.8.12\hardware\tools\avr\etc\avrdude.conf -c avrisp -p m328p -P com4 -b 19200
    avrdude -CD:\Git-code\arduino\arduino-1.8.12-windows\arduino-1.8.12\hardware\tools\avr\etc\avrdude.conf -c avrisp -p m328p -P com4 -b 19200

CMD1

    avrdude -CD:\Git-code\arduino\arduino-1.8.12-windows\arduino-1.8.12\hardware\tools\avr\etc\avrdude.conf -c avrisp -p m328p -P com4 -b 19200

CMD2

    avrdude -CD:\Git-code\arduino\arduino-1.8.12-windows\arduino-1.8.12\hardware\tools\avr\etc\avrdude.conf -c arduino -p atmega328p -P com4 -b 19200

CMD3

    avrdude -CD:\Git-code\arduino\arduino-1.8.12-windows\arduino-1.8.12\hardware\tools\avr\etc\avrdude.conf -c arduino -p m328p -P com4 -b 19200

    avrdude: AVR device initialized and ready to accept instructions
    Reading | ################################################## | 100% 0.04s
    avrdude: Device signature = 0x1e950f (probably m328p)
    avrdude: safemode: Fuses OK (E:FD, H:DA, L:FF)
    avrdude done.  Thank you.

## ATTINY13 - 2 == diy-attiny-dat

- [[attiny-dat]] - [[diy-attiny-dat]]

## ATTINY13 - MicroCore 

- [[microcore-dat]]



## AVRDUDE + USBASP, get start within arduino IDE

- [[avrdude-dat]]

avrdude locate 
* D:\arduino-1.8.19-windows\arduino-1.8.19\hardware\tools\avr\bin
* cd D:\Git-code\arduino\arduino-1.8.12-windows\arduino-1.8.12\hardware\tools\avr\bin

conf file locate
* D:\arduino-1.8.19-windows\arduino-1.8.19\hardware\tools\avr\etc

bootloader file locate
* D:\arduino-1.8.19-windows\arduino-1.8.19\hardware\arduino\avr\bootloaders\optiboot\optiboot_atmega328.hex

running with conf file 

    avrdude -C D:\avrdude.conf -c jtag2updi -P com285 -p avr128db64

based on [[cmd-dat]] varilables 

    %ad% -C %conf% -c USBASP -P USB -p atmega328p

### Read Chip using conf file 

    avrdude -CD:\Git-code\arduino\arduino-1.8.12-windows\arduino-1.8.12\hardware\tools\avr\etc\avrdude.conf -c usbasp -p m328p -b 19200

    avrdude: warning: cannot set sck period. please check for usbasp firmware update.
    avrdude: AVR device initialized and ready to accept instructions

    Reading | ################################################## | 100% 0.02s

    avrdude: Device signature = 0x1e9489 (probably m16u2)
    avrdude: Expected signature for ATmega328P is 1E 95 0F
            Double check chip, or use -F to override this check.

    avrdude done.  Thank you.

Correctly Read ATMEGA328P

    Reading | ################################################## | 100% 0.02s

    avrdude: Device signature = 0x1e950f (probably m328p) 

    avrdude: safemode: Fuses OK (E:FD, H:DE, L:FF)

    avrdude done.  Thank you.



### Flash bootloader for Arduino UNO

    avrdude -CD:\Git-code\arduino\arduino-1.8.12-windows\arduino-1.8.12\hardware\tools\avr\etc\avrdude.conf -c usbasp -p m328p -b 19200 -U flash:w:"D:\Git-code\arduino\arduino-1.8.12-windows\arduino-1.8.12\hardware\arduino\avr\bootloaders\optiboot\optiboot_atmega328.hex":a

    set "bl=D:\arduino-1.8.19-windows\arduino-1.8.19\hardware\arduino\avr\bootloaders\optiboot\optiboot_atmega328.hex"

    %ad% -C %conf% -c USBASP -p m328p -b 19200 -U flash:w:"%bl%":a

    %ad% -C %conf% -c USBASP -p m328p -b 19200 -U flash:w:"%bl%":i -U efuse:w:0xFD:m -U hfuse:w:0xDE:m -U lfuse:w:0xFF:m

full commands by arduino IDE, this will be failed if use alone 

    C:\Users\Administrator\AppData\Local\Arduino15\packages\arduino\tools\avrdude\6.3.0-arduino17/bin/avrdude -CC:\Users\Administrator\AppData\Local\Arduino15\packages\arduino\tools\avrdude\6.3.0-arduino17/etc/avrdude.conf -v -patmega328p -cusbasp -Pusb -Uflash:w:D:\arduino-1.8.19-windows\arduino-1.8.19\hardware\arduino\avr/bootloaders/optiboot/optiboot_atmega328.hex:i -Ulock:w:0x0F:m 

    C:\Users\Administrator\AppData\Local\Arduino15\packages\arduino\tools\avrdude\6.3.0-arduino17/bin/avrdude -CC:\Users\Administrator\AppData\Local\Arduino15\packages\arduino\tools\avrdude\6.3.0-arduino17/etc/avrdude.conf -v -patmega328p -cusbasp -Pusb -Uflash:w:D:\arduino-1.8.19-windows\arduino-1.8.19\hardware\arduino\avr/bootloaders/optiboot/optiboot_atmega328.hex:i -Ulock:w:0x0F:m

- [[avrdude-log-dat]]

## Supported List 

- Commands: avrdude -p ?
  
![](2023-09-12-17-52-25.png)

D:\arduino-1.8.19-windows\arduino-1.8.19\hardware\tools\avr\etc\avrdude.conf

Valid parts are:

    uc3a0512 = AT32UC3A0512       [...:14844]
    c128     = AT90CAN128         [...:3648]
    c32      = AT90CAN32          [...:4032]
    c64      = AT90CAN64          [...:3840]
    pwm2     = AT90PWM2           [...:9232]
    pwm216   = AT90PWM216         [...:9505]
    pwm2b    = AT90PWM2B          [...:9425]
    pwm3     = AT90PWM3           [...:9415]
    pwm316   = AT90PWM316         [...:9452]
    pwm3b    = AT90PWM3B          [...:9439]
    1200     = AT90S1200          [...:2109]
    2313     = AT90S2313          [...:2338]
    2333     = AT90S2333          [...:2451]
    2343     = AT90S2343          [...:2579]
    4414     = AT90S4414          [...:2225]
    4433     = AT90S4433          [...:2703]
    4434     = AT90S4434          [...:2827]
    8515     = AT90S8515          [...:2910]
    8535     = AT90S8535          [...:3024]
    usb1286  = AT90USB1286        [...:12152]
    usb1287  = AT90USB1287        [...:12343]
    usb162   = AT90USB162         [...:12356]
    usb646   = AT90USB646         [...:11948]
    usb647   = AT90USB647         [...:12139]
    usb82    = AT90USB82          [...:12543]
    m103     = ATmega103          [...:3145]
    m128     = ATmega128          [...:3468]
    m1280    = ATmega1280         [...:10257]
    m1281    = ATmega1281         [...:10447]
    m1284    = ATmega1284         [...:4844]
    m1284p   = ATmega1284P        [...:5038]
    m1284rfr2 = ATmega1284RFR2     [...:10882]
    m128rfa1 = ATmega128RFA1      [...:10667]
    m128rfr2 = ATmega128RFR2      [...:10770]
    m16      = ATmega16           [...:4225]
    m161     = ATmega161          [...:6370]
    m162     = ATmega162          [...:5230]
    m163     = ATmega163          [...:5428]
    m164p    = ATmega164P         [...:4404]
    m168     = ATmega168          [...:8207]
    m168p    = ATmega168P         [...:8396]
    m168pb   = ATmega168PB        [...:8408]
    m169     = ATmega169          [...:5586]
    m16u2    = ATmega16U2         [...:12920]
    m2560    = ATmega2560         [...:10460]
    m2561    = ATmega2561         [...:10654]
    m2564rfr2 = ATmega2564RFR2     [...:10872]
    m256rfr2 = ATmega256RFR2      [...:10721]
    m32      = ATmega32           [...:6193]
    m3208    = ATmega3208         [...:15987]
    m3209    = ATmega3209         [...:16011]
    m324p    = ATmega324P         [...:4428]
    m324pa   = ATmega324PA        [...:4620]
    m325     = ATmega325          [...:13290]
    m3250    = ATmega3250         [...:13671]
    m328     = ATmega328          [...:8609]
    m328p    = ATmega328P         [...:8794]
    m328pb   = ATmega328PB        [...:8802]
    m329     = ATmega329          [...:5768]
    m3290    = ATmega3290         [...:5967]
    m3290p   = ATmega3290P        [...:5981]
    m329p    = ATmega329P         [...:5953]
    m32m1    = ATmega32M1         [...:8814]
    m32u2    = ATmega32U2         [...:12732]
    m32u4    = ATmega32U4         [...:11757]
    m406     = ATMEGA406          [...:15182]
    m48      = ATmega48           [...:7783]
    m4808    = ATmega4808         [...:16035]
    m4809    = ATmega4809         [...:16059]
    m48p     = ATmega48P          [...:7970]
    m48pb    = ATmega48PB         [...:7982]
    m64      = ATmega64           [...:3285]
    m640     = ATmega640          [...:10067]
    m644     = ATmega644          [...:4636]
    m644p    = ATmega644P         [...:4827]
    m644rfr2 = ATmega644RFR2      [...:10892]
    m645     = ATmega645          [...:13481]
    m6450    = ATmega6450         [...:13683]
    m649     = ATmega649          [...:5994]
    m6490    = ATmega6490         [...:6180]
    m64m1    = ATmega64M1         [...:8834]
    m64rfr2  = ATmega64RFR2       [...:10783]
    m8       = ATmega8            [...:6510]
    m8515    = ATmega8515         [...:6678]
    m8535    = ATmega8535         [...:6836]
    m88      = ATmega88           [...:7995]
    m88p     = ATmega88P          [...:8182]
    m88pb    = ATmega88PB         [...:8194]
    m8u2     = ATmega8U2          [...:13108]
    t10      = ATtiny10           [...:15137]
    t11      = ATtiny11           [...:1604]
    t12      = ATtiny12           [...:1668]
    t13      = ATtiny13           [...:1801]
    t15      = ATtiny15           [...:1976]
    t1604    = ATtiny1604         [...:15551]
    t1606    = ATtiny1606         [...:15575]
    t1607    = ATtiny1607         [...:15599]
    t1614    = ATtiny1614         [...:15843]
    t1616    = ATtiny1616         [...:15867]
    t1617    = ATtiny1617         [...:15891]
    t1634    = ATtiny1634         [...:14870]
    t20      = ATtiny20           [...:15147]
    t202     = ATtiny202          [...:15359]
    t204     = ATtiny204          [...:15383]
    t212     = ATtiny212          [...:15623]
    t214     = ATtiny214          [...:15647]
    t2313    = ATtiny2313         [...:8859]
    t24      = ATtiny24           [...:10903]
    t25      = ATtiny25           [...:9515]
    t26      = ATtiny26           [...:6994]
    t261     = ATtiny261          [...:7151]
    t28      = ATtiny28           [...:7725]
    t3214    = ATtiny3214         [...:15915]
    t3216    = ATtiny3216         [...:15939]
    t3217    = ATtiny3217         [...:15963]
    t4       = ATtiny4            [...:15093]
    t40      = ATtiny40           [...:15164]
    t402     = ATtiny402          [...:15407]
    t404     = ATtiny404          [...:15431]
    t406     = ATtiny406          [...:15455]
    t412     = ATtiny412          [...:15671]
    t414     = ATtiny414          [...:15696]
    t416     = ATtiny416          [...:15720]
    t417     = ATtiny417          [...:15745]
    t4313    = ATtiny4313         [...:9048]
    t43u     = ATtiny43u          [...:11578]
    t44      = ATtiny44           [...:11087]
    t441     = ATtiny441          [...:11455]
    t45      = ATtiny45           [...:9699]
    t461     = ATtiny461          [...:7342]
    t5       = ATtiny5            [...:15110]
    t804     = ATtiny804          [...:15479]
    t806     = ATtiny806          [...:15503]
    t807     = ATtiny807          [...:15527]
    t814     = ATtiny814          [...:15770]
    t816     = ATtiny816          [...:15795]
    t817     = ATtiny817          [...:15819]
    t84      = ATtiny84           [...:11271]
    t841     = ATtiny841          [...:11516]
    t85      = ATtiny85           [...:9882]
    t861     = ATtiny861          [...:7533]
    t88      = ATtiny88           [...:8421]
    t9       = ATtiny9            [...:15120]
    x128a1   = ATxmega128A1       [...:14164]
    x128a1d  = ATxmega128A1revD   [...:14180]
    x128a1u  = ATxmega128A1U      [...:14190]
    x128a3   = ATxmega128A3       [...:14201]
    x128a3u  = ATxmega128A3U      [...:14211]
    x128a4   = ATxmega128A4       [...:14222]
    x128a4u  = ATxmega128A4U      [...:14280]
    x128b1   = ATxmega128B1       [...:14333]
    x128b3   = ATxmega128B3       [...:14392]
    x128c3   = ATxmega128C3       [...:14091]
    x128d3   = ATxmega128D3       [...:14144]
    x128d4   = ATxmega128D4       [...:14154]
    x16a4    = ATxmega16A4        [...:13822]
    x16a4u   = ATxmega16A4U       [...:13749]
    x16c4    = ATxmega16C4        [...:13802]
    x16d4    = ATxmega16D4        [...:13812]
    x16e5    = ATxmega16E5        [...:14739]
    x192a1   = ATxmega192A1       [...:14466]
    x192a3   = ATxmega192A3       [...:14482]
    x192a3u  = ATxmega192A3U      [...:14492]
    x192c3   = ATxmega192C3       [...:14403]
    x192d3   = ATxmega192D3       [...:14456]
    x256a1   = ATxmega256A1       [...:14566]
    x256a3   = ATxmega256A3       [...:14582]
    x256a3b  = ATxmega256A3B      [...:14603]
    x256a3bu = ATxmega256A3BU     [...:14613]
    x256a3u  = ATxmega256A3U      [...:14592]
    x256c3   = ATxmega256C3       [...:14503]
    x256d3   = ATxmega256D3       [...:14556]
    x32a4    = ATxmega32A4        [...:13911]
    x32a4u   = ATxmega32A4U       [...:13838]
    x32c4    = ATxmega32C4        [...:13891]
    x32d4    = ATxmega32D4        [...:13901]
    x32e5    = ATxmega32E5        [...:14791]
    x384c3   = ATxmega384C3       [...:14624]
    x384d3   = ATxmega384D3       [...:14677]
    x64a1    = ATxmega64A1        [...:14011]
    x64a1u   = ATxmega64A1U       [...:14027]
    x64a3    = ATxmega64A3        [...:14038]
    x64a3u   = ATxmega64A3U       [...:14048]
    x64a4    = ATxmega64A4        [...:14059]
    x64a4u   = ATxmega64A4U       [...:13927]
    x64b1    = ATxmega64B1        [...:14069]
    x64b3    = ATxmega64B3        [...:14080]
    x64c3    = ATxmega64C3        [...:13980]
    x64d3    = ATxmega64D3        [...:13991]
    x64d4    = ATxmega64D4        [...:14001]
    x8e5     = ATxmega8E5         [...:14687]
    ucr2     = deprecated, use 'uc3a0512' [...:14860]


## ref 

- [[avr-dat]]


- [[avrdude]]