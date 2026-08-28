

# FPV-build-dat



- [[FPV-build-dat]] - [[FPV-frame-dat]] - [[flight-controller-dat]] - [[motor-FPV-dat]] - [[propeller-FPV-dat]] - [[camera-FPV-dat]]

- [[FPV-build-dat]] - [[battery-FPV-dat]]

- [[VTX-dat]] - [[VRX-dat]] - [[video-dat]] - [[goggles-dat]]


## build 5in

| part                      | build 1                          |
| ------------------------- | -------------------------------- |
| [[FPV-frame-dat]]         | MAK5机架                         |
| [[flight-controller-dat]] | 飞拓F405V3 飞控                  |
| [[ESC-dat]]               | 飞拓60A四合一电调                |
| [[VTX-dat]]               | FOXEER4代天线津航VTX30-800mw图传 |
| [[motor-FPV-dat]]         | 电机 2205-2450KV                 |
| [[propeller-FPV-dat]]     | 乾丰51466*2对                    |
| [[camera-FPV-dat]]        | Caddx平头哥二代1                 |
| [[battery-FPV-dat]]       | 格氏4S1300MAH 120C/3.0           |
| total                     | 971                              |




## build common by size 

| setup                     | [[FPV-frame-dat]] | [[flight-controller-dat]] | [[motor-FPV-dat]] | [[propeller-FPV-dat]] | [[camera-FPV-dat]] |
| ------------------------- | ----------------- | ------------------------- | ----------------- | --------------------- | ------------------ |
| 2'' [[mobula8-dat]] specs | default           | [[X12-dat]]               | [[EX1103-dat]]    | 乾丰2023三叶          | Caddx ANT 1200TVL  |
| 2'' [[mobula8-dat]] price | 22.5 RMB          | 383 RMB                   | 54 RMB            | 1.6 RMB               | 81 RMB             |
| 5'' specs                 | common frame      | -                         | -                 | -                     | -                  |
| 5'' price                 | 250 RMB           | 400-600 RMB               | -                 | -                     | -                  |


## build common

| indx | parts                              | cost RMB | cost USD/7      | eg. common select |
| ---- | ---------------------------------- | -------- | --------------- | ----------------- |
| 1    | [[FPV-frame-dat]]                  | 22.5     | 3               | [[mobula8-dat]]   |
| 2    | [[FC-AIO-dat]] or [[FC-stack-dat]] | 383      | 55              | [[X12-dat]]       |
| 3    | [[motor-FPV-dat]] x4               | 54       | 8 x4 = 32       | [[EX1103-dat]]    |
| 4    | [[propeller-FPV-dat]] x4           | 1.6      | 0.23  x4 = 0.92 | 乾丰2023三叶      |
| 5    | [[camera-FPV-dat]]                 | 81       | 11.6            | Caddx ANT 1200TVL |

total USD == 100 for [[FC-AIO-dat]] or 120+ for [[FC-stack-dat]]




### extra 

- swappable [[battery-dat]]

- accessories == PCB vibration absorber //  [[cable-XT-dat]] cable // [[camera-FPV-dat]] canopy // [[screw-dat]]

- [[sensor-dat]] - [[FPV-build-dat]] - [[location-FPV-dat]] - [[location-dat]]

- remote - [[goggles-dat]]


## build == [[mobula8-dat]] 

| indx | parts                     | cost RMB | cost USD/7      | eg. common select |
| ---- | ------------------------- | -------- | --------------- | ----------------- |
| 1    | [[FPV-frame-dat]]         | 22.5     | 3               | [[mobula8-dat]]   |
| 2    | [[flight-controller-dat]] | 383      | 55              | [[X12-dat]]       |
| 3    | [[motor-FPV-dat]] x4      | 54       | 8 x4 = 32       | [[EX1103-dat]]    |
| 4    | [[propeller-dat]] x4      | 1.6      | 0.23  x4 = 0.92 | 乾丰2023三叶      |
| 5    | [[VTX-dat]]               | 81       | 11.6            | Caddx ANT 1200TVL |
|      | PCB vibration absorber    | 0        | 0               |                   |
|      | [[XT30-dat]] cable        | 4        | 0.6             |                   |
|      | [[battery-dat]]  x2       | 55       | 7.9 x2 = 15.8   |                   |
|      | [[mobula8-dat]]           |          | 100             |                   |


- accessories == PCB vibration absorber //  [[cable-XT-dat]] cable    

- [[CONN-dat]]






## parts of the FPV drones


- [[flight-controller-dat]]

- [[ESC-dat]]

- **Motors**: Provide the thrust needed for flight. Brushless motors are commonly used in FPV drones due to their efficiency and power.

- **Propellers**: Generate lift by spinning rapidly. The size and pitch of the propellers can significantly affect the drone's performance and flight characteristics.

- [[SCU1059-dat]] - [[propeller-dat]]

- **Camera**: Captures real-time video for FPV flying. FPV cameras are designed to provide low-latency video transmission to the pilot's goggles or screen.

- [[VTX-dat]]: Video Transmitters are commonly referred to as VTX units. They are responsible for transmitting the video signal from the camera to the pilot's goggles or screen. VTX units come in various power levels and frequencies, allowing pilots to choose the best option for their flying environment.
- **Antenna**: Enhances the signal strength and range of the VTX. Different antenna types (e.g., dipole, patch, circular polarized) can be used to optimize performance.

- **ExpressLRS**: A long-range radio control link for FPV drones, known for its low latency and high refresh rates. It is an open-source project that competes with other systems like Crossfire and ELRS.

  - [[ELRS-dat]]

- **Goggles**: Wearable displays that allow pilots to see the live video feed from the drone's camera. They often include features like head tracking and DVR (Digital Video Recorder) capabilities.


## ref 

- [[FPV]] - [[FPV-build]]