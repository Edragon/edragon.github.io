
# camera-SDK-dat

- [[ESP1000-dat]] - [[SCM1030-dat]]

- [[camera-dat]]


- https://github.com/espressif/esp32-camera

Arduino IDE

If you are using the arduino-esp32 core in Arduino IDE, no installation is needed! You can use esp32-camera right away.


## repro 

- [[openMV-dat]]

- [[circuitpython-dat]] - better support for [[ESP32-S3-dat]] not well support for ESP32-CAM == [[SCM1030-dat]] == https://github.com/adafruit/Adafruit_CircuitPython_OV2640/issues/22


- https://github.com/alanesq/esp32cam-demo

- https://github.com/yoursunny/esp32cam
  - WifiCam
  - AsyncCam
  - https://github.com/emannuell/ESP32-CAM-OV2640
- https://github.com/donny681/ESP32_CAMERA_QR
- https://github.com/ArduCAM/Arduino

https://github.com/shariltumin/esp32-cam-micropython-2022

https://github.com/shariltumin/esp32-cam-micropython-2022/blob/main/Christmas-2023-Edition/scripts/cam_config.py


[[micropython-dat]] - [[script-based-SDK-dat]]

- [[esp-idf-dat]]

- https://github.com/Edragon/esp-idf-code



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



## repo 

- https://github.com/Edragon/Camera
- https://github.com/Edragon/esp32-camera-series
- https://github.com/Edragon/esp32-camera-screen


## ref 

- [[camera-dat]]

- [[camera-SDK]] - [[SDK]]