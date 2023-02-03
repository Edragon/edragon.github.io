
# IDD1013 DAT

![](2022-07-26-17-41-46.png)

- DMA version 
- https://w.electrodragon.com/w/ESP32_DMA_RMP


# Code And Test Demo 

- lib: https://github.com/mrfaptastic/ESP32-HUB75-MatrixPanel-I2S-DMA



### new lib pin definitions 

    file: esp32-default-pins.cpp

    #define R1_PIN_DEFAULT  25
    #define G1_PIN_DEFAULT  26
    #define B1_PIN_DEFAULT  27
    #define R2_PIN_DEFAULT  14
    #define G2_PIN_DEFAULT  12
    #define B2_PIN_DEFAULT  13

    #define A_PIN_DEFAULT   23
    #define B_PIN_DEFAULT   19
    #define C_PIN_DEFAULT   5
    #define D_PIN_DEFAULT   17
    #define E_PIN_DEFAULT   -1 // IMPORTANT: Change to a valid pin if using a 64x64px panel.
                
    #define LAT_PIN_DEFAULT 4
    #define OE_PIN_DEFAULT  15
    #define CLK_PIN_DEFAULT 16


### old setup file 

    #include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>

### board pin definitions 

    #define R1_PIN_DEFAULT  25
    #define G1_PIN_DEFAULT  26
    #define B1_PIN_DEFAULT  27
    #define R2_PIN_DEFAULT  14
    #define G2_PIN_DEFAULT  12
    #define B2_PIN_DEFAULT  13

    #define A_PIN_DEFAULT   23
    #define B_PIN_DEFAULT   19
    #define C_PIN_DEFAULT   5
    #define D_PIN_DEFAULT   33
    #define E_PIN_DEFAULT   18 // IMPORTANT: Change to a valid pin if using a 64x64px panel.
            
    #define LAT_PIN_DEFAULT 4
    #define OE_PIN_DEFAULT  15
    #define CLK_PIN_DEFAULT 32


### ENV 
- [[arduino-IDE]] - 1.8.19
- lib - version 3.0.5
- esp32 2.0.6




### note

- better test with a 32 x 64 panel 
- 64 x 64 will need to setup E-line
- result 
![](32-17-14-03-02-2023.png)