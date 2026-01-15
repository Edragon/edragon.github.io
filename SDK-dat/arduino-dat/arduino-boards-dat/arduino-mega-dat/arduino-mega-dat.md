# arduino-mega-dat

- [[arduino-uno-dat]]


## dev board 

- [[DARS017-dat]] 

- [[DARS013-dat]]

## MISC board 

- [[DAS1004-dat]] - [[DAS1065-dat]]

- [[DAS1063-dat]]


## APP board 

- [[SDRS045-dat]] - [[reprap-dat]] 

- [[EDL-LCD-dat]]


## pintout template 


| Pin Number | Pin Label |   | Type                    | Functions / Notes                                    |
|------------|-----------|---|-------------------------|------------------------------------------------------|
| 0          | RX0       |   | Digital                 | UART0 RX (Serial)                                    |
| 1          | TX0       |   | Digital                 | UART0 TX (Serial)                                    |
| 2          | D2        |   | Digital                 | External Interrupt 4 (INT4)                          |
| 3          | ~D3       |   | Digital (PWM)           | PWM (OC3C), External Interrupt 5 (INT5)              |
| 4          | D4        |   | Digital                 | PWM (OC0B)                                           |
| 5          | ~D5       |   | Digital (PWM)           | PWM (OC3A)                                           |
| 6          | ~D6       |   | Digital (PWM)           | PWM (OC4A)                                           |
| 7          | D7        |   | Digital                 | PWM (OC4B)                                           |
| 8          | D8        |   | Digital                 | PWM (OC4C)                                           |
| 9          | ~D9       |   | Digital (PWM)           | PWM (OC2B)                                           |
| 10         | ~D10      |   | Digital (PWM, SPI SS)   | PWM (OC2A); SPI SS (hardware)                        |
| 11         | ~D11      |   | Digital (PWM, SPI MOSI) | PWM (OC1A); SPI MOSI                                 |
| 12         | D12       |   | Digital (SPI MISO)      | SPI MISO                                             |
| 13         | D13       |   | Digital (LED, SPI SCK)  | Built-in LED; SPI SCK                                |
| 14         | TX3       |   | Digital                 | UART3 TX                                             |
| 15         | RX3       |   | Digital                 | UART3 RX                                             |
| 16         | TX2       |   | Digital                 | UART2 TX                                             |
| 17         | RX2       |   | Digital                 | UART2 RX                                             |
| 18         | TX1       |   | Digital                 | UART1 TX                                             |
| 19         | RX1       |   | Digital                 | UART1 RX                                             |
| 20         | SDA       |   | Digital (I2C SDA)       | I2C SDA                                              |
| 21         | SCL       |   | Digital (I2C SCL)       | I2C SCL                                              |
| 22         | D22       |   | Digital                 | General purpose                                      |
| 23         | D23       |   | Digital                 | General purpose                                      |
| 24         | D24       |   | Digital                 | General purpose                                      |
| 25         | D25       |   | Digital                 | General purpose                                      |
| 26         | D26       |   | Digital                 | General purpose                                      |
| 27         | D27       |   | Digital                 | General purpose                                      |
| 28         | D28       |   | Digital                 | General purpose                                      |
| 29         | D29       |   | Digital                 | General purpose                                      |
| 30         | D30       |   | Digital                 | General purpose                                      |
| 31         | D31       |   | Digital                 | General purpose                                      |
| 32         | D32       |   | Digital                 | General purpose                                      |
| 33         | D33       |   | Digital                 | General purpose                                      |
| 34         | D34       |   | Digital                 | General purpose                                      |
| 35         | D35       |   | Digital                 | General purpose                                      |
| 36         | D36       |   | Digital                 | General purpose                                      |
| 37         | D37       |   | Digital                 | General purpose                                      |
| 38         | D38       |   | Digital                 | General purpose                                      |
| 39         | D39       |   | Digital                 | General purpose                                      |
| 40         | D40       |   | Digital                 | General purpose                                      |
| 41         | D41       |   | Digital                 | General purpose                                      |
| 42         | D42       |   | Digital                 | General purpose                                      |
| 43         | D43       |   | Digital                 | General purpose                                      |
| 44         | D44       |   | Digital                 | PWM (OC5C)                                           |
| 45         | D45       |   | Digital                 | PWM (OC5B)                                           |
| 46         | D46       |   | Digital                 | PWM (OC5A)                                           |
| 47         | D47       |   | Digital                 | General purpose                                      |
| 48         | D48       |   | Digital                 | General purpose                                      |
| 49         | D49       |   | Digital                 | General purpose                                      |
| 50         | MISO      |   | Digital (SPI MISO)      | SPI MISO (duplicate of D12)                          |
| 51         | MOSI      |   | Digital (SPI MOSI)      | SPI MOSI (duplicate of D11)                          |
| 52         | SCK       |   | Digital (SPI SCK)       | SPI SCK (duplicate of D13)                           |
| 53         | SS        |   | Digital (SPI SS)        | SPI SS (duplicate of D10)                            |
| A0 (54)    | A0        |   | Analog / Digital        | ADC0; digital (D54)                                  |
| A1 (55)    | A1        |   | Analog / Digital        | ADC1; digital (D55)                                  |
| A2 (56)    | A2        |   | Analog / Digital        | ADC2; digital (D56)                                  |
| A3 (57)    | A3        |   | Analog / Digital        | ADC3; digital (D57)                                  |
| A4 (58)    | A4        |   | Analog / Digital        | ADC4; digital (D58)                                  |
| A5 (59)    | A5        |   | Analog / Digital        | ADC5; digital (D59)                                  |
| A6 (60)    | A6        |   | Analog / Digital        | ADC6; digital (D60)                                  |
| A7 (61)    | A7        |   | Analog / Digital        | ADC7; digital (D61)                                  |
| A8 (62)    | A8        |   | Analog / Digital        | ADC8; digital (D62)                                  |
| A9 (63)    | A9        |   | Analog / Digital        | ADC9; digital (D63)                                  |
| A10 (64)   | A10       |   | Analog / Digital        | ADC10; digital (D64)                                 |
| A11 (65)   | A11       |   | Analog / Digital        | ADC11; digital (D65)                                 |
| A12 (66)   | A12       |   | Analog / Digital        | ADC12; digital (D66)                                 |
| A13 (67)   | A13       |   | Analog / Digital        | ADC13; digital (D67)                                 |
| A14 (68)   | A14       |   | Analog / Digital        | ADC14; digital (D68)                                 |
| A15 (69)   | A15       |   | Analog / Digital        | ADC15; digital (D69)                                 |
| -          | VIN       |   | Power                   | Input to onboard regulator (7-12V recommended)       |
| -          | 5V        |   | Power                   | Regulated 5V output (or USB input)                   |
| -          | 3.3V      |   | Power                   | 3.3V regulator output                                |
| -          | GND       |   | Power                   | Ground pins (multiple)                               |
| -          | IOREF     |   | Power / Reference       | Provides reference voltage for shields (5V on Mega)  |
| -          | RESET     |   | Control                 | Active-low reset input                               |
| -          | AREF      |   | Reference               | External analog reference for ADC                    |
| -          | ICSP      |   | SPI header              | MOSI, MISO, SCK for programming / SPI (6-pin header) |



