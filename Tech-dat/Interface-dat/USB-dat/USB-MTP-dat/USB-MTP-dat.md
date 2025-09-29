
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




## ref 

- [[USB-dat]]