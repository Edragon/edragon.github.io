# mark-point-dat

## Why

Mark points, also known as fiducial markers, provide common measurable points for all steps in the assembly process, ensuring that each device used for assembly can accurately locate the circuit pattern. Therefore, mark points are crucial for SMT production.

The PCB must have a pair of Mark points on the diagonal of the board's long side for overall board positioning. 

Chips with an integrated circuit pin center distance of less than 0.65mm on the board need a pair of Mark points on the diagonal of the integrated circuit's long side for chip positioning. 

If both sides of the PCB have surface mount components, Mark points should be added to both sides according to this rule.

## Mark Shape

![](2025-04-01-16-27-50.png)

- **Shape**: It is recommended that the Mark point be marked as a solid circle with a diameter of D=1.0mm;
- **A complete MAR point consists of**: a marking point (or feature point) and an empty area.
- **Position**: Mark points are located diagonally opposite each other on a single board or panel and are as far apart as possible; it is best to distribute them at the longest diagonal position (as shown in the MAR point position diagram).
- **Quantity requirements**: Each PCB must have at least two MAR points that meet the design requirements and can be recognized by the machine.
- When panelizing, the relative position of the MAR points on each single board must be the same. The position of the MAR point on any single board in the panel cannot be moved for any reason.
- The distance from the MAR point (edge of the clear area) to the PC edge must be > 5.0mm (minimum spacing requirement for machine clamping PC) (as shown in the MAR point position diagram).