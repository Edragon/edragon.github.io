
# NRF5x-SDK-dat.md

## software 

- nrfconnect



## Bootloader

如果想要进入Bootloder，请在0.5S内短接2次RST到GND。进入Bootloder，通过USB连接电脑，此时会显示一个叫Nice!Nano的存储设备。此时你就可以拖入.uf2文件，来烧录程序。




## SDK and bootloader 


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




## ref 


- [[python-dat]]

- [[NRF5x-dat]] - [[Jlink-dat]]