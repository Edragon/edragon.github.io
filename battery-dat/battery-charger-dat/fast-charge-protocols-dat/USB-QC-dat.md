
# USB-QC-dat


- [[fast-charge-protocols-dat]] - [[USB-QC-dat]] - [[USB-PD-dat]]

- [[conn-usb-micro-dat]] - [[conn-usb-type-c-dat]]

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