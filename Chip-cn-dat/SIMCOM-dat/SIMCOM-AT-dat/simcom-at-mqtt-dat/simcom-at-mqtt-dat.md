
# simcom-at-mqtt-dat

- [[SIMCOM-AT-DAT]]

- [[simcom-at-mqtt-dat.exe]] - preconfig == [[SSCOM51.ini]]

- [[MQTT-dat]]


log 

    AT+CMQTTSTART
    OK

    +CMQTTSTART: 1


    AT+CMQTTWILLTOPIC=0,4
    >test
    OK
    AT+CMQTTWILLMSG=0,6,1
    >123456
    OK


receive message 

    +CMQTTRXSTART: 0,4,6
    +CMQTTRXTOPIC: 0,4
    test
    +CMQTTRXPAYLOAD: 0,6
    999999
    +CMQTTRXEND: 0

## ref 

- [[SIMCOM-dat]]