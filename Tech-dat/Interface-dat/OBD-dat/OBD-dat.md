
# OBD-dat

OBD stands for On-Board Diagnostics. It's a system in modern vehicles that monitors the engine and other vehicle systems. When it detects a problem, it turns on the "check engine" or "service engine soon" light on your dashboard and stores a diagnostic trouble code (DTC) that identifies the issue. This helps technicians diagnose and repair problems more easily.

## OBD-II Pinout (SAE J1962 Connector)

| Pin | Description                       |
| --- | --------------------------------- |
| 1   | Manufacturer specific             |
| 2   | SAE J1850 Bus+ (PWM/VPW)          |
| 3   | Manufacturer specific             |
| 4   | Chassis Ground                    |
| 5   | Signal Ground                     |
| 6   | CAN High (ISO 15765-4)            |
| 7   | K-Line (ISO 9141-2 / ISO 14230-4) |
| 8   | Manufacturer specific             |
| 9   | Manufacturer specific             |
| 10  | SAE J1850 Bus- (PWM only)         |
| 11  | Manufacturer specific             |
| 12  | Manufacturer specific             |
| 13  | Manufacturer specific             |
| 14  | CAN Low (ISO 15765-4)             |
| 15  | L-Line (ISO 9141-2 / ISO 14230-4) |
| 16  | Battery Voltage (+12V)            |

## the pins in the OBD-II connector related to J1850 are:

Pin 2 (SAE J1850 Bus+): Carries the signal for both PWM and VPW protocols.
Pin 10 (SAE J1850 Bus-): Used only for the PWM protocol (Ford).

## K-line and L-line

The K-Line (Pin 7) and L-Line (Pin 15) are communication lines used by the ISO 9141-2 and ISO 14230-4 (KWP2000) diagnostic protocols. These protocols were common in European, Asian, and some Chrysler vehicles before CAN bus became standard.

- K-Line (Pin 7): This is the primary bidirectional serial communication line. Diagnostic tools use this line to send requests to and receive data from the vehicle's electronic control units (ECUs).
- L-Line (Pin 15): This is an optional unidirectional line primarily used for initialization or "waking up" the ECUs before communication starts on the K-Line. Not all vehicles using K-Line implement or require the L-Line, especially those using the later KWP2000 protocol.

In essence:

- K-Line: Does the main talking (sending and receiving data).
- L-Line: Sometimes used to start the conversation (initialization).


## ref 

- [[CAN-dat]] - [[SAEJ1850-dat]]