



# IP2752-dat

- [[injoinic-dat]] - [[IP2726-dat]] - [[IP2752-dat]] - [[fast-charge-protocols-dat]] - [[USB-PD-dat]]

The Injoinic IP2752 is a USB Power Delivery (PD) sink controller (PD trigger/decoy chip) designed to negotiate power from USB-C chargers.

Key Specifications & Features

- • Protocol Support. Supports USB PD 3.1 applications.
- • Interface. Communicates with a host or secondary protocol controller via an I2C port.
- • Voltage Tolerance. The VBUS, CC1, and CC2 pins feature a 28V voltage resistance.
- • Primary Function. Acts as an upstream PD trigger to request specific voltage profiles from a power adapter (starting at 5V and scaling up as needed).

Common Applications

The IP2752 is widely used in 2-in-1 (1C-to-2C) fast-charging USB-C cables. In these designs, it sits at the upstream plug to request high wattage (up to 140W or 170W) from the wall charger, working alongside a protocol chip like the Injoinic IP2738U and DC-DC buck converters to dynamically split power between two connected devices. Notable products using this chip include:
- • Anker 140W 2-in-1 USB-C to USB-C Cable
- • Lenovo Legion 170W 2-in-1 Fast Charging Cable
- • CUKTECH No. 10 Super Power Cable (2-in-1)







## ref 


