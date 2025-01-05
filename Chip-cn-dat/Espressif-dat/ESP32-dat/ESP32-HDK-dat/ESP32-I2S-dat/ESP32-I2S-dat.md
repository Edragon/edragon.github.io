
# ESP32-I2S-dat

- [[ESP32_PCM5102.ino]] - [[I2S-dat]]


The ESP32-WROVER module supports I2S (Inter-IC Sound) communication, which is typically used for audio data transmission. The I2S peripheral allows the ESP32 to act as a transmitter (master or slave) or receiver of audio data.

The I2S pins can be assigned to almost any GPIO pin using the ESP32's **flexible pin mapping**, but the default pins are often used for convenience.


## The default I2S pins for ESP32-WROVER are typically:

| Signal                                   | Default GPIO |
| ---------------------------------------- | ------------ |
| I2S_WS (word select, also known as LRCK) | 25           |
| I2S_BCK (bit clock)                      | 26           |
| I2S_SD_OUT (serial data out, TX)         | 22           |
| I2S_SD_IN (serial data in, RX)           | 35           |





## I2S devices 

- [[MAX98357-dat]] - [[MSM261S4030H0R-dat]] - [[INMP441-dat]]


## demo code 

- use dual I2S, please note the code generate by AI [[dual-i2s.ino]]

| **Signal**       | **I2S0 GPIO Pin** | **I2S1 GPIO Pin** |
| ---------------- | ----------------- | ----------------- |
| BCLK (Bit Clock) | 26                | 19                |
| WS (LRCLK)       | 25                | 18                |
| DOUT (Data Out)  | 22                | Not used (-1)     |
| DIN (Data In)    | Not used (-1)     | 23                |

- [[arduino-lib-dat]]


## ref 

- Espressif has their usual [excellent documentation](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/i2s.html) for I2S on the ESP32, it can link you to more information.