
# LGT8F328-SSOP20-dat

- [[atmega328-dat]]

- [[LGT8F328-DAT]] - [[LGT8F328-SSOP20-dat]] - [[LGT-dat]] - [[LGT8F328-SDK-DAT]]

- [[]]

- [[driver-dat]]


## board 

- [[DVA1014-dat]] - [[DVA1018-dat]]




## LGT8F328P-SSOP20 

![](2025-06-25-14-39-49.png)


| arduino     | pin | LGT8F328-SSOP20 | function     | slave |
| ----------- | --- | --------------- | ------------ | ----- |
| GND         | 5   | GND             | GND          |       |
| 3V3         | 4   | 3V3             | 3.3V         |       |
| RST         | 1   | RST             | reset        |       |
| RST + 0.1uf | 1   | RST + 0.1uf     | rest + 0.1UF |       |
| D2          | 2   | D2              | INT0         |       |
| D3          | 3   | D3              | INT1         |       |
| RXD         | 9   | D6              | UART0        |       |
| TXD         | 8   | D5              | UART0        |       |
| D7          | 10  | D7              |              |       |
| D9          | 11  | D9              |              |       |
| x           | 6   | PB6             |              |       |
| x           | 7   | PB7             |              |       |
| D11         | 12  | D11             | MO           |       |
| D12         | 13  | D12             | MI           |       |
| D13         | 14  | D13             | SCK          |       |
| x           | 15  | PE0             | SWC          |       |
| x           | 16  | PE2             | SWD          |       |
| A0          | 17  | PC0             |              |       |
| A1          | 18  | PC1             |              |       |
| A4          | 19  | PC4             | SCL          |       |
| A5          | 20  | PC5             | SDA          |       |



[[arduino-dat]] compatible design 

![](2025-06-25-14-42-46.png)


## SDK 

C:\Users\Administrator\AppData\Local\Arduino15\packages\lgt8fx\hardware\avr\2.0.7\bootloaders\lgt8fx8ds20\optiboot_lgt8f88ds20.hex

https://github.com/dbuezas/lgt8fx

compile by - [[arduino-dat]]

"C:\\Users\\Administrator\\AppData\\Local\\Arduino15\\packages\\DxCore\\tools\\avr-gcc\\7.3.0-atmel3.6.1-azduino8a/bin/avr-objcopy" -O ihex -R .eeprom "C:\\Users\\Administrator\\AppData\\Local\\arduino\\sketches\\A205FB4B03B052BB263E3D031BDFA0CD/Blink.ino.elf" "C:\\Users\\Administrator\\AppData\\Local\\arduino\\sketches\\A205FB4B03B052BB263E3D031BDFA0CD/Blink.ino.hex"

"C:\\Users\\Administrator\\AppData\\Local\\Arduino15\\packages\\DxCore\\tools\\avr-gcc\\7.3.0-atmel3.6.1-azduino8a/bin/avr-size" -A "C:\\Users\\Administrator\\AppData\\Local\\arduino\\sketches\\A205FB4B03B052BB263E3D031BDFA0CD/Blink.ino.elf"


    C:\Users\Administrator\AppData\Local\arduino\sketches\A205FB4B03B052BB263E3D031BDFA0CD\Blink.ino.hex

upload by [[LGT-SWDICE_MKII-dat]] - [[LGT-dat]]

![](2026-04-21-22-34-06.png)

- programming test D12 

## ref 

- [[LGT-dat]]