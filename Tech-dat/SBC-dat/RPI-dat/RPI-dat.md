
# raspberry pi dat 

- [[RPI3-dat]] - [[RPI-CM4-dat]] - [[RPI-CM4-expansion-board-dat]]

- [[RPI-zero-dat]]

- official documentation - https://www.raspberrypi.com/documentation/

## hardware 

- [[rpi-pin-dat]]

- [[raspbian-os-dat]]

- [[RPI-HDK-dat]]

### power delivery 

In summary, the Raspberry Pi 3 can deliver a maximum of 50 mA to 150 mA from the 3.3V GPIO pins, but care should be taken not to exceed the individual pin limit of 16 mA for each GPIO pin. Always ensure that the total current drawn does not exceed the recommended limits to avoid damaging the board.

### 3.3V power delivery 

All Raspberry Pi since the Model B+ can provide quite a bit more, up to 500mA to remain on the safe side, thanks to a switching regulator.

- ref - https://pinout.xyz/pinout/pin1_3v3_power/#:~:text=The%203v3%20supply%20pin%20on,regulator%20for%203.3v%20projects.


### chip 

- [[BCM2835-dat]] - [[BCM2711-dat]]

### Boards and Shields 

- [[MPC1029-dat]]

## RPI4 

- BCM2711B0: cortex-A72 

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

## I2C 

- turn on I2C functions at [[raspi-config]]




## demo code 

- [[rpi-python-dat]] - [[rpi-c-dat]]

- https://github.com/Edragon/RPI

can use commands nohup to run script in background for long term.


## repository
- general - https://github.com/Edragon/RPI
- display https://github.com/Edragon/RPI_Display
- nas - https://github.com/Edragon/RPI_nas
- matrix - https://github.com/Edragon/RPI_matrix
- RPI prog - https://github.com/Edragon/RPI-PROG
- RPI serial - https://github.com/Edragon/RPI-Serial

## Competitors 

- [[RK3588-dat]] - [[rocketchip-dat]]

