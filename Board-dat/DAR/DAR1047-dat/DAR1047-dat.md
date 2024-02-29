
# DAR1047-dat

- https://www.electrodragon.com/product/attiny85-mini-dev-board-lilytiny-digispark-edatiny/

![](2024-02-28-17-43-30.png)





## ref 

- Compatible with Digispark lilytiny, etc board, can use open source project [micronucleus](https://github.com/micronucleus/micronucleus)
- https://www.electrodragon.com/w/EDAtiny

## debug 

* During upload sketch in you encounter any error, update the board driver to lisusb-win32 by [[AVR]]

* Blink - On board test LED is D1, please try pinMode(1, OUTPUT);



## resources 

check the use guide video here: https://www.youtube.com/shorts/ePX9KjBYBIk

- 1. install driver here [[Digistump.Drivers.zip]]
- 2. install the board: http://digistump.com/package_digistump_index.json


## Deep Part 

### Burning bootloader

Firmware - https://github.com/micronucleus/micronucleus/releases

* Use firmware - > release -> attiny85 aggressive.hex

* Our board already burned bootloader, use this only when things corrupted.
* Git clone bootloader project from here: https://github.com/Edragon/micronucleus, or [[File:Micronucleus-2.01.zip|download it from here]] - [download it from here](File:Micronucleus-2.01.zip)

* High fuse DD, Low fuse E1, extend fuse FE. 