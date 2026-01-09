
# wiegand-dat

- [[wiegand-dat]] [[Wiegand-26-dat]] - [[Wiegand-34-dat]] - [[Wiegand-37-dat]]


A **Wiegand device** typically refers to a component in an access control system that uses the **Wiegand interface** to communicate. This interface is a de facto standard for transmitting data from a card reader (like those for ID badges) to an access control panel.

Key characteristics:
*   **Data Lines:** Uses two data lines, typically DATA0 (D0) and DATA1 (D1).
*   **Signaling:** A pulse on D0 represents a binary '0', and a pulse on D1 represents a binary '1'.
*   **Format:** Data is sent in a specific bit format (e.g., 26-bit Wiegand is common, but many others exist), which includes parity bits, facility codes, and card numbers.
*   **One-Way Communication:** It's generally a one-way communication from the reader to the controller.
*   **Physical Layer:** Originally based on the Wiegand effect in specially prepared wires, though modern readers often emulate this electrical interface.

In short, it's the technology that allows a card reader to send identification data to a control panel to grant or deny access.



## ref 

- [[rfid-dat]]