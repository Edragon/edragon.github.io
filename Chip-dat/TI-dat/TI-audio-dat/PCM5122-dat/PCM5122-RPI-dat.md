
# PCM5122-RPI-dat.md

1) Modify the config.txt on termianl. Open the config.txt in system. 

    sudo nano /boot/config.txt
    sudo nano /boot/firmware/config.txt

Append the following lines to the end of the file,enable the audio module.Draw attention to theformat , Otherwise it doesn't work. press "ctrl+o" and press "Enter" to save the file. Reboot thesystem. 

    dtoverlay=allo-boss-dac-pcm512x-audio

![](2024-12-20-18-19-02.png)

and not yet tested: 

    dtoverlay=i2s-mmap
    dtoverlay=hifiberry-dacplus

2)Check the DAC module

Type in the commands that are shown below. You can see the BossDAC, the 3 is the dac devicenumber. 

    aplay -l
    cat /proc/asound/cards

![](2024-12-20-18-19-39.png)



## after installation 

command will read UU instead 

    i2cdetect -y 1

        0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
    00:                         -- -- -- -- -- -- -- -- 
    10: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
    20: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
    30: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
    40: -- -- -- -- -- -- -- -- -- -- -- -- -- UU -- -- 
    50: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
    60: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
    70: -- -- -- -- -- -- -- --                        

unset dtoverlay=allo-boss-dac-pcm512x-audio will return to 0x4d: 

        0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
    00:                         -- -- -- -- -- -- -- -- 
    10: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
    20: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
    30: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
    40: -- -- -- -- -- -- -- -- -- -- -- -- -- 4d -- -- 
    50: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
    60: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
    70: -- -- -- -- -- -- -- --   