
# RF-LINK-dat 

- [more info please find at legacy wiki page](https://w.electrodragon.com/w/Category:RF-Link)

[legacy wiki page 2](https://www.electrodragon.com/w/Category:Wireless)

## products 


- [[NWL1016-dat]] - [[NWL1017-dat]]

https://www.electrodragon.com/product/433m-rf-wireless-module-a-pair-of-receiver-and-transmitter/


- [[NWL1021-dat]] - [[NWL1022-dat]]

- [[NWL1026-dat]] - [[NWL1027-dat]]


### snap button 

- [[NRF1003-dat]] == https://www.electrodragon.com/product/press-button-round-rf-ask-transmitter-433mhz-w-adhesive/



### RF-LINK relay 

[[SCU1001-dat]] == https://www.electrodragon.com/product/wireless-relay-kit-learning-code/



## EDRF1 and EDRF2 Decoder

- [[NWL1089-dat]] - [[NWL1068-dat]] / [[NWL1070-dat]]




## tech 

Manchester encoding

- [[PT2262-dat]] - [[PT2272-dat]] - [[EV1527-dat]]

learning code 
 
fixed (welding code) code

## working mode 

### Jog (M4) Single Working Mode Description:

When the transmitter button is pressed, the corresponding channel outputs a high level. When the button is released, it returns to a low level, with a VT (valid transmission) pulse output.  
Example: If button A has been learned by channel D0, pressing button A will make channel D0 output a high level; releasing the button will return it to a low level. Other channels are not affected.

### Interlock (H4)

### Self-lock (T4)


## schematic and APP 

Application Fields
Wireless remote control switches, sockets, wireless burglar alarms, wireless remote control door locks, wireless doorbells, wireless remote control electric rolling doors and windows, wireless LED lighting, industrial remote control products, etc.

![](2025-06-25-15-15-27.png)


min. SCH 

![](2025-06-25-15-19-01.png)

## Note 


Note about distance:

If the distance required for far, can be connected to the 1/4 wavelength of the antenna, generally use 50 ohm single conductor, the length of the antenna 315M of about 23cm, 433M of about 17cm;

The position of the antenna has also affected the reception of the module, install the antenna as straight as possible away from the shield, high pressure, and interference sources;


## code

### arduino 



## demo video 

https://www.youtube.com/watch?v=LDGr38Ie1L4


## ref 

- [[RF-LINK]]