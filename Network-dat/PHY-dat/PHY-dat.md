
# PHY-dat


- [[ethernet-dat]] - [[wireless-dat]] - [[fiber-optic-dat]]


- [[PHY-dat]] - [[SerDes-dat]] - [[SGMII-dat]] - [[RGMII-dat]] - [[RMII-dat]] - [[PHY-dat]]

- [[1000BASE-X-dat]] - [[1000BASE-T-dat]] - [[100BASE-TX-dat]] - [[10BASE-T-dat]]


## speed base 

These names are IEEE 802.3 Ethernet physical-layer (PHY) standards. Each label breaks down into **Speed** + **BASE** (baseband signaling) + **Medium/Coding**:

| Standard | Speed | Medium & Wires | Max Distance | Key Notes |
| --- | --- | --- | --- | --- |
| **10BASE-T** | 10 Mbps | Twisted-pair copper (Cat3 or higher) | 100 m | Legacy Ethernet; uses 2 pairs (pins 1, 2, 3, 6). |
| **100BASE-TX** | 100 Mbps ("Fast Ethernet") | Twisted-pair copper (Cat5 or higher) | 100 m | Uses 2 pairs (1 TX, 1 RX) with 4B5B + MLT-3 encoding; supports full duplex. |
| **1000BASE-T** | 1000 Mbps / 1 Gbps ("Gigabit Ethernet") | Twisted-pair copper (Cat5e or higher) | 100 m | Uses **all 4 pairs** simultaneously in full duplex with PAM-5 encoding and auto-negotiation. |
| **1000BASE-X** | 1000 Mbps / 1 Gbps (1.25 Gbps line rate with 8B/10B) | Optical fiber / SerDes family (includes 1000BASE-SX, LX, BX) | Varies (hundreds of meters to 80+ km) | Family name for 1G optical/SerDes standards (such as BiDi single-fiber modules). |

### How They Relate to Your SFP / PHY Design

* **`1000BASE-T` vs. `1000BASE-X`:** Both run at **1 Gbps** payload data rate, so a chip like the **RTL8211FS** can bridge between a `1000BASE-X` SFP optical link and a `1000BASE-T` RJ45 copper port.
* **Why `1000BASE-X` matters for SFP:** Optical SFP modules (including BiDi `1310nm / 1510nm` pairs) use **1000BASE-X** signaling (8B/10B encoding at 1.25 Gbps) rather than `1000BASE-T` copper signaling. When configuring a PHY or SerDes interface for an SFP module, set the interface mode to **1000BASE-X** rather than copper `1000BASE-T`.




## RGMII and SGMII Interfaces

`RGMII (Reduced Gigabit Media Independent Interface)` is a parallel, single-ended interface (typically 12–14 pins). 
`SGMII (Serial Gigabit Media Independent Interface)` is a high-speed serial, differential (LVDS) interface (typically 4–6 pins). Both connect a MAC to a PHY for Ethernet (commonly 1 Gbps, and up to 2.5 Gbps for SGMII/HSGMII).

### Key Differences


| Feature           | RGMII                                                            | SGMII                                                                       |
| ----------------- | ---------------------------------------------------------------- | --------------------------------------------------------------------------- |
| Signaling         | Parallel, single-ended (DDR/SDR)                                 | Serial, differential (LVDS) with 8B/10B encoding                            |
| Pin Count         | ~12–14 pins per port                                             | ~4–6 pins per port                                                          |
| Clock / Line Rate | 125 MHz clock (at 1 Gbps DDR)                                    | 625 MHz DDR / 1.25 Gbps line rate (at 1 Gbps)                               |
| Host Requirement  | Standard MAC/GPIO pins (no SerDes needed)                        | Requires SerDes transceiver support                                         |
| PCB Layout        | Requires length matching and skew control; best for short traces | Fewer traces and better EMI immunity; requires 100 Ω differential impedance |


### When to Choose Which

- • Choose RGMII for 1–2 port designs, cost-sensitive boards, short PCB traces, or processors without SerDes.
- • Choose SGMII for pin-constrained MCUs/SoCs, multi-port switches or routers, longer board traces, or noisy (high-EMI) environments where your chip has SerDes.



## PHY 

A PHY chip (short for physical layer chip, also called a PHY transceiver or PHY IC) is a hardware circuit that implements Layer 1 of the OSI model. It bridges digital logic inside a processor or controller with the physical transmission medium—such as copper cable, fiber optic cable, or radio waves—by converting digital bits into analog or physical signals and back.

How a PHY Chip Works

- • Signal conversion: Translates digital bitstreams into electrical pulses, optical signals, or modulated radio waves for transmission, and decodes incoming signals back into digital bits.
- • Encoding and timing: Handles line coding, clock and data recovery (CDR), and signal conditioning to keep data reliable over noisy or long links.
- • Link management: Negotiates connection parameters (such as link speed and duplex mode on Ethernet) and reports link status.
- • PHY vs. MAC: The Media Access Control (MAC) layer handles frames, addressing, and access timing, while the PHY handles raw physical signals on and off the medium. They often connect via interfaces like MII, RMII, or RGMII.

Common Usage Examples

- • `Ethernet`: Found in routers, switches, network cards, and embedded boards to drive twisted-pair copper or optical links (see everything RF for an overview of PHY layers).
- • `Wireless communications`: Used in Wi-Fi, Bluetooth, cellular (4G/5G), and UWB systems with RF/analog front-ends and baseband signal processing.
- • `High-speed I/O and storage`: Used in USB, HDMI, SATA, and high-speed chip-to-chip or memory interfaces to move data reliably at high rates.



Key roles of a PHY:

- Signal encoding/decoding: Converts digital data (from the MAC) into signals suitable for transmission over physical media (and vice versa).
- Clock recovery: Extracts clock signals from incoming data streams.
- Auto-negotiation: Determines connection parameters like speed (10/100/1000 Mbps) and duplex mode (full/half).
- Media-dependent interfaces: Provides the electrical interface for the transmission medium, such as copper wires or fiber.

The PHY communicates with the MAC through standardized interfaces like RGMII, MII, or GMII.





## MDIO (Management Data Input/Output)

The MDIO (Management Data Input/Output) interface is a two-wire protocol used for managing and configuring Ethernet PHYs. It allows the MAC (or a host controller) to:

- Read status registers in the PHY.
- Configure operating modes (e.g., speed, duplex, auto-negotiation settings).

MDIO Interface Components:
- MDIO Signal: A bidirectional data line that transfers register addresses and data between the controller and the PHY.
- MDC (Management Data Clock): A clock signal provided by the MAC or host to synchronize MDIO operations.


Using the MDIO interface, a host can control multiple PHY devices on the same bus by assigning unique addresses to each PHY.