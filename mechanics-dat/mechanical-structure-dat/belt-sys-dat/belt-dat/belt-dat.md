


# belt-dat


## open loop belt 

GT2_Belt_6mm



## 闭环同步带


GT2-6-200（2mm pitch，6mm 宽，200mm 周长）




## 紧张方案

✅ 方案 2：惰轮张紧（最优雅）
      O  ← 惰轮
     / \
====     ====


惰轮压在同步带背面

微调惰轮位置即可张紧

优点

中心距可固定

微调方便

张力可控

缺点：

多一个轮子

占空间




Compact closed-loop GT2 timing belt configuration and length calculation.

## Overview
- Belt type: GT2 (2 mm pitch)
- Belt width: 6 mm
- Pulley teeth (both ends): 20T × 2 (1:1 drive)
- Center distance (C): 149 mm

## Formulas
- Pulley pitch diameter:

  D = (T × P) / π

  where
  - D = pulley pitch diameter (mm)
  - T = number of teeth
  - P = belt pitch (mm)

- Closed-loop belt length for two equal pulleys (1:1):

  L = 2C + πD

  where
  - L = belt pitch-line length (mm)
  - C = center distance between shafts (mm)

## Example calculation (20T GT2 pulley)
1. Pulley pitch diameter:

   T = 20 teeth
   P = 2 mm

   D = (20 × 2) / π ≈ 40 / π ≈ 12.73 mm

2. Belt length:

   L = 2 × 149 + π × 12.73
   L ≈ 298 + 40 = 338 mm

## Recommendation
- Preferred standard belt: **GT2-6-340** (GT2, 6 mm width, 340 mm circumference) — strongly recommended.
- GT2-6-338 is not a standard size and is hard to source.
- Choose the 340 mm belt and use an adjustable tensioning mechanism (tensioner or idler) to take up the ~2 mm difference.

## Summary (specifications)
- Pitch: GT2 (2 mm)
- Width: 6 mm
- Recommended belt circumference: 340 mm
- Pulleys: 20T × 2 (both ends)
- Center distance: 149 mm

Notes:
- Using a standard 340 mm belt simplifies sourcing and inventory.
- Use a tensioner to ensure proper belt tension and compensate for the small length difference.