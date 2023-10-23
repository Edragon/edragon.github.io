
# HC05-dat 

![](2023-10-23-15-05-01.png)

## Enter the AT command.

1: Before powering on the module (or at the same time), set the KEY pin to high level (or connect it to VCC), and then power on the module. At this time, the LED flashes slowly (once every 2 seconds), the module enters the AT state, and the baud rate is fixed at 38400.

2: When the module is powered on, set the KEY pin to low level (or connect it to GND). At this time, the LED flashes quickly (twice in 1S), and then set the KEY pin to high level (or connect it to VCC). The module will also enter the AT command, but the LED will still flash quickly. At this time, the baud rate is the default baud rate of 9600.

