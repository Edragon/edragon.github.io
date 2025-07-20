
# MPC1108-dat

https://www.electrodragon.com/product/smart-fan-cooling-control-board-for-raspberry-pi/


![](2024-07-08-18-28-25.png)




## Function 

### Fan control by three options 

- NAND gate use [[logic-gate-dat]] 

- LM temperature Limit ALRAM (NAND_A)
- GPIO12 (NAND_B either gate )
- Manual switch (NAND_B either gate )

| A =temp. alarm | B = IO12 or switch | out |
| -------------- | ------------------ | --- |
| L              | L                  | H   |
| L              | H                  | H   |
| H              | L                  | H   |
| H              | H                  | L   |


![](2025-02-03-17-08-52.png)

- [[Fan-dat]] drive by [[mosfet-dat]], only turn on or off

### Temperature sensor 

- [[LM75-dat]]


## Note 

Note when use this board and external 12V power supply to DC jack, you should NOT use micro USB power anymore, otherwise it can damage board.






## ref 

- [[dcdc-buck-dat]]

- [[MPC1108]]

