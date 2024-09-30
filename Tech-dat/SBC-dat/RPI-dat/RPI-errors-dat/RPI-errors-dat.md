
# RPI-errors-dat


### The Repository "***" does not have a Release file. unable to update

The repository 'http://raspbian.raspberrypi.org/raspbian stretch Release' does no longer have a Release file.


/etc/apt/sources.list

    deb http://raspbian.raspberrypi.org/raspbian/ stretch main contrib non-free rpi

to

    deb http://legacy.raspbian.org/raspbian/ stretch main contrib non-free rpi


- ref - https://raspberrypi.stackexchange.com/questions/143053/my-rpi-wont-update



- /etc/apt/sources.list.d/ 是存放额外软件源的目录。
- /etc/apt/sources.list 是主要的系统软件源文件。
- /etc/sources.list.d/raspi.list 是与 Raspberry Pi 相关的软件源配置文件。

not working options 

/etc/apt/sources.list.d/raspi.list

    deb http://archive.raspberrypi.org/debian/ stretch main ui
    # Uncomment line below then 'apt-get update' to enable 'apt-get source'
    deb-src http://archive.raspberrypi.org/debian/ stretch main ui

- apt autoremove 
- apt --fix-broken install



## E: Unmet dependencies. Try 'apt --fix-broken install' with no packages (or specify a solution).

