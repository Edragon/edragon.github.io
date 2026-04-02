

# PCB-soldering-dross-dat

In the context of PCB soldering, the professional term for 锡渣 (xī zhā) is Solder Dross.

While you might hear "solder scrap" or "waste solder" in casual conversation, "dross" is the specific technical term used in manufacturing and engineering.


### What exactly is Solder Dross?

Dross is a combination of oxidized metal and impurities that forms on the surface of molten solder, particularly during wave soldering or selective soldering processes. When the liquid solder is exposed to air, it reacts with oxygen to create a thick, crusty layer of metal oxides (mostly tin and lead oxides).


### Key Terminology Comparison
| Chinese Term | English Technical Term | Description |
| :--- | :--- | :--- |
| **锡渣** | **Solder Dross** | The oxidized "scum" that floats on top of a solder pot. |
| **锡球 / 锡珠** | **Solder Ball / Solder Bead** | Small, unwanted spheres of solder that stick to the PCB surface. |
| **锡桥** | **Solder Bridge** | An accidental connection between two conductors (a short circuit). |
| **焊坝** | **Solder Dam** | A barrier (often solder mask) used to prevent solder from flowing where it shouldn't. |

---

### Why it matters in production
In a professional setting, dross is managed carefully because:
1. **Waste:** It consumes expensive solder alloy that could otherwise be used for joints.
2. **Defects:** If dross particles get trapped in a solder joint, they can cause physical weakness or poor electrical conductivity.
3. **Maintenance:** It must be regularly skimmed off the top of the solder pot. Many factories use "dross reducers" (chemical powders) or nitrogen-inert environments to minimize its formation.



## common hobby level solutions

Markdown
### Reducing Solder Dross in Non-Professional Reflow Soldering

For DIY enthusiasts or users using **non-professional equipment** (such as converted toaster ovens, hot plates, or heat guns), the "dross" or residue you see is usually caused by solder paste oxidation, flux charring, or poor temperature control.

Here is how to minimize these issues in a home or lab environment:

---

### 1. Solder Paste Management (The Source)
In SMT reflow, dross-like particles are often "solder balls" caused by degraded paste.
* **Avoid Oxidation:** Solder paste has a shelf life. Once the flux dries out, the microscopic metal powder oxidizes. When heated, these powder grains won't fuse, creating a "sand-like" dross.
* **Proper Warming:** If stored in a fridge, let the paste reach room temperature for 2-4 hours before opening. Using cold paste causes moisture to condense, leading to "spattering" and tiny solder beads during heating.

### 2. Optimize the Temperature Profile
Non-professional tools often heat too fast or stay at peak temperature too long.
* **The Soak Phase:** Do not rush to the melting point. Maintain a temperature around **150°C** for 60-90 seconds. This allows the flux to clean the metal surfaces and prevents the "popcorn effect."
* **Limit Peak Time:** Once the solder melts (approx. 217°C for lead-free), try to finish the reflow and start cooling within 30-60 seconds. Staying at high heat for too long burns the flux into a black, crusty residue.

### 3. Use High-Quality External Flux
If your solder joints look dull or have "scum" on top:
* **Add Tacky Flux:** Apply a small amount of high-quality flux (like NC-559 or similar) to the pads before reflow.
* **The Benefit:** Extra flux helps reduce any oxides that form during the uneven heating of a DIY oven, helping the liquid metal pull together into a clean, shiny joint.

### 4. Stencil & Deposition Control
"Dross" in SMT is often just excess solder that had nowhere to go.
* **Use a Stencil:** Avoid hand-applying paste if possible. A stencil ensures the exact volume is applied.
* **Reduce Apertures:** If you consistently see tiny beads around components, design your stencil openings to be about 90% of the actual pad size.

### 5. Environment & Cleaning
* **Minimize Airflow:** In a DIY toaster oven, try to keep the door closed and seal major gaps. Constant fresh air brings in more oxygen, which accelerates dross formation.
* **Pre-Cleaning:** Use 99.9% Isopropyl Alcohol (IPA) to clean the PCB and component leads before soldering. Contaminants like finger oils often turn into "dross" under heat.

