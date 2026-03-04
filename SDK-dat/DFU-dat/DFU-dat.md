

# DFU-dat

- [[UF2-dat]]

- [[NRF52832-dat]] - [[NRF52840-dat]]

To enter **Device Firmware Update (DFU)** mode, use one of the following three methods depending on your bootloader:

### 1. Physical Button (Standard)
* **Action:** Hold the **Reset** button (or **Button 1**) while powering on or plugging in the USB.
* **Result:** A slow pulsing/breathing LED indicator.

### 2. Double-Tap Reset (Adafruit/Arduino)
* **Action:** Quickly press the **Reset** button twice (within 0.5s).
* **Result:** The device appears as a USB drive named `NRF52BOOT`.

### 3. Software Trigger (BLE)
* **Action:** Connect via the **nRF Connect** app.
* **Command:** Locate the **Secure DFU Service** and write `01` to the Control Point characteristic to jump to the bootloader.



## ref 

