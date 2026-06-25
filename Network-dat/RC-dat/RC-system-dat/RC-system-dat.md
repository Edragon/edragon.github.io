
# RC-system-dat




- [[RC-system-dat]] - [[elrs-dat]] - [[CRSF-dat]] - [[edge-tx-dat]] 


When getting into FPV drones or RC robotics, it's incredibly common to see **EdgeTX**, **CRSF**, and **ELRS** tossed around in the same sentence. However, they aren't competing technologies; rather, they are **three entirely different layers** of your radio control system that work together. 

Think of it like a modern smartphone setup: EdgeTX is the operating system, CRSF is the cable protocol connecting the phone to an external modem, and ELRS is the wireless 5G signal sent into the air.

---

## 1. EdgeTX (The Radio Operating System)
EdgeTX is an open-source **operating system that runs on your physical radio controller** (handset). It is the software you interact with on the screen to manage menus, configure model settings, set up switches, mix channels, and play voice alerts.

* **What it does:** It handles everything *inside* the radio controller up until the moment a stick command needs to leave the main motherboard.
* **Analogy:** The Windows or Android OS on your computer or phone.

## 2. CRSF / Crossfire (The Communication Protocol)
CRSF (short for *Crossfire*) is a **digital data protocol** originally developed by Team BlackSheep (TBS). It is a highly optimized, low-latency language used for wired and wireless data transfer between devices.

* **What it does:** In an RC setup, CRSF acts as the language spoken over the internal wires. It transfers data from your radio's main processor (EdgeTX) to your transmission module (like an ELRS module), and from your quad's receiver to the flight controller. 
* **Why it matters for ELRS:** Even if you aren't using TBS hardware, **ELRS uses the CRSF protocol** to talk to the EdgeTX radio handset and the flight controller because CRSF is incredibly fast and widely supported.
* **Analogy:** The USB-C protocol or HDMI standard used to transfer data between hardware components.

## 3. ELRS / ExpressLRS (The Long-Range Wireless Link)
ELRS is an open-source, high-performance **radio control system that handles the over-the-air wireless link** between your radio transmitter and the model's receiver. 

* **What it does:** It takes the control data, encodes it using advanced LoRa (Long Range) modulation technology, and blasts it wirelessly through the air at frequencies like 2.4GHz or 915MHz to achieve extreme range and ultra-low latency.
* **Why it's popular:** It offers incredible refresh rates (up to 1000Hz) and massive range, all while remaining highly affordable and open-source.
* **Analogy:** The 5G, Wi-Fi, or Bluetooth wireless signal traveling through the air.

---

## Summary of How They Interact

When you move a gimbal stick on your radio, the journey looks exactly like this:

$$\text{Your Hand} \xrightarrow{\text{Moves Stick}} \mathbf{\text{EdgeTX (Radio OS)}} \xrightarrow[\text{Internal Language}]{\mathbf{\text{CRSF Protocol}}} \mathbf{\text{ELRS Module}} \xrightarrow[\text{Wireless Signal}]{\mathbf{\text{LoRa Link}}} \text{Drone Receiver}$$

| Component | What it is | Primary Job |
| :--- | :--- | :--- |
| **EdgeTX** | Open-source Firmware / OS | Manages your radio handset, screens, models, and mixes. |
| **CRSF** | Digital Protocol (Language) | The high-speed wire format used to send data between components. |
| **ELRS** | Wireless RC Link System | The actual RF hardware and software sending data over the air. |



## info 






- [[betaflight-dat]] - [[heli-configurator-dat]]

- [[ardupilot-dat]] - [[PX4-dat]] - [[iNav-dat]]






## RC-configurator-dat

- [[betaflight-dat]]

- [[heli-configurator-dat]]



## commerlized projects 

- **speedybee** == https://www.speedybee.com/ == SpeedyBee is a company that specializes in providing high-quality drone components and accessories, including flight controllers, ESCs, and other related products. They are known for their innovative designs and user-friendly interfaces, making them a popular choice among drone enthusiasts.
- **betafpv** == https://www.betafpv.com/ == BETAFPV is a company that focuses on producing small and lightweight drones, particularly for FPV (First Person View) racing and freestyle flying. They offer a range of products, including flight controllers, cameras, and other accessories tailored for FPV enthusiasts.
- happymodel
- iFlight
- Holybro
- TBS
- Flywoo
- HGLRC
- Diatone
- GepRC
- Racerstar
- Emax
- Eachine
- HGLRC
- Racerstar




## ref 

