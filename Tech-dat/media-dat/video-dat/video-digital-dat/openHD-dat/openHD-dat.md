


# openHD-dat

- [[camera-digital-dat]] - [[Sigmastar-dat]] - [[openHD-dat]] - [[opensource-dat]] - [[openIPC-dat]] - [[rubyFPV-dat]]




## Overview
**Ruby FPV** is a high-performance open-source digital video transmission (VTX) and telemetry platform built for FPV drones, fixed-wing aircraft, and rovers.

## Key Highlights
- **Ultra-Low Latency:** High frame rates (up to 120fps) designed for rapid response in fast-paced flight.
- **Robust Link Resilience:** Built-in forward error correction (FEC) and adaptive algorithms to resist radio interference.
- **All-in-One Integration:** Handles HD video, telemetry (MAVLink, MSP, LTM), and RC control link over a single digital connection.

## Hardware & Software Ecosystem
- **Supported Hardware:** Raspberry Pi, Rockchip SoCs, and OpenIPC modules.
- **Flight Controllers:** ArduPilot, Betaflight, INav, and CubePilot.

- [[betaflight-dat]]

## Official Resources
- **Website:** [rubyfpv.com](https://rubyfpv.com/)
- **GitHub:** [github.com/RubyFPV](https://github.com/RubyFPV/)



Building an affordable and straightforward Ruby FPV setup relies on pairing a cost-effective, all-in-one OpenIPC camera on the aircraft with a standard Raspberry Pi on the ground station.


1. Air Unit (On the Drone / Vehicle)

- [[Sigmastar-dat]] - [[SSC338-dat]]


Hardware: OpenIPC / Sigmastar (e.g., SSC338Q or similar SStar) camera module.

Benefits:

Integrates the processor, video sensor (often Sony sensors), and Wi-Fi interface into a single tiny, lightweight board.

No separate single-board computer needed on the drone.

Flashes directly onto onboard storage (no flight-risk micro-SD cards on the airframe).

Very cost-effective compared to older Raspberry Pi air units.

1. Ground Station / Receiver (Ground Unit)
Hardware: Raspberry Pi 4 (or Pi 3 / Pi Zero 2 W depending on budget and display needs) paired with a supported high-power Wi-Fi/radio USB adapter.

Benefits:

Fully supported and natively documented within the Ruby FPV ecosystem.

Easy installation: Flash the Ruby ground controller image onto an SD card.

Connects to a standard HDMI screen or FPV goggles with HDMI-in, plus inexpensive push buttons for the on-screen menu.

3. Power & Connectivity Essentials
Power Supply: A clean 5V BEC / regulator (minimum 2A–3A output) to step down flight battery voltage safely.

Telemetry Connection: Simple 3-wire UART connection from the OpenIPC air unit to your flight controller (ArduPilot / Betaflight / INav) for MAVLink or MSP telemetry.

Why This Setup Works Best
Minimal Soldering & Wiring: Combines camera and computer into one tiny package on the drone.

Automated Ecosystem: Ruby's firmware natively supports OpenIPC hardware, drastically reducing manual configuration hurdles.


## ref 

