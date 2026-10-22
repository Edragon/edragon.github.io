

# fab-stencil-dat




印刷锡膏（金属刮刀 45-60°，一次刮过，不要反复刮——反复会让锡塌陷、拉丝）




- [[fab-stencil-dat]] - [[fab-stencil-printer-dat]] - [[fab-stencil-frameless-dat]] - [[fab-stencil-frame-dat]]



## common size frameless

- 10 x 10 cm
- 15 x 15 cm
- 20 x 20 cm

other un-common size frameless

- 10 x 15 cm
- 15 x 20 cm


### all size framed 

- 30*40cm（有框）
- 37*47CM（有框）
- 42*52CM（有框）
- 45*55CM（有框）
- 55*65CM（有框）
- 73.6*73.6CM（有框）



25 X 30 CM
30 X 40 CM
37 X 47 CM
42 X 52 CM
45 x 55 CM
40 x 60 CM
40 x 70 CM
40 x 80 CM
58 X 58 CM
55 x 65 CM



| no. | area                | usable   | price   | weight |
| --- | ------------------- | -------- | ------- | ------ |
| 1   | 37 x 47             | 19 x 29  | 71 RMB  | 1.5KG  |
| 2   | 30 x 40             | 14 x 24  | 68 RMB  | 1KG    |
| 3   | 42 x 52             | 24 x 34  | 89 RMB  | 1.8KG  |
| 4   | 45 x 55             | 27 x 37  | 113 RMB | 2KG    |
| 5   | 58.4 x 58.4         | 38 x 38  | 137 RMB | 3.2KG  |
| 6   | 55 x 65             | 34 x 44  | 147 RMB | 3.5KG  |
| 7   | 73.6 x 73.6         | 50 x 50  | 187 RMB | 5KG    |
| 8   | 28 x 38 (frameless) | 19 x 29  | 55 RMB  | 0.8KG  |
| 9   | 40 x 60             | 22 x 40  | 110 RMB | 2.5KG  |
| 10  | 40 x 80             | 22 x 60  | 125 RMB | 3.5KG  |
| 11  | 40 x 100            | 22 x 76  | 141 RMB | 4KG    |
| 12  | 40 x 120            | 22 x 100 | 165 RMB | 6KG    |



## Land Pattern Design

  * Design strictly to the footprint dimensions recommended in the official STM32 datasheet, ensuring a moderate pad length (typically the pin extends 0.3 – 0.5 mm beyond the pad) for sufficient solder fillet height without component drift caused by oversized pads.
  * Ensure a **thermal balance design** on multilayer boards: large copper areas connected to GND or VCC must use **thermal relief** connections to prevent excessive heat dissipation that leaves local areas too cool and causes cold joints.





## Stencil Thickness

In SMT surface-mount assembly, stencil thickness is the core parameter that determines solder-paste print volume and solder joint quality. For different component densities, pin pitches, and mixed-technology PCBs, stencils typically come in a few standard thicknesses.

---

## I. Common Stencil Thickness Categories and Feature Comparison

| Stencil Thickness                           | Typical Applications                                                                                              | Key Advantages                                                                                                                                                            | Main Drawbacks                                                                                                                 |
| ------------------------------------------- | ----------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------ |
| **0.08 mm – 0.09 mm**<br>*(Ultra-thin)*     | Ultra-fine-pitch ICs at 0.3 mm / 0.4 mm pitch, CSP, micro BGA, 01005/0201 chip components.                        | Greatly reduces paste release volume and reliably prevents **solder bridging** between fine pitches.                                                                      | Low paste volume; if printing or reflow is not well controlled, it easily causes **cold joints, solder starvation, or opens**. |
| **0.10 mm**<br>*(Fine-pitch)*               | 0.4 mm / 0.5 mm pitch LQFP, QFN, BGA, and mixed micro chip components (0201/0402).                                | Balances bridging prevention at fine pitch with the paste volume needed by standard components; currently the mainstream choice for high-density boards.                  | Places higher demands on solder paste powder (Type 4/5 required) and on the paste release process.                             |
| **0.12 mm**<br>*(Standard fine-pitch)*      | **0.5 mm pitch QFP/LQFP (e.g., STM32F103)**, 0603/0402 chip components.                                           | An industry-recognized balance point: stable paste release, higher tolerance for process variation, and a good compromise between mechanical strength and joint fullness. | Still carries a slight bridging risk in purely 0.4 mm ultra-fine-pitch areas; requires a local **step-down** design.           |
| **0.15 mm**<br>*(Standard general-purpose)* | ICs at 0.65 mm pitch and above, standard 0603 / 0805 / 1206 chip components, boards with mixed through-hole pins. | Long stencil life, resistant to deformation, low manufacturing cost, and provides ample paste volume.                                                                     | **Absolutely unsuitable for 0.5 mm and finer pitch**; very likely to cause large-area bridging.                                |
| **0.18 mm – 0.20 mm**<br>*(Thick)*          | Large connectors, high-power modules, and boards that require a large paste volume for thermal pads.              | Can deliver a very large paste volume, ensuring complete melting for large pins and high-thermal-capacity devices.                                                        | Must never be used for fine-pitch components; would cause catastrophic shorts.                                                 |

---

## II. Core Principles for Selecting Stencil Thickness

1. **Match to the minimum pin pitch**:
   * Pitch $\le 0.4\text{ mm}$: prefer **0.08 mm – 0.10 mm**.
   * Pitch $= 0.5\text{ mm}$: prefer **0.10 mm – 0.12 mm** (such as the STM32F103 discussed above).
   * Pitch $\ge 0.65\text{ mm}$: prefer **0.15 mm**.

2. **Resolve the conflict on mixed-technology boards**:
   * When a single PCB carries both ultra-fine-pitch chips (e.g., 0.4 mm BGA) and high-power connectors, no single stencil thickness can satisfy both requirements. In this case, use a **step stencil (local step-down or local step-up)**: 0.10 mm in fine-pitch areas and 0.15 mm or 0.18 mm in large-component areas.

---

## III. Engineering Verification Checklist for Stencil Thickness

* [ ] Determine the base stencil thickness from the densest, smallest-pitch components on the PCB (e.g., 0.5 mm QFP or 0.4 mm BGA).
* [ ] Verify that the stencil aperture area ratio (Area Ratio = aperture area / aperture wall surface area) is greater than 0.66 to ensure smooth paste release.
* [ ] For regions where thickness does not match local needs (e.g., very large or very small pads), confirm whether a local step-down or local aperture enlargement has been applied.


## ref 

