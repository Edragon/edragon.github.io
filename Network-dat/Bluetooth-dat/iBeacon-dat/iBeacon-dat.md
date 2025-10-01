
# iBeacon-dat

## e.g. [[JDY-25M-dat]]

需要配置 iBeacon 模式，请发送 AT+ROLE3，再发 AT+RESET 重启
- 第一步配置 iBeacon 的 UUID：AT+IBUUID 例子：AT+IBUUIDFDA50693A4E24FB1AFCFC6EB07647825
- 第二步配置 iBeacon 的 MAJOR：AT+MAJOR0007
- 第一步配置 iBeacon 的 MINOR：AT+MINOR000A



## ESP32 

    #include <BLEDevice.h>
    #include <BLEServer.h>
    #include <BLEUtils.h>
    #include <BLE2902.h>
    #include <BLEBeacon.h>

    #define DEVICE_NAME         "ESP32"
    #define SERVICE_UUID        "7A0247E7-8E88-409B-A959-AB5092DDB03E"
    #define BEACON_UUID         "2D7A9F0C-E0E8-4CC9-A71B-A21DB2D034A1"
    #define BEACON_UUID_REV     "A134D0B2-1DA2-1BA7-C94C-E8E00C9F7A2D"
    #define CHARACTERISTIC_UUID "82258BAA-DF72-47E8-99BC-B73D7ECD08A5"