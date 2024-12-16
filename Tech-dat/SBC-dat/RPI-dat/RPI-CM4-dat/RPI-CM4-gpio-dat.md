
# RPI-CM4-gpio-dat


reference extra pins - https://docs.google.com/spreadsheets/d/1m27caMlk2gofswU9ZlBD_y3y81Y_0ARSmmQgm0i1AdQ/edit?gid=0#gid=0

pin definitions - [[cm4-datasheet.pdf]] - Chapter 4. Pinout


| Pin | Signal            | Description                                                                                                                                                                                                         |
| --- | ----------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 1   | GND               | Ground (0V)                                                                                                                                                                                                         |
| 2   | GND               | Ground (0V)                                                                                                                                                                                                         |
| 3   | Ethernet_Pair3_P  | Ethernet pair 3 positive (connect to transformer or MagJack)                                                                                                                                                        |
| 4   | Ethernet_Pair1_P  | Ethernet pair 1 positive (connect to transformer or MagJack)                                                                                                                                                        |
| 5   | Ethernet_Pair3_N  | Ethernet pair 3 negative (connect to transformer or MagJack)                                                                                                                                                        |
| 6   | Ethernet_Pair1_N  | Ethernet pair 1 negative (connect to transformer or MagJack)                                                                                                                                                        |
| 7   | GND               | Ground (0V)                                                                                                                                                                                                         |
| 8   | GND               | Ground (0V)                                                                                                                                                                                                         |
| 9   | Ethernet_Pair2_N  | Ethernet pair 2 negative (connect to transformer or MagJack)                                                                                                                                                        |
| 10  | Ethernet_Pair0_N  | Ethernet pair 0 negative (connect to transformer or MagJack)                                                                                                                                                        |
| 11  | Ethernet_Pair2_P  | Ethernet pair 2 positive (connect to transformer or MagJack)                                                                                                                                                        |
| 12  | Ethernet_Pair0_P  | Ethernet pair 0 positive (connect to transformer or MagJack)                                                                                                                                                        |
| 13  | GND               | Ground (0V)                                                                                                                                                                                                         |
| 14  | GND               | Ground (0V)                                                                                                                                                                                                         |
| 15  | Ethernet_nLED3    | Active-low Ethernet activity indicator (CM4_3.3V signal): typically a green LED is connected to this pin. IOL = 8mA @ VOL < 0.4V |
| 16  | Ethernet_SYNC_IN  | IEEE1588 SYNC Input pin (CM4_3.3V signal: IOL = 8mA @ VOL < 0.4V)                                                                                                                                                   |
| 17  | Ethernet_nLED2    | Active-low Ethernet speed indicator (`CM4_3.3V`signal): typically a yellow LED is connected to this pin. A low state indicates the 1Gbit or 100Mbit link: IOL = 8mA @ VOL < 0.4V                                    |
| 18  | Ethernet_SYNC_OUT | IEEE1588 SYNC Output pin (CM4_3.3V signal: IOL = 8mA @ VOL < 0.4V)                                                                                                                                                  |
| 19  | Ethernet_nLED1    | Active-low Ethernet speed indicator (CM4_3.3V signal): typically a yellow LED is connected to this pin. A low state indicates the 1Gbit or 10Mbit link: IOL = 8mA @ VOL < 0.4V                                      |
| 20  | EEPROM_nWP        | Leave floating NB internally pulled up to CM4_3.3V via 100kΩ (VIL < 0.8V), but can be grounded to prevent writing to the on-board EEPROM which stores the bootcode                                                  |
| 21  | Pi_nLED_Activity  | Active-low Pi activity LED. 20mA Max, 5V tolerant (VOL < 0.4V). (this is the signal that drives the green LED on the Raspberry Pi 4 Model B)                                                                        |
| 22  | GND               | Ground (0V)                                                                                                                                                                                                         |
| 23  | GND               | Ground (0V)                                                                                                                                                                                                         |
| 24  | GPIO26            | GPIO: typically a 3.3V signal, but can be a 1.8V signal by connecting GPIO_VREF to CM4_1.8V                                                                                                                         |
| 25  | GPIO21            | GPIO: typically a 3.3V signal, but can be a 1.8V signal by connecting GPIO_VREF to CM4_1.8V                                                                                                                         |
| 26  | GPIO19            | GPIO: typically a 3.3V signal, but can be a 1.8V signal by connecting GPIO_VREF to CM4_1.8V                                                                                                                         |
| 27  | GPIO20            | GPIO: typically a 3.3V signal, but can be a 1.8V signal by connecting GPIO_VREF to CM4_1.8V                                                                                                                         |
