
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
