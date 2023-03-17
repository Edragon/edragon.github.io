
# LGT8F328 DAT

## chip features

- can work without crystal 

- [[LGT8F328]]



## differences 

| pin   | LGT     | ARD |
| ----- | ------- | - |
| pin3  | PE4     | GND | 
| pin6  | PE5     | VCC |
| pin18 | PE0/SWC | AVCC |
| pin21 | PE2/SWD | GND | 

comm 
- pin 4 / pin 5


![](58-57-15-14-02-2023.png)



## bootloader

### nullab 

- Nullab Nano/ Maker Nano 
- https://nulllab.coding.net/p/lgt/d/nulllab_lgt_arduino/git/raw/master/package_nulllab_boards_index_zh.json



### old 
https://github.com/LGTMCU/Larduino_HSP
Installation:
- Unzip master.zip
- Copy the [hardware] directory to Arduino's sketchbook directory (see below to find out where it normally resides)
- Restart Arduino, you will see new board from [Tools]->[Board] menu.