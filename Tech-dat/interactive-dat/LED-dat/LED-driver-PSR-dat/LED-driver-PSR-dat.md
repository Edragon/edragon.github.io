

# LED-driver-PSR-dat


- [[acdc-dat]] - [[light-spot-dat]] - [[led-driver-PSR-dat]]


- [[BP9022-dat]] - [[BP9021-dat]] - [[BPS-dat]] - [[LED-driver-PSR-dat]] - [[OPM1101-dat]]

- [[light-dat]] - [[light-spot-dat]] - [[LED-dat]] - [[LED-driver-dat]]

A **PSR LED Driver** stands for **Primary-Side Regulation LED Driver**. 

It is a specialized type of power supply used to drive LED lights efficiently. To understand what it means, we have to break down how traditional LED drivers work versus how a PSR driver simplifies the process.

---

### The Breakdown: What does "Primary-Side Regulation" mean?

In a standard isolated power converter (like a flyback converter used for LEDs), the circuit is split into two halves for safety:
1. **Primary Side:** Connected to the high-voltage AC mains input (e.g., 110V or 220V).
2. **Secondary Side:** Connected to the low-voltage DC output that powers the LEDs.

To keep LEDs from burning out, the driver must maintain a **constant current**. 

* **Traditional Method (Secondary-Side Regulation):** The driver samples the output voltage/current on the *secondary side* and sends a feedback signal back to the *primary side* using a component called an **optocoupler** (an optical isolator). 
* **The PSR Method:** A PSR driver eliminates the optocoupler and secondary-side sensing circuitry entirely. Instead, it regulates the output current by monitoring the voltage and current waveforms on the **primary side** (specifically through an auxiliary winding on the transformer).

---

### Why use a PSR LED Driver? (Advantages)

PSR technology is highly popular in modern LED lighting (like LED bulbs, downlights, and tube lights) for several reasons:

* **Lower Cost & Smaller Size:** By removing the optocoupler, shunt regulator, and extra resistors from the secondary side, the component count drops significantly. This makes the driver cheaper to manufacture and small enough to fit inside the tight base of a standard LED light bulb.
* **Higher Reliability:** Optocouplers are notorious for aging rapidly under high temperatures, which can cause the LED driver to fail prematurely. Eliminating them significantly extends the lifespan of the driver to match the long life of the LEDs.
* **Safety Integration:** Because the primary and secondary sides are physically isolated by the transformer (with no optocoupler bridging the gap), it inherently provides good electrical isolation, protecting users from electric shocks.

### The Downside

While PSR drivers are efficient and cost-effective, they are **not as precise** as secondary-side regulated drivers. Because they estimate the output based on the primary side, they can suffer from slight inaccuracies if the temperature changes drastically or if the components age. Therefore, they are mostly used in cost-sensitive consumer lighting rather than high-end industrial lighting systems.




## ref 

