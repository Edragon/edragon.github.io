

# flux-thinner-dat

- [[PCB-soldering-dross-dat]] - [[fab-PCB-soldering-dat]]




## Solder Paste Thinner: Essential Guidelines

The liquid used to adjust the viscosity of solder paste is professionally referred to as **Solder Paste Thinner** (or Flux Thinner).

**CRITICAL WARNING:** In professional electronics manufacturing, **it is generally discouraged to thin solder paste.** Solder paste is a carefully engineered chemical mixture. If it has dried out or expired, the flux activity and the rheology (flow characteristics) have already been degraded. Adding a thinner often results in:
* **Bridge defects** during reflow.
* **Solder beading** or "tombstoning" due to altered wetting properties.
* **Voids** in the solder joint caused by improper solvent evaporation.

---

### 1. Composition
Specialized solder paste thinners typically consist of:
* **Glycol Ethers (e.g., Propylene Glycol Ethers):** These are the primary solvents that dissolve the resin/rosin binder.
* **Surfactants:** Added to maintain the thixotropic properties (the ability to flow under shear stress but stay stationary when idle).
* **Stability Agents:** Prevent the metal particles from settling out of the flux medium.

### 2. Best Practices for Use
If you must attempt to salvage a paste (for non-critical prototyping), follow these strict rules:

* **Use Only Professional Grade Thinner:** Do not use general solvents like acetone, lacquer thinner, or standard hardware store cleaners. These will chemically destroy the flux.
* **Minimal Dosage:** Add only **1% to 3% by weight**. Adding too much will cause the paste to slump, leading to shorts between fine-pitch pads.
* **Homogeneous Mixing:** Use a mechanical or manual spatula to stir the paste for at least 3-5 minutes until the consistency is uniform. 
* **Stabilization:** Let the paste sit for at least 30 minutes after mixing before using it to allow the chemical solvents to distribute evenly.



### 3. Troubleshooting "Dry" Paste
Before reaching for a thinner, check these common issues:
* **Temperature (The #1 Culprit):** Solder paste must be stored in a refrigerator (typically 2°C–10°C). It **must** be brought to room temperature (naturally, in its container) for at least 2–4 hours before opening. If opened while cold, moisture from the air will condense into the paste, causing it to appear dry or gritty.
* **Shelf Life:** Check the expiration date. Once the activator in the flux is exhausted, no amount of thinner will restore the paste's ability to create a reliable solder joint.

### 4. Important Distinction
* **Thinners:** Are for modifying the paste's viscosity.
* **Cleaners (IPA/Alcohol):** Are for removing flux residues **after** soldering or cleaning stencils. **Never mix these into your solder paste.**

