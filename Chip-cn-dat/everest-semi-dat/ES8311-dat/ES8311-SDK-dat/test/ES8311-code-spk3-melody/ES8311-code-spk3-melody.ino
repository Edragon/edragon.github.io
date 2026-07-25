/*
 * ES8311 Melody Player for ESP32-S3 + ES8311-NS4150B
 *
 * ES8311 init adapted from the official ESP-IDF es8311.c driver.
 *
 * Board wiring (from ES8311-dat):
 *   GPIO  4 → SCL       GPIO  5 → SDA
 *   GPIO  6 → MCLK      GPIO 11 → DIN (ESP32 DOUT → ES8311 SDIN)
 *   GPIO 12 → LRCK      GPIO 13 → DOUT (not used for playback)
 *   GPIO 14 → SCLK (BCLK)
 */

#include <Wire.h>
#include <driver/i2s.h>

#ifndef PI
#define PI 3.141592653589793f
#endif

// ==================== PIN MAPPING ====================
#define I2C_SDA      5
#define I2C_SCL      4

#define I2S_MCLK     6
#define I2S_BCLK     14
#define I2S_LRCK     12
#define I2S_DOUT     11   // ESP32 DOUT → ES8311 SDIN
#define I2S_DIN      13   // unused for playback

#define PA_CTRL      -1

#define ES8311_ADDR  0x18
#define SAMPLE_RATE  16000
#define MCLK_HZ      (SAMPLE_RATE * 256)  // 4.096 MHz

// ==================== I2C Helpers ====================
bool writeReg(uint8_t reg, uint8_t val) {
  Wire.beginTransmission(ES8311_ADDR);
  Wire.write(reg);
  Wire.write(val);
  return Wire.endTransmission() == 0;
}

uint8_t readReg(uint8_t reg) {
  Wire.beginTransmission(ES8311_ADDR);
  Wire.write(reg);
  Wire.endTransmission(false);
  Wire.requestFrom((uint16_t)ES8311_ADDR, (uint8_t)1);
  return Wire.available() ? Wire.read() : 0xFF;
}

void dumpRegs() {
  Serial.println("--- ES8311 Registers ---");
  uint8_t regs[] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
                    0x09,0x0A,0x0D,0x0E,0x12,0x14,0x15,0x31,0x32,0x37,0x44,0x45};
  for (int i = 0; i < (int)(sizeof(regs)/sizeof(regs[0])); i++) {
    Serial.printf("  REG[0x%02X] = 0x%02X\n", regs[i], readReg(regs[i]));
  }
}

// ==================== ES8311 Init (from es8311.c official driver) ====================
/*
 * Coefficient for 16kHz @ MCLK=4.096MHz (256 × 16kHz):
 *   pre_div=1, pre_multi=1, adc_div=1, dac_div=1,
 *   fs_mode=0, lrck_h=0, lrck_l=0xFF, bclk_div=4, adc_osr=16, dac_osr=16
 */
