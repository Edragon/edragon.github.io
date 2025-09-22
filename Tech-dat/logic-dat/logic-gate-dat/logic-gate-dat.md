
# logic gate 

- [[buffer-dat]]

## implementation 

- [[MPC1108-dat]]


## 74AHC1G125 = SINGLE BUFFER GATE WITH 3-STATE OUTPUT

The 74AHC1G125 is a single non-inverting buffer/bus driver with a 3-state output. The output enters a high impedance state when a HIGH-level is applied to the output enable (OE) pin. The device is designed for operation with a power supply range of 2.0V to 5.5V.

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


## AND 

### SN74AHC1G08

SN74AHC1G08 Single 2-Input Positive-AND Gate

The SN74AHC1G08 device is a single 2-input positive-AND gate. The device performs the Boolean function 

    Y = A ● B 
    or Y = A + B 

in positive logic.

| A   | B   | Y   |
| --- | --- | --- |
| H   | H   | H   |
| L   | X   | L   |
| X   | L   | L   |


| Input A | Input B | Output |
| ------- | ------- | ------ |
| 0       | 0       | 0      |
| 0       | 1       | 0      |
| 1       | 0       | 0      |
| 1       | 1       | 1      |



| Term              | Meaning                                                              |
| ----------------- | -------------------------------------------------------------------- |
| AND gate          | Basic logic gate: output is 1 only if both inputs are 1              |
| Positive-AND gate | Same thing — "positive" means using standard logic levels (high = 1) |
| Negative logic    | Less common, where high voltage = logic 0                            |

## more gate chips 

- CDx4HC11 == Triple 3-Input AND Gates 

- CD4001B, CD4002B, CD4025B == CMOS NOR Gates


## ref 

- [[logic-dat]]