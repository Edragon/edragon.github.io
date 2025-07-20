
# A7670-at-log.md

- use pre-build SIMCOM AT here [[simcom-at-basic-dat]]

- [[A7670-dat]]

## network 

AT+CPING

    AT+CPING="www.baidu.com",1,4,64,1000,10000,255
    OK

    +CPING: 1,157.148.69.186,92,25,52

    +CPING: 1,157.148.69.186,92,30,52

    +CPING: 1,157.148.69.186,92,30,52

    +CPING: 1,157.148.69.186,92,40,52

    +CPING: 3,4,4,0,25,40,34


## file system 

Select directory as current directory

    AT+FSCD?
    +FSCD: C:/

    OK

AT+FSLS List directories/files in current directory

    AT+FSLS?
    +FSLS: SUBDIRECTORIES:0,FILES:0

    OK

 AT+FSMEM Check the size of available memory

    AT+FSMEM
    +FSMEM: C:(3145728,397312)

    OK

## hardware 

AT+CADC Read ADC value

    AT+CADC=2
    +CADC: 7

    OK

AT+CRIIC Read values from register of IIC device nau8810


AT+CBC Read the voltage value of the power supply

    AT+CBC
    +CBC: 0.039V

    OK

AT+CPMUTEMP Read the temperature of the module

    AT+CPMUTEMP
    +CPMUTEMP: 34

    OK

AT+CGSETV Set the value of specified GPIO

    AT+CGSETV=?
    +CGSETV: (1,2,3,4),(0-1),(0-1)

    OK

AT+CGGETV Get the value of specified GPIO

    AT+CGDRT=3,0
    OK

    AT+CGGETV=3
    +CGGETV: 3,0

    OK

## wifi scan 

AT+CWSTASCAN Scan WIFI network