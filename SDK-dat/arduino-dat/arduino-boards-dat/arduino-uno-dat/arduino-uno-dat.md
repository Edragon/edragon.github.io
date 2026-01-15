# arduino-uno-dat

https://docs.arduino.cc/hardware/uno-rev3


## pin definitions 

![](2025-11-15-17-20-20.png)


![](2024-03-26-16-17-03.png)

## pin table

Below is a comprehensive reference table for the Arduino Uno (Uno R3 / ATmega328P-based) pins and common functions.

| Pin Number | Pin Label | Type                    | Functions / Notes                                    |
| ---------- | --------- | ----------------------- | ---------------------------------------------------- |
| 0          | RX        | Digital                 | UART RX (Serial)                                     |
| 1          | TX        | Digital                 | UART TX (Serial)                                     |
| 2          | D2        | Digital                 | External Interrupt 0 (INT0)                          |
| 3          | ~D3       | Digital (PWM)           | PWM (OC2B), External Interrupt 1 (INT1)              |
| 4          | D4        | Digital                 | General purpose                                      |
| 5          | ~D5       | Digital (PWM)           | PWM (OC0B)                                           |
| 6          | ~D6       | Digital (PWM)           | PWM (OC0A)                                           |
| 7          | D7        | Digital                 | General purpose                                      |
| 8          | D8        | Digital                 | General purpose                                      |
| 9          | ~D9       | Digital (PWM)           | PWM (OC1A)                                           |
| 10         | ~D10      | Digital (PWM, SPI SS)   | PWM (OC1B); SPI SS (hardware)                        |
| 11         | ~D11      | Digital (PWM, SPI MOSI) | PWM (OC2A); SPI MOSI                                 |
| 12         | D12       | Digital (SPI MISO)      | SPI MISO                                             |
| 13         | D13       | Digital (LED, SPI SCK)  | Built-in LED; SPI SCK                                |
| A0 (14)    | A0        | Analog / Digital        | ADC0; can be used as digital (D14)                   |
| A1 (15)    | A1        | Analog / Digital        | ADC1; digital (D15)                                  |
| A2 (16)    | A2        | Analog / Digital        | ADC2; digital (D16)                                  |
| A3 (17)    | A3        | Analog / Digital        | ADC3; digital (D17)                                  |
| A4 (18)    | A4        | Analog / I2C (SDA)      | ADC4; I2C SDA (also digital D18 on some mappings)    |
| A5 (19)    | A5        | Analog / I2C (SCL)      | ADC5; I2C SCL (also digital D19 on some mappings)    |
| -          | VIN       | Power                   | Input to onboard regulator (7-12V recommended)       |
| -          | 5V        | Power                   | Regulated 5V output (or USB input)                   |
| -          | 3.3V      | Power                   | 3.3V regulator output on some boards                 |
| -          | GND       | Power                   | Ground pins (multiple)                               |
| -          | IOREF     | Power / Reference       | Provides reference voltage for shields (5V on Uno)   |
| -          | RESET     | Control                 | Active-low reset input                               |
| -          | AREF      | Reference               | External analog reference for ADC                    |
| -          | ICSP      | SPI header              | MOSI, MISO, SCK for programming / SPI (6-pin header) |

Notes:
- PWM pins: ~3, ~5, ~6, ~9, ~10, ~11 (marked with ~ on board silkscreen).
- SPI pins: D11 = MOSI, D12 = MISO, D13 = SCK; D10 typically used as SS for SPI slave select.
- I2C: SDA = A4, SCL = A5. Uno R3 also exposes dedicated SDA / SCL pins near AREF.
- Digital pins can be used as inputs or outputs; analog pins can also be used as digital pins when referenced by number (A0 = 14, ... A5 = 19).



## ref 

- datasheet - https://docs.arduino.cc/resources/datasheets/A000066-datasheet.pdf
- SCH - https://docs.arduino.cc/resources/schematics/A000066-schematics.pdf



## ref 

- [[avr-sdk-dat]]

- [[arduino-dat]]


## ref 

- [[atmega328-dat]]
