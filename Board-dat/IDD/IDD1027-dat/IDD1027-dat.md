

# IDD1027-dat

- [[ESP32-S3-dat]]

suitable boards - [[ESP32-S3-board-VCC-dat]] - [[ESP32-S3-board-WV-dat]] - [[ESP32-S3-board-dat]] 


- [[protection-power-dat]]

- [[IDD1013-dat]]




## board map 

![](2026-03-12-15-40-24.png)


- IO4_LAT
- IO5_OE
- IO6_CLK

- IO7_A
- IO15_B
- IO16_C
- IO17_D
- IO18_E

- IO08_LDR
- IO3_x
- IO46_x

- IO9_G1
- IO10_B1
- IO11_R1
- IO12_G2
- IO13_B2
- IO14_R2



## default pin for ESP32-S3 

#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>


libraries\ESP32_HUB75_LED_MATRIX_PANEL_DMA_Display\esp32s3-default-pins.hpp

    #pragma once

    // Avoid and QSPI pins

    #define R1_PIN_DEFAULT 4
    #define G1_PIN_DEFAULT 5
    #define B1_PIN_DEFAULT 6
    #define R2_PIN_DEFAULT 7
    #define G2_PIN_DEFAULT 15
    #define B2_PIN_DEFAULT 16

    #define A_PIN_DEFAULT  18
    #define B_PIN_DEFAULT  8
    #define C_PIN_DEFAULT  3
    #define D_PIN_DEFAULT  42
    #define E_PIN_DEFAULT  -1 // required for 1/32 scan panels, like 64x64. Any available pin would do, i.e. IO32
    
    #define LAT_PIN_DEFAULT 40
    #define OE_PIN_DEFAULT  2
    #define CLK_PIN_DEFAULT 41

modified 


    #define G1_PIN_DEFAULT 9
    #define B1_PIN_DEFAULT 10
    #define R1_PIN_DEFAULT 11

    #define G2_PIN_DEFAULT 12
    #define B2_PIN_DEFAULT 13
    #define R2_PIN_DEFAULT 14

    #define A_PIN_DEFAULT  7
    #define B_PIN_DEFAULT  15
    #define C_PIN_DEFAULT  16
    #define D_PIN_DEFAULT  17
    #define E_PIN_DEFAULT  -1

    #define LAT_PIN_DEFAULT 4
    #define OE_PIN_DEFAULT  5
    #define CLK_PIN_DEFAULT 6

## ref 

