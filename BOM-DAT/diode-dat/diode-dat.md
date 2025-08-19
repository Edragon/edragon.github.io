
# diode-dat

brand - [[st-dat]]

| model  | footprint | mark    |
| ------ | --------- | ------- |
| SS14   | SMA       | SS14/SL |
| 1N4007 | SMA       | M7      |


- [[diode-zener-dat]] - [[flyback-diode-dat]]


## Schottky diode

Schottky diode SS14 DO-214AC SMA
Schottky diode BAT54J.115 SOD-323F
Schottky diode ES2D DO-214AA (SMB) == [ES2A, ES2B, ES2C, ES2D](https://www.vishay.com/docs/88587/es2.pdf) == Vishay

## Voltage regulator diodes

### nexperia

- [BZX384-C3V3](https://www.nexperia.com/product/BZX384-C3V3)

## Ultrafast Diode

[stth4r02](https://www.st.com/en/diodes-and-rectifiers/stth4r02.html)

- 200 V, 4 A High Effiency Ultrafast Diode
- st 




## SRGC10MH 1N4007 Specs 

| Feature                           | SRGC10MH              | 1N4007                |
| :-------------------------------- | :-------------------- | :-------------------- |
| **Type**                          | Standard Rectifier    | Standard Rectifier    |
| **Package**                       | SMA (Surface Mount)   | DO-41 (Through-Hole)  |
| **Peak Reverse Voltage (VRRM)**   | 1000 V                | 1000 V                |
| **Avg. Forward Current (IF(AV))** | 1 A                   | 1 A                   |
| **Forward Voltage (VF @ 1A)**     | ~1.1 V                | ~1.1 V                |
| **Reverse Current (IR @ VRRM)**   | ~5 µA (Typical)       | ~5 µA (Typical)       |
| **Operating Temperature**         | -55°C to +150/175°C * | -55°C to +175°C (Typ) |

*Operating temperature for SRGC10MH can vary slightly by manufacturer.

- [[SRGC10MH-dat]] - [[1N4007-dat]] - [[diode-dat]]

## voltage drop of diode 

| Diode         | Type     | Max Current | Typical Vf @ 1A | Notes                             |     |
| ------------- | -------- | ----------- | --------------- | --------------------------------- | --- |
| 1N4001–1N4007 | Silicon  | 1A          | ~0.7V           | General-purpose rectifier         |     |
| 1N5401–1N5408 | Silicon  | 3A          | ~0.7–1.0V       | Higher current, bulkier           |     |
| UF4001–UF4007 | Silicon  | 1A          | ~0.7V           | Ultra-fast silicon version        |     |
| 1N5817        | Schottky | 1A          | ~0.45V          | Good low-drop Schottky            |     |
| 1N5819        | Schottky | 1A          | ~0.5V           | Slightly higher Vf than 1N5817    |     |
| SS14          | Schottky | 1A (avg)    | ~0.5V           | Compact SMD version               |     |
| MBRS140       | Schottky | 1A          | ~0.5V           | SMD Schottky, low forward drop    |     |
| MR754         | Power    | 6A          | ~1.0–1.1V       | High-power stud-mount diode       |     |
| BYV29         | Power    | 9A          | ~0.9–1.2V       | Fast recovery, TO-220             |     |
| RHRP8120      | Power    | 8A          | ~1.0–1.2V       | Ultrafast recovery, large package |     |
| SS34          |          | 3A          |                 |                                   | 40V |



1N5401 

MBR0520L

## BAV99S == High-speed switching diode

https://assets.nexperia.com/documents/data-sheet/BAV99S.pdf

![](2025-08-19-16-51-09.png)


## ref 

- [[BOM-dat]]