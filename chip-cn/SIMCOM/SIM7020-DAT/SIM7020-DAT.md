
# SIM7020 DAT

- NBIOT - https://w.electrodragon.com/w/Category:NBIOT
- legacy wiki - https://w.electrodragon.com/w/Category:SIM7020


- SIM7020 git info : https://github.com/Edragon/SIMCOM_SIM7020

- [[SIMCOM-AT-dat]]

## Chip Info 

Supported band
- SIM7020E: B1 B3 B5 B8 B20 B28
- SIM7020G: all bands, please see our wiki page NBIOT.

## quick setup guide 

* Please use a USB-serial adapter like CP2102 or FT232RL, connect 5V, GND, VTXD and VRXD.
* Must well attached the SIM card and 2.4Ghz antenna.
* Hold down the side button for 3-5 seconds until LED start to blink,.
* Now you can send AT commands via serial uart COM port.
* (USB port is NOT working for debugging, please do not connect to use it.)



## Power Supply Mode 

* 500mA @ 3.3V 
  
Test based on our current SIM7020E module 

| Module               | Current       | -   |
| -------------------- | ------------- | --- |
| Registeration Mode   | ~15mA         | -   |
| Registered Idle Mode | ~5mA          | -   |
| PSM mode             | 110 ~ 140 0uA |     |


To enter into PSM mode
* AT+CFUN=0,0 // minimium function mode
* AT+CFUN=1,1 // full working mode
* AT+CPSMS=1  // turn on PSM mode 
  
Quit PSM mode
* Short pulse Boot pin to leave PSM mode



## REF

module version: - SIM7020E tested working countries: Finland, Sweden


board ref 
- [[NGS1095-dat]] - [[NGS1096-dat]]

- [[SIMCOM-AT-dat]]

- [[NGS1094-dat]]: old version SIM7020E, life time over

- [[SIM7020]]


## doc

- https://w2.electrodragon.com/chip-cn/SIMCOM/SIM7020-DAT/SIM7020_Series_AT_Command_Manual_V1.00.pdf
- https://w2.electrodragon.com/chip-cn/SIMCOM/SIM7020-DAT/SIM7020G_Hardware_Design_V1.00.pdf