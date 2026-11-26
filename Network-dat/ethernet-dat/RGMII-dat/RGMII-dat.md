
# RGMII-dat

- [[ethernet-dat]] - [[RGMII-dat]] - [[RGMII-phy-dat]]



- [[impedance-dat]] - [[RGMII-dat]] - [[impedance-GRMII-dat]]




## RGMII (Reduced Gigabit Media Independent Interface)

RGMII is a standard interface used between a MAC and a PHY to support Gigabit Ethernet (1 Gbps) connectivity. It is a more compact and efficient version of GMII, reducing the number of data pins.

Features of RGMII:

1. Reduced pin count: Uses only 12 data pins (compared to GMII's 24 pins) by transmitting data on both the rising and falling edges of the clock (DDR - Double Data Rate).
2. Speed support: Capable of operating at 10 Mbps, 100 Mbps, and 1 Gbps.
3. Signals in RGMII:
- TX (Transmit) and RX (Receive) data signals
- Clock signals for TX and RX
- Control signals (TX_EN, RX_DV)

RGMII enables the MAC and PHY to communicate effectively while optimizing space and complexity.





## 🌐 What is RGMII?

**RGMII** stands for **Reduced Gigabit Media Independent Interface**.

It's a type of **electrical interface** used to connect a **MAC** (Media Access Controller) to a **PHY** (Physical Layer Transceiver) in Ethernet devices.

---

### 📦 What is it used for?

- Used in **Gigabit Ethernet (1000 Mbps)** hardware
- Common in **routers, switches, SoCs, FPGAs**, and other networking devices

---

### 🧠 Why "Reduced"?

RGMII reduces the number of data lines compared to **GMII**:

| Interface | Data Lines | Speed |
|-----------|------------|-------|
| GMII      | 24         | Up to 1 Gbps |
| RGMII     | 12         | Up to 1 Gbps |

🔧 RGMII uses **double data rate (DDR)** — it transfers data on **both rising and falling edges** of the clock signal, so it needs **fewer wires**.

---

### ⚙️ Key Features

- ✅ Supports **10/100/1000 Mbps** Ethernet
- ✅ Uses **DDR clocking** to reduce pin count
- ✅ Total of **12 signals**:
  - 4 TX data
  - 4 RX data
  - TX control
  - RX control
  - TX clock
  - RX clock

---

### 🛠️ Typical RGMII Pinout

| Signal       | Direction      | Description                  |
|--------------|----------------|------------------------------|
| TXD[3:0]     | MAC → PHY      | Transmit data                |
| RXD[3:0]     | PHY → MAC      | Receive data                 |
| TX_CTL       | MAC → PHY      | Transmit control             |
| RX_CTL       | PHY → MAC      | Receive control              |
| TXC          | MAC → PHY      | Transmit clock               |
| RXC          | PHY → MAC      | Receive clock                |

---

### 🔌 Summary

- **RGMII = Compact, fast interface** for Gigabit Ethernet
- **Used between Ethernet MAC and PHY**
- **Saves pins** compared to GMII
- **Supports up to 1 Gbps** using DDR signaling