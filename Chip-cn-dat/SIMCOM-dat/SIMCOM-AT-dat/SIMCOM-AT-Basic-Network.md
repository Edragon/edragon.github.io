

## AT+CREG
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


### no network 

    AT+CREG?
    +CREG: 0,2

    OK

## AT+CSQ

    AT+CSQ
    +CSQ: 24,0
    OK

Execution Command returns received signal strength indication <rssi> and channel bit error rate <ber> from the ME



## AT+COPS - slow reply 

    AT+COPS?
    +COPS: 0,2,"46001",7

    AT+COPS=?
    +COPS:(2,"CHN-UNICOM","UNICOM","46001",7),(3,"CHINA MOBILE","CMCC","46000",0),(3,"CHN-CT","CT","46011",7),(3,"CHINA MOBILE","CMCC","46000",7),,(0,1,2,3,4),(0,1,2)

## AT+CPSI

    AT+CPSI?
    +CPSI: LTE,Online,460-01,0x254F,102117378,85,EUTRAN-BAND3,1650,5,0,16,59,61,9



## AT+CPING Ping destination address

    for sim7020
    
    AT+CIPPING="111.13.100.92",4,32,100

    AT+CPING="www.baidu.com",1,4,64,1000,10000,255
    OK

    +CPING: 1,163.177.151.109,60,85,54

    +CPING: 1,163.177.151.109,60,35,54

    +CPING: 1,163.177.151.109,60,25,54

    +CPING: 1,163.177.151.109,60,30,54

    +CPING: 3,4,4,0,25,85,43

## AT+CGATT

    AT+CGATT? 
    +CGATT: 1 
    
    OK 





### AT+CGNSINF

### AT+CGMI

    AT+CGMI
    SIMCOM_Ltd
    OK

### AT+CGMM
    AT+CGMM
    SIMCOM_SIM7080
    OK

### AT+CGSN

## basic 

### AT+GSV 

    SIMCOM_Ltd
    SIM7020G
    Revision:1752B02SIM7020G
    OK

### GPS

    AT+CGNSPWR=1
    AT+CGNSPWR?
    AT+CGNSIPR=9600
    AT+CGNSINF



### AT+CPIN

    AT+CPIN?
    AT+CPIN=password123

### init 

    +CPIN: READY
    SMS DONE
    +CEREG: 1,"774b","0770ac34",7
    +CGEV: EPS PDN ACT 1
    PB DONE


### AT+COPN




### AT+CGATT

    AT+CGATT? Packet domain attach or detach
    +CGATT: 1

### AT+IPREX - permantly set baud rate 
    AT+IPREX=9600
    AT+IPREX=115200

### AT+GSN - Request TA Serial Number Identification (IMEI)

    AT+GSN
    866192034590826

# SIM7020G

    AT+CSQ
    +CSQ: 2,0

    OK

    AT+CREG?
    +CREG: 0,2

    OK

    AT+CIPPING="111.13.100.92",4,32,100

    AT+CNMP=2


    AT+CEREG=5



## Network 

### AT+CBAND

AT+CBAND?
+CBAND: ALL_MODE

OK

### AT+SNPING4

- AT+SNPING4="202.89.233.101",1,16,5000
- AT+CIFSR

### AT+CNSMOD?
+CNSMOD: 0,9

OK

<stat>
- 0 no service
- 1 GSM
- 3 EGPRS
- 7 LTE M1
- 9 LTE NB


### AT+COPN Read Operator Names


### AT+CCLK?

AT+CCLK?
+CCLK: "80/01/06,00:22:45+00"

OK


### AT+CIICR - Bring Up Wireless Connection with GPRS

### AT+CEREG?

### AT+CGNAPN
+CGNAPN: 1,"CMIOT"

OK

### AT+COPS?

AT+COPS?
+COPS: 0,0,"CHINA MOBILE CMCC",9

OK

### AT+CNACT

AT+CNACT=1
OK

+APP PDP: ACTIVE

AT+CNACT?
+CNACT: 1,"10.126.178.255"

OK


## GPRS 
