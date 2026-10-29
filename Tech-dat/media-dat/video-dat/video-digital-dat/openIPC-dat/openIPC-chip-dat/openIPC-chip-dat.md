


# openIPC-chip-dat

- [[openIPC-chip-dat]] - [[VTX-openIPC-dat]]




## RTL8822CU 

![](2026-10-30-02-43-34.png)


## Chip solutions confirmed

The TP-Link Archer T4U has used different chips depending on the hardware revision — historically Realtek parts such as the **RTL8812AU**.

WFB-NG video links place special demands on the NIC: the **ground-side** adapter must be able to enter Monitor mode (promiscuous / listen mode) and support packet injection, otherwise it cannot correctly unpack the WFB-NG RF stream coming from the aircraft.

**Alternative and recommended options**

- [[antenna-MIMO-dat]] - [[RTL8814AU-dat]] - [[RTL8812AU-dat]] - [[RTL8822-dat]] - [[openIPC-dat]] - [[AR9271-dat]] - [[RT3070-dat]] - [[ralink-dat]] - [[RT3072-dat]]

If you are planning the airborne or ground-station NIC for OpenIPC, it is best to pick chips that are **highly mature in the community and fully covered by drivers**:

| Chip | Antenna config | Recommended use | Community support | Notes |
|---|---|---|---|---|
| **RTL8812AU** | 2x2 MIMO | airborne / ground station | ⭐⭐⭐⭐⭐ (top pick) | the current mainstream standard chip for OpenIPC / WFB-NG; richest tutorials and drivers |
| **RTL8812EU** | 2x2 MIMO | airborne (onboard / NIC) | ⭐⭐⭐⭐⭐ | newer chip, lower power than the 8812AU, common on dedicated OpenIPC airborne all-in-one boards |
| **RTL8822BU** | 2x2 MIMO | airborne / ground station | ⭐⭐⭐⭐ | well-controlled power draw, decent compatibility |
| **AR9271 / RT3070** | 1x1 (2.4G single band) | ground station / backup for speed | ⭐⭐⭐ | 2.4 GHz band only, lower performance |


## error

### RTL8814AU — root cause analysis

Put simply: **the RTL8814AU cannot be used directly — or is very strongly discouraged — in an OpenIPC digital video (WFB-NG) system.**

Although it belongs to the same chip family as the **RTL8812AU** that OpenIPC widely uses, under OpenIPC / WFB-NG the RTL8814AU has several fatal technical bottlenecks:

**① Missing driver and kernel-compatibility problems**

OpenIPC — especially the WFB-NG firmware used for HD digital video — relies heavily on the wireless driver's **Monitor mode** and **packet injection** support inside the embedded Linux kernel.

Very little porting and optimisation of the RTL8814AU's open-source / third-party Linux driver has been done on embedded SoCs (HiSilicon, SigmaStar, Rockchip and other IPC chips), so it cannot simply be compiled into OpenIPC's limited flash space.

**② WFB-NG (the video protocol) has not been adapted for it**

The WFB-NG stack underneath OpenIPC makes specific modifications to the NIC driver (to support a particular frame-injection rate, power control and low-latency transfer). All of the community's optimisation and testing is concentrated on **RTL8812AU / RTL8822BU / RTL8812EU** and similar chips — the RTL8814AU is not on the supported list.

**③ Much higher power draw and heat**

The RTL8814AU is a 4x4 MIMO (4-antenna) adapter, so its power draw and heat are far beyond a 2x2 MIMO RTL8812AU. The GPIO and 5 V/3.3 V supply rails of an IPC camera mainboard (the airborne side) usually cannot withstand the current the RTL8814AU pulls under load, which very easily causes the IPC board to reboot or the adapter to drop offline.



## ref 