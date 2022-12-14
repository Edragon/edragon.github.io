

# ESP8684-MINI-1

## type 
- ESP8684-MINI-1-H2
- ESP8684-MINI-1-H4
- ESP8684-MINI-1U-H2

【样品说明】
1、当前芯片版本为 ECO V1 、量产版本设计，但此批次芯片 ADC 功能 和 温度传感器未校准；
未来IDF 将不支持此批芯片 ADC 、温度传感器校准。
建议您在非量产阶段使用， 或者用于对ADC 、温度传感器校准无严格要求的产品应用。

2、硬件设计请注意： ESP8684 ECO V1 芯片，需搭配 26MHZ 晶振。 

3、软件开发请注意：当前 IDF 暂不支持 26MHZ 晶振，预计 2022年8月15日左右 IDF V5.0.1 

将添加对 26MHZ 晶振支持   

（详情以 IDF 后续更新为准  https://github.com/espressif/esp-idf  ）

![](17-48-16-14-12-2022.png)


## DS 

https://www.espressif.com.cn/sites/default/files/documentation/esp8684_datasheet_en.pdf