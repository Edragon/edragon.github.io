
# Logic-shifter-dat

## board 

- [[MSP1007-dat]]




## Chip and solutions

### bidirection logic shifter

- [[ti-signal-dat]]

- [[TXB0108-dat]] - [[BSS138-dat]] 

- [[LSF0102-dat]]

- [[TXS0102-dat]] - [[TXS0108-dat]] - [[TI-logic-dat]]


### one-direction logic shifter

- [[74HCT245-dat]]





## TXB010x VS TXS010x 

For the same reason, the TXB0108 should not be used in applications such as I2C or 1-Wire where an open-drain driver is connected on the bidirectional data I/O. For these applications, use a device from the TI TXS01xx series of level translators.

| Type     | Open-Drive | Push-pull | Examples    |
| -------- | ---------- | --------- | ----------- |
| TXB 010x | ×          |           |             |
| TXS 010x | ✔          | ✔         | I2C, 1-Wire |

![](2024-04-30-16-16-14.png)

Make sure the VCCA ≤VCCB.

### Simple logic shifter for VBAT 


![](2025-04-18-18-57-43.png)




## logic level shifter for UART 

![](2025-07-10-18-34-29.png)

- Diode + pull-up resistor on RXD 


## Simple I2C shifter 

- [[I2C-dat]]

![](2025-07-13-01-24-51.png)

![](2025-07-13-02-12-39.png)



## unsort 

- MAX3372E–MAX3379E/MAX3390E–MAX3393E - ±15kV ESD-Protected, 1μA, 16Mbps, Dual/Quad Low-Voltage Level Translators in UCSP





## ref 

- [[logic-shifter]]