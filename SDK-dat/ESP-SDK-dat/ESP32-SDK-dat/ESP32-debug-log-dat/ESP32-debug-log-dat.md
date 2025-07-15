
# ESP32-debug-log-dat

## boot log  


    rst:0x1 (POWERON_RESET),boot:0x13 (SPI_FAST_FLASH_BOOT)
    configsip: 0, SPIWP:0xee
    clk_drv:0x00,q_drv:0x00,d_drv:0x00,cs0_drv:0x00,hd_drv:0x00,wp_drv:0x00
    mode:DIO, clock div:2
    load:0x3fff0018,len:4
    load:0x3fff001c,len:5656
    load:0x40078000,len:0
    ho 12 tail 0 room 4
    load:0x40078000,len:13844
    entry 0x40078fc4
    [0;32mI (30) boot: ESP-IDF v3.0.7 2nd stage bootloader[0m
    [0;32mI (30) boot: compile time 09:04:31[0m
    [0;32mI (30) boot: Enabling RNG early entropy source...[0m
    [0;32mI (35) boot: SPI Speed      : 40MHz[0m
    [0;32mI (39) boot: SPI Mode       : DIO[0m
    [0;32mI (43) boot: SPI Flash Size : 4MB[0m
    [0;32mI (47) boot: Partition Table:[0m
    [0;32mI (51) boot: ## Label            Usage          Type ST Offset   Length[0m
    [0;32mI (58) boot:  0 phy_init         RF data          01 01 0000f000 00001000[0m
    [0;32mI (65) boot:  1 otadata          OTA data         01 00 00010000 00002000[0m
    [0;32mI (73) boot:  2 nvs              WiFi data        01 02 00012000 0000e000[0m
    [0;32mI (80) boot:  3 at_customize     unknown          40 00 00020000 000e0000[0m
    [0;32mI (88) boot:  4 ota_0            OTA app          00 10 00100000 00180000[0m
    [0;32mI (95) boot:  5 ota_1            OTA app          00 11 00280000 00180000[0m
    [0;32mI (103) boot: End of partition table[0m
    [0;32mI (107) boot: No factory image, trying OTA 0[0m
    [0;32mI (112) esp_image: segment 0: paddr=0x00100020 vaddr=0x3f400020 size=0x20614 (132628) map[0m
    [0;32mI (167) esp_image: segment 1: paddr=0x0012063c vaddr=0x3ffc0000 size=0x02d7c ( 11644) load[0m
    [0;32mI (172) esp_image: segment 2: paddr=0x001233c0 vaddr=0x40080000 size=0x00400 (  1024) load[0m
    [0;32mI (174) esp_image: segment 3: paddr=0x001237c8 vaddr=0x40080400 size=0x0c848 ( 51272) load[0m
    [0;32mI (204) esp_image: segment 4: paddr=0x00130018 vaddr=0x400d0018 size=0xdfc80 (916608) map[0m
    [0;32mI (526) esp_image: segment 5: paddr=0x0020fca0 vaddr=0x4008cc48 size=0x02504 (  9476) load[0m
    [0;32mI (530) esp_image: segment 6: paddr=0x002121ac vaddr=0x400c0000 size=0x00064 (   100) load[0m
    [0;32mI (541) boot: Loaded app from partition at offset 0x100000[0m
    [0;32mI (541) boot: Disabling RNG early entropy source...[0m
    1.1.3
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
    I (725) wifi: mode : softAP (fc:f5:c4:06:91:55)
    I (733) wifi: mode : sta (fc:f5:c4:06:91:54) + softAP (fc:f5:c4:06:91:55)
    I (736) wifi: mode : softAP (fc:f5:c4:06:91:55)
    I (740) wifi: set country: cc=CN\0 schan=1 nchan=13 policy=1