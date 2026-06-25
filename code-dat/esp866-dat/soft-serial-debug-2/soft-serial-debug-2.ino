#include <SoftwareSerial.h>

// PIN 12 = RX, PIN 13 = TX
SoftwareSerial soft(12, 13);

uint8_t buffer[64];
int bufPtr = 0;
unsigned long lastByteTime = 0;
unsigned long lastPrintTime = 0;

void setup() {
  Serial.begin(115200);
  // Increase SoftwareSerial reliability by sticking to 115200
  soft.begin(115200); 
  Serial.println("\n--- CRSF Debug V2 (Robust) ---");
}

void loop() {
  unsigned long now = millis();

  while (soft.available()) {
    uint8_t b = soft.read();
    lastByteTime = now;

    // 1. SYNC: Look for 0xC8 (Receiver Address)
    if (bufPtr == 0) {
      if (b == 0xC8) {
        buffer[bufPtr++] = b;
      }
    } 
    // 2. LENGTH: Expecting 0x18 (24 bytes payload) for RC Channels
    else if (bufPtr == 1) {
      if (b == 0x18) {
        buffer[bufPtr++] = b;
      } else {
        bufPtr = 0; // Invalid length for channels, restart
      }
    }
    // 3. TYPE: Expecting 0x16 (RC Channels)
    else if (bufPtr == 2) {
      if (b == 0x16) {
        buffer[bufPtr++] = b;
      } else {
        bufPtr = 0; // Not a channel frame
      }
    }
    // 4. COLLECT DATA
    else {
      buffer[bufPtr++] = b;
      
      // CRSF RC packet is exactly 26 bytes: [Addr][Len][Type][22 bytes channels][CRC]
      if (bufPtr >= 26) {
        decodeAndPrint(buffer);
        bufPtr = 0;
      }
    }
  }

  // RECOVERY: If we got half a packet but no more data for 10ms, reset
  if (bufPtr > 0 && (now - lastByteTime > 10)) {
    bufPtr = 0;
  }
}

void decodeAndPrint(uint8_t* b) {
  // Only print every 100ms to reduce CPU load and let SoftwareSerial run smoothly
  if (millis() - lastPrintTime < 100) return;
  lastPrintTime = millis();

  unsigned int ch[4];
  // 11-bit decoding logic
  ch[0] = (b[3] | b[4] << 8) & 0x07FF;
  ch[1] = (b[4] >> 3 | b[5] << 5) & 0x07FF;
  ch[2] = (b[5] >> 6 | b[6] << 2 | b[7] << 10) & 0x07FF;
  ch[3] = (b[7] >> 1 | b[8] << 7) & 0x07FF;

  Serial.print("T:");  Serial.print(ch[2]); // Throttle usually CH3
  Serial.print(" R:");  Serial.print(ch[3]); // Yaw/Rudder
  Serial.print(" E:");  Serial.print(ch[1]); // Pitch/Elevator
  Serial.print(" A:");  Serial.print(ch[0]); // Roll/Aileron
  Serial.println();
}