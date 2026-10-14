


# SX1268-dat

- [[SX1262-dat]] - [[SX1268-dat]]


The **SX1268** is a popular ultra-low power, long-range Sub-GHz radio transceiver IC designed by Semtech. It is heavily utilized in IoT systems, smart metering, asset tracking, and industrial automation.

### Key Technical Specifications

* **Frequency Range:** Sub-GHz bands (commonly deployed in the **410 MHz – 510 MHz** range, such as 433 MHz and 470 MHz ISM bands, often aligned with Chinese regulatory standards).
* **Modulation Techniques:** LoRa, (G)FSK, (G)MSK.
* **Maximum Output Power:** Up to **+22 dBm** (high-efficiency Power Amplifier).
* **Receiver Sensitivity:** Down to **-148 dBm**.
* **Link Budget:** Up to **170 dB** maximum link budget.
* **Power Consumption:**
* Low receive (RX) current: ~4.2 to 4.6 mA.
* Deep sleep current: ~2 µA.


* **Host Interface:** SPI (often integrated alongside UART on ready-to-use breakout modules like E22 or Waveshare HATs).
* **Protocol Support:** Compatible with the physical layer requirements of **LoRaWAN**, though it is frequently used with custom/private point-to-point protocols depending on the specific module firmware.

### SX1262 vs. SX1268

* **SX1262:** Typically targets global frequencies (such as 868 MHz for Europe and 915 MHz for the US).
* **SX1268:** Optimized to target lower regional sub-GHz frequencies (such as 433/470 MHz blocks) to better comply with specific regional regulations.




## ref 

