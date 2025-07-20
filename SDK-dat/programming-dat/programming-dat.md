
# programming-dat

- [[JTAG-dat]] - [[JLINK-dat]]

- [[ISP-dat]] - [[ICP-dat]]

| Feature                    | ICP (In-Circuit Programming)                                | ISP (In-System Programming)                                    |
| -------------------------- | ----------------------------------------------------------- | -------------------------------------------------------------- |
| **Full Name**              | In-Circuit Programming                                      | In-System Programming                                          |
| **Purpose**                | Programs a microcontroller while it is still on the circuit | Programs a microcontroller without removing it from the system |
| **Connection Requirement** | Requires access to programming pins on the circuit board    | Uses standard communication interfaces (SPI, UART, etc.)       |
| **Typical Usage Stage**    | Manufacturing/test stage                                    | Field updates and development stage                            |
| **System Power**           | Often requires external programming power                   | Uses system power (target board can be powered)                |
| **Microcontroller State**  | Can be programmed even if microcontroller is blank          | Assumes microcontroller has a working bootloader or interface  |
| **Tools Used**             | Dedicated programmer/debugger (e.g., JTAG, SWD)             | On-board bootloader, or external programmer via standard I/O   |
| **Flexibility**            | Less flexible for field upgrades                            | More flexible; supports firmware updates without disassembly   |
| **Hardware Complexity**    | May require additional programming circuitry                | Minimal extra hardware required                                |
| **Examples**               | Programming via JTAG or SWD interfaces                      | Programming via USB, UART, SPI using bootloader or firmware    |

- [[hex-dat]] - [[bin-dat]]

## ICP-dat 

If ISP fails or UART is unavailable, consider using ICP via SWD with Nuvoton's Nu-Link debugger.




## Target 

### ARM 

- [[JLINK-dat]]


### AVR

- [[AVR-dat]]
  
- [[avrdude-dat]]

- [[DPR1045-dat]] - [[DPR1009-dat]]

- [[CCO3626-dat]] - [[CCO3627-dat]]