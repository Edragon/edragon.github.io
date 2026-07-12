

# PCIE-1x-dat

- [[PCIE-mini-dat]] - [[PCIE-dat]] - [[PCIE-1x-dat]]




## PCIE 1x == 36 pins 

A PCIe x1 slot is a type of expansion slot on a computer motherboard, primarily designed for low-bandwidth devices. It has a single PCIe lane, offering the lowest data transfer rate among different PCIe slot types. Despite its limitations, it's useful for various low-power peripheral cards. 

![](2025-08-14-15-10-45.png)

18 *2 = 36 pins

PCI Express 1x - 36 pin Female Connector

PCI Express (PCIe) is a high-speed serial expansion interface maintained by the PCI Special Interest Group (PCI-SIG); the base specification was published in 2002 and the bus reached mainstream PCs in 2003–2004. It replaces the shared parallel bus of conventional PCI with point-to-point serial links. 

A link is built from lanes, each lane being one differential pair per direction (dual-simplex); the x1 slot provides a single lane and is the smallest PCIe slot, used for lower-bandwidth expansion cards such as network, sound and capture cards. 

First-generation PCIe runs at 2.5 GT/s per lane per direction and the second generation at 5.0 GT/s, using 8b/10b encoding with an embedded clock. 

The x1 add-in card edge connector has 36 contacts, 18 on each side. 


https://en.wikipedia.org/wiki/PCI_Express

Pinout
The following table identifies the conductors on each side of the edge connector on a PCI Express card. The solder side of the printed circuit board (PCB) is the A-side, and the component side is the B-side.

`PRSNT1#` and `PRSNT2#` pins must be slightly shorter than the rest, to ensure that a hot-plugged card is fully inserted. The `WAKE#` pin uses full voltage to wake the computer, but must be pulled high from the standby power to indicate that the card is wake capable.


| Pin  | Side B     | Side A  | Description                          |
| :--- | :--------- | :------ | :----------------------------------- |
| 1    | +12 V      | PRSNT1# | Must connect to farthest PRSNT2# pin |
| 2    | +12 V      | +12 V   | Main power pins                      |
| 3    | +12 V      | +12 V   | Main power pins                      |
| 4    | Ground     | Ground  |                                      |
| 5    | SMCLK      | TCK     | SMBus and JTAG port pins             |
| 6    | SMDAT      | TDI     | SMBus and JTAG port pins             |
| 7    | Ground     | TDO     | SMBus and JTAG port pins             |
| 8    | +3.3 V     | TMS     | SMBus and JTAG port pins             |
| 9    | TRST#      | +3.3 V  | SMBus and JTAG port pins             |
| 10   | +3.3 V aux | +3.3 V  | Aux power & standby power            |
| 11   | WAKE#      | PERST#  | Link reactivation; fundamental reset |
|      |            |         |                                      |
| 12   | CLKREQ#    | Ground  | Clock request signal[28]             |
| 13   | Ground     | REFCLK+ | Reference clock differential pair    |
| 14   | HSOp(0)    | REFCLK− | Lane 0 transmit data, + and −        |
| 15   | HSOn(0)    | Ground  | Lane 0 transmit data, + and −        |
| 16   | Ground     | HSIp(0) | Lane 0 receive data, + and −         |
| 17   | PRSNT2#    | HSIn(0) | Lane 0 receive data, + and −         |
| 18   | Ground     | Ground  |                                      |

## ref 

