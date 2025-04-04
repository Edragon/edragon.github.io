
# ESP1000-dat

Module based on [[SCM1030-dat]]




## All in one Pin Map 

| ESP32 L_Pin | ESP32_CAM | tori     | ESP32 M_Pin | ESP32_CAM | tori   | ESP32 R_Pin | ESP32_CAM      | tori |
| ----------- | --------- | -------- | ----------- | --------- | ------ | ----------- | -------------- | ---- |
| GND         |           |          | GND2        |           |        | GND         |                |      |
| 3V3         |           |          | 13          | microSD   | SCL    | 23          | CAM            |      |
| EN          |           |          | SD2         | PSRAM     |        | 22          | CAM            |      |
| 36          | CAM       |          | SD3         | PSRAM     |        | TXD0        |                |      |
| 39          | CAM       |          | CMD         |           |        | RXD0        |                | PIR  |
| 34          | CAM       |          | CLK         |           |        | 21          | CAM            |      |
| 35          | CAM       |          | SD0         | PSRAM     |        | --          |                |      |
| 32          | CAM_PWR   |          | SD1         | PSRAM     |        | 19          | CAM            |      |
| 33          |           |          | 15          | microSD   | SDA    | 18          | CAM            |      |
| 25          |           |          | 2           | microSD   | I2S_WS | 5           | CAM            |      |
| 26          | CAM       |          |             |           |        | 17          | PSRAM          |      |
| 27          | CAM       |          |             |           |        | 16          | PSRAM          |      |
| 14          | microSD   | I2S_SD   |             |           |        | 4           | microSD, flash |      |
| 12          | microSD   | I2S_SCLK |             |           |        | 0           | CAM            |      |


## Board map 

![](2025-02-21-14-53-56.png)

### Programming Note 

- Purple box jumper must be disconnected for enabling RXD0, otherwise used by PIR sensor 
- Connect purple box by a jumper to enter into programming mode 

### more jumpers note: 

- "GND3" - disconnect pin from GND, due a problem on [[SCM1030-dat]] board V1701, default does not connect 
- "USB-5V" - set USB power supply, default ON, simplifed the power supply, see section below 
- "JP3" - set PIR sensor power supply to 3.3V, could be better to do at 2.5V

### Power Supply 

Version 1.1 

- Simplfied Power Supply, connect [[serial-dat]] 5V / GND / TXD / RXD to use, [[lithium-battery-dat]] can be charged by USB cable or [[serial-dat]]

Verion 1.0 

- top-left green box will be used for power ESP32 ONLY, not for our this based board
- To use our this base board sensors while debugging, please use: 
  - Lihtium battery + USB Cable 
  - USB-TTL debug power supply + USB Cable 

![](2025-02-21-14-58-48.png)
![](2025-02-21-14-59-03.png)




### ESP32-CAM Version Note

- fixed by jumper in version 1.1
- version V1701 GND3 is not woring, please read at [[SCM1030-dat]], just bend this pin or cut if off to leave it


## In Use 

- [[I2S-dat]] - [[I2S-microphone-dat]]

- [[PIR-sensor-dat]]  - [[OLED-dat]] 
  
- [[sensor-dat]] - [[I2C-dat]] - [[BME280-dat]] - [[BMP280-dat]]

solar charge and battery function please refer to [[BAT1002-dat]]

- [[consonance-dat]] - [[solar-power-dat]] - [[battery-dat]] - [[lithium-ion-battery-dat]]

- [[ESP32-dat]] - [[SCM1030-dat]]



## Not in Use  

- [[SD-dat]] - [[IP5306-dat]]


## Demo Code 

- BSP/ESP/ESP1000-ESP32-tori @ https://github.com/Edragon/Arduino-ESP32

code test: 
- T1: 
  - T1.1-BMP280-PIR-OLED.ino
  - T1-all-test.ino == test for BMP280, SSD1306 OLED, PIR sensor
- T2: T2-CameraWebServer.ino == Camera test please use official code 
- T3: T3-I2S-mem-mic.ino == test for [[I2S-microphone-dat]]

pin definitions: 

    #define I2S_WS 02
    #define I2S_SD 14
    #define I2S_SCK 12
    SSD1306Wire display(0x3c, 15, 13);
    BMx280I2C bmx280(0x76);

    #define flash 4
    #define PIR 3

## Demo Video 

- [default camera log, powered by battery](https://x.com/electro_phoenix/status/1881569671020949656) 
- [I2S camera sound detect](https://x.com/electro_phoenix/status/1877590478109159437)
- [PIR sensor detector](https://x.com/electro_phoenix/status/1877256534687650008)

- [I2S sound test 2](https://t.me/electrodragon3/349) 


## ref 

- [[ESP1000]] - [[PIR-sensor]]