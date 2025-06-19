
# simcom-at-sscom-network-dat

simcom-at-sscom-network-dat preconfig == [[sscom51.ini]]


## 4.2.2 AT+COPS Operator selection


    AT+COPS?
    +COPS: 0,2,"46011",7

    OK

## 4.2.5 AT+CPOL Preferred operator list

## 4.2.6 AT+COPN Read operator names


    AT+COPN
    +COPN: "46000","CHINA MOBILE"

    +COPN: "46001","CHN-UNICOM"

    +COPN: "46002","CHINA MOBILE"

    +COPN: "46003","CHN-CT"

    +COPN: "46004","CHINA MOBILE"

    +COPN: "46005","CHINA TELECOM"

    +COPN: "46006","CHN-UNICOM"

    +COPN: "46007","CHINA MOBILE"

    +COPN: "46008","CHINA MOBILE"

    +COPN: "46009","CHN-UNICOM"

    +COPN: "46011","CHN-CT"

    +COPN: "46015","CHINA BROADNET"

    OK

## 4.2.7 AT+CNMP Preferred mode selection

2 Automatic

    AT+CNMP?
    +CNMP: 2

## 4.2.9 AT+CPSI Inquiring UE system information

    AT+CPSI?
    +CPSI: LTE,Online,460-11,0x774B,126375687,303,EUTRAN-BAND1,100,5,0,12,36,42,5

    OK

## 5.2.3 AT+CGATT Packet domain attach or detach

    AT+CGATT?
    +CGATT: 1

    OK

## 5.2.4 AT+CGACT PDP context activate or deactivate

    AT+CGACT?
    +CGACT: 1,1

    +CGACT: 8,1

    OK


## 5.2.5 AT+CGDCONT Define PDP context

    AT+CGDCONT=?
    +CGDCONT: (1-15),"IP",,,(0-2),(0-1),(0-1),(0-2)
    +CGDCONT: (1-15),"IPV6",,,(0-2),(0-1),(0-1),(0-2)
    +CGDCONT: (1-15),"IPV4V6",,,(0-2),(0-1),(0-1),(0-2)

    OK
    AT+CGDCONT?
    +CGDCONT: 1,"IP","nodata.MNC011.MCC460.GPRS","10.63.231.228",0,0,,,,

    +CGDCONT: 8,"IPV4V6","IMS","254.128.0.0.0.0.0.0.24.72.135.247.235.115.194.34",0,0,0,2,1,1

    OK

## 5.2.12 AT+CGDATA Enter data state

    AT+CGDATA="",1
    CONNECT

## 5.2.13 AT+CGPADDR Show PDP address

    AT+CGPADDR=1
    +CGPADDR: 1,10.83.214.110


## web ping 

test1 

    AT+CPING="www.baidu.com",1,4,64,1000,10000,255
    OK

    +CPING: 1,157.148.69.186,92,170,52

    +CPING: 1,157.148.69.186,92,130,52

    +CPING: 1,157.148.69.186,92,840,52

    +CPING: 1,157.148.69.186,92,125,52

    +CPING: 3,4,4,0,125,840,310

test2 
    AT+CPING="www.baidu.com",1,4,64,1000,10000,255
    OK

    +CPING: 2

    +CPING: 2

    +CPING: 1,192.168.0.100,92,0,128

    +CPING: 1,192.168.0.100,92,0,128

    +CPING: 3,4,2,2,0,0,0


## TCPIP 

- [[TCPIP-dat]]

### 15.2.1 AT+NETOPEN Start Socket Service

    AT+NETOPEN?
    +NETOPEN: 0

    OK
    AT+NETOPEN
    OK

    +NETOPEN: 0
    AT+NETOPEN?
    +NETOPEN: 1

    OK


### 15.2.3 AT+CIPOPEN Establish Connection in Multi-Socket Mode


    AT+CIPOPEN=0,"TCP","183.230.174.137",6031
    OK

    +CIPOPEN: 0,1