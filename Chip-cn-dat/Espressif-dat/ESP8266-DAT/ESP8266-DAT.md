
# ESP8266 

find modules here - [[esp8266-modules-dat.md]]


### common pins 


| pin    | setup | func                                  | Note    |
| ------ | ----- | ------------------------------------- | ------- |
| U0_RXD | GPIO3 | I/O UART Rx during flash programming  |         |
| U0_TXD | GPIO1 | I/O UART TX during flash programming; | SPI_CS1 |

serial1 = U0



### bootstrap

| pin    | setup                | func          |
| ------ | -------------------- | ------------- |
| RESET  | pull up + cap 0.1 UF |               |
| EN     | pull up              |               |
| IO0    | pull up              |               |
| IO2    | pull up              | on-module LED |
| GPIO15 | pull down            |               |

![](15-46-00-28-03-2023.png)


## programmer 

- [[DPR1150-dat]] - [[NWI1070-dat]] for ESP-01/01S 


## ref 

- design guidelines - https://espressif.com/en/support/download/documents?keys=&field_type_tid%5B%5D=16

- CN datasheet of all series - [[esp8266系列使用手册.pdf]]
- Module datasheet please see here: https://github.com/Edragon/ESP8266-HDK/tree/master/MOD




Common Used 

- [[NWI1086-dat]] - [[NWI1077-dat]] - [[NWI1059-dat]] - [[NWI1075-dat]]

- [[ESP-12F-dat]] - [[ESP-12S-dat]] - [[ESP-01-dat]] - [[ESP-01S-dat]]

- [[ESP8266-dat]] - [[ESP32-dat]] - [[ESP-dat]]

- [[ESP8266]]





