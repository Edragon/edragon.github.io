
# DAR1047-dat


[ATTiny85 Mini Dev. Board. Lilytiny, Digispark, EDAtiny](https://www.electrodragon.com/product/attiny85-mini-dev-board-lilytiny-digispark-edatiny/)

![](2024-02-28-17-43-30.png)

- use guide please see here [[VUSB-dat]]






## Note 

* The board won't be regonized BUT it is OK. No problem for uploading sketch


## For developer only

### Burning bootloader

Firmware - https://github.com/micronucleus/micronucleus/releases

* Use firmware - > release -> attiny85 aggressive.hex

* Our board already burned bootloader, use this only when things corrupted.
* Git clone bootloader project from here: https://github.com/Edragon/micronucleus, or download it from here [[Micronucleus-2.01.zip]] - [download it from here](Micronucleus-2.01.zip)

#### fuse setup
* High fuse DD
* Low fuse E1
* extend fuse FE. 



## demo 

https://www.youtube.com/shorts/ePX9KjBYBIk


## ref 

- [[DAR1047]]

- [[attiny-dat]]

- Compatible with Digispark lilytiny, etc board, can use open source project [micronucleus](https://github.com/micronucleus/micronucleus)
- https://www.electrodragon.com/w/EDAtiny