
# ESP32-FAQ




### Will ESP32-WROOM-32U be damaged if operated without an antenna?

- It can be damaged, and for this reason it is not recommended to any enable RF transmission without a suitable antenna connected.

- ref https://esp32.com/viewtopic.php?t=10797



### can not select the correct board ESP32C3 
- upgrade ESP32 SDK in arduino into the latest version 
- board selection ESP32C2 DEV Board 

- If you have rebooting problems, you can try to use ESP flash tool to erase the whole module incase of any conflicts, normally in Arduino it is not that necessary.


### checksum issue for arduino previous version 

- https://github.com/espressif/arduino-esp32/issues/7011
- solution: upgrade to latest arduino ESP32 boards 
- problem occured on version before 2.0.5
- we tested with vesion 2.0.6, works OK 