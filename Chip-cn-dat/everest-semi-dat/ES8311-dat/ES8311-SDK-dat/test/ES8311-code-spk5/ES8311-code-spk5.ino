/*
 * ES8311-code-spk5.ino
 *
 * Minimal Arduino sketch that reuses es8311.c / es8311.h from the
 * official ESP-IDF driver.  Both files live in this same folder and
 * are auto-compiled by the Arduino IDE.
 *
 * The init sequence follows es8311.c exactly:
 *   es8311_codec_init() → es8311_start(ES_MODULE_DAC)
 *
 * I2C uses Arduino Wire instead of the ESP-IDF i2c_driver.
 *
 * Wiring (from ES8311-dat):
 *   GPIO  4 → SCL      GPIO  5 → SDA
 *   GPIO  6 → MCLK     GPIO 11 → DIN (ESP32 DOUT → ES8311 SDIN)
 *   GPIO 12 → LRCK     GPIO 14 → BCLK
 */

#include <Wire.h>
#include <driver/i2s.h>
#include "es8311.h"        // register constants

// ==================== Pins ====================
#define I2C_SDA      5
#define I2C_SCL      4
#define I2S_MCLK     6
#define I2S_BCLK     14
#define I2S_LRCK     12
#define I2S_DOUT     11   // → ES8311 SDIN
#define I2S_DIN      13   // unused

#define PA_CTRL      -1
#define SAMPLE_RATE  16000
#define MCLK_HZ      (SAMPLE_RATE * 256)

// ==================== I2C helpers ====================
static bool w(uint8_t r, uint8_t v) {
    Wire.beginTransmission(0x18);
    Wire.write(r); Wire.write(v);
    return Wire.endTransmission() == 0;
}
static uint8_t r(uint8_t r) {
    Wire.beginTransmission(0x18); Wire.write(r);
    Wire.endTransmission(false);
    Wire.requestFrom((uint16_t)0x18, (uint8_t)1);
    return Wire.available() ? Wire.read() : 0xFF;
}

// ==================== Clock coefficient (16k, MCLK=4.096M) ====================
// From coeff_div[]: {4096000,16000, pre=1,mult=1, adc=1,dac=1,
//                     fs=0, lrch=0,lrcl=0xFF, bck=4, osr=16}
static void set_coeff() {
    w(ES8311_CLK_MANAGER_REG02, 0x00);   // pre_div=1, pre_multi=1
    w(ES8311_CLK_MANAGER_REG03, 0x10);   // fs=0, adc_osr=16
    w(ES8311_CLK_MANAGER_REG04, 0x10);   // dac_osr=16
    w(ES8311_CLK_MANAGER_REG05, 0x00);   // adc=1, dac=1
    w(ES8311_CLK_MANAGER_REG06, 0x03);   // bclk_div=4
    w(ES8311_CLK_MANAGER_REG07, 0x00);   // lrck_h=0
    w(ES8311_CLK_MANAGER_REG08, 0xFF);   // lrck_l=0xFF
}

// ==================== ES8311 init ====================
// Follows es8311_codec_init() from es8311.c line-for-line
bool es8311_init() {
    // Pre-reset
    w(ES8311_CLK_MANAGER_REG01, 0x30);
    w(ES8311_CLK_MANAGER_REG02, 0x00);
    w(ES8311_CLK_MANAGER_REG03, 0x10);
    w(ES8311_ADC_REG16,         0x24);
    w(ES8311_CLK_MANAGER_REG04, 0x10);
    w(ES8311_CLK_MANAGER_REG05, 0x00);
    w(ES8311_SYSTEM_REG0B,      0x00);
    w(ES8311_SYSTEM_REG0C,      0x00);
    w(ES8311_SYSTEM_REG10,      0x1F);
    w(ES8311_SYSTEM_REG11,      0x7F);

    if (!w(ES8311_RESET_REG00, 0x80)) return false;
    delay(20);

    // Slave mode
    w(ES8311_RESET_REG00, r(ES8311_RESET_REG00) & 0xBF);

    // All clocks ON
    w(ES8311_CLK_MANAGER_REG01, 0x3F);

    // MCLK pin (clear bit7)
    w(ES8311_CLK_MANAGER_REG01, r(ES8311_CLK_MANAGER_REG01) & 0x7F);

    set_coeff();

    // MCLK not inverted, BCLK not inverted
    w(ES8311_CLK_MANAGER_REG01, r(ES8311_CLK_MANAGER_REG01) & ~0x40);
    w(ES8311_CLK_MANAGER_REG06, r(ES8311_CLK_MANAGER_REG06) & ~0x20);

    w(ES8311_SYSTEM_REG13, 0x10);
    w(ES8311_ADC_REG1B,    0x0A);
    w(ES8311_ADC_REG1C,    0x6A);
    w(ES8311_GPIO_REG44,   0x08);
    return true;
}

