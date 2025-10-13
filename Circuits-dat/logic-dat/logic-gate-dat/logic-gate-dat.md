
# logic gate 

- [[buffer-dat]]

- [[XOR-dat]]


## Inverters

SN54HC14, SN74HC14 == SNx4HC14 Hex Inverters with Schmitt-Trigger Inputs


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

SN74HC00N ==  'NAND' GATE QUAD, 2 -INPUT

SN74HCS30DR - SN74HCS30 Single 8-Input NAND Gate with Schmitt-Trigger Inputs

### NC7SZ00


The NC7SZ00 is a single two−input NAND gate from onsemi’s Ultra−High Speed (UHS) series of TinyLogic.

![](2024-07-08-18-34-43.png)


## AND 

SN74HC11N ==  'AND' GATE TRIPLE, 3-INPUT

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

## OR gate

74HCT32D - Quad 2-Input OR Gate

## more gate chips 

- CDx4HC11 == Triple 3-Input AND Gates 

- CD4001B, CD4002B, CD4025B == CMOS NOR Gates

### dual 

DS75451/2/3 Series Dual Peripheral Drivers

The DS75451, DS75452 and DS75453 are dual peripheral AND, NAND and NOR drivers, respectively, (positive logic) with the output of the logic gates internally connected to the bases of the NPN output transistors.


## ref 

- [[logic-dat]]