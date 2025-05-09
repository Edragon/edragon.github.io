
# simcom-at-sscom-basic-dat

- [[SIMCOM-AT-DAT]]

- [[simcom-at-sscom-dat.exe]] - [[SSCOM51.ini]]

## commandds 

### AT+CREG

    AT+CREG?
    +CREG: 0,1


- 0 disable network registration unsolicited result code.
- 1 enable network registration unsolicited result code +CREG: <stat>.
- 2 enable network registration and location information unsolicited result code +CREG: <stat>[,<lac>,<ci>].


- 0 not registered, ME is not currently searching a new operator to register to.
- 1 registered, home network.
- 2 not registered, but ME is currently searching a new operator to register to.
- 3 registration denied.
- 4 unknown.
- 5 registered, roaming.
- 6 registered for "SMS only", home network (applicable only when E-UTRAN)



## log 


    AT+CEREG?
    +CEREG: 0,1

    OK

    +CGEV: ME PDN DEACT 8

    +CGEV: ME PDN ACT 8,1


    +CGEV: ME PDN DEACT 8

    +CGEV: ME PDN ACT 8,1


### web ping 

    AT+CPING="www.baidu.com",1,4,64,1000,10000,255
    OK

    +CPING: 1,157.148.69.186,92,170,52

    +CPING: 1,157.148.69.186,92,130,52

    +CPING: 1,157.148.69.186,92,840,52

    +CPING: 1,157.148.69.186,92,125,52

    +CPING: 3,4,4,0,125,840,310