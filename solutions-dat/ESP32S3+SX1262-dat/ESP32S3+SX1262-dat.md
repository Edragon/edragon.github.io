
# ESP32S3+SX1262-dat

- [[ADC-dat]] - [[battery-charger-dat]]

- [[CP2102-dat]]

- [[OLED-dat]]

- [[ESP32-S3-dat]] - [[SX1262-dat]]

- [[LDO-dat]]

## Pin Definitions 

| Pin # | Pin Name   | Functions (Typical)    | Note.  |
| ----- | ---------- | ---------------------- | ------ |
| 1     | LNA_IN     | RF Input (Antenna)     | x      |
| 2     | VDD3P3     | 3.3V Power Supply      | x      |
| 3     | VDD3P3     | 3.3V Power Supply      | x      |
| 4     | CHIP_PU    | EN                     | boot   |
| 5     | GPIO0      | GPIO, Boot, ADC, Touch | boot   |
| 6     | GPIO1      | GPIO, ADC, Touch       | ADC    |
| 7     | GPIO2      | GPIO, ADC, Touch       |        |
| 8     | GPIO3      | GPIO, ADC, Touch       |        |
| 9     | GPIO4      | GPIO, ADC, Touch       |        |
| 10    | GPIO5      | GPIO, ADC, Touch       |        |
| 11    | GPIO6      | GPIO, ADC, Touch       |        |
| 12    | GPIO7      | GPIO, ADC, Touch       |        |
| 13    | GPIO8      | GPIO, ADC, Touch       | LORA   |
| 14    | GPIO9      | GPIO, ADC, Touch       | LORA   |
| 15    | GPIO10     | GPIO, ADC, Touch       | LORA   |
| 16    | GPIO11     | GPIO, ADC, Touch       | LORA   |
| 17    | GPIO12     | GPIO, ADC, Touch       | LORA   |
| 18    | GPIO13     | GPIO, ADC, Touch       | LORA   |
| 19    | GPIO14     | GPIO, ADC, Touch       | LORA   |
| 20    | VDD3P3_RTC | 3.3V RTC Power Supply  | x      |
| 21    | XTAL_32K_P | 32.768kHz              | 32K    |
| 22    | XTAL_32K_N | 32.768kHz              | 32K    |
| 23    | GPIO17     | GPIO, ADC, Touch       | OLED   |
| 24    | GPIO18     | GPIO, ADC, Touch       | OLED   |
| 25    | GPIO19     | GPIO, ADC, Touch       |        |
| 26    | GPIO20     | GPIO, ADC, Touch       |        |
| 27    | GPIO21     | GPIO, ADC, Touch       | OLED   |
| 28    | SPICS1     | SPI Chip Select 1      |        |
| 29    | VDD_SPI    | 3.3V SPI Power Supply  | x      |
| 30    | SPIHD      | SPI HD                 | x      |
| 31    | SPIWP      | SPI WP                 | x      |
| 32    | SPICS0     | SPI Chip Select 0      | x      |
| 33    | SPICLK     | SPI Clock              | x      |
| 34    | SPIQ       | SPI Q                  | x      |
| 35    | SPID       | SPI D                  | x      |
| 36    | SPICLK_N   | SPI Clock Negative     |        |
| 37    | SPICLK_P   | SPI Clock Positive     |        |
| 38    | GPIO33     | GPIO                   |        |
| 39    | GPIO34     | GPIO                   |        |
| 40    | GPIO35     | GPIO                   | button |
| 41    | GPIO36     | GPIO                   | ADC    |
| 42    | GPIO37     | GPIO                   | ADC    |
| 43    | GPIO38     | GPIO                   |        |
| 44    | MTCK       | JTAG Clock, GPIO       |        |
| 45    | MTDO       | JTAG Data Out, GPIO    |        |
| 46    | VDD3P3_CPU | 3.3V CPU Power Supply  | x      |
| 47    | MTMS       | JTAG Mode Select, GPIO |        |
| 48    | MTDI       | JTAG Data In, GPIO     |        |
| 49    | U0TXD      | UART0 TX, GPIO         | UART0  |
| 50    | U0RXD      | UART0 RX, GPIO         | UART0  |
| 51    | GPIO45     | GPIO                   |        |
| 52    | GPIO46     | GPIO                   |        |
| 53    | XTAL_N     | Crystal_N              | XTAL   |
| 54    | XTAL_P     | Crystal_P              | XTAL   |
| 55    | VDDA       | Analog_PWR             | x      |
| 56    | VDDA       | Analog_PWR             | x      |
| 57    | GND        | Ground                 | x      |



## ref 

- [[HTIT-WB32LA(F)_V3.1_Schematic_Diagram.pdf]]