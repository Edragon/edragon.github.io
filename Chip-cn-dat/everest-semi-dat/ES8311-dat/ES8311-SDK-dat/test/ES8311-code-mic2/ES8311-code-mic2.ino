#include <Wire.h>
#include <ESP_I2S.h>

// PIN CONFIGURATION
#define I2C_SDA      5
#define I2C_SCL      4

#define I2S_BCLK     14
#define I2S_LRCK     12
#define I2S_DOUT     13
#define I2S_DIN      11    // unused (DAC playback only)
#define I2S_MCLK     6

#define ES8311_ADDR  0x18 

I2SClass i2s;

void writeReg(uint8_t reg, uint8_t value) {
  Wire.beginTransmission(ES8311_ADDR);
  Wire.write(reg);
  Wire.write(value);
  Wire.endTransmission();
}

void init_ES8311() {
  // 1. Reset
  writeReg(0x00, 0x80); delay(50); 
  writeReg(0x00, 0x00); 

  // 2. Clock Management (Slave Mode)
  writeReg(0x01, 0x30); // Enable MCLK and Clocks
  writeReg(0x02, 0x10); // ADC Clock
  writeReg(0x03, 0x10); // DAC Clock
  
  // 3. I2S Format (Phillips 16-bit)
  writeReg(0x0A, 0x00); // Phillips Mode
  writeReg(0x0B, 0x0C); // 16-bit word length (0x0C)
  
  // 4. Power & Analog Path
  writeReg(0x0D, 0x03); // Power up Analog core
  writeReg(0x0E, 0x02); // Enable ADC Analog
  writeReg(0x13, 0x40); // SELECT MIC1 (MIC_P), Power up MICBIAS
  writeReg(0x14, 0x1A); // PGA Gain +24dB
  writeReg(0x15, 0x00); // SELECT ANALOG ADC (0x40 was Digital Mic mode)
  writeReg(0x16, 0x00); // ALC Off
  writeReg(0x17, 0x00); // Volume Max
  
  // 5. Digital Enable
  writeReg(0x45, 0x01); 
  Serial.println("ES8311 Configured (Phillips, MIC1, +24dB)");
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  Wire.begin(I2C_SDA, I2C_SCL);
  init_ES8311();

  // STABLE I2S CONFIG
  i2s.setPins(I2S_BCLK, I2S_LRCK, I2S_DOUT, I2S_DIN, I2S_MCLK);
  
  // Use Phillips mode and 16-bit. Read both slots.
  if (!i2s.begin(I2S_MODE_STD, 16000, I2S_DATA_BIT_WIDTH_16BIT, I2S_SLOT_MODE_STEREO, I2S_STD_SLOT_BOTH)) {
    Serial.println("I2S Init Failed");
    while (1);
  }
  Serial.println("I2S Ready (Stereo 16-bit).");
}

void loop() {
  int16_t samples[2]; // [0] = Left, [1] = Right
  size_t bytes_read = i2s.readBytes((char*)samples, sizeof(samples));
  
  if (bytes_read == sizeof(samples)) {
    // If you talk into the mic, these numbers should JUMP wildly
    Serial.printf("L:%6d R:%6d\n", samples[0], samples[1]);
  }
}