
# antenna-RHCP-dat


- [[antenna-RHCP-dat]] - [[antenna-LHCP-dat]] - [[antenna-patch-dat]] - [[antenna-skew-planar-dat]] 




- [[antenna-dat]] Polarization == - [[antenna-RHCP-dat]] - [[antenna-linear-dat]] - [[antenna-polarization-dat]] - [[antenna-helical-dat]]


- [[antenna-RHCP-dat]] - [[antenna-panel-dat]] (shape-only) - [[antenna-patch-dat]]


## maker 

- [[trueRC-dat]] - [[MapleLeaf-dat]] - [[GEPRC-dat]] - [[Foxeer-dat]]



## DIY 自绕 🛠️

- 5-turn / 7-turn 螺旋（铜线 + 塑料管 + 接头）
- 成本 ¥30-60，教程一搜一大把
- 优点：极便宜 + 有乐趣（你的动手能力完全够）
- 缺点：需调校（驻波/阻抗）




## Right-Hand Circularly Polarized (RHCP) "Mushroom" Antenna Explained

An **RHCP Mushroom Antenna** (often referred to as a "mushroom" or "cloverleaf" antenna, where RHCP stands for **Right-Hand Circular Polarization**) is a high-performance antenna widely used in wireless communication, video transmission, and high-precision positioning. 

The name comes from its distinct shape: a smooth, rounded radome (protective plastic cover) that houses an intricate radiating element inside.

---

### 1. What is RHCP (Right-Hand Circular Polarization)?
* **Polarization Type**: As an electromagnetic wave travels through space, its electric field vector rotates. If the electric field vector rotates **clockwise** when viewed along the direction of propagation, it is called **Right-Hand Circular Polarization (RHCP)**. (Counter-clockwise is Left-Hand, or LHCP).
* **Key Advantages**:
  * **Multipath Interference Rejection**: When a radio wave hits a wall, ground, or obstacle and reflects, its rotational direction reverses (an RHCP wave typically becomes LHCP upon reflection). If both the transmitter and receiver use **RHCP**, the receiving antenna largely filters out these reflected ghost signals, drastically reducing signal dropouts and video static.
  * **Orientation Resilience**: Unlike linear antennas (like standard straight whips) which suffer massive signal drops if the transmitter and receiver angles mismatch, circular polarization maintains a stable link even as the device tilts, rolls, or banks in flight.

### 2. Why the "Mushroom" Shape?
* **Mechanical Protection**: The actual internal radiating elements (such as cloverleaf or skew-planar wheel wire structures) are quite fragile. Enclosing them in an aerodynamic plastic "mushroom" shell provides protection against water, dust, and crashes while maintaining proper high-frequency impedance matching.
* **Omnidirectional Balance**: It typically delivers a **360-degree omnidirectional** radiation pattern in the horizontal plane while keeping a balanced vertical beamwidth, preventing wasted energy toward the sky or ground and offering a solid gain (typically around 5dBi) in a compact form factor.

### 3. Common Application Scenarios
* **FPV Drones**: A staple in 5.8GHz analog and digital video transmission systems. Transmitters and receivers both use matched RHCP mushroom antennas to keep video feeds clear and stable during high-speed acrobatic flight or when flying around obstacles.
* **GNSS High-Precision Positioning**: Large "mushroom" antennas used in surveying and autonomous navigation utilize circular polarization to reject multipath ground reflections, ensuring precise satellite lock.

---

> **Important Usage Note**: Circularly polarized antennas **must be matched**. If your transmitter uses an **RHCP** mushroom antenna, your receiver **must** also use an RHCP antenna. Mixing RHCP with LHCP or linear antennas will result in massive signal attenuation.


## tiny whoop antenna 

- The **cable is for the video transmitter (VTX)**.  
- The **radio/control link (ELRS)** uses a separate, tiny PCB antenna embedded on the flight controller or VTX board.  
- So even though there is "one visible cable antenna," the drone **still has two radio paths internally**:  
   - **Video (5.8 GHz)** → cable antenna  
   - **Control (2.4 GHz ELRS)** → small PCB or tiny wire antenna


## linear antenna VS circular antenna 


| VTX Power       | Typical Range (Linear Antenna) | Typical Range (Circular Antenna) | Notes |
|-----------------|-------------------------------|---------------------------------|-------|
| 25–100 mW       | 120–300 meters                | 100–250 meters                  | Short indoor range, low interference |
| 200–400 mW      | 500–900 meters                | 400–800 meters                  | Suitable for backyard or small outdoor fields |
| 600–800 mW      | 1.2–2.2 km                    | 1–2 km                          | Common for outdoor FPV, moderate interference |
| 1 W (1000 mW)   | 2–3.5 km                      | 2–3 km                          | Maximum legal power in some regions; susceptible to interference |

### Notes on Antenna Types
- **Linear Antenna:** Slightly longer LOS range in perfect alignment, but highly sensitive to orientation changes.  
- **Circular Antenna:** Slightly shorter max LOS, but maintains more reliable signal through obstacles and multipath interference.




## What Does the "Lollipop" Antenna Do for FPV?

In FPV (First Person View) drone systems, the **Lollipop antenna** is a type of **circularly polarized antenna** designed for the video transmitter (VTX) or receiver (VRX/goggles).  

---

### 📡 Main Functions

1. **Improves Signal Stability**  
   - Circular polarization helps reduce signal dropouts and multipath interference (caused by signals bouncing off walls, trees, or the ground).  
   - This makes your FPV feed more consistent and less "glitchy".

2. **Omnidirectional Coverage**  
   - Lollipop antennas are usually **omnidirectional**, meaning they radiate and receive signals in nearly all directions around the drone.  
   - You don’t need to point the antenna perfectly toward the drone.

3. **Compact and Durable**  
   - They are small, lightweight, and often enclosed in a protective plastic shell.  
   - Good for freestyle and racing drones, since they can survive crashes better than long whip antennas.

4. **Match with Receiver Antenna**  
   - For best performance, both the VTX and goggles should use **circularly polarized antennas with the same handedness** (e.g., LHCP with LHCP, or RHCP with RHCP).  

---

### 🛠️ When to Use
- On your **drone’s VTX** → stable signal while flying in environments with obstacles.  
- On your **FPV goggles** → better reception and fewer blind spots compared to linear antennas.  

---

### ✅ **Summary**:  
The FPV Lollipop antenna is a **circularly polarized omnidirectional antenna** that improves video signal quality, reduces interference, and provides reliable coverage for freestyle or racing drones.



## ref 

- [[antenna-dat]]