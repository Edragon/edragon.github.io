
# SIMCOM AT dat 

legacy wiki page 
https://w.electrodragon.com/w/SIM7020_AT

- [[SIMCOM-AT-GNSS]]



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


## ref 

- [[SIMCOM-AT]]