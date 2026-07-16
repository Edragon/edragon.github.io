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
using namespace audio_tools;

// 2. Use the correct class: DriverPins
DriverPins my_pins;

// 3. Initialize the board with the driver and pins
AudioBoard board(AudioDriverES8311, my_pins);

// 4. Define Audio Tools objects
AudioInfo info(44100, 1, 16); // Mono, 44.1kHz, 16-bit
SineWaveGenerator<int16_t> sineWave;
GeneratedSoundStream<int16_t> sound(sineWave);
I2SStream i2s;
StreamCopy copier(i2s, sound);

void setup()
{
    Serial.begin(115200);

    // Define I2S Pins for the driver
    my_pins.addI2S(PinFunction::CODEC, I2S_MCLK, I2S_BCLK, I2S_LRCK, I2S_DOUT);

    // Initialize Wire and add to pins for the driver
    Wire.begin(I2C_SDA, I2C_SCL);
    my_pins.addI2C(PinFunction::CODEC, Wire);

    // Start the board (I2C configuration of ES8311)
    if (!board.begin())
    {
        Serial.println("Failed to initialize ES8311 Board!");
        while (true)
            ;
    }
    board.setVolume(0.8); // Set volume (0.0 to 1.0)
    Serial.println("ES8311 Driver Initialized.");

    // Configure I2S for Audio Tools
    auto config = i2s.defaultConfig(TX_MODE);
    config.pin_bck = I2S_BCLK;
    config.pin_ws = I2S_LRCK;
    config.pin_data = I2S_DOUT;
    config.pin_mck = I2S_MCLK;
    config.copyFrom(info);
    i2s.begin(config);

    // Start generator
    sineWave.begin(info, 440); // 440Hz Sine Wave
    sound.begin();

    Serial.println("Streaming Sine Wave to ES8311...");
}

void loop()
{
    copier.copy();
}
