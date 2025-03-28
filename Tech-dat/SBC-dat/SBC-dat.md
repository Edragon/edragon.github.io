
# SBC dat 


- Beaglebone Black

- [[RPI-dat]] - [[OPI-DAT]]

- [[rockchip-dat]] - [[RK3588-dat]] - [[RK3506-dat]] - [[RV1103-dat]]

- [[mediatek-dat]] - [[MT7628-dat]] - [[MT7688-dat]] - [[MT7620-dat]]

- [[BTT-DAT]]





## Compare 

| Device                   | CPU                        | Clock Speed   | NPU           | GPU                             | RAM                                          | Multimedia                    | Connectivity                            | Target Use Case             | Power Efficiency | Price Range |
|--------------------------|----------------------------|---------------|---------------|--------------------------------|----------------------------------------------|-------------------------------|----------------------------------------|------------------------------|------------------|-------------|
| **RV1103**               | Dual-core Cortex-A7        | Up to 1.2 GHz | 0.5 TOPS      | Basic 2D/3D                     | Low memory usage (external)                  | Basic H.264/VP8 decoding      | Basic (IoT focus)                       | Edge AI, IoT, low power      | High             | Low         |
| **RK3588**               | Octa-core (A76 + A55)      | Up to 2.4 GHz | 6 TOPS        | Mali-G610 MP4                   | Up to 32GB LPDDR4X/LPDDR5                    | 8K H.265/VP9 decoding         | PCIe, USB 3.0, HDMI                     | AI, 8K media, high-end apps  | Moderate         | High        |
| **Raspberry Pi 3**       | Quad-core Cortex-A53       | 1.2 GHz       | None          | VideoCore IV                    | 1GB LPDDR2                                   | 1080p H.264 decoding          | HDMI, USB 2.0                           | DIY, education, IoT          | Moderate         | Low         |
| **Raspberry Pi 4**       | Quad-core Cortex-A72       | 1.5 GHz       | None          | VideoCore VI                    | Up to 8GB LPDDR4                             | 4K H.265/VP9 decoding         | HDMI, USB 3.0, Gigabit Ethernet         | Desktop replacement, IoT     | Moderate         | Moderate    |
| **Raspberry Pi Zero 2 W**| Quad-core Cortex-A53       | 1 GHz         | None          | VideoCore IV                    | 512MB LPDDR2                                 | 1080p H.264 decoding          | HDMI, USB OTG                           | IoT, ultra-low power         | High             | Very Low    |
| **MT7620**               | MIPS 24KEc                 | 580 MHz       | None          | None                            | Low memory usage (external)                  | None                          | Wi-Fi, Ethernet, USB 2.0                | Routers, IoT, networking     | High             | Very Low    |
| **ESP32-P4**             | Dual-core RISC-V           | Up to 400 MHz | AI Extensions | 2D Pixel Processing Accelerator | 768 KB on-chip SRAM; supports external PSRAM | H.264 and JPEG codecs support | USB OTG 2.0 HS, Ethernet, SDIO Host 3.0 | HMI, edge computing, IoT     | High             | Low         |
| **Raspberry Pi Compute Module 4** | Quad-core Cortex-A72 | 1.5 GHz | None | VideoCore VI | 1GB, 2GB, 4GB, or 8GB LPDDR4; optional 8GB, 16GB, or 32GB eMMC | 4K H.265/VP9 decoding | Optional Wi-Fi, Gigabit Ethernet, PCIe | Embedded systems, industrial applications | High | $25 - $90 |



- RV1103 mem RAM: The RV1103 is designed as a lightweight processor for edge AI and IoT applications, where power efficiency and simplicity are prioritized over high performance. Here's why its memory usage is low and relies on external memory








## ref 

- [[SBC]]


