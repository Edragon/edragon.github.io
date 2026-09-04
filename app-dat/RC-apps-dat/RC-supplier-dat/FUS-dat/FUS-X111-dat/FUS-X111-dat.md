

# FUS-X111-dat

- [[FPV-build-dat]] - [[FPV-3in-dat]] - [[FUS-X111-dat]]

screws 

- [[bolt-hex-dat]] 
    - M2 * 6 
    - M2 * 8 ? 


## build 

![](2026-09-04-21-30-17.png)

![](2026-09-04-21-30-35.png)

![](2026-09-04-21-30-44.png)

![](2026-09-04-21-30-54.png)




## PCB

- [[flight-controller-dat]]

![](2026-09-04-21-57-21.png)

layout 

- [[VTX-dat]] - [[ELRS-dat]]

![](2026-09-04-22-07-33.png)

GND
5V
VIN
LED
BZ-
5V
GND

RX1
TX1
VOUT
5V
GND

RX1
TX1
VOUT
5V
GND

LED: Connect to Smart RGB LED Strip (WS2812 data line).

BZ- / 5V: Connect an active 5V Buzzer (BZ- triggers the ground line, 5V powers it).



1. FPV Camera
   
VIN: Connect to Camera Video Out / Signal (Video In to FC).

5V: Connect to Camera Power (+5V).

GND: Connect to Camera Ground.

2. Analog Video Transmitter (VTX)
   
VOUT: Connect to VTX Video In (FC output with Betaflight OSD overlay).

TX1: Connect to VTX SmartAudio or IRC Tramp control wire (for changing channels/power in OSD).

5V: Connect to VTX Power Input.

GND: Connect to VTX Ground.

3. Receiver (ELRS / Crossfire)

Because UART1 (TX1/RX1) is being shared with the VTX telemetry on this cluster, you have two wiring approaches:

If using UART1 for Receiver:

RX1: Connect to Receiver TX

TX1: Connect to Receiver RX

5V / GND: Receiver Power and Ground

(Note: In this case, you won't connect the VTX SmartAudio wire to TX1 as UART1 is dedicated to the RX).

If using SBUS Receiver:

Connect the Receiver signal line to the inverted SBUS/RX1 pad.



## specs 


F411 & 20A AI0 board

- Size:32.5*32.5mm
- Mounting pattern: 25.5*25.5mm (3mm harf
- Weight: 6.3g
- Connector: Micro-USB
- MCU: STM32F411
- Gyro: MPU6000(SPI)
- Blackbox: Not included
- BEC output: 5V 2A
- Constant current: 20A,25A(Peak)
- Input: 2-4s (support HV)
- Current sensor: Included
- BLHeli: BLHeli-S
- Target: MATEK F411
- ESC  Firmware:G H 30  BLS
- VIDEO TRANSMISSION
- Power—25MW/100MW/200MW
- IRC Tramp— Support to change power and frequen .control (TXD)
- Number of signal channel: 40
- Frequency adjustment: short press button


Product Introduction

The FUS X-111 is a 2.5-inch ducted-fanqund which was designed to flying indisadvanany narrowed space, and without commontages of 2 or 3-inch such asther for beginners or pros, the FUS X-111 can perfectly proilar expererience to a larger quad with a reasonable price of 2-inch quad.

Features

The material combination of CF/ABS/EVAalong with triangle/cross structure,can provide you higher durability and intensity with minimum weight.

Thanks to the ultimate weight-reduce design, the FUS X-11I can provide youmore than 8 minutes indoor flying by a 4s 500mah battery, and performanceway better than an ordinary 2-inch quad.

Extended features

The FUS X-111 can install the DJI-Vista HD Digital FPV system, or HDrecording/FPV camera. Also you can mount your motion camera such as Runcamvideo recorder、gopro、 insta on the X-11l with 3D printing parts. Eitherway, X-1ll is perfectly capable for HD FPV or filming.


![](2026-09-04-22-06-26.png)



## ref 

