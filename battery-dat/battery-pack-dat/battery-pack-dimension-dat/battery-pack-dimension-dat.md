

# battery-pack-dimension-dat

2x2 18650 battery == 66 x 40.5 x 40.5 mm (with spacers and insulation)

65+1 x 18+18+4.5 

for [[heat-shrink-tube-dat]] == 106.5 + 10 or 81 + 10




## Dimensions Calculation for a 2x2 18650 Battery Pack Layout

The dimensions for a 2x2 layout of 18650 cells are derived from the standard physical specifications of a single cell, where the designation **18650** defines its nominal size:
*   **18**: Diameter of 18 mm
*   **65**: Length/Height of 65 mm
*   **0**: Denotes a cylindrical form factor

For a small 4-cell square assembly, a standard **Matrix Layout** (flat grid alignment) is preferred over an interleaved honeycomb pattern.

---

### 1. Theoretical Minimum Dimensions (Bare Cells Only)

These figures represent the absolute physical boundaries of the cells resting directly against one another without any structural packaging, wiring, or isolation gaps:

*   **Length (Z-axis):** Constant height of a single cell = **65 mm**
*   **Width (X-axis):** 2 diameters side-by-side = 18 mm * 2 = **36 mm**
*   **Height/Thickness (Y-axis):** 2 diameters stacked = 18 mm * 2 = **36 mm**

> **Ideal Envelope Volume:** 65 mm * 36 mm * 36 mm

---

### 2. Practical Engineering Dimensions (Recommended for CAD & Enclosure Design)

In real-world applications, cells should not touch metal-to-metal due to short-circuit hazards. You must factor in processing variables and safety materials:
1.  **Plastic Interlocking Spacers (Brackets):** Standard interlocking 18650 grid spacers have an outer edge dimension of 20.2 mm per cell slot to allow air-cooling gaps and structural spacing.
2.  **Top/Bottom Fishpaper:** Adds about 0.3 mm to the longitudinal stackup.
3.  **Outer PVC Heat-Shrink Tubing:** Adds around 0.5 mm to 1.0 mm around the finished perimeter.

#### Option A: Pack Assembled with Standard Plastic Modular Spacers (Best Practice)
*This is the standard for robots, vehicles, and high-vibration applications.*
*   **Length:** 65 mm (cell) + 0.3 mm (fishpaper) + 0.7 mm (nickel/wrap tolerance) = **66.0 mm**
*   **Width:** 20.2 mm * 2 = **40.4 mm**
*   **Height:** 20.2 mm * 2 = **40.4 mm**

#### Option B: Wrapped Pack Without Spacers (Glue + Heat-Shrink Only)
*Utilized for tight space constraints where spacers cannot physically fit.*
*   **Length:** **66.0 mm**
*   **Width:** (18 mm * 2) + 1.0 mm (insulation/wrap allowance) = **37.0 mm**
*   **Height:** (18 mm * 2) + 1.0 mm (insulation/wrap allowance) = **37.0 mm**

---

### 3. Design and Tolerancing Advice

> ⚠️ **Mechanical Clearance Tip:** When modeling 3D-printed battery cradles, CNC-machined enclosures, or laser-cut mounting plates for your hardware projects, always implement a **1.0 mm to 1.5 mm design tolerance/clearance buffer** on each axis past your option numbers. This prevents assembly interference caused by variations in adhesive thickness, solder joints, or 3D printer material shrinkage.


## ref 