// ==================== DAC start ====================
// Follows es8311_start(ES_MODULE_DAC) from es8311.c
void es8311_start_dac() {
    // Unmute DAC (clear bit6 in reg09)
    w(ES8311_SDPIN_REG09,  r(ES8311_SDPIN_REG09)  & 0xBF);
    // Unmute ADC (clear bit6 in reg0A)
    w(ES8311_SDPOUT_REG0A, r(ES8311_SDPOUT_REG0A) & 0xBF);

    w(ES8311_DAC_REG32,    0xBF);   // 0 dB
    w(ES8311_ADC_REG17,    0xBF);
    w(ES8311_SYSTEM_REG0E, 0x02);
    w(ES8311_SYSTEM_REG12, 0x00);
    w(ES8311_SYSTEM_REG14, 0x1A);   // analog mic, not DMIC
    w(ES8311_SYSTEM_REG0D, 0x01);
    delay(5);
    w(ES8311_ADC_REG15,    0x40);
    w(ES8311_DAC_REG37,    0x48);
    w(ES8311_GP_REG45,     0x00);
}

// ==================== I2S ====================
void setup_i2s() {
    i2s_config_t c = {
        .mode               = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),
        .sample_rate        = SAMPLE_RATE,
        .bits_per_sample    = I2S_BITS_PER_SAMPLE_16BIT,
        .channel_format     = I2S_CHANNEL_FMT_RIGHT_LEFT,
        .communication_format = I2S_COMM_FORMAT_STAND_I2S,
        .intr_alloc_flags   = ESP_INTR_FLAG_LEVEL1,
        .dma_buf_count      = 4,
        .dma_buf_len        = 256,
        .use_apll           = true,
        .tx_desc_auto_clear = true,
        .fixed_mclk         = MCLK_HZ,
    };
    i2s_pin_config_t p = {
        .bck_io_num   = I2S_BCLK,
        .ws_io_num    = I2S_LRCK,
        .data_out_num = I2S_DOUT,
        .data_in_num  = I2S_PIN_NO_CHANGE,
    };
    ESP_ERROR_CHECK(i2s_driver_install(I2S_NUM_0, &c, 0, NULL));
    ESP_ERROR_CHECK(i2s_set_pin(I2S_NUM_0, &p));
    i2s_zero_dma_buffer(I2S_NUM_0);
}

// ==================== Register dump ====================
void dump() {
    Serial.println("--- ES8311 regs ---");
    uint8_t regs[] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
                      0x09,0x0A,0x0D,0x0E,0x12,0x14,0x15,0x31,0x32,0x37,0x44,0x45};
    for (int i = 0; i < (int)(sizeof(regs)/sizeof(regs[0])); i++)
        Serial.printf("  [0x%02X] = 0x%02X\n", regs[i], r(regs[i]));
}

// ==================== Melody ====================
#define BUF_SZ  256
#define N8(f) {f,800}
#define N4(f) {f,400}
#define RST  {0,600}

static const struct { uint16_t f, d; } mel[] = {
    N4(262),N4(262),N4(392),N4(392),N4(440),N4(440),N8(392),
    N4(349),N4(349),N4(330),N4(330),N4(294),N4(294),N8(262),
    N8(392),N8(349),N8(330),N8(294),
    N4(262),N4(262),N4(392),N4(392),N4(440),N4(440),N8(392),
    N4(349),N4(349),N4(330),N4(330),N4(294),N4(294),N8(262),
    RST,
};
static const int N = sizeof(mel)/sizeof(mel[0]);

static float   ph  = 0;
static uint8_t ix  = 0;
static uint32_t t0 = 0;
static bool    fst = true;

// ==================== Setup ====================
void setup() {
    Serial.begin(115200);  delay(1500);
    Serial.println("\n=== spk5 ===");

    if (PA_CTRL >= 0) { pinMode(PA_CTRL, OUTPUT); digitalWrite(PA_CTRL, HIGH); }

    Wire.begin(I2C_SDA, I2C_SCL);  Wire.setClock(100000);
    Wire.beginTransmission(0x18);
    if (Wire.endTransmission()) { Serial.println("No ES8311!"); while (1); }
    Serial.println("ES8311 found");

    if (!es8311_init()) { Serial.println("Init FAIL"); while (1); }
    es8311_start_dac();
    dump();
    setup_i2s();
    Serial.println("=== play ===\n");
}

// ==================== Loop ====================
void loop() {
    int16_t buf[BUF_SZ * 2];
    uint32_t now = millis();
    if (fst) { t0 = now; fst = false; }

    uint32_t el = now - t0;
    if (el >= mel[ix].d + 4) {
        ix = (ix + 1) % N;
        t0 = now; el = 0;
        Serial.printf("♪ %d Hz\n", mel[ix].f);
    }

    for (int i = 0; i < BUF_SZ; i++) {
        int16_t s = mel[ix].f ? (int16_t)(sinf(ph) * 24000) : 0;
        ph += 2 * PI * mel[ix].f / SAMPLE_RATE;
        if (ph > 2 * PI) ph -= 2 * PI;
        buf[i*2] = buf[i*2+1] = s;
    }
    size_t w = 0;
    i2s_write(I2S_NUM_0, buf, sizeof(buf), &w, portMAX_DELAY);
}
