#include <Wire.h>
#include <ESP_I2S.h> // Uses the standard ESP32 Arduino I2S library

// Fallback in case Arduino core doesn't define PI
#ifndef PI
#define PI 3.141592653589793f
#endif

// Define your board's pin layout (Change these values to match your specific board schematic)
#define I2S_BCLK 14
#define I2S_LRCK 12
#define I2S_DOUT 13
#define I2S_DIN  -1   // not used (DAC playback only)

#define I2S_MCLK 6

#define I2C_SDA 5
#define I2C_SCL 4


// NS4150 CTRL pin: hardware-pulled HIGH (no GPIO needed)

#define ES8311_ADDR  0x18 // Default I2C Address for ES8311

I2SClass i2s;

// Helper to write to ES8311 registers over I2C
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

void init_ES8311() {
  // === ES8311 Register Map (from arduino-audio-driver ES8311.h) ===
  // 0x00=RESET, 0x01=CLK_MGR1, 0x02=CLK_MGR2, 0x03=CLK_MGR3(ADC OSR),
  // 0x04=CLK_MGR4(DAC OSR), 0x05=CLK_MGR5(ADC/DAC div),
  // 0x06=CLK_MGR6(BCLK div), 0x07=CLK_MGR7(LRCK H), 0x08=CLK_MGR8(LRCK L),
  // 0x09=SDP_IN(DAC I2S), 0x0A=SDP_OUT(ADC I2S),
  // 0x0B-0x0C=SYSTEM, 0x0D=ANALOG_PWR, 0x0E=SYSTEM,
  // 0x10-0x11=SYSTEM, 0x12-0x13=SYSTEM,
  // 0x14=SYSTEM(PGA/analog), 0x15-0x1C=ADC,
  // 0x31-0x35=DAC, 0x37=DAC_CTRL, 0x32=DAC_VOL,
  // 0xFD=CHIP_ID1, 0xFE=CHIP_ID2

  // === 1. Initial register setup (before reset) ===
  writeReg(0x01, 0x30); // CLK_MGR1: enable main clocks
  writeReg(0x02, 0x00); // CLK_MGR2: clear pre-divider
  writeReg(0x03, 0x10); // CLK_MGR3: ADC OSR=16x (default)
  writeReg(0x16, 0x24); // ADC_REG16: MIC gain initial
  writeReg(0x04, 0x10); // CLK_MGR4: DAC OSR=16x
  writeReg(0x05, 0x00); // CLK_MGR5: clear ADC/DAC dividers
  writeReg(0x0B, 0x00); // SYSTEM_REG0B
  writeReg(0x0C, 0x00); // SYSTEM_REG0C
  writeReg(0x10, 0x1F); // SYSTEM_REG10
  writeReg(0x11, 0x7F); // SYSTEM_REG11

  // === 2. Reset chip ===
  writeReg(0x00, 0x80); // RESET: trigger reset
  delay(20);

  // === 3. Set Slave Mode (ESP32 is I2S Master) ===
  uint8_t regv = readReg(0x00);
  regv &= 0xBF;         // Clear bit 6 → Slave mode
  writeReg(0x00, regv);

  // === 4. Enable all internal clocks, use BCLK as clock source ===
  // Using BCLK (SCLK) instead of MCLK pin avoids MCLK frequency mismatch
  writeReg(0x01, 0x3F); // CLK_MGR1: all clocks ON
  regv = readReg(0x01);
  regv |= 0x80;         // Set bit 7 → clock source = BCLK (SCLK pin)
  writeReg(0x01, regv);

  // === 5. Clock dividers for 16kHz @ 4.096MHz MCLK (256*Fs) ===
  // From coefficient table: {4096000, 16000, pre=1, mult=1, adc=1, dac=1,
  //                          fs=0, lrch=0, lrcl=0xFF, bck=4, osr=0x10}
  writeReg(0x02, 0x00); // CLK_MGR2: pre_div=1, multi=1
  writeReg(0x03, 0x10); // CLK_MGR3: fs_mode=0, adc_osr=0x10
  writeReg(0x04, 0x10); // CLK_MGR4: dac_osr=0x10
  writeReg(0x05, 0x00); // CLK_MGR5: adc_div=1, dac_div=1
  writeReg(0x06, 0x03); // CLK_MGR6: bclk_div=4
  writeReg(0x07, 0x00); // CLK_MGR7: lrck_h=0
  writeReg(0x08, 0xFF); // CLK_MGR8: lrck_l=0xFF

  // === 6. I2S Format: 16-bit Phillips (standard I2S) ===
  writeReg(0x09, 0x0C); // SDP_IN: 16-bit I2S for DAC
  writeReg(0x0A, 0x0C); // SDP_OUT: 16-bit I2S for ADC

  // === 7. System init (from official driver) ===
  writeReg(0x13, 0x10); // SYSTEM_REG13
  writeReg(0x1B, 0x0A); // ADC_REG1B
  writeReg(0x1C, 0x6A); // ADC_REG1C

  Serial.println("ES8311 Init done (clock + I2S format).");

  // === Verify chip ID ===
  uint8_t chip_id1 = readReg(0xFD);
  uint8_t chip_id2 = readReg(0xFE);
  Serial.printf("ES8311 Chip ID: 0x%02X%02X (expect 0x8311)\n", chip_id1, chip_id2);
}

