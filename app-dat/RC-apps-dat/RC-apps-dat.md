
# RC-apps-dat

- [[RC-dat]]

- [[rover-dat]] - [[RC-car-dat]] - [[RC-car-hack-dat]] - [[video-rc-car-dat]]

- [[Curiosity-rover-dat]]

- [[quadcopter-dat]] - [[FPV-dat]]

- [[rc-aircraft-dat]] - [[fixed-wing-dat]]

- [[UAV-dat]]

- [[rc-code-dat]]

- [[ROV-dat]] - [[rc-boat-dat]]



## RC - signal 

- [[RC-signal-dat]]

## RC - systems 

- [[ardupilot-dat]] 

## RC - Hardware

- [[flight-controller-dat]] - [[RC-link-dat]]

- [[BMS-dat]] - [[battery-dat]]

## RC - manufacturers

- [[Wfly-dat]] - [[betaFPV-dat]] - [[speedybee-dat]]

## Teardown post 

[Tear down and Learn a good-build $20 RC Toy Car](https://www.electrodragon.com/disassemble-and-learn-a-good-build-20-rc-toy-car/)




## RC Link  - SPI ELRS RC Link Update Rates

### 1. Supported ELRS Packet Rates (Hz)
- 25 Hz (long range, very low latency priority not needed)
- 50 Hz
- 100 Hz
- 250 Hz
- 500 Hz
- 1000 Hz (only with UART-based receivers, *not supported* on SPI RX)

### 2. Mobula8 SPI Receiver Limitation
- SPI-based ELRS receivers (built into flight controllers) **usually support up to 500 Hz max**.
- They don’t handle 1000 Hz mode reliably.

### 3. Radiomaster Pocket ELRS
- Can output up to **1000 Hz**.
- But the Mobula8 SPI ELRS will negotiate down to **max 500 Hz**.

---

### Final Answer

The **RC link update rate between your Radiomaster Pocket and Mobula8 SPI ELRS** can be set to **25 / 50 / 100 / 250 / 500 Hz**,  
but **500 Hz is the highest stable rate** supported by the Mobula8 SPI receiver.



## ref 

- [[rc-apps]]

- [[mechanics-dat]]

