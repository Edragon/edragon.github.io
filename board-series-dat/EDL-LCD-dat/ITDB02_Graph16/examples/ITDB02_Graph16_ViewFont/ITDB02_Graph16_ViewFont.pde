// ITDB02_Graph16_ViewFont (C)2010 Henning Karlsen
// web: http://www.henningkarlsen.com/electronics
//
// This program is a demo of the included fonts.
//
// This program requires the ITDB02_Graph16 (16bit mode).
//
// It is assumed that the ITDB02 module is connected to a
// ITDB02 Shield, a ITDB02 Mega Shield or that you know how 
// to change the pin numbers in the setup.
//
// *** This sketch requires that the large font is enabled for a correct display.


#include <ITDB02_Graph16.h>

// Declare which fonts we will be using
extern uint8_t SmallFont[];
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
}

void loop()
{
  myGLCD.setColor(0, 255, 0);
  myGLCD.setBackColor(0, 0, 0);

  myGLCD.setFont(BigFont);
  myGLCD.print(" !\"#$%&'()*+,-./", CENTER, 0);
  myGLCD.print("0123456789:;<=>?", CENTER, 16);
  myGLCD.print("@ABCDEFGHIJKLMNO", CENTER, 32);
  myGLCD.print("PQRSTUVWXYZ[\\]^_", CENTER, 48);
  myGLCD.print("`abcdefghijklmno", CENTER, 64);
  myGLCD.print("pqrstuvwxyz{|}~ ", CENTER, 80);

  myGLCD.setFont(SmallFont);
  myGLCD.print(" !\"#$%&'()*+,-./0123456789:;<=>?", CENTER, 120);
  myGLCD.print("@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_", CENTER, 132);
  myGLCD.print("`abcdefghijklmnopqrstuvwxyz{|}~ ", CENTER, 144);

  myGLCD.setFont(SevenSegNumFont);
  myGLCD.print("0123456789", CENTER, 190);

  while(1) {};
}

