

# SIMCOM AT GNSS


### AT+SGNSCMD=1,0

### AT+SGNSCFG

    AT+SGNSCFG="NMEAOUTPORT",1 //Configure GNSS out to USB NMEA port before
    GNSS power on

    AT+SGNSCFG="NMEAOUTPORT",2


### from Modem Side 

    AT+CGNSPWR=1
    AT+CGNSINF