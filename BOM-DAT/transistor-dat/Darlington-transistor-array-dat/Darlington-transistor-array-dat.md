
# Darlington-transistor-array-dat

## Example: Connecting a DC Motor to ULN2003

Components:

- 1x Toy DC Motor (like a 130 or 230 motor) - [[dc-motor-dat]]
- 1x [[ULN2003-dat]]
- 1x Diode-protected external power supply (e.g., 6V or 12V)
- 1x Microcontroller (e.g., Arduino)

Wiring:

1. Connect motor one end to **+V (e.g. 6V)**
2. Connect other motor end to **ULN2003 output (e.g., OUT1)**
3. Connect **IN1** of ULN2003 to your microcontroller output pin
4. Tie **GND** of ULN2003, microcontroller, and motor power supply together
5. Connect **COM pin** of ULN2003 to motor **+V** (for flyback protection diodes)

When IN1 is HIGH, the ULN2003 will pull OUT1 to GND, allowing current through the motor and it will spin.