void start_ES8311_DAC() {
  // === START sequence for DAC playback (from official driver) ===
  // Powers up DAC, unmutes, routes audio to output

  // 1. Set PGA / analog control (max analog gain)
  writeReg(0x14, 0x3B); // SYSTEM_REG14: max PGA gain, no mic bias

  // 2. Unmute DAC on I2S interface (clear bit 6 in SDP_IN)
  uint8_t dac_iface = readReg(0x09) & 0xBF;
  writeReg(0x09, dac_iface);

  // 3. Unmute ADC on I2S interface (not needed, but harmless)
  uint8_t adc_iface = readReg(0x0A) & 0xBF;
  writeReg(0x0A, adc_iface);

  // 4. ADC digital volume = max
  writeReg(0x17, 0xBF); // ADC_REG17

  // 5. System analog enable
  writeReg(0x0E, 0x02); // SYSTEM_REG0E

  // 6. System control
  writeReg(0x12, 0x00); // SYSTEM_REG12

  // 7. Power up analog (DAC + ADC + full analog blocks)
  writeReg(0x0D, 0x03); // SYSTEM_REG0D: power up DAC + ADC analog

  // 8. ADC control
  writeReg(0x15, 0x40); // ADC_REG15

  // 9. DAC control - max output drive
  writeReg(0x37, 0x78); // DAC_REG37: max DAC output drive (was 0x68)

  // 10. GPIO / digital
  writeReg(0x45, 0x00); // GP_REG45

  // 11. DAC digital volume (0x00=mute, 0xBF=0dB, 0xFF=+6dB max)
  writeReg(0x32, 0xFF); // DAC_REG32: MAXIMUM volume

  Serial.println("ES8311 DAC STARTED (powered, unmuted, routed).");
}

void setup() {
  Serial.begin(115200);
  delay(1000); // Wait for Serial monitor

  // === 1. Fire up I2C Bus ===
  Wire.begin(I2C_SDA, I2C_SCL);
  Wire.setClock(100000); // 100kHz standard speed

  // === 2. Scan I2C to verify ES8311 is reachable ===
  Wire.beginTransmission(ES8311_ADDR);
  if (Wire.endTransmission() == 0) {
    Serial.printf("✅ ES8311 found at I2C address 0x%02X\n", ES8311_ADDR);
  } else {
    Serial.printf("❌ ES8311 NOT found at I2C address 0x%02X! Check wiring.\n", ES8311_ADDR);
  }

  init_ES8311();

  // === 2b. Power up DAC and start output path ===
  start_ES8311_DAC();

  // === 3. Initialize I2S peripheral (STEREO to match ES8311) ===
  i2s.setPins(I2S_BCLK, I2S_LRCK, I2S_DOUT, I2S_DIN, I2S_MCLK);
  if (!i2s.begin(I2S_MODE_STD, 16000, I2S_DATA_BIT_WIDTH_16BIT, I2S_SLOT_MODE_STEREO, I2S_STD_SLOT_BOTH)) {
    Serial.println("❌ Failed to initialize I2S!");
    while (1);
  }
  Serial.println("✅ I2S initialized successfully (STEREO).");
}

// === Melody: "Twinkle Twinkle Little Star" ===
// Frequencies in Hz
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_REST 0

struct Note {
  uint16_t freq;     // Hz, 0 = rest
  uint16_t duration; // ms
};

