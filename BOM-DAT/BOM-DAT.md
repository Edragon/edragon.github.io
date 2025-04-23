

# BOM-dat

The common bom we hosted 

https://www.electrodragon.com/w/RCL_List

## passive

- [[diode-dat]] - [[tvs-dat]] - [[transistor-dat]] - [[mosfet-dat]] - [[capacitor-dat]] - [[inductor-dat]]

- [[Ferrite-Bead-dat]]

## Chip 

- [[chip-dat]] - [[chip-cn-dat]]

- [[PL2303-DAT]]


## Chip-CN
- [[WCH-DAT]] - [[ESP32-dat]] - [[ESP8266-DAT]]

- [[BTB-dat]]

- [[optocoupler-dat]]



## CONN

- [[CONN-dat]] - [[DB9-dat]] - [[JST-dat]]


## other components

- [[battery-dat]] - [[high-power-led-dat]]

- [[infrared-dat]] - [[LDO-dat]]

## generate footprint descriptions 

CAP 4.7UF, 0805, 10%, MLCC, 50V, X5R, ROHS

RES 1K 5%, 0805, THICK FILM, 150V, 1/8W, ROHS

Here's a breakdown of the structure:

- CAP/RES: Component Type (Capacitor or Resistor)
- 4.7UF/1K: Value (4.7 Microfarads or 1 Kiloohm)
- 0805: Package Size (0805 is a standard SMD package size)
- 10%/5%: Tolerance (10% or 5% variation in value)
- MLCC/THICK FILM: Technology or Type (Multi-Layer Ceramic Capacitor or Thick Film Resistor)
- 50V/150V: Voltage Rating (50 Volts or 150 Volts)
- X5R: Dielectric (Specific to capacitors, defines temperature characteristics)
- 1/8W: Power Rating (1/8 Watt, specific to resistors)
- ROHS: RoHS Compliant (Restriction of Hazardous Substances)

LED SMD VERMELHO, 0805, 2V, 25MA, 624NM, 60MCD, 140°, ROHS

- "VERMELHO" is Portuguese for red.
- 624nm wavelength corresponds to red light on the visible spectrum.
- Other details like 2V, 25mA, and 60mcd just describe electrical and luminous specs.

### Electronic Industries Alliance (EIA)


EIA 3528-21 Meaning

| Section | Description                                                                                                     |
| ------- | --------------------------------------------------------------------------------------------------------------- |
| 3528    | Physical size of the component in hundredths of inches: 3.5 mm x 2.8 mm (i.e., 0.138" x 0.110")                 |
| -21     | Indicates a specific height and pad layout variation within the 3528 size range. Typically means ~2.1 mm height |


CRISTAL 12MHz, SMD, 3.2X2.5MM, 18PF, 20PPM, ROHS

This corresponds to the standard 3225 SMD package (also known as EIA 3225 or 3.2x2.5mm SMD crystal).

### IND FILTRO MODO COMUM,100uH,+50/-30%,0.2A,7.5k/10MHz,1812,RO

| Term                      | Meaning                                                                              |
| ------------------------- | ------------------------------------------------------------------------------------ |
| **IND FILTRO MODO COMUM** | Common Mode Filter Inductor — used to suppress EMI/RFI by blocking common-mode noise |
| **100µH**                 | Inductance value: 100 microhenries (μH)                                              |
| **+50/-30%**              | Tolerance range: +50% to -30%                                                        |
| **0.2A**                  | Maximum rated current: 0.2 Amps (200mA)                                              |
| **7.5k/10MHz**            | Impedance: 7.5 kΩ at 10 MHz — blocks high-frequency noise effectively                |
| **1812**                  | Package size: 1812 (0.18" x 0.12" or 4.6 mm x 3.2 mm) SMD footprint                  |
| **RO**                    | RoHS compliant (lead-free and environmentally safe)                                  |

## IND FILTRO MODO COMUM, 4A, 700Ω/100MHz, 2824, ROHS

| Term                      | Meaning                                                                 |
|---------------------------|-------------------------------------------------------------------------|
| **IND FILTRO MODO COMUM** | Common Mode Filter Inductor — used to suppress EMI/RFI by blocking common-mode noise |
| **4A**                    | Maximum current: 4 Amps — suitable for high-current applications         |
| **700Ω / 100MHz**         | Impedance: 700 ohms at 100 MHz — blocks high-frequency noise effectively |
| **2824**                  | Package size: 2824 (7.1 mm × 6.0 mm) — Surface Mount Device (SMD)       |
| **ROHS**                  | RoHS compliant — lead-free and environmentally safe                      |



## 0.8-6P-Pitch Type C vertical WTB capping

| Term             | Meaning                                                                 |
|------------------|-------------------------------------------------------------------------|
| **0.8**          | Pitch: 0.8 mm — distance between adjacent pins                          |
| **6P**           | 6 Pins — total number of electrical contacts                            |
| **Pitch Type C** | Likely refers to a connector family/style (Type C) with a specific profile or housing style |
| **Vertical**     | Vertical mount orientation on the PCB                                   |
| **WTB**          | Wire-to-Board — used to connect cables/wires directly to a PCB          |
| **Capping**      | May include a top-entry cap, locking feature, or closed housing design  |



## ref 

- [[BOM]]