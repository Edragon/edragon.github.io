



# SC5239S-dat

- [[sensor-camera-chip-dat]] == [[SC5239S-dat]] - [[xiongmai-dat]]


SC5239S is an OEM/Xiongmai (XM) sensor designation used on IP security camera modules, most commonly paired with Goke SoCs (such as GK7205V210, GK7205V300, or GK7605V100). While often marketed as a 5MP (up to 2880×1616) or 4MP sensor on surveillance boards, no public SmartSens datasheet is listed directly under the "SC5239S" name, and OpenIPC notes that boards sold under this label can vary or map to related sensors (such as sc223a) depending on the module.

Key Details & Usage Notes

- • Typical Hardware Pairing: Found on 38×38 mm XM/Xmeye-style IP camera PCBs alongside Goke processors (e.g., GK7205V210/V300), supporting H.264/H.265, RTSP, and ONVIF on compatible firmware.
- • Resolution & Low Light: Module spec sheets (such as Xiongmai's IVG-G5A) list a 1/2.8" low-light CMOS sensor supporting main-stream resolutions up to 2880×1616 at 25 fps (as well as 2560×1440, 2304×1296, and 1080p).
- • Firmware & Compatibility: According to OpenIPC Documentation and OpenIPC, verifying the exact underlying sensor ID and SoC on your board is important before flashing custom firmware or troubleshooting frame rates.


- [[H.265-dat]] - [[RTSP-dat]] - [[ONVIF-dat]] - [[video-dat]] - [[video-streaming-dat]] - [[sensor-camera-dat]]



## ref 