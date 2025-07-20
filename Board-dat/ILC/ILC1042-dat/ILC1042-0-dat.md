
# ILC1042-0-dat


## Setup for HDMI standard 

make sure you use the latest (or recent version in 2015) version of raspbian, When the first time you use it, the dipslay may not displaying properly, please reset the resolution

Run commands Or edit file in sd card on PC (not RPI)

    sudo nano  /boot/config.txt

uncomment the following line

    hdmi_force_hotplug=1

uncomment and add the following line too, resolution is set to 800x640

    hdmi_group=2
    hdmi_mode=1
    hdmi_mode=87
    hdmi_cvt  800  480  60  6  0  0  0

## Setup for Touch Screen (Optional) 

* Touch screen control ads7846 and XPT2046
* Find the following driver here. copy it to anywhere in RPI
* run the following command to install drive

commands:

    pi@raspberrypi ~ $ tar xvf 5inch_HDMI_LCD.tar.gz
    pi@raspberrypi ~ $ cd 5inch_HDMI_LCD/
    pi@raspberrypi ~ $ sudo ./5inch_HDMI_LCD

* '''in the command the /boot/config.txt will be automatically setup'''
* Reboot and now the touch control should work. check the kernel log again

commands:

    cat /var/log/kern.log


[[File:5'' lcd touch control.png|400px]]


## The bash of 5inch_hdmi_LCD including

commands:

    sudo cp ./etc/modules /etc/modules
    sudo rm /boot/kernel.img
    sudo rm /boot/config.txt
    sudo cp ./kernel.img /boot/kernel.img
    sudo cp ./kernel7.img /boot/
    sudo cp ./config.txt /boot/config.txt
    sudo rm -rf /lib/modules
    sudo cp -rf ./modules /lib/
    sudo reboot


## Calibration

evtest
    apt-get install evtest

install xinput_calibrator and run

    DISPLAY=:0.0 xinput_calibrator

Once the xinput_calibrator is installed, go the graphic control screen, in the menu ""preference"" => choose "calibrate touchscreen"

Manually calibration: 

    nano /etc/modules

and edit x y cords:

    ads7846_device model=7846 speed=100000 cs=1 gpio_pendown=25  keep_vref_on=0 swap_xy=0 pressure_max=255 x_plate_ohms=150 x_min=176 x_max=3913 y_min=561 y_max=3947

in our case, mouse pointer is little bit up, so we set y_min=561 to 300, works better
