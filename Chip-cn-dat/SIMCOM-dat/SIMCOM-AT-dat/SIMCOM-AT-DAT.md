
# SIMCOM AT dat 

legacy wiki page 
https://w.electrodragon.com/w/SIM7020_AT

- [[SIMCOM-AT-GNSS-dat]]



# SIMCOM AT

- [[SIMCOM-AT-Basic-Network]]


### AT

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


## ref 

- [[SIMCOM-AT]]