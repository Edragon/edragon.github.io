

# AXP853T-dat


## AXP853T Battery Support Summary

The **AXP853T does not support battery charging.** Unlike the AXP2101, which is a battery-management PMIC, the AXP853T is a **system-rail PMIC** designed to provide high-current power distribution for multi-core processors.

| Feature                | AXP853T                  | AXP2101                 |
| :--------------------- | :----------------------- | :---------------------- |
| **Integrated Charger** | **No**                   | Yes (1.5A Buck Charger) |
| **Fuel Gauge**         | **No**                   | Yes (E-Gauge™ 3.0)      |
| **Battery Pins**       | No (System VIN only)     | Yes (VBUS, BAT, TS)     |
| **Primary Focus**      | Complex Power Sequencing | Battery Life & Charging |

**Design Note:** If your project requires a battery, you must use a standalone charger IC (e.g., **TP4056** or **BQ24195**) to feed power into the AXP853T system input.



## specs 

The **AXP853T** is a highly integrated **Power Management IC (PMIC)** from X-Powers, designed for high-performance multi-core system applications. Compared to the AXP2101, the AXP853T is a more robust solution with significantly more output channels, making it suitable for complex SoC (System on Chip) environments such as industrial control, in-vehicle infotainment, and commercial displays.

### Key Specifications & Features

* **Total Power Channels**: 23 channels (including 6 DCDCs and 16 LDOs).
* **DCDC Converters (6 Channels)**:
    * **DCDC1**: 1.5V ~ 3.4V, up to 2A.
    * **DCDC2 & DCDC3**: 0.5V ~ 1.54V, up to 3.5A each (supports **Dual-phase mode** for higher current).
    * **DCDC4**: 0.5V ~ 1.54V, up to 2A.
    * **DCDC5**: 0.8V ~ 1.84V, up to 2A.
    * **DCDC6**: 0.5V ~ 3.4V, up to 2A (supports dual-phase with DCDC4).
    * **Dynamic Voltage Scaling (DVS)**: Available on DCDC2 through DCDC5.
* **LDOs & Switches (17 Channels)**:
    * **RTCLDO**: 1.8V/3.3V, 100mA (for real-time clock).
    * **ALDO (1-5)**: 0.7V ~ 3.3V, up to 600mA.
    * **BLDO (1-5)**: 0.7V ~ 3.3V, up to 600mA.
    * **CLDO (1-4)**: 0.7V ~ 4.2V, up to 300mA.
    * **CPUSLDO**: 0.7V ~ 1.4V, 200mA (Source/Sink, derived from DCDC5).
    * **Integrated Switch**: 0.1Ω internal switch for DCDC1 output (up to 1A).
* **Communication**: Uses **TWSI** (Two-Wire Serial Interface) supporting Standard (100kHz) and Fast (400kHz) modes.
* **Package**: QFN-52-EP (6mm x 6mm).



### Protection & Monitoring

The AXP853T includes comprehensive system safety features:
* **Voltage Monitoring**: Over-Voltage (OVP) and Under-Voltage (UVP) protection.
* **Thermal Management**: Built-in temperature sensor with Over-Temperature Protection (OTP).
* **Customization**: Supports user-defined start-up sequences and default voltages for specific SoC requirements.

### Comparison: AXP853T vs. AXP2101

| Feature              | AXP2101                 | AXP853T                         |
| :------------------- | :---------------------- | :------------------------------ |
| **Total Channels**   | 15                      | 23                              |
| **DCDC Rails**       | 4                       | 6                               |
| **Max DCDC Current** | 2A                      | 3.5A (Dual-phase support)       |
| **Primary Use**      | Portable/IoT devices    | Multi-core SoCs / Industrial    |
| **Charging**         | Integrated 1.5A charger | Specialized for rail management |



## ref 

