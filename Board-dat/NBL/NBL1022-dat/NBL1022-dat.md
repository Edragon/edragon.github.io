# NBL1022-dat

- [legacy wiki page](https://w.electrodragon.com/w/Category:BC-04)

https://www.electrodragon.com/product/lc-05-bluetooth-serial-moduel-masterslave-in-one/

## Features:

- BQB certificated
- Master / Slave Mode supported
- classic bluetooth easy to use

## SCH

![](2023-10-20-17-05-57.png)

![](2023-10-23-15-06-05.png)

## Base Board Pin Definitions

![](2023-10-19-13-27-25.png)

from left to right from front side

- GND
- +5V
- 3V3
- TXD
- RXD
- Clear - clear the pairing status

## Backside Jumper Setup Mode:

![](2023-10-19-13-23-35.png)

Bottom jumper set hardware / software method for slave / master mode, Default setup for hardware method.

| Jumper | Function         | Mode                      | Default |
| ------ | ---------------- | ------------------------- | ------- |
| SJ2    | master / slave   | hardware control M/S mode |
| SJ1    | soft / hard Mode | control mode select       | Hard    |

- Top jumper set for slave / master mode.
- If you prefer to use software method by AT commands to change slave / mater mode, cut the bottom jumper connection (GND - middle pin), then re-connect to top by solder (VCC-middle pin).

## Note

Wiring

- Board RXD -> target RXD, board TXD -> target TXD

Mode

- Be aware default setting of the product is slave mode, communication only available between master and slave mode, but not master and master, or slave and slave mode.

## Demo Video

- [Please see here.](https://www.youtube.com/watch?v=CmMGhHMciu8)

## Compare

![](2023-10-19-13-52-14.png)

| func                               | BC04—B         | HC—05            | HC—06          |
| ---------------------------------- | -------------- | ---------------- | -------------- |
| 1. Software master-slave setting   | ✔              | ✔                | ✔              |
| 2． Hardware master-slave settings | ✔              | X                | X              |
| 3． Ultra-low power consumption    | 2 ~ 10mA       | 30 ~ 40mA        | 30 ~ 40mA      |
| 4. Intelligent AT command system   | ✔              | X                | X              |
| 5． Normal AT set                  | ✔              | ✔                | ✔              |
| 6. Support help command            | ✔              | X                | X              |
| 7． Product Grade                  | Military Grade | Industrial Grade | Civilian Grade |
| 8． Support software development   | ✔              | X                | X              |
| 9. Support uplink command          | ✔              | X                | X              |

## ref

- based on module - [[NBL1018-dat]] - [[NBL1022-dat]] - [[NBL1057-dat]]

simialr modules - [[BC04-B-dat]] - [[HC05-dat]] - [[HC06-dat]] - [[NBL1012-dat]]

- [[NBL1022]]