
# ESP32-debug-log-dat




## partitions error 

    ESP-ROM:esp32c3-api1-20210207
    Build:Feb  7 2021
    rst:0x3 (RTC_SW_SYS_RST),boot:0xd (SPI_FAST_FLASH_BOOT)
    Saved PC:0x40048b82
    SPIWP:0xee
    mode:DIO, clock div:1
    load:0x3fcd5820,len:0x1174
    load:0x403cbf10,len:0xb34
    load:0x403ce710,len:0x2fb4
    entry 0x403cbf10
    E (35) flash_parts: partition 3 invalid - offset 0x340000 size 0x330000 exceeds flash chip size 0x400000
    E (35) boot: Failed to verify partition table
    E (37) boot: load partition table error!


That boot log is not a sketch bug. It means the firmware you flashed contains a partition table that doesn�t fit your chip�s flash size.

Key line:

- exceeds flash chip size 0x400000 ? your module has 4MB flash
- but the partition table expects partitions going past 4MB (offset 0x340000 + size 0x330000).

Fix (Arduino core 3.x / Arduino IDE)

- Select the correct board (you�re booting as ESP32-C3).
- In Tools ? Flash Size, set it to 4MB (or the actual size if different).
- In Tools ? Partition Scheme, pick a layout that fits 4MB (examples: �Default 4MB�, �No OTA (2MB APP/2MB SPIFFS)�, etc.).
- Avoid any scheme intended for 8MB/16MB.




## GPIO_PIN mask error left shift count >= width of type

How to fix:
Change this line in led.c:

    led_pin_config.pin_bit_mask = 1<<LED_PIN;

to:

    led_pin_config.pin_bit_mask = 1ULL << LED_PIN;

log: 

    E (275) gpio: GPIO_PIN mask error 
    I (275) main_task: Returned from app_main()

warning: 

    E:/Git-category/Git-Arduino/esp-idf-code/blink/blink2-build/main/led.c: In function 'led_init':
    E:/Git-category/Git-Arduino/esp-idf-code/blink/blink2-build/main/led.c:8:36: warning: left shift count >= width of type [-Wshift-count-overflow]
        8 |     led_pin_config.pin_bit_mask = 1<<LED_PIN;
        |                                    ^~


            
## serial read 

串坣接收有一个buffer，毝次read其实是从buffer中读坖数杮，并丝是直接从串坣读入的

## Interrupt Control Issues Troubleshooting

**Arduino examples wiki link:** https://docs.espressif.com/projects/arduino-esp32/en/latest/libraries.html

### Common Issues and Solutions:

1. **Interrupt functions need the `ARDUINO_ISR_ATTR` macro**
2. **Use serial debugging**
3. **Program crashes due to incorrect flash size settings**


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



# ESP32-compiler-error-dat


## common errors 


better store file in [[sd-dat]] - [[memory-dat]]

This error E (1183) intr_alloc: No free interrupt inputs indicates a hardware interrupt conflict between the I2S audio driver and the camera driver on your ESP32. Both peripherals are competing for the same system resources.

To resolve this, you need to modify the interrupt allocation flags when initializing the I2S driver. This ensures it doesn't conflict with the interrupt required by the camera.

Locate the i2s_config_t structure in your setup() function.
Change the value of .intr_alloc_flags from 0 to ESP_INTR_FLAG_LEVEL1.


    E (1183) intr_alloc: No free interrupt inputs for I2S0 interrupt (flags 0x40E)
    E (1183) cam_hal: cam_config(407): cam intr alloc failed
    E (1184) camera: Camera config failed with error 0xffffffff
    Camera init failed with error 0xffffffff





## watchdog 

    rst:0x1 (POWERON_RESET),boot:0x13 (SPI_FAST_FLASH_BOOT)
    configsip: 0, SPIWP:0xee
    clk_drv:0x00,q_drv:0x00,d_drv:0x00,cs0_drv:0x00,hd_drv:0x00,wp_drv:0x00
    mode:DIO, clock div:1
    load:0x3fff0030,len:4888
    load:0x40078000,len:16456
    load:0x40080400,len:4
    load:0x40080404,len:3476
    entry 0x400805b4
    ESP32-CAM Simple Image Capture to SPIFFS
    E (6) SPIFFS: mount failed, -10025
    E (122) task_wdt: esp_task_wdt_reset(705): task not found
    E (122) task_wdt: esp_task_wdt_reset(705): task not found
    E (128) task_wdt: esp_task_wdt_reset(705): task not found
    E (157) task_wdt: esp_task_wdt_reset(705): task not found
    E (158) task_wdt: esp_task_wdt_reset(705): task not found
    E (158) task_wdt: esp_task_wdt_reset(705): task not found
    E (185) task_wdt: esp_task_wdt_reset(705): task not found
    E (186) task_wdt: esp_task_wdt_reset(705): task not found