---

### Troubleshooting Table
| Symptom | Primary Cause | Solution |
| :--- | :--- | :--- |
| **Solder Beads (Scattered dots)** | Rapid heating or moisture | Increase "soak" time at 150°C |
| **Charred Residue (Black crust)** | Temperature too high/too long | Lower peak temp; shorten reflow time |
| **Dull/Grainy Joints** | High oxidation | Use fresh paste; add extra flux |

> **Pro Tip:** If using a **Hot Plate**, placing a small metal "tent" or cover over the PCB can help stabilize the temperature and create a micro-environment with less oxygen movement, resulting in much cleaner solder joints.



## pressfional methods to prevent solder dross


To prevent **Solder Dross** (锡渣) in a professional SMT (Surface Mount Technology) or through-hole environment, you must address the root cause: **Oxidation**.

Dross forms when molten solder reacts with oxygen. In a standard SMT reflow process (using solder paste), dross is less of a concern than in **Wave Soldering** or **Selective Soldering**, where large pots of molten metal are exposed to air.

Here are the professional methods to prevent and manage dross:

### 1. Atmosphere Control (The Gold Standard)
The most effective way to prevent dross is to remove the oxygen entirely.
* **Nitrogen ($N_2$) Blanketing:** Filling the soldering machine with high-purity Nitrogen (typically 99.99% or oxygen levels below 500 ppm). Without oxygen, the metal cannot oxidize into dross.
* **Inerting the Wave:** In wave soldering, specialized "hoods" or nitrogen diffusers cover the solder pot to keep the air out.



### 2. Chemical Solutions
If nitrogen is too expensive for your setup, you can use chemicals to inhibit oxidation:
* **Dross Reducers / "Anti-Dross" Powder:** These are antioxidant powders (like phosphorus-based pellets) added to the solder pot. They float on top and react with oxygen so the solder doesn't have to.
* **Solder Oils/Blankets:** A layer of specialized heat-stable oil is floated on the surface of the molten solder to create a physical barrier against air.

### 3. Equipment & Process Optimization
Mechanical turbulence is a major "dross generator." Every time the solder splashes or ripples, more surface area is exposed to air.
* **Reduce Wave Height:** Keep the solder wave as low as possible while still making contact with the PCB.
* **Minimize Turbulence:** Ensure pump speeds are steady and that the "fall" of the solder back into the pot is smooth rather than splashing.
* **Standby Mode:** Use machines that automatically lower the pump speed or turn off the wave when no PCBs are detected on the conveyor.
* **Keep the Pot Full:** A low solder level increases the distance the metal "falls" back into the pot, creating more bubbles and turbulence.



### 4. Solder Quality & Maintenance
* **Use Low-Drossing Alloys:** Professional-grade solder bars (like SAC305 or Sn63Pb37) often contain trace amounts of **Germanium (Ge)** or **Phosphorus (P)** which act as "oxygen scavengers" to keep the surface shiny.
* **Controlled De-drossing:** When you must remove dross, use a **Solder Recovery System** (a mechanical press). "Raw" dross is actually 70%–90% good solder trapped in an oxide "web." These machines squeeze the good metal back out so you don't waste it.

### Comparison Summary
| Method | Effectiveness | Cost | Best For |
| :--- | :--- | :--- | :--- |
| **Nitrogen ($N_2$)** | Highest | High (Gas costs) | High-volume, High-reliability |
| **Antioxidant Pellets** | Medium | Low | Small-to-medium shops |
| **Wave Optimization** | Low-Medium | Free (Process) | All wave soldering |
| **Solder Recovery** | High (for savings) | Moderate (Tool) | Reducing waste costs |

> **Pro Tip:** If you are seeing "grainy" or "dull" joints on your PCBs, it’s a sign that dross is being sucked into the pump and mixed into your solder joints. Always skim the surface regularly but gently—vigorous stirring actually creates more dross!



## ref 

