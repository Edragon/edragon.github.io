

#include <Wire.h>

void setup() {
    Serial.begin(115200);
    // 用你实际接的引脚！
    Wire.begin(5, 4);  // 如果实际不是 18/17，改这里
    Wire.setClock(50000);  // 降到 50kHz 测试

    Serial.println("=== I2C Scanner ===");
    for (uint8_t addr = 1; addr < 127; addr++) {
        Wire.beginTransmission(addr);
        if (Wire.endTransmission() == 0) {
            Serial.printf("Found: 0x%02X\n", addr);
        }
    }
    Serial.println("=== Done ===");
}

void loop() {}