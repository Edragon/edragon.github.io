# ES8311-SDK-dat

- [[ES8311-SDK-dat]] - [[ES8311-dat]] - [[everest-semi-dat]] - [[ES7201-dat]] - [[codec-audio-dat]] - [[I2S-dat]]

- [[NS4150-dat]]

https://github.com/espressif/esp-idf/blob/master/examples/peripherals/i2s/i2s_codec/i2s_es8311/main/i2s_es8311_example.c

    I2C device found at address 0x18  !

    "Chip ID: 0x8311": If you see this, your I2C wiring (SDA/SCL) is correct.

## Example 1: Music Playback

This example demonstrates how to play music using an ESP32-C3 development board. If you are using an ESP32-S3, you simply need to switch the target chip in the project configuration. This guide is based on modifications to the official ESP-IDF example.

### 1. Locate the Example

- [[ESP-IDF-dat]] - [[VScode-dat]]

- **Original Path**: `esp-idf-v5.4.1\examples\peripherals\i2s\i2s_codec\i2s_es8311`
- **Action**: Copy the `i2s_es8311` folder to your local working directory (e.g., `D:\esp32c3\i2s_es8311`).

### 2. Project Setup
1. Open **VS Code**.
2. Open the `i2s_es8311` project folder.

### 3. Hardware Pin Configuration
The ES8311 codec connects to the ESP32 via two interfaces:
- **I2S**: For digital audio data transmission.
- **I2C**: For chip configuration and control.

Open `example_config.h` to adjust the pin definitions (usually found between lines 24–35). These are wrapped in conditional compilation blocks depending on the ESP32 model.

#### For ESP32-C3:
Update the I2C pins (lines 33–34) to match your board. The example below uses **GPIO 1** for SCL and **GPIO 0** for SDA:

```c
// example_config.h
#define I2C_SCL_IO           (GPIO_NUM_1)
#define I2C_SDA_IO           (GPIO_NUM_0)
```

## pschatzmann/arduino-audio-tools

Install both libraries: You will need both the main `arduino-audio-tools` and the `arduino-audio-driver`.

- [[audio-dat]] - [[codec-dat]] - [[arduino-audio-dat]] - [[arduino-dat]]

https://github.com/pschatzmann/arduino-audio-driver

https://github.com/pschatzmann/arduino-audio-tools


    #include "AudioTools.h"
    #include "AudioBoard.h"

    // 1. Define your pins clearly
    #define I2S_BCLK 5
    #define I2S_LRCK 4
    #define I2S_DOUT 6
    #define I2S_MCLK 2

    #define I2C_SDA 18
    #define I2C_SCL 19

    using namespace audio_driver;

    // 2. Use the correct class: DriverPins
    DriverPins my_pins;

    // 3. Initialize the board with the driver and pins
    // AudioDriverES8311 is a static instance provided by the library
    AudioBoard board(AudioDriverES8311, my_pins);

    void setup() {
        Serial.begin(115200);

        // Define I2S Pins
        my_pins.addI2S(PinFunction::CODEC, I2S_MCLK, I2S_BCLK, I2S_LRCK, I2S_DOUT);
        
        // Initialize Wire and add to pins
        Wire.begin(I2C_SDA, I2C_SCL);
        my_pins.addI2C(PinFunction::CODEC, Wire);

        // Start the board
        if (!board.begin()) {
            Serial.println("Failed to initialize ES8311 Board!");
            while (true);
        }
        Serial.println("ES8311 Initialized Successfully.");
    }

    void loop() {
        delay(1000);
    }


## ref 

https://gitlab.informatik.uni-bremen.de/fbrning/esp-idf/-/blob/v5.0-dev/examples/peripherals/i2s/i2s_es8311/main/i2s_es8311_example.c?ref_type=tags

https://github.com/pschatzmann/arduino-audio-tools


- [[ES8311]]