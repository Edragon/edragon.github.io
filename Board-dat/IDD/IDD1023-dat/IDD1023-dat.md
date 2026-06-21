
# IDD1023-dat 


- [[fab-soldering-float]] - [[fab-soldering-float-dat]] - [[fab-soldering-dat]]

- [[HUB12-dat]] - [[HUB75-dat]]

- [[RMP-driver-dat]] - [[IDD1023-dat]]

## Board Map 



## Wiring

![](2023-11-29-15-48-23.png)


* You will need a [[USB-TTL-dat]] adapter bridge board or cable, to interface or program ESP32 via the serial interface

To communicate with ESP32 normally, connect (working mode):
* TXD->RXD, RXD->TXD, +5V=+5V, GND=GND
* remove IO0-GND jumper, IO0 LED should be off

To program ESP32 (flashing mode):
* Connect the same serial interface
* Put **IO0-GND jumper ON**, IO0 LED should be ON
* press reset button to enter into flash mode
* Upload arduino demo code

## Code 

- original library DMD32 - https://github.com/Qudor-Engineer/DMD32
- the code has not maintained for a long while, please use old version of arduino ESP32, please refer to the video below
- https://github.com/Edragon/Arduino-ESP32
- please use the standard code in folder - Arduino-ESP32/libraries
/DMD32-main/


correct pin definitions in DMD32.h

    #warning CHANGE THESE TO SEMI-ADJUSTABLE PIN DEFS!
    //ESP32 pins used for the display connection (Using VSPI)

    #define PIN_DMD_nOE		22 		// D22 active low Output Enable, setting this low lights all the LEDs in the selected rows. Can pwm it at very high frequency for brightness control.
    #define PIN_DMD_A		19		// D19
    #define PIN_DMD_B		21		// D21
    #define PIN_DMD_CLK		18		// D18_SCK  is SPI Clock if SPI is used
    #define PIN_DMD_SCLK		2		// D02
    #define PIN_DMD_R_DATA    23	// D23_MOSI is SPI Master Out if SPI is used

## Demo Early Test 

use guide - https://www.youtube.com/shorts/mtdM9uB3fyo

correct test: https://twitter.com/electro_phoenix/status/1434776186354241536

test in error: https://twitter.com/electro_phoenix/status/1427971402561327106





## demo video 

- https://t.me/electrodragon3/187
- https://t.me/electrodragon3/196


## ref 

- [[RMP-driver-dat]]

- [[IDD1023]] - [[IDD1023-fab]]

- [[ESP-SDK-dat]]