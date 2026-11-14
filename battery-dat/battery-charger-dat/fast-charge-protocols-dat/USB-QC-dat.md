
# USB-QC-dat


- [[fast-charge-protocols-dat]] - [[USB-QC-dat]] - [[USB-PD-dat]]

- [[conn-usb-micro-dat]] - [[conn-usb-type-c-dat]]



## chip 

- [[qualcomm-dat]] - [[USB-QC-dat]] - [[FT4SJK-dat]] - [[ZXW602-dat]]


`FT4SJK` is a top-side SMD marking code found on a tiny USB fast-charging protocol controller IC (integrated circuit), typically housed in a SOT-23-6 package. 

It is commonly seen inside USB wall chargers and power banks, such as Yoobao Quick Charge 3.0 adapters.

Key Details & Function

- • Primary Role. The chip negotiates fast-charging voltages (such as Qualcomm Quick Charge 2.0/3.0) between the charger or power bank and a connected mobile device.
- • Circuit Placement. Its pins connect directly to the USB D+ and D- data lines to detect the attached device and communicate voltage requests to the main power management IC.
- • Datasheet Availability. FT4SJK is a proprietary marking code (often a batch or house code from a Chinese semiconductor manufacturer) rather than a standard part number, meaning public datasheets are generally unavailable.




## info 

1. Different "Languages" (Protocols)
 
QC 2.0: Uses the D+ and D- data lines of a USB cable to negotiate voltage by changing the DC voltage levels on those pins.

USB PD: Uses a dedicated CC (Configuration Channel) line inside the USB-C cable to send high-speed digital data packets for negotiation.

2. Physical Interface

`QC 2.0` was designed for USB-A to Micro-USB cables.

`USB PD` requires a USB-C to USB-C (or USB-C to Lightning) connection to utilize the CC pin.



USB Charging Compatibility Matrix

| Power Source (Charger) | Device (Load)                   | Result        | Protocol Negotiation                  |
| :--------------------- | :------------------------------ | :------------ | :------------------------------------ |
| **QC 2.0 / 3.0**       | **USB PD** (e.g., Pixel/iPhone) | **Slow (5V)** | Fails; defaults to standard USB power |
| **USB PD**             | **QC 2.0 / 3.0**                | **Slow (5V)** | Fails; CC pins vs D+/D- mismatch      |
| **QC 4.0 / 4+ / 5.0**  | **USB PD**                      | **Fast**      | Compatible (QC 4+ is built on PD)     |
| **Multi-Protocol**     | **Any**                         | **Fast**      | Charger chip auto-detects protocol    |



1. Important Exception: QC 4.0 and Newer

Starting with Quick Charge 4.0, Qualcomm made their technology compatible with the USB PD standard.

QC 2.0 / 3.0: Proprietary and Incompatible with PD.

QC 4.0 / 4+ / 5.0: Built on top of USB PD, so they are compatible.

## ref 


- [[m]]