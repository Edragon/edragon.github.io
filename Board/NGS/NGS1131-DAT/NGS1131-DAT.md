
# NGS1131 DAT 

- [[A7670-DAT]]

## Hardware

![](08-59-16-08-02-2023.png)

- Hold down reset button for 2 seconds to boot the module 
- pull up   reset pin    for 2 seconds to boot the module (by external MCU)

### Pin Definitions 

- RST 
- GND 
- PEN 
- RXD 
- TXD
- ~RI 
- DTR 
- 3V3 
- VIN 
- VBUS

Note 
- When use VIN input, UART serial logic level power +5V should be supplied via VUSB
- 3.3V logic is supplied on board 


### Wiring UART communication with ESP32

| ESP32      | note         | A7670               |
| ---------- | ------------ | ------------------- |
| IO18 IO19  | UART         | A7670C              |
| Vin / Vusb | Logic Level  | A7670C logic        |
| Vin / Vusb | Power Supply | A7670C Power Supply |

![](15-36-16-05-01-2023.png)


