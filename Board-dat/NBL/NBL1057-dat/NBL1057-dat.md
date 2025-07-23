# NBL1057-dat

## Jumper pin setup 

- Default setup for BC-04B

| Jumper | BC-04B                    | EC-04B                    | HC-05           | HC-06           |
| ------ | ------------------------- | ------------------------- | --------------- | --------------- |
| JP1    | BC                        | BC                        | HC              | HC              |
| JP2    | -                         | -                         | state or status * | state or status * |
| JP3    | BC                        | BC                        | HC              | HC              |
| JP4    | hardware Master or slave  | hardware Master or slave  | -               | -               |
| JP5    | hardware or software mode | hardware or software mode | -               | -               |

- JP1 ~ JP3: core module type setup 
- JP5 = HA + JP4 = MA: set module by hardware to master 
- JP5 = HA + JP4 = SL: set module by hardware to slave
- JP5 = SO + JP4 = *any*: set module by software 
- state or status: pair state or AT commands status


## Base Board Pin Definitions

![](2023-10-19-13-27-25.png)

from left to right from front side

- GND
- +5V
- 3V3
- TXD
- RXD
- Clear - clear the pairing status


## SCH

### Version New 2
* add extra two functions pad pins 

![](2023-10-27-15-17-54.png)

![](2023-10-27-15-14-19.png)




## Wiring

- Board RXD -> target RXD, board TXD -> target TXD

## Mode

- Be aware default setting of the product is slave mode, communication only available between master and slave mode, but not master and master, or slave and slave mode.


## ref

for old version, and basic schematic please read at [[NBL1057-0-dat]]

- based on module - [[NBL1018-dat]] - [[NBL1022-dat]] - [[NBL1057-dat]]

- simialr modules - [[BC04-B-dat]] - [[HC05-dat]] - [[HC06-dat]] - [[NBL1012-dat]]
