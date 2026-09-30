
# SBUS-dat


- [[SBUS-dat]] - [[CRSF-dat]] - [[RC-protocols-dat]]

- [[futaba-dat]]


Cause B: Analog RSSI Wire is Missing or Misconfigured
If you are using an older receiver (like FrSky ACCST/SBUS) that uses a dedicated analog RSSI wire:

Check if the physical RSSI wire is soldered from the receiver's RSSI pad to an RSSI/ADC pad on the flight controller.

Go to the Ports tab in Betaflight and ensure the correct settings are applied, or go to the Configuration tab and check "RSSI ADC Analog".


## RSSI 

- [[FHSS-dat]] - [[RSSI-dat]] - [[SBUS-dat]] - [[RC-protocols-dat]]

Since you are using an **FHSS / SBUS** receiver and do not have a physical analog RSSI wire, you can still get RSSI to work. **SBUS** can carry RSSI data embedded directly as a channel in the digital data stream.

Here is how to set it up:

Step 1: Check/Set RSSI on your Radio (OpenTX / EdgeTX)
Most traditional SBUS receivers (like FrSky XM+ or R-XSR) automatically output RSSI on Channel 16.

Go to your Radio's Mixes page.

Check if CH16 is assigned to RSSI (on many setups, this is handled automatically by the receiver firmware, but verify your radio model settings).

Step 2: Configure RSSI in Betaflight
Connect your flight controller to Betaflight Configurator.

Go to the Receiver tab.

Locate the RSSI Channel dropdown menu:

Change it from Disabled to the corresponding auxiliary channel.

Since Channel 1-4 are your main sticks (Throttle, Roll, Pitch, Yaw), Channel 16 usually maps to AUX 12 in Betaflight.

Test it: Turn off your radio or walk away slightly and watch if the channel bar moves or if the RSSI value changes.

Click Save and Reboot.

Step 3: Verify the OSD Element
Go to the OSD tab in Betaflight.

Ensure you have the standard RSSI Value element enabled on your screen.

Save your settings.

Because the RSSI data is now correctly mapped from the SBUS stream to the RSSI channel in Betaflight, the "no data" error will disappear.





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
