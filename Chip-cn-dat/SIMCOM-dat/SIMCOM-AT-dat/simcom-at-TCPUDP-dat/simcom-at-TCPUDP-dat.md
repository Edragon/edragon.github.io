
# simcom-at-TCPUDP-dat

- [[SIMCOM-AT-DAT]]

- [[simcom-at-mqtt-dat.exe]] - preconfig == [[SSCOM51.ini]]

- [[TCPIP-dat]] - [[UDP-dat]]


## log 

    AT+CIPOPEN=5,"UDP",,,6031
    +CIPOPEN: 5,0

    OK
    AT+CIPOPEN?
    +CIPOPEN: 0
    +CIPOPEN: 1
    +CIPOPEN: 2
    +CIPOPEN: 3
    +CIPOPEN: 4
    +CIPOPEN: 5,"UDP","0.0.0.0",0,-1
    +CIPOPEN: 6
    +CIPOPEN: 7
    +CIPOPEN: 8
    +CIPOPEN: 9

    OK

    AT+CIPSEND=8,5,"183.230.174.137",6031
    +CIPERROR: 3

    ERROR
    AT+CIPSEND=5,5,"183.230.174.137",6031
    >12345
    OK

    +CIPSEND: 5,5,5



AT+CIPSEND Send data through TCP or UDP Connection

If service type is "UDP", send data with fixed length

    AT+CIPSEND=8,5,"183.230.174.137",6031
    >12345
    OK
    +CIPSEND: 8,5,5






## errors 

Numeric Value String Value
- 0 Connection time out
- 1 Bind port failed
- 2 Port overflow
- 3 Create socket failed
- 4 Network is already opened
- 5 Network is already closed
- 6 No clients connected
- 7 No active client
- 8 Network not opened
- 9 Client index overflow
- 10 Connection is already created
- 11 Connection is not created
- 12 Invalid parameter
- 13 Operation not supported
- 14 DNS query failed
- 15 TCP busy
- 16 Net close failed for socket opened
- 17 Sending time out
- 18 Sending failure for network error
- 19 Open failure for network error
- 20 Server is already listening
- 21 Operation failed
- 22 No data

## ref 

- [[SIMCOM-dat]]