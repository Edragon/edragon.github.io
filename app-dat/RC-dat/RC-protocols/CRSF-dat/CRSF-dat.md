
# CRSF-dat

CRSF (Crossfire Serial Protocol) is a low-latency, high-speed serial protocol developed by **Team BlackSheep (TBS)** for communication between radio receivers (like TBS Crossfire Nano RX) and flight controllers.

It’s used in RC applications (especially FPV drones) to transmit RC channel data, telemetry, and link status over a compact serial format.

CRSF packets are binary data. Here's the basic structure of a CRSF packet:

## CRSF Packet Structure (General)

| Byte Index | Name           | Description                                 |
|------------|----------------|---------------------------------------------|
| 0          | Device Address | Who is sending (e.g., RX, TX)               |
| 1          | Frame Length   | Length of payload + 1 (type byte + data)    |
| 2          | Frame Type     | Type of data (e.g., RC channels, telemetry) |
| 3 - N      | Payload        | Actual data, varies by Frame Type           |
| Last Byte  | CRC            | Checksum for packet validation              |


This is how a typical RC channel data packet might look (in hex):

C8 18 16 A1 84 3F C1 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 9E

## RC Channel Encoding (Packed 11-bit)

Each RC channel is packed as 11-bit little-endian integers, with up to 16 channels per frame. Example values:

- 1000 → channel center
- 172 → min
- 1811 → max

## read data via serial 

Yes, you can use a serial port to read CRSF data, because CRSF is a serial protocol — specifically, a half-duplex, asynchronous UART protocol using 8N1 (8 data bits, no parity, 1 stop bit).

### 📡 CRSF over Serial – Quick Guide

- **Baud rate**: 420000 or 115200 (depends on TX/RX version or setting)
- **Protocol**: UART (8N1)
- **Signal direction**: Half-duplex (same wire for TX and RX)
- **Voltage**: 3.3V (NOT 5V safe on most Crossfire receivers)
- **Typical usage**: Read CRSF data from TBS Nano RX or TX

#### 🧰 What You Need:
- A microcontroller or board with UART support (e.g., Arduino, ESP32, STM32, Raspberry Pi)
- Logic-level conversion (if needed for 3.3V safety)
- CRSF-compatible device (e.g., TBS Crossfire Nano RX)

Code Concept (Pseudocode)


    Serial.begin(420000); // Or 115200 for some TX modules

    void loop() {
    if (Serial.available()) {
        uint8_t byte = Serial.read();
        // Process CRSF packet bytes here
    }
    }



## via ardupilot 

If you wish to use telemetry then a receiver can be connected to a UART utilizing the CRSF protocol.

CRSF is a full-duplex protocol that supports integrated telemetry and a number of other features. Connect the RX pin of the UART to the CRSF TX pin of the CRSF device and vice versa. Currently a full-duplex UART connection is required. For best performance a UART with DMA capability on its RX port is desirable, but not required. A message will be displayed once on the GCS console, if connected to a UART without this capability on an F4/F7 based autopilot.

https://ardupilot.org/rover/docs/common-tbs-rc.html#common-tbs-rc

## ref 

- [[FPV-dat]]