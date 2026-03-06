
# PCB-standards-dat



## Manufacturing Capability

- 8 mil = 0.2 mm
- 10 mil = 0.25 mm (common used)
- 12 mil = 0.3048 mm 
- 14 mil = 0.3556 mm

### Comprehensive Manufacturing Limits & Design Rules

| Category        | Parameter                        | Specification / Limits                 | Notes / Defaults                  |
| :-------------- | :------------------------------- | :------------------------------------- | :-------------------------------- |
| **Clearance**   | Spacing (Wire to Wire, Pad, Via) | 0.2 mm (8 mil)                         | Min. 6 mil (0.15mm)               |
|                 | Wire to Edge                     | 0.2 mm (8 mil)                         | -                                 |
|                 | Via to Hole Spacing              | 6 mils (0.15 mm)                       | 8 mils (Eagle Default)            |
|                 | Copper/Trace to Ground           | 8 mils (0.2 mm)                        | 40 mils (Eagle Default)           |
| **Size**        | Signal Width                     | 0.2 mm (8 mil)                         | Min. 6 mil (0.15mm)               |
|                 | Maximum Board Size               | 1200mm x 1200mm                        | Prices increase > 550mm           |
| **Drilling**    | Minimum Drill (Vias)             | 0.25 mm (10 mil)                       | Range: 0.3mm - 6.30mm             |
|                 | Hole Tolerances                  | ± 0.08mm                               | Position tolerance: 0.09mm        |
|                 | Milling Width (Grooves)          | Min. 0.8mm                             | -                                 |
| **Physical**    | PCB Type                         | FR-4 (KB Company)                      | -                                 |
|                 | Board Thickness                  | 0.40mm - 3.00mm                        | ±10% tolerance; 0.6-1.6mm free    |
|                 | Copper Thickness                 | 17um - 100um                           | Default 1oz (35um)                |
|                 | Dielectric Thickness             | 0.075mm - 5.00mm                       | -                                 |
|                 | Dimension Accuracy               | ± 0.2mm                                | Irregular shapes treated as rect. |
| **Mask/Finish** | Solder Mask Min.                 | 0.1 mm (4 mil)                         | -                                 |
|                 | Roundness                        | 0.15 mm @ 100%                         | -                                 |
|                 | Color                            | Red, Blue, Green, White, Yellow, Black | Default: Green                    |
|                 | Plating Finishes                 | HASL, RoHS (Lead-free), ENIG           | -                                 |
| **Special**     | Pour Hypotenuse                  | 30° ~ 60°                              | -                                 |
|                 | Half-Hole / Castellated          | Supported (+$20)                       | Contact before ordering           |
|                 | Impedance Control                | Supported (+$60)                       | -                                 |

### Constraints & Services

- **Unsupported**: Four layer boards, Blind/Buried holes.
- **Testing**: Fully tested by flying probes.
- **Express Options**: 30 Hours (+$42, no ENIG), 53 Hours (+$21).

## ref 

- [[kicad-dat]]