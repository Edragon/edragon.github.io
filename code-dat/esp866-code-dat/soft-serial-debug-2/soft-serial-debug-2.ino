#include <SoftwareSerial.h>
SoftwareSerial s(13, 12);
uint8_t buffer[64];
int p = 0;
unsigned long t = 0;
void setup() {
  pinMode(13, INPUT_PULLUP); // Enable internal pull-up on RX pin
  Serial.begin(115200);
  s.begin(115200);
  Serial.println("\n--- CRSF V5 Filtered ---");
}
void loop() {
  while (s.available()) {
    uint8_t v = s.read();
    if (p == 0) {
      if (v == 0xC4 || v == 0xC8 || v == 0xEE) p = 1;
    } else {
      buffer[p++] = v;
      if (p >= 26) {
        unsigned int rc[4];
        rc[0] = (buffer[3] | buffer[4] << 8) & 0x7FF;
        rc[1] = (buffer[4] >> 3 | buffer[5] << 5) & 0x7FF;
        rc[2] = (buffer[5] >> 6 | buffer[6] << 2 | buffer[7] << 10) & 0x7FF;
        rc[3] = (buffer[7] >> 1 | buffer[8] << 7) & 0x7FF;
        bool ok = true;
        for(int i=0; i<4; i++) if(rc[i] < 170 || rc[i] > 1820) ok = false;
        if (ok) { // Removed the 100ms delay for faster output
          Serial.print("CH1:"); Serial.print(rc[0]);
          Serial.print(" CH2:"); Serial.print(rc[1]);
          Serial.print(" CH3:"); Serial.print(rc[2]);
          Serial.print(" CH4:"); Serial.println(rc[3]);
        }
        p = 0;
      }
    }
  }
}
