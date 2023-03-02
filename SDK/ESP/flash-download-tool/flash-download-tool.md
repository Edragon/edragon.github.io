
# Flash Download Tool


## NWI1126 

### ESP32-C3 Factory Mode 

- Chip = ESP32-C3
- Mode = Factory
- LoadMode = UART


![](32-02-18-06-02-2023.png)

### setup 设置

- Flash Frequency: 40M or 80M 
- SPI Mode: QIO or DIO 


![](56-04-18-06-02-2023.png)

- 红色 - 5V电源正 = pin1 第一脚 = +5V or VCC
- NC
- 绿色 - USB_TXD
- 白色 - USB_RXD
- GND - 电源地



![](36-05-18-06-02-2023.png)

### ESP32-C3 进入烧写模式 

- 接上线
- 先按下 IO9 保持不动
- 按 EN或者RST 重启一下, 即可进入烧写模式
