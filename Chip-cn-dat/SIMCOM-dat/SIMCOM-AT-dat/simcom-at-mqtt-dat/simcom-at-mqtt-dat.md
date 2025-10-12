
# simcom-at-mqtt-dat

- [[SIMCOM-AT-DAT]]

- [[simcom-at-mqtt-dat.exe]] - preconfig == [[SSCOM51.ini]]

- [[MQTT-dat]]

- [[A7670-dat]]

log start 

    AT+CMQTTSTART
    OK

    +CMQTTSTART: 1

set channel 

    AT+CMQTTACCQ=0,"a12mmmm",0

- note: Changed from AT+CMQTTACCQ=0,"a12mmmm",0 to AT+CMQTTACCQ=0,"a12mmmm". The third parameter might not be supported by your modem


connect to server 

    AT+CMQTTCONNECT=0,"tcp://206.237.31.27:1883",20,1,"electrodragon","electrodragon"


send message 

    AT+CMQTTTOPIC=0,4
    >
    OK
    AT+CMQTTPAYLOAD=0,6
    >
    OK
    AT+CMQTTPUB=0,0,60
    OK

    +CMQTTPUB: 0,0



receive message 

    +CMQTTRXSTART: 0,4,6
    +CMQTTRXTOPIC: 0,4
    test
    +CMQTTRXPAYLOAD: 0,6
    999999
    +CMQTTRXEND: 0




will info 


    AT+CMQTTWILLTOPIC=0,4
    >test
    OK
    AT+CMQTTWILLMSG=0,6,1
    >123456
    OK

## ref 

- [[SIMCOM-dat]]