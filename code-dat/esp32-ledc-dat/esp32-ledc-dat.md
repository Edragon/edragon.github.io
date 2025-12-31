
# esp32-ledc-dat


## wrong part 

Add the LEDC driver include (put near top of your sketch)

    #include <driver/ledc.h>

Replace ledcAttachPin calls if the core expects ledcAttach instead of ledcAttachPin. Try this variant first:

    ledcSetup(PWM_CHANNEL1, PWM_FREQ, PWM_RESOLUTION);
    ledcSetup(PWM_CHANNEL2, PWM_FREQ, PWM_RESOLUTION);
    // use ledcAttach(channel, pin) for this core
    ledcAttach(PWM_CHANNEL1, IN1_PIN);
    ledcAttach(PWM_CHANNEL2, IN2_PIN);


Compilation error: 'ledcSetup' was not declared in this scope; did you mean 'ledc_stop'?

### error == solution 1 

If that still fails, try the original signature (some cores use this):

    ledcAttachPin(IN1_PIN, PWM_CHANNEL1);
    ledcAttachPin(IN2_PIN, PWM_CHANNEL2);

### error == solution 2

Compilation error: 'ledcAttachPin' was not declared in this scope; did you mean 'ledcAttach'?

#include <esp32-hal-ledc.h>

driver/ledc.h is the IDF/ESP-IDF header; the Arduino core for ESP32 exposes ledc APIs via esp32-hal-ledc.h. This makes ledcSetup, ledcAttachPin, ledcWrite available when compiling with the Arduino ESP32 package.



### correct 

#include <esp32-hal-ledc.h>

  // Configure LEDC PWM channels and attach pins (ESP32 Arduino Core 3.x API)
  ledcAttach(IN1_PIN, PWM_FREQ, PWM_RESOLUTION);
  ledcAttach(IN2_PIN, PWM_FREQ, PWM_RESOLUTION);

  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);

  // 默认停止
  ledcWrite(IN1_PIN, 0);
  ledcWrite(IN2_PIN, 0);