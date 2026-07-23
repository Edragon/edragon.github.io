#include "AudioTools.h"
#include "AudioBoard.h"

// 1. Define your pins clearly
#define I2S_BCLK 14
#define I2S_LRCK 12
#define I2S_DOUT 13

#define I2S_MCLK 6

#define I2C_SDA 5
#define I2C_SCL 4

using namespace audio_driver;
using namespace audio_tools;

// 2. Use the correct class: DriverPins
DriverPins my_pins;

// 3. Initialize the board with the driver and pins
AudioBoard board(AudioDriverES8311, my_pins);

// 4. Define Audio Tools objects
AudioInfo info(16000, 2, 16); // STEREO 16kHz (proven working rate)
SineWaveGenerator<int16_t> sineWave(2); // 2 channels
GeneratedSoundStream<int16_t> sound(sineWave);
I2SStream i2s;
VolumeStream volume(i2s);
StreamCopy copier(volume, sound);

void setup()
{
    Serial.begin(115200);
    delay(1000);
    Serial.println("=== ESP32-S3 + ES8311 + NS4150 ===");

    // Define I2S Pins for the driver
    my_pins.addI2S(PinFunction::CODEC, I2S_MCLK, I2S_BCLK, I2S_LRCK, I2S_DOUT);

    // Initialize Wire and add to pins for the driver
    Wire.begin(I2C_SDA, I2C_SCL);
    my_pins.addI2C(PinFunction::CODEC, Wire);

    // Verify I2C
    Wire.beginTransmission(0x18);
    if (Wire.endTransmission() == 0)
        Serial.println("✅ ES8311 found at 0x18");
    else {
        Serial.println("❌ ES8311 NOT found at 0x18!");
        while (true);
    }

    // Configure codec explicitly for DAC playback
    CodecConfig cfg;
    cfg.output_device = DAC_OUTPUT_ALL;
    cfg.i2s.bits = BIT_LENGTH_16BITS;
    cfg.i2s.rate = RATE_16K;
    cfg.i2s.fmt = I2S_NORMAL;
    cfg.i2s.mode = MODE_SLAVE;  // ESP32 is I2S master

    // Start the board with explicit config
    Serial.print("Initializing ES8311... ");
    if (!board.begin(cfg))
    {
        Serial.println("FAILED!");
        while (true);
    }
    Serial.println("OK");
    board.setVolume(1.0);
    Serial.println("ES8311 Driver Initialized.");

    // Configure I2S for Audio Tools
    auto config = i2s.defaultConfig(TX_MODE);
    config.pin_bck = I2S_BCLK;
    config.pin_ws = I2S_LRCK;
    config.pin_data = I2S_DOUT;
    config.pin_mck = I2S_MCLK;
    // Do NOT use APLL at 16kHz — let the driver use default clock division
    config.copyFrom(info);
    Serial.print("Starting I2S... ");
    if (!i2s.begin(config)) {
        Serial.println("FAILED!");
        while (true);
    }
    Serial.println("OK");

    // Initialize VolumeStream
    volume.begin(config);
    volume.setVolume(1.0);

    // Start generator
    sineWave.begin(info, 440); // 440Hz Sine Wave
    sound.begin();

    Serial.println("▶ Streaming 440Hz to ES8311...");
}

void loop()
{
    copier.copy();
}
