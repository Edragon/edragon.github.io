

# Board Info 

### Pin Definitions 

BOOT 3V3 GND PIN RXD TXD


Pin Definitions of SIM7020-V: 
* TXD RXD PIN GND 3V3 BOOT


### Power supply 
- 3V3 500mA
- Logic level is the sme 3V3


### Common Debug Error

- you must use NBIOT Card, normal phone card may not work
- if the card no service, system will shut power at CREG 0,2

# PSM Mode 

- AT commands to enter into PSM power save mode 
- pull down RTC_EINT or PWR_KEY to quit PSM mode 

## Dimension / Pins / Schematic 

![](04-17-16-01-02-2023.png)

![](57-21-16-01-02-2023.png)



# reference 
- [[SIM7020-DAT]]
- [[low-power-test-dat]]