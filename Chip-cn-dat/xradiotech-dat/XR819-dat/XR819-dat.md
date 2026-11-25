


# XR819-dat

- [[XR819-dat]] - [[XRadiotech-dat]]


The XR819 is a single-band 2.4 GHz WLAN System-on-Chip (SoC) manufactured by XRadio Technology (associated with Allwinner) in a QFN-40 package, designed for embedded devices, single-board computers (such as Allwinner H3 boards), TV boxes, and IoT hardware.

Key Specifications

• Wi-Fi Standard: IEEE 802.11 b/g/n (2.4 GHz), up to 65 Mbps OFDM data rates
• Host Interface: SDIO 2.0
• RF & Power Integration: Integrated 2.4 GHz RF transceiver, PA, LNA, TR switch, internal impedance matching, and on-chip auto-calibration
• Clocks: XTAL or external reference clock (13–52 MHz); internal or external 32.768 kHz low-power clock
• Security & Features: Wi-Fi Direct, WMM/802.11e QoS, 802.11d/h, WPA2, and WAPI

Linux & Hardware Notes

• Drivers & Firmware: It does not have an official upstream Linux kernel driver; developers typically rely on out-of-tree xradio kernel modules and firmware blobs (fw_xr819.bin, sdd_xr819.bin, boot_xr819.bin). You can review build instructions and driver sources in the XR819 Datasheet and the katyo/xr819 repository.
• Power & Layout: Requires 3.3V, 1.8V, and VDD_IO rails with local decoupling capacitors and a pull-up resistor on SDIO_DATA2.




## ref 