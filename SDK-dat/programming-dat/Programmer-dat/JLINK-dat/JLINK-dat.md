
# JLINK dat 


- [[ARM-dat]]

- [[DPR1135-dat]]


JLink is a the SEGGER company launched JTAG emulator for ARM core chip to support simulation. IAR EWARM, ADS, KEIL, WINARM, RealView and other integrated development environment with the support all ARM7/ARM9 kernel chip simulation and seamless connectivity through the RDI interface and the integrated development environment, easy to operate, easy to connect, easy to learn, learning to develop ARM the best and most practical development tools.


- [[JTAG-dat]] - [[SWD-dat]]

## About J-Link 


* J-Link-OB developed by Segger, for development board "on-board"
* Interface include JTAG and SWD, simple version only have SWD
* Support IDE: J-Flash ARM、Keil MDK-ARM、IAR EWARM、CoIDE、mikroC PRO for ARM、nRFgo Studio
* Supported MCUs: ST、Freecale、nuvoton、NXP、TI, Cypress, Atmel, Analog, Fujitsu, Toshiba, Energy Micro and more
* Could be detected as fake in MDK, so not as good as STLINK or DAPLINK


![](2024-07-05-17-55-07.png)

![](2024-07-05-17-55-19.png)



## supported MCUs 

- ARM7/9/11，
- Cortex-A5/A7/A8/A9，
- Cortex-M0/M1/M3/M4/M7，Cortex-R4，
- Microchip PIC32
- Renesas RX100/RX200/RX610/RX621/RX62N/RX62T/RX630/RX631/RX63N


## usage 

![](2025-09-23-13-24-54.png)

- VOUT is a 3.3V voltage output pin.
- Users can remove the internal shorting jumper of the device to disable the 3.3V output.
- VTREF is the internal voltage reference; this pin must be connected to



## BULK interface 

- [[usb-driver-dat]] - [[serial-dat]]

![](2025-09-23-13-17-18.png)

# What is a BULK Interface (USB)?

A **BULK interface** is a type of **USB transfer mode** defined by the USB specification.  
It is used for **large, non-time-critical data transfers** between a USB device and a host.

---

## Key Points

- **Purpose**: Moves large amounts of data reliably, without strict timing.
- **Error Handling**: Each transfer is error-checked (CRC). If errors occur, the host retries.
- **Speed**: Uses all available USB bandwidth that isn’t reserved for other transfers.
- **Transfer Size**:
  - USB 2.0 → up to **64 KB per transfer**, with max **512 bytes per packet** (High-Speed).
  - USB 3.0 → larger packet sizes (up to **1024 bytes**).
- **Scheduling**: Lowest priority compared to isochronous or interrupt transfers.  
  The host only sends bulk data when bus time is free.

---

## Examples of Devices Using BULK Transfers
- **USB flash drives** (file transfers).
- **Printers** (sending print jobs).
- **Scanners** (image data).
- **Custom devices** (MCU development boards, DA14585 debug/test interfaces, etc.).

---

## Comparison with Other USB Transfers

| Transfer Type   | Use Case                     | Priority | Guaranteed Bandwidth | Error Handling |
|-----------------|------------------------------|----------|----------------------|----------------|
| **Control**     | Device configuration (setup) | Highest  | Yes                  | Yes            |
| **Isochronous** | Audio/video streaming        | High     | Yes                  | No retry       |
| **Interrupt**   | Small, quick signals (mouse) | Medium   | Yes                  | Yes            |
| **Bulk**        | Large, non-urgent data       | Lowest   | No                   | Yes            |

---

👉 In short: A **BULK interface** is a **USB data channel** used for transferring large, reliable chunks of data when timing is not critical.



## ref 

- [[SDK-dat]]