
#include <driver/i2s.h>

// I2S0 Configuration (e.g., for an output speaker)
i2s_pin_config_t i2s0_pins = {
    .bck_io_num = 26,   // BCLK pin
    .ws_io_num = 25,    // WS (LRCLK) pin
    .data_out_num = 22, // Data output (DOUT) pin
    .data_in_num = -1   // Not used for output
};

// I2S1 Configuration (e.g., for an input microphone)
i2s_pin_config_t i2s1_pins = {
    .bck_io_num = 19,   // BCLK pin
    .ws_io_num = 18,    // WS (LRCLK) pin
    .data_out_num = -1, // Not used for input
    .data_in_num = 23   // Data input (DIN) pin
};

void setup() {
    // I2S0 Configuration
    i2s_config_t i2s0_config = {
        .mode = I2S_MODE_MASTER | I2S_MODE_TX,
        .sample_rate = 44100,
        .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
        .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
        .communication_format = I2S_COMM_FORMAT_I2S,
        .intr_alloc_flags = 0,
        .dma_buf_count = 8,
        .dma_buf_len = 64
    };
    i2s_driver_install(I2S_NUM_0, &i2s0_config, 0, NULL);
    i2s_set_pin(I2S_NUM_0, &i2s0_pins);

    // I2S1 Configuration
    i2s_config_t i2s1_config = {
        .mode = I2S_MODE_MASTER | I2S_MODE_RX,
        .sample_rate = 44100,
        .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
        .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
        .communication_format = I2S_COMM_FORMAT_I2S,
        .intr_alloc_flags = 0,
        .dma_buf_count = 8,
        .dma_buf_len = 64
    };
    i2s_driver_install(I2S_NUM_1, &i2s1_config, 0, NULL);
    i2s_set_pin(I2S_NUM_1, &i2s1_pins);
}

void loop() {
    // Your audio processing code here
}
