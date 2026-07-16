#include "AudioTools.h"
#include "AudioBoard.h"

// 1. Define your pins clearly
#define I2S_BCLK 5
#define I2S_LRCK 4
#define I2S_DOUT 6
#define I2S_MCLK 2

#define I2C_SDA 18
#define I2C_SCL 17

#define I2S_DIN  7  // I2S Data Input (from ES8311 to ESP32)

using namespace audio_driver;
using namespace audio_tools;

// 2. Use the correct class: DriverPins
DriverPins my_pins;

// 3. Initialize the board with the driver and pins
AudioBoard board(AudioDriverES8311, my_pins);

// 4. Define Audio Tools objects
AudioInfo info(16000, 1, 16); // 16kHz for better Serial printing performance
I2SStream i2s;
StreamCopy copier(Serial, i2s); // Directly copy Binary data to Serial, or use a custom print loop

void setup()
{
    Serial.begin(115200);
    while(!Serial); // Wait for Serial to be ready

    // Define I2S Pins for the driver (Include DIN pin)
    my_pins.addI2S(PinFunction::CODEC, I2S_MCLK, I2S_BCLK, I2S_LRCK, I2S_DOUT, I2S_DIN);

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
    
    // Configure for Input (Microphone) using setConfig
    CodecConfig codec_config;
    codec_config.input_device = ADC_INPUT_LINE1; // Use Line 1 for Microphone
    codec_config.i2s.rate = RATE_16K;            // Match the I2S rate
    codec_config.i2s.channels = CHANNELS2;       // Use CHANNELS2 (Stereo) as it's the minimum supported in this driver version
    board.setConfig(codec_config);
    
    board.setInputVolume(100); // Set Input gain to maximum (usually 0-100)
    Serial.println("ES8311 Mic Driver Initialized.");

    // Configure I2S for Input
    auto config = i2s.defaultConfig(RX_MODE); 
    config.pin_bck = I2S_BCLK;
    config.pin_ws = I2S_LRCK;
    config.pin_data = I2S_DIN;
    config.pin_mck = I2S_MCLK;
    config.use_apll = true; 
    config.copyFrom(info);
    i2s.begin(config);

    Serial.println("Reading Microphone data and printing integers to Serial...");
}

void loop()
{
    int16_t sample;
    if (i2s.readBytes((uint8_t*)&sample, 2) == 2) {
        Serial.println(sample);
    }
}
