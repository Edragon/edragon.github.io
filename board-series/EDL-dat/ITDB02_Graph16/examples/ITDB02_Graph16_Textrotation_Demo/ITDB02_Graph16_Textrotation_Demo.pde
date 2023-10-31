// ITDB02_Graph16_Textrotation_Demo (C)2010 Henning Karlsen
// web: http://www.henningkarlsen.com/electronics
//
// This program is a demo of the textrotation-functions.
//
// This program requires the ITDB02_Graph16 (16bit mode).
//
// It is assumed that the ITDB02 module is connected to a
// ITDB02 Shield, a ITDB02 Mega Shield or that you know how 
// to change the pin numbers in the setup.
//
// This demo will work on the ITDB02-3.2WC module, but
// keep in mind that this demo was also made to work on
// the 240x320 modules, so it will not use the added 
// pixels of the ITDB02-3.2WC.
//

#include <ITDB02_Graph16.h>

// Declare which fonts we will be using
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];

// Uncomment the next line for the ITDB02 Shield
//ITDB02 myGLCD(19,18,17,16);   // Remember to add ASPECT_16x9 if you are using an ITDB02-3.2WC!

// Uncomment the next line for the ITDB02 Mega Shield
ITDB02 myGLCD(38,39,40,41);   // Remember to add ASPECT_16x9 if you are using an ITDB02-3.2WC!

void setup()
{
  myGLCD.InitLCD(LANDSCAPE);
  myGLCD.clrScr();
  myGLCD.setFont(BigFont);
}

void loop()
{
    myGLCD.print("Text rotation", 0, 0);
    myGLCD.setColor(0, 0, 255);
    myGLCD.print("0 degrees", 0, 16, 0);
    myGLCD.print("90 degrees", 319, 0, 90);
    myGLCD.print("180 degrees", 319, 239, 180);
    myGLCD.print("270 degrees", 0, 239, 270);

    myGLCD.setFont(SevenSegNumFont);
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("45", 90, 100, 45);
    myGLCD.print("90", 200, 50, 90);
    myGLCD.print("180", 300, 200, 180);

  while (true) {};
}

