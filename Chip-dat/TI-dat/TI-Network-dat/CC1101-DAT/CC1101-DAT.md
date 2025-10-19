

# CC1101 DAT


Low-Power Sub-1 GHz RF Transceiver 

## CC1101 Chip Features 
- Work on 433 MHz free ISM RF band, no need license.
- Built-in hardware CRC error detection, and address control
- The maximum rate of 500kbps (1.2K Min.), support for 2-FSK, GFSK, FSK and MSK modulation, support the transmission channel before the auto-clean-up visits (CCA), the Carrier Sense System, very suitable for using at industrial environment.
- Fast frequency changes brought about by a suitable synthesizer frequency hopping system
- Most 256 program channels (20M band).
- Large data buffer area. Separate 64-byte RX and TX data FIFO
- Address can be set up by software, only received local address only when the output data (provided interrupt instruction), can be directly connected using a variety of MCU, very convenient
- High sensitivity: 1.2Kbps under-110dBm, 1% packet error rate
- Lower current consumption: 20mA averagely in RX mode and 30mA averagely in TX mode, at 10dBm

## Board Versions 
![](36-52-17-29-01-2023.png)

LSS - standard chip only version 
- CC1101-LSS: Low Power, SPI interface, Spring Coil - [[NWL1037-DAT]]

MSR
- CC1101-MSR: Medium Power, SPI interface, rod antenna - [[NWL1044-DAT]]


- same board except antenna LUS LUR 
- CC1101-LUS: Low Power, UART TLL interface, Spring Coil - [[NWL1042-DAT]]
- CC1101-LUR: Low Power, UART TTL interface, rod antenna - [[NWL1039-DAT]]
  


## Schematic 

![](2023-09-05-16-22-07.png)



## ref 

- [[CC1101-code]]

-  legacy wiki - https://w.electrodragon.com/w/CC1101

- [[RF-DAT]] - [[RF]]