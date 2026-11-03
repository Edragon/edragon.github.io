
# VTX-dat


- [[VTX-analog-dat]] - [[VTX-dat]] - [[VTX-openIPC-dat]] - [[VTX-digital-dat]]



- [[OSD-dat]] - [[VTX-dat]]


- [[ESC-dat]] - [[RX-dat]] - [[VTX-dat]] [[FC-dat]] - [[AIO-dat]] - [[flight-controller-dat]] - [[crazybee-dat]] - [[whoop-dat]]

- [[VTX-dat]] - [[OpenHD-dat]] - [[ELRS-dat]] - [[CRSF-dat]] - [[ghost-dat]] - [[mavlink-dat]]


- [[FPV-build-dat]]

The Video Transmitter (VTX) is a crucial component of the FPV system, wirelessly transmitting camera images to FPV goggles.

- [[FPV-dat]]

- [[antenna-dat]] - [[antenna-lolipop-dat]]

- [[camera-FPV-dat]] 

- [[camera-analog-dat]]

- [[rc-supplier-dat]]

- [[betaflight-VTX-dat]] - [[betaflight-dat]] - [[betaflight-video-transmitter-dat]]

- [[flight-controller-dat]]

- [[VTX-dat]] - [[VRX-dat]] - [[antenna-FPV-dat]]

- [[VTX-analog-protocols-dat]]






## maker

- [[TX800-dat]]

digital camera + VTX integrated alone system ? 

- [[camera-digital-dat]]

- [[DJI-dat]] - [[DJI-air-unit-dat]] - [[DJI-O4-dat]] == 100 usd - [[DJI-O3-dat]] 

- [[runCAM-dat]] - [[caddx-dat]]

- [[opensource-dat]] - [[openIPC-dat]] ?? - [[IMX307-dat]] - [[VTX-dat]]

- [[openVTX-dat]]



## other info 

- [[fiber-analog-video-dat]]

- [[video-transmission-dat]]

- [[goggles-dat]]



## FAQ 

### Running a 1 W Analog VTX for Extended Periods

1. **Heat**
- 1 W VTX produces significant heat.
- On tiny drones like the Mobula8, heat can **damage the VTX, FC, or battery** if there’s poor airflow.
- Risk increases in warm indoor environments.

2. **Battery Drain**
- 1 W output draws **more current**, reducing flight time significantly.
- Tiny cinewhoops may overheat their small LiPo packs if flown at full power for long periods.

3. **Legal Limits**
- Many regions **restrict 5.8 GHz analog power** (often max 25–600 mW).
- Flying 1 W indoors or near populated areas could **violate regulations**.

4. **Interference**
- High-power VTX can **interfere with nearby electronics** and even your own control link.
- On tiny drones, the ELRS RX is very close to the VTX, so interference risk is higher.

5. **Practical Recommendation**
- For **indoor flying**: 25–100 mW is sufficient.
- For **small outdoor fields**: 200–400 mW is usually enough.
- Only use 1 W for **long-range outdoor FPV** with proper cooling and larger drones.

### ✅ Summary
- Running 1 W for hours is **possible**, but not recommended on micro drones due to **heat, battery drain, and interference risks**.  
- Stick to lower VTX power for safe and reliable indoor/outdoor use.






## what is the VTX in FPV?

- VTX = video transmitter, the device that transmits the video signal from the drone to the goggles or monitor.
- AIO = all in one, a flight controller that integrates multiple components into a single unit, including the flight controller, ESC (electronic speed controller), and sometimes the VTX.
- smart audio = a feature that allows you to control the VTX settings (such as frequency and power) from the flight controller or goggles, without needing to access the VTX directly.
- IRC Tramp = a type of smart audio protocol used by some VTXs, allowing for remote control of the VTX settings.

- TBS UNIFY PRO 32 HV V2 = a high-voltage version of the TBS UNIFY PRO 32 VTX, which supports higher power output and is designed for use with high-voltage battery systems.







## VTX build 

refer to - [[VTX-analog-dat]]



## ref 

- [[VTX-dat]] - [[sensor-Camera-dat]] - [[wireless-camera-dat]]

- [[FPV-dat]]

- [[VTX]]