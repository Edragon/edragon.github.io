# PNP Machine Data

- [[openpnp-dat]] - [[PNP-machine-dat]] - [[fab-PNP-machine-dat]]






## Overview

### Open Source Options

- [[openpnp-dat]] - [[PixiePlacer-dat]]

### Commercial Options

- [[lumenpnp-dat]]

### Related Knowledge

- [[PCB-dat]] - [[EDA-dat]] - [[pnp-machine-software-dat]] - [[serial-dat]]



### Hardware Components

- [[vacuum-pump-dat]] - [[motor-dat]] - [[sensor-Camera-dat]] - [[vision-dat]] - [[pnp-header-dat]] - [[XYZ-frame-dat]]



## BOM Overview

- **Key Components**: [[nozzle-dat]], [[feeder-dat]], [[XYZ-frame-dat]]

## Electronics

- [[Pick-and-place-dat]]

---

## Basic Concepts ⚡⚡

### Single Board
A physical entity consisting of a PCB and its mounted components. The software supports placing components on both sides (Top and Bottom).

### CSV Coordinate File
A file exported from EDA software and imported into the PNP software. Must be in CSV format. Supported tools include:
- Altium Designer (AD)
- KiCad
- LCEDA (EasyEDA)
- Allegro
*(Other formats can be adapted upon request.)*

### Panelization
The process of assembling multiple small PCBs into a single larger array for easier production.

### PCB Origin
The reference zero-point defined during PCB design. This point should be located within the PCB's physical frame.

### Fiducials (MARK Points)
[Fiducials](#) (or [[mark-point-dat]]) are markers on the PCB or panel used by the machine's vision system to accurately locate the board. They are typically small circular pads with a large keep-out area and no solder paste.

### Components
Specific parts (e.g., Manufacturer Part Numbers) to be placed. Components with different values (e.g., 10k vs 22k resistor) are treated as distinct entities, even if they share the same package.

### Package
Describes the physical footprint (length, width, etc.) of a component. Multiple components often share the same package (e.g., 0603, SOIC-8).
In the software, packages are used to:
1. Assign the correct **Nozzle** type.
2. Provide dimensions for **Vision Analysis** of larger parts.

### Crosshairs
Visual overlays (crosses or shapes) on the camera feed to indicate the alignment center.

### Bottom Vision
The upward-facing camera used to inspect components for alignment and defects before placement, significantly increasing accuracy.

### Top Vision
The downward-facing camera mounted on the head. It identifies fiducials and locates components within feeders.

### Feeders
Hardware that supplies components to the machine. Supports:
- Automatic Feeders
- Cut Tape Feeders
- Visual Loose Components
- Tray Feeders
*(Custom feeder types can also be integrated.)*



## ref 

- [[pnp-machine]]