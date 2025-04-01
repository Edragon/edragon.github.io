
# camera-interface-dat

- [[SCCB-dat]] - [[CSI-dat]] - [[UVC-dat]] - [[analog-video-dat]] - [[HDMI-dat]]

### Standard Camera Output that Can Be Read by Android

- [[UVC-dat]] - [[CSI-dat]] - [[HDMI-dat]]

1. **USB Video Class (UVC):**  
   A standard for transmitting video over USB connections. Many external webcams and cameras use this standard, which Android devices can read directly if the appropriate app or support is in place.

2. **MIPI-CSI (Mobile Industry Processor Interface - Camera Serial Interface):**  
   A standard for connecting cameras to mobile processors. Android devices use this for built-in cameras, and it requires a specific interface and drivers.

3. **RTSP/HTTP Stream (for IP cameras):**  
   If using an IP camera or a camera connected to a network, Android devices can receive video through a network stream (RTSP/HTTP). Specific apps are needed to view the stream.

4. **HDMI Output:**  
   Some Android devices with HDMI-in capabilities can receive video signals via HDMI (usually using a USB-C to HDMI adapter or specific equipment).

5. **Camera API (for internal phone cameras):**  
   Android provides its own camera API (Camera2 API) for controlling and processing video feeds from the internal cameras.

For external camera integration, using a UVC-compatible device or an IP camera with a network stream would be the most straightforward ways to transmit video data that Android can read.



## ref 

- [[camera-interface]] - [[camera]]