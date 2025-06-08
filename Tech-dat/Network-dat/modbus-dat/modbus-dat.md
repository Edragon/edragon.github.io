
# modbus-dat

## Modbus: An Overview

Modbus is a serial communication protocol originally published by Modicon (now Schneider Electric) in 1979 for use with its programmable logic controllers (PLCs). It has since become a de facto standard communication protocol in industry and is now one of the most commonly available means of connecting industrial electronic devices.

**Purpose:** Modbus is typically used for transmitting information over serial lines or Ethernet between electronic devices. The device requesting the information is called the Modbus Master (or Client), and the devices supplying information are Modbus Slaves (or Servers). In a standard Modbus network, there is one Master and up to 247 Slaves, each with a unique Slave Address from 1 to 247.


## How Modbus Works

Modbus communication is based on a master-slave (or client-server in Modbus TCP/IP) architecture.

1.  **Master-Slave Architecture:**
    *   **Master (Client):** Initiates communication. It sends a request (a "query") to a specific slave device. Only one master can initiate communication at a time on a Modbus serial line.
    *   **Slave (Server):** Responds to requests from the master. It performs the action requested by the master (e.g., read data, write data) and sends a response back. Slaves do not initiate communication; they only respond.

2.  **Communication Layers & Variants:**
    Modbus has different variants depending on the communication layer:
    *   **Modbus RTU (Remote Terminal Unit):** This is the most common implementation and uses serial communication (typically RS-485, but also RS-232 or RS-422). Data is transmitted in a binary format. It includes a Cyclic Redundancy Check (CRC) for error detection.
    *   **Modbus ASCII:** Also uses serial communication but transmits data as ASCII characters. This makes it more human-readable but less efficient than RTU. It uses a Longitudinal Redundancy Check (LRC) for error detection.
    *   **Modbus TCP/IP (or Modbus TCP):** This variant is used for communications over TCP/IP networks (like Ethernet). It encapsulates Modbus RTU messages within a TCP/IP wrapper. It doesn't require a checksum as TCP/IP already handles error checking. This allows for communication over standard Ethernet networks and the internet.
    *   **Modbus Plus (MB+):** A proprietary, higher-speed, token-passing network developed by Modicon. Less common now.

3.  **Data Representation (Data Model):**
    Modbus defines a simple data model consisting of four primary data types or tables that can be accessed in the slave device:
    *   **Coils (Discrete Outputs):** 1-bit read/write values. These typically represent on/off states (e.g., a relay, a lamp).
    *   **Discrete Inputs:** 1-bit read-only values. These typically represent digital inputs (e.g., a switch status).
    *   **Input Registers:** 16-bit read-only values. These typically represent analog inputs or other measured data from sensors.
    *   **Holding Registers:** 16-bit read/write values. These can be used for various purposes, such as configuration parameters, setpoints, or general data storage.

    Each of these data types is addressed from 0 to 65535.

4.  **Message Structure (PDU and ADU):**
    A Modbus message frame consists of two main parts:
    *   **PDU (Protocol Data Unit):** This is independent of the underlying communication layer. It contains:
        *   **Function Code (1 byte):** Specifies the action to be performed (e.g., read coils, write holding register).
        *   **Data (N bytes):** Contains the actual data for the request or response (e.g., starting address, number of registers, register values).
    *   **ADU (Application Data Unit):** This includes the PDU plus additional information specific to the communication layer:
        *   **For Modbus RTU/ASCII (Serial):**
            *   **Slave Address (1 byte):** The address of the slave device the message is intended for (or from).
            *   **PDU**
            *   **Error Check (2 bytes for CRC in RTU, 1 byte for LRC in ASCII):** For detecting transmission errors.
        *   **For Modbus TCP/IP:**
            *   **MBAP Header (Modbus Application Protocol Header - 7 bytes):** Contains a transaction identifier, protocol identifier, length field, and unit identifier (similar to slave address).
            *   **PDU**

5.  **Communication Flow (Example - Read Holding Registers):**
    1.  **Master Sends Request:**
        *   Slave Address (e.g., 01)
        *   Function Code (e.g., 03 for Read Holding Registers)
        *   Starting Address of Registers (e.g., 00 6B for register 40108)
        *   Number of Registers to Read (e.g., 00 02 for 2 registers)
        *   Error Check (CRC)
    2.  **Slave Processes Request:** The slave device with the specified address receives the request, validates it, and retrieves the requested data.
    3.  **Slave Sends Response:**
        *   Slave Address (e.g., 01)
        *   Function Code (e.g., 03)
        *   Byte Count (number of data bytes to follow, e.g., 04 for 2 registers * 2 bytes/register)
        *   Register Values (e.g., 02 2B for the first register, 00 00 for the second)
        *   Error Check (CRC)
    If an error occurs (e.g., invalid address, invalid function code), the slave responds with an exception code.

6.  **Common Function Codes:**
    *   `01 (0x01)`: Read Coils
    *   `02 (0x02)`: Read Discrete Inputs
    *   `03 (0x03)`: Read Holding Registers
    *   `04 (0x04)`: Read Input Registers
    *   `05 (0x05)`: Write Single Coil
    *   `06 (0x06)`: Write Single Holding Register
    *   `15 (0x0F)`: Write Multiple Coils
    *   `16 (0x10)`: Write Multiple Holding Registers

## Key Characteristics & Advantages:

*   **Simplicity:** The protocol is relatively simple to implement and understand.
*   **Open Standard:** It's an open protocol, meaning manufacturers can build it into their equipment without paying royalties.
*   **Widely Adopted:** Supported by a vast range of industrial devices from many different vendors.
*   **Flexibility:** Can be used over various physical layers (serial, Ethernet).
*   **Reliability:** Error checking mechanisms (CRC/LRC) are built-in for serial versions.

## Common Use Cases:

*   Connecting SCADA, HMI (Human-Machine Interface) systems to PLCs and other industrial devices.
*   Reading sensor data (temperature, pressure, flow, level).
*   Controlling actuators (valves, motors).
*   Monitoring and configuring device parameters.
*   Data logging.
*   Building automation.
*   Energy monitoring.
*   

