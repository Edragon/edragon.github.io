
# NRF5x-SDK-dat.md




## programming guide 

1. 模块内置ARM单片机，程序下载使用J-LINK下载器 ，不能使用串口或其他任何JTAG、ISP、ICP工具。
2. 程序的烧录需要两部分完成，由于NORDIC官方提供的协议栈没有加载在程序中，因此在进行二次开发的时候，
    
    - 需要使用官方烧录工具 `nRFgo studio` 烧录协议栈，再用nRFgo studio烧录应用代码的hex；
    
    - 也可以先使用官方烧录工具nRFgo studio烧录协议栈，再用IAR或者KEIL下载。

官网工具下载网址 :http://www.nordicsemi.com/eng/Products/Bluetooth-low-energy/nRF52832/ (language)/eng-GB


- [[nRFgo-studio-dat]] 

- [[jlink-dat]]

## software 

- nrfconnect



## Bootloader

如果想要进入Bootloder，请在0.5S内短接2次RST到GND。进入Bootloder，通过USB连接电脑，此时会显示一个叫Nice!Nano的存储设备。此时你就可以拖入.uf2文件，来烧录程序。




## SDK and bootloader 



### command line 

windows: 

    adafruit-nrfutil.exe --verbose dfu serial --package feather_nrf52840_express_bootloader-0.8.0_s140_6.1.1.zip --port COMxx -b 115200 --singlebank --touch 1200

    
### arduino 

- Adafruit nRF52 by Adafruit - https://adafruit.github.io/arduino-board-index/package_adafruit_index.json


### UF2 

particle.iot 

- nrf5_sdk - https://github.com/particle-iot/nrf5_sdk

- nrfx_ppi.h 
- https://github.com/particle-iot/nrf5_sdk/blob/master/modules/nrfx/drivers/include/nrfx_ppi.h
- https://github.com/NordicSemiconductor/nrfx/blob/master/hal/nrf_ppi.h


- nrfx - https://github.com/NordicSemiconductor/nrfx

Adafruit nRF52 Bootloader - https://github.com/adafruit/Adafruit_nRF52_Bootloader

- [[UF2-dat]]


How to use
There are two pins, DFU and FRST that bootloader will check upon reset/power:

- Double Reset Reset twice within 500 ms will enter DFU with UF2 and CDC support (only works with nRF52840)
- DFU = LOW and FRST = HIGH: Enter bootloader with UF2 and CDC support
- DFU = LOW and FRST = LOW: Enter bootloader with OTA, to upgrade with a mobile application such as Nordic nrfConnect/Toolbox
- DFU = HIGH and FRST = LOW: Factory Reset mode: erase firmware application and its data
- DFU = HIGH and FRST = HIGH: Go to application code if it is present, otherwise enter DFU with UF2
- The GPREGRET register can also be set to force the bootloader can enter any of above modes (plus a CDC-only mode for Arduino). GPREGRET is set by the application before performing a soft reset.



## Nordic's nRF5x Command Line Tools 

https://www.nordicsemi.com/Software-and-Tools/Development-Tools/nRF-Command-Line-Tools




## NRFutil 

Nordic nrfutil - https://github.com/NordicSemiconductor/pc-nrfutil


DFU via serial/CDC requires adafruit-nrfutil, a modified version of Nordic nrfutil. Install python3 if it is not installed already and run this command to install adafruit-nrfutil from PyPi:

pip3 install --user adafruit-nrfutil

- [[DFU-dat]] - [[serial-dat]] - [[CDC-dat]] - [[NRF5x-sdk-dat]] - [[python-dat]]





## ref 


- [[python-dat]]

- [[NRF5x-dat]] - [[Jlink-dat]]