## 4 

I see the issue! There's a conflict between the camera and I2S driver trying to use the same interrupt resources. The ESP32-CAM without PSRAM has limited interrupt resources, and both the camera and I2S are trying to allocate interrupts.

    E (2198) intr_alloc: No free interrupt inputs for I2S0 interrupt (flags 0x40E)
    E (2199) cam_hal: cam_config(407): cam intr alloc failed
    E (2200) camera: Camera config failed with error 0xffffffff
    Camera init failed with error 0xffffffff
    === System Status ===
    Free heap: 271820 bytes
    Camera task stack high water mark: 5356
    Display task stack high water mark: 5356
    Sensor task stack high water mark: 5356
    Audio task stack high water mark: 5356
    WiFi status: Disconnected



## 3 

fix ==   Serial.printf("Free heap after setup: %u bytes\n", ESP.getFreeHeap());

    E:\Git-category\Git-Arduino\Arduino-ESP32\BSP\ESP\ESP1000-ESP32-tori\rtos-cam-web-2\rtos-cam-web-2.ino: In function 'void loop()':
    E:\Git-category\Git-Arduino\Arduino-ESP32\BSP\ESP\ESP1000-ESP32-tori\rtos-cam-web-2\rtos-cam-web-2.ino:479:19: warning: format '%d' expects argument of type 'int', but argument 3 has type 'uint32_t' {aka 'long unsigned int'} [-Wformat=]
    479 |     Serial.printf("Free heap: %d bytes\n", ESP.getFreeHeap());
        |                   ^~~~~~~~~~~~~~~~~~~~~~~  ~~~~~~~~~~~~~~~~~
        |                                                           |
        |                                                           uint32_t {aka long unsigned int}

