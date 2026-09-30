


# openHD-dat

- [[camera-digital-dat]] - [[Sigmastar-dat]] - [[openHD-dat]] - [[opensource-dat]] - [[openIPC-dat]] - [[rubyFPV-dat]]






## Overview & Hardware Guide

**OpenHD** is an open-source, long-range digital HD video transmission, telemetry, and RC control system designed for FPV drones, fixed-wing aircraft, and ground vehicles. It transforms low-cost consumer hardware into a high-performance digital FPV ecosystem.


- [[RPI-SBC-dat]] - [[RPI-zero-dat]]

### 1. Key Features

* **Digital High Definition Video**: Supports 720p and 1080p live streaming at high frame rates with low end-to-end latency.
* **Long Range & Anti-Interference**: Utilizes packet injection (via `mac80211` / custom drivers) and Forward Error Correction (FEC) over standard Wi-Fi hardware to ensure video feed continuity in poor signal conditions.
* **Unified Control & Telemetry**:
* **Telemetry**: Integrated support for MAVLink, MSP, and LTM protocols with rich On-Screen Display (OSD) overlays.
* **RC Link**: Bi-directional control link with low latency, supporting OpenTX / EdgeTX integration.
* **Audio**: Real-time mono or stereo audio streaming from the air to the ground station.


### 2. Supported Hardware & Compatibility

#### **Air Unit (Vehicle)**:
* **Raspberry Pi**: Pi 3B+, Pi 4, Pi Zero 2 W, and Compute Module 4 (CM4).
* **OpenIPC / Custom Boards**: OpenIPC-compatible IPC cameras (Sigmastar, HiSilicon) for ultralight, cheap all-in-one setups.
* **Radxa Zero / Rockchip**: Supported ARM SBCs with hardware H.264/H.265 encoding.

- [[HiSilicon-dat]] - [[Sigmastar-dat]] - [[Radxa-dat]] - [[SBC-dat]]


#### **Ground Station (Receiver)**:
* **Raspberry Pi**: Pi 4 or Pi 5 paired with supported high-power Wi-Fi adapters (e.g., RTL8812AU / RTL8812BU chipsets).
* **Android / PC App**: OpenHD app for Android tablets, phones, or PCs via USB tethering/Wi-Fi.


#### **Supported Flight Controllers**:

* ArduPilot
* Betaflight
* INav




### 3. Official Resources

* **Official Website**: [openhd.org](https://openhd.org/)
* **GitHub Organization**: [github.com/OpenHD](https://github.com/OpenHD)



## ref 

