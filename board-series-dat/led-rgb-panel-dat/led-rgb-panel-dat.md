# RGB matrix panel dat

We sell the highly reliable, high quality panels. Probably the top quality from local top factory.

https://www.electrodragon.com/product/rgb-full-color-led-matrix-panel/


## Panel Specifications

![](39-44-14-03-08-2023.png)

| type | dots  | size CM   |
| ---- | ----- | --------- |
| P3   | 64x64 | 19x19     |
| P6   | 32x32 | 19x19     |
| P8   | 32x16 | 25.6x12.8 |

| Type | LED SPECs | XY LEDs | subtotal | Dimension      | spec         | Usage              | Scan | Power | Status  | SKU             | intern |
| ---- | --------- | ------- | -------- | -------------- | ------------ | ------------------ | ---- | ----- | ------- | --------------- |- |
| P3   | 3mm       | 64 x 64 | 4096     | 19 x 19 CM     | 1919_6464_3  | Indoor Display     | 1/32 | ~20W  | selling | [[ILE1060-dat]] |
| P4   | 4mm       | 64 x 32 | 2048     | 25.6 x 12.8 CM | 2613_6432_4  | Indoor Display     |      |       | N/A     |                 |
| P5   | 5mm       | 64 x 32 |          |                |              |                    |      |       |         |                 |
| P6   | 6mm 3535  | 32 x 32 | 1024     | 19 x 19 CM     | 1919_3232_6  | Outdoor, wateproof | 1/8  | ~30W  | selling | [[ILE1059-dat]] |
| P8-1 | 8mm       | 32 x 16 | 512      | 25.6 x 12.8 CM | 2613_3216_8  | Outdoor, wateproof | 1/4  | ~30W  | selling | [[ILE1058-dat]] | [[ILE1058]]
| P8-2 | 8mm       | 40 x 20 | 800      | 32 x 16 CM     | 3216_4020_8  | Outdoor, wateproof | 1/4  | ~30W  | selling |                 |
| P10  | 10mm 3535 | 32 x 16 | 512      | 32 x 16 CM     | 3216_3216_10 |                    |      |       |         |                 |


- type = LED pitch

* Life time 1000,000,000 hours.
* Drive constant current, dynamic
* Flash rate 2000Hz

## Code Documentation

- Demo code supported for Raspberry Pi, code revised from here https://github.com/hzeller/rpi-rgb-led-matrix, compatible and mostly same except transfomer part, original code can not well support our this type.
- https://www.electrodragon.com/w/RPI_Matrix
- Demo video available here. - https://www.youtube.com/watch?v=wN-cqQ_2kNs
- Raspberry Pi adapter board is available here. https://www.electrodragon.com/product/rgb-matrix-panel-drive-board-raspberry-pi/

## Packge and Accessories Included

- power cable --> 2-to-2,  4pin 3.96mm to "Y" connector power cable. ONLY 50% cables will be inlcuded, since each power cable has two outputs, and you can use one cable for two panels. 
- data cable for [[HUB75-dat]] --> Include 16P ribbon cable for HUB75 connector to drive board.
- 4pcs magnetic snap screw, can be snapped on you metal frame. Screw specs is M3 OR M4, Dia. 13mm, L 12mm.

for outdoor ONLY P6 and P8
- waterproof rubber seal ring




## Matrix Panels Development 

Gen-1: Basic HUB75 panels using 4–5 address lines, simple driver chips (ICN2037BP, FM6124), and separate row decoder chips (like 74HC138 or FM6124A). These panels are compatible with the Adafruit MatrixPortal S3, RP2040, and Adafruit libraries.

Gen-2: Panels with smart driver chips (like ICND2038S or ICND2153) that handle internal row multiplexing and require initialization sequences. These may use fewer address lines and are not compatible with most simple microcontroller libraries without modifications. There are some great libraries on Github that provide control of these panels using an Raspberry Pi controller.

Gen-3: Advanced grayscale panels using chips like MBI5153 or ICND2153 that support PWM or stacked PWM (S-PWM) for high refresh rates and deep color. These require precise signal timing and are typically driven with FPGAs or heavily modified firmware. Some GitHub projects have figured out how to support these.

[reference from here.](https://rpi-rgb-led-matrix.discourse.group/t/trying-to-get-an-overall-understanding-on-led-matrix-panels/1075/4)

## read more

- [[magnetic-screw-dat]] - [[led-full-panel-installation]]

- chips perforamcne issues [[led-rgb-panel-chip-dat]]

## Links

- [[ILE1058-dat]] - [[ILE1059-dat]] - [[ILE1060-dat]] - [[led-rgb-panel-dat]]
  
- [[mono-matrix-panel-dat]] 

- [[led-rgb-panel]]


## ref 

- [[HUB75-dat]]