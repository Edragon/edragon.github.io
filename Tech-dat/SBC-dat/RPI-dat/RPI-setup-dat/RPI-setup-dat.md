
# RPI-setup-dat

## login 

- default login user = pi, pass = raspberry  

- reset password - https://forums.raspberrypi.com/viewtopic.php?t=319398

![](2024-09-30-19-19-11.png)

## network 

- [[rpi-dat]] has built-in wifi 

iwconfig

    eth0      no wireless extensions.

    lo        no wireless extensions.

    wlan0     IEEE 802.11  ESSID:"111"  
            Mode:Managed  Frequency:2.472 GHz  Access Point: D0:05:E4:E2:CD:A1   
            Bit Rate=72.2 Mb/s   Tx-Power=31 dBm   
            Retry short limit:7   RTS thr:off   Fragment thr:off
            Encryption key:off
            Power Management:on
            Link Quality=65/70  Signal level=-45 dBm  
            Rx invalid nwid:0  Rx invalid crypt:0  Rx invalid frag:0
            Tx excessive retries:1  Invalid misc:0   Missed beacon:0


- iwgetid will give you the SSID




