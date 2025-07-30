
# ESP-Compile-log-dat

    *  Executing task: e:\work-data\IDF_tools\tools\cmake\3.30.2\bin\cmake.exe -G Ninja -DPYTHON_DEPS_CHECKED=1 -DESP_PLATFORM=1 -B e:\Git-category\Git-Arduino\esp-idf-code\blink\blink2-build\build -S e:\Git-category\Git-Arduino\esp-idf-code\blink\blink2-
    -- Found Git: E:/work-data/IDF_tools/tools/idf-git/2.39.2/cmd/git.exe (found version "2.39.2.windows.1")
    -- Minimal build - OFF
    -- The C compiler identification is GNU 14.2.0
    -- The CXX compiler identification is GNU 14.2.0
    -- The ASM compiler identification is GNU
    -- Found assembler: E:/work-data/IDF_tools/tools/xtensa-esp-elf/esp-14.2.0_20241119/xtensa-esp-elf/bin/xtensa-esp32s3-elf-gcc.exe
    -- Detecting C compiler ABI info
    -- Detecting C compiler ABI info - done
    -- Check for working C compiler: E:/work-data/IDF_tools/tools/xtensa-esp-elf/esp-14.2.0_20241119/xtensa-esp-elf/bin/xtensa-esp32s3-elf-gcc.exe - skipped
    -- Detecting C compile features       
    -- Detecting C compile features - done
    -- Detecting CXX compiler ABI info
    -- Detecting CXX compiler ABI info - done
    -- Check for working CXX compiler: E:/work-data/IDF_tools/tools/xtensa-esp-elf/esp-14.2.0_20241119/xtensa-esp-elf/bin/xtensa-esp32s3-elf-g++.exe - skipped
    -- Detecting CXX compile features       
    -- Detecting CXX compile features - done
    -- git rev-parse returned 'fatal: not a git repository (or any of the parent directories): .git'
    -- Could not use 'git describe' to determine PROJECT_VER.
    -- Building ESP-IDF components for target esp32s3        
    -- Project sdkconfig file E:/Git-category/Git-Arduino/esp-idf-code/blink/blink2-build/sdkconfig
    -- Compiler supported targets: xtensa-esp-elf
    -- Found Python3: e:/work-data/IDF_tools/python_env/idf5.5_py3.11_env/Scripts/python.exe (found version "3.11.2") found 
    components: Interpreter
    -- Performing Test CMAKE_HAVE_LIBC_PTHREAD
    -- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Success
    -- Found Threads: TRUE
    -- Performing Test C_COMPILER_SUPPORTS_WFORMAT_SIGNEDNESS
    -- Performing Test C_COMPILER_SUPPORTS_WFORMAT_SIGNEDNESS - Success
    -- USING O3
    -- App "blink2-build" version: 1
    -- Adding linker script E:/Git-category/Git-Arduino/esp-idf-code/blink/blink2-build/build/esp-idf/esp_system/ld/memory.ld
    -- Adding linker script E:/Git-category/Git-Arduino/esp-idf-code/blink/blink2-build/build/esp-idf/esp_system/ld/sections.ld.in
    -- Adding linker script E:/work-data/IDF/v5.5/esp-idf/components/esp_rom/esp32s3/ld/esp32s3.rom.ld
    -- Adding linker script E:/work-data/IDF/v5.5/esp-idf/components/esp_rom/esp32s3/ld/esp32s3.rom.api.ld       
    -- Adding linker script E:/work-data/IDF/v5.5/esp-idf/components/esp_rom/esp32s3/ld/esp32s3.rom.bt_funcs.ld  
    -- Adding linker script E:/work-data/IDF/v5.5/esp-idf/components/esp_rom/esp32s3/ld/esp32s3.rom.libgcc.ld    
    -- Adding linker script E:/work-data/IDF/v5.5/esp-idf/components/esp_rom/esp32s3/ld/esp32s3.rom.wdt.ld       
    -- Adding linker script E:/work-data/IDF/v5.5/esp-idf/components/esp_rom/esp32s3/ld/esp32s3.rom.version.ld   
    -- Adding linker script E:/work-data/IDF/v5.5/esp-idf/components/esp_rom/esp32s3/ld/esp32s3.rom.ble_master.ld
    -- Adding linker script E:/work-data/IDF/v5.5/esp-idf/components/esp_rom/esp32s3/ld/esp32s3.rom.ble_50.ld    
    -- Adding linker script E:/work-data/IDF/v5.5/esp-idf/components/esp_rom/esp32s3/ld/esp32s3.rom.ble_smp.ld   
    -- Adding linker script E:/work-data/IDF/v5.5/esp-idf/components/esp_rom/esp32s3/ld/esp32s3.rom.ble_dtm.ld   
    -- Adding linker script E:/work-data/IDF/v5.5/esp-idf/components/esp_rom/esp32s3/ld/esp32s3.rom.ble_test.ld  
    -- Adding linker script E:/work-data/IDF/v5.5/esp-idf/components/esp_rom/esp32s3/ld/esp32s3.rom.ble_scan.ld  
    -- Adding linker script E:/work-data/IDF/v5.5/esp-idf/components/esp_rom/esp32s3/ld/esp32s3.rom.libc.ld      
    -- Adding linker script E:/work-data/IDF/v5.5/esp-idf/components/esp_rom/esp32s3/ld/esp32s3.rom.newlib.ld    
    -- Adding linker script E:/work-data/IDF/v5.5/esp-idf/components/soc/esp32s3/ld/esp32s3.peripherals.ld
    -- Components: app_trace app_update bootloader bootloader_support bt cmock console cxx driver efuse esp-tls esp_adc esp_app_format esp_bootloader_format esp_coex esp_common esp_driver_ana_cmpr esp_driver_bitscrambler esp_driver_cam esp_driver_dac esp_driver_gpio esp_driver_gptimer esp_driver_i2c esp_driver_i2s esp_driver_isp esp_driver_jpeg esp_driver_ledc esp_driver_mcpwm esp_driver_parlio esp_driver_pcnt esp_driver_ppa esp_driver_rmt esp_driver_sdio esp_driver_sdm esp_driver_sdmmc esp_driver_sdspi esp_driver_spi esp_driver_touch_sens esp_driver_tsens esp_driver_twai esp_driver_uart esp_driver_usb_serial_jtag esp_eth esp_event esp_gdbstub esp_hid esp_http_client esp_http_server esp_https_ota esp_https_server esp_hw_support esp_lcd esp_local_ctrl esp_mm esp_netif esp_netif_stack esp_partition esp_phy esp_pm esp_psram esp_ringbuf esp_rom esp_security esp_system esp_timer esp_vfs_console esp_wifi espcoredump esptool_py fatfs freertos hal heap http_parser idf_test ieee802154 json log lwip main mbedtls mqtt newlib nvs_flash nvs_sec_provider openthread partition_table 
    perfmon protobuf-c protocomm pthread rt sdmmc soc spi_flash spiffs tcp_transport touch_element ulp unity usb vfs wear_levelling wifi_provisioning wpa_supplicant xtensa
    -- Component paths: E:/work-data/IDF/v5.5/esp-idf/components/app_trace E:/work-data/IDF/v5.5/esp-idf/components/app_update E:/work-data/IDF/v5.5/esp-idf/components/bootloader E:/work-data/IDF/v5.5/esp-idf/components/bootloader_support E:/work-data/IDF/v5.5/esp-idf/components/bt E:/work-data/IDF/v5.5/esp-idf/components/cmock E:/work-data/IDF/v5.5/esp-idf/components/console E:/work-data/IDF/v5.5/esp-idf/components/cxx E:/work-data/IDF/v5.5/esp-idf/components/driver E:/work-data/IDF/v5.5/esp-idf/components/efuse E:/work-data/IDF/v5.5/esp-idf/components/esp-tls E:/work-data/IDF/v5.5/esp-idf/components/esp_adc E:/work-data/IDF/v5.5/esp-idf/components/esp_app_format E:/work-data/IDF/v5.5/esp-idf/components/esp_bootloader_format E:/work-data/IDF/v5.5/esp-idf/components/esp_coex E:/work-data/IDF/v5.5/esp-idf/components/esp_common E:/work-data/IDF/v5.5/esp-idf/components/esp_driver_ana_cmpr E:/work-data/IDF/v5.5/esp-idf/components/esp_driver_bitscrambler 
    E:/work-data/IDF/v5.5/esp-idf/components/esp_driver_cam E:/work-data/IDF/v5.5/esp-idf/components/esp_driver_dac E:/work-data/IDF/v5.5/esp-idf/components/esp_driver_gpio E:/work-data/IDF/v5.5/esp-idf/components/esp_driver_gptimer E:/work-data/IDF/v5.5/esp-idf/components/esp_driver_i2c E:/work-data/IDF/v5.5/esp-idf/components/esp_driver_i2s E:/work-data/IDF/v5.5/esp-idf/components/esp_driver_isp E:/work-data/IDF/v5.5/esp-idf/components/esp_driver_jpeg E:/work-data/IDF/v5.5/esp-idf/components/esp_driver_ledc E:/work-data/IDF/v5.5/esp-idf/components/esp_driver_mcpwm E:/work-data/IDF/v5.5/esp-idf/components/esp_driver_parlio E:/work-data/IDF/v5.5/esp-idf/components/esp_driver_pcnt E:/work-data/IDF/v5.5/esp-idf/components/esp_driver_ppa E:/work-data/IDF/v5.5/esp-idf/components/esp_driver_rmt E:/work-data/IDF/v5.5/esp-idf/components/esp_driver_sdio E:/work-data/IDF/v5.5/esp-idf/components/esp_driver_sdm E:/work-data/IDF/v5.5/esp-idf/components/esp_driver_sdmmc E:/work-data/IDF/v5.5/esp-idf/components/esp_driver_sdspi E:/work-data/IDF/v5.5/esp-idf/components/esp_driver_spi E:/work-data/IDF/v5.5/esp-idf/components/esp_driver_touch_sens E:/work-data/IDF/v5.5/esp-idf/components/esp_driver_tsens E:/work-data/IDF/v5.5/esp-idf/components/esp_driver_twai E:/work-data/IDF/v5.5/esp-idf/components/esp_driver_uart E:/work-data/IDF/v5.5/esp-idf/components/esp_driver_usb_serial_jtag E:/work-data/IDF/v5.5/esp-idf/components/esp_eth E:/work-data/IDF/v5.5/esp-idf/components/esp_event E:/work-data/IDF/v5.5/esp-idf/components/esp_gdbstub E:/work-data/IDF/v5.5/esp-idf/components/esp_hid E:/work-data/IDF/v5.5/esp-idf/components/esp_http_client E:/work-data/IDF/v5.5/esp-idf/components/esp_http_server E:/work-data/IDF/v5.5/esp-idf/components/esp_https_ota E:/work-data/IDF/v5.5/esp-idf/components/esp_https_server E:/work-data/IDF/v5.5/esp-idf/components/esp_hw_support E:/work-data/IDF/v5.5/esp-idf/components/esp_lcd E:/work-data/IDF/v5.5/esp-idf/components/esp_local_ctrl E:/work-data/IDF/v5.5/esp-idf/components/esp_mm E:/work-data/IDF/v5.5/esp-idf/components/esp_netif E:/work-data/IDF/v5.5/esp-idf/components/esp_netif_stack E:/work-data/IDF/v5.5/esp-idf/components/esp_partition E:/work-data/IDF/v5.5/esp-idf/components/esp_phy E:/work-data/IDF/v5.5/esp-idf/components/esp_pm E:/work-data/IDF/v5.5/esp-idf/components/esp_psram E:/work-data/IDF/v5.5/esp-idf/components/esp_ringbuf E:/work-data/IDF/v5.5/esp-idf/components/esp_rom E:/work-data/IDF/v5.5/esp-idf/components/esp_security E:/work-data/IDF/v5.5/esp-idf/components/esp_system E:/work-data/IDF/v5.5/esp-idf/components/esp_timer E:/work-data/IDF/v5.5/esp-idf/components/esp_vfs_console E:/work-data/IDF/v5.5/esp-idf/components/esp_wifi E:/work-data/IDF/v5.5/esp-idf/components/espcoredump E:/work-data/IDF/v5.5/esp-idf/components/esptool_py E:/work-data/IDF/v5.5/esp-idf/components/fatfs E:/work-data/IDF/v5.5/esp-idf/components/freertos E:/work-data/IDF/v5.5/esp-idf/components/hal E:/work-data/IDF/v5.5/esp-idf/components/heap E:/work-data/IDF/v5.5/esp-idf/components/http_parser E:/work-data/IDF/v5.5/esp-idf/components/idf_test E:/work-data/IDF/v5.5/esp-idf/components/ieee802154 E:/work-data/IDF/v5.5/esp-idf/components/json E:/work-data/IDF/v5.5/esp-idf/components/log E:/work-data/IDF/v5.5/esp-idf/components/lwip E:/Git-category/Git-Arduino/esp-idf-code/blink/blink2-build/main E:/work-data/IDF/v5.5/esp-idf/components/mbedtls E:/work-data/IDF/v5.5/esp-idf/components/mqtt E:/work-data/IDF/v5.5/esp-idf/components/newlib E:/work-data/IDF/v5.5/esp-idf/components/nvs_flash E:/work-data/IDF/v5.5/esp-idf/components/nvs_sec_provider E:/work-data/IDF/v5.5/esp-idf/components/openthread E:/work-data/IDF/v5.5/esp-idf/components/partition_table E:/work-data/IDF/v5.5/esp-idf/components/perfmon E:/work-data/IDF/v5.5/esp-idf/components/protobuf-c E:/work-data/IDF/v5.5/esp-idf/components/protocomm E:/work-data/IDF/v5.5/esp-idf/components/pthread E:/work-data/IDF/v5.5/esp-idf/components/rt E:/work-data/IDF/v5.5/esp-idf/components/sdmmc E:/work-data/IDF/v5.5/esp-idf/components/soc E:/work-data/IDF/v5.5/esp-idf/components/spi_flash E:/work-data/IDF/v5.5/esp-idf/components/spiffs E:/work-data/IDF/v5.5/esp-idf/components/tcp_transport E:/work-data/IDF/v5.5/esp-idf/components/touch_element E:/work-data/IDF/v5.5/esp-idf/components/ulp E:/work-data/IDF/v5.5/esp-idf/components/unity E:/work-data/IDF/v5.5/esp-idf/components/usb E:/work-data/IDF/v5.5/esp-idf/components/vfs E:/work-data/IDF/v5.5/esp-idf/components/wear_levelling E:/work-data/IDF/v5.5/esp-idf/components/wifi_provisioning E:/work-data/IDF/v5.5/esp-idf/components/wpa_supplicant E:/work-data/IDF/v5.5/esp-idf/components/xtensa
    -- Configuring done (36.8s)
    -- Generating done (16.7s)
    -- Build files have been written to: E:/Git-category/Git-Arduino/esp-idf-code/blink/blink2-build/build

    *  Executing task: e:\work-data\IDF_tools\tools\ninja\1.12.1\ninja.EXE  

    [4/1063] Generating ../../partition_table/partition-table.bin
    Partition table binary generated. Contents:
    *******************************************************************************
    # ESP-IDF Partition Table
    # Name, Type, SubType, Offset, Size, Flags
    nvs,data,nvs,0x9000,24K,
    phy_init,data,phy,0xf000,4K,
    factory,app,factory,0x10000,1M,
    *******************************************************************************
    [1055/1063] Performing configure step for 'bootloader'
    -- Found Git: E:/work-data/IDF_tools/tools/idf-git/2.39.2/cmd/git.exe (found version "2.39.2.windows.1")
    -- Minimal build - OFF
    -- The C compiler identification is GNU 14.2.0
    -- The CXX compiler identification is GNU 14.2.0
    -- The ASM compiler identification is GNU
    -- Found assembler: E:/work-data/IDF_tools/tools/xtensa-esp-elf/esp-14.2.0_20241119/xtensa-esp-elf/bin/xtensa-esp32s3-elf-gcc.exe
    -- Detecting C compiler ABI info
    -- Detecting C compiler ABI info - done
    -- Check for working C compiler: E:/work-data/IDF_tools/tools/xtensa-esp-elf/esp-14.2.0_20241119/xtensa-esp-elf/bin/xtensa-esp32s3-elf-gcc.exe - skipped
    -- Detecting C compile features
    -- Detecting C compile features - done
    -- Detecting CXX compiler ABI info
    -- Detecting CXX compiler ABI info - done
    -- Check for working CXX compiler: E:/work-data/IDF_tools/tools/xtensa-esp-elf/esp-14.2.0_20241119/xtensa-esp-elf/bin/xtensa-esp32s3-elf-g++.exe - skipped
    -- Detecting CXX compile features
    -- Detecting CXX compile features - done
    -- Building ESP-IDF components for target esp32s3
    -- Project sdkconfig file E:/Git-category/Git-Arduino/esp-idf-code/blink/blink2-build/sdkconfig
    -- Compiler supported targets: xtensa-esp-elf
    -- Adding linker script E:/work-data/IDF/v5.5/esp-idf/components/soc/esp32s3/ld/esp32s3.peripherals.ld
    -- Bootloader project name: "bootloader" version: 1
    -- Adding linker script E:/work-data/IDF/v5.5/esp-idf/components/esp_rom/esp32s3/ld/esp32s3.rom.ld
    -- Adding linker script E:/work-data/IDF/v5.5/esp-idf/components/esp_rom/esp32s3/ld/esp32s3.rom.api.ld
    -- Adding linker script E:/work-data/IDF/v5.5/esp-idf/components/esp_rom/esp32s3/ld/esp32s3.rom.bt_funcs.ld
    -- Adding linker script E:/work-data/IDF/v5.5/esp-idf/components/esp_rom/esp32s3/ld/esp32s3.rom.libgcc.ld
    -- Adding linker script E:/work-data/IDF/v5.5/esp-idf/components/esp_rom/esp32s3/ld/esp32s3.rom.wdt.ld
    -- Adding linker script E:/work-data/IDF/v5.5/esp-idf/components/esp_rom/esp32s3/ld/esp32s3.rom.version.ld
    -- Adding linker script E:/work-data/IDF/v5.5/esp-idf/components/esp_rom/esp32s3/ld/esp32s3.rom.libc.ld
    -- Adding linker script E:/work-data/IDF/v5.5/esp-idf/components/esp_rom/esp32s3/ld/esp32s3.rom.newlib.ld
    -- Adding linker script E:/work-data/IDF/v5.5/esp-idf/components/bootloader/subproject/main/ld/esp32s3/bootloader.ld    
    -- Adding linker script E:/work-data/IDF/v5.5/esp-idf/components/bootloader/subproject/main/ld/esp32s3/bootloader.rom.ld-- Components: bootloader bootloader_support efuse esp_app_format esp_bootloader_format esp_common esp_hw_support esp_rom esp_security esp_system esptool_py freertos hal log main micro-ecc newlib partition_table soc spi_flash xtensa        
    -- Component paths: E:/work-data/IDF/v5.5/esp-idf/components/bootloader E:/work-data/IDF/v5.5/esp-idf/components/bootloader_support E:/work-data/IDF/v5.5/esp-idf/components/efuse E:/work-data/IDF/v5.5/esp-idf/components/esp_app_format E:/work-data/IDF/v5.5/esp-idf/components/esp_bootloader_format E:/work-data/IDF/v5.5/esp-idf/components/esp_common E:/work-data/IDF/v5.5/esp-idf/components/esp_hw_support E:/work-data/IDF/v5.5/esp-idf/components/esp_rom E:/work-data/IDF/v5.5/esp-idf/components/esp_security E:/work-data/IDF/v5.5/esp-idf/components/esp_system E:/work-data/IDF/v5.5/esp-idf/components/esptool_py E:/work-data/IDF/v5.5/esp-idf/components/freertos E:/work-data/IDF/v5.5/esp-idf/components/hal E:/work-data/IDF/v5.5/esp-idf/components/log E:/work-data/IDF/v5.5/esp-idf/components/bootloader/subproject/main E:/work-data/IDF/v5.5/esp-idf/components/bootloader/subproject/components/micro-ecc E:/work-data/IDF/v5.5/esp-idf/components/newlib E:/work-data/IDF/v5.5/esp-idf/components/partition_table E:/work-data/IDF/v5.5/esp-idf/components/soc E:/work-data/IDF/v5.5/esp-idf/components/spi_flash E:/work-data/IDF/v5.5/esp-idf/components/xtensa
    -- Configuring done (67.8s)
    -- Generating done (2.4s)
    -- Build files have been written to: E:/Git-category/Git-Arduino/esp-idf-code/blink/blink2-build/build/bootloader       
    [1056/1063] Performing build step for 'bootloader'
    [1/122] Building C object esp-idf/log/CMakeFiles/__idf_log.dir/src/noos/util.c.obj
    [2/122] Building C object esp-idf/log/CMakeFiles/__idf_log.dir/src/util.c.obj
    [3/122] Building C object esp-idf/log/CMakeFiles/__idf_log.dir/src/noos/log_lock.c.obj
    [4/122] Building C object esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/patches/esp_rom_crc.c.obj
    [5/122] Building C object esp-idf/log/CMakeFiles/__idf_log.dir/src/log_print.c.obj
    [6/122] Building C object esp-idf/log/CMakeFiles/__idf_log.dir/src/noos/log_timestamp.c.obj
    [7/122] Building C object esp-idf/log/CMakeFiles/__idf_log.dir/src/log_format_text.c.obj
    [8/122] Building C object esp-idf/log/CMakeFiles/__idf_log.dir/src/log.c.obj
    [9/122] Building ASM object esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/patches/esp_rom_longjmp.S.obj
    [10/122] Building C object esp-idf/log/CMakeFiles/__idf_log.dir/src/log_timestamp_common.c.obj
    [11/122] Building C object esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/patches/esp_rom_sys.c.obj
    [12/122] Building C object esp-idf/log/CMakeFiles/__idf_log.dir/src/buffer/log_buffers.c.obj
    [13/122] Building C object esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/patches/esp_rom_uart.c.obj
    [14/122] Building C object esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/patches/esp_rom_spiflash.c.obj
    [15/122] Building C object esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/patches/esp_rom_efuse.c.obj
    [16/122] Building C object esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/patches/esp_rom_systimer.c.obj
    [17/122] Building ASM object esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/patches/esp_rom_cache_writeback_esp32s3.S.obj 
    [18/122] Building C object esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/patches/esp_rom_gpio.c.obj
    [19/122] Building C object esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/patches/esp_rom_print.c.obj
    [20/122] Building C object esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/patches/esp_rom_wdt.c.obj
    [21/122] Building C object esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/patches/esp_rom_cache_esp32s2_esp32s3.c.obj     
    [22/122] Building C object esp-idf/esp_hw_support/CMakeFiles/__idf_esp_hw_support.dir/esp_memory_utils.c.obj
    [23/122] Building C object esp-idf/esp_hw_support/CMakeFiles/__idf_esp_hw_support.dir/port/esp32s3/esp_cpu_intr.c.obj   
    [24/122] Building C object esp-idf/esp_common/CMakeFiles/__idf_esp_common.dir/src/esp_err_to_name.c.obj
    [25/122] Building C object esp-idf/esp_hw_support/CMakeFiles/__idf_esp_hw_support.dir/cpu.c.obj
    [26/122] Building C object esp-idf/esp_hw_support/CMakeFiles/__idf_esp_hw_support.dir/port/esp32s3/cpu_region_protect.c.obj
    [27/122] Building C object esp-idf/esp_system/CMakeFiles/__idf_esp_system.dir/esp_err.c.obj
    [28/122] Building C object esp-idf/efuse/CMakeFiles/__idf_efuse.dir/esp32s3/esp_efuse_table.c.obj
    [29/122] Building C object esp-idf/esp_hw_support/CMakeFiles/__idf_esp_hw_support.dir/port/esp32s3/chip_info.c.obj      
    [30/122] Building C object esp-idf/esp_hw_support/CMakeFiles/__idf_esp_hw_support.dir/port/esp32s3/rtc_sleep.c.obj      
    [31/122] Building C object esp-idf/esp_hw_support/CMakeFiles/__idf_esp_hw_support.dir/port/esp32s3/rtc_clk_init.c.obj   
    [32/122] Linking C static library esp-idf\log\liblog.a
    [33/122] Building C object esp-idf/esp_hw_support/CMakeFiles/__idf_esp_hw_support.dir/port/esp32s3/rtc_time.c.obj       
    [34/122] Building C object esp-idf/efuse/CMakeFiles/__idf_efuse.dir/esp32s3/esp_efuse_fields.c.obj
    [35/122] Building C object esp-idf/efuse/CMakeFiles/__idf_efuse.dir/esp32s3/esp_efuse_rtc_calib.c.obj
    [36/122] Building C object esp-idf/efuse/CMakeFiles/__idf_efuse.dir/esp32s3/esp_efuse_utility.c.obj
    [37/122] Building C object esp-idf/efuse/CMakeFiles/__idf_efuse.dir/src/esp_efuse_fields.c.obj
    [38/122] Building C object esp-idf/esp_hw_support/CMakeFiles/__idf_esp_hw_support.dir/port/esp32s3/rtc_clk.c.obj        
    [39/122] Building C object esp-idf/esp_hw_support/CMakeFiles/__idf_esp_hw_support.dir/port/esp32s3/rtc_init.c.obj       
    [40/122] Building C object esp-idf/efuse/CMakeFiles/__idf_efuse.dir/src/esp_efuse_api.c.obj
    [41/122] Building C object esp-idf/efuse/CMakeFiles/__idf_efuse.dir/src/esp_efuse_utility.c.obj
    [42/122] Building C object esp-idf/bootloader_support/CMakeFiles/__idf_bootloader_support.dir/src/bootloader_common.c.obj
    [43/122] Building C object esp-idf/efuse/CMakeFiles/__idf_efuse.dir/src/efuse_controller/keys/with_key_purposes/esp_efuse_api_key.c.obj
    [44/122] Building C object esp-idf/bootloader_support/CMakeFiles/__idf_bootloader_support.dir/src/bootloader_clock_init.c.obj
    [45/122] Building C object esp-idf/bootloader_support/CMakeFiles/__idf_bootloader_support.dir/src/bootloader_mem.c.obj  
    [46/122] Building C object esp-idf/bootloader_support/CMakeFiles/__idf_bootloader_support.dir/src/bootloader_efuse.c.obj[47/122] Building C object esp-idf/bootloader_support/CMakeFiles/__idf_bootloader_support.dir/src/bootloader_random.c.obj
    [48/122] Building C object esp-idf/bootloader_support/CMakeFiles/__idf_bootloader_support.dir/src/bootloader_random_esp32s3.c.obj
    [49/122] Building C object esp-idf/bootloader_support/CMakeFiles/__idf_bootloader_support.dir/src/secure_boot.c.obj     
    [50/122] Building C object esp-idf/bootloader_support/CMakeFiles/__idf_bootloader_support.dir/src/bootloader_common_loader.c.obj
    [51/122] Building C object esp-idf/bootloader_support/CMakeFiles/__idf_bootloader_support.dir/src/flash_encrypt.c.obj   
    [52/122] Building C object esp-idf/bootloader_support/CMakeFiles/__idf_bootloader_support.dir/bootloader_flash/src/flash_qio_mode.c.obj
    [53/122] Building C object esp-idf/bootloader_support/CMakeFiles/__idf_bootloader_support.dir/src/bootloader_clock_loader.c.obj
    [54/122] Building C object esp-idf/bootloader_support/CMakeFiles/__idf_bootloader_support.dir/src/flash_partitions.c.obj[55/122] Building C object esp-idf/bootloader_support/CMakeFiles/__idf_bootloader_support.dir/bootloader_flash/src/bootloader_flash_config_esp32s3.c.obj
    [56/122] Linking C static library esp-idf\esp_rom\libesp_rom.a
    [57/122] Building C object esp-idf/bootloader_support/CMakeFiles/__idf_bootloader_support.dir/src/bootloader_sha.c.obj  
    [58/122] Building C object esp-idf/bootloader_support/CMakeFiles/__idf_bootloader_support.dir/bootloader_flash/src/bootloader_flash.c.obj
    [59/122] Building C object esp-idf/bootloader_support/CMakeFiles/__idf_bootloader_support.dir/src/esp32s3/bootloader_soc.c.obj
    [60/122] Building C object esp-idf/bootloader_support/CMakeFiles/__idf_bootloader_support.dir/src/bootloader_console_loader.c.obj
    [61/122] Building C object esp-idf/bootloader_support/CMakeFiles/__idf_bootloader_support.dir/src/bootloader_init.c.obj 
    [62/122] Building C object esp-idf/hal/CMakeFiles/__idf_hal.dir/hal_utils.c.obj
    [63/122] Building C object esp-idf/esp_bootloader_format/CMakeFiles/__idf_esp_bootloader_format.dir/esp_bootloader_desc.c.obj
    [64/122] Building C object esp-idf/bootloader_support/CMakeFiles/__idf_bootloader_support.dir/src/bootloader_console.c.obj
    [65/122] Linking C static library esp-idf\esp_common\libesp_common.a
    [66/122] Building C object esp-idf/hal/CMakeFiles/__idf_hal.dir/mpu_hal.c.obj
    [67/122] Building C object esp-idf/bootloader_support/CMakeFiles/__idf_bootloader_support.dir/src/bootloader_panic.c.obj[68/122] Building C object esp-idf/spi_flash/CMakeFiles/__idf_spi_flash.dir/spi_flash_wrap.c.obj
    [69/122] Building C object esp-idf/soc/CMakeFiles/__idf_soc.dir/lldesc.c.obj
    [70/122] Building C object esp-idf/soc/CMakeFiles/__idf_soc.dir/dport_access_common.c.obj
    [71/122] Building C object esp-idf/hal/CMakeFiles/__idf_hal.dir/efuse_hal.c.obj
    [72/122] Building C object esp-idf/soc/CMakeFiles/__idf_soc.dir/esp32s3/interrupts.c.obj
    [73/122] Building C object esp-idf/hal/CMakeFiles/__idf_hal.dir/esp32s3/efuse_hal.c.obj
    [74/122] Building C object esp-idf/bootloader_support/CMakeFiles/__idf_bootloader_support.dir/src/esp32s3/bootloader_esp32s3.c.obj
    [75/122] Building C object esp-idf/bootloader_support/CMakeFiles/__idf_bootloader_support.dir/src/esp_image_format.c.obj[76/122] Building C object esp-idf/hal/CMakeFiles/__idf_hal.dir/mmu_hal.c.obj
    [77/122] Building C object esp-idf/hal/CMakeFiles/__idf_hal.dir/cache_hal.c.obj
    [78/122] Building C object esp-idf/soc/CMakeFiles/__idf_soc.dir/esp32s3/uart_periph.c.obj
    [79/122] Building C object esp-idf/bootloader_support/CMakeFiles/__idf_bootloader_support.dir/src/bootloader_utility.c.obj
    [80/122] Building C object esp-idf/soc/CMakeFiles/__idf_soc.dir/esp32s3/dedic_gpio_periph.c.obj
    [81/122] Building C object esp-idf/soc/CMakeFiles/__idf_soc.dir/esp32s3/gpio_periph.c.obj
    [82/122] Building C object esp-idf/soc/CMakeFiles/__idf_soc.dir/esp32s3/adc_periph.c.obj
    [83/122] Building C object esp-idf/soc/CMakeFiles/__idf_soc.dir/esp32s3/gdma_periph.c.obj
    [84/122] Building C object esp-idf/soc/CMakeFiles/__idf_soc.dir/esp32s3/pcnt_periph.c.obj
    [85/122] Building C object esp-idf/soc/CMakeFiles/__idf_soc.dir/esp32s3/sdm_periph.c.obj
    [86/122] Building C object esp-idf/soc/CMakeFiles/__idf_soc.dir/esp32s3/i2c_periph.c.obj
    [87/122] Building C object esp-idf/soc/CMakeFiles/__idf_soc.dir/esp32s3/temperature_sensor_periph.c.obj
    [88/122] Building C object esp-idf/soc/CMakeFiles/__idf_soc.dir/esp32s3/i2s_periph.c.obj
    [89/122] Building C object esp-idf/soc/CMakeFiles/__idf_soc.dir/esp32s3/spi_periph.c.obj
    [90/122] Building C object esp-idf/soc/CMakeFiles/__idf_soc.dir/esp32s3/ledc_periph.c.obj
    [91/122] Building C object esp-idf/soc/CMakeFiles/__idf_soc.dir/esp32s3/rmt_periph.c.obj
    [92/122] Building C object esp-idf/soc/CMakeFiles/__idf_soc.dir/esp32s3/lcd_periph.c.obj
    [93/122] Linking C static library esp-idf\esp_hw_support\libesp_hw_support.a
    [94/122] Building C object esp-idf/soc/CMakeFiles/__idf_soc.dir/esp32s3/mcpwm_periph.c.obj
    [95/122] Building C object esp-idf/soc/CMakeFiles/__idf_soc.dir/esp32s3/touch_sensor_periph.c.obj
    [96/122] Building C object esp-idf/soc/CMakeFiles/__idf_soc.dir/esp32s3/twai_periph.c.obj
    [97/122] Generating project_elf_src_esp32s3.c
    [98/122] Building C object esp-idf/soc/CMakeFiles/__idf_soc.dir/esp32s3/mpi_periph.c.obj
    [99/122] Building C object esp-idf/soc/CMakeFiles/__idf_soc.dir/esp32s3/sdmmc_periph.c.obj
    [100/122] Building C object esp-idf/soc/CMakeFiles/__idf_soc.dir/esp32s3/usb_dwc_periph.c.obj
    [101/122] Building C object esp-idf/soc/CMakeFiles/__idf_soc.dir/esp32s3/timer_periph.c.obj
    [102/122] Building C object esp-idf/soc/CMakeFiles/__idf_soc.dir/esp32s3/power_supply_periph.c.obj
    [103/122] Building C object esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/eri.c.obj
    [104/122] Building C object esp-idf/soc/CMakeFiles/__idf_soc.dir/esp32s3/wdt_periph.c.obj
    [105/122] Building C object esp-idf/soc/CMakeFiles/__idf_soc.dir/esp32s3/rtc_io_periph.c.obj
    [106/122] Building C object CMakeFiles/bootloader.elf.dir/project_elf_src_esp32s3.c.obj
    [107/122] Building C object esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xt_trax.c.obj
    [108/122] Linking C static library esp-idf\esp_system\libesp_system.a
    [109/122] Building C object esp-idf/main/CMakeFiles/__idf_main.dir/bootloader_start.c.obj
    [110/122] Building C object esp-idf/micro-ecc/CMakeFiles/__idf_micro-ecc.dir/uECC_verify_antifault.c.obj
    [111/122] Linking C static library esp-idf\efuse\libefuse.a
    [112/122] Linking C static library esp-idf\bootloader_support\libbootloader_support.a
    [113/122] Linking C static library esp-idf\esp_bootloader_format\libesp_bootloader_format.a
    [114/122] Linking C static library esp-idf\spi_flash\libspi_flash.a
    [115/122] Linking C static library esp-idf\hal\libhal.a
    [116/122] Linking C static library esp-idf\micro-ecc\libmicro-ecc.a
    [117/122] Linking C static library esp-idf\soc\libsoc.a
    [118/122] Linking C static library esp-idf\xtensa\libxtensa.a
    [119/122] Linking C static library esp-idf\main\libmain.a
    [120/122] Linking C executable bootloader.elf
    [121/122] Generating binary image from built executable
    esptool.py v4.9.0
    Creating esp32s3 image...
    Merged 2 ELF sections
    Successfully created esp32s3 image.
    Generated E:/Git-category/Git-Arduino/esp-idf-code/blink/blink2-build/build/bootloader/bootloader.bin
    [122/122] C:\WINDOWS\system32\cmd.exe /C "cd /D E:\Git-category\Git-Arduino\esp-idf-code\blink\blink2-build\build\bootloader\esp-idf\esptool_py && e:\work-data\IDF_tools\python_env\idf5.5_py3.11_env\Scripts\python.exe E:/work-data/IDF/v5.5/esp-idf/components/partition_table/check_sizes.py --offset 0x8000 bootloader 0x0 E:/Git-category/Git-Arduino/esp-idf-code/blink/blink2-build/build/bootloader/bootloader.bin"
    Bootloader binary size 0x5260 bytes. 0x2da0 bytes (36%) free.
    [1061/1063] Linking CXX executable blink2-build.elf






    -- Configuring done (21.4s)
    -- Generating done (2.5s)
    -- Build files have been written to: E:/Git-category/Git-Arduino/esp-idf-code/blink/blink2-build/build

    [1/10] Performing build step for 'bootloader'
    [1/1] C:\WINDOWS\system32\cmd.exe /C "cd /D E:\Git-category\Git-Arduino\esp-idf-code\blink\blink2-build\build\bootloader\esp-idf\esptool_py && e:\work-data\IDF_tools\python_env\idf5.5_py3.11_env\Scripts\python.exe E:/work-data/IDF/v5.5/esp-idf/components/partition_table/check_sizes.py --offset 0x8000 bootloader 0x0 E:/Git-category/Git-Arduino/esp-idf-code/blink/blink2-build/build/bootloader/bootloader.bin"
    Bootloader binary size 0x5260 bytes. 0x2da0 bytes (36%) free.
    [3/10] Building C object esp-idf/main/CMakeFiles/__idf_main.dir/led.c.obj


    [8/10] Generating binary image from built executable
    esptool.py v4.9.0
    Creating esp32s3 image...
    Merged 2 ELF sections
    Successfully created esp32s3 image.
    Generated E:/Git-category/Git-Arduino/esp-idf-code/blink/blink2-build/build/blink2-build.bin
    [9/10] C:\WINDOWS\system32\cmd.exe /C "cd ...blink/blink2-build/build/blink2-build.bin" 
    blink2-build.bin binary size 0x33b60 bytes. Smallest app partition is 0x100000 bytes. 0xcc4a0 bytes (80%) free.




