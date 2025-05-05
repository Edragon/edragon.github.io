
# Espressif-dat

## Modules Series 

- [[ESP32-dat]] - [[ESP32-compare-dat]]

- [[ESP8266-dat]]

- [[ESP8684-dat]]

- [[ESP8685-dat]]

## Software and SDK 

- [[ESP-SDK-dat]]


## longevity-commitment

- ESP8266 ganurtee until 2029 

https://www.espressif.com.cn/en/products/longevity-commitment

Based on their commitment, ESP8266 will at least last until 2029. It is just not recommended for new designs. 

New design should use ESP8684, also called ESP32-C2, I will try to add more information later.

## Debug 

### ESP failed when system trying to connect to WIFI

- USB power supply must be sufficient, the WIFI connection cost peak current up to 500mA, USB without external power supply will NOT work

- use external power supply instead, and check if you can find ESP IP address if wifi back-end console page. 



## ref 

- [[ESP-SDK-dat]]