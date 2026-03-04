# OmniVision-dat

legacy wiki page - https://w.electrodragon.com/w/OV_Camera


- [[sensor-camera-dat]] - [[sensor-camera-HDK-dat]] - [[OmniVision-dat]] - [[LDO-2CH-dat]]



## Chip Overview

- [[OV3660-dat]] - [[OV2640-dat]] - [[OV5640-dat]] - [[omnivision-dat]] - [[camera-DVP-dat]]


- [[OV3660-dat]] - [[omnivision-dat]]


- [[OV9281-dat]]

| Type           | Mega pixels | Replace old version | Specs           |
| -------------- | ----------- | ------------------- | --------------- |
| [[OV7670-dat]] | 30 MP       |                     |                 |
| [[OV7725-dat]] | 30 MP       | OV7670              |                 |
| [[OV2640-dat]] | 200 MP      |                     |                 |
| OV2710         | 200 MP      |                     | 1920X1080@30fps |
| OV5640         |             |                     |                 |
| OV9712         |             |                     |                 |
| OV9732         |             |                     |                 |


## common option Camera Sensor Comparison: OV2640 vs. OV3660 vs. OV5640

The following table compares the three most popular image sensors used with the ESP32 and ESP32-S3 platforms.

| Feature             | OV2640                    | OV3660                     | OV5640                     |
| :------------------ | :------------------------ | :------------------------- | :------------------------- |
| **Max Resolution**  | 2 MP (1600 x 1200)        | 3 MP (2048 x 1536)         | **5 MP** (2592 x 1944)     |
| **Optical Size**    | 1/4"                      | 1/5"                       | 1/4"                       |
| **Pixel Size**      | 2.2 $\mu m$ x 2.2 $\mu m$ | 1.4 $\mu m$ x 1.4 $\mu m$  | 1.4 $\mu m$ x 1.4 $\mu m$  |
| **Architecture**    | FSI (Front Side Illum.)   | **BSI** (Back Side Illum.) | **BSI** (Back Side Illum.) |
| **Interface**       | DVP (Parallel)            | DVP (Parallel)             | DVP & MIPI                 |
| **Max Frame Rate**  | 15 fps @ UXGA             | 15 fps @ QXGA              | 15 fps @ QSXGA             |
| **720p HD Video**   | N/A (Sub-sampled)         | 45 fps                     | **60 fps**                 |
| **1080p Video**     | No                        | 20 fps                     | **30 fps**                 |
| **Autofocus**       | No (Fixed/Manual)         | No (Fixed/Manual)          | **Yes** (Optional AF)      |
| **JPEG Encoder**    | Built-in                  | Built-in                   | Built-in                   |
| **Low Light Perf.** | Average                   | **Excellent**              | Good                       |
| **Sensitivity**     | 0.6 V/Lux-sec             | 0.67 V/Lux-sec             | 0.6 V/Lux-sec              |
| **Dynamic Range**   | 50 dB                     | **70 dB**                  | 68 dB                      |

---

### Summary Recommendation

* **OV2640 (The Reliable Standard):** Best for basic streaming and general IoT. It is the most widely supported sensor for the original **ESP32-CAM (AI-Thinker)** and consumes the least power.
* **OV3660 (The AI/Low-Light Specialist):** Highly recommended for **ESP32-S3** projects involving computer vision or face detection. Its **BSI (Back Side Illumination)** architecture and higher dynamic range make it significantly better in dim environments.
* **OV5640 (The Photographer):** Choose this if you need high-resolution still photos or QR code scanning. The **Autofocus (AF)** version is a game-changer for macro photography or reading documents. Note that it runs much hotter than the OV2640.



---

### Technical Implementation Tip
When switching between these sensors on an ESP32, you usually only need to change the `PIXFORMAT` and `FRAMESIZE` in your `camera_config_t`. However, the **OV5640** often requires a more robust power supply (at least 500mA) to handle the peak current during initialization and autofocus.

Would you like me to provide the specific initialization code for the OV5640 to enable its autofocus features?




## 24 pins compare 

- [[OV2640-dat]] 

## pins 

- [[OV2640-dat]]

| NO. | SYMBOL |
| --- | ------ |
| 1   | STORBE |
| 2   | AGND   |
| 3   | SIO_D  |
| 4   | AVDD   |
| 5   | SIO_C  |
| 6   | RESET  |
| 7   | VSYNC  |
| 8   | PWDN   |
| 9   | HREF   |
| 10  | DVDD   |
| 11  | DOVDD  |
| 12  | Y9     |
| 13  | XCLK   |
| 14  | Y8     |
| 15  | DGND   |
| 16  | Y7     |
| 17  | PCLK   |
| 18  | Y6     |
| 19  | Y2     |
| 20  | Y5     |
| 21  | Y3     |
| 22  | Y4     |
| 23  | Y1     |
| 24  | YO     |

- [[OV3660-dat]]


| pin | camera | ESP32 | extra     |
|-----|--------|-------|-----------|
| 1   | NC     |       |           |
| 2   | AGND   |       | GND       |
| 3   | SDA    | IO8   | SDA       |
| 4   | AVDD   |       | 2V8       |
| 5   | SCL    | IO9   | SCL       |
| 6   | RST    |       | pull-up   |
| 7   | VSYNC  | IO1   |           |
| 8   | PWDN   |       | pull-down |
| 9   | HSYNC  | IO2   |           |
| 10  | DVDD   |       | 1V5       |
| 11  | DOVDD  |       | 2V8       |
| 12  | Y9     | IO4   |           |
| 13  | XMCLK  | IO5   |           |
| 14  | Y8     | IO6   |           |
| 15  | GND    |       | GND       |
| 16  | Y7     | IO7   |           |
| 17  | PCLK   | IO15  | 32K_P     |
| 18  | Y6     | IO14  |           |
| 19  | Y2     | IO16  | 32K_N     |
| 20  | Y5     | IO17  |           |
| 21  | Y3     | IO18  |           |
| 22  | Y4     | IO21  |           |
| 23  | NC     |       |           |
| 24  | NC     |       |           |
| 25* | GND    |       | GND       |




## Modules

- [[SCM1008-dat]] - [[SCM1009-dat]] - [[SCM1017-dat]] - [[SCM1024-dat]] - [[SCM1030-dat]]

## Chip

- [[OV7670-dat]] - [[OV2640-dat]] - [[OV5640-dat]] - [[OV7725-dat]]

## ref

- [[sensor-Camera-dat]] - [[omnivision-dat]]

- [[SCM1009]] - [[SCM1008]] - [[SCM1030]]
