
# SPI-CMD-dat.md

- [[raspi-config-dat]] - [[RPI-HDK-dat]]

- [[lora-HDK-dat]]


## demo code 

- [[spi-cmd-1.py]]

Uses SPI (spidev)

Resets SX1278

Reads Version register (0x42) to verify communication

Does not transmit RF (safe, non-invasive)



## output 

test demo output 

    root@raspberrypi:/home/pi/RPI-SDK# python rpi-py-spi.py 
    Warning: Failed to add edge detection: Failed to add edge detection
    Note: GPIO interrupts may require running the script with sudo
    SX1278 LoRa SPI Demo Start
    SX1278 VERSION = 0x12
    SX1278 detected successfully
    LoRa mode enabled
    Waiting for DIO0 interrupt (Ctrl+C to exit)



## disable CE1 


When SPI is enabled:

Kernel configures:

GPIO8 → CE0

GPIO7 → CE1



Disable CE1 in device tree

    sudo nano /boot/config.txt

    Add: dtoverlay=spi0-1cs

    Reboot.

    This disables CE1 → GPIO7 becomes free.

    ✔ Safe to use GPIO7 manually



## ref 

- [[spi-dat]]