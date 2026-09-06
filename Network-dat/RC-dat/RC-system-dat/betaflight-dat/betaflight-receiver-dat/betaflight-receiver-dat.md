
# betaflight-receiver-dat

- [[betaflight-dat]] - [[betaflight-receiver-dat]] - [[betaflight-modes-dat]]

- [[radiomaster-dat]]


### Telemetry

TELEMETRY - Telemetry output

### RSSI 

Analog RSSl input == on or off

RSSIChannel == disabled or AUX1 .. AUX12?


### 1. Analog RSSI Input (ON or OFF)
* **What it does**: Tells the flight controller whether to look for a physical analog DC voltage signal (ranging from 0V to 3.3V) wired into a dedicated analog RSSI pad on the board.
* **When to set to OFF (Recommended for 99% of modern setups)**: If you use modern serial receivers like **ExpressLRS (ELRS)**, Crossfire, or modern FrSky/FlySky protocols connected via a serial port (UART), your signal strength (RSSI) is already transmitted digitally through the serial data stream. You must keep this **OFF**.
* **When to set to ON**: Only if you are using an extremely old-school PWM or PPM receiver that features a physical analog RSSI wire connected to an analog-to-digital converter (ADC) pad on the flight controller.

---

### 2. RSSI Channel (Disabled or AUX1...AUX12)
* **What it does**: Assigns an auxiliary channel coming from your radio transmitter to carry the RSSI (Signal Strength) data value.
* **When to set to DISABLED (Recommended for modern serial links like ELRS)**: If your receiver protocol (like ELRS or CRSF) automatically injects RSSI into the data stream (often displayed as the `LQ` or `RSSI` link stat in your OSD automatically), you do **not** need to map a physical channel. Set this to **Disabled**.
* **When to set to an AUX Channel (e.g., AUX1 to AUX12)**: If your receiver outputs RSSI as a dedicated channel stream (common with some older analog receivers or specific SBUS setups), you would select the specific AUX channel here that corresponds to the RSSI channel output configured in your radio.

`RSSI (Signal Strength)` RSSI_ADC Analog RSSI input

`Channel Map` == AETR1234


![](2026-09-04-17-37-55.png)

## 1. Telemetry (`TELEMETRY` Telemetry output)

* **What it means**: This setting enables the flight controller to **transmit real-time sensor data back to your radio transmitter** over the radio link (using protocols like SmartAudio, F.Port, CRSF, or S.Port).
* **What it does**: When turned **ON**, your radio screen can display live telemetry data sent from the drone, such as battery voltage (`VBAT`), current draw, current GPS coordinates (if equipped), flight mode, and ESC temperatures. 
* **Recommendation**: Keep this **ON** so you can monitor your battery voltage directly on your radio and set up low-voltage audio warnings.

---

## 2. RSSI (Signal Strength) (`RSSI_ADC` Analog RSSI input)

* **What it means**: **RSSI** stands for **Received Signal Strength Indicator**, which measures the strength of the radio link signal between your transmitter and the drone's receiver. 

* **What `RSSI_ADC` specifically means**: This is a legacy or specific hardware configuration where the RSSI signal is fed into the flight controller via an **Analog-to-Digital Converter (ADC)** pin using an analog DC voltage wire (ranging from 0V to 3.3V) coming from an older style receiver.

* **Modern Context**: If you are using modern digital or serial receivers like ExpressLRS (ELRS), Crossfire, or modern FrSky/FlySky protocols over a serial port (SBUS/CRSF), **RSSI is transmitted automatically over the digital serial link**, and you do *not* need to enable `RSSI_ADC`. Leaving it checked when using a digital receiver can cause RSSI to read incorrectly or stay stuck at 0/100%.



## ref 

- [[betaflight-dat]]