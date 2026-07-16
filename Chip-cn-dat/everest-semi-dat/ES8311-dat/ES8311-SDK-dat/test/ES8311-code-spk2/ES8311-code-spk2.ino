#include <Wire.h>
#include <ESP_I2S.h> // Uses the standard ESP32 Arduino I2S library

// Define your board's pin layout (Change these values to match your specific board schematic)
#define I2C_SDA      18
#define I2C_SCL      17

#define I2S_BCLK     5
#define I2S_LRCK     4
#define I2S_DOUT     6
#define I2S_DIN      7
#define I2S_MCLK     2

#define ES8311_ADDR  0x18 // Default I2C Address for ES8311

I2SClass i2s;

// Helper to write to ES8311 registers over I2C
void writeReg(uint8_t reg, uint8_t value) {
  Wire.beginTransmission(ES8311_ADDR);
  Wire.write(reg);
  Wire.write(value);
  Wire.endTransmission();
}

void init_ES8311() {
  // Resets and wakes up the chip sequence
  writeReg(0x00, 0x80); // Reset system
  delay(10);
  writeReg(0x00, 0x00); // Clear reset
  
  // Clock configurations
  writeReg(0x01, 0x30); // Enable master clock (MCLK)
  writeReg(0x02, 0x00); // Digital calibration clock
  
  // ADC/DAC powering setup
  writeReg(0x03, 0x10); // Power up analog core
  writeReg(0x04, 0x10); // Power up DAC
  writeReg(0x0D, 0x02); // Configure DAC standard resolution (e.g., 16-bit I2S)
  
  // Volume Controls
  // 0x32: DAC Digital Volume (0x00 to 0xFF, 0xBF is 0dB, 0xFF is maximum gain)
  writeReg(0x32, 0xFF); 
  
  // 0x14: System Control (PGA and Analog Gain)
  // Bits [3:0] are analog gain. 0x0B sets high analog gain.
  writeReg(0x14, 0x1B); 
  
  Serial.println("ES8311 Registers Configured for Maximum Volume.");
}

void setup() {
  Serial.begin(115200);

  // 1. Fire up I2C Bus
  Wire.begin(I2C_SDA, I2C_SCL);
  init_ES8311();

  // 3. Initialize I2S peripheral
  i2s.setPins(I2S_BCLK, I2S_LRCK, I2S_DOUT, I2S_DIN, I2S_MCLK); // BCLK, LRCK, DOUT, DIN, MCLK
  if (!i2s.begin(I2S_MODE_STD, 16000, I2S_DATA_BIT_WIDTH_16BIT, I2S_SLOT_MODE_MONO, I2S_STD_SLOT_LEFT)) {
    Serial.println("Failed to initialize I2S!");
    while (1);
  }
  Serial.println("I2S initialized successfully.");
}

void loop() {
  const int sample_rate = 16000;
  const float frequency = 440.0; // 440Hz (A4 note)
  const int ramp_duration_ms = 3000;  // 3 seconds ramp
  const int hold_duration_ms = 2000;  // 2 seconds hold at max
  const int buffer_size = 512;
  int16_t audio_buffer[buffer_size];
  
  static uint32_t sample_index = 0;
  uint32_t ramp_samples = sample_rate * (ramp_duration_ms / 1000.0);
  uint32_t hold_samples = sample_rate * (hold_duration_ms / 1000.0);
  uint32_t total_samples_in_cycle = ramp_samples + hold_samples;

  for (int i = 0; i < buffer_size; i++) {
    uint32_t current_pos = sample_index % total_samples_in_cycle;
    float volume;

    if (current_pos < ramp_samples) {
      // Phase 1: Ramp from 0 to 1 over 3 seconds
      volume = (float)current_pos / ramp_samples;
    } else {
      // Phase 2: Hold at 1 for 2 seconds
      volume = 1.0f;
    }
    
    // Generate sine wave
    float sin_val = sin(2.0 * PI * frequency * sample_index / sample_rate);
    
    // Scale to 16-bit range
    audio_buffer[i] = (int16_t)(sin_val * volume * 32767);
    
    sample_index++;
  }
  
  i2s.write((uint8_t*)audio_buffer, sizeof(audio_buffer));
}