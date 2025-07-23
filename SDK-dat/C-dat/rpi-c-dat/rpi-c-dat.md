
# rpi-c-dat

    chmod +x 2_5449615149826598388

    (.venv) root@raspberrypi:/home/pi# ./2_5449615149826598388

    ./2_5449615149826598388: error while loading shared libraries: libwiringPi.so: cannot open shared object file: No such file or directory


## library 

- [[WiringPi-dat]]


## compile 

compile 

    g++ rsr.cpp -o rsr2 -lwiringPi


## errors 

wrong 32bit version installed: 

    gpio: error while loading shared libraries: libcrypt.so.1: cannot open shared object file: No such file or directory


## ref 

- [[rpi-dat]]



