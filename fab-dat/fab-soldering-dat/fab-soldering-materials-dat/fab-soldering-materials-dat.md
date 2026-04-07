

# soldering-materials-dat


- [[solder-paste-dat]] - [[soldering-flux-dat]]




## soldering wire 

Nickel, Copper, and Sandwich (For 18650/21700)

| Material        | Best Use Case                      | Pros                                                                         | Cons                                                                   |
| :-------------- | :--------------------------------- | :--------------------------------------------------------------------------- | :--------------------------------------------------------------------- |
| **Pure Nickel** | Standard DIY packs (5A-15A)        | Easiest to spot weld; corrosion resistant.                                   | Higher resistance than copper; heats up at high current.               |
| **Pure Copper** | High-performance (30A+)            | Lowest resistance; minimal heat generation.                                  | Extremely difficult to spot weld (requires laser/ultrasonic).          |
| **Sandwich**    | High-current DIY (Nickel + Copper) | Better conductivity than pure nickel; weldable with high-power spot welders. | Hard to tune welding parameters; risk of "cold" welds or blow-through. |






## 18650 Interconnect Materials: Why vs. Why Not


- Nickel Strip

| Material        | Conductivity      | Weldability   | Best Used For...                                             |
| :-------------- | :---------------- | :------------ | :----------------------------------------------------------- |
| **Pure Nickel** | Good (~25% of Cu) | **Excellent** | Standard DIY packs, Robotics (Rover V2), Electric bikes.     |
| **Pure Copper** | **Best (100%)**   | **Very Poor** | Ultra-high performance racing drones or EV modules.          |
| **Sandwich**    | High              | **Difficult** | High-current DIY builds (Copper strip under a Nickel strip). |

---

### Why we choose Pure Nickel for 18650s:
1. **High Resistance (Ideal for Welding):** Spot welding relies on electrical resistance to generate heat. Nickel resists current just enough to melt instantly at the contact point, creating a strong bond.
2. **Thermal Control:** Copper is a "heat sink"—it pulls heat away so fast that the weld point never gets hot enough to melt, but the battery cell underneath gets dangerously hot.
3. **Corrosion Resistance:** Nickel does not rust or oxidize easily. Copper turns green (oxidizes) over time, which increases resistance and creates "hot spots."
4. **Tool Compatibility:** Most hobbyist spot welders (Sunkko, Malectrics, Kweld) are designed specifically for the physics of nickel.


---

### 2. Al-Ni (Aluminum-Nickel) Composite Strips

**Primary Purpose:** Transitioning between dissimilar metals.

* **When to use:** Specifically for **Pouch Cells** or **Prismatic Cells** where the positive terminal (tab) is made of **Aluminum**.
* **Why:** Aluminum and Nickel do not bond well through standard spot welding.
* **How it works:** The strip is bi-metallic (half Al, half Ni).
    * **Al side** is welded to the battery's Aluminum tab.
    * **Ni side** provides a weldable surface for standard nickel busbars or wires.
* **Summary:** It is a "bridge" material, not for 18650s (which use steel/nickel caps), but for batteries with raw aluminum electrodes.

examples: 

- 0.11mm镀镍 + 叠加0.2mm紫铜
- 0.1mm镀镍 + 叠加0.15mm紫铜
- 1.2mm复合带 镍 + 铝
- 铜极材料
- 0.3mm镀镍
- 0.4mm不锈钢
- 0.2mm铝镍

## ref 

- [[PCB-soldering-tools-dat]]



