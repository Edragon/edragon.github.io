#include <SoftwareSerial.h>

// Define SoftwareSerial pins: RX, TX
// We'll use pin 2 for RX (receiving data from HLW8032)
// Pin 3 for TX (not strictly needed for HLW8032 communication but required by library)
SoftwareSerial hlwSerial(2, 3); 

void setup() {
  Serial.begin(9600); // Initialize hardware serial for debugging output to Serial Monitor
  while (!Serial) {
    ; // wait for hardware serial port to connect.
  }
  Serial.println("Arduino initialized. Hardware Serial for debugging active.");

  hlwSerial.begin(4800); // Initialize software serial for HLW8032 communication
  Serial.println("Software Serial on pins 2 (RX) and 3 (TX) initialized for HLW8032.");
  Serial.println("Waiting for HLW8032 data (starting with 0xF2 and Check Register 0x5A)...");
}

void loop() {
  if (hlwSerial.available() > 0) { // Check if data is available on SoftwareSerial
    if (hlwSerial.peek() == 0xF2) { // Check if the first byte is the start byte without consuming it yet
      // Check if enough bytes for Start Byte (1) + Check Register (1) are available
      if (hlwSerial.available() >= 2) { 
        byte startByte = hlwSerial.read(); // Read the start byte (confirmed 0xF2 by peek)
        byte checkRegister = hlwSerial.read(); // Read the next byte for Check Register

        if (checkRegister == 0x5A) {
          // Start byte is 0xF2 and Check Register is 0x5A, proceed
          Serial.print("Start Byte: 0x");
          Serial.println(startByte, HEX);
          Serial.print("Check Register: 0x");
          Serial.println(checkRegister, HEX);

          // Now check if enough bytes for the 4 registers (12 bytes) are available
          // Total bytes for the segment we want: Start(1) + Check(1) + VP(3) + V(3) + CP(3) + C(3) = 14
          // We've read 2, so we need 12 more.
          if (hlwSerial.available() >= 12) { 
            // Read Voltage Parameter Register (3 bytes)
            byte vpReg[3];
            Serial.print("Voltage Parameter Register (hex): 0x");
            for (int i = 0; i < 3; i++) {
              vpReg[i] = hlwSerial.read();
              if (vpReg[i] < 0x10) Serial.print("0");
              Serial.print(vpReg[i], HEX);
              Serial.print(" ");
            }
            Serial.println();
            unsigned long voltageParam = ((unsigned long)vpReg[0] << 16) | ((unsigned long)vpReg[1] << 8) | vpReg[2];
            Serial.print("Voltage Parameter Register (dec): ");
            Serial.println(voltageParam);

            // Read Voltage Register (3 bytes)
            byte vReg[3];
// ...existing code...
            Serial.print("Voltage Register (hex): 0x");
            for (int i = 0; i < 3; i++) {
              vReg[i] = hlwSerial.read();
              if (vReg[i] < 0x10) Serial.print("0");
              Serial.print(vReg[i], HEX);
              Serial.print(" ");
            }
            Serial.println();
            unsigned long voltageVal = ((unsigned long)vReg[0] << 16) | ((unsigned long)vReg[1] << 8) | vReg[2];
            Serial.print("Voltage Register (dec): ");
            Serial.println(voltageVal);

            // Read Current Parameter Register (3 bytes)
            byte cpReg[3];
            Serial.print("Current Parameter Register (hex): 0x");
            for (int i = 0; i < 3; i++) {
              cpReg[i] = hlwSerial.read();
              if (cpReg[i] < 0x10) Serial.print("0");
              Serial.print(cpReg[i], HEX);
              Serial.print(" ");
            }
            Serial.println();
            unsigned long currentParam = ((unsigned long)cpReg[0] << 16) | ((unsigned long)cpReg[1] << 8) | cpReg[2];
            Serial.print("Current Parameter Register (dec): ");
            Serial.println(currentParam);

            // Read Current Register (3 bytes)
            byte cReg[3];
            Serial.print("Current Register (hex): 0x");
            for (int i = 0; i < 3; i++) {
              cReg[i] = hlwSerial.read();
              if (cReg[i] < 0x10) Serial.print("0");
              Serial.print(cReg[i], HEX);
              Serial.print(" ");
            }
            Serial.println();
            unsigned long currentVal = ((unsigned long)cReg[0] << 16) | ((unsigned long)cReg[1] << 8) | cReg[2];
            Serial.print("Current Register (dec): ");
            Serial.println(currentVal);

            Serial.println("--- End of Packet Segment ---");
            
            // Consider reading the rest of the 24-byte packet here
            // if the HLW8032 always sends full packets, to keep the buffer clean.
            // int remainingBytesInFullPacket = 24 - 14; // Example if full packet is 24 bytes
            // for(int i=0; i < remainingBytesInFullPacket; i++){
            //   if(hlwSerial.available()) hlwSerial.read(); else break;
            // }

          } else {
            Serial.println("Error: Incomplete packet after valid Start (0xF2) and Check Register (0x5A). Waiting for more data.");
            // The first two bytes (0xF2 and 0x5A) are consumed.
            // The loop will re-evaluate on the next iteration.
          }
        } else {
          // Start byte was 0xF2, but Check Register is incorrect.
          Serial.print("Error: Start Byte 0xF2 found, but Check Register is 0x");
          if (checkRegister < 0x10) Serial.print("0");
          Serial.print(checkRegister, HEX);
          Serial.println(" (expected 0x5A). Discarding this packet attempt.");
          // Both startByte (0xF2) and the incorrect checkRegister are consumed.
          // The loop will continue to search for the next 0xF2.
        }
      } else {
        // Peeked 0xF2, but not enough bytes for Start + Check Register yet.
        // Loop will run again, hopefully more data will be available.
      }
    } else {
      // Byte is not the start byte (0xF2), discard it to find the next potential start.
      hlwSerial.read(); 
      // Serial.println("Discarding non-start byte..."); // Optional: for debugging
    }
  }
}