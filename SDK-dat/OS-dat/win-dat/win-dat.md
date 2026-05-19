

# win-dat

## network scan 

install [[nmap-dat]]

https://nmap.org/download.html#windows

    PS C:\Users\Administrator> nmap -p 22 192.168.141.0/24
    Starting Nmap 7.98 ( https://nmap.org ) at 2026-05-14 15:19 +0800
    Nmap scan report for 192.168.141.98
    Host is up (0.0089s latency).

    PORT   STATE  SERVICE
    22/tcp closed ssh
    MAC Address: 32:97:37:31:8B:2B (Unknown)

    Nmap scan report for 192.168.141.142
    Host is up (0.010s latency).

    PORT   STATE  SERVICE
    22/tcp closed ssh
    MAC Address: 9C:47:82:E9:EA:56 (TP-Link Technologies)

    Nmap scan report for 192.168.141.250
    Host is up (0.15s latency).

    PORT   STATE  SERVICE
    22/tcp closed ssh
    MAC Address: D6:A1:27:1D:34:0B (Unknown)

    Nmap scan report for 192.168.141.106
    Host is up (0.0010s latency).

    PORT   STATE  SERVICE
    22/tcp closed ssh

    Nmap done: 256 IP addresses (4 hosts up) scanned in 13.16 seconds


## set the permanent environment variables The Command Line Way (setx)

The setx command is the standard way to set permanent variables directly from the Command Prompt.

For the Current User:
setx VAR_NAME "your_value"

For the Entire System (Requires Admin):
setx VAR_NAME "your_value" /M

Note: When you use setx, the variable is saved to the Registry, but it will not appear in the current CMD window you are using. You must close and reopen the Command Prompt to see the change.



set variable - first

    setx avrdude "C:\Users\Administrator\AppData\Local\Arduino15\packages\arduino\tools\avrdude\6.3.0-arduino17\bin\avrdude.exe" /M
    setx avrdude_conf "C:\Users\Administrator\AppData\Local\Arduino15\packages\arduino\tools\avrdude\6.3.0-arduino17\etc\avrdude.conf" /M

then run 

    %avrdude% -C %avrdude_conf% -v -p m328p -c avrispmkii -P usb -D -Uflash:w:optiboot_lgt8f328p.hex:i

## cancel setx 


The "Empty String" Trick (CMD)

You can't truly delete a variable with setx, but you can strip it of its value. This leaves the variable name in the registry but makes it empty.

    setx VAR_NAME ""



## ref 

- [[OS-dat]] - [[linux-dat]]