
# ESP32 SPI 

- 3V3	- 3.3V
- CS	- GPIO 5
- MOSI	- GPIO 23
- CLK	- GPIO 18
- MISO	- GPIO 19
- GND	- GND




## ESP32 Software SPI Interface

- SPI_CS = IO15 or IO27
- SPI_MOSI = IO13
- SPI_CLK = IO14
- SPI_MISO = IO12


- sketch refer to here: 



SPI	MOSI	MISO	SCLK	CS
VSPI	GPIO 23	GPIO 19	GPIO 18	GPIO 5
HSPI	GPIO 13	GPIO 12	GPIO 14	GPIO 15



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