
# RPI-SDK-dat

- [[RPI-OS-dat]]

- [[python-dat]] 

- [[rpi-python-dat]] - [[rpi-c-dat]]

- [[RPI-setup-dat]] - [[RPI-errors-dat]]

- [[raspi-config-dat]]

- [[RPI-tools-dat]]

## Usage and Software 

copy file to /boot/myfiles 

    To get files across you put the SD into your PC and make a folder (lets say myfiles) on the SD card for your files and put your files in there.

    Then, when you plug the SD card back into your RPi, these files are available in a folder called /boot/myfiles.

    You can then copy them to anywhere you need on your RPi

or use a USB driver 


You can log in using the default username: “pi” and the default password: “raspberry”.

For raspberry pi OS: raspi-config config "administrator" password to "pi"

    root@2W:/boot# lsblk

    NAME        MAJ:MIN RM  SIZE RO TYPE MOUNTPOINTS
    sda           8:0    1 14.8G  0 disk 
    └─sda1        8:1    1 14.8G  0 part /media/administrator/_¼Ӿ_
    mmcblk0     179:0    0   15G  0 disk 
    ├─mmcblk0p1 179:1    0  512M  0 part /boot/firmware
    └─mmcblk0p2 179:2    0 14.5G  0 part /

    cd /media/administrator/_¼Ӿ_



## tips 

can use commands nohup to run script in background for long term.



## repository
- general - https://github.com/Edragon/RPI
- display - https://github.com/Edragon/RPI_Display
- display 2 - https://github.com/Edragon/Display-E-paper
- nas - https://github.com/Edragon/RPI_nas
- matrix - https://github.com/Edragon/RPI_matrix
- RPI prog - https://github.com/Edragon/RPI-PROG
- RPI serial - https://github.com/Edragon/RPI-Serial


## ref 

- [[RPI-dat]]