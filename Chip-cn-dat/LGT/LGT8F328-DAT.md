# LGT8F328 DAT

- [legacy wiki page](https://www.electrodragon.com/w/Logicgreen)


## comparison to arduino atmega328

| pin   | LGT     | arduino | note      |
| ----- | ------- | ------- | --------- |
| pin3  | PE4     | GND     | extra pin |
| pin6  | PE5     | VCC     | extra pin |
| pin18 | PE0/SWC | AVCC    | prog port |
| pin21 | PE2/SWD | GND     | prog port |

common pin 
- pin 4 = VCC
- pin 5 = GND

![](58-57-15-14-02-2023.png)

## Sketch uploads By Arduino IDE
- Pre-loaded bootloder. Just select corresponding board to upload sketch, refer to bootloader sketch below
- Programming pin port same as FTDI [[FT232-dat]], same as arduino pro mini
- A backup method for without DTR, just hold down RESET button when "compiling", then release when "uploading".



## bootloader

### nullab board 

- most compatible, please use this one
- Nullab Nano/ Maker Nano
- install by this - https://nulllab.coding.net/p/lgt/d/nulllab_lgt_arduino/git/raw/master/package_nulllab_boards_index_zh.json


### old 1

https://github.com/LGTMCU/Larduino_HSP
Installation:

- Unzip master.zip
- Copy the [hardware] directory to Arduino's sketchbook directory (see below to find out where it normally resides)
- Restart Arduino, you will see new board from [Tools]->[Board] menu.

### old 2 bootloader

- Better not used for experiment, your often daily programming learning or testing, although no problem, but if unexpected error cause the board bricked, you need special programmer to re-programme the bootloader.
- Good to migrate to a low cost board instead of original expensive board.
- Same way to upload sketch as pro mini, notice to choose the board
  - 8F328P - original IC bootloader, please use this one
  - 8F328D - compatible, can also upload code, but don't know if any unknow error.
  - Pro mini - also can upload, but active very wired


## Chip Note 

- crystal is not soldered, it can work without crystal, unlike [[atmega328]]

## Programmer

- arduino UNO can pretend as a chip programmer
- please contact us if you need to order original programmer

## demo 

https://www.youtube.com/shorts/CL2-iH4KWQQ


## ref

- [[LGT8F328]]
