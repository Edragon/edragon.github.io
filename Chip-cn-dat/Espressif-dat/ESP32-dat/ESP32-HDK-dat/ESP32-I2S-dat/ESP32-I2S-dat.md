
# ESP32-I2S-dat

- [[ESP32_PCM5102.ino]]


The ESP32-WROVER module supports I2S (Inter-IC Sound) communication, which is typically used for audio data transmission. The I2S peripheral allows the ESP32 to act as a transmitter (master or slave) or receiver of audio data.

The I2S pins can be assigned to almost any GPIO pin using the ESP32's **flexible pin mapping**, but the default pins are often used for convenience.


## The default I2S pins for ESP32-WROVER are typically:

| Signal                                   | Default GPIO |
| ---------------------------------------- | ------------ |
| I2S_WS (word select, also known as LRCK) | GPIO25       |
| I2S_BCK (bit clock)                      | GPIO26       |
| I2S_SD_OUT (serial data out, TX)         | GPIO22       |
| I2S_SD_IN (serial data in, RX)           | GPIO35       |