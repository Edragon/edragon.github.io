
# RMP-driver-dat-setup.md

find out more at troubleshooting section: https://github.com/hzeller/rpi-rgb-led-matrix#troubleshooting

and how to setup the E-sel multiplexing - [[MPC1073-multiplexing-dat]]



## sound card 

```
Suggestion: to slightly improve display update, add
	isolcpus=3
at the end of /boot/cmdline.txt and reboot (see README.md)

=== snd_bcm2835: found that the Pi sound module is loaded. ===
Don't use the built-in sound of the Pi together with this lib; it is known to be
incompatible and cause trouble and hangs (you can still use external USB sound adapters).

See Troubleshooting section in README how to disable the sound module.
You can also run with --led-no-hardware-pulse to avoid the incompatibility,
but you will have more flicker.
Exiting; fix the above first or use --led-no-hardware-pulse
```

## improve display update 


> Suggestion: to slightly improve display update, add
> 	isolcpus=3
> at the end of /boot/cmdline.txt and reboot (see README.md)

nano /boot/firmware/cmdline.txt


## To disable the built-in sound card (Broadcom BCM2835 ALSA) on a Raspberry Pi 3, you can follow these steps:


sudo nano /boot/firmware/config.txt

    dtparam=audio=off

After reboot, the built-in sound card should be disabled. You can verify with:

    aplay -l


    root@raspberrypi:/home/pi/rpi-rgb-led-matrix-master# aplay -l
    **** List of PLAYBACK Hardware Devices ****
    card 0: vc4hdmi [vc4-hdmi], device 0: MAI PCM i2s-hifi-0 [MAI PCM i2s-hifi-0]
    Subdevices: 1/1
    Subdevice #0: subdevice #0

sudo nano /etc/modprobe.d/raspi-blacklist.conf

blacklist snd_bcm2835




## ref 

- [[RPI-setup-dat]]

- [[RMP-driver-dat]] - [[RPI-dat]]