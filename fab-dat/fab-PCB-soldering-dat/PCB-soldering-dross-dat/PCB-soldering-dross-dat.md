# PCB Solder Dross Data

- [[PCB-soldering-dross-dat]] - [[fab-PCB-soldering-dat]] - [[solder-paste-dat]]

## 1. Introduction to Solder Dross

In the context of PCB soldering, the professional term for **锡渣 (xī zhā)** is **Solder Dross**. While terms like "solder scrap" or "waste solder" are used casually, "dross" is the technical standard in manufacturing.

### What is Solder Dross?
Dross is a combination of oxidized metal and impurities that forms on the surface of molten solder, particularly during wave or selective soldering. When liquid solder is exposed to air, it reacts with oxygen to create a crusty layer of metal oxides (mostly tin and lead oxides).

### Technical Terminology Comparison
| Chinese Term | English Technical Term | Description |
| :--- | :--- | :--- |
| **锡渣** | **Solder Dross** | The oxidized "scum" floating on a solder pot. |
| **锡球 / 锡珠** | **Solder Ball / Solder Bead** | Unwanted spheres of solder sticking to the PCB. |
| **锡桥** | **Solder Bridge** | Accidental short circuit between two conductors. |
| **焊坝** | **Solder Dam** | Physical barrier (e.g., solder mask) to control flow. |

---

## 2. Professional Prevention & Management
To prevent dross, you must address the root cause: **Oxidation**.

### Atmosphere & Chemical Control
*   **Nitrogen ($N_2$) Blanketing:** The gold standard. Filling machines with high-purity $N_2$ (99.99%) prevents the metal from reacting with oxygen.
*   **Dross Reducers:** Antioxidant powders (phosphorus-based pellets) or "solder oils" added to the pot to create a physical barrier against air.

### Process Optimization
*   **Reduce Turbulence:** Splashing and ripples increase the surface area exposed to air. Keep pump speeds steady and wave height as low as possible.
*   **Equipment Settings:** Use "Standby Mode" to lower pump speeds when no PCBs are on the conveyor. Keep the solder pot full to minimize the "fall" distance of returning metal.
*   **Low-Drossing Alloys:** Use professional bars (SAC305, Sn63Pb37) that include "oxygen scavengers" like trace Germanium (Ge).
*   **Mechanical Recovery:** Use a recovery press to squeeze good metal (usually 70-90%) out of raw dross.

---

## 3. Hobby & DIY Solutions (Reflow/SMT)

In DIY reflow (toaster ovens, hot plates), "dross" is often the grey residue from oxidized paste or charred flux.

### Best Practices for DIY
1.  **Optimize the Profile:** Use a **"Soak Phase"** (~150°C for 60-90s) to allow flux to clean surfaces. Limit **Peak Time** (217°C+) to 30-60s to avoid burning flux into a black crust.
2.  **Add External Flux:** Applying high-quality tacky flux (e.g., NC-559) helps reduce oxides formed by uneven heating, resulting in shiny joints.
3.  **Stencil Precision:** Use a stencil to control volume. If beads persist, reduce stencil apertures to 90% of the pad size.
4.  **Board Prep:** Clean the PCB with 99.9% IPA before soldering. Finger oils and contaminants often turn into "dross" under heat.

### Troubleshooting Table
| Symptom | Primary Cause | Solution |
| :--- | :--- | :--- |
| **Solder Beads** | Rapid heating or moisture | Increase "soak" time at 150°C. |
| **Charred Residue** | Temperature too high/long | Lower peak temp/shorten time. |
| **Dull/Grainy Joints** | High oxidation | Use fresh paste; add extra flux. |

---

## 4. Solder Paste Storage & Maintenance

Oxidation often starts in the container, especially at high temperatures ($30^\circ\text{C}+$):
*   **Flux Separation:** Solder powder settles, and oily flux rises to the top.
*   **Premature Activation:** Heat exhausts the flux's cleaning power before use.
*   **Powder Oxidation:** Heat catalyzes the formation of Tin Oxide on the tiny spheres.

### Storage Comparison
| Storage Temp | Expected Shelf Life | Quality Result |
| :--- | :--- | :--- |
| **$0\text{--}10^\circ\text{C}$ (Fridge)** | 6–12 Months | **Professional.** Shiny joints. |
| **$20\text{--}25^\circ\text{C}$ (Room)** | 1–2 Months | **DIY Grade.** May need extra flux. |
| **$30^\circ\text{C}+$ (Warm)** | < 3 Weeks | **Poor.** High risk of grey joints. |

### How to Identify "Dead" Paste
*   **The Stir Test:** If it's "chunky" or like "wet sand" and won't stir into a smooth cream, it's dead.
*   **The Slump Test:** If it spreads out at room temperature, it will cause bridging during reflow.
*   **The Solder Ball Test:** Heat a dab on scrap PCB. If it forms one shiny ball, it's good. If it leaves tiny "satellites" (grey dust), it's heavily oxidized.

### Recovery Methods
*   **Manual Homogenization:** Stir vigorously for 2–3 minutes until it looks like creamy peanut butter. 
*   **Rescue Flux:** Adding a few drops of **Tacky Flux** can sometimes revive dry paste, but it increases the risk of "runny" paste (lower viscosity).

---

## 5. Fixing "Grey" or Oxidized Joints
If joints are already dull (overheated or oxidized):
1.  **Apply Tacky Flux:** Cover the joint with high-quality flux.
2.  **Re-Reflow:** Briefly use a hot air station (~300°C) or a clean soldering iron tip. The flux will chemically reduce the oxides and allow the metal to flow into a shiny, silver shape.

## References
- [[solder-paste]]
- [[soldering-dat]]
 