## 2 

    "C:\\Users\\Administrator\\AppData\\Local\\Arduino15\\packages\\esp32\\tools\\esp-x32\\2411/bin/xtensa-esp32-elf-g++" -MMD -c "@C:\\Users\\Administrator\\AppData\\Local\\Arduino15\\packages\\esp32\\tools\\esp32-arduino-libs\\idf-release_v5.4-858a988d-v1\\esp32/flags/cpp_flags" -Wall -Wextra -Os -Werror=return-type -DF_CPU=240000000L -DARDUINO=10607 -DARDUINO_ESP32_DEV -DARDUINO_ARCH_ESP32 "-DARDUINO_BOARD=\"ESP32_DEV\"" "-DARDUINO_VARIANT=\"esp32\"" -DARDUINO_PARTITION_default "-DARDUINO_HOST_OS=\"windows\"" "-DARDUINO_FQBN=\"esp32:esp32:esp32:UploadSpeed=921600,CPUFreq=240,FlashFreq=80,FlashMode=qio,FlashSize=4M,PartitionScheme=default,DebugLevel=none,PSRAM=disabled,LoopCore=1,EventsCore=0,EraseFlash=all,JTAGAdapter=default,ZigbeeMode=default\"" -DESP32=ESP32 -DCORE_DEBUG_LEVEL=0 -DARDUINO_RUNNING_CORE=1 -DARDUINO_EVENT_RUNNING_CORE=0 -DARDUINO_USB_CDC_ON_BOOT=0 "@C:\\Users\\Administrator\\AppData\\Local\\Arduino15\\packages\\esp32\\tools\\esp32-arduino-libs\\idf-release_v5.4-858a988d-v1\\esp32/flags/defines" "-IE:\\Git-category\\Git-Arduino\\Arduino-ESP32\\BSP\\ESP\\ESP1000-ESP32-tori\\rtos-cam-web-2" -iprefix "C:\\Users\\Administrator\\AppData\\Local\\Arduino15\\packages\\esp32\\tools\\esp32-arduino-libs\\idf-release_v5.4-858a988d-v1\\esp32/include/" "@C:\\Users\\Administrator\\AppData\\Local\\Arduino15\\packages\\esp32\\tools\\esp32-arduino-libs\\idf-release_v5.4-858a988d-v1\\esp32/flags/includes" "-IC:\\Users\\Administrator\\AppData\\Local\\Arduino15\\packages\\esp32\\tools\\esp32-arduino-libs\\idf-release_v5.4-858a988d-v1\\esp32/qio_qspi/include" "-IC:\\Users\\Administrator\\AppData\\Local\\Arduino15\\packages\\esp32\\hardware\\esp32\\3.2.1\\cores\\esp32" "-IC:\\Users\\Administrator\\AppData\\Local\\Arduino15\\packages\\esp32\\hardware\\esp32\\3.2.1\\variants\\esp32" "-IC:\\Users\\Administrator\\AppData\\Local\\Arduino15\\packages\\esp32\\hardware\\esp32\\3.2.1\\libraries\\FS\\src" "-IC:\\Users\\Administrator\\AppData\\Local\\Arduino15\\packages\\esp32\\hardware\\esp32\\3.2.1\\libraries\\LittleFS\\src" "-IC:\\Users\\Administrator\\AppData\\Local\\Arduino15\\packages\\esp32\\hardware\\esp32\\3.2.1\\libraries\\WiFi\\src" "-IC:\\Users\\Administrator\\AppData\\Local\\Arduino15\\packages\\esp32\\hardware\\esp32\\3.2.1\\libraries\\Network\\src" "-IC:\\Users\\Administrator\\AppData\\Local\\Arduino15\\packages\\esp32\\hardware\\esp32\\3.2.1\\libraries\\WebServer\\src" "-IC:\\Users\\Administrator\\AppData\\Local\\Arduino15\\packages\\esp32\\hardware\\esp32\\3.2.1\\libraries\\Wire\\src" "-Ie:\\Git-category\\Git-Arduino\\Arduino-ESP32\\libraries\\Adafruit_GFX_Library" "-Ie:\\Git-category\\Git-Arduino\\Arduino-ESP32\\libraries\\Adafruit_SSD1306" "-IC:\\Users\\Administrator\\AppData\\Local\\Arduino15\\packages\\esp32\\hardware\\esp32\\3.2.1\\libraries\\SPI\\src" "-Ie:\\Git-category\\Git-Arduino\\Arduino-ESP32\\libraries\\Adafruit_BMP280_Library" "-Ie:\\Git-category\\Git-Arduino\\Arduino-ESP32\\libraries\\Adafruit_Unified_Sensor" "-Ie:\\Git-category\\Git-Arduino\\Arduino-ESP32\\libraries\\Adafruit_BusIO" "@C:\\Users\\Administrator\\AppData\\Local\\arduino\\sketches\\058F81B8D9D12F158C24DA0778C64AEF/build_opt.h" "@C:\\Users\\Administrator\\AppData\\Local\\arduino\\sketches\\058F81B8D9D12F158C24DA0778C64AEF/file_opts" "C:\\Users\\Administrator\\AppData\\Local\\arduino\\sketches\\058F81B8D9D12F158C24DA0778C64AEF\\sketch\\rtos-cam-web-2.ino.cpp" -o "C:\\Users\\Administrator\\AppData\\Local\\arduino\\sketches\\058F81B8D9D12F158C24DA0778C64AEF\\sketch\\rtos-cam-web-2.ino.cpp.o"
    In file included from e:\Git-category\Git-Arduino\Arduino-ESP32\libraries\Adafruit_BMP280_Library/Adafruit_BMP280.h:26,
                    from E:\Git-category\Git-Arduino\Arduino-ESP32\BSP\ESP\ESP1000-ESP32-tori\rtos-cam-web-2\rtos-cam-web-2.ino:30:
    e:\Git-category\Git-Arduino\Arduino-ESP32\libraries\Adafruit_Unified_Sensor/Adafruit_Sensor.h:191:3: error: conflicting declaration 'typedef struct sensor_t sensor_t'
    191 | } sensor_t;
        |   ^~~~~~~~
    In file included from C:\Users\Administrator\AppData\Local\Arduino15\packages\esp32\tools\esp32-arduino-libs\idf-release_v5.4-858a988d-v1\esp32/include/espressif__esp32-camera/driver/include/esp_camera.h:71,
                    from E:\Git-category\Git-Arduino\Arduino-ESP32\BSP\ESP\ESP1000-ESP32-tori\rtos-cam-web-2\rtos-cam-web-2.ino:19:
    C:\Users\Administrator\AppData\Local\Arduino15\packages\esp32\tools\esp32-arduino-libs\idf-release_v5.4-858a988d-v1\esp32/include/espressif__esp32-camera/driver/include/sensor.h:259:3: note: previous declaration as 'typedef struct _sensor sensor_t'
    259 | } sensor_t;
        |   ^~~~~~~~