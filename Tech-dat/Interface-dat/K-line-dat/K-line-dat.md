

# K-line-dat

- [[CAN-dat]] - [[K-line-dat]] - [[OBD-dat]]

## ISO 9141-2 (K-Line) Protocol Overview

**ISO 9141-2** is a diagnostic communication protocol primarily used in European and Asian vehicles manufactured between the late 1990s and the mid-2000s. It is the "language" used by an OBD-II scanner to talk to the Engine Control Unit (ECU).

### 1. Physical Layer & Pins
The protocol relies on a single-wire or dual-wire serial bus found on the standard 16-pin OBD-II connector:

* **K-Line (Pin 7):** The bidirectional line used for all data exchange (queries and responses).
* **L-Line (Pin 15):** An optional unidirectional line used only for "waking up" the system in older implementations.



---

### 2. Key Technical Specifications
* **Signaling:** Asynchronous serial communication (UART).
* **Voltage Levels:** Based on the vehicle battery (0V for Logic Low, 12V for Logic High).
* **Baud Rate:** Usually fixed at **10.4 kbps**.
* **Initialization:** Requires a specific "5-baud init" (very slow pulse) or a "Fast Init" sequence to establish a handshake before data flows.

---

### 3. Comparison with Modern CAN Bus
| Feature          | ISO 9141-2 (K-Line)             | ISO 15765 (CAN Bus)      |
| :--------------- | :------------------------------ | :----------------------- |
| **Data Speed**   | 10.4 kbps                       | 500 kbps                 |
| **Architecture** | Master-Slave (Request/Response) | Multi-Master (Broadcast) |
| **Typical Era**  | 1996 – 2007                     | 2008 – Present           |
| **Hardware**     | Single wire (K)                 | Twisted pair (High/Low)  |

---

### 4. Implementation for DIY Projects
Since you are familiar with **motor drivers** and **IMU sensors**, you can think of the K-Line as a standard UART signal shifted to 12V. 

If you wanted to interface a 3.3V microcontroller (like an ESP32) with a car's K-Line, you cannot connect them directly. You would need a **Level Shifter** or a dedicated K-Line transceiver chip (such as the **L9637D** or **MC33660**) to handle the 12V swings without frying your MCU.



