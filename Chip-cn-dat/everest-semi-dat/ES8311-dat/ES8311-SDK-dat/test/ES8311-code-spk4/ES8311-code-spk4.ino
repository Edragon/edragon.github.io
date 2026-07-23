/*
 * ES8311 Codec + NS4150 Amplifier — Melody Player (Arduino)
 *
 * Reference: ESP-IDF official example
 *   https://github.com/espressif/esp-idf/blob/master/examples/peripherals/i2s/i2s_codec/i2s_es8311/main/i2s_es8311_example.c
 *
 * Key settings from ESP-IDF reference:
 *   - Sample Rate: 16000 Hz
 *   - MCLK Multiple: 384 (MCLK = 6.144 MHz) — matches ES8311 coeff table
 *   - I2S Format:   Philips (standard I2S)
 *   - Bit Width:    16-bit
 *   - Channels:     2 (stereo)
 *   - Codec Mode:   Slave (ESP32 is I2S master)
 *   - PA_CTRL pin:  High = amplifier enabled
 *
 * Wiring (match your board):
 *   ES8311 SDA  -> GPIO 5
 *   ES8311 SCL  -> GPIO 4
 *   ES8311 MCLK -> GPIO 6
 *   ES8311 BCLK -> GPIO 14
 *   ES8311 LRCK -> GPIO 12
 *   ES8311 SDIN -> GPIO 13  (I2S data INTO ES8311 = ESP32 DOUT)
 *   NS4150 CTRL -> hardware pull-up HIGH (no GPIO needed, or use PA_CTRL)
 */

#include <Wire.h>
#include <ESP_I2S.h>

// PI fallback (Arduino defines PI, but ensure M_PI as well)
#ifndef PI
#define PI 3.141592653589793f
#endif
#ifndef M_PI
#define M_PI PI
#endif

// ==================== Pin Definitions ====================
#define I2C_SDA      5
#define I2C_SCL      4

#define I2S_BCLK     14
#define I2S_LRCK     12
#define I2S_DOUT     13
#define I2S_DIN      -1    // unused (DAC playback only)
#define I2S_MCLK     6

#define PA_CTRL      -1    // set to GPIO if you have amp enable pin, -1 = not used

#define ES8311_ADDR  0x18

// ==================== Audio Parameters (from ESP-IDF example) ====================
#define SAMPLE_RATE       16000
#define MCLK_MULTIPLE     384         // ESP-IDF uses 384 for 16-bit
// MCLK = SAMPLE_RATE * MCLK_MULTIPLE = 6,144,000 Hz (in ES8311 coeff table)
#define BIT_WIDTH         16
#define CHANNELS          2

// ==================== I2S ====================
I2SClass i2s;

// ==================== ES8311 Register Helpers ====================
void writeReg(uint8_t reg, uint8_t value) {
  Wire.beginTransmission(ES8311_ADDR);
  Wire.write(reg);
  Wire.write(value);
  Wire.endTransmission();
}

uint8_t readReg(uint8_t reg) {
  Wire.beginTransmission(ES8311_ADDR);
  Wire.write(reg);
  Wire.endTransmission(false);
  Wire.requestFrom((uint16_t)ES8311_ADDR, (uint8_t)1);
  if (Wire.available()) return Wire.read();
  return 0;
}

// ==================== ES8311 Init (based on ESP-IDF esp_codec_dev driver) ====================
void es8311_init() {
  // --- Step 1: Pre-reset defaults ---
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

  // --- Step 2: Reset ---
  writeReg(0x00, 0x80);
  delay(20);

  // --- Step 3: Slave mode (ESP32 is master, same as ESP-IDF: master_mode=false) ---
  uint8_t r = readReg(0x00);
  r &= 0xBF;           // clear bit 6 → slave
  writeReg(0x00, r);

  // --- Step 4: Clock source = BCLK (avoids MCLK frequency dependency) ---
  // ESP-IDF uses MCLK at 384×Fs which is also valid; BCLK source is simpler
  writeReg(0x01, 0x3F);
  r = readReg(0x01);
  r |= 0x80;           // bit 7 = 1 → use BCLK/SCLK as PLL source
  writeReg(0x01, r);

  // --- Step 5: Clock dividers for 16kHz ---
  // From ES8311 coefficient table entry {6144000, 16000, ...}
  // These work for both MCLK and BCLK clock sources
  writeReg(0x02, 0x00);   // pre_div=1, multi=1
  writeReg(0x03, 0x10);   // adc_osr=16x
  writeReg(0x04, 0x10);   // dac_osr=16x
  writeReg(0x05, 0x00);   // adc_div=1, dac_div=1
  writeReg(0x06, 0x03);   // bclk_div=4
  writeReg(0x07, 0x00);   // lrck_h
  writeReg(0x08, 0xFF);   // lrck_l

  // --- Step 6: I2S format — Philips (standard I2S) ---
  // ESP-IDF uses I2S_STD_PHILIPS_SLOT_DEFAULT_CONFIG
  writeReg(0x09, 0x0C);   // SDP_IN:  16-bit I2S Philips
  writeReg(0x0A, 0x0C);   // SDP_OUT: 16-bit I2S Philips

  // --- Step 7: System init (from official driver) ---
  writeReg(0x13, 0x10);
  writeReg(0x1B, 0x0A);
  writeReg(0x1C, 0x6A);

  // --- Verify ---
  uint8_t id1 = readReg(0xFD);
  uint8_t id2 = readReg(0xFE);
  Serial.printf("ES8311 Chip ID: 0x%02X%02X (expect 0x8311)\n", id1, id2);
}

// ==================== ES8311 DAC Start (power-up + unmute) ====================
void es8311_dac_start() {
  writeReg(0x14, 0x3B);   // analog gain, no mic bias

  uint8_t dac = readReg(0x09) & 0xBF;  // unmute DAC
  writeReg(0x09, dac);
  uint8_t adc = readReg(0x0A) & 0xBF;  // unmute ADC (harmless)
  writeReg(0x0A, adc);

  writeReg(0x17, 0xBF);   // ADC digital vol
  writeReg(0x0E, 0x02);   // analog enable
  writeReg(0x12, 0x00);   // system ctrl
  writeReg(0x0D, 0x03);   // power: DAC + ADC analog
  writeReg(0x15, 0x40);   // ADC ctrl
  writeReg(0x37, 0x48);   // DAC output drive (reduced from 0x78)
  writeReg(0x45, 0x00);   // GPIO

  // DAC digital volume: 0x00=mute, 0xBF=0dB, 0xFF=+6dB
  writeReg(0x32, 0x20);   // very soft

  Serial.println("ES8311 DAC started.");
}

// ==================== Melody ====================
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_REST 0

struct Note { uint16_t freq; uint16_t dur; };

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
const int MELODY_LEN = sizeof(melody) / sizeof(Note);

// ==================== Audio Generator ====================
const int BUF_SAMPLES = 256;
const int ATTACK_MS  = 12;
const int RELEASE_MS = 15;
const int GAP_MS     = 4;
const int XFADE_MS   = 10;

static float     g_phase       = 0.0f;
static uint8_t   g_note_idx    = 0;
static uint32_t  g_note_start  = 0;
static float     g_prev_freq   = melody[0].freq;
static bool      g_first_run   = true;

void loop() {
  int16_t buf[BUF_SAMPLES * 2];      // stereo interleaved
  uint32_t now = millis();

  // First run: sync clock so we don't skip the first note
  if (g_first_run) {
    g_note_start = now;
    g_first_run = false;
    Serial.printf("♪ [0] freq=%d dur=%d\n", melody[0].freq, melody[0].dur);
  }

  uint32_t elapsed = now - g_note_start;
  Note cur = melody[g_note_idx];

  // --- Note transition ---
  if (elapsed >= cur.dur + GAP_MS) {
    g_prev_freq = cur.freq;
    g_note_idx = (g_note_idx + 1) % MELODY_LEN;
    g_note_start = now;
    cur = melody[g_note_idx];
    Serial.printf("♪ [%d] freq=%d dur=%d\n", g_note_idx, cur.freq, cur.dur);
  }
  elapsed = now - g_note_start;       // recalibrate after possible transition

  // --- Crossfade ---
  float xf = (elapsed < XFADE_MS) ? (elapsed / (float)XFADE_MS) : 1.0f;
  float freq = g_prev_freq * (1.0f - xf) + cur.freq * xf;

  // --- Timing in samples ---
  int gap_s     = GAP_MS     * SAMPLE_RATE / 1000;
  int att_s     = ATTACK_MS  * SAMPLE_RATE / 1000;
  int rel_s     = RELEASE_MS * SAMPLE_RATE / 1000;
  uint32_t off  = (uint32_t)(elapsed * SAMPLE_RATE / 1000.0f);
  uint32_t dur_s = (uint32_t)(cur.dur * SAMPLE_RATE / 1000.0f);

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

      smp = (int16_t)(sinf(g_phase) * env * 6000);   // very soft
      g_phase += 2.0f * (float)M_PI * freq / SAMPLE_RATE;
      if (g_phase > 2.0f * (float)M_PI) g_phase -= 2.0f * (float)M_PI;
    }
    buf[i * 2]     = smp;
    buf[i * 2 + 1] = smp;
  }

  size_t w = i2s.write((uint8_t*)buf, sizeof(buf));
  if (w != sizeof(buf))
    Serial.printf("⚠ I2S short write: %d/%d\n", w, sizeof(buf));
}

// ==================== Setup ====================
void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n=== ES8311 Melody Player (ESP-IDF ref) ===");

  // --- PA_CTRL (amplifier enable) ---
  if (PA_CTRL >= 0) {
    pinMode(PA_CTRL, OUTPUT);
    digitalWrite(PA_CTRL, HIGH);
    Serial.printf("PA_CTRL: GPIO%d = HIGH\n", PA_CTRL);
  }

  // --- I2C ---
  Wire.begin(I2C_SDA, I2C_SCL);
  Wire.setClock(100000);

  Wire.beginTransmission(ES8311_ADDR);
  if (Wire.endTransmission() == 0)
    Serial.printf("✅ ES8311 found at 0x%02X\n", ES8311_ADDR);
  else {
    Serial.printf("❌ ES8311 NOT found at 0x%02X!\n", ES8311_ADDR);
    while (1);
  }

  // --- Init ES8311 ---
  es8311_init();
  es8311_dac_start();

  // --- I2S (Philips standard, 16kHz, 16-bit, stereo, ESP32=master) ---
  i2s.setPins(I2S_BCLK, I2S_LRCK, I2S_DOUT, I2S_DIN, I2S_MCLK);
  if (!i2s.begin(I2S_MODE_STD, SAMPLE_RATE,
                 I2S_DATA_BIT_WIDTH_16BIT,
                 I2S_SLOT_MODE_STEREO,
                 I2S_STD_SLOT_BOTH)) {
    Serial.println("❌ I2S init failed!");
    while (1);
  }
  Serial.printf("✅ I2S started: %d Hz, %d-bit, stereo, Philips\n",
                SAMPLE_RATE, BIT_WIDTH);
  Serial.println("▶ Playing: Twinkle Twinkle Little Star");
}

