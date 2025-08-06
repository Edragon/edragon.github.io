
# logic gate 


## 74AHC1G125

https://www.diodes.com/assets/Datasheets/74AHC1G125.pdf

| OE  | A   | Y   |
| --- | --- | --- |
| L   | H   | H   |
| L   | L   | L   |
| H   | X   | Z   |

The output enters a high impedance state when a HIGH-level is applied to the output enable (OE) pin. 


## NAND 

### NC7SZ00


The NC7SZ00 is a single two−input NAND gate from onsemi’s Ultra−High Speed (UHS) series of TinyLogic.

![](2024-07-08-18-34-43.png)



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



## ref 

- [[logic-dat]]