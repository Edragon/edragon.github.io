
# MPC1108-dat

https://www.electrodragon.com/product/smart-fan-cooling-control-board-for-raspberry-pi/



![](2025-08-07-19-07-16.png)

- left-top RED SPDT witch == ON/OFF 12V power IN 
- right-bottom RED SPDT switch == fan manual ON/OFF 
- orange jumper - set to 5V, less important, keep default 
- left-top BLUE connector - [[DC-barrel-jack-dat]] - 12V power IN
- right-bottom BLUE connector - external 5V output supply (SJ2)
- SJ1 == less important, keep default 
- SJ3 == IO12 control or manual switch control 

![](2025-08-07-18-53-33.png)

## Function 

### Fan control by three options 

- NAND gate use [[logic-gate-dat]] 

- LM temperature Limit ALRAM (NAND_A)
- GPIO12 (NAND_B either gate ) - [[RPI-pin-dat]] - [[rpi-python-dat]]
- Manual switch (NAND_B either gate )


| A   | B   | output mosfet | fan |
| --- | --- | ------------- | --- |
| L   | L   | H             | ON  |
| L   | H   | H             | ON  |
| H   | L   | H             | ON  |
| H   | H   | L             | OFF |


![](2025-02-03-17-08-52.png)

- [[Fan-dat]] drive by [[mosfet-dat]], only turn on or off




## demo code 

- Temperature sensor == [[LM75-dat]]
- GPIO12 code to run == [[RPI-python-dat]]

## Note 

Note when use this board and external 12V power supply to DC jack, you should NOT use micro USB power anymore, otherwise it can damage board.






## ref 

- [[RPI-SDK-dat]] - [[RPI-dat]] - [[RPI-python-dat]]

- [[power-protection-dat]] - [[DFK-dat]]

- [[fan-dat]] == FAN 3007 

- [[dcdc-buck-dat]]

- [[LDO-dat]]

- [[MPC1108]]

