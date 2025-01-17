
# MPC1080-dat 

https://www.electrodragon.com/product/raspberry-pi-camera-500mp-ov5647/



## Software use:
1. Please use the latest official operating system, or raspi-config update the system
2. Start the RPi firmware camera driver, select sudo raspi-config camera and open, and then restart
3. Use the command line programs raspivid and raspistill to operate the camera to capture video clips or images.
4. Can try to test the camera command: 

command 

    raspistill -t 5000 -o szbxm.jpg

-t: (is the photo waiting time, 5000 for five seconds) -o szbxm.jpg (szbxm.jpg is a file command)

1. Captured video clips need to use mplayer player



## ref 

- [[OV5647-dat]] - [[omniVision-dat]]