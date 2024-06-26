

# DVA1007 DAT

legacy wiki page
- https://w.electrodragon.com/w/Loraduino


## hardware setup 

| Function Pin | category | Arduino |
| ------------ | -------- | ------- |
| Flash_CS     | D8       | Flash   |
| LED          | D7       | LED     |
| RF_CS        | D10      | SX1278  |
| RF_INT       | D2       | SX1278  |
| RF_RST       | D8       | SX1278  |
| Voltage-Dect | A7       |         |

### Board Map 

![](2023-11-06-16-04-30.png)
![](2023-11-06-16-06-22.png)

### Pin Definitions

FT232 Programming Port 
- VBAT
- DTR
- TXD
- RXD
- +5V
- GND
- --



## Radio Lora Network 
- arduino library radiohead
- [[arduino-lib]]

## flash 
- must well initiated flash into low power mode 
- 0xEF40 manufactuer ID for 16mbit
- [[flash]] - user lowpower lab flash arduino library 

## bootloader 
- arduino pro mini 3.3V/8M 

## Functions 

- [[SPI-flash-dat]] - [[memory-dat]] - [[low-power-dat]] - [[lora-dat]]

## Lora Modules 

- [[NWL1071-dat]] - [[NWL1072-dat]]

- [[LDO-dat]]

- [[DVA1007]] - [[DVA1008]] - [[DVA1009]]


## demo 

- low power - https://x.com/electro_phoenix/status/1639160253811142656

