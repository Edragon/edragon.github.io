
# USB-FC-trigger-dat


- [[CH224-dat]]


- [[USB-PD-dat]] - [[USB-BC-dat]]

- [[USB-FC-dat]]

## How USB Type-C 12V Fast Charging Trigger Works

A USB Type-C 12V fast charging trigger is a small device or circuit that negotiates with a USB Type-C power source (such as a charger or power bank) to output 12V instead of the default 5V. This is done using the USB Power Delivery (PD) protocol.

### Working Principle

1. **Connection & Communication**: The trigger connects to the USB Type-C port and communicates with the charger using the PD protocol over the CC (Configuration Channel) pins.
2. **Voltage Request**: It sends a request for 12V output (sometimes specifying the desired current, e.g., 1.5A or 3A).
3. **Charger Response**: If the charger supports 12V PD output, it switches its output to 12V.
4. **Power Delivery**: The trigger then provides this 12V to the connected device or circuit.

### Applications

- Powering devices that require 12V from USB Type-C chargers (DIY electronics, routers, etc.)
- Avoids the need for a dedicated 12V adapter
- Used in projects and gadgets needing higher voltage from USB-C

### Note

The trigger automatically handles the PD negotiation, making it easy to use with compatible



## ref 

- [[USB-dat]]