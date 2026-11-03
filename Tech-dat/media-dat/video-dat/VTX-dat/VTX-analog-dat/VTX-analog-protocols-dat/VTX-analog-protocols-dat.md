


# VTX-analog-protocols-dat

- [[VTX-dat]] - [[blackbox-dat]] - [[OSD-dat]] - [[betaflight-ports-dat]] - [[VTX-analog-protocols-dat]]


## Comparison of FPV Control and OSD Protocols: IRC Tramp, SmartAudio, MSP, Displayport, and MSP SmartAudio

In FPV (First-Person View) drones and model aircraft, **VTX (Video Transmitter) control protocols** and **OSD (On-Screen Display) protocols** enable seamless communication between the flight controller (FC) and the video transmitter or digital high-definition system. They eliminate the need to manually press tiny physical buttons on hardware components, allowing pilots to adjust parameters directly via radio transmitters, goggles, or ground station menus.



### 1. SmartAudio (SA)
* **Origin & Maintainer**: Developed and maintained by **TBS (Team BlackSheep)**.
* **Key Characteristics**:
  * One of the most popular and widely adopted analog VTX control protocols (found on TBS Unify series, Rush Tank, AKK, and various modern VTXes).
  * Uses **single-wire half-duplex communication** (connected to an FC **TX** UART pad).
  * Has evolved through multiple versions (SA 1.0, 2.0, 2.1 / SA Lite), transitioning from proprietary power indices to standardized **dBm** power levels.
  * Requires correct **VTX Tables** in flight controller firmwares (such as Betaflight) to accurately map channels, bands, and power output.

### 2. IRC Tramp / Tramp Telemetry
* **Origin & Maintainer**: Developed by **ImmersionRC**.
* **Key Characteristics**:
  * Historically the main counterpart to TBS SmartAudio in the analog VTX ecosystem.
  * Also utilizes a **single-wire serial connection** to an FC **TX** pad.
  * Differs from SmartAudio in its underlying command architecture, packet structure, and frequency definition.
  * Tramp natively transmits precise frequency values in MHz, making it heavily supported across third-party hardware (like Holybro Atlatl and various Matek models).

### 3. MSP (MultiWii Serial Protocol)
* **Origin & Maintainer**: Originating from the MultiWii project, MSP serves as the foundational bidirectional serial communication protocol between flight controllers and configuration software (e.g., Betaflight Configurator, mobile apps).
* **Key Characteristics**:
  * **Not strictly a VTX protocol**, but a comprehensive flight controller telemetry and configuration protocol handling PID tuning, sensor stats, and GPS data.
  * Early digital high-definition systems (such as the original DJI FPV Air Unit and HDZero) leveraged MSP to feed flight metrics and OSD updates back and forth between the air unit and flight controller.

### 4. Displayport (MSP Displayport)
* **Origin & Function**: Often referred to simply as **Displayport**, this protocol is the standard mechanism used by **digital HD systems** (such as DJI O3/newer DJI systems, Walksnail Avatar, and HDZero) to handle OSD overlays.
* **Key Characteristics**:
  * Operates over a bidirectional UART link using an extension of the MSP protocol.
  * Pushes the flight controller's rendered OSD elements, layout graphics, and font bitmaps directly into the digital video stream for high-definition viewing.
  * Focuses purely on **rendering graphical OSD data**, distinct from modifying RF radio frequency power parameters.

### 5. MSP SmartAudio
* **Origin & Function**: A hybrid or virtualized bridging method used in modern integrated digital systems and specialized hardware setups.
* **Key Characteristics**:
  * Encapsulates traditional SmartAudio commands inside an **MSP data tunnel** across the digital link or specialized VTX architecture.
  * Allows ground stations and configuration tools designed around classic SmartAudio workflows to control compatible hardware seamlessly via a unified digital MSP connection.


### Summary and Comparison Table

| Protocol Name | Primary Use Case | Hardware Connection | Core Function |
| :--- | :--- | :--- | :--- |
| **SmartAudio** | Traditional Analog VTX (TBS/Rush, etc.) | FC TX pad (Single wire) | Configures analog VTX band, channel, and power levels |
| **IRC Tramp** | Traditional Analog VTX (ImmersionRC, etc.) | FC TX pad (Single wire) | Configures analog VTX frequency and power using alternate packet definitions |
| **MSP** | Flight controller telemetry, general configuration, and legacy digital links | Bidirectional UART (TX/RX) | General system status, sensor streaming, and bidirectional configuration |
| **Displayport** | Digital HD Video Systems (DJI/Avatar/HDZero) | Bidirectional UART (TX/RX) | Streams FC-generated OSD graphics and text elements to digital goggles |
| **MSP SmartAudio** | Modern integrated systems / specialized digital VTX | Underlying MSP link | Tunnels SmartAudio control structures over an MSP framework |





## ref 



