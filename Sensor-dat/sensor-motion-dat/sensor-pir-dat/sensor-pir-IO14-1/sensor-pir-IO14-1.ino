/*
 * PIR Motion Sensor Demo — ESP32 / Arduino
 *
 * Reads digital output from PIR sensor on GPIO14.
 * Prints motion status to Serial.
 *
 * Wiring:
 *   PIR VCC  -> 5V  (or 3.3V depending on module)
 *   PIR GND  -> GND
 *   PIR OUT  -> GPIO14
 *
 * Some PIR modules also have:
 *   - Sensitivity adjust (potentiometer)
 *   - Hold-time adjust
 */

#define PIR_PIN   14          // PIR sensor digital output

void setup() {
  Serial.begin(115200);
  delay(500);
  pinMode(PIR_PIN, INPUT);

  Serial.println("PIR Motion Sensor Demo");
  Serial.println("----------------------");
  Serial.println("Sensing...");
}

void loop() {
  int val = digitalRead(PIR_PIN);

  if (val == HIGH) {
    Serial.println("🔴 Motion detected!");
  } else {
    Serial.println("🟢 No motion");
  }

  delay(300);  // debounce / sampling interval
}
