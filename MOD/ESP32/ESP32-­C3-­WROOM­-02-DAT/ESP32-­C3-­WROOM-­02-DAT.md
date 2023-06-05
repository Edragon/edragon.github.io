

![](33-15-13-29-12-2022.png)


## Dimensions 
![](22-24-13-29-12-2022.png)

## Pin Definitions 
![](30-35-16-06-02-2023.png)


## datasheet 
https://www.espressif.com.cn/sites/default/files/documentation/esp32-c3-wroom-02_datasheet_cn.pdf

## Flash 

- [[flash-download-tool]] - [[arduino-ESP32]]


## FAQ

### can not select the correct board ESP32C3 
- upgrade ESP32 SDK in arduino into the latest version 
- board selection ESP32C2 DEV Board 

- If you have rebooting problems, you can try to use ESP flash tool to erase the whole module incase of any conflicts, normally in Arduino it is not that necessary.


### checksum issue for arduino previous version 

- https://github.com/espressif/arduino-esp32/issues/7011
- solution: upgrade to latest arduino ESP32 boards 
- problem occured on version before 2.0.5
- we tested with vesion 2.0.6, works OK 