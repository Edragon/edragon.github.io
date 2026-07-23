#include "AudioTools.h"
#include "AudioBoard.h"

// 1. Define your pins clearly
#define I2C_SDA      5
#define I2C_SCL      4

#define I2S_BCLK     14
#define I2S_LRCK     12
#define I2S_DOUT     13
#define I2S_DIN      11    // unused (DAC playback only)
#define I2S_MCLK     15


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
    while(!Serial);

    // =============================================
    // Step 1: 先用 I2S 生成全部时钟（MCLK + BCLK + LRCK）
    //   ESP32 I2S RX master 模式会持续输出 MCLK
    // =============================================
    auto config = i2s.defaultConfig(RX_MODE);
    config.pin_bck = I2S_BCLK;
    config.pin_ws  = I2S_LRCK;
    config.pin_data = I2S_DIN;
    config.pin_mck = I2S_MCLK;           // I2S 输出 MCLK 到 GPIO15
    config.sample_rate = 16000;
    config.channels = 2;
    config.bits_per_sample = 16;
    config.use_apll = true;
    i2s.begin(config);
    delay(20);  // 等时钟稳定

    // =============================================
    // Step 2: 初始化 I2C
    // =============================================
    Wire.begin(I2C_SDA, I2C_SCL);
    Wire.setClock(100000);
    my_pins.addI2C(PinFunction::CODEC, Wire);
    my_pins.addI2S(PinFunction::CODEC, I2S_MCLK, I2S_BCLK, I2S_LRCK, I2S_DOUT, I2S_DIN);

    // =============================================
    // Step 3: 配置 ES8311（MCLK+BCLK+LRCK 全部就绪）
    // =============================================
    if (!board.begin()) {
        Serial.println("Failed to initialize ES8311 Board!");
        while (true);
    }

    // 设置为麦克风编码模式
    CodecConfig codec_config;
    codec_config.input_device = ADC_INPUT_LINE1;
    codec_config.i2s.rate = RATE_16K;
    codec_config.i2s.channels = CHANNELS2;
    board.setConfig(codec_config);
    board.setInputVolume(100);

    Serial.println("ES8311 Mic Initialized. Reading...");
}

void loop()
{
    int16_t sample;
    if (i2s.readBytes((uint8_t*)&sample, 2) == 2) {
        Serial.println(sample);
    }
}
