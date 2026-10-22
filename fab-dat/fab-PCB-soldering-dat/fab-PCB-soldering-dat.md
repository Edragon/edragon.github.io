# fab-PCB-soldering-dat

- [[fab-PCB-soldering-dat]] - [[fab-workspace-dat]]

- [[syringe-dat]] - [[syringe-pusher-dat]]  - [[solder-paste-dat]]

- [[Flux-Thinner-dat]]

- [[soldering-flux-dat]]

- [[brush-dat]]

- [[soldering-tip-revive-dat]]

- [[light-dat]]

- [[fab-soldering-materials-dat]] - [[fab-soldering-metal-dat]]

- [[heat-isolator-pad-dat]]


- [[fab-PCB-dat]] - [[fab-PCB-soldering-dat]] - [[fab-PCB-soldering-tools-dat]] - [[fab-PCB-desoldering-dat]] - [[fab-soldering-materials-dat]]

- [[fab-soldering-float]] - [[fab-soldering-float-dat]] - [[fab-soldering-dat]]





- [[PCB-soldering-skills-dat]]

- [[PCB-soldering-dross-dat]]

- [[fab-soldering-tools-dat]] - [[soldering-tools-spot-welding-dat]] - [[soldering-iron-dat]] - [[preheat-bed-dat]] - [[hot-air-station-dat]] 


- [[fab-soldering-materials-dat]] - [[soldering-flux-dat]] - [[solder-paste-dat]] 

## Bad Soldering

For STM32F103-series MCUs (common packages such as LQFP-48 / LQFP-64, usually with 0.5 mm pin pitch), problems like cold joints, solder bridging, and poor wetting during PCBA (surface-mount assembly) can be systematically prevented and controlled across four core dimensions: stencil design, solder-paste process, reflow profile, and PCB design.

---

## I. Stencil and Solder-Paste Process Optimization

Fine-pitch packages are extremely sensitive to solder-paste volume; stencil apertures and paste quality are the first gate that determines soldering yield.

* **Stencil Aperture Design**:
  * **Inner cut and outer extension**: For 0.5 mm pitch LQFP packages, the stencil aperture should use a **trapezoidal inward taper** or a slight outward extension (recommended: reduce the aperture width by 5%–10% and extend the length direction by 10%). This prevents bridging between adjacent pins while still providing enough paste to avoid cold joints.
  * **Stencil thickness**: A **0.12 mm** laser-cut, electropolished stencil is recommended to ensure smooth paste release.

* **Solder Paste Selection and Storage**:
  * Use **Type 4 or Type 5** fine-powder solder paste (smaller metal powder particle size) for better print definition and activity on fine-pitch pads.
  * Strictly follow the paste **temperature recovery (warm up for more than 4 hours)** and **stirring** procedures, and measure viscosity before use to avoid reduced activity caused by moisture absorption or separation.

- [[solder-paste-dat]]

- [[fab-PCB-soldering-reflow-dat]]



## III. PCB Land Pattern Design and Component Quality Control

The physical condition of the substrate and the components themselves directly affects solder wetting.

- [[fab-stencil-dat]]
 
- [[fab-PCB-soldering-baking-dat]]


---

## IV. Placement Accuracy and Manual/AOI Inspection Control

* **Pick-and-Place Pressure and Accuracy Calibration**:
  * Check the placement machine's Z-axis downward pressure. Too much pressure squeezes paste out beyond the pads and causes bridging; too little pressure results in poor contact between pins and paste, causing cold joints.

- [[fab-QC-dat]] - [[AOI-dat]]

* **AOI and X-Ray Inspection**:
  * **AOI (Automated Optical Inspection)** is mandatory after reflow, focusing on the coplanarity of the STM32's four pin rows and on any bridging or insufficient solder.
  * For chips with a bottom thermal pad (e.g., certain QFN packages or packages with a Thermal Pad), perform **X-Ray** sampling as needed to check void rate and cold joints in the bottom solder joint.

---

## V. Verification Checklist

* [ ] Check that the stencil aperture dimensions match the 0.5 mm pitch and that the thickness is 0.12 mm.
* [ ] Confirm the reflow oven profile meets the peak temperature (235 °C–245 °C) and time above liquidus (45–75 s) targets.
* [ ] Confirm the STM32 pins and PCB pads are free of oxidation and deformation, and that coplanarity is good.
* [ ] Use AOI to re-inspect 100% of pin appearance and coplanarity on the first article.





## Ref

- [[fab-soldering]]