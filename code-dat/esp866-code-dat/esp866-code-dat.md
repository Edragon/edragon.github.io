

# esp866-code-dat

- [[esp866-code-dat]] - [[ESP8266-SDK-dat]] - [[ESP-dat]]

- [[CRSF-dat]]

## design 

slow software serial - can not be more than 115200 baud, otherwise the data will be corrupted.

The data you shared is raw CRSF binary packets, but they look slightly corrupted or "jittery," which is very common when using SoftwareSerial at 115200 on an ESP8266.

- [[CRSF-dat]]

    0B 56 FE D8 10 0B 56 FE D8 10 0B 52 FE 84 D8 10 
    0B 52 FE D8 10 0B 56 FE D8 10 0B 52 FF D8 10 0B 
    52 FF D9 10 99 FF 44 D8 10 0B 56 FE D8 10 0B 52 
    FF D8 10 0B 56 FE D8 10 0B 56 FF 25 26 12 4B A2 
    D8 10 0B 52 FE D8 10 0B 56 FE A6 12 4B D8 10 99 
    FF D8 10 0B 56 FE E4 26 12 4B A2 A6 12 4B D8 10 
    0B 52 FE D8 10 0B 56 FE D8 10 0B 56 FF 84 D8 10 
    99 FF D8 10 0B 52 FF D8 10 0B 56 FE A6 12 4B A4 
    D8 10 0B 56 FE D8 10 FF D8 10 0B 52 FE D8 10 0B 
    56 FE D8 10 0B 56 FE 44 12 4B FF D8 10 0B 52 FF 
    D8 10 0B 56 FF D9 10 FE D8 10 0B 56 FF 80 D8 10 
    0B 56 FF D8 10 0B 56 FF 12 4B 54 FF 84 D8 10 0B 
    52 FF D8 10 0B 52 FF D8 10 0B 52 FF D8 10 0B 56 
    FF D9 10 FE C4 D9 10 0B 56 FF D8 10 FE 12 4B 02 
    4E D8 10 0B D2 FF D8 10 FE A2 D8 10 0B 52 FF D8 
    10 0B 56 FF D8 10 FE D8 10 0B 56 FF 00 80 D8 10 
    0B 56 FE D8 10 0B 56 FE D8 10 0B 52 FE D8 10 FF 
    D8 10 0B 56 FE 80 D8 10 0B 52 FE D8 10 0B 56 FE 
    D8 10 0B 52 FE D8 10 0B 52 FE D8 10 99 FF 40 D8 


## ref 


