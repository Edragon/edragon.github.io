

# OSD-MSP-dat

- [[OSD-dat]] - [[OSD-MSP-dat]]

MSP-OSD


**MSP-OSD** (MultiWii Serial Protocol On-Screen Display) is a specific method used to send flight data to an on-screen display, particularly for digital FPV systems.

To understand what it is, it helps to look at how it contrasts with MAVLink:

* **MSP (MultiWii Serial Protocol):** Originally created for MultiWii and heavily used by **Betaflight** and **INAV**, MSP is a binary protocol designed for configuration and telemetry.
* **The Problem it Solved:** Digital FPV systems (like DJI FPV/O3, Walksnail Avatar, and HDZero) and digital goggles were originally built around the Betaflight/INAV ecosystem, which natively speaks MSP rather than MAVLink.
* **ArduPilot/PX4 Integration:** Autopilots like ArduPilot and PX4 (which natively run on MAVLink) added support for **MSP-OSD / MSP DisplayPort**. This allows an ArduPilot-powered drone to "translate" its telemetry into MSP packets and send them out a serial port.

### How MSP-OSD Works in Practice

1. **The Connection:** Your flight controller connects to a digital video air unit or an HD system via a UART serial port configured for MSP.
2. **DisplayPort Protocol:** Instead of just throwing raw numbers at the air unit, MSP-OSD often uses a *DisplayPort* standard where the flight controller tells the goggles exactly which characters/symbols to draw on a grid, resulting in crisp, clean OSD text and warnings on your digital screen.
3. **Cross-Platform Compatibility:** If you are running an advanced flight stack like ArduPilot (which is traditionally MAVLink-first) but want to use modern digital HD goggles that expect Betaflight-style telemetry, you enable **MSP-OSD** in your flight controller parameters so the goggles can properly render the HUD.


## ref 



