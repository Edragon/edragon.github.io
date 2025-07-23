
# fiber-optic-serial-dat

# Sending UART Serial Data over Plastic Optical Fiber (POF)

Using plastic optical fiber (POF) to transmit UART serial data provides EMI resistance and electrical isolation. Here's how to do it:

---

## 🧰 What You Need

1. **Plastic Optical Fiber (POF)** – typically 1mm core, 650nm red LED compatible.
2. **Optical Transceivers** – e.g., Avago HFBR-1521 (TX) and HFBR-2521 (RX)
3. **Microcontrollers or USB-to-UART adapters**
4. **Resistors and capacitors** – per the transceiver datasheet
5. **Logic level shifters** – if voltage levels don't match

---

## 🔌 Basic Wiring Overview

### TX Side (UART → Optical)
- Microcontroller UART TX → Optical Transmitter (e.g., HFBR-1521)
- Power (3.3V or 5V)
- Current-limiting resistor for LED (per datasheet)

### RX Side (Optical → UART)
- Optical Receiver (e.g., HFBR-2521) → UART RX
- Power supply
- Pull-up resistor on RX output (if open collector)

---

## 🛠️ Wiring Example with HFBR-15X1 / 25X1

- **TX Module (HFBR-1521)**:
  - Anode → Vcc through resistor
  - Cathode → UART TX (possibly via transistor)

- **RX Module (HFBR-2521)**:
  - Output → UART RX with pull-up resistor to Vcc

> ⚠️ Note: These modules output non-inverted logic compatible with UART.

---

## ⚙️ UART Settings

- Baud Rate: up to **250 kbps** recommended for stable operation
- Settings: Standard 8N1 (e.g., 9600 8N1)

---

## 📏 Max Transmission Distance

- Up to **20 meters** for typical POF setups

---

## 🧪 Testing

- Connect USB-to-UART adapter to one side, microcontroller or another adapter to the other
- Use serial terminal (PuTTY, Arduino IDE, etc.) to send test messages
- Perform loopback or echo tests

## ref 

- [[fiber-optic-serial]] - [[fiber-optic]]

- [[fiber-optic-app-dat]]