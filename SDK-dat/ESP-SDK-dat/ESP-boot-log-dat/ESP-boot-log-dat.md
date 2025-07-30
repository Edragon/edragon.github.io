
# ESP32-boot-log-dat.md

## IDF boot 

    ESP-ROM:esp32s3-20210327
    Build:Mar 27 2021
    rst:0x1 (POWERON),boot:0x29 (SPI_FAST_FLASH_BOOT)
    SPIWP:0xee
    mode:DIO, clock div:1
    load:0x3fce2820,len:0x159c
    load:0x403c8700,len:0xd24
    load:0x403cb700,len:0x2f48
    entry 0x403c8924
    I (24) boot: ESP-IDF v5.5 2nd stage bootloader
    I (25) boot: compile time Jul 30 2025 17:47:22
    I (25) boot: Multicore bootloader
    I (25) boot: chip revision: v0.2
    I (28) boot: efuse block revision: v1.3
    I (31) boot.esp32s3: Boot SPI Speed : 80MHz
    I (35) boot.esp32s3: SPI Mode       : DIO
    I (39) boot.esp32s3: SPI Flash Size : 2MB
    I (43) boot: Enabling RNG early entropy source...
    I (47) boot: Partition Table:
    I (50) boot: ## Label            Usage          Type ST Offset   Length
    I (56) boot:  0 nvs              WiFi data        01 02 00009000 00006000
    I (62) boot:  1 phy_init         RF data          01 01 0000f000 00001000
    I (69) boot:  2 factory          factory app      00 00 00010000 00100000
    I (76) boot: End of partition table
    I (79) esp_image: segment 0: paddr=00010020 vaddr=3c020020 size=0a550h ( 42320) map
    I (94) esp_image: segment 1: paddr=0001a578 vaddr=3fc92700 size=02ad8h ( 10968) load
    I (96) esp_image: segment 2: paddr=0001d058 vaddr=40374000 size=02fc0h ( 12224) load
    I (104) esp_image: segment 3: paddr=00020020 vaddr=42000020 size=184b4h ( 99508) map
    I (126) esp_image: segment 4: paddr=000384dc vaddr=40376fc0 size=0b638h ( 46648) load
    I (137) esp_image: segment 5: paddr=00043b1c vaddr=600fe000 size=00020h (    32) load
    I (143) boot: Loaded app from partition at offset 0x10000
    I (143) boot: Disabling RNG early entropy source...
    I (154) cpu_start: Multicore app
    I (163) cpu_start: Pro cpu start user code
    I (163) cpu_start: cpu freq: 160000000 Hz
    I (163) app_init: Application information:
    I (164) app_init: Project name:     blink2-build
    I (168) app_init: App version:      1
    I (171) app_init: Compile time:     Jul 30 2025 17:45:23
    I (176) app_init: ELF file SHA256:  775b8be9f...
    I (181) app_init: ESP-IDF:          v5.5
    I (184) efuse_init: Min chip rev:     v0.0
    I (188) efuse_init: Max chip rev:     v0.99 
    I (192) efuse_init: Chip rev:         v0.2
    I (196) heap_init: Initializing. RAM available for dynamic allocation:
    I (202) heap_init: At 3FC95AC8 len 00053C48 (335 KiB): RAM
    I (207) heap_init: At 3FCE9710 len 00005724 (21 KiB): RAM
    I (212) heap_init: At 3FCF0000 len 00008000 (32 KiB): DRAM
    I (218) heap_init: At 600FE020 len 00001FC8 (7 KiB): RTCRAM
    I (224) spi_flash: detected chip: generic
    I (227) spi_flash: flash io: dio
    W (230) spi_flash: Detected size(16384k) larger than the size in the binary image header(2048k). Using the size in the binary image header.
    I (242) sleep_gpio: Configure to isolate all GPIO pins in sleep state
    I (248) sleep_gpio: Enable automatic switching of GPIO sleep configuration
    I (255) main_task: Started on CPU0
    I (275) main_task: Calling app_main()


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