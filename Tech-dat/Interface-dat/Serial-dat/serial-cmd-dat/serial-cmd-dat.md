
# serial-cmd-dat



## CMD 

serial output 

    cat /dev/serial0
    cat /dev/ttyAMA0


## dmesg


root@raspberrypi:/home/pi/RPI-SDK# dmesg | grep -E "ttyAMA|ttyS"

    [    0.000000] Kernel command line: coherent_pool=1M 8250.nr_uarts=0 snd_bcm2835.enable_headphones=0 snd_bcm2835.enable_headphones=0 snd_bcm2835.enable_hdmi=0 snd_bcm2835.enable_hdmi=0  vc_mem.mem_base=0x3ec00000 vc_mem.mem_size=0x40000000  console=ttyS0,115200 console=tty1 root=PARTUUID=06a61d06-02 rootfstype=ext4 fsck.repair=yes rootwait quiet splash plymouth.ignore-serial-consoles cfg80211.ieee80211_regdom=GB isolcpus=3
    [    3.103080] 3f201000.serial: ttyAMA1 at MMIO 0x3f201000 (irq = 114, base_baud = 0) is a PL011 rev2
    [    3.103429] serial serial0: tty port ttyAMA1 registered



Verify mapping (recommended) == ls -l /dev/serial0

How to read UART now

    stty -F /dev/serial0 115200 cs8 -cstopb -parenb
    cat /dev/serial0


## ref 

- [[serial-cmd-dat]]