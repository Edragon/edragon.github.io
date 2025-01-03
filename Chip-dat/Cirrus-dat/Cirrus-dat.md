
# Cirrus-dat

## CS4344 

Hi, i2s driver let you map LRCLK BCLK and DATA to any GPIO pins you specify.

However, CS4344 require MCLK, so you need to generate it! By the way, this is a reason you cannot use CS4344 with esp8266.

As far as I know esp32 can only generate MCLK on GPIO0:

    i2s_config_t i2s_config = {
        .mode = I2S_MODE_MASTER | I2S_MODE_TX, // Only TX
        .sample_rate = 44100,
        .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
        .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT, //2-channels
        .communication_format = (I2S_COMM_FORMAT_I2S | I2S_COMM_FORMAT_I2S_MSB),
        .dma_buf_count = 6,
        .dma_buf_len = 60,
        .intr_alloc_flags = 0, //Default interrupt priority
        .tx_desc_auto_clear = true, //Auto clear tx descriptor on underflow
        .use_apll = true // change to false if it sounds bad (rev0 chip - better set to false, newer chips - set to true)
    };

    i2s_driver_install(0, &i2s_config, 0, NULL);

    i2s_pin_config_t pin_config = { .bck_io_num = CONFIG_I2S_BCK_PIN, .ws_io_num = CONFIG_I2S_LRCK_PIN, .data_out_num = CONFIG_I2S_DATA_PIN, .data_in_num = -1 // Not used };

    i2s_set_pin(0, &pin_config);

    // generate mclk on gpio0
    REG_WRITE(PIN_CTRL, 0b111111110000);
    
    PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO0_U, FUNC_GPIO0_CLK_OUT1);


Define CONFIG_I2S_BCK_PIN CONFIG_I2S_LRCK_PIN CONFIG_I2S_DATA_PIN as your connected GPIO pins. Connect CS4344 MCLK to IO0. It should work that way, at least it works perfectly for me.




## ref 

- https://www.reddit.com/r/esp32/comments/g48lzs/esp_32_i2s_and_cs4344_dac/