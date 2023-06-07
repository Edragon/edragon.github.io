

# ESP32 

- [[ESP32-SDK]]
  
选型工具 
https://products.espressif.com/#/product-selector?language=zh&names=


https://products.espressif.com/#/product-selector?language=en

## pins 
- U0 = RXD0 / TXD0
- U1 = SD2 / SD3 (can not use)
- U2RXD = IO16
- U2TXD = IO17 



## datasheet
- esp32
- https://www.espressif.com/sites/default/files/documentation/esp32_technical_reference_manual_cn.pdf

- ESP32 Chip Revision v3.0 - User Guid
- https://www.espressif.com/sites/default/files/documentation/esp32_chip_revision_v3_0_user_guide_en.pdf

## ESP32-C3

- [[ESP32-C3-DAT]] - [[ESP32-C3-WROOM-02-DAT]]



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