/**
 * HT517-test-1.ino
 * 
 * Simple I2S audio output demo for ESP32-S3 → I2S amplifier (MAX98357 / PCM5102 / etc.)
 *
 * Hardware connection (ESP32-S3 → I2S amplifier):
 *   I2S_BCK   (Bit Clock)  → GPIO 4   -> BCK / BCLK / SCK
 *   I2S_WS    (Word Select) → GPIO 5   -> WS / LRCK / FS
 *   I2S_DATA  (Data)        → GPIO 6   -> DIN / DATA / SD
 *   (Optional) I2S_MCLK (Master Clock) → GPIO 7 -> MCLK (not required by MAX98357)
 *
 * Tested amplifiers: MAX98357, PCM5102, I2S DAC, etc.
 * Output: 16-bit 44100 Hz mono sine wave (left+right same data).
 */

#include <driver/i2s.h>
#include <math.h>

// ============ CONFIGURATION ============
#define SAMPLE_RATE  44100
#define BITS_PER_SAMPLE 16
#define I2S_PORT     I2S_NUM_0

// GPIO pins (adjust to your wiring)
#define I2S_BCK      4   // Bit Clock
#define I2S_WS       5   // Word Select  (LRCK)
#define I2S_DATA     6   // Data out     (DIN)
#define I2S_MCLK     -1  // -1 = disable Master Clock (not needed for MAX98357)

// ============ BUFFER ============
#define BUF_LEN      256   // samples per channel per buffer
int16_t buf[BUF_LEN * 2]; // stereo interleaved

// ============ I2S CONFIG ============

void setupI2S() {
  i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),
    .sample_rate = SAMPLE_RATE,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
    .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
    .communication_format = I2S_COMM_FORMAT_STAND_I2S,
    .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
    .dma_buf_count = 8,
    .dma_buf_len = BUF_LEN,
    .use_apll = true,
    .tx_desc_auto_clear = true,
    .fixed_mclk = 0,
  };

  i2s_pin_config_t pin_config = {
    .bck_io_num = I2S_BCK,
    .ws_io_num = I2S_WS,
    .data_out_num = I2S_DATA,
    .data_in_num = I2S_PIN_NO_CHANGE,
  };

  // Install and start I2S driver
  esp_err_t err = i2s_driver_install(I2S_PORT, &i2s_config, 0, NULL);
  if (err != ESP_OK) {
    Serial.printf("FAIL: i2s_driver_install returned %d\n", err);
    while (1) delay(100);
  }

  // Set pins (only if MCLK is not used)
  err = i2s_set_pin(I2S_PORT, &pin_config);
  if (err != ESP_OK) {
    Serial.printf("FAIL: i2s_set_pin returned %d\n", err);
    while (1) delay(100);
  }

  // Set MCLK if enabled
  if (I2S_MCLK > 0) {
    i2s_set_clk(I2S_PORT, SAMPLE_RATE, I2S_BITS_PER_SAMPLE_16BIT, I2S_CHANNEL_STEREO);
  }

  Serial.println("I2S initialized OK");
}

// ============ GENERATE AUDIO ============
void generateSine(int16_t *buf, int len, float freq, float amplitude, uint32_t &phase_acc) {
  float phase_step = freq / SAMPLE_RATE;  // fractional phase increment per sample
  for (int i = 0; i < len; i++) {
    float phase = (phase_acc & 0xFFFF) / 65536.0f;  // 0.0 ~ 1.0
    int16_t sample = (int16_t)(amplitude * sinf(phase * 2.0f * M_PI));
    // stereo: left = right
    buf[i * 2 + 0] = sample;  // left
    buf[i * 2 + 1] = sample;  // right
    phase_acc = (uint32_t)(phase_acc + phase_step * 65536);
  }
}

// ============ SETUP ============
void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("\n--- I2S Audio Demo for ESP32-S3 ---");

  setupI2S();
}

// ============ LOOP ============
void loop() {
  static uint32_t phase_acc = 0;
  static float freq = 440.0f;     // A4 note
  static float amplitude = 16000; // 0 ~ 32767

  generateSine(buf, BUF_LEN, freq, amplitude, phase_acc);

  size_t bytes_written = 0;
  esp_err_t err = i2s_write(I2S_PORT, buf, sizeof(buf), &bytes_written, portMAX_DELAY);
  if (err != ESP_OK) {
    Serial.printf("I2S write error: %d\n", err);
  }

  // Optional: cycle through notes every 2 seconds
  static unsigned long last_note_change = 0;
  if (millis() - last_note_change > 2000) {
    last_note_change = millis();
    static float notes[] = {262, 294, 330, 349, 392, 440, 494, 523}; // C4 ~ C5
    static int note_idx = 0;
    freq = notes[note_idx];
    note_idx = (note_idx + 1) % 8;
    Serial.printf("Playing: %.0f Hz\n", freq);
  }
}
