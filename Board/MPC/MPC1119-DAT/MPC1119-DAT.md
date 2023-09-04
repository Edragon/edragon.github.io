
# MPC1119 DAT


## pin definitions 

- pin SC to raspberry pi pin ID_SC
- pin SD to raspberry pi pin ID_SD

- to use the extra pins, you need to cut the jumpers to release them from the chip below, and chain P3 can not be used anymore. 

- RX | GND (some boards mark could be reversed): UART_RX debug, or ROW_E set to ground 

## Wiring

- If you supply power to matrix panels separately, the converter board MPC1119 will be power supplied by pins, no need extra power supply. 
- If you supply all power from one port on the converted board, you can connect the power supply to matrix panels from another port.
- Voltage should be no more than 5.5V.



### Legacy Wiki 

- RMP Guide - https://w.electrodragon.com/w/RPI_RMP_Guide#P3/P4_64x64_(tested)

- [[MPC1119]]

- [[MPC1073-DAT]] - [[MPC1119-DAT]]