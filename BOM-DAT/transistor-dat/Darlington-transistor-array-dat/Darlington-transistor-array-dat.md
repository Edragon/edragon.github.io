
# Darlington-transistor-array-dat



## ULN2804 

The ULN2804 is an integrated circuit containing eight high-voltage, high-current NPN Darlington transistor pairs. It handles up to 500 mA per channel and 50V outputs, optimized with built-in clamp diodes to drive heavy peripheral loads like relays, stepper motors, and LED displays from 6V to 15V CMOS logic.

	
Bipolar (BJT) Transistor Array 8 NPN Darlington 50V 500mA 2.25W Through Hole 18-DIP

- [[ST-dat]] - [[Darlington-transistor-array-dat]] - [[motor-driver-dat]]




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


## ref 


