# ESP32-P4-SDK-dat

- [[ESP-IDF-vscode-dat]]

## relevant library 

| Library Name              | Description                                 | Version  | Installation Requirement   |
|---------------------------|---------------------------------------------|----------|---------------------------|
| GFX_Library_for_Arduino   | GFX library for SH8601                      | v1.6.0   | Offline installation      |
| lvgl                      | LVGL graphics library                       | v9.3.0   | Recommended offline       |
| displays                  | I2C driver, display and touch definitions   | —        | Offline installation      |
| lv_conf.h                 | LVGL configuration file                     | —        | Offline installation      |


## demos 

| Demo Name            | Description                                                                 | Dependencies                        |
|----------------------|-----------------------------------------------------------------------------|-------------------------------------|
| HelloWorld           | Demonstrates basic graphics library features, tests display performance, random text | GFX_Library_for_Arduino, displays   |
| Drawing_board        | Touch drawing test                                                           | GFX_Library_for_Arduino, displays   |
| AsciiTable           | Prints ASCII characters by row/column based on screen size                    | GFX_Library_for_Arduino, displays   |
| GFX_ESPWiFiAnalyzer  | Draws WiFi band signal strength on screen                                     | GFX_Library_for_Arduino, displays   |
| LVGLV9_Arduino       | LVGL demo                                                                    | LVGL, GFX_Library_for_Arduino, displays |



## ref 

- [[ESP-SDK-dat]]