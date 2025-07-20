# DPR1045-dat

[ATtiny Series 13 85 2313 Programming Shield](https://www.electrodragon.com/product/attiny-1385-programming-shield/)

- attiny chip order [[6001274-dat]] 


- [legacy wiki page - arduino](https://w.electrodragon.com/w/Category:Arduino)

- [[attiny13-dat]] - [[attiny85-dat]] - [[attiny2313-dat]]

- [[arduino-programmer-dat]]

## pin deifinitions 

| target pin | interface | arduino shield pin     |
| ---------- | --------- | ---------------------- |
| PB5        | RST       | *D10                   |
| PB4        |           | ~side D4               |
| PB3        |           | ~side D3, on-board LED |
| PB2        | SCK       | *D13                   |
| PB1        | MISO      | *D12                   |
| PB0        | MOSI      | *D11                   |

\* for programming pin \~ for lead out pin



## Board Map 

![](2023-12-13-14-49-25.png)

- test LED = PB3
- PB5 ~ PB0 = D5-D0, 6 functional pins of the SOP-8 chip
  - e.g PB3 = D3, PB5 = D5
  - digitalWrite(3, HIGH);
- VCC / GND

## soldeing by yourself 

![](2025-06-30-18-03-06.png)


## Using Guide

Flash Bootloader Programming Guide and Note

- Support three attiny series
- Some version of ArduinoIDE is not working well, for example, 1.61, 1.00, etc, better version approved 1.05, 1.56-r2
- Burn bootloader twice, sometimes it seems the arduinoIDE bug: the IC will fail on uploading sketch when moved to arduino board

- If you see the problem "programmer of out sync", get the easy solution here. [[arduino-as-ISP-dat]]
- Find all the unofficial attiny board files here. [[attiny-dat]]

setup 

![](2025-06-30-18-13-12.png)

upload arduino sketch using "upload using programmer" options in the menu, DO NOT use "upload" button

![](2023-12-13-14-38-35.png)

- mess uploading by [[AVRDUDE-dat]]


## Demo with using Guide

- [please see here. ](https://www.youtube.com/watch?v=6SlruQVLcK4)

blink PB3 == 3 

  void setup() {
    // initialize digital pin LED_BUILTIN as an output.
    pinMode(3, OUTPUT);
  }

  // the loop function runs over and over again forever
  void loop() {
    digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
    digitalWrite(3, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);                       // wait for a second
  }

![](2025-06-30-18-16-32.png)

## ref 

- [[arduino-as-ISP-dat]]
- [[attiny-dat]]