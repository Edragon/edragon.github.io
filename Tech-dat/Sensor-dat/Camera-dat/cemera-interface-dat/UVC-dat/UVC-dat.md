
# UVC-dat

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