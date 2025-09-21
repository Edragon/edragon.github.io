# ESP32-HDK-dat

- [[ESP-SDK-dat]]
  
- [[ESP32-modules-dat]] - [[ESP32-board-dat]]

- [[ESP32-chip-error-dat]]

- [[ESP-prog-dat]]

- [[ESP32-ADC-dat]] - [[ESP32-DAC-dat]] - [[ESP32-I2C-dat]] - [[esp32-serial-dat]] - [[esp32-gpios-dat]] - [[esp32-usb-dat]] - [[ESP32-SPI-dat]] - [[ESP32-I2S-dat]] 


## pins 

You can use almost any GPIO, except:

GPIO6–11: used for flash

GPIO34–39: input-only (not usable as output like SCL)

### RMT

- RMT_SIG_IN0~7
- Any GPIO Pins
- Eight channels for an IR transmitter and
- RMT_SIG_OUT0~7 receiver of various waveforms

- [[infrared-dat]]


### Functions 

- [[interface-dat]]

- use [[PDM-dat]] instead of [[I2S-dat]] on [[ESP32-S3-dat]]


- [[ESP32-DAC-dat]] - [[ESP32-I2C-dat]] - [[esp32-serial-dat]] - [[ESP32-GPIOs-dat]] - [[esp32-usb-dat]] - [[ESP32-SPI-dat]] - [[ESP32-I2S-dat]] - [[sd-dat]]

## RAM 

### ESP32 DRAM Configuration

ESP32 has **520 KB SRAM** split into multiple regions:

- **DRAM0**: 192 KB - Main data RAM for variables and heap
- **DRAM1**: 128 KB - Instruction RAM cache (can be used as data RAM)  
- **DRAM2**: 200 KB - Used by WiFi/Bluetooth stack and DMA buffers

**Key Points:**
- **Internal DRAM**: Fast access, used for critical data and stack
- **External PSRAM**: Optional 4-8MB external RAM (via SPI)
- **DMA Capable**: Some regions support DMA operations
- **Shared Memory**: WiFi/BT libraries consume significant DRAM

**Memory Management:**
- Heap allocation uses internal DRAM first
- Large buffers should use PSRAM when available
- Use `esp_get_free_heap_size()` to monitor usage


- [[memory-dat]]

## Module Compare 

![](2024-12-27-18-11-21.png)


## Diagram 

![](2024-12-27-18-11-50.png)

## boot mode 

### Table 3-1. Default Configuration of Strapping Pins

- from esp32 chip datasheet 

| Strapping Pin | note | Default Configuration Bit | Value |
| ------------- | ---- | ------------------------- | ----- |
| GPIO0         | 0    | Pull-up                   | 1     |
| GPIO2         | 2    | Pull-down                 | 0     |
| MTDI          | 12   | Pull-down                 | 0     |
| MTDO          | 15   | Pull-up                   | 1     |
| GPIO5         | 5    | Pull-up                   | 1     |

### Table 6: Chip Boot Mode Control

- from esp32 wroom module datasheet 
  
| Boot Mode                | GPIO0 | GPIO2     |
| ------------------------ | ----- | --------- |
| SPI Boot Mode            | 1     | Any value |
| Joint Download Boot Mode | 0     | 0         |




## documentas 

- [[esp32_technical_reference_manual_en_v5.2.pdf]]

- [[ESP32_Series_datasheet_v4.7.pdf]]



### Shields (stack boards) 
- [[NWI1245-dat]]

### In Development
- [[ESP32-ISO-dat]]



## ref


## Chip Info 

### datasheet

- chip datasheet
- https://www.espressif.com.cn/sites/default/files/documentation/esp32_datasheet_en.pdf

- esp32 technical_reference_manual CN
- https://www.espressif.com/sites/default/files/documentation/esp32_technical_reference_manual_cn.pdf

- ESP32 Chip Revision v3.0 - User Guid
- https://www.espressif.com/sites/default/files/documentation/esp32_chip_revision_v3_0_user_guide_en.pdf





- [[BTB-dat]]

- [[ESP32-HDK]]

EMAC = Ethernet 


ref 

- https://electropeak.com/learn/full-guide-to-esp32-pinout-reference-what-gpio-pins-should-we-use/
- https://randomnerdtutorials.com/esp32-pinout-reference-gpios/



