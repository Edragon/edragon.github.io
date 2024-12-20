
# I2S-dat 

An I2S (Interactive Two-Way Serial) interface is a type of serial communication protocol used for transferring data between devices. 

It is commonly used in computer networking, as well as in audio processing and digital electronics. 

I2S interfaces typically use a combination of fast and slow data transfer rates to make efficient use of communication bandwidth and minimize noise and errors. 

One of the key features of I2S interfaces is their ability to support full-duplex communication, which allows for the simultaneous transfer of data in both directions. 

This makes I2S a popular choice for high-speed data transfer applications.

## Pin 

| Name | also Name    | func                               | RPI GPIO | RPI pin |
| ---- | ------------ | ---------------------------------- | -------- | ------- |
| BCLK |              | Bit clock line                     | G18      | PIN 12  |
| WS   | LRCK         | Word clock line                    | G19      | PIN 35  |
| SD   | SDIN / SDOUT | At least one multiplexed data line | G21      | PIN 40  |

## RPI I2S check 

Open the Raspberry Pi configuration tool:

    sudo raspi-config

Navigate to Interfacing Options → I2S and enable it.

Check if the module is loaded:

    lsmod | grep snd

Look for snd_soc_bcm2835_i2s.

Edit /boot/config.txt:

Add the following lines to enable I2S and configure the DAC:

    dtparam=i2s=on
    dtoverlay=hifiberry-dac

Save and reboot:

    sudo reboot

Verify Device Tree Overlay:

After reboot, check for the overlay:

    dmesg | grep -i i2s

List audio devices:

    aplay -l




## RPI ref 

- https://www.raspberrypi-spy.co.uk/2012/06/simple-guide-to-the-rpi-gpio-header-and-pins/#prettyPhoto
- https://docs.microsoft.com/en-us/windows/iot-core/learn-about-hardware/pinmappings/pinmappingsrpi






## Solution 

- [[WM8960-dat]]

- [[PCM5102-dat]] - [[AMP1006-dat]]

- [[UDA1334-dat]] - [[AMP1013-dat]]

- [[PCM5122-dat]] - [[MPC1083-dat]] - [[I2S-dat]]

- [[bt-audio-dat]] - [[DAC-dat]] - [[ADC-dat]]

- [[ES9023-dat]] - [[MPC1111-dat]]

- [[PCM1808-dat]]

## ref 

https://en.wikipedia.org/wiki/I%C2%B2S

