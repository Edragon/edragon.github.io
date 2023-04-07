

# NGS1128-DAT

## Hardware 

### V2 version 
- Simplified Connection: TXD / RXD / GND / VIN
- VIN: 4.2-18Vin
- default TXD / RXD logic at 3.3V
- Boot: hold down boot button for 2 seconds, or pull key pin to up for 2 seconds

![](21-53-15-14-03-2023.png)


### V1 version 

![](36-15-17-03-04-2023.png)

Lead out all the function pins
- TXD / RXD / RTS / CTS / DCD / DTR / RI (via logic shifter)
- ADC / 1V8 / CS / SI / CLK / SO (SPI)
- DIN / DOUT / CLK / SYNC (PCM) / IO5 / USB_BOOT
- IO1 / IO3 / U3T / SDA / U2T
- IO2 / IO4 / U3R/ SCL / U2R
- MCU_BOOT / EXT_3V3 / VBAT / GND / 5V / DM / DP / USB_V

## Use Guide 

### boot the module 
- hold down the top-middle small button for 2 seconds to boot the module
- or pull the "boot" pin to high for 2 seconds to boot the module 



### Use as a Modem and COM PORT

- power via USB

![](27-07-17-14-03-2023.png)




## ref 

- Driver: [[git]] simcom_driver
- chip documentation: [[git]] SIMCOM_SIM70X0
- [[MQTT]]
- [[NGS1128]]
- [[SIMCOM-AT]]
- [[SIMCOM-AT-GNSS]]
- https://w.electrodragon.com/w/SIM7080