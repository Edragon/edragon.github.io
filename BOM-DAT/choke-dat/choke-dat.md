

# choke-dat


## common mode choke

- [[CR6842-dat]] - [[chip-rail-dat]] - [[AC-mains-dat]]

This is the `common mode choke` at the AC input of the ACDC power board, in a very standard position:

- [[AC-mains-dat]] - [[ACDC-dat]]

Its role in the circuit:
1. Suppress common mode noise — filter common mode EMI between the mains and the power board
2. Bidirectional filtering — prevents switching noise from the board from propagating back to the mains (conducted emission), and also prevents mains noise from entering the power supply
3. Interference isolation — presents low impedance to differential mode signals (current between L/N lines) without affecting power delivery, but exhibits high impedance to common mode noise (interference where L/N currents are in phase)

## ref 

