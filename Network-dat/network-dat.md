# network-dat.md

- [[protocols-dat]]

- [[RC-dat]]

- [[rf-switches-dat]]



## Network tech by range 

| Technology      | Range                      | Data Rate | Notes                               |
| --------------- | -------------------------- | --------- | ----------------------------------- |
| [[M2M-dat]]     | Almost infinite (provider) | Varies    | Limited by service provider network |
| [[lora-dat]]    | Long, up to 10 km          | Low       |                                     |
| [[RF-link-dat]] | Medium, up to 1 km         | Low       |                                     |
| [[ELRS-dat]]    | Medium, up to 1 km (5 km)  | High      |                                     |



## main category

- [[M2M-dat]] - [[LTE-dat]] - [[POE-dat]] - [[low-power-test-dat]] - [[M2M-interface-dat]]

- [[bluetooth-dat]]


- [[cable-dat]] - [[fiber-optic-dat]]- [[coaxial-cable-dat]] - [[POF-dat]] - [[toslink-dat]]

- long distance = [[lora-dat]] - [[lorawan-dat]] - [[rf-switch-dat]]

- [[RFID-dat]] - [[wiegand-dat]]

- [[M2M-dat]] - [[LTE-dat]] - [[LWPA-dat]]

- [[interface-dat]]

- [[radio-dat]]

- [[ethernet-dat]] - [[WIFI-DAT]]

## internet 

- [[network-system-dat]]

- [[WIFI-DAT]] - [[HTTP-dat]] - [[UDP-dat]] - [[MQTT-dat]] - [[TCPIP-dat]]


## RC apps protocols 

- [[RC-dat]] - [[RF-DAT]] - [[CRSF-dat]] - [[GFSK-dat]] - [[ardupilot-dat]] - [[SBUS-dat]]

 
- [[ELRS-dat]] - [[ELRS-TX-dat]] - [[ELRS-RX-dat]] - [[GFSK-dat]]

RC protocols - [[CRSF-dat]] - [[SBUS-dat]] 

and more - [[IBUS-dat]] - [[PPM-dat]] - [[FPort-dat]] - [[SPEKTRUM-dat]] - [[SUMD-dat]] - [[SRXL-dat]] - [[Ghost-dat]] - [[MAVLink-dat]] - [[DroneCAN-dat]] 

- [[PS2-console-dat]]



## Software 

- [[ardupilot-dat]]

- [[openwrt-dat]]

- [[zigbee-dat]] - [[openthread-dat]] - [[micropython-dat]]


## RF boards 

- [[DVA1002-dat]] - [[DVA1007-dat]]

- [[NRF24L01-dat]] - [[NWL1032-dat]]


## M2M Boards 

- [[NGS1131-dat]] - [[NGS1132-dat]] - [[NGS1140-dat]]

- [[NGS1063-dat]]


## Location 


- [[location-dat]] - [[GNSS-dat]] - [[GPS-dat]] - [[AGPS-dat]]

- [[NGS1089-dat]][[mqtt-dat]]

## IOT 

- [[NBIOT-dat]] - [[MQTT-dat]]

- [[zigbee-dat]]

## Ethernet 

- [[ethernet-dat]]

EtherCAT (Ethernet for Control Automation Technology) is a high-performance, real-time Ethernet-based fieldbus system. It was originally developed by Beckhoff Automation.

## System and APPs 

- [[RTU-dat]] - [[modbus-dat]]


## info 

### What is DTE and DCE?  

**DCE** = **Data Circuit-terminating Equipment** (also called Data Communications Equipment).  

- In the context of modems, the **DCE** is the modem itself.  
- It connects to a **DTE** (**Data Terminal Equipment**), which is typically your computer, microcontroller, or router.  

**Roles:**

| Device Type | Meaning                                                                        | Example                                |
| ----------- | ------------------------------------------------------------------------------ | -------------------------------------- |
| **DTE**     | Data Terminal Equipment — device that generates/uses data                      | PC, microcontroller, router            |
| **DCE**     | Data Circuit-terminating Equipment — device that provides a communication path | Modem, serial adapter, cellular module |


- The DTE and DCE sides determine **who provides clock signals**, and how cables are wired (TX/RX pins).  
- In UART serial communication, for example:  
  - DTE sends data to DCE, which modulates/transmits it.  
  - DCE receives data from DTE, demodulates it, and sends it to the remote device.  



## What is PPP?  

**PPP** (**Point-to-Point Protocol**) is a data link layer protocol used to establish a **direct connection between two network nodes**.  
It allows the transmission of **multi-protocol datagrams** (e.g., IP, IPv6, IPX) over serial links, phone lines, or other point-to-point connections.

---

### 2. Key Uses of PPP  
- Connecting two devices over a serial link.  
- Dial-up Internet access (historical).  
- VPN connections (PPP over SSH or PPP over Ethernet).  
- Cellular data connections (PPP over UART for modems).  

Example:  
A microcontroller talking to a cellular modem (SIMCom, Quectel) over UART often uses PPP to establish an IP connection.



## network protocols and standards 

- [[network-dat]] - [[xbee-dat]] - [[btbee-dat]] - [[nrf24l01-dat]] - [[CC1101-dat]] - [[sensor-dat]]

- [[zigbee-dat]]

- [[wifi-dat]]

- [[IEEE-dat]]


## network system

- [[network-system-dat]]



## unsort 

- ET5171 - EMI RFI FILTER 10A ELCOM AC 115V 230V single phase ET5171



## ref 

- [[antenna-dat]]