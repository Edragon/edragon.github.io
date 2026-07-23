
// Step 1: 直流测试 — 用万用表 DC 档测 GPIO15 是否为 3.3V
// Step 2: 确认后再用示波器看方波

void setup() {
    Serial.begin(115200);
    delay(1000);

    pinMode(15, OUTPUT);
    digitalWrite(15, HIGH);
    Serial.println("GPIO 15 set HIGH (3.3V). Measure with multimeter DC first!");
    Serial.println("If 3.3V OK, proceeding to square wave test...");
    delay(5000);

    // LEDC 方波：8-bit 分辨率，duty=128 = 50%
    ledcAttach(15, 100000, 8);    // 8-bit → max duty 255
    ledcWrite(15, 128);           // 128 = 50% duty
    Serial.println("Now GPIO 15 = 100kHz square wave. Check oscilloscope.");
    Serial.println("Scope: DC coupling, 1V/div, 5us/div, rising edge trigger ~1.5V");
}

void loop() {}