

# USB-tethering-dat


- [[USB-tethering-dat]] - [[wifi-dongle-dat]]

## Overview

Most mainstream consumer ZTE portable Wi-Fi devices, 4G/5G dongles, and CPEs (e.g., MF935, MF971, MU5001, MC801) do **not** ship with a pure "RNDIS Mode" in their default firmware and standard feature set. Instead, they rely on:

- **CDC-ECM / CDC-NCM** protocols, or
- Management via the **web UI / mobile app**

However, at the technical level, ZTE devices do support RNDIS (or an equivalent USB virtual network card sharing effect). This mainly applies in the following scenarios.

---

## Why do many ZTE portable Wi-Fi devices work directly with "USB Tethering" on a PC?

### 1. Underlying protocol similarity

RNDIS is a virtual Ethernet standard defined by Microsoft.

When **USB Tethering** is enabled on ZTE portable Wi-Fi devices (e.g., Qualcomm-based portable Wi-Fi and MiFi devices with official firmware) — also known as **USB network sharing** or **Ethernet-priority mode** — the device registers itself with Windows as a local wired network card, essentially through **RNDIS** (or a compatible CDC-NCM driver).

### 2. Driverless plug-and-play

When using the ZTE device's admin panel (usually `192.168.0.1` or `192.168.1.1`) or its bundled driver, simply enabling **USB network card / sharing mode** allows:

- **Windows**
- **Linux**
- Mainstream software routers (e.g., **OpenWrt**)

to treat the device directly as an Ethernet device (e.g., `usb0`) and obtain an IP address from it — no extra configuration needed.  



## ref 

