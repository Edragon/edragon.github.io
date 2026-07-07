

# PCB-vias-dat

- [[PCB-solder-mask-dat]] - [[PCB-dat]] - [[PCB-design-dat]] - [[PCB-vias-dat]]


default minimal vias == 0.3 mm

## The Via Rule of Thumb

As a reliable hardware engineering benchmark for a standard **0.3 mm hole diameter** with standard **$1\ \text{oz}$ ($35\ \mu\text{m}$) hole wall plating**:
* **1 Via** safely handles **~1A to 1.5A** of continuous current at a $10^\circ\text{C}$ temperature rise.

Therefore, to safely pass a **10A peak**, you should use:
* **Minimum:** **4 to 5 vias** (if the 10A is a very brief, occasional pulse).
* **Recommended Safely:** **7 to 10 vias** stitched together in a cluster or grid.

---

### Via Current Capacity Table

If you change the size of your vias, their current capacity changes. Here is a quick reference table for common prototyping via sizes (assuming standard 1 oz / $35\ \mu\text{m}$ copper plating and a conservative $10^\circ\text{C}$ rise):

| Drill/Hole Size       | Outer Pad Diameter | Current Capacity (Per Via) | Vias Needed for 10A Peak |
| :-------------------- | :----------------- | :------------------------- | :----------------------- |
| **0.3 mm** (~12 mils) | 0.6 mm (~24 mils)  | **~1.2 A**                 | **8 to 10 vias**         |
| **0.5 mm** (~20 mils) | 0.9 mm (~35 mils)  | **~1.9 A**                 | **5 to 6 vias**          |
| **0.8 mm** (~31 mils) | 1.4 mm (~55 mils)  | **~2.8 A**                 | **3 to 4 vias**          |

---

### Best Practices for Layout in KiCad

When splitting 10A across multiple vias, how you place them matters just as much as how many you use:

1. **Arrange them in a Grid/Cluster:** Place the vias close together right where the top trace transitions to the bottom trace. Arrange them in a tight $2\times4$ or $3\times3$ grid.
2. **Ensure Equal Sharing:** Place the vias symmetrically across the width of the 2.0 mm trace. If you line them up in a single file line matching the direction of the current, the first few vias will take the brunt of the current, while the ones at the back won't do much work.
3. **Keep the Tracks Wide:** Make sure the copper traces leading *into* and *out of* the via cluster on both layers are wide enough to handle their share of the current.

