
# cooperative-loop-dat

```
void loop() {
    readELRS();              // non-blocking UART read
    updateMotors();          // update PWM
    if (millis() - lastAdc >= 1000) {
        readBattery();
        lastAdc = millis();
    }
    if (millis() - lastBle >= 2000) {
        updateBleAdvert(control.battery_mv);
        lastBle = millis();
    }
}
```