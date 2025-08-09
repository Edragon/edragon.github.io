
# display-protocols-dat


## protocols convert 

- [[RGB-to-LVDS-dat]]



## protocols 

**MIPI** stands for **Mobile Industry Processor Interface**.

- [[MIPI-DSI-dat]]  - [[HDMI-dat]] - [[LVDS-dat]] - [[VGA-dat]]

- [[eDP-dat]] - [[SLVS-EC-dat]]

- [[parallel-display-dat]] - [[RGB-LCD-dat]]

- [[MIPI-CSI-DAT]] - [[MIPI-dat]]

### Other Display Interfaces

#### 1. **MIPI-CSI** (Camera Serial Interface)
- **Direction:** Camera → Processor
- Also uses MIPI D-PHY (similar electrical layer as DSI).
- Serial, differential, high-speed.
- Instead of pixel-out, it’s pixel-in.

#### 2. **LVDS** (Low-Voltage Differential Signaling)
- Parallel pixel data serialized over multiple lanes.
- Widely used in laptops before MIPI-DSI became popular.
- Lower data rate per lane (~945 Mbps) but can use many lanes.
- Simpler than DSI (no packet protocol like DSI).

#### 3. **eDP** (Embedded DisplayPort)
- Mostly used in laptops and tablets.
- Based on DisplayPort standard.
- Packet-based like DSI, but higher bandwidth (multi-Gbps per lane).
- Supports very high resolutions (4K, 8K).

#### 4. **HDMI**
- For external displays/TVs.
- Packetized video + audio.
- Higher voltage, not as power-efficient as DSI.
- Not usually used for mobile internal displays.

#### 5. **Parallel RGB / TTL**
- Old-school direct pixel bus (1 wire per color bit + sync signals).
- Very high pin count, no serialization.
- Easy to understand but not good for high resolution.

#### 6. **SLVS-EC** (Scalable Low Voltage Signaling – Embedded Clock)
- Newer serial interface from Sony and others.
- Competes with MIPI for camera & display links.
- Higher speeds than D-PHY in some cases.

---

💡 **Main takeaway:**  
- **MIPI-DSI** = optimized for **internal** mobile/tablet displays, low pin count, low EMI, power-efficient.  
- **LVDS** and **eDP** = laptop displays.  
- **HDMI** = external monitors/TVs.  
- **Parallel RGB** = simple, low-res systems.

## ref 

- [[display-dat]]