## pin out table

Below is a comprehensive reference table for the Arduino Mega 2560 (ATmega2560-based) pins and common functions.

| Pin Number | Pin Label | Type                    | Functions / Notes                                    |
| ---------- | --------- | ----------------------- | ---------------------------------------------------- |
| 0          | RX0       | Digital                 | UART0 RX (Serial)                                    |
| 1          | TX0       | Digital                 | UART0 TX (Serial)                                    |
| 2          | D2        | Digital                 | External Interrupt 4 (INT4)                          |
| 3          | ~D3       | Digital (PWM)           | PWM (OC3C), External Interrupt 5 (INT5)              |
| 4          | D4        | Digital                 | PWM (OC0B)                                           |
| 5          | ~D5       | Digital (PWM)           | PWM (OC3A)                                           |
| 6          | ~D6       | Digital (PWM)           | PWM (OC4A)                                           |
| 7          | D7        | Digital                 | PWM (OC4B)                                           |
| 8          | D8        | Digital                 | PWM (OC4C)                                           |
| 9          | ~D9       | Digital (PWM)           | PWM (OC2B)                                           |
| 10         | ~D10      | Digital (PWM, SPI SS)   | PWM (OC2A); SPI SS (hardware)                        |
| 11         | ~D11      | Digital (PWM, SPI MOSI) | PWM (OC1A); SPI MOSI                                 |
| 12         | D12       | Digital (SPI MISO)      | SPI MISO                                             |
| 13         | D13       | Digital (LED, SPI SCK)  | Built-in LED; SPI SCK                                |
| 14         | TX3       | Digital                 | UART3 TX                                             |
| 15         | RX3       | Digital                 | UART3 RX                                             |
| 16         | TX2       | Digital                 | UART2 TX                                             |
| 17         | RX2       | Digital                 | UART2 RX                                             |
| 18         | TX1       | Digital                 | UART1 TX                                             |
| 19         | RX1       | Digital                 | UART1 RX                                             |
| 20         | SDA       | Digital (I2C SDA)       | I2C SDA                                              |
| 21         | SCL       | Digital (I2C SCL)       | I2C SCL                                              |
| 22         | D22       | Digital                 | General purpose                                      |
| 23         | D23       | Digital                 | General purpose                                      |
| 24         | D24       | Digital                 | General purpose                                      |
| 25         | D25       | Digital                 | General purpose                                      |
| 26         | D26       | Digital                 | General purpose                                      |
| 27         | D27       | Digital                 | General purpose                                      |
| 28         | D28       | Digital                 | General purpose                                      |
| 29         | D29       | Digital                 | General purpose                                      |
| 30         | D30       | Digital                 | General purpose                                      |
| 31         | D31       | Digital                 | General purpose                                      |
| 32         | D32       | Digital                 | General purpose                                      |
| 33         | D33       | Digital                 | General purpose                                      |
| 34         | D34       | Digital                 | General purpose                                      |
| 35         | D35       | Digital                 | General purpose                                      |
| 36         | D36       | Digital                 | General purpose                                      |
| 37         | D37       | Digital                 | General purpose                                      |
| 38         | D38       | Digital                 | General purpose                                      |
| 39         | D39       | Digital                 | General purpose                                      |
| 40         | D40       | Digital                 | General purpose                                      |
| 41         | D41       | Digital                 | General purpose                                      |
| 42         | D42       | Digital                 | General purpose                                      |
| 43         | D43       | Digital                 | General purpose                                      |
| 44         | D44       | Digital                 | PWM (OC5C)                                           |
| 45         | D45       | Digital                 | PWM (OC5B)                                           |
| 46         | D46       | Digital                 | PWM (OC5A)                                           |
| 47         | D47       | Digital                 | General purpose                                      |
| 48         | D48       | Digital                 | General purpose                                      |
| 49         | D49       | Digital                 | General purpose                                      |
| 50         | MISO      | Digital (SPI MISO)      | SPI MISO (duplicate of D12)                          |
| 51         | MOSI      | Digital (SPI MOSI)      | SPI MOSI (duplicate of D11)                          |
| 52         | SCK       | Digital (SPI SCK)       | SPI SCK (duplicate of D13)                           |
| 53         | SS        | Digital (SPI SS)        | SPI SS (duplicate of D10)                            |
| A0 (54)    | A0        | Analog / Digital        | ADC0; digital (D54)                                  |
| A1 (55)    | A1        | Analog / Digital        | ADC1; digital (D55)                                  |
| A2 (56)    | A2        | Analog / Digital        | ADC2; digital (D56)                                  |
| A3 (57)    | A3        | Analog / Digital        | ADC3; digital (D57)                                  |
| A4 (58)    | A4        | Analog / Digital        | ADC4; digital (D58)                                  |
| A5 (59)    | A5        | Analog / Digital        | ADC5; digital (D59)                                  |
| A6 (60)    | A6        | Analog / Digital        | ADC6; digital (D60)                                  |
| A7 (61)    | A7        | Analog / Digital        | ADC7; digital (D61)                                  |
| A8 (62)    | A8        | Analog / Digital        | ADC8; digital (D62)                                  |
| A9 (63)    | A9        | Analog / Digital        | ADC9; digital (D63)                                  |
| A10 (64)   | A10       | Analog / Digital        | ADC10; digital (D64)                                 |
| A11 (65)   | A11       | Analog / Digital        | ADC11; digital (D65)                                 |
| A12 (66)   | A12       | Analog / Digital        | ADC12; digital (D66)                                 |
| A13 (67)   | A13       | Analog / Digital        | ADC13; digital (D67)                                 |
| A14 (68)   | A14       | Analog / Digital        | ADC14; digital (D68)                                 |
| A15 (69)   | A15       | Analog / Digital        | ADC15; digital (D69)                                 |
| -          | VIN       | Power                   | Input to onboard regulator (7-12V recommended)       |
| -          | 5V        | Power                   | Regulated 5V output (or USB input)                   |
| -          | 3.3V      | Power                   | 3.3V regulator output                                |
| -          | GND       | Power                   | Ground pins (multiple)                               |
| -          | IOREF     | Power / Reference       | Provides reference voltage for shields (5V on Mega)  |
| -          | RESET     | Control                 | Active-low reset input                               |
| -          | AREF      | Reference               | External analog reference for ADC                    |
| -          | ICSP      | SPI header              | MOSI, MISO, SCK for programming / SPI (6-pin header) |

Notes:
- PWM pins: ~2-13, ~44-46 (marked with ~ on board silkscreen).
- UARTs: Serial (0: pins 0/1), Serial1 (1: 18/19), Serial2 (2: 16/17), Serial3 (3: 14/15).
- SPI pins: D50-53 are duplicates of D12, D11, D13, D10 respectively.
- I2C: SDA = D20, SCL = D21.
- Digital pins can be used as inputs or outputs; analog pins can also be used as digital pins when referenced by number (A0 = 54, ... A15 = 69).
- External interrupts: INT0 (D2), INT1 (D3), INT2 (D21), INT3 (D20), INT4 (D19), INT5 (D18).


## ref 

- [[arduino-boards-dat]]