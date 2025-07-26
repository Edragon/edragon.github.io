
# ESP32-compiler-error-dat

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