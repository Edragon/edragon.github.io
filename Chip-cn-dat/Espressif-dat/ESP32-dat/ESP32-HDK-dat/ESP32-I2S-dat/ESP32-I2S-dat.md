
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


## Simple tone ino

setup 

    const int frequency = 600;    // Frequency of the square wave in Hz (600 cycles per second)
    const int amplitude = 500;    // Amplitude of the square wave (controls loudness)
    const int sampleRate = 4000;  // Sample rate in Hz (samples per second for accurate waveform)

    // Define I2S bit depth (16 bits per audio sample)
    i2s_data_bit_width_t bps = I2S_DATA_BIT_WIDTH_16BIT;  

    // Define the I2S communication mode (standard protocol)
    i2s_mode_t mode = I2S_MODE_STD;  

    // Define I2S slot mode (stereo sends data to both left and right channels)
    i2s_slot_mode_t slot = I2S_SLOT_MODE_STEREO;  


- [[audio-dat]]


## AudioI2S

- soundrecorder - https://github.com/Edragon/esp32_SoundRecorder
- music_player - https://github.com/Edragon/esp32_MusicPlayer
- https://github.com/Edragon/ESP32-S3-I2Saudio


- repo - https://github.com/schreibfaul1/ESP32-audioI2S
- ⚠️ This library only works on multi-core ESP32 chips like the ESP32-S3. It does not work on the ESP32-S2 or the ESP32-C3 ⚠️

- [[arduino-ESP32-dat]]


## ref 

- Espressif has their usual [excellent documentation](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/i2s.html) for I2S on the ESP32, it can link you to more information.

- [[ESP32-wroom-dat]]