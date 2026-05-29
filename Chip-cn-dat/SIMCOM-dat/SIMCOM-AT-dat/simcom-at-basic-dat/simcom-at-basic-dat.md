
# simcom-at-sscom-basic-dat

- [[SIMCOM-AT-DAT]]

- [[simcom-at-sscom-dat.exe]] - preconfig == [[SSCOM51.ini]]


tested == [[SIM868-dat]] - [[NGS1089-dat]]

## Basic 


AT+CGMR
Revision:1418B06SIM868M32_BT

OK

1418B06 SIM868 M32_BT 
- 1418B06: Represents the firmware version/revision.
- SIM868M32_BT: Indicates the specific module model and hardware configuration.

AT+CGSN
868298067490038

OK

AT+GMM
SIMCOM_SIM868

OK

AT+GMI 
SIMCOM_Ltd

OK
AT+GMR
Revision:1418B06SIM868M32_BT

OK
AT+GSN
868298067490038

OK
AT+CGMI
SIMCOM_Ltd

OK

boot log 

    *ATREADY: 1

    +CPIN: READY

    SMS DONE

    +CGEV: EPS PDN ACT 1

    +CGEV: ME PDN ACT 8,1

    +CGEV: NW PDN DEACT 1

    +CGEV: ME DETACH

    +CGEV: EPS PDN ACT 1

    +CGEV: ME PDN ACT 8,1

    +CMTI: "SM",1

    +CMTI: "SM",2

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



### AT+CGMM

    AT+CGMM
    A7670SA-FASE

    OK




## Call 

    ATD18576608994;
    +CME ERROR: no network service



## ref 

- [[SIMCOM-dat]]