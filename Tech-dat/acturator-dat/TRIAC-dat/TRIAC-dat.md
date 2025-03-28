
# TRIAC-dat

- compare to - [[SSR-relay-dat]]



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
