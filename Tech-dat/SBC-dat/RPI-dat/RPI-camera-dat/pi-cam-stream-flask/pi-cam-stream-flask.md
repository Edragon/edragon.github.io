
# pi-camera-stream-flask

## install dependencies

    sudo apt-get update

    sudo apt-get upgrade

    sudo apt-get install libatlas-base-dev

    sudo apt-get install libjasper-dev

    sudo apt-get install libqtgui4

    sudo apt-get install libqt4-test

    sudo apt-get install libhdf5-dev

    sudo pip3 install Flask

    sudo pip3 install numpy

    sudo pip3 install opencv-contrib-python

    sudo pip3 install imutils

    sudo pip3 install opencv-python


## install python project code 

Open terminal and clone the Camera Stream repo:

    cd /home/pi git clone https://github.com/EbenKouao/pi-camera-stream-flask.git

You can start the Flask Camera Stream via with the following command:

    sudo python3 /home/pi/pi-camera-stream-flask/main.py


## setup auto boot 

A good idea is to make the camera stream auto-start at bootup of your pi. You will now not need to re-run the script every time you want to create the stream. You can do this by going editing the /etc/profile to:

    sudo nano /etc/profile

Go to the end of the and add the following (from above):

    sudo python3 /home/pi/pi-camera-stream-flask/main.py

This would cause the following terminal command to auto-start each time the Raspberry Pi boots up. This, in effect, creates a headless setup, which would be accessed via SSH.


## project code 

- https://github.com/EbenKouao/pi-camera-stream-flask
