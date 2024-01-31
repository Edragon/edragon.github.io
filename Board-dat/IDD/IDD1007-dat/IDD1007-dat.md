
# IDD1007-dat

https://www.electrodragon.com/product/rgb-dot-matrix-display-drive-wifi-board-esp8266/

legacy wiki page - https://www.electrodragon.com/w/Matrix_Display#ESP8266


## Use guide:
- Load sketch into D1 mini, plug on board to panel.
- Connect the 40CM data pin from output of board to panel output.
- Connect power supply from board to panel power pins.
- Optionally turn on/off toggle switch in case the boot pins conflict with D1 mini.
- Power on board or reset D1 mini, optionally turn on all toggle switches.


## Customize 

- If you need chain the panels, [for example 5 32×32 our version outdoor panels](https://twitter.com/electro_phoenix/status/1168376476028133377), please write note how many you need chain, we can add extra longer cable for you.
- [Each extra longer cable 1.5M for 1usd, please buy by add cost via this link.](https://www.electrodragon.com/product/custom-order/)


## Code 

- https://github.com/2dom/PxMatrix
- All demo code in our arduino main github folder - skechbook - ESP Matrix.
- https://github.com/Edragon/arduino-esp8266/tree/master/Sketchbooks/ESP_Matrix

## Demo 

- https://twitter.com/electro_phoenix/status/1138397535762931713
- https://twitter.com/electro_phoenix/status/1146710992497172480

### Testing 

Demo Sketch based on PXMatrix library for our following panels:
- 32x16: Tested OK
- 64x64: Tested OK


## Accesories 

- [[RGB-matrix-panel-dat]]
- [[NWI1083-dat]]

## Version Logs 

### Version V2 

- Longer plug-in pin for input, in case the board have any physical confliction with panel frame
- Side angled output pin header
- Spare pins lead out: 3V3, GND, RST, A0, TXD, RXD, 5V, GND in 2*8 pin header
- ROW_D, ROW_C, ROW_E, OE pin connect to panel via jumper, some pins may not be used, please try by yourself and set them free to use.



## ref 

- [[IDD1007]]