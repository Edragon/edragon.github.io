
# USB-MTP-dat





## What is MTP?
- **MTP (Media Transfer Protocol)** is a USB class protocol.
- Lets a PC (Windows/macOS/Linux) access ESP32 files (SPIFFS, LittleFS, SD card).
- Host sees device as a **Media Device** (like a phone or camera).

---

## MTP vs MSC

| Feature              | MSC (Mass Storage)             | MTP (Media Transfer Protocol)        |
|----------------------|--------------------------------|--------------------------------------|
| Host view            | Removable USB disk             | Media device (camera/phone style)    |
| File system control  | Host manages FS directly       | ESP32 manages FS                     |
| Safety               | Risk of flash corruption       | Safer, controlled by ESP32           |
| Use case             | Drag & drop, direct FS access  | File browsing, sync, safe updates    |

---

## Why use MTP?
- Safer file transfer (no direct FS corruption).
- Compatible with Windows Explorer, macOS Finder, Linux file managers.
- ESP32 firmware stays in control of FS.

## ESP32-S3 Core and MTP Support Availability

- **ESP-IDF**: MTP is supported via TinyUSB component.
- **Arduino-ESP32 core (v2.0.5 and newer)**: Includes MTP classes (`MTP.h`).
- Works on **ESP32-S2** and **ESP32-S3** (chips with native USB OTG).
- Not supported on original ESP32 or ESP32-C3 (no native USB device).


## ref 

- [[USB-dat]]