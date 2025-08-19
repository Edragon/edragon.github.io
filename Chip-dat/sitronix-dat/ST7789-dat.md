
# ST7789-dat.md

- datasheet == [[ST7789-DS]]

## C 

```c
ST7789VW_ initial
void LCD_Init(void)
{
    // Hardware reset
    LCD_RES_Clr(); // 复位
    delay_ms(100);
    LCD_RES_Set();
    delay_ms(100);
    LCD_BLK_Set(); // 打开背光
    delay_ms(100);

    // Start Initial Sequence
    LCD_WR_REG(0x11); // Sleep out
    delay_ms(120);

    // Power control and related settings
    LCD_WR_REG(0xC4); LCD_WR_DATA8(0x20);
    LCD_WR_REG(0xC6); LCD_WR_DATA8(0x0F);
    LCD_WR_REG(0xD0); LCD_WR_DATA8(0xA4); LCD_WR_DATA8(0xA1);

    // Positive voltage gamma control
    LCD_WR_REG(0xE0);
    LCD_WR_DATA8(0xD0); LCD_WR_DATA8(0x04); LCD_WR_DATA8(0x0D); LCD_WR_DATA8(0x11);
    LCD_WR_DATA8(0x13); LCD_WR_DATA8(0x2B); LCD_WR_DATA8(0x3F); LCD_WR_DATA8(0x54);
    LCD_WR_DATA8(0x4C); LCD_WR_DATA8(0x18); LCD_WR_DATA8(0x0D); LCD_WR_DATA8(0x0B);
    LCD_WR_DATA8(0x1F); LCD_WR_DATA8(0x23);

    // Negative voltage gamma control
    LCD_WR_REG(0xE1);
    LCD_WR_DATA8(0xD0); LCD_WR_DATA8(0x04); LCD_WR_DATA8(0x0C); LCD_WR_DATA8(0x11);
    LCD_WR_DATA8(0x13); LCD_WR_DATA8(0x2C); LCD_WR_DATA8(0x3F); LCD_WR_DATA8(0x44);
    LCD_WR_DATA8(0x51); LCD_WR_DATA8(0x2F); LCD_WR_DATA8(0x1F); LCD_WR_DATA8(0x1F);
    LCD_WR_DATA8(0x20); LCD_WR_DATA8(0x23);

    // Display inversion and on
    LCD_WR_REG(0x21); // Display inversion on
    LCD_WR_REG(0x29); // Display on
}
```

## arduino code 

```c
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>             // SPI communication library

// Define the pins connected to your ST7789 display
#define TFT_CS 10  // Chip Select pin
#define TFT_RST 9  // Reset pin (or -1 if connected to Arduino's RESET)
#define TFT_DC 8   // Data/Command pin

// Create an Adafruit_ST7789 object
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

void setup(void) {
  Serial.begin(9600);
  Serial.println(F("Hello! ST7789 TFT Test"));

  // Initialize the display
  // Use the correct dimensions for your specific ST7789 display (e.g., 240, 240)
  tft.init(240, 240, SPI_MODE2); // Init ST7789 240x240
  tft.setRotation(2); // Adjust rotation as needed

  Serial.println(F("Initialized"));

  // Fill the screen with black
  tft.fillScreen(ST77XX_BLACK);

  // Set text properties and print "Hello World!"
  tft.setCursor(0, 0);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
  tft.println(F("Hello World!"));
}

void loop() {
  // Your main program loop, display updates, etc.
}
```

## ref 

- [[sitronix-dat]]