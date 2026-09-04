
# serial-dat

- [[serial-monitor-dat]] 

- [[serial-circuits-dat]] - [[auto-serial-dat]]

- [[serial-cmd-dat]]


- [legacy wiki page](https://w.electrodragon.com/w/Serial)

- classic common options - [[CH340-dat]]

- [[USB-sys-dat]] - [[Logic-level-shifter-dat]]

- [[USB-dat]]

- detailed use guide [[serial-USB-debugger-dat]]





## on board USB to TTL serial adapters check 

below is the variation of [[CH340-dat]]

![](2026-02-07-18-57-06.png)




### FT232 vs CP2102 

- [[FT232-dat]] - [[CP2102-dat]]

![](2026-05-24-22-06-41.png)




## categorized by target friendly

- [[Arduino-ide-dat]] == [[CH9102-dat]] - [[CH9104-dat]] - [[FT232RL-dat]] - [[CP2102-dat]] - [[CP2104-dat]]


## driver 

- https://github.com/Edragon/COM-Driver
- https://github.com/Edragon/git-Debug
- https://github.com/Edragon/Tools



## APP 

- [[serial-dat]] - [[DTU-dat]]

## demo 

serial flashing with DTR pin for [[arduino-dat]]

![](2026-04-28-13-12-05.png)



### other interface 

- [[RS485-DAT]] - [[RS232-dat]] - [[I2C-dat]]


- [[usb-ttl]] - [[serial]]


## full interface - Full-Function UART (Universal Asynchronous Receiver-Transmitter)

While modern UART configurations often use just two pins (TXD and RXD) or four pins (adding RTS and CTS), this specific list includes the legacy hardware modem control lines.

---

### Pin Definition & Breakdown

Here is what each specific pin does (note: there is a slight typo in your list; `UART1_R1` is almost certainly `UART1_RI`):

| Pin Name                      | Full Name           | Direction (Relative to DTE/Host) | Description                                                                                        |
| :---------------------------- | :------------------ | :------------------------------- | :------------------------------------------------------------------------------------------------- |
| **UART1_TXD**                 | Transmit Data       | Output                           | Carries the actual serial data being sent out from the host.                                       |
| **UART1_RXD**                 | Receive Data        | Input                            | Carries the incoming serial data being received by the host.                                       |
| **UART1_RTS**                 | Request To Send     | Output                           | Used for hardware flow control. Tells the receiver that the transmitter has data ready to send.    |
| **UART1_CTS**                 | Clear To Send       | Input                            | Used for hardware flow control. Tells the transmitter that the receiver is ready to accept data.   |
| **UART1_DCD**                 | Data Carrier Detect | Input                            | Incoming signal from a modem indicating it has successfully connected to a telephone line/carrier. |
| **UART1_DTR**                 | Data Terminal Ready | Output                           | Outgoing signal from the host indicating it is powered on and ready to communicate.                |
| **UART1_RI** *(listed as R1)* | Ring Indicator      | Input                            | Incoming signal from a modem indicating an incoming phone call/ring is detected.                   |

---

### How It Is Used Today

While originally designed in the 20th century to connect computers (DTE) to telephone modems (DCE), you will still encounter this exact 7-to-8 pin configuration (including Ground) in several modern scenarios:

* **Industrial Automation:** Connecting to legacy PLCs, industrial machinery, and CNC equipment that require full RS-232 signaling.
* **Cellular Modems & IoT Modules:** High-end 4G/5G LTE or NB-IoT modules embedded on PCBs often utilize the full UART interface. The `RI` pin is especially useful for waking up a host microcontroller from deep sleep when an incoming SMS or data packet arrives.
* **Telecommunications:** Network routers and switches still frequently use full serial interfaces for console management.


## SCH 

- [[CH340-dat]] with - [[isolation-dat]]

![](2026-07-23-16-17-36.png)





## ref 

software [[com-monitor-dat]]

- [[ESP-SDK-dat]]

