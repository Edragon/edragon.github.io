

# RGB matrix panel dat 

## Panel Specifications 

![](39-44-14-03-08-2023.png)

| type | dots  | size CM   |
| ---- | ----- | --------- |
| P3   | 64x64 | 19x19     |
| P6   | 32x32 | 19x19     |
| P8   | 32x16 | 25.6x12.8 |



| Type | LED SPECs | XY LEDs | subtotal | Dimension      | Usage              | Scan | Power | Status  |
| ---- | --------- | ------- | -------- | -------------- | ------------------ | ---- | ----- | ------- |
| P3   | 3mm       | 64 x 64 | 4096     | 19 x 19 CM     | Indoor Display     | 1/32 | ~20W  | selling |
| P4   | 4mm       | 64 x 32 | 2048     | 25.6 x 12.8 CM | Indoor Display     |      |       | N/A     |
| P6   | 6mm 3535  | 32 x 32 | 1024     | 19 x 19 CM     | Outdoor, wateproof | 1/8  | ~30W  | selling |
| P8   | 8mm 3535  | 32 x 16 | 512      | 25.6 x 12.8 CM | Outdoor, wateproof | 1/4  | ~30W  | selling |

- type = LED pitch 

* Life time 1000,000,000 hours.
* Drive constant current, dynamic
* Flash rate 2000Hz



## Code Documentation
- Demo code supported for Raspberry Pi, code revised from here https://github.com/hzeller/rpi-rgb-led-matrix, compatible and mostly same except transfomer part, original code can not well support our this type.
- https://www.electrodragon.com/w/RPI_Matrix
- Demo video available here. - https://www.youtube.com/watch?v=wN-cqQ_2kNs
- Raspberry Pi adapter board is available here. https://www.electrodragon.com/product/rgb-matrix-panel-drive-board-raspberry-pi/


## Accessories Included

- power cable --> 2-to-2,  4pin 3.96mm to "Y" connector power cable.
- data cable [[HUB75]] --> Include 16P ribbon cable for HUB75 connector to drive board.

for outdoor ONLY P6 and P8 
- 4pcs magnetic snap screw, can be snapped on you metal frame. Screw specs is M3, Dia. 13mm, L 12mm.
- waterproof rubber seal ring

## read more 

- [[full-panel-installation]]
  
## Links 

- [[ILE1058-dat]] - [[ILE1059-dat]] - [[ILE1060-dat]] - [[RGB-matrix-panel-dat]]

- [[mono-matrix-panel-dat]] 

- [[led-rgb-panel]]