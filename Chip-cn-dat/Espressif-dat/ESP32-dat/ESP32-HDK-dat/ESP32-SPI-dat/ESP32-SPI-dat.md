
# ESP32-SPI-dat 

| Pin  | VSPI  | HSPI    |
| ---- | ----- | ------- |
| 3V3  | 3.3V  |         |
| CS   | io 5  | 15 / 27 |
| CLK  | io 18 | 14      |
| MISO | io 19 | 12      |
| MOSI | io 23 | 13      |
| GND  | GND   |         |



SPI arduino define

    #define VSPI_MISO   MISO
    #define VSPI_MOSI   MOSI
    #define VSPI_SCLK   SCK
    #define VSPI_SS     SS  

    #define HSPI_MISO   12
    #define HSPI_MOSI   13
    #define HSPI_SCLK   14
    #define HSPI_SS     15

## sketch refer to here: 


hspi.begin(HSPI_CLK, HSPI_MISO, HSPI_MOSI, HSPI_SS);


    #include "FS.h"
    #include "SD.h"
    #include "SPI.h"

    SPIClass spiSD(HSPI);
    #define SD_CS 15

    void setup() {
        Serial.begin(115200);
        spiSD.begin(14, 12, 13, SD_CS ); //SCK, MISO, MOSI, SS //HSPI1 // hspi.begin(HSPI_CLK, HSPI_MISO, HSPI_MOSI, HSPI_SS);
        
        if (!SD.begin( SD_CS, spiSD )) {
            // if(!SD.begin()){
                Serial.println("Card Mount Failed");
                return;
            }
    }

    void loop() {
    }



- [[RA-01]]