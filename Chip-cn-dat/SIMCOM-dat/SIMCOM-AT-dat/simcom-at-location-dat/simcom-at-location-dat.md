

# SIMCOM AT GNSS


## A7670A 

    AT+CGNSSPWR=1
    OK

    long wait == 15 ~ 30 seconds 

    +CGNSSPWR: READY!


    AT+CGPSINFO
    +CGPSINFO: 2234.26947,N,11353.24671,E,211025,073352.00,2.2,0.713,

    OK



## logs 


### AT+SGNSCMD=1,0

### AT+SGNSCFG

    AT+SGNSCFG="NMEAOUTPORT",1 //Configure GNSS out to USB NMEA port before
    GNSS power on

    AT+SGNSCFG="NMEAOUTPORT",2


### from Modem Side 

    AT+CGNSPWR=1
    AT+CGNSINF

result

    //Example of Open GNSS.
    AT+CGNSPWR=1 //Turn on GNSS power(UART or USB AT port)
    OK
    AT+CGNSINF //Read GNSS navigation information
    +CGNSINF: 1,1,20191024051848.000,31.221946,121.355565,3.417,0.00,,0,,1.4,1.7,0.9,,6,,12.4,12.0
    OK

result shift from time verified to location verified

    OK
    AT+CGNSINF
    +CGNSINF: 1,,20230315095031.434,0.000000,0.000000,-18.000,,,1,,0.1,0.1,0.1,,,,9999000.0,6000.0

    OK
    AT+CGNSINF
    +CGNSINF: 1,,20230315095032.155,22.571717,113.887426,10.487,1.07,,1,,1.4,3.6,3.3,,4,,142.8,270.0

my location: 22.571717,113.887426

    AT+CGNSSPWR=1
    AT+CGNSSTST=1
    AT+CGPSINFO=1


### AT+CGNSSPROD

    AT+CGNSSPROD
    PRODUCT: UNICORECOMM,UC6228CI,R3.2.10.100Build8108

    OK



## SIM868 

![](2025-03-14-15-27-07.png)


## ref 

- [[SIMCOM-at-dat]]


# simcom-at-sscom-dat

- [[SIMCOM-AT-DAT]]

- [[simcom-at-sscom-dat.exe]] - [[SSCOM51.ini]]


## Power ON 

    AT+CGNSSPWR=1

    wait 5~10 seconds 

    +CGNSSPWR: READY!


## GPIO Control (optinally)

    AT+CGDRT=4,1

    AT+CGSETV=4,1


## forward GNSS Serial Port to UART3 


    AT+CGNSSTST=1


## Check 

    AT+CGPSINFO
    +CGPSINFO: 2234.27181,N,11353.24648,E,010625,084110.00,20.9,0.000,

    OK
    
    AT+CGNSSINFO
    +CGNSSINFO: 3,08,,,,22.5711975,N,113.8874359,E,010625,084112.00,20.9,0.000,,2.08,1.15,1.74,13

    OK
