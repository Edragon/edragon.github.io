
# nimBLE-dat

NimBLE (often written as NimBLE, sometimes people shorten it to "NIM BLE") is an open-source Bluetooth Low Energy (BLE) stack originally developed by Apache Mynewt project.

On ESP32, it’s provided as an alternative BLE library to the default bluedroid stack from Espressif.

## Why NimBLE is used on ESP32

- Lower RAM & flash usage than Bluedroid (important if you’re doing Wi-Fi + BLE + other heavy tasks).
- More stable and lightweight for applications that only need BLE (not full Bluetooth Classic).
- Provides GATT server/client, advertising, scanning with a smaller footprint.
- Integrated in ESP-IDF as NimBLE host, so you can choose either Bluedroid or NimBLE.
- In Arduino-ESP32, there’s a library called NimBLE-Arduino (a wrapper around ESP-IDF NimBLE).

## Example differences

Bluedroid stack (default ESP32 BLE):

- Feature-rich, supports more profiles.
- Uses more memory (often ~100kB+ RAM).
- Heavier API.

NimBLE stack:

- Lightweight (~50% less RAM/flash).
- Faster connection / lower latency.
- Still supports most BLE use cases (advertising, GATT server/client).



## ref 

- [[BLE-dat]]