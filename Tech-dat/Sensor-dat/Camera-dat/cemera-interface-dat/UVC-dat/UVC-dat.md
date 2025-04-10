
# UVC-dat

USB video V1.1 compliance (UVC)


What is the UVC protocol?

The full name of UVC is USB video class or USB video device class. It is a protocol standard jointly launched by Microsoft and several other equipment manufacturers for USB video capture devices. 

It has become one of the USBorg standards. Hardware that meets the UVC specification does not need to install any drivers and can be used normally.


## Understanding UVC Signal (USB Video Class)

### What is UVC?
UVC (**USB Video Class**) is a standard that allows USB video devices, such as webcams and capture cards, to communicate with computers without requiring additional drivers.

### Key Features
- **Plug-and-Play**: Works on Windows, macOS, and Linux without extra drivers.
- **Standardized Video Formats**: Supports MJPEG, YUV, H.264, and more.
- **Common in Webcams & Capture Cards**: Many USB cameras and HDMI-to-USB devices use UVC.
- **Bandwidth-Limited**: Resolution and frame rate depend on USB speed.

### Applications
- Video conferencing (Zoom, Skype)
- Streaming & recording (OBS, VLC)
- USB-based microscope & endoscope cameras

### Limitations
- Higher resolutions (e.g., 4K 60fps) may not be supported over USB 2.0.
- Some UVC devices may have limited control over exposure, white balance, and focus.

### Checking UVC Compatibility

On Linux, you can check if a device supports UVC with:

    lsusb | grep -i uvc



## USB

Works with USB webcams and UVC-compatible cameras.

More flexible but may have higher latency and lower performance compared to CSI.

Requires drivers if the camera isn't UVC-compliant.


## Android APPs 

USB Camera
- https://play.google.com/store/apps/details?id=com.shenyaocn.android.usbcamera&hl=en
- https://www.apkmirror.com/apk/%E6%B2%88%E5%9E%9A-shenyao-china/usb-camera/variant-%7B%22minapi_slug%22%3A%22minapi-18%22%7D/