const Note melody[] = {
  // Twinkle twinkle little star
  {NOTE_C4, 400}, {NOTE_C4, 400}, {NOTE_G4, 400}, {NOTE_G4, 400},
  {NOTE_A4, 400}, {NOTE_A4, 400}, {NOTE_G4, 800},
  // How I wonder what you are
  {NOTE_F4, 400}, {NOTE_F4, 400}, {NOTE_E4, 400}, {NOTE_E4, 400},
  {NOTE_D4, 400}, {NOTE_D4, 400}, {NOTE_C4, 800},
  // Up above the world so high
  {NOTE_G4, 400}, {NOTE_G4, 400}, {NOTE_F4, 400}, {NOTE_F4, 400},
  {NOTE_E4, 400}, {NOTE_E4, 400}, {NOTE_D4, 800},
  // Like a diamond in the sky
  {NOTE_G4, 400}, {NOTE_G4, 400}, {NOTE_F4, 400}, {NOTE_F4, 400},
  {NOTE_E4, 400}, {NOTE_E4, 400}, {NOTE_D4, 800},
  // Twinkle twinkle little star
  {NOTE_C4, 400}, {NOTE_C4, 400}, {NOTE_G4, 400}, {NOTE_G4, 400},
  {NOTE_A4, 400}, {NOTE_A4, 400}, {NOTE_G4, 800},
  // How I wonder what you are
  {NOTE_F4, 400}, {NOTE_F4, 400}, {NOTE_E4, 400}, {NOTE_E4, 400},
  {NOTE_D4, 400}, {NOTE_D4, 400}, {NOTE_C4, 800},
  // Pause before repeat
  {NOTE_REST, 600},
};
const int melody_len = sizeof(melody) / sizeof(Note);

const int SAMPLE_RATE = 16000;
const int BUFFER_SAMPLES = 256;

// Timing constants (in ms)
const int ATTACK_MS  = 12;   // note attack ramp
const int RELEASE_MS = 15;   // note release ramp
const int GAP_MS     = 3;    // silence gap between notes
const int XFADE_MS   = 8;    // frequency crossfade duration

// State
static float phase = 0.0f;
static uint8_t note_idx = 0;
static uint32_t note_start_ms = 0;
static float prev_freq = melody[0].freq;
static bool first_buffer = true;

void loop() {
  int16_t audio_buffer[BUFFER_SAMPLES * 2]; // stereo L,R interleaved
  uint32_t now = millis();
  uint32_t note_elapsed = now - note_start_ms;
  Note current = melody[note_idx];

  // --- Note transition ---
  if (note_elapsed >= current.duration + GAP_MS) {
    prev_freq = current.freq;
    note_idx++;
    if (note_idx >= melody_len) note_idx = 0;
    note_start_ms = now;
    current = melody[note_idx];
    Serial.printf("♪ Note %d: freq=%d Hz, dur=%d ms\n",
                  note_idx, current.freq, current.duration);
  }
  // Recalculate note_elapsed AFTER possible transition (fixes envelope bug)
  note_elapsed = now - note_start_ms;

  // --- Crossfade frequency between old and new note ---
  float xfade_k = (note_elapsed < XFADE_MS) ? (note_elapsed / (float)XFADE_MS) : 1.0f;
  float freq = prev_freq * (1.0f - xfade_k) + current.freq * xfade_k;

  // --- Generate audio buffer ---
  int gap_samples = GAP_MS * SAMPLE_RATE / 1000;
  int attack_samples = ATTACK_MS * SAMPLE_RATE / 1000;
  int release_samples = RELEASE_MS * SAMPLE_RATE / 1000;
  // current elapsed in samples (estimate, tracking from note_start)
  uint32_t sample_offset = (uint32_t)((float)note_elapsed * SAMPLE_RATE / 1000.0f);
  uint32_t dur_samples = (uint32_t)((float)current.duration * SAMPLE_RATE / 1000.0f);

  for (int i = 0; i < BUFFER_SAMPLES; i++) {
    uint32_t s = sample_offset + i;
    int16_t sample;

    // Silence during gap between notes
    if (s < (uint32_t)gap_samples) {
      sample = 0;
    }
    // Silence during rest (after crossfade)
    else if (current.freq == 0 && note_elapsed >= XFADE_MS) {
      sample = 0;
    }
    else {
      // Envelope: attack → sustain → release
      float envelope = 0.75f;
      uint32_t note_s = s - gap_samples; // sample pos relative to note body
      if (note_s < (uint32_t)attack_samples) {
        envelope *= (float)note_s / attack_samples;              // linear attack
      } else if (note_s > dur_samples - release_samples && dur_samples > (uint32_t)(attack_samples + release_samples)) {
        uint32_t rel = dur_samples - note_s;
        envelope *= (float)rel / release_samples;                // linear release
      }

      sample = (int16_t)(sinf(phase) * envelope * 28000);
      phase += 2.0f * PI * freq / SAMPLE_RATE;
      if (phase > 2.0f * PI) phase -= 2.0f * PI;
    }
    audio_buffer[i * 2]     = sample; // Left
    audio_buffer[i * 2 + 1] = sample; // Right
  }

  size_t written = i2s.write((uint8_t*)audio_buffer, sizeof(audio_buffer));
  if (written != sizeof(audio_buffer)) {
    Serial.printf("⚠ I2S write short: %d / %d bytes\n", written, sizeof(audio_buffer));
  }

  if (first_buffer) {
    Serial.println("▶ Melody started: Twinkle Twinkle Little Star");
    first_buffer = false;
  }
}