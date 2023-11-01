// ITDB02_Graph16_Rotate_Bitmap (C)2010 Henning Karlsen
// web: http://www.henningkarlsen.com/electronics
//
// This program is a demo of the drawBitmap()-function.
//
// This program requires the ITDB02_Graph16 (16bit mode).
//
// It is assumed that the ITDB02 module is connected to a
// ITDB02 Shield, a ITDB02 Mega Shield or that you know how 
// to change the pin numbers in the setup.
//

#include <ITDB02_Graph16.h>
#include <avr/pgmspace.h>

// Uncomment the next line for the ITDB02 Shield
//ITDB02 myGLCD(19,18,17,16);   // Remember to add ASPECT_16x9 if you are using an ITDB02-3.2WC!

// Uncomment the next line for the ITDB02 Mega Shield
ITDB02 myGLCD(38,39,40,41);   // Remember to add ASPECT_16x9 if you are using an ITDB02-3.2WC!

extern unsigned int tux[0x400];

void setup()
{
  myGLCD.InitLCD(LANDSCAPE);
  myGLCD.fillScr(255, 255, 255);
  myGLCD.setColor(0, 0, 0);
}

void loop()
{
    for (int i=0; i<360; i+=5)
    {
      myGLCD.drawBitmap (100, 100, 32, 32, tux, i, 16, 16);
    }
}

