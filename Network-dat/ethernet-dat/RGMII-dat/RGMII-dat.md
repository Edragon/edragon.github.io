
# RGMII-dat

- [[ethernet-dat]] - [[RGMII-dat]] - [[RGMII-phy-dat]]



- [[impedance-dat]] - [[RGMII-dat]] - [[impedance-GRMII-dat]]





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