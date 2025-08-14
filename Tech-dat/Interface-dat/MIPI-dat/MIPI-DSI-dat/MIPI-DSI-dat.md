
# DSI-dat 

MIPI serial display

![](2023-11-30-15-49-17.png)


## MIPI-DSI Interface Pinout

| Pin No. | Symbol   | Description                              | When Not in Use      |
|---------|----------|------------------------------------------|----------------------|
| 1       | LEDA     | B/L positive pin                         |                      |
| 2       | LEDK     | B/L negative pin                         |                      |
| 3       | VDD      | Power supply, 2.8–3.3V type              |                      |
| 4       | GND      | Power Ground                             |                      |
| 5       | DON      | MIPI DSI differential data pair (N)      |                      |
| 6       | DOP      | MIPI DSI differential data pair (P)      |                      |
| 7       | GND      | Power Ground                             |                      |
| 8       | CLKN     | MIPI DSI differential clock pair (N)     |                      |
| 9       | CLKP     | MIPI DSI differential clock pair (P)     |                      |
| 10      | GND      | Power Ground                             |                      |
| 11      | D1N      | MIPI DSI differential data pair 1 (N)    |                      |
| 12      | D1P      | MIPI DSI differential data pair 1 (P)    |                      |
| 13–33   | GND      | Power Ground                             |                      |
| 34      | RESET    | Reset the LCM                            |                      |
| 35–37   | GND      | Power Ground                             |                      |
| 38      | VDD      | Power supply, 2.8–3.3V type              |                      |
| 39      | GND      | Power Ground                             |                      |
| 40      | NC       | Dummy                                    |                      |


**DSI** stands for **Display Serial Interface**.  

It’s a high-speed serial interface standard defined by **MIPI** (Mobile Industry Processor Interface) for connecting a display module (like an LCD or AMOLED panel) to a host device (like a smartphone SoC or single-board computer).




### MIPI-DSI  

1. **Physical Layer (D-PHY)**
   - Uses **1 clock lane + 1–4 data lanes** (each differential pair).
   - Two modes:
     - **Low-Power (LP) mode** → for commands & initialization (slow, ~10 Mbps).
     - **High-Speed (HS) mode** → for pixel streaming (up to ~1–6 Gbps per lane).

2. **Protocol Layers**
   - **Packet-based transmission**:
     - **Short packets** → commands, sync signals.
     - **Long packets** → pixel data for a line.
   - Works kind of like sending “frames” line by line over a high-speed serial link.

3. **Video Modes**
   - **Command Mode** → SoC sends drawing commands (used with display’s own RAM).
   - **Video Mode** → Continuous stream of pixel data (panel shows it directly).

4. **Key Advantages**
   - Fewer wires than parallel RGB.
   - High bandwidth for high-resolution displays.
   - Low EMI due to differential signaling.

📌 **Flow in simple terms**:  
**SoC** prepares pixel data → wraps it in DSI packets → sends over differential lanes (HS mode) → **Display controller** unpacks → drives LCD pixels.



## ref 

- [[display-dat]]

- [[display]]