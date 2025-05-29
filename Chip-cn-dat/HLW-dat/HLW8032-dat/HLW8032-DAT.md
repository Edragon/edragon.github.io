# HLW8032 DAT

- [[SVC1031-dat]] - [[SVC1035-dat]]

- [[HLW8032-faq-dat]] - [[HLW8032-reg-dat]]

## Chip Info

- The HLW8032 is a high precision energy metering IC that uses a CMOS manufacturing process and is primarily intended for single phase applications. It can measure line voltage and current, and can calculate active power, apparent power and power factor.
- The device integrates two ∑-Δ ADCs and a high-precision energy metering core. The HLW8032 can communicate data through the UART port. The HLW8032 uses a 5V supply, a built-in 3.579M crystal, and an 8PIN SOP package.
- The HLW8032 has the advantages of high precision, low power consumption, high reliability and strong adaptability to the environment. It is suitable for energy metering of single-phase two-wire power users.


## UART communication interface


HLW8032 has a simple UART interface and adopts asynchronous serial communication mode, which allows data communication via two one -way pins. The UART interface can realize isolated communication by only a low-cost photoelectric coupler. The UART interface operates at fixed frequency of 4800 bps and its interval for transmitting data is 50mS, which is suitable for design of low velocity.   

UART of HLW8032 uses two pins. The TX pin is used to transmit data from HLW8032, and data is transmitted in the least significant bit (LSB) with priority. The RX pin is used to receive the data from microcontroller. 

![](2025-02-13-16-09-20.png)

Data format of HLW8032:   
 
- Baud rate:4800bps   
- Start bit+data bit (8bit) + even bit + stop bit


## Applications 

![](2023-11-01-18-24-07.png)


## debugging software 

![](2024-12-18-17-08-33.png)

![](2024-12-18-17-09-06.png)

## SCH 

- [[AC-isolation-dat]]

![](2025-05-20-12-28-21.png)

- [[HLW8032-ISO-Version-dat]]

## Application areas:

- Smart home appliances
- Metering sockets
- Smart WIFI sockets
- Electric vehicle charging piles
- PDU equipment
- LED lighting
- Street light control

## Demo code 

- please find them in [repo](https://github.com/Edragon/HLW)
- https://github.com/Edragon/arduino-main2/tree/main/tech/Sensor/1-Current/HLW8032
- https://github.com/Edragon/arduino-esp8266/tree/master/Sketchbook/APP/HLW
- https://github.com/Edragon/arduino-esp8266/tree/master/Libraries/HLW8032-master


## ref

- [[sample-resistor-dat]] - [[resistor-dat]] - [[Optical-Coupler-DAT]]

- [[HLW-dat]]

- [[HLW8032.pdf]]

- [[HLW8012-dat]] 