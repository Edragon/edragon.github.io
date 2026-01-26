
# ESP32-C3-SDK-dat


- [[ESP-SDK-dat]] - [[ESP32-SDK-dat]] - [[ESP32-C3-SDK-dat]] - [[ESP32-S3-SDK-dat]]

- [[SPIFFS-dat]] - [[OTA-dat]]

- [[rainmaker-dat]] 

- [[bluetooth-dat]] - [[wifi-dat]] - [[zigbee-dat]] - [[USB-dat]] - [[ESP32-C3-USB-dat]]



Arduino-ESP32 core version (2.x vs 3.x)

## ledcSetup

ledcSetup() is not available in ESP32 Arduino core v3.x (it was the old LEDC API in 2.x). On ESP32‑C3 with core 3.x you must use the new LEDC API: ledcAttach(...) + ledcWrite(...) (no ledcSetup, no ledcAttachPin).

Fix (ESP32‑C3 / Arduino-ESP32 v3.x)
In your setup() replace the whole “configure PWM channels” block with this:

  // configure PWM channels for RGBW (Arduino-ESP32 core 3.x)
  ledcAttach(R_LED, LEDC_BASE_FREQ, LEDC_TIMER_BIT);
  ledcAttach(G_LED, LEDC_BASE_FREQ, LEDC_TIMER_BIT);
  ledcAttach(B_LED, LEDC_BASE_FREQ, LEDC_TIMER_BIT);
  ledcAttach(W_LED, LEDC_BASE_FREQ, LEDC_TIMER_BIT);

And in test_LED() change all writes from channel-based to pin-based:

Replace:

    ledcWrite(LEDC_CHANNEL_R, v) → ledcWrite(R_LED, v)
    ledcWrite(LEDC_CHANNEL_G, v) → ledcWrite(G_LED, v)
    ledcWrite(LEDC_CHANNEL_B, v) → ledcWrite(B_LED, v)
    ledcWrite(LEDC_CHANNEL_W, v) → ledcWrite(W_LED, v)



## ref 

- [[ESP32-C3-dat]] - [[ESP32-S3-dat]]

- [[AI]]