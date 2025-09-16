
# antenna-lolipop-dat


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