

# USB-blaster-dat


- [[cypress-dat]] - [[Infineon-dat]] - [[pins003-dat]] - [[MCU-dat]]

- [[app-dat]] - [[logic-analyzer-dat]] - [[USB-blaster-dat]] - [[data-acquisition-board-dat]] - [[PINS003-dat]]

- [[JLINK-dat]] - [[FPGA-dat]] - [[CPLD-dat]] - [[Altera-dat]] - [[intel-dat]]


A **USB Blaster** is a hardware programming adapter used to download configuration data, program code, and firmware from a computer onto programmable logic devices—specifically **FPGAs** (Field Programmable Gate Arrays) and **CPLDs** (Complex Programmable Logic Devices). 

Originally developed by Altera (now Intel Programmable Solutions Group), it serves as a bridge between your development machine and the target hardware. 

---

## How It Works
When developing firmware or hardware layouts in design software (like Intel Quartus Prime), the code needs a way to physically reach the chip. The USB Blaster hooks into a standard USB port on your PC and translates those signals into protocol-specific data streams that the target chip understands.

It typically supports three communication protocols:
*   **JTAG (Joint Test Action Group):** The standard protocol used for programming, debugging, and testing FPGAs.
*   **Passive Serial:** Used to send configuration data to an external configuration device or directly to the FPGA during development.
*   **Active Serial:** Used to program non-volatile flash memory chips directly on the circuit board, ensuring the device retains its program even after it loses power.

## Physical Connection
A standard setup consists of a small plastic enclosure with two primary ports:
1.  **A USB Interface:** Connects to the host computer using a standard USB cable.
2.  **A 10-Pin Header:** Connects to the target printed circuit board via a flat ribbon cable. This header plugs into a matching male pin header on the development board, routing the essential power, ground, and data tracking lines (`TDI`, `TDO`, `TMS`, `TCK`) to the chip.

While official enterprise versions exist, the market is filled with low-cost "USB Blaster clones" built around basic microcontrollers. These clones function identically in development software, making them standard tools for hardware hacking, prototyping, and embedded engineering.


## ref 

