
# camera-SDK-dat

- [[ESP1000-dat]] - [[SCM1030-dat]]

- [[camera-dat]]

[[micropython-dat]] - [[script-based-SDK]]


## repro 

- https://github.com/alanesq/esp32cam-demo
- https://github.com/espressif/esp32-camera
- https://github.com/yoursunny/esp32cam
  - WifiCam
  - AsyncCam
  - https://github.com/emannuell/ESP32-CAM-OV2640
- https://github.com/donny681/ESP32_CAMERA_QR
- https://github.com/ArduCAM/Arduino

## OV2640 

- [[OV2640-lemariva-dat]]






### namato/micropython-ov2640 == only support SPI OV2640 camera 


- https://github.com/namato/micropython-ov2640

  git clone https://github.com/namato/micropython-ov2640
![OV2640-lemariva-dat/capture0724.jpg](OV2640-lemariva-dat/capture0724.jpg)640
  sudo ampy -p /dev/ttyUSB0 put boot.py
  sudo ampy -p /dev/ttyUSB0 put main.py
  sudo ampy -p /dev/ttyUSB0 put ov2640_constants.py
  sudo ampy -p /dev/ttyUSB0 put ov2640_hires_constants.py
  sudo ampy -p /dev/ttyUSB0 put ov2640_lores_constants.py
  sudo ampy -p /dev/ttyUSB0 put ov2640.py






Then initialize and capture still frames using code like this. The included main.py contains an example.

  import ov2640
  cam = ov2640.ov2640()
  nbytes = cam.capture_to_file("/image.jpg")

A good way to retrieve files for testing/verification is [[rshell-dat]].

  sudo rshell -p /dev/ttyUSB0
  Connecting to /dev/ttyUSB0 ...
  Welcome to rshell. Use Control-D to exit.
  /home/namato/micropython-ov2640> 
  /home/namato/micropython-ov2640> cp /image2.jpg .

This will copy the newly created image locally for viewing.



## dependency

- [[freeRTOS-dat]]


## ref 

- [[camera-dat]]