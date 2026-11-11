

# radiomaster-lua-dat


- [[ELRS-dat]] - [[ELRS-script-dat]] - [[radiomaster-lua-dat]] - [[LUA-dat]]

- [[radiomaster-lua-dat]] - [[radiomaster-dat]] - [[radiomaster-pocket-dat]] - [[edgetx-dat]] - [[lua-dat]] - [[SDK-dat]]

## run scripts 

- [[radiomaster-dat]] - [[radiomaster-pocket-dat]] == system - [[edgetx-dat]] 

**Yes, absolutely.** The RadioMaster Pocket runs on **EdgeTX**, so it fully supports EdgeTX Lua scripts.

However, because the RadioMaster Pocket features a **monochrome (black and white) 128x64 LCD screen**, there are a few important considerations:

### 1. Screen Compatibility

* **B/W Compatible Scripts:** Scripts designed for black-and-white displays—such as the standard **ExpressLRS Lua script**, **Betaflight configuration scripts (B/W version)**, and various telemetry or tool scripts—work perfectly.
* **Color-Only Scripts:** Scripts built specifically for large color-screen radios (like the TX16S or Boxer color edition, which use LVGL or color graphics) **will not display properly** or will fail to run because the Pocket lacks a color graphics processor and display.




### 2. Common Scripts Used on the Pocket

* **ExpressLRS Lua:** Used out-of-the-box to change packet rates, telemetry ratios, and transmitter power.
* **Betaflight Lua / Multi / ELRS Finder:** Highly popular utility scripts optimized for black-and-white layouts.

### Quick Tips for Installation:

1. Make sure you download or use versions of scripts specifically optimized for **B/W (Black and White) 128x64 screens**.
2. Place them in the correct directories on your SD card (typically `/SCRIPTS/TOOLS/` for tool-based scripts).
3. Keep filenames relatively short (standard EdgeTX naming conventions apply).





## ref 



