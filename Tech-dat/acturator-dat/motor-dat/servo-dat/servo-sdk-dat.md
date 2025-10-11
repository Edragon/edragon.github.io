
# servo-sdk-dat.md

- ESP32Servo 


ESP32 LEDC official libarry 

https://docs.espressif.com/projects/arduino-esp32/en/latest/api/ledc.html?highlight=ledcWrite




## 'ledcSetup' was not declared in this scope


If you prefer to use the latest ESP32 core version, you need to update your code to reflect the new LEDC API.
- `ledcSetup() and ledcAttachPin()` are no longer used.
- You can now use `analogWrite(pin, value)` for basic PWM, where value is the duty cycle.
- For more advanced control, use `ledcAttachChannel(pin, freq, resolution, channel)` to attach a pin to a specific PWM channel and then `ledcWrite(pin, duty)` to set the duty cycle. The channel will be automatically attributed if not specified.


### New Code (ESP32 Core >= 3.0.0):

```
const int LED_PIN = 2;
const int FREQ = 5000;
const int RESOLUTION = 8; // Not directly used in ledcWrite(), but useful for calculating duty cycle

void setup() {
  // Option 1: Use analogWrite for basic PWM
  // analogWrite(LED_PIN, 128); // Sets initial duty cycle

  // Option 2: Use ledcAttachChannel for more control
  ledcAttachChannel(LED_PIN, FREQ, RESOLUTION, 0); // Attaches pin to channel 0
}

void loop() {
  // Option 1: Use analogWrite
  // analogWrite(LED_PIN, 128);
  // delay(1000);
  // analogWrite(LED_PIN, 0);
  // delay(1000);

  // Option 2: Use ledcWrite
  ledcWrite(LED_PIN, 128); // 50% duty cycle for 8-bit resolution
  delay(1000);
  ledcWrite(LED_PIN, 0);
  delay(1000);
}

``` 

### Old Code (ESP32 Core < 3.0.0):

```
const int LED_PIN = 2;
const int FREQ = 5000;
const int LED_CHANNEL = 0;
const int RESOLUTION = 8;

void setup() {
  ledcSetup(LED_CHANNEL, FREQ, RESOLUTION);
  ledcAttachPin(LED_PIN, LED_CHANNEL);
}

void loop() {
  ledcWrite(LED_CHANNEL, 128); // 50% duty cycle for 8-bit resolution
  delay(1000);
  ledcWrite(LED_CHANNEL, 0);
  delay(1000);
}
```


## servo 360 


