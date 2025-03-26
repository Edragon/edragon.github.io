
# MPC1130-dat

- board use guide please refer to page [[RMP-driver-dat]]

https://www.electrodragon.com/product/rpi-passive-3ch-rgb-matrix-drive-board-v0/



## Board map 

![](2024-12-08-17-15-49.png)

- reserved pull resistor for P18 IO1 (not soldered)

## Extra Pins 

![](2024-12-08-17-13-39.png)

- ROW_E GND Sel_8 Sel_8 SC
- ROW_E GND Sel_8 Sel_8 SC

## demo video 

- https://www.youtube.com/shorts/7zcytJmziE4

## Summary of LED Control Board Feedback

Board Compatibility & Performance:

- The passive-3 control board works well with ABCDE panels without requiring additional GPIO slowdown
- With ABC panels (using shift registers), it needs high GPIO slowdown (--led-slowdown-gpio=8)
- Comparatively, the active board requires only --led-slowdown-gpio=7 to function properly

For two types of **flexible** P2 128x64 panels:

- ABCDE panels have problematic magnetic connectors (2.5mm screws too shallow)
- ABC panels have better 3mm screw frames but require shift register handling

Chip Compatibility:

- New chips (SM5368 and DP32020A) have subtle timing incompatibilities with rpi-rgb-panel software
- This issue needs further debugging with a logic analyzer

## update Logs 

Current version is V1 to quick start 

### further change

- default setup like this: 
    - 4   ROW-E --- 8  
    - So Row-e has a trace already connected to pin 8, and it will "just work" by default.
- clear instruction how to connect the board 
- added slik print to mark clearly of the orders of the connectors 
- have two pins on the board to easily attach 5 volts


## ref 

- [[RPI3-dat]]

