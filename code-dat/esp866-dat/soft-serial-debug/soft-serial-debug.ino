#include <SoftwareSerial.h>

SoftwareSerial soft(13, 12); // RX, TX

void setup() {
  Serial.begin(115200);
  soft.begin(115200);
  Serial.println("\n--- CRSF Raw Hex Debugger ---");
}

void loop() {
  if (soft.available()) {
    uint8_t incomingByte = soft.read();
    
    // Print as Hex
    if (incomingByte < 0x10) Serial.print("0");
    Serial.print(incomingByte, HEX);
    Serial.print(" ");
    
    // Newline every 16 bytes
    static int byteCount = 0;
    byteCount++;
    if (byteCount >= 16) {
      Serial.println();
      byteCount = 0;
    }
  }
}