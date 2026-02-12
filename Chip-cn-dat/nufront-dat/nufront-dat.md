# nufront-dat

[legacy wiki page. ](https://w.electrodragon.com/w/NL6621_Wifi_Module)


## NL6621

The Nufront NL6621M is a highly integrated SoC designed for low-cost, high-throughput WLAN products. It integrates an MCU, MAC, 1T1R baseband and an RF transceiver with an on-chip power amplifier into a single chip. The NL6621M supports 802.11b/g/n, Wi‑Fi Direct (SDIO network card mode), BSS STA, soft AP and Wi‑Fi Protected Setup. It also supports WMM‑PS and WPA/WPA2 security protocols.

The NL6621M can operate as a slave device controlled by a host processor or as a standalone WLAN device that does not require any external processor. Supported peripheral interfaces include Quad‑SPI, standard SPI, I2C, UART, GPIO, I2S audio, and PWM audio. The chip can connect directly to peripherals such as speakers, cameras, flash memory and LCDs. A full TCP/IP stack (UDP, HTTP, etc.) is integrated on the device. High-performance wireless transport combined with rich I/O and protocol support makes the NL6621M a strong single‑chip solution for wireless audio, wireless video, smart home, and medical IoT applications.

### Key features

- Single‑chip WLAN solution supporting 802.11 b/g/n
- Integrated radio, LNA, AFE, MAC and PHY
- Integrated efficient PA: max output power ~17 dBm (802.11b), ~16 dBm (802.11n)
- On‑chip LDOs (power management) — example: convert 1.8 V domain to 1.2 V supply rails
- On‑chip CPU with program/data SRAM and serial online debug support
- Rich peripheral interfaces: Quad‑SPI, standard SPI, UART, I2C, I2S, PWM, GPIO
- Hardware timers and watchdog timer
- Supports Wi‑Fi Direct, soft AP, STA, WMM‑PS and WPA/WPA2

### Typical use cases

- Wireless audio devices (network speakers)
- IP cameras and video streaming devices
- Smart home gateways and IoT devices
- Medical telemetry and wireless sensors

### Quick specs

| Item                 |                                             Specification |
| -------------------- | --------------------------------------------------------: |
| Wireless standard    |                                         IEEE 802.11 b/g/n |
| RX/TX configuration  |                                                      1T1R |
| Maximum TX power     |                              ~17 dBm (11b), ~16 dBm (11n) |
| Supply domains       |                     On‑chip LDOs (example: 1.8 V → 1.2 V) |
| On‑chip CPU & memory | Integrated CPU, program/data SRAM; serial debug supported |
| Interfaces           |                  Quad‑SPI, SPI, I2C, UART, I2S, PWM, GPIO |
| Audio                |                                 I2S and PWM audio outputs |
| Timing               |                           Hardware timers, watchdog timer |


## ref 

- [[wifi-dat]] - [[nufront-dat]]