bool init_ES8311_DAC() {
  // === 1. Pre-reset writes (es8311_codec_init) ===
  writeReg(0x01, 0x30);
  writeReg(0x02, 0x00);
  writeReg(0x03, 0x10);
  writeReg(0x16, 0x24);
  writeReg(0x04, 0x10);
  writeReg(0x05, 0x00);
  writeReg(0x0B, 0x00);
  writeReg(0x0C, 0x00);
  writeReg(0x10, 0x1F);
  writeReg(0x11, 0x7F);

  // === 2. Reset ===
  if (!writeReg(0x00, 0x80)) { Serial.println("I2C FAIL"); return false; }
  delay(20);
  writeReg(0x00, 0x00);

  // === 3. Slave mode (clear bit6) ===
  uint8_t r = readReg(0x00);
  r &= 0xBF;
  writeReg(0x00, r);

  // === 4. Enable all clocks ===
  writeReg(0x01, 0x3F);

  // === 5. Select MCLK pin as clock source (clear bit7) ===
  r = readReg(0x01);
  r &= 0x7F;
  writeReg(0x01, r);

  // === 6. Clock dividers from coefficient table ===
  // pre_div=1, pre_multi=1 → reg02 = 0x00
  writeReg(0x02, 0x00);
  // fs_mode=0, adc_osr=16 → reg03 = 0x10
  writeReg(0x03, 0x10);
  // dac_osr=16 → reg04 = 0x10
  writeReg(0x04, 0x10);
  // adc_div=1, dac_div=1 → reg05 = 0x00
  writeReg(0x05, 0x00);
  // bclk_div=4 → reg06 = 0x03
  writeReg(0x06, 0x03);
  // lrck_h=0 → reg07 = 0x00
  writeReg(0x07, 0x00);
  // lrck_l=0xFF → reg08 = 0xFF
  writeReg(0x08, 0xFF);

  // === 7. I2S format: Philips 16-bit ===
  writeReg(0x09, 0x0C);
  writeReg(0x0A, 0x0C);

  // === 8. System init (from official driver) ===
  writeReg(0x13, 0x10);
  writeReg(0x1B, 0x0A);
  writeReg(0x1C, 0x6A);
  writeReg(0x44, 0x08);

  // === 9. DAC start sequence (es8311_start in DAC mode) ===
  // Unmute DAC (clear bit6 in reg09)
  r = readReg(0x09) & 0xBF;
  writeReg(0x09, r);
  // Unmute ADC (clear bit6 in reg0A) — harmless
  r = readReg(0x0A) & 0xBF;
  writeReg(0x0A, r);

  writeReg(0x32, 0xBF);  // DAC volume = 0dB (official driver value)
  writeReg(0x17, 0xBF);  // ADC volume
  writeReg(0x0E, 0x02);  // Analog enable
  writeReg(0x12, 0x00);  // System
  writeReg(0x14, 0x1A);  // PGA + DMIC select (0=analog mic)
  writeReg(0x0D, 0x01);  // Power digital only
  delay(5);
  writeReg(0x15, 0x40);  // ADC control
  writeReg(0x37, 0x48);  // DAC output drive
  writeReg(0x45, 0x00);  // GPIO

  Serial.println("ES8311 DAC configured (es8311.c reference)");
  dumpRegs();
  return true;
}

// ==================== I2S Setup ====================
void setupI2S() {
  i2s_config_t cfg = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),
    .sample_rate = SAMPLE_RATE,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
    .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
    .communication_format = I2S_COMM_FORMAT_STAND_I2S,
    .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
    .dma_buf_count = 4,
    .dma_buf_len = 256,
    .use_apll = true,
    .tx_desc_auto_clear = true,
    .fixed_mclk = MCLK_HZ,  // 4.096 MHz for ES8311 MCLK pin
  };

  i2s_pin_config_t pins = {
    .bck_io_num = I2S_BCLK,
    .ws_io_num = I2S_LRCK,
    .data_out_num = I2S_DOUT,
    .data_in_num = I2S_PIN_NO_CHANGE,
  };

  ESP_ERROR_CHECK(i2s_driver_install(I2S_NUM_0, &cfg, 0, NULL));
  ESP_ERROR_CHECK(i2s_set_pin(I2S_NUM_0, &pins));
  i2s_zero_dma_buffer(I2S_NUM_0);
  Serial.println("I2S TX ready");
}

// ==================== Setup ====================
void setup() {
  Serial.begin(115200);
  delay(1500);
  Serial.println("\n=== ES8311 Melody Player ===");

  // Enable amplifier if PA_CTRL pin is configured
  if (PA_CTRL >= 0) {
    pinMode(PA_CTRL, OUTPUT);
    digitalWrite(PA_CTRL, HIGH);
    Serial.printf("PA_CTRL GPIO%d = HIGH\n", PA_CTRL);
  }

  Wire.begin(I2C_SDA, I2C_SCL);
  Wire.setClock(100000);

  Wire.beginTransmission(ES8311_ADDR);
  if (Wire.endTransmission() == 0) {
    Serial.printf("ES8311 found at 0x%02X\n", ES8311_ADDR);
  } else {
    Serial.printf("ES8311 NOT found at 0x%02X! Check wiring.\n", ES8311_ADDR);
    while (1);
  }

  if (!init_ES8311_DAC()) { while (1); }
  setupI2S();
  Serial.println("=== Playing melody ===\n");
}

// ==================== Melody Data ====================
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_REST 0

struct Note { uint16_t freq; uint16_t duration; };

const Note melody[] = {
  {NOTE_C4,400},{NOTE_C4,400},{NOTE_G4,400},{NOTE_G4,400},
  {NOTE_A4,400},{NOTE_A4,400},{NOTE_G4,800},
  {NOTE_F4,400},{NOTE_F4,400},{NOTE_E4,400},{NOTE_E4,400},
  {NOTE_D4,400},{NOTE_D4,400},{NOTE_C4,800},
  {NOTE_G4,400},{NOTE_G4,400},{NOTE_F4,400},{NOTE_F4,400},
  {NOTE_E4,400},{NOTE_E4,400},{NOTE_D4,800},
  {NOTE_G4,400},{NOTE_G4,400},{NOTE_F4,400},{NOTE_F4,400},
  {NOTE_E4,400},{NOTE_E4,400},{NOTE_D4,800},
  {NOTE_C4,400},{NOTE_C4,400},{NOTE_G4,400},{NOTE_G4,400},
  {NOTE_A4,400},{NOTE_A4,400},{NOTE_G4,800},
  {NOTE_F4,400},{NOTE_F4,400},{NOTE_E4,400},{NOTE_E4,400},
  {NOTE_D4,400},{NOTE_D4,400},{NOTE_C4,800},
  {NOTE_REST,600},
};
const int melody_len = sizeof(melody) / sizeof(Note);

// ==================== Audio Generator ====================
#define BUF_SAMPLES 256
#define ATTACK_MS   12
#define RELEASE_MS  15
#define GAP_MS      4
#define XFADE_MS    10

static float     g_phase      = 0.0f;
static uint8_t   g_note_idx   = 0;
static uint32_t  g_note_start = 0;
static float     g_prev_freq  = melody[0].freq;
static bool      g_first      = true;

void loop() {
  int16_t buf[BUF_SAMPLES * 2];
  uint32_t now = millis();

  if (g_first) {
    g_note_start = now;
    g_first = false;
    Serial.printf("♪ [0] %d Hz %d ms\n", melody[0].freq, melody[0].duration);
  }

  uint32_t elapsed = now - g_note_start;
  Note cur = melody[g_note_idx];

  // Note transition
  if (elapsed >= cur.duration + GAP_MS) {
    g_prev_freq = cur.freq;
    g_note_idx = (g_note_idx + 1) % melody_len;
    g_note_start = now;
    cur = melody[g_note_idx];
    Serial.printf("♪ [%d] %d Hz %d ms\n", g_note_idx, cur.freq, cur.duration);
  }
  elapsed = now - g_note_start;

  // Crossfade frequency
  float xf = (elapsed < XFADE_MS) ? (elapsed / (float)XFADE_MS) : 1.0f;
  float freq = g_prev_freq * (1.0f - xf) + cur.freq * xf;

  // Timing
  int gap_s  = GAP_MS     * SAMPLE_RATE / 1000;
  int att_s  = ATTACK_MS  * SAMPLE_RATE / 1000;
  int rel_s  = RELEASE_MS * SAMPLE_RATE / 1000;
  uint32_t off = (uint32_t)(elapsed * SAMPLE_RATE / 1000.0f);
  uint32_t dur_s = (uint32_t)(cur.duration * SAMPLE_RATE / 1000.0f);

  for (int i = 0; i < BUF_SAMPLES; i++) {
    uint32_t s = off + i;
    int16_t smp;
    if (s < (uint32_t)gap_s) {
      smp = 0;
    } else if (cur.freq == 0 && elapsed >= XFADE_MS) {
      smp = 0;
    } else {
      float env = 0.75f;
      uint32_t ns = s - gap_s;
      if (ns < (uint32_t)att_s)
        env *= (float)ns / att_s;
      else if (ns > dur_s - rel_s && dur_s > (uint32_t)(att_s + rel_s))
        env *= (float)(dur_s - ns) / rel_s;
      smp = (int16_t)(sinf(g_phase) * env * 28000);
      g_phase += 2.0f * PI * freq / SAMPLE_RATE;
      if (g_phase > 2.0f * PI) g_phase -= 2.0f * PI;
    }
    buf[i * 2]     = smp;
    buf[i * 2 + 1] = smp;
  }

  size_t written = 0;
  esp_err_t err = i2s_write(I2S_NUM_0, buf, sizeof(buf), &written, portMAX_DELAY);
  if (err != ESP_OK || written != sizeof(buf)) {
    Serial.printf("I2S err=%d written=%d\n", err, written);
  }
}