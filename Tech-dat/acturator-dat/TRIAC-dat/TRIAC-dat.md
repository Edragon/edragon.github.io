
# TRIAC-dat

## board 

- [[SCU1041-dat]]

## info 

- compare to - [[SSR-relay-dat]]


- [[Thyristor-dat]]

- **Type**: Bidirectional semiconductor device.  
- **Structure**: Basically two thyristors connected in inverse parallel in a single package.  
- **Operation**: Can conduct current in **both directions** when triggered.  
- **Turn-off**: Turns off when AC current crosses zero (natural commutation).  
- **Applications**:
  - AC light dimmers  
  - Fan speed control  
  - AC motor control  
  - Household appliance controllers  


## 3. Key Differences Table

| Feature        | Thyristor (SCR)           | TRIAC                          |
|----------------|---------------------------|--------------------------------|
| Current flow   | One direction (unidirectional) | Both directions (bidirectional) |
| Main use       | DC or controlled rectifiers | AC control (dimmers, speed control) |
| Gate trigger   | Positive gate with respect to cathode | Triggerable in both polarities |
| Structure      | PNPN (4 layers)           | Two SCRs in anti-parallel       |
| Commutation    | Needs forced or natural   | Natural at AC zero-crossing     |

---

✅ **Summary**:  
- **Thyristor = one-way switch** (mainly for DC).  
- **TRIAC = two-way switch** (mainly for AC).  





# TRIAC Comparison Table

| Feature                     | BT136                  | BTA12                  | BTA16                  | BT138                  |
|-----------------------------|------------------------|------------------------|------------------------|------------------------|
| **Maximum Voltage (V)**     | 600V                  | 600V                  | 600V                  | 600V                  |
| **Maximum Current (A)**     | 4A                    | 12A                   | 16A                   | 12A                   |
| **Gate Trigger Current (Igt)** | 5mA                  | 35mA                  | 35mA                  | 10mA                  |
| **Holding Current (Ih)**    | 2mA                   | 25mA                  | 25mA                  | 15mA                  |
| **Thermal Resistance (Rth)**| 75°C/W                | 60°C/W                | 60°C/W                | 75°C/W                |
| **Package Type**            | TO-220                | TO-220                | TO-220                | TO-220                |
| **Applications**            | General-purpose AC switching | Light dimmers, motor controls | High-power AC switching | General-purpose AC switching |



## TRIAC
A TRIAC is a bidirectional, three-electrode AC switch that allows electrons to flow in either direction. 
It is the equivalent of two SCRs connected in a reverse-parallel arrangement with gates connected to each other. A TRIAC is triggered into conduction in both directions by a gate signal like that of an SCR.

## SCR 

SCR stands for Silicon Controlled Rectifier. It is a three-terminal device that is used to control the flow of current. 




## Demo 

https://t.me/electrodragon3/198

## intro of triac 

A TRIAC (Triode for Alternating Current) is a type of semiconductor device that is used to control the flow of electrical power. It is essentially a bidirectional thyristor, meaning it can conduct current in both directions when triggered, making it particularly useful for AC (alternating current) applications.

### Key points about TRIAC:

- Bidirectional: Unlike a regular thyristor (which only conducts in one direction), a TRIAC can control the current flow in both directions, making it ideal for AC power control.
- Triggering: It can be triggered by a small current applied to its gate, after which it allows current to pass through it until the current drops below a certain threshold.
- Applications: TRIACs are commonly used in light dimmers, motor speed controls, and other devices where AC power needs to be modulated.

In short, a TRIAC is a specific type of thyristor designed for efficient AC power control.



# TRIAC 

https://www.electrodragon.com/w/Category:TRIAC

## chips 
- BT136 DS - https://www.mouser.com/datasheet/2/848/bt136-600e-1520534.pdf
- BTA16 DS - https://www.mouser.com/datasheet/2/848/BTA16-600B-1375641.pdf


## demos 

- arduino control with large triac - https://t.me/electrodragon3/198
- arduino control [[SCU1041-dat]] - https://t.me/electrodragon3/185


## thyristor = 可控硅

It is a type of semiconductor device used for controlling high-power electric signals, often in switching applications.


## MOC Triac driver 

| Feature                     | MOC3020 (Random-Phase)                                     | MOC3021 (Random-Phase)                                     | MOC3063 (Zero-Cross)                                          |
|-----------------------------|----------------------------------------------------------|----------------------------------------------------------|--------------------------------------------------------------|
| **Triggering Behavior**     | Random-phase (non–zero–cross); triggers at any point in AC cycle | Random-phase (non–zero–cross); similar to MOC3020 but optimized for lower LED drive | Zero–cross; triggers only near the AC waveform’s zero point, reducing EMI and inrush current |
| **LED Trigger Current**     | Typical trigger current ~30 mA                           | Typical trigger current ~15 mA                           | Optimized for zero–cross operation (exact value varies per datasheet)  |
| **Applications**            | Phase–control applications (lamp dimmers, motor controls) | Phase–control applications where a lower drive current is desired | AC switching (solid state relays, noise reduction, on/off control)  |
| **Isolation Voltage**       | 5,000 Vrms                                             | 5,000 Vrms                                             | 5,000 Vrms                                                  |
| **Off-State Output Voltage**| Minimum 400 V                                          | Minimum 400 V                                          | Minimum 400 V                                               |
| **dV/dt Rating**            | Typically ≥1000 V/µs                                   | Typically ≥1000 V/µs                                   | May be optimized for zero–cross switching (check datasheet for specifics) |



## unsort 

BT137-600E - 4Q Triac



## ref 

- [[acturator-dat]]