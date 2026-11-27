


# RTL8188US-dat

- [[realtek-dat]] - [[RTL8188US-dat]] - [[RTL8188-dat]] - [[ddpai-dat]] - [[RTL8192-dat]] - [[linux-dat]] - [[wifi-sdio-dat]]

The Realtek RTL8188CUS is a single-chip USB 2.0 wireless network controller supporting 2.4 GHz 802.11n (1T1R) up to 150 Mbps. Commonly found in budget USB Wi-Fi dongles and older embedded modules, it is widely used on legacy PCs, Raspberry Pi boards, and DIY electronics.

Key Specifications & Compatibility

- • Wireless Standard: IEEE 802.11b/g/n (2.4 GHz only, single-stream 1T1R, 150 Mbps theoretical max).
- • Interface: USB 2.0.
- • Windows: Supported via legacy drivers on Windows 7 through Windows 10/11 (often available through the Microsoft Update Catalog or vendor archives such as Lenovo Support).
- • Linux: Supported in the Linux kernel (`rtl8192cu` / `rtl8xxxu` drivers), with older source packages and guides also archived on GitHub and RidgeRun Developer Wiki.
- • FreeBSD: Supported via the rtwn(4) driver. A single user on The FreeBSD Forums noted an issue where ifconfig could fail to create a wlan interface on FreeBSD 14 despite the hardware being detected.
- • Embedded & Single-Board: Frequently paired with Raspberry Pi boards or microcontroller/tablet projects (such as modules sold on eBay).


- [[freeBSD-dat]]

- [[RPI-SBC-dat]]

## ref 