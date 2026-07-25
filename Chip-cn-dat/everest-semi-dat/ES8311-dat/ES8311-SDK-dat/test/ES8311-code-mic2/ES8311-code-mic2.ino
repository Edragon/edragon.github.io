#include <Wire.h>
#include <driver/i2s.h>

// ========== PIN CONFIGURATION ==========
#define I2C_SDA      5
#define I2C_SCL      4

#define I2S_BCLK     14
#define I2S_LRCK     13
#define I2S_DOUT     12   // unused (reading from mic)
#define I2S_DIN      15   // ES8311 SDTO (data out)
#define I2S_MCLK     16

#define ES8311_ADDR  0x18
#define SAMPLE_RATE  16000

// ========== I2C HELPERS ==========
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
  Wire.requestFrom(ES8311_ADDR, (uint8_t)1);
  return Wire.available() ? Wire.read() : 0xFF;
}

void dumpRegs() {
  Serial.println("--- ES8311 Registers ---");
  uint8_t regs[] = {0x00,0x01,0x02,0x03,0x0A,0x0B,0x0D,0x0E,
                    0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x45};
  for (int i = 0; i < (int)(sizeof(regs)/sizeof(regs[0])); i++) {
    Serial.printf("  REG[0x%02X] = 0x%02X\n", regs[i], readReg(regs[i]));
  }
}

// ========== ES8311 INIT ==========
bool init_ES8311() {
  // 1. Reset
  if (!writeReg(0x00, 0x1F)) { Serial.println("I2C FAIL - check wiring"); return false; }
  delay(10);
  writeReg(0x00, 0x00); delay(10);

  // 2. Clock: MCLK divider — MCLK=4.096MHz (256 × 16kHz)
  writeReg(0x01, 0x30); // MCLK input enabled, clock divider on
  writeReg(0x02, 0x10); // ADC: fs = MCLK/256
  writeReg(0x03, 0x10); // DAC: fs = MCLK/256

  // 3. I2S format: Philips, 16-bit
  writeReg(0x0A, 0x00); // I2S Philips mode
  writeReg(0x0B, 0x0C); // bits[4:2]=011 → 16-bit

  // 4. Power up
  writeReg(0x0D, 0x01); delay(5);  // digital core
  writeReg(0x0D, 0x03); delay(5);  // analog + digital

  // 5. Analog path: MIC1
  writeReg(0x0E, 0x06); // ADC + I/O buffer powered
  writeReg(0x13, 0x40); // MIC1 selected, MICBIAS on
  writeReg(0x14, 0x1A); // PGA gain +24 dB
  writeReg(0x15, 0x00); // ADC input = analog PGA
  writeReg(0x1A, 0x00); // MIC1 volume
  writeReg(0x1B, 0x00); // MIC2 volume

  // 6. ALC off, volume max
  writeReg(0x16, 0x00); // ALC disable
  writeReg(0x17, 0x00); // ADC volume
  writeReg(0x18, 0x00); // DAC volume L
  writeReg(0x19, 0x00); // DAC volume R

  // 7. Digital enable
  writeReg(0x45, 0x01); delay(10);

  Serial.println("ES8311 configured");
  dumpRegs();
  return true;
}

// ========== I2S SETUP (IDF driver — reliable) ==========
void setupI2S() {
  i2s_config_t cfg = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX),
    .sample_rate = SAMPLE_RATE,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
    .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
    .communication_format = I2S_COMM_FORMAT_STAND_I2S,
    .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
    .dma_buf_count = 4,
    .dma_buf_len = 128,
    .use_apll = true,
    .tx_desc_auto_clear = false,
    .fixed_mclk = SAMPLE_RATE * 256,
  };

  i2s_pin_config_t pins = {
    .bck_io_num = I2S_BCLK,
    .ws_io_num = I2S_LRCK,
    .data_out_num = I2S_PIN_NO_CHANGE,
    .data_in_num = I2S_DIN,
  };

  ESP_ERROR_CHECK(i2s_driver_install(I2S_NUM_0, &cfg, 0, NULL));
  ESP_ERROR_CHECK(i2s_set_pin(I2S_NUM_0, &pins));
  i2s_zero_dma_buffer(I2S_NUM_0);
  Serial.println("I2S RX ready");
}

// ========== SETUP ==========
void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("\n=== ES8311 Mic Test ===");

  Wire.begin(I2C_SDA, I2C_SCL);

  // I2C bus scan
  Serial.println("Scanning I2C bus...");
  int found = 0;
  for (uint8_t addr = 1; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) {
      Serial.printf("  Found 0x%02X\n", addr);
      found++;
    }
  }
  if (found == 0) { Serial.println("NO I2C devices found!"); while (1); }

  if (!init_ES8311()) { Serial.println("ES8311 init FAILED"); while (1); }
  setupI2S();
  Serial.println("=== Ready — tap the mic! ===\n");
}

// ========== LOOP ==========
void loop() {
  int16_t sample;
  size_t bytes_read = 0;

  esp_err_t err = i2s_read(I2S_NUM_0, &sample, sizeof(sample), &bytes_read, portMAX_DELAY);
  if (err == ESP_OK && bytes_read == sizeof(sample)) {
    Serial.println(sample);
  }
}