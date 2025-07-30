

menuconfig里面找到ESP PSRAM并打开，勾选support for external ,SPI -connected RAM，spiram的模式就选择 quad，如果自己的板子后面在调试监视的时候报错，就更换成另外一种模式，自动检测使用SPIRAM类型，设置RAM的时钟速度为80MHZ，并且勾选Initialize SPI RAM during startup，这样就可以在初始化的过程中自己识别PSRAM的芯片类型并且在监视中显示出来了，这一步是初始化camera的关键，然后记得保存。

然后还有关键的一步，需要给现有的工程添加esp_camera的依赖库

通过idf的终端，输入指令：

idf.py add-dependency "espressif/esp32-camera"

即可在现有工程中添加相机库的依赖，引用esp_camera.h 

这里面为了确保psram确实已经得到了初始化，我们添加如下代码，显示如下：


    // 检测 PSRAM 存在性和大小
        if(esp_psram_get_size() == 0) {
            ESP_LOGE("BOOT", "PSRAM NOT DETECTED! Check hardware connection.");
            vTaskDelay(pdMS_TO_TICKS(1000));
            esp_restart(); // 自动重启
        }
        
        ESP_LOGI("BOOT", "PSRAM Size: %d KB", esp_psram_get_size() / 1024);
        
        // 初始化 PSRAM 缓存
        esp_psram_init();

