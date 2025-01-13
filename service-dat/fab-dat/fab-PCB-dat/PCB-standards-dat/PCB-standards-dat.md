
# PCB-standards-dat

- 8 mil = 0.2 mm
- 10 mil = 0.25 mm (common used)
- 12 mil = 0.3048 mm 
- 14 mil = 0.3556 mm

| category  | Standards              | 0.2 mm         | 10 mil | Note. CN |
| --------- | ---------------------- | -------------- | ------ | -------- |
| clearance | Wire -> Wire, Pad, Via | 0.2 mm         |        |          |
| clearance | Wire -> edge           | 0.2 mm         |        |          |
| Size      | Signal Width           | 0.2 mm         |        |          |
| Size      | Minimum Drill          | 0.25 mm        |        |          |
| Miscs.    | roundness              | 0.15 mm @ 100% |        |          |
| Miscs.    | Mask                   | 0.1mm @ 100%   |        |          |
| Misc.     | Min. Diameter          |                |        |          |
| Misc.     | Annular Ring           |                |        |          |





### Other Manufacturing Limits

| Type                             | Specs                                  | Note                                 |
| -------------------------------- | -------------------------------------- | ------------------------------------ |
| PCB Type                         | FR-4 from KB company                   | -                                    |
| Maximum size                     | 1200mm X1200mm                         | more than 550mm prices will increase |
| Dimensions accuracy of board     | ± 0.2mm                                | -                                    |
| Thickness range                  | 0.40~3mm                               | -                                    |
| Thickness tolerance              | ±10%                                   | -                                    |
| Dielectric thickness             | 0.075 - 5.00mm                         | -                                    |
| Copper thickness                 | 17um - 100um                           | default 1OZ 35um, 0.035mm            |
| Drilling Hole                    | 0.3mm - 6.30mm                         | -                                    |
| Drilling Hole Tolerances         | 0.08mm                                 | -                                    |
| Drilling Hole position tolerance | 0.09mm                                 | -                                    |
| Pour hypotenuse                  | 30~60 °                                | -                                    |
| Color                            | red, blue, green, white, yellow, black | default green\|-                     |
| Soldering Pads Plating           | HASL, ROSH (lead-free), ENIG           |                                      |






## Manufacturing capability
Please adapte this to your own "DRC(Design Rule Check)" tool, to make sure your board reach the manufacturing limits.<br />

### Common-Used Design Ruled DRC

| Name                                | Min. inch (mm)      | Max.               | Eagle CAD Default |
| ----------------------------------- | ------------------- | ------------------ | ----------------- |
| Trace Width/Spacing                 | 6/6 mils (0.15 mm)  | -                  | 10/8 mils         |
| Via/Hole Spacing                    | 6 mils (0.15 mm)    | -                  | 8 mils            |
| Drilling hole (vias)                | 10 mils (0.25 mm) * | 250 mils (6.35 mm) | Sizes 24 mils     |
| Min. stop mask                      | 4 mils (0.1 mm)     | -                  | Masks 4 mils      |
| Min. copper/trace to ground spacing | 8 mils (0.2 mm)     | -                  | 40 mils           |


### Note 
* Minimum milling width of grooves is 0.8mm
* A lot numbers of vias may cost extra 
* Dimension: Any irregular shape should be treated as a rectangular, with maximum size.
* Board test:  fully tested by fly probes.

#### Half-Hole/Impedance
- Half-Hole + $20, if you need this please contact first or write note in order.
- Impedance + $60

### What do not support
* Four layers boards
* Blind holes (not through holes).




### Extra PCB Technics

| Type                   | Description                                                                                                                                 | Category                     |
| ---------------------- | ------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------- |
| Lead free ROHS         | free for samples, extra cost for batch production                                                                                           | Soldering Pads Plate Technic |
| ENIG                   | Gold immersion on pads, better look, better soldering, etc                                                                                  | Soldering Pads Plate Technic |
| Faster PCB in 30 Hours | PCB Manufacturing will be finished in one and half day, not including shipping and handing time. Cost is 42 USD. Can not with ENIG service. | Express PCB                  |
| Faster PCB in 53 Hours | PCB Manufacturing will be finished in two and half day, not including shipping and handing time. Cost is 21 USD.                            | Express PCB                  |
| 2oz copper thickness   | Get better heat dissipation for your board, example like A4988 board.                                                                       | -                            |
| Board thickness        | Free from 0.6 till 1.6 mm, extra cost need for 0.4 and 2.0 mm thickness. (available thickness 0.4 0.6 0.8 1.0 1.2 1.6 2.0)                  | -                            |





## ref 

- [[kicad-dat]]