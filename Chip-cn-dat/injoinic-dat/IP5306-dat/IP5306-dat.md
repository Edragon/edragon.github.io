
# IP5306-dat

- [[OPM1123-dat]] - [[NWI1241-dat]]

- DS: https://www.laskakit.cz/user/related_files/ip5306.pdf

## HDK 

- KEY = flashing LED output and key function as below 

Push button’s connecting is shown in Fig 5. IP5306 can identify long push and short push.

| **Feature**                                  | **Description**                                                                 |
|----------------------------------------------|---------------------------------------------------------------------------------|
| **No Key Required**                          | If no key is needed, PIN5 can remain floating.                                  |
| **Short Press (30ms - 2s)**                  | Activates the battery level indicator and boost output.                         |
| **Long Press (>2s)**                         | Turns the LED light on or off.                                                  |
| **Press Duration (<30ms)**                   | No response will be triggered.                                                  |
| **Double Short Press (within 1s)**           | Turns off the boost output, battery level indicator, and LED light.             |


## Typical SCH 

![](2024-03-27-17-08-13.png)


## versions 

- IP5306-I2C
- IP5306-LC
- IP5306       = 4.20V
- IP5306_4.30V = 4.30V
- IP5306_4.35V = 4.35V
- IP5306_4.40V = 4.40V

## Note 
- According to the data sheet (in Chinese language only by the way), if the load current drops below 45mA during 32 seconds, the IP5306 goes into standby.
- battery need to be attached and "activate" by charging first 
- MAKE SURE to use high quality, full charged battery for testing, otherwise could cause power off 
- The board does not supports modern quick charging options, like QC, PD, etc 

![](2024-03-27-17-03-26.png)

- to prevent board enter into sleep mode automatically for small power load, you can add some more load resistors to keep it continuously on.

- this chip has two version: LED version or I2C version, normllay we only provide LED-version 

### standby issue 

- You can use IP5306_CK，this version always output 5V.
- I2C function only apply to IP5306_I2C custom design. you can order samples use the name: IP5306_I2C.
- Accessory is the I2C register document of IP5306, you can use IP5306_I2C, then modify IP5306's register(reg0x00[1]=1) to make IP5306 always output 5V.


## IP3506-I2C 

- LED1 = SCL
- LED2 = SDA 
- LED3 = detect the sleep mode 

- [[IP5306-I2C-DS.pdf]]


### SCH 

![](2024-12-28-15-01-01.png)



## ref 

- [[IP5306]]

- [[solutions-dat]]