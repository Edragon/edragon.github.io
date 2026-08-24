
# SBUS-dat


- [[SBUS-dat]] - [[CRSF-dat]] - [[RC-protocols-dat]]

- [[futaba-dat]]

## 📡 What is SBUS? — Simple Explanation

**SBUS (Serial Bus)** is a digital protocol used in RC systems to send multiple control signals (channels) over a single wire.

What it is: SBUS is a legacy serial communication protocol originally developed by Futaba.



What it does on the FC:

- One-Way Data Flow: It acts strictly as a receive-only (RX) channel. It sends stick and switch commands from the receiver to the flight controller, but it cannot send data back.  
- Signal Type: It uses an inverted serial data stream running at 100,000 baud. On many flight controllers (especially older F4 boards), this requires a dedicated, inverted SBUS hardware pad.  
- Telemetry: SBUS natively carries no telemetry. If you want to see battery voltage, GPS coordinates, or link quality (LQ) back on your radio transmitter, you have to wire a separate telemetry wire (like SmartPort).  
- Performance: It has higher latency (typically around 14ms) and is limited to 16 channels.



### 🧩 Key Features

- 🔢 **Up to 16 channels** in one signal
- 💬 **Digital serial protocol**
- 📦 Sends data in **serial frames**
- ⏱️ **100,000 baud**, **inverted UART**
- ↪️ Invented by **Futaba**, widely used (FrSky, Radiolink, etc.)
- 🧠 Needs **inversion** to be read by normal UART (hardware or software)

---

### 🧱 Simple Analogy

> SBUS is like 16 people taking turns speaking very fast on one microphone.  
> Each frame contains all channel values packed tightly together.

---

### 🧪 Data Frame Structure

Each SBUS frame is 25 bytes:

| 1 byte | 22 bytes    | 1 byte | 1 byte |
| ------ | ----------- | ------ | ------ |
| Header | 16 channels | Flags  | End    |



- **Header**: 0x0F
- **End**: 0x00
- Sent **every ~9ms** (111Hz refresh rate)

---

### 🔌 Common Use Cases

- RC Receiver → Flight Controller (e.g., FrSky RX to Betaflight FC)
- RC Receiver → Microcontroller (Arduino, ESP32)
- RC → Servo controller boards (if SBUS supported)

---

### ⚖️ SBUS vs PWM vs PPM

| Feature       | SBUS        | PWM           | PPM           |
|---------------|-------------|---------------|---------------|
| Channels      | 16          | 1 per wire    | 8 (typically) |
| Wires needed  | 1           | 1 per channel | 1             |
| Type          | Digital     | Analog pulse  | Analog pulse  |
| Speed         | Very fast   | Slow          | Medium        |
| Latency       | Very low    | High          | Medium        |

---

### 🧰 Tip for Developers

To read SBUS using a microcontroller:
- Use **UART** at **100000 baud**, **8E2**, **inverted signal**
- Some MCUs (like ESP32) support inversion natively
- Otherwise, use an **inverter circuit** or a software decoder

## ref 

- [[network-dat]]
