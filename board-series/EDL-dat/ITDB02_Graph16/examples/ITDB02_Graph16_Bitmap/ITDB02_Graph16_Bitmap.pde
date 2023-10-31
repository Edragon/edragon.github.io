// ITDB02_Graph16_Bitmap (C)2010 Henning Karlsen
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
// This demo will work on the ITDB02-3.2WC module, but
// keep in mind that this demo was also made to work on
// the 240x320 modules, so it will not use the added 
// pixels of the ITDB02-3.2WC.
//

#include <ITDB02_Graph16.h>
#include <avr/pgmspace.h>

// Declare which fonts we will be using
extern uint8_t SmallFont[];

// Uncomment the next line for the ITDB02 Shield
//ITDB02 myGLCD(19,18,17,16);   // Remember to add ASPECT_16x9 if you are using an ITDB02-3.2WC!

// Uncomment the next line for the ITDB02 Mega Shield
ITDB02 myGLCD(38,39,40,41);   // Remember to add ASPECT_16x9 if you are using an ITDB02-3.2WC!

extern unsigned int info[0x400];
extern unsigned int icon[0x400];
extern unsigned int tux[0x400];

void setup()
{
  myGLCD.InitLCD(LANDSCAPE);
  myGLCD.setFont(SmallFont);
}

void loop()
{
  myGLCD.fillScr(255, 255, 255);
  myGLCD.setColor(255, 255, 255);
  myGLCD.print(" *** A 10 by 7 grid of a 32x32 icon *** ", CENTER, 228);
  for (int x=0; x<10; x++)
    for (int y=0; y<7; y++)
      myGLCD.drawBitmap (x*32, y*32, 32, 32, info);

  delay(5000);
  
  myGLCD.fillScr(255, 255, 255);
  myGLCD.setColor(255, 255, 255);
  myGLCD.print("   Two different icons in scale 1 to 4  ", CENTER, 228);
  int x=0;
  for (int s=0; s<4; s++)
  {
    x+=(s*32);
    myGLCD.drawBitmap (x, 0, 32, 32, tux, s+1);
  }
  x=0;
  for (int s=4; s>0; s--)
  {
    myGLCD.drawBitmap (x, 224-(s*32), 32, 32, icon, s);
    x+=(s*32);
  }

  delay(5000);
}

