
# GPS-dat 

- legacy wiki page - https://w.electrodragon.com/w/Category:Location#GNSS

## Functions 

- GNSS
- ATGM
- GPS
- Galileo
- sbas
- dgps
- beidou
- glonass
- gzss


## software 

- https://igs.bkg.bund.de/ntrip/download






## Tesing 

[[NGS1089-dat]]

    AT+CPIN?
    +CPIN: READY

    AT+CGNSPWR=?
    +CGNSPWR: (0-1)

    OK
    AT+CGNSPWR?
    +CGNSPWR: 0

    OK
    AT+CGNSPWR=1
    OK

    AT+CGNSINF
    +CGNSINF: 1,0,19800109075159.000,,,,0.00,0.0,0,,,,,,3,0,2,,44,,

    OK
    AT+CGNSINF
    +CGNSINF: 1,0,20240626075200.000,,,,0.00,0.0,0,,,,,,3,0,2,,44,,


    AT+CGNSINF
    +CGNSINF: 1,1,20240626074838.000,22.570777,113.887168,155.727,0.00,65.8,1,,2.8,3.0,1.0,,7,4,5,,47,,


- 2.1  AT+CGNSPWR      GNSS power control ...................................................................... 8 
- 2.2  AT+CGNSSEQ   Define the last NMEA sentence that parsed ..................................... 9 
- 2.3  AT+CGNSINF    GNSS navigation information parsed from NMEA sentences ......... 11 
- 2.4  AT+CGNSURC   GNSS navigation, GEO-fences and speed alarm URC report ....... 12 
- 2.5  AT+CGNSCMD    Send command to GNSS ............................................................... 13 
- 2.6  AT+CGNSTST    Send data received from UART2 to UART1 ................................... 14 
- 2.7  AT+CGNSCHK    Check EPO file property ................................................................ 14 
- 2.8  AT+CGNSDEL    Delete EPO file ............................................................................... 15 
- 2.9  AT+CGNSIPR   Configure UART2 baud rate ............................................................ 16 
- 2.10  AT+CGNSAID    Send EPO file to GNSS engine ....................................................... 16 
- 2.11  AT+CRFLOC   Give reference location to GNSS engine ........................................... 17 
- 2.12  AT+CGNSVER  Query GNSS version....................................................................... 17 





## Note 

### Why you really need good GPS signal, compare to your smart phone? 

- your smart phone use 4G network to assist the location, but GPS module use [[GPS-dat]] signal location only
- read more at [[AGPS-net]]

## interface 

- [[serial-dat]]

- [[NGS1078]]

- [[quectel-gps-dat]] - [[quectel-gnss-dat]]

