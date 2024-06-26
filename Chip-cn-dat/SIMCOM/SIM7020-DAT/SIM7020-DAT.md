
# SIM7020 DAT




## quick setup guide 

* Please use a USB-serial adapter like CP2102 or FT232RL, connect 5V, GND, VTXD and VRXD.
* Must well attached the SIM card and 2.4Ghz antenna.
* Hold down the side button for 3-5 seconds until LED start to blink,.
* Now you can send AT commands via serial uart COM port.
* (USB port is NOT working for debugging, please do not connect to use it.)

## Application Note 

## Power supply 

- VBAT  Module power voltage  min. 2.1  typ. 3.3  max. 3.6  V


### PSM Mode 

- AT commands to enter into PSM power save mode 
- pull down RTC_EINT or PWR_KEY to quit PSM mode 

- [[SIMCOM-PSM-Dat]]

## REF

### module versions 
module version: - SIM7020E tested working countries: Finland, Sweden

Supported band
- SIM7020E: B1 B3 B5 B8 B20 B28
- SIM7020G: all bands, please see our wiki page NBIOT.


- [[SIMCOM-AT-DAT]]


### other ref 
- NBIOT - https://w.electrodragon.com/w/Category:NBIOT
- legacy wiki - https://w.electrodragon.com/w/Category:SIM7020


- SIM7020 git info : https://github.com/Edragon/SIMCOM_SIM7020


## Demo 

- Basic Test Demo - https://www.youtube.com/shorts/HXGcgzOb-aY
- https://x.com/electro_phoenix/status/1640585737308622850



### board ref 


- [[NGS1095-dat]] - [[NGS1096-dat]] - [[NBIOT-dat]]

- [[NGS1094-dat]] - SIM7020E (old version) - life time end 

- [[SIMCOM-AT-DAT]] - [[SIMCOM-dat]]

- [[SIM7020]] - [[BTB-dat]]

- [[low-power-dat]] - [[SIMCOM-low-power-Dat/SIMCOM-PSM-Dat/SIMCOM-PSM-Dat]]

## doc

- [[SIM7020_Series_AT_Command_Manual_V1.00.pdf]]

- [[SIM7020G_Hardware_Design_V1.00.pdf]]
