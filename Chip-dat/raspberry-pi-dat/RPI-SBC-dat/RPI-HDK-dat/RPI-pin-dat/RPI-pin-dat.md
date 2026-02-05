
# RPI-pin-dat

- [[MPC1120-dat]]

- [[I2C-dat]] - [[RPI3-I2C0-dat.md]] - [[RPI-pin-dat]]



## RPI-26P-dat

![](2024-01-14-11-12-16.png)


## RPI-40P-dat

| note   | GPIO | pin | pin | GPIO | note2  |
| ------ | ---- | --- | --- | ---- | ------ |
| 3V3    | -    | 1   | 2   | -    | 5V     |
| SDA    | 2    | 3   | 4   | -    | 5V     |
| SCL    | 3    | 5   | 6   | -    | Ground |
|        | 4    | 7   | 8   | 14   | TXD    |
| Ground | -    | 9   | 10  | 15   | RXD    |
| ce1    | 17   | 11  | 12  | 18   | ce0    |
|        | 27   | 13  | 14  | -    | Ground |
|        | 22   | 15  | 16  | 23   |        |
| 3V3    | -    | 17  | 18  | 24   |        |  
| MOSI   | 10   | 19  | 20  | -    | Ground |
| MISO   | 9    | 21  | 22  | 25   |        |
| SCLK   | 11   | 23  | 24  | 8    | CE0    |
| Ground | -    | 25  | 26  | 7    | CE1    |
| ID_SD  | 0    | 27  | 28  | 1    | ID_SC  |
|        | 5    | 29  | 30  | -    | Ground |
|        | 6    | 31  | 32  | 12   |        |
|        | 13   | 33  | 34  | -    | Ground |
| miso   | 19   | 35  | 36  | 16   | ce2    |
|        | 26   | 37  | 38  | 20   | mosi   |
| Ground | -    | 39  | 40  | 21   | sclk   |

![](2024-10-03-20-12-54.png)


## GPIO 27 28 

The Primary Function: HAT Identification

These pins are reserved for the I2C ID EEPROM. When you attach a "HAT" (Hardware Attached on Top) to a Raspberry Pi, the system uses these pins to communicate with a small memory chip on the HAT.

Pin 27 (ID_SD): I2C ID Data

Pin 28 (ID_SC): I2C ID Clock

This allows the Raspberry Pi to automatically identify the board, load the correct drivers, and configure the GPIOs accordingly during the boot process.

**Usage Precautions**

- **Avoid General Use**: It is strongly recommended not to use these pins for general-purpose tasks (like connecting LEDs or switches) or for your own I2C sensors.
- **Boot Interference**: Since the Pi probes these pins at startup to look for a HAT, connecting hardware to them can occasionally cause the Pi to hang or fail to boot if it misinterprets the signals.
- **No Internal Pull-ups**: Unlike the default I2C pins (GPIO 2 and 3), these do not have physical 1.8 kΩ pull-up resistors on the board.

**When should you use them?**

You should only focus on these pins if you are designing your own HAT and want it to be "Plug and Play" compliant with Raspberry Pi standards. In that case, you would wire them to an AT24C32 (or similar) EEPROM.



## ref 

- [[RPI-dat]] - [[rpi-python-dat]]