
# ESP32-boot-log-dat.md

## initiate log 

    rst:0x1 (POWERON_RESET),boot:0x13 (SPI_FAST_FLASH_BOOT)
    configsip: 0, SPIWP:0xee
    clk_drv:0x00,q_drv:0x00,d_drv:0x00,cs0_drv:0x00,hd_drv:0x00,wp_drv:0x00
    mode:DIO, clock div:1
    load:0x3fff0030,len:4832
    load:0x40078000,len:16460
    load:0x40080400,len:4
    load:0x40080404,len:3504
    entry 0x400805cc

> **rst:0x1**: This indicates the reset reason was a power-on reset.

> **boot:0x13**: This indicates the boot mode is SPI fast flash boot, meaning it's booting from external flash over SPI.

configsip: 0, SPIWP:0xee

> SPI flash configuration, including the write protect pin.

clk_drv:0x00,q_drv:0x00,d_drv:0x00,cs0_drv:0x00,hd_drv:0x00,wp_drv:0x00

> These are drive strength settings for various SPI flash pins (clock, data, etc.).


mode:DIO, clock div:1

> mode:DIO: Flash is operating in Dual I/O mode.
> clock div:1: Clock divider is set to 1 (max speed).


load:0x3fff0030,len:4832
load:0x40078000,len:16460
load:0x40080400,len:4
load:0x40080404,len:3504
entry 0x400805cc

> These lines show the loading of firmware segments into memory.
> entry 0x400805cc is the starting address of the user code.


## firmware log 

    I (662) wifi: wifi firmware version: 703e53b
    I (663) wifi: config NVS flash: enabled
    I (663) wifi: config nano formating: disabled
    I (673) wifi: Init dynamic tx buffer num: 32
    I (673) wifi: Init data frame dynamic rx buffer num: 32
    I (673) wifi: Init management frame dynamic rx buffer num: 32
    I (679) wifi: wifi driver task: 3ffdee34, prio:23, stack:3584
    I (684) wifi: Init static rx buffer num: 10
    I (687) wifi: Init dynamic rx buffer num: 32
    I (692) wifi: wifi power manager task: 0x3ffe369c prio: 21 stack: 2560
    I (726) wifi: mode : softAP (7c:9e:bd:5f:66:11)
    I (734) wifi: mode : sta (7c:9e:bd:5f:66:10) + softAP (7c:9e:bd:5f:66:11)
    I (738) wifi: mode : softAP (7c:9e:bd:5f:66:11)
    I (741) wifi: set country: cc=CN\0 schan=1 nchan=13 policy=1



## wait for download 

    rst:0x1 (POWERON_RESET),boot:0x3 (DOWNLOAD_BOOT(UART0/UART1/SDIO_REI_REO_V2))
    waiting for download


## ref 

- [[ESP32-dat]]