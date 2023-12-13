# DPR1045-dat

- https://www.electrodragon.com/product/attiny-1385-programming-shield/

## Using Guide

Flash Bootloader Programming Guide and Note

- Support three attiny series
- Some version of ArduinoIDE is not working well, for example, 1.61, 1.00, etc, better version approved 1.05, 1.56-r2
- Burn bootloader twice, sometimes it seems the arduinoIDE bug: the IC will fail on uploading sketch when moved to arduino board

- If you see the problem "programmer of out sync", get the easy solution here. [[arduinoISP-dat]]
- Find all the unofficial attiny board files here. [[attiny-dat]]

* upload arduino sketch using "programmer" options in the menu, DO NOT use "upload" button
  ![](2023-12-13-14-38-35.png)

* Program hex file into target IC with AVRDUDESS
  ![](2023-12-13-14-39-13.png)

