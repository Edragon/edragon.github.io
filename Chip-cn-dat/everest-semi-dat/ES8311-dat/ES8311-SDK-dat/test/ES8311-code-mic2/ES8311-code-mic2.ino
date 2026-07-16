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
  delay(100);
  writeReg(0x00, 0x00); // Clear reset
  
  // Clock configurations
  writeReg(0x01, 0x30); // Enable master clock (MCLK)
  writeReg(0x02, 0x00); // Digital calibration clock
  
  // ADC setup
  writeReg(0x03, 0x70); // Power up analog core & ADC
  writeReg(0x13, 0x40); // Select Mic-1 input
  writeReg(0x14, 0x1A); // Set ADC PGA gain (24dB or similar)
  writeReg(0x17, 0xBF); // ADC Digital Volume (0dB)
  
  // I2S configuration for ADC
  writeReg(0x0A, 0x0C); // ADC I2S format, 16-bit
  
  Serial.println("ES8311 Registers Configured for Microphone.");
}

void setup() {
  Serial.begin(115200);
  while(!Serial);

  // 1. Fire up I2C Bus
  Wire.begin(I2C_SDA, I2C_SCL);
  init_ES8311();

  // 3. Initialize I2S peripheral
  i2s.setPins(I2S_BCLK, I2S_LRCK, I2S_DOUT, I2S_DIN, I2S_MCLK); // BCLK, LRCK, DOUT, DIN, MCLK
  if (!i2s.begin(I2S_MODE_STD, 16000, I2S_DATA_BIT_WIDTH_16BIT, I2S_SLOT_MODE_MONO, I2S_STD_SLOT_LEFT)) {
    Serial.println("Failed to initialize I2S!");
    while (1);
  }
  Serial.println("I2S initialized for Microphone.");
}

void loop() {
  int16_t sample = 0;
  size_t bytes_read = i2s.readBytes((uint8_t*)&sample, sizeof(sample));
  
  if (bytes_read == sizeof(sample)) {
    Serial.println(sample);
  }
}