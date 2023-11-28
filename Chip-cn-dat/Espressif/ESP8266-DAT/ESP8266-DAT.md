
# ESP8266 


- [[esp-modules-dat]]

### common pins 


| pin    | setup | func                                  | Note    |
| ------ | ----- | ------------------------------------- | ------- |
| U0_RXD | GPIO3 | I/O UART Rx during flash programming  |         |
| U0_TXD | GPIO1 | I/O UART TX during flash programming; | SPI_CS1 |

serial1 = 

### bootstrap

| pin    | setup                | func          |
| ------ | -------------------- | ------------- |
| RESET  | pull up + cap 0.1 UF |               |
| EN     | pull up              |               |
| IO0    | pull up              |               |
| IO2    | pull up              | on-module LED |
| GPIO15 | pull down            |               |

![](15-46-00-28-03-2023.png)


## Modules 

| models                   | SKU             | note                                                             |
| ------------------------ | --------------- | ---------------------------------------------------------------- |
| [[ESP-01-DAT]] = ESP-01S | [[NWI1077-dat]] | General DIP PTH version, less pin lead out, easy to use          |
| [[ESP-01-DAT]] = ESP-01M | [[NWI1127-dat]] | Vertical stand on your PCBsave space and better signal           |
| [[ESP-07S-DAT]]          | [[NWI1075-dat]] | Pin compatible with esp-12, IPEX connector to get greater signal |
| [[ESP-12F-DAT]]          | [[NWI1059-dat]] | Common ESP8266 module early version                              |
| [[ESP-12S-DAT]]          | [[NWI1086-dat]] | optimized from [[ESP-12F-dat]]                                   |
| [[ESP-WROOM-02-dat]]     | [[NWI1112-dat]] | Most certificated, best design by original Espressif.            |


- [[ESP-01-DAT]] - [[ESP-07S-DAT]] - [[ESP-12F-DAT]] - [[ESP-12S-DAT]]

Sell - [[NWI1059-dat]] - [[NWI1086-dat]] - [[NWI1077-dat]] - [[NWI1127-dat]] - [[NWI1075-dat]]

- [[NWI1112-dat]] - [[NWI1160-dat]] - [[NWI1161-dat]]


## ref 

- CN datasheet of all series - [[esp8266系列使用手册.pdf]]


- [[ESP8266]]