
# GMSL2-dat


**GMSL2** is a high-speed **video + data + power** transmission interface designed by **Maxim/Analog Devices**, widely used in automotive cameras, robotics, drones, and machine-vision systems.

---

## ⭐ What GMSL2 Does
GMSL2 can transmit through a single cable:

- High-resolution video (up to ~6 Gbps)
- Control signals (I²C / UART / GPIO)
- Power-over-Coax (PoC)
- Low-latency data streams

Cable length: **15–20 meters** with excellent signal integrity.

---

## ⭐ Why GMSL2 Is Popular
- **Long cable distance** without image loss  
- **Power + data on one cable** (PoC)
- **Very low latency**
- Supports **up to 4K** resolution
- Strong **EMI/EMC** performance (important in cars and robotics)

---

## ⭐ How GMSL2 Works (Simple)
GMSL2 is a **SerDes** system:

1. **Serializer** (camera side):  
   Converts MIPI CSI-2 → GMSL2 high-speed serial.

2. **Cable**:  
   Coax or STP.

3. **Deserializer** (processor side):  
   Converts GMSL2 → MIPI CSI-2 → into your SoC/CPU.

---

## ⭐ Typical Use Case
Camera → MAX9295 Serializer → Coax → MAX9296 Deserializer → MIPI CSI-2 → Jetson / Orin / CM4 / NXP / Qualcomm

---

## ⭐ GMSL Versions Comparison

| Version | Speed | Cable | Notes |
|--------|-------|-------|-------|
| GMSL    | ~3 Gbps | Coax/STP | Older generation |
| **GMSL2** | ~6 Gbps | Coax/STP | Most common today |
| GMSL3   | 12+ Gbps | Coax | Latest ADAS systems |

---

## ⭐ When to Use GMSL2
Use GMSL2 if you need:
- A camera **far from the computer**
- **Stable**, low-latency, long-distance video
- Avoiding USB dropouts or high latency
- Automotive-grade reliability for robots/drones



## ref 

- [[camera-interface-dat]]