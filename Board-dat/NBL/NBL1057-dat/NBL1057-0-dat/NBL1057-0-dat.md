

## NBL1057-0-dat

### Version Old 1

![](2023-10-27-14-56-16.png)

- R2 version add software and hardware master/slave mode select,
- default is software on.
- To use hardware select, need cut off connection on software ON with middle pin first.


### Backside Jumper Setup Mode:

![](2023-10-19-13-23-35.png)

Bottom jumper set hardware / software method for slave / master mode, Default setup for hardware method.

| Jumper | Function         | Mode                      | Default |
| ------ | ---------------- | ------------------------- | ------- |
| SJ2    | master / slave   | hardware control M/S mode |
| SJ1    | soft / hard Mode | control mode select       | Hard    |

- Top jumper set for slave / master mode.
- If you prefer to use software method by AT commands to change slave / mater mode, cut the bottom jumper connection (GND - middle pin), then re-connect to top by solder (VCC-middle pin).




### base version 

![](2023-10-20-17-05-57.png)

![](2023-10-23-15-06-05.png)
