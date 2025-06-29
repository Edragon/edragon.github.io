
# ESP8266 

find modules here - [[esp8266-modules-dat]]

## dev board 

- [[NWI1044-dat]] - orignally design for [[nodemcu-dat]]

- [[NWI1083-dat]] small size mini board, pro version [[NWI1122-dat]]

- [[ESP8266-modules-dat]] holder board - [[NWI1050-dat]] - [[NWI1053-dat]] - [[NWI1130-dat]]

## APP Board 

- [[esp-relay-board-dat]] - [[NWI1072-dat]] - [[NWI1124-dat]]

## Hardware 

### chip info 

- DS [[0a-esp8266ex_datasheet_en.pdf]]


### common pins 


| pin   | name   | GPIO | function | Note    | note                                  |
| ----- | ------ | ---- | -------- | ------- | ------------------------------------- |
| 25    | U0_RXD | 3    | IO3      |         | I/O UART Rx during flash programming  |
| 26    | U0_TXD | 1    | IO1      | SPI_CS1 | I/O UART TX during flash programming; |
| 14    | IO2    | 2    | U1_TXD   |         | Flash debug output                    |
| 13    | MTDO   | 15   | U0_RTS   | HSPI_CS |                                       |
| 18~23 | SDIO   |      |          |         |                                       |



### bootstrap

| pin    | default boot         | Against Mode        | [[ESP-12F-dat]] | [[ESP-12S-dat]] | func              |
| ------ | -------------------- | ------------------- | --------------- | --------------- | ----------------- |
| RESET  | pull up + cap 0.1 UF | Reboot              | ext.            | int.            |                   |
| EN     | pull up              | Reboot              | ext.            | int.            |                   |
| IO0    | pull up              | Flash Mode          | ext.            | int.            | Boot mode control |
| IO2    | pull up              |                     | pull-up w/LED   | pull-up w/LED   | on-module LED     |
| GPIO15 | pull down            | Fail into SDIO Mode | ext.            | int.            | MTDO              |

- reference from chip datasheet section "Pin Definitions" Note part

![](15-46-00-28-03-2023.png)

Baud rate 74880 is what the ESP8266 bootloader uses. The apps on top of the Espressif SDK (e.g. Arduino sketch) talk at 115200 if not specified otherwise.

the normal reset boot 

    ets Jan  8 2013,rst cause:2, boot mode:(3,6)

    load 0x40100000, len 28740, room 16 
    tail 4
    chksum 0xef
    load 0x33333333, len 858993459, room 4 

the prog mode boot 

    ets Jan  8 2013,rst cause:2, boot mode:(1,7)

![](2025-06-11-18-18-29.png)

### programmer and programming 

- [[DPR1150-dat]] - [[NWI1070-dat]] for ESP-01/01S 

- Batch Brogramming for ESP8266 modules, use [[OPM1095-dat]] and [[DPR1120-dat]] - https://t.me/electrodragon3/331

### Schematic 

![](2025-05-14-17-59-15.png)

The ESP8266EX schematics include seven aspects: 

• Power supply 
• Power-on sequence and reset 
• Flash 
• Crystal oscillator 
• RF 
• External resistor 
• UART


#### ADC

(4. Peripheral Interface)

Hardware Design - The input voltage range is 0 to 1.0 V when **TOUT** is connected to external circuit.


## Modules and Boards 

- [[ESP8266-modules-dat]] - [[NWI1086-dat]] - [[NWI1077-dat]] - [[NWI1059-dat]] - [[NWI1075-dat]]

- [[ESP-12F-dat]] - [[ESP-12S-dat]] - [[ESP-01-dat]] - [[ESP-01S-dat]]

- [[espressif-dat]] - [[ESP8266-dat]] - [[ESP32-dat]] - [[ESP-dat]]





## ref 

- design guidelines - [[esp8266_hardware_design_guidelines_en.pdf]]

- Module datasheet please see here: https://github.com/Edragon/ESP8266-HDK/tree/master/MOD



- [[ESP8266]]





