
# SBUS-dat

- [[futaba-dat]]

## 📡 What is SBUS? — Simple Explanation

**SBUS (Serial Bus)** is a digital protocol used in RC systems to send multiple control signals (channels) over a single wire.

---

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
