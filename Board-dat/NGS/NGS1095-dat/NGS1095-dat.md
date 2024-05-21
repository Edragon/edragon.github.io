
# NGS1095 Dat 

* Pin pitch 2.0 mm 


![](55-39-13-18-07-2023.png)

## pin definitions 

Pin Definitions R2:
* U1V_RXD, U1V_TXD: uart1 txd and rxd pin via logic shifter, 5V compliant
* IO0: GPIO 0
* VDD: VDD 3.3V from module
* RI DTR DCD CTS RTS RXD TXD: Full UART1 pins, extra pins can be used as GPIO or other control functions, please refer to datasheet.
* M_K: external MCU control pin, pull high to power on module
* U2TXD, U2RXD: uart2 pins, can be used for upgrade firmware.
* VUSB, DP, DM, GND: USB debug pins
* RST - reset, ADC - analog read pin, V_ext: power supply logic, STAT: status logic, NET: netlight
* GND, VIN: Power supply in, support up to 12V.


## Pin Soldering Side 

on sim card side  
![](56-21-17-02-08-2023.png)

on module side
![](04-22-17-02-08-2023.png)


# reference 

- [[SIM7020-DAT]] - [[SIMCOM-dat]]

- [[low-power-dat]]

- [[SIM